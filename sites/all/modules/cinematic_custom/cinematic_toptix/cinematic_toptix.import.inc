<?php

function cinematic_toptix_import($form, &$form_state) {
  $last = variable_get('toptix_import', 'Never');
  $form['last_run'] = array(
    '#type' => 'value',
    '#value' => $last == 'Never' ? new DateTime() : new DateTime($last),
  );

  $form['description'] = array(
    '#markup' => '<p> import events from toptix that where created or changed from last run </p>',
    '#suffix' => '<p> last run at : ' . $last . '</p>',
  );

  $form['import'] = array(
    '#type' => 'submit',
    '#value' =>  t('Import'),
  );

  return $form;
}

function cinematic_toptix_import_submit($form, &$form_state) {
  $message = TopTixImport::import();
  drupal_set_message($message);
}

class TopTixImport {
  public static function import() {
    variable_set('toptix_import', date('Y-m-d H:i:s'));
    $url = 'http://' . TOPTIX_HOST . '/feed/events/?groupby=show&withfutureevents=true';
    $context = stream_context_create(array('http' => array('timeout' => 1200)));
    $in = file_get_contents($url, false, $context);
    $xml = new TopTixReader();
    $xml->xml($in);
    list($total_shows, $total_events) = $xml->read_shows();
    $holders = array('@count1' => $total_shows, '@count2' => $total_events);
    return t('imported @count1 shows and @count2 events', $holders);
  }
}

class TopTixContext {
  public $shows;
  public $show;
  public $event;
  public $context;
  public $key = '';
  public $batch = 0;
  public $total_shows = 0;
  public $total_events = 0;
}

class TopTixReader extends XMLReader {
  private $toptix;

  public function read_shows() {
    $this->toptix = new TopTixContext();
    $this->toptix->shows = array();
    while ($this->read()) {
      if ($this->nodeType == XMLReader::ELEMENT) {
        $this->process_element();
      }
      if ($this->nodeType == XMLReader::TEXT and $this->toptix->key != '') {
        $this->toptix->context[$this->toptix->key] = $this->value;
        $this->toptix->key = '';
      }
      if ($this->nodeType == XMLReader::END_ELEMENT) {
        $this->process_end_element();
      }
    }
    if ($this->toptix->batch > 0) {
      $this->toptix->total_shows += $this->toptix->batch;
      $this->write_shows();
    }
    return array($this->toptix->total_shows, $this->toptix->total_events);
  }

  private function process_element() {
    switch ($this->name) {
      case 'Show':
        $this->toptix->context = &$this->toptix->show;
        break;
      case 'Event':
        $this->toptix->context = &$this->toptix->event;
        break;
      case 'Name':
      case 'ID':
      case 'EventId':
      case 'EventLocalId':
      case 'ActualEventDate':
      case 'LongMinutes':
      default:
        $this->toptix->key = $this->name;
        break;
    }
  }

  private function process_end_element() {
    switch ($this->name) {
      case 'Show':
        $this->toptix->shows[] = $this->toptix->show;
        if ($this->toptix->batch++ > 16) {
          $this->toptix->total_shows += $this->toptix->batch;
          $this->toptix->batch = 0;
          $this->write_shows();
          unset($this->toptix->shows);
          $this->toptix->shows = array();
        }
        unset($this->toptix->show);
        $this->toptix->show = array('events' => array());
        break;
      case 'events':
        break;
      case 'Event':
        $this->toptix->show['events'][] = $this->toptix->event;
        unset($this->toptix->event);
        $this->toptix->event = array();
        break;
    }
  }

  private function write_shows() {
    $ids = array();
    $transaction = db_transaction();
    foreach ($this->toptix->shows as $show) {
      $ids[] = $show['ID'];
      db_merge('toptix_shows')
        ->key(array('external_id' => $show['ID']))
        ->fields(array('title' => $show['Name']))
        ->execute();
    }
    $query = db_select('toptix_shows', 'ts');
    $query->fields('ts', array('external_id', 'id'));
    $query->condition('external_id', $ids, 'IN');
    $show_ids = $query->execute()->fetchAllKeyed();

    $this->write_events($show_ids);
  }

  private function write_events($show_ids) {
    foreach ($this->toptix->shows as $show) {
      $show_id = $show_ids[ $show['ID'] ];
      $interval = new DateInterval('PT' . $show['LongMinutes']. 'M');
      foreach ($show['events'] as $event) {
        $this->toptix->total_events++;
        $date = new DateTime($event['ActualEventDate']);
        $event['ActualEventDate'] = $date->format('c'); // add +02:00
        $end_date = $date->add($interval);
        $event['EndDate'] = $end_date->format('c');
        $event['LongMinutes'] = $show['LongMinutes'];
        db_merge('toptix_events')
          ->key(array('local_id' => $event['EventLocalId']))
          ->fields(array(
            'local_id' => $event['EventLocalId'],
            'external_id' => $event['EventId'],
            'show_id' => $show_id,
            'event_date' => $event['ActualEventDate'],
          ))
          ->execute();
        db_merge('toptix_events_data')
          ->key(array('local_id' => $event['EventLocalId']))
          ->fields(array(
            'local_id' => $event['EventLocalId'],
            'data' => serialize($event),
          ))
          ->execute();
      }
    }
  }
}
