<?php
define('TOPTIX_TITLE_ORDER', 0);
define('TOPTIX_DATE_ORDER', 1);
define('TOPTIX_PAGER', 30);

function cinematic_toptix_browse() {
  $page = isset($_GET['page']) ? $_GET['page'] : 0;

  list($shows, $total, $data) = cinematic_toptix_browse_query($page);

  $filters = cinematic_toptix_browse_control($page, $total);
  $output = theme('cinematic_browser', array('shows' => $shows, 'filters' => $filters));
  drupal_json_output(array('results' => $output, 'data' => $data));
}

function cinematic_toptix_browse_control($page, $total) {
  $filters = array();

  $options = '';
  for ($iter = 0; $iter * TOPTIX_PAGER < $total; $iter++) {
    $options .= '<option value="' . $iter . '"';
    if ($iter == $page) $options .= ' selected';
    $options .= " > $iter </option>";
  }
  $label = '<label>' . t('Pager') . '</label>';
  $filters['select_page'] = $label . '<select name="pager">' . $options . '</select>';

  $label = '<label>' . t('Title') . '</label>';
  $default = isset($_GET['title']) ? 'value="' . $_GET['title'] . '"' : '';
  $filters['title_search'] = $label . '<input ' . $default . ' class="form-text" type="text" size="15" name="title"></input>';


  $date_range = isset($_GET['date_range']) ? explode(':', $_GET['date_range']) : array(0, 0);

  $from = '<labe>' . t('From date') . '</label>';
  $default = $date_range[0] ? 'value=' . $date_range[0] : '';
  $from .= '<input ' . $default . ' class="form-text" type="text" size="15" name="date_from"></input>';

  $to = '<labe>' . t('To date') . '</label>';
  $default = $date_range[1] ? 'value=' . $date_range[1] : '';
  $to .= '<input ' . $default . ' class="form-text" type="text" size="15" name="date_to"></input>';
  $filters['date_range'] = $from . $to;

  return $filters; 
}

function cinematic_toptix_browse_query($page) {
  $query = db_select('toptix_events', 'te');
  $query->join('toptix_shows', 'ts', 'ts.id = te.show_id');
  $query->groupBy('te.show_id');
  $query->addExpression('max(te.event_date)', 'max_date');

  $order = TOPTIX_TITLE_ORDER;
  if (isset($_GET['date_range'])) {
    $date_range = $_GET['date_range'];
    $date_range = explode(':', $date_range);
    if ($date_range[0]) {
      $query->condition('te.event_date', $date_range[0], '>=');
      $order = TOPTIX_DATE_ORDER;
    }
    if ($date_range[1]) {
      $query->condition('te.event_date', $date_range[1], '<=');
      $order = TOPTIX_DATE_ORDER;
    }
  }

  if (isset($_GET['title'])) {
    $query->condition('ts.title', '%' . $_GET['title'] . '%', 'LIKE');
  }

  if ($order == TOPTIX_DATE_ORDER) {
    $query->orderBy('max_date', 'DESC');
  }
  else {
    $query->orderBy('ts.title', 'DESC');
  }

  $count = $query->countQuery()->execute()->fetchField();

  $query->fields('ts', array('title'));
  $query->fields('te', array('show_id', 'local_id', 'event_date'));

  $offset = $page * 30;
  $query->range($offset, 30);

  $events = $query->execute()->fetchAll();

  $shows = array();
  $event_ids = array();
  foreach ($events as $event) {
    $event_ids[$event->local_id] = $event->title;
    if (!isset($shows[$event->show_id])) {
      $shows[$event->show_id] = array('title' => $event->title, 'events' => '');
    }
    $shows[$event->show_id]['events'] .= "<div data-id=\"$event->local_id\"> $event->local_id : $event->event_date </div>";
  }

  if ($event_ids) {
    $query = db_select('toptix_events_data', 'ted');
    $query->condition('local_id', array_keys($event_ids), 'IN');
    $query->fields('ted', array('local_id', 'data'));
    $data = $query->execute()->fetchAllKeyed();
    foreach ($data as $id => &$event_data) {
      $event_data = unserialize($event_data);
      $event_data['title'] = $event_ids[$id];
    }
  }
  else {
    $data = array();
  }

  return array($shows, $count, $data);
}

