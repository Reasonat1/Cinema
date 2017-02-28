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
  $myNow=time();
  $results=$view->result;
  $movie_nid = $results[0]->node_field_data_field_cm_event_lineup_nid;
  $node_type = node_load($movie_nid);
  $types = $node_type->type;
  $current_nid = arg(1);
    global $language ;
  $lang_name = isset($language->language) ? $language->language : '';
  if($lang_name == ''){
      $lang_name = 'en';
  }
   $result = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0')
WHERE ((( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$movie_nid' ) )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('$types')) AND (node.language IN  ('$lang_name'))))) AND (field_data_field_cm_event_time.field_cm_event_time_value > '$myNow') AND (node.nid != '$current_nid'))
ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();

  $row_count = count($result);
  if($row_count > 0){
    $output .= '<div class="table-responsive">';
     $output .= '<table class="views-table cols-8 table table-striped table-bordered">';
       $output .= '<thead>';
         $output .= '<tr>';
           $output .= '<th class="views-field views-field-field-cm-event-time-1 date test">'. t('Date') .'</th>';
           $output .= '<th class="views-field views-field-field-cm-event-time first-mobile time">'. t('Time') .'</th>';
           $output .= '<th class="views-field views-field-field-cm-event-hall hall">'. t('Hall') .'</th>';
           $output .= '<th class="views-field views-field-field-cm-event-short-title views-field-title title">'. t('Event') .'</th>';
           $output .= '<th class="views-field views-field-field-cm-event-internal-id code">'. t('Code') .'</th>';
           $output .= '<th class="views-field views-field-ops like-flag"></th>';
           $output .= '<th class="views-field views-field-php add-event"></th>';
          $output .= '<th class="views-field views-field-field-toptix-purchase last-mobile purchase">'. t('TICKETS') .'</th>';
         $output .= '</tr>';
       $output .= '</thead>';
       $output .= '<tbody>';
       $a= 0;
       $row_count = count($result);
       foreach($result as $val){
         $a++;
         $node = node_load($val->nid);
         
         if($val->nid !=$current_nid){
           if(!empty($node->nid)){
             //$event_title = (!empty($node->field_cm_event_short_title)) ? $node->field_cm_event_short_title['und'][0]['value'] : $node->title;
             $title_new = (!empty($node->field_cm_event_comment)) ? $node->field_cm_event_comment['und'][0]['value'] : '';
           }else{
             $title_new = '<div class="hide-div"></div>';
           }
           $path = drupal_get_path_alias('node/'.$node->nid);
            $flag = flag_create_link('favorite_', $node->nid);
            $addevent = '<div class="views-field views-field-php add-event">'._return_addthisevent_markup($node).'</div>';
            if(!empty($node->field_cm_event_internal_id['und'])){
                $event_code = t($node->field_cm_event_internal_id['und'][0]['value']);
            }else{
              $event_code = '';
            }
             if(!empty($node->field_cm_event_time['und'])){
               $event_date = '<span class="day-same-width">'.format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'l').'</span>';
               $event_date .= format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', ' d.m.y');
               $event_date_mobile = date('d.m.y', $node->field_cm_event_time['und'][0]['value']);
             }else{
                $event_date = '<div class="hide-div"></div>';
             }
            if(!empty($node->field_cm_event_time['und'])){
                $event_time = date('H:i', $node->field_cm_event_time['und'][0]['value']);
            }else{
                $event_time = '<div class="hide-div"></div>';
            }
            if(!empty($node->field_cm_event_hall['und'])){
                $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
                $hall_name = t($hall_id->name);
            }else{
              $hall_name = '<div class="hide-div"></div>';
            }
            if(!empty($node->field_toptix_purchase['und'])){
                 $toptix_code = $node->field_toptix_purchase['und'][0]['value'];
                 $top_link = 'http://tickets.jer-cin.org.il/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
                 if(empty($node->field_tickets_sold_out['und'][0]['value'])){
                    $puchase = '<button data-url="'.$top_link.'" class="toptix-purchase">'.t('TICKETS').'</button>';
                  }
                  else{
                    $puchase = '<button class="sold-out">'.t('sold out').'</button>';
                  }
            }else{
               $puchase = '<div class="hide-div"></div>';
            }
            
          $output .= '<tr class="odd views-row-first up-events-item-movie views-row-last item-show-'.$a.'">';
           $output .= '<td class="views-field views-field-field-cm-event-time-1 only-desktop date">'. $event_date. '</td>';
           $output .= '<td class="views-field views-field-field-cm-event-time first-mobile time"><div class="only-mobile">'.$event_date_mobile. '</div>' . $event_time .'</td>';
           $output .= '<td class="views-field views-field-field-cm-event-hall hall">'. $hall_name .'<div class="only-mobile">'.$event_code.'</td>';
           $output .= '<td class="views-field views-field-title views-field-field-cm-event-short-title only-desktop title">'. l($title_new, $path) .'</td>';
           $output .= '<td class="views-field views-field-field-cm-event-internal-id only-desktop code">'.$event_code.'</td>';
           $output .= '<td class="views-field views-field-ops only-desktop like-flag">' .$flag .'</td>';
           $output .= '<td class="views-field views-field-php add-event only-desktop">' ._return_addthisevent_markup($node) .'</td>';
           $output .= '<td class="views-field views-field-field-toptix-purchase last-mobile purchase">'.$puchase.'</td>';
          $output .= '</tr>';
         }
       }
       $output .= '</tbody>';
     $output .= '</table>';
       $output .='<div class="view-footer">';
       if($row_count > 0){
        $output .='<div class="more-event event-page"><span class="only-mobile"> - </span><span class="text text-open-event">'. t('For more screenings press here'). '</span><span class="text text-close-event">'. t('Less Screenings'). '</span><span class="only-mobile"> - </span></div>';
       }
       $output .='</div>';
    $output .= '</div>';
    print $output;
  }else{
    print '<div class="hide-table"></div>';
  }
?>