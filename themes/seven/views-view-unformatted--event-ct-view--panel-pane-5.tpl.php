<?php
/**
 * @file views-exposed-form.tpl.php
 *
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php
$results=$view->result;
$current_nid = $results[0]->nid;
    $tagetId = $results[0]->field_field_cm_event_lineup[0]['raw']['target_id'];
    $query = "SELECT entity_id FROM {field_data_field_cm_event_lineup} WHERE field_cm_event_lineup_target_id = " . $tagetId . "";
	$rs = db_query($query);
    print '<div class="table-responsive">';
    print '<table class="table">';
    print '<thead>';
      print '<tr>';
        print '<th>'.t('Date').'</th>';
        print '<th>'.t('Time').'</th>';
        print '<th>'.t('Hall').'</th>';
        print '<th>'.t('Event Title').'</th>';
        print '<th>'.t('Event Code').'</th>';
      print '</tr>';
    print '</thead>';
    print ' <tbody>';
    $i = 0;
	foreach ($rs as $row) {
        $event_ref_nid = $row->entity_id;
        $array = array($event_ref_nid); 
        $array_without_current_event = array_diff($array, array($current_nid));
        $node = node_load($array_without_current_event[0]);
        if(!empty($node)){
            $i++;
            $event_title = $node->title;
            $path = drupal_get_path_alias('node/'.$node->nid);
            $event_date = date('l d.m.y', $node->field_cm_event_time['und'][0]['value']);
            $event_time = date('g:i a', $node->field_cm_event_time['und'][0]['value']);
            $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
            $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
            $hall_name = $hall_id->name;
            //drupal_set_message('<pre>'.print_r($hall_id->name, 1).'</pre>');
            print '<tr class="'.' common-row row-custom-'.$i.'">';
            print '<td>'.$event_date.'</td>';
            print '<td>'.$event_time.'</td>';
            print '<td>'.$hall_name.'</td>';
            print '<td>'.l($event_title, $path).'</td>';
            print '<td>'.$event_code.'</td>';
            print '</tr>';
        }
	}
    print '</table>';
    print '<div class="more-event">Show more screenings</div>';
    print '</div>';
?>
