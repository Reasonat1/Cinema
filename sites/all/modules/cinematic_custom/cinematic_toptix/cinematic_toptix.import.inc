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

  $form['custom_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom date'),
    '#description' => 'Example: 2016-10-21',
    '#size' => 16,
  );

  $form['import'] = array(
    '#type' => 'submit',
    '#value' =>  t('Import'),
  );

  return $form;
}

function cinematic_toptix_import_validate($form, &$form_state) {
  $custom_date = $form_state['values']['custom_date'];
  if ($custom_date) {
    try {
      $custom_date = new DateTime($custom_date);
      $form_state['values']['custom_run'] = $custom_date;
    }
    catch (Exception $e) {
      form_set_error('custom_date', $e->getMessage());
    }
  }
}

function cinematic_toptix_import_submit($form, &$form_state) {
  $last_run = $form_state['values']['last_run'];
  variable_set('toptix_import', date('Y-m-d H:i:s'));
  if (isset($form_state['values']['custom_run'])) {
    $last_run = $form_state['values']['custom_run'];
  }
  $lastupdate = $last_run->format('Y-m-d');
  //$url = 'http://' . TOPTIX_HOST . '/feed/events/?groupby=show&lastupdate=' . $lastupdate;
  $url = 'http://' . TOPTIX_HOST . '/feed/events/?groupby=show';
  $context = stream_context_create(array('http' => array('timeout' => 1200)));
  $in = file_get_contents($url, false, $context);
  $xml = new TopTixReader();
  $xml->xml($in);
  list($total_shows, $total_events) = $xml->read_shows();
  $holders = array('@count1' => $total_shows, '@count2' => $total_events);
  drupal_set_message(t('imported @count1 shows and @count2 events', $holders));
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
    db_delete('toptix_events')->execute();
    db_delete('toptix_events_data')->execute();
    db_delete('toptix_shows')->execute();

    $shows_insert = db_insert('toptix_shows');
    $shows_insert->fields(array('external_id', 'title'));
    foreach ($this->toptix->shows as $show) {
      $shows_insert->values(array($show['ID'], $show['Name']));
    }
    $shows_insert->execute();
    $query = db_select('toptix_shows', 'ts');
    $query->fields('ts', array('external_id', 'id'));
    $show_ids = $query->execute()->fetchAllKeyed();

    $this->write_events($show_ids);
  }

  private function write_events($show_ids) {
    $events_insert = db_insert('toptix_events');
    $events_insert->fields(array('local_id', 'external_id', 'show_id', 'event_date'));

    $data_insert = db_insert('toptix_events_data');
    $data_insert->fields(array('local_id', 'data'));

    foreach ($this->toptix->shows as $show) {
      $show_id = $show_ids[ $show['ID'] ];
      foreach ($show['events'] as $event) {
        $this->toptix->total_events++;
        $events_insert->values(array(
          $event['EventLocalId'],
          $event['EventId'],
          $show_id,
          $event['ActualEventDate'],
        ));
        $data_insert->values(array(
          $event['EventLocalId'],
          serialize($event),
        ));
      }
    }
    $events_insert->execute();
    $data_insert->execute();
  }
}

