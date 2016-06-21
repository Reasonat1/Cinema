<?php
define('TOPTIX_TITLE_ORDER', 0);
define('TOPTIX_DATE_ORDER', 1);
define('TOPTIX_PAGER', 30);

function cinematic_toptix_browse() {
  $page = isset($_GET['page']) ? $_GET['page'] : 0;

  $shows = cinematic_toptix_browse_query($page);

  $filters = cinematic_toptix_browse_control($page);
  $output = theme('cinematic_browser', array('shows' => $shows, 'filters' => $filters));
  drupal_json_output($output);
}

function cinematic_toptix_browse_control($page) {
  $filters = array();

  $count = db_select('toptix_shows', 'ts')
    ->countQuery()
    ->execute()->fetchField();
  $options = '';
  for ($iter = 0; $iter*TOPTIX_PAGER < $count; $iter++) {
    $options .= '<option value="' . $iter . '"';
    if ($iter == $page) $options .= ' selected';
    $options .= " > $iter </option>";
  }
  $label = '<label>' . t('Pager') . '</label>';
  $filters['select_page'] = $label . '<select name="pager">' . $options . '</select>';

  $label = '<label>' . t('Title') . '</label>';
  $default = isset($_GET['title']) ? 'value="' . $_GET['title'] . '"' : '';
  $filters['title_search'] = $label . '<input ' . $default . 'class="form-text" type="text" size="15" name="title"></input>';

  $from = '<labe>' . t('From date') . '</label>';
  $from .= '<input class="form-text" type="text" size="15" name="date_from"></input>';
  $to = '<labe>' . t('To date') . '</label>';
  $to .= '<input class="form-text" type="text" size="15" name="date_to"></input>';
  $filters['date_range'] = $from . $to;

  return $filters; 
}

function cinematic_toptix_browse_query($page) {
  $query = db_select('toptix_events', 'te');
  $query->join('toptix_shows', 'ts', 'ts.id = te.show_id');
  $query->groupBy('te.show_id');
  $query->addExpression('max(te.event_date)', 'max_date');

  $order = TOPTIX_TITLE_ORDER;
  if ($_GET['date_range']) {
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

  if ($_GET['title']) {
    $query->condition('ts.title', '%' . $_GET['title'] . '%', 'LIKE');
  }

  if ($order == TOPTIX_DATE_ORDER) {
    $query->orderBy('max_date', 'DESC');
  }
  else {
    $query->orderBy('ts.title', 'DESC');
  }

  $offset = $page * 30;
  $query->range($offset, 30);

  $query->fields('ts', array('title'));
  $query->fields('te', array('show_id', 'local_id', 'event_date'));
  $events = $query->execute()->fetchAll();

  $shows = array();
  foreach ($events as $event) {
    if (!isset($shows[$event->show_id])) {
      $shows[$event->show_id] = array('title' => $event->title, 'events' => '');
    }
    $shows[$event->show_id]['events'] .= "<div data-id=\"$event->local_id\"> $event->local_id : $event->event_date </div>";
  }
  return $shows;
}

