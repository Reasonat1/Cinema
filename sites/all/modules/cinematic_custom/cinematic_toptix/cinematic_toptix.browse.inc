<?php
define('TOPTIX_TITLE_ORDER', 0);
define('TOPTIX_DATE_ORDER', 1);
define('TOPTIX_PAGER', 30);

function cinematic_toptix_browse() {
  $page = isset($_GET['page']) ? $_GET['page'] : 0;
  $order = isset($_GET['order']) ? $_GET['order'] : TOPTIX_TITLE_ORDER;

  $order_by_title = $order == TOPTIX_TITLE_ORDER;
  if ($order_by_title) {
    $shows = cinematic_toptix_browse_title($page);
  }
  else {
    $shows = cinematic_toptix_browse_date($page);
  }

  $selects = cinematic_toptix_browse_control($page, $order_by_title);

  $results = '<div class="browse-results">';

  foreach ($shows as $show_id => $show) {
    $title = '<h3>' . check_plain($show['title']) . '</h3>';
    $events = '<div class="events"> ' . $show['events'] . '</div>';
    $results .= $title . $events;
  }
  $results .= '</div>';
  drupal_json_output('<div class="browser-wrapper">' . $selects . $results . '</div>');
}

function cinematic_toptix_browse_control($page, $order_by_title) {
  $count = db_select('toptix_shows', 'ts')
    ->countQuery()
    ->execute()->fetchField();
  $options = '';
  for ($iter = 0; $iter*TOPTIX_PAGER < $count; $iter++) {
    $options .= '<option value="' . $iter . '"';
    if ($iter == $page) $options .= ' selected';
    $options .= " > $iter </option>";
  }
  $select_page = '<label>' . t('Pager') . '</label>' . '<select name="pager">' . $options . '</select>';

  $options = '<option value="0" ' . ($order_by_title ? 'selected' : '') . '> ' . t('Title') . ' </option>';
  $options .= '<option value="1" ' . ($order_by_title ? '' : 'selected') . '> ' . t('Date') . ' </option>';
  $select_order = '<label>' . t('Order by') . '</label>' . '<select name="order">' . $options . '</select>';

  return $select_page . $select_order;
}

function cinematic_toptix_browse_title($page) {
  $query = db_select('toptix_shows', 'ts');
  $offset = $page * TOPTIX_PAGER;
  $query->range($offset, TOPTIX_PAGER);
  $query->orderBy('ts.title');
  $query->fields('ts', array('id', 'title'));
  $shows = $query->execute()->fetchAllKeyed();

  $query = db_select('toptix_events', 'te');
  $query->condition('show_id', array_keys($shows), 'IN');
  $query->fields('te', array('show_id', 'local_id', 'event_date'));
  $events = $query->execute()->fetchAll();

  foreach ($events as $event) {
    if (!is_array($shows[$event->show_id])) {
      $title = $shows[$event->show_id];
      $shows[$event->show_id] = array('title' => $title, 'events' => '');
    }
    $shows[$event->show_id]['events'] .= "<div data-id=\"$event->local_id\"> $event->local_id : $event->event_date </div>";
  }
  return $shows;
}

function cinematic_toptix_browse_date($page) {

  $query = db_select('toptix_events', 'te');
  $query->groupBy('te.show_id');
  $query->addExpression('max(te.event_date)', 'max_date');
  $query->orderBy('max_date', 'DESC');
  $query->fields('te', array('show_id'));
  $offset = $page * 30;
  $query->range($offset, 30);
  $shows_ids = $query->execute()->fetchCol();

  $query = db_select('toptix_shows', 'ts');
  $query->join('toptix_events', 'te', 'te.show_id = ts.id');
  $query->condition('show_id', $shows_ids, 'IN');
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

  $ordered_shows = array();
  foreach ($shows_ids as $show_id) {
    $ordered_shows[$show_id] = $shows[$show_id];
  }
  return $ordered_shows;
}

