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
  $output = '';
  $results=$view->result;
  $movie_nid = $results[0]->node_field_data_field_cm_event_lineup_nid;
  $current_nid = arg(1);
    global $language ;
  $lang_name = isset($language->language) ? $language->language : '';
  if($lang_name == ''){
      $lang_name = 'en';
  }
   $result = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0')
WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$movie_nid' ) )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie')) AND (node.language IN  ('$lang_name')) )))
ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
   $output .= '<div class="table-responsive">';
    $output .= '<table class="views-table cols-8 table table-striped table-bordered">';
      $output .= '<thead>';
        $output .= '<tr>';
          $output .= '<th class="views-field views-field-field-cm-event-time">'. t('Date') .'</th>';
          $output .= '<th class="views-field views-field-field-cm-event-time-1">'. t('Time') .'</th>';
          $output .= '<th class="views-field views-field-field-cm-event-hall">'. t('Hall') .'</th>';
          $output .= '<th class="views-field views-field-field-cm-event-short-title">'. t('Event') .'</th>';
          $output .= '<th class="views-field views-field-field-cm-event-internal-id">'. t('Code') .'</th>';
          $output .= '<th class="views-field views-field-ops"></th>';
          $output .= '<th class="views-field views-field-php"></th>';
          $output .= '<th class="views-field views-field-field-toptix-purchase">'. t('Order Tickets') .'</th>';
        $output .= '</tr>';
      $output .= '</thead>';
      $output .= '<tbody>';
      $a= 0;
      $row_count = count($result);
      foreach($result as $val){
        $a++;
        $node = node_load($val->nid);
        if($val->nid !=$current_nid){
          $event_title = (!empty($node->field_cm_event_short_title)) ? $node->field_cm_event_short_title['und'][0]['value'] : $node->title;
          $path = drupal_get_path_alias('node/'.$node->nid);
           $flag = flag_create_link('favorite_', $node->nid);
           $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node).'</div>';
           if(!empty($node->field_cm_event_internal_id['und'])){
               $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
           }else{
             $event_code = '';
           }
           if(!empty($node->field_cm_event_time['und'])){
               $event_date = date('l d.m.y', $node->field_cm_event_time['und'][0]['value']);
               $event_time = date('g:i a', $node->field_cm_event_time['und'][0]['value']);
           }
           if(!empty($node->field_cm_event_hall['und'])){
               $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
               $hall_name = $hall_id->name;
           }else{
             $hall_name ='';
           }
           if(!empty($node->field_toptix_purchase['und'])){
               $toptix_code = $node->field_toptix_purchase['und'][0]['value'];
               $top_link = 'http://tickets.jer-cin.org.il/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
           }else {
             $top_link = '';
           }
         $output .= '<tr class="odd views-row-first views-row-last item-show-'.$a.'">';
           $output .= '<td class="views-field views-field-field-cm-event-time">'. $event_date. '</td>';
           $output .= '<td class="views-field views-field-field-cm-event-time-1">'. $event_time .'</td>';
           $output .= '<td class="views-field views-field-field-cm-event-hall">'. $hall_name .'</td>';
           $output .= '<td class="views-field views-field-field-cm-event-short-title">'. l($event_title, $path) .'</td>';
           $output .= '<td class="views-field views-field-field-cm-event-internal-id">' .$event_code .'</td>';
           $output .= '<td class="views-field views-field-ops">' .$flag .'</td>';
           $output .= '<td class="views-field views-field-php">' ._return_addthisevent_markup($node) .'</td>';
           if(!empty($top_link)) {
             $output .= '<td class="views-field views-field-field-toptix-purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">Puchase</button>'.'</td>';
          }
         $output .= '</tr>';
        }
      }
      $output .= '</tbody>';
    $output .= '</table>';
      $output .='<div class="view-footer">';
      if($row_count > 4){
       $output .='<div class="more-event">'. t('More Events').'</div>';
      }
      $output .='</div>';
  $output .= '</div>';
  print $output;
?>
