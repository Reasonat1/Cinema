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
foreach ($results as $val) {
  $nid = $val->node_taxonomy_index_nid;
  $node = node_load($nid);
  //drupal_set_message('<pre>'.print_r($nid, 1).'</pre>');
  // drupal_set_message('<pre>'.print_r($node, 1).'</pre>');
}
//$current_nid = $results[0]->nid;
//    print '<div class="table-responsive">';
//    print '<table class="table">';
//    print '<thead>';
//      print '<tr>';
//        print '<th>'.t('Date').'</th>';
//        print '<th>'.t('Time').'</th>';
//        print '<th>'.t('Hall').'</th>';
//        print '<th>'.t('Event Title').'</th>';
//        print '<th>'.t('Event Code').'</th>';
//		print '<th>'.t('Toptix purchase').'</th>';
//      print '</tr>';
//    print '</thead>';
//    print ' <tbody>';
//    $i = 0;
//	foreach ($rs as $row) {
//        $event_ref_nid = $row->entity_id;
//        $array = array($event_ref_nid); 
//        $array_without_current_event = array_diff($array, array($current_nid));
//		if(!empty($array_without_current_event[0])){
//        $node = node_load($array_without_current_event[0]);
//            $i++;
//            $event_title = $node->title;
//            $path = drupal_get_path_alias('node/'.$node->nid);
//			if(!empty($node->field_cm_event_internal_id['und'])){
//				$event_code = $node->field_cm_event_internal_id['und'][0]['value'];
//			}
//			if(!empty($node->field_cm_event_time['und'])){
//				$event_date = date('l d.m.y', $node->field_cm_event_time['und'][0]['value']);
//				$event_time = date('g:i a', $node->field_cm_event_time['und'][0]['value']);
//			}
//			if(!empty($node->field_cm_event_hall['und'])){
//				$hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
//				$hall_name = $hall_id->name;
//			}
//			if(!empty($node->field_toptix_purchase['und'])){
//				$toptix_code = $node->field_toptix_purchase['und'][0]['value'];
//			}
//			//print field_view_field('node', $node, 'field_toptix_purchase', 'full')
//           //drupal_set_message('<pre>'.print_r(field_view_field('node', $node, 'field_toptix_purchase', 'full'), 1).'</pre>');
//            print '<tr class="'.'row-custom-'.$i.'">';
//            print '<td>'.$event_date.'</td>';
//            print '<td>'.$event_time.'</td>';
//            print '<td>'.$hall_name.'</td>';
//            print '<td>'.l($event_title, $path).'</td>';
//            print '<td>'.$event_code.'</td>';
//			print '<td>'.'<button data-url="http://199.203.164.53/loader.aspx/?target=hall.aspx?event="'.$toptix_code.'" class="toptix-purchase">Puchase</button>'.'</td>';
//            print '</tr>';
//        }
//	}
//    print '</table>';
//    print '<div class="more-event">More Events</div>';
//    print '</div>';
?>
