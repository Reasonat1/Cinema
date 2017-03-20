<?php
define('TOPTIX_TITLE_ORDER', 0);
define('TOPTIX_DATE_ORDER', 1);
define('TOPTIX_PAGER', 30);

function cinematic_toptix_browse($bundle) {
  $page = isset($_GET['page']) ? $_GET['page'] : 0;

  list($items, $total, $data) = cinematic_toptix_browse_query($page, $bundle);

  $filters = cinematic_toptix_browse_control($page, $total, $bundle);
  $variables = array( 'items' => $items, 'filters' => $filters, 'bundle' => $bundle);
  $output = theme('cinematic_browser', $variables);
  if (isset($_GET['html'])) {
    if ($data) {
      dpm($data);
    }
    else {
      dpm($items);
    }
    return 'output';
  }
  else {
    drupal_json_output(array('results' => $output, 'data' => $data));
  }
}

function cinematic_toptix_browse_control($page, $total, $bundle) {
  $filters = array();

  $options = '';
  for ($iter = 0; $iter * TOPTIX_PAGER < $total; $iter++) {
    $options .= '<option value="' . $iter . '"';
    if ($iter == $page) $options .= ' selected';
    $options .= " > $iter </option>";
  }
  $label = '<label>' . t('Pager') . '</label>';
  $filters['select_page'] = '<div class="filter">'.$label . '<select name="pager">' . $options . '</select></div>';

  $label = '<label>' . t('Title') . '</label>';
  $default = isset($_GET['title']) ? 'value="' . $_GET['title'] . '"' : '';
  $filters['title_search'] = '<div class="filter">'.$label . '<input ' . $default . ' class="form-text" type="text" size="15" name="title"></input></div>';

  if ($bundle != 'hall') {
    $date_range = isset($_GET['date_range']) ? explode(':', $_GET['date_range']) : array(0, 0);

    $from = '<label>' . t('From date') . '</label>';
    $default = $date_range[0] ? 'value=' . $date_range[0] : '';
    $from .= '<input ' . $default . ' class="form-text" type="text" size="15" name="date_from"></input>';

    $to = '<label>' . t('To date') . '</label>';
    $default = $date_range[1] ? 'value=' . $date_range[1] : '';
    $to .= '<input ' . $default . ' class="form-text" type="text" size="15" name="date_to"></input>';
    $filters['date_range'] = '<div class="filter">'.$from.'</div><div class="filter">'.$to.'</div>';
  }

  return $filters; 
}

function cinematic_toptix_browse_query($page, $bundle) {
  if ($bundle == 'hall') {
    return cinematic_toptix_browse_query_hall($page);
  }
  $now = new DateTime();
  $today = $now->format('Y-m-d');
  $query = db_select('toptix_events', 'te');
  $query->condition('te.event_date', $today, '>');
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

  $query->addField('ts', 'id');

  $offset = $page * 30;
  $query->range($offset, 30);
  $show_ids = $query->execute()->fetchCol();
  if (!$show_ids) {
    return array(array(), 0, array());
  }

  $events_query = db_select('toptix_events', 'te');
  $events_query->condition('te.event_date', $today, '>');
  $events_query->join('toptix_shows', 'ts', 'ts.id = te.show_id');
  $events_query->condition('te.show_id', $show_ids, 'IN');
  $events_query->fields('ts', array('title', 'code'));
  $events_query->fields('te', array('show_id', 'local_id', 'event_date'));
  $events = $events_query->execute()->fetchAll();

  $shows = array();
  $event_ids = array();
  foreach ($events as $event) {
    $event_ids[] = $event->local_id;
    if (!isset($shows[$event->show_id])) {
      $shows[$event->show_id] = array(
        'title' => "{$event->title} : {$event->code}",
        'options' => ''
      );
    }
    $shows[$event->show_id]['options'] .= "<div data-id=\"$event->local_id\"> $event->local_id : $event->event_date </div>";
  }

  if ($event_ids) {
    $query = db_select('toptix_events_data', 'ted');
    $query->condition('local_id', $event_ids, 'IN');
    $query->fields('ted', array('local_id', 'data'));
    $data = $query->execute()->fetchAllKeyed();
    foreach ($data as $id => &$event_data) {
      $event_data = unserialize($event_data);
    }
    cinematic_toptix_browse_event_halls($event_ids, $data);
  }
  else {
    $data = array();
  }

  return array($shows, $count, $data);
}

function cinematic_toptix_browse_event_halls($event_ids, &$data) {

  $language = isset($_GET['language']) ? $_GET['language'] : 'en';
  
  $query = db_select('toptix_events', 'te');
  $query->condition('te.local_id', $event_ids, 'IN');
  $query->join('field_data_field_toptix_purchase', 'tp', 'tp.field_toptix_purchase_value = te.hall_id');
  $query->condition('tp.bundle', 'hall');
  $query->join('taxonomy_term_data', 'td', 'td.tid = tp.entity_id');
  if ($language != 'und') {
    $query->condition('td.language', $language);
  }
  $query->fields('td', array('tid', 'name'));
  $query->addField('te', 'local_id', 'event_id');
  $hall_terms = $query->execute()->fetchAll();

  foreach ($hall_terms as $term) {
    $name = check_plain($term->name);
    $match = "$name ({$term->tid})";
    $data[$term->event_id]['hall_term'] = $match;
  }
}

function cinematic_toptix_browse_query_hall($page) {

  $query = db_select('toptix_halls', 'ha');
  if (isset($_GET['title'])) {
    $query->condition('ha.title', '%' . $_GET['title'] . '%', 'LIKE');
  }
  $count = $query->countQuery()->execute()->fetchField();

  $query->fields('ha');

  $offset = $page * 30;
  $query->range($offset, 30);
  $halls = $query->execute()->fetchAll();
  if (!$halls) {
    return array(array(), 0, array());
  }

  $halls_items = array();
  foreach ($halls as $hall) {
    $halls_items[$hall->id] = array(
      'title' => $hall->title,
    );
  }

  $data = '';
  return array($halls_items, $count, $data);
}
