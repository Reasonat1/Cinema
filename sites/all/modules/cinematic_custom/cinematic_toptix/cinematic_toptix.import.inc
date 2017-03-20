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
  $messages = TopTixImport::import();
  drupal_set_message($messages[0]);
  drupal_set_message($messages[1]);
  $time_zone = new DateTimeZone('Asia/Jerusalem');
  $now = new DateTime('now', $time_zone);
  variable_set('toptix_import', $now->format('c'));
}

class TopTixImport {

  public static function import() {
    $messages = array();
    $messages[] = self::import_halls();
    $url = 'http://' . TOPTIX_HOST . '/feed/events/?groupby=show&withfutureevents=true';
    $context = stream_context_create(array('http' => array('timeout' => 1200)));
    $in = file_get_contents($url, false, $context);
    $xml = new TopTixReader();
    $xml->xml($in);
    list($total_shows, $total_events) = $xml->read_shows();
    unset($in);
    $holders = array('@count1' => $total_shows, '@count2' => $total_events);
    $messages[] = t('imported @count1 shows and @count2 events', $holders);
    return $messages;
  }

  public static function import_halls() {
    $url = 'http://' . TOPTIX_HOST . '/feed/halls';
    $context = stream_context_create(array('http' => array('timeout' => 1200)));
    $in = file_get_contents($url, false, $context);
    $xml = new TopTixHallReader();
    $xml->xml($in);
    $total = $xml->read_halls();
    unset($in);
    return t('imported @count halls', array('@count' => $total));
  }

  public static function process_data() {
    $query = db_select('toptix_events_data', 'ed');
    $query->fields('ed');
    $events = $query->execute()->fetchAll();
    $time_zone = new DateTimeZone('Asia/Jerusalem');
    $interval = new DateInterval('PT180M');
    $reader = new TopTixReader();
    foreach ($events as $event) {
      $event = unserialize($event->data);
      $reader->alter_dates($event, $time_zone, $interval);
      $event['LongMinutes'] = 180;
      db_merge('toptix_events_data')
        ->key(array('local_id' => $event['EventLocalId']))
        ->fields(array(
          'local_id' => $event['EventLocalId'],
          'data' => serialize($event),
        ))
     ->execute();
    }
  }

  public static function create_events($movie) {
    $toptix_purchase = field_get_items('node', $movie, 'field_toptix_purchase');
    if (!$toptix_purchase) {
      return;
    }
    $show_id = $toptix_purchase[0]['value'];
    $create_events = $toptix_purchase[0]['events'];
    if (!$show_id or !$create_events) {
      return;
    }

    $existing_events = self::fetch_existing_events($movie->nid);
    $events = self::fetch_toptix_events($show_id);

    foreach ($events as &$event) {
      if ($existing_events and isset($existing_events[$event->local_id])) {
        continue;
      }
      $event->data = unserialize($event->data);
      $new_id = self::create_event($event, $movie);
      $params = array(
        '!link' => l($new_id, 'node/' . $new_id),
      );
      drupal_set_message(t('Created event !link', $params));
    }
  }

  public static function create_event($event, $movie) {
    $event_node = entity_create('node', array('type' => 'cm_event'));
    $event_node->uid = $movie->uid;
    $event_node->language = $movie->language;
    $wrapper = entity_metadata_wrapper('node', $event_node);
    $wrapper->title = $movie->title;
    $wrapper->field_toptix_purchase = $event->local_id;
    $wrapper->field_cm_event_lineup->set(array($movie->nid));
    $start_date = new DateTime($event->data['ActualEventDate']);
    $end_date = new DateTime($event->data['EndDate']);
    $event_time = array(
      'value' => $start_date->getTimestamp(), 
      'value2' => $end_date->getTimestamp(),
      'timezone' => 'Asia/Jerusalem',
    );
    $wrapper->field_cm_event_time->set($event_time);

    if (isset($event->data['EndSaleAt'])) {
      $start_date = new DateTime($event->data['StartSaleFrom']);
      $end_date = new DateTime($event->data['EndSaleAt']);
      $sale_time = array(
        'value' => $start_date->getTimestamp(), 
        'value2' => $end_date->getTimestamp(),
        'timezone' => 'Asia/Jerusalem',
      );
      $wrapper->field_cm_sale_time->set($sale_time);
    }
    $wrapper->field_tickets_sold_out->set($event->data['SoldOut'] != 'False');
    $wrapper->field_include_ticket_sale->set($event->data['SaleStatus'] == 'Open');
    $wrapper->field_cm_event_onsale->set(TRUE);

    $wrapper->save();
    return $wrapper->getIdentifier();
  }

  public static function fetch_existing_events($movie_nid) {
    $query = db_select('field_data_field_cm_event_lineup', 'el');
    $query->condition('field_cm_event_lineup_target_id', $movie_nid);
    $query->condition('el.entity_type', 'node');
    $query->join('field_data_field_toptix_purchase', 'tp', 'tp.entity_id = el.entity_id');
    $query->condition('tp.bundle', 'cm_event');
    $query->addField('tp', 'field_toptix_purchase_value');
    $query->addExpression('1');
    return $query->execute()->fetchAllKeyed();
  }

  public static function fetch_toptix_events($show_id) {
    $query = db_select('toptix_shows', 'ts');
    $query->condition('te.show_id', $show_id);
    $query->join('toptix_events', 'te', 'ts.id = te.show_id');
    $query->join('toptix_events_data', 'ted', 'ted.local_id = te.local_id');
    $query->fields('te', array('local_id', 'event_date'));
    $query->fields('ted', array('data'));
    return $query->execute()->fetchAll();
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
      case 'Code':
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
    $fields = array();
    foreach ($this->toptix->shows as $show) {
      $ids[] = $show['ID'];
      $fields['title'] = $show['Name'];
      $fields['code'] = $show['Code'];
      db_merge('toptix_shows')
        ->key(array('external_id' => $show['ID']))
        ->fields($fields)
        ->execute();
    }
    $query = db_select('toptix_shows', 'ts');
    $query->fields('ts', array('external_id', 'id'));
    $query->condition('external_id', $ids, 'IN');
    $show_ids = $query->execute()->fetchAllKeyed();

    $this->write_events($show_ids);
  }

  private function write_events($show_ids) {
    $time_zone = new DateTimeZone('Asia/Jerusalem');
    foreach ($this->toptix->shows as $show) {
      $show_id = $show_ids[ $show['ID'] ];
      $interval = new DateInterval('PT' . $show['LongMinutes']. 'M');
      foreach ($show['events'] as $event) {
        $this->toptix->total_events++;
        $mysql_ActualEventDate = $event['ActualEventDate'];
        $this->alter_dates($event, $time_zone, $interval);
        $event['LongMinutes'] = $show['LongMinutes'];
        db_merge('toptix_events')
          ->key(array('local_id' => $event['EventLocalId']))
          ->fields(array(
            'local_id' => $event['EventLocalId'],
            'external_id' => $event['EventId'],
            'show_id' => $show_id,
            'event_date' => $mysql_ActualEventDate,
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
  
  public function alter_dates(&$event, $time_zone, $interval) {
    $date = new DateTime($event['ActualEventDate'], $time_zone);
    $event['ActualEventDate'] = $date->format('c'); // add +02:00
    $end_date = $date->add($interval);
    $event['EndDate'] = $end_date->format('c');
    unset($date, $end_date);

    if (isset($event['EndSaleAt'])) {
      $end_date = new DateTime($event['EndSaleAt'], $time_zone);
      $event['EndSaleAt'] = $end_date->format('c');
    }
    elseif(0) {
      $params = "{$event['ActualEventDate']}, {$event['EventLocalId']}";
      watchdog('toptix import', 'end sale not set:' . $params);
    }
    if (isset($event['StartSaleFrom'])) {
      $start_date = new DateTime($event['StartSaleFrom'], $time_zone);
      $event['StartSaleFrom'] = $start_date->format('c');
    }
    elseif (0) {
      $params = "{$event['ActualEventDate']}, {$event['EventLocalId']}";
      watchdog('toptix import', 'start sale not set:' . $params);
    }
    unset($end_date, $start_date);
  }
}

class TopTixHallsContext {
  public $halls;
  public $hall;
  public $key = '';
  public $batch = 0;
  public $total_halls = 0;
}

class TopTixHallReader extends XMLReader {
  private $toptix;

  public function read_halls() {
    $this->toptix = new TopTixHallsContext();
    $this->toptix->halls = array();
    while ($this->read()) {
      if ($this->nodeType == XMLReader::ELEMENT) {
        $this->process_element();
      }
      if ($this->nodeType == XMLReader::TEXT and $this->toptix->key != '') {
        $this->toptix->hall[$this->toptix->key] = $this->value;
        $this->toptix->key = '';
      }
      if ($this->nodeType == XMLReader::END_ELEMENT) {
        $this->process_end_element();
      }
    }
    if ($this->toptix->batch > 0) {
      $this->toptix->total_halls += $this->toptix->batch;
      $this->write_halls();
    }
    return $this->toptix->total_halls;
  }

  private function process_element() {
    switch ($this->name) {
      case 'Name':
      case 'Id':
      case 'LocalId':
        $this->toptix->key = $this->name;
        break;
    }
  }

  private function process_end_element() {
    switch ($this->name) {
      case 'Hall':
        $this->toptix->halls[] = $this->toptix->hall;
        if ($this->toptix->batch++ > 16) {
          $this->toptix->total_halls += $this->toptix->batch;
          $this->toptix->batch = 0;
          $this->write_halls();
          unset($this->toptix->halls);
          $this->toptix->halls = array();
        }
        unset($this->toptix->hall);
        $this->toptix->hall = array();
        break;
    }
  }

  private function write_halls() {
    $ids = array();
    $transaction = db_transaction();
    $fields = array();
    foreach ($this->toptix->halls as $hall) {
      $fields['title'] = $hall['Name'];
      $fields['local_id'] = $hall['LocalId'];
      db_merge('toptix_halls')
        ->key(array('external_id' => $hall['Id']))
        ->fields($fields)
        ->execute();
    }
  }
}
