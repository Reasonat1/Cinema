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
     //drupal_set_message('<pre>'.print_r($node->type, 1).'</pre>');
    $path_node = drupal_get_path_alias('node/'.$node->nid);
    $title = l($node->title, $path_node);
    if(!empty($node->field_mc_teaser_toptxt_white['und'])){
     $white_text = $node->field_mc_teaser_toptxt_white['und'][0]['value'];  
    }
    if(!empty($node->field_mc_teaser_toptxt_blk['und'])){
     $black_text = $node->field_mc_teaser_toptxt_blk['und'][0]['value'];  
    }
    if(!empty($node->field_cm_movie_duration)){
      $length_interval = $node->field_cm_movie_duration['und'][0]['interval'];
      $length_period = $node->field_cm_movie_duration['und'][0]['period'];
      $length = $length_interval.' '.$length_period;
    }
    elseif(!empty($node->field_cm_moviegroup_duration)){
      $length_interval = $node->field_cm_moviegroup_duration['und'][0]['interval'];
      $length_period = $node->field_cm_moviegroup_duration['und'][0]['period'];
      $length = $length_interval.' '.$length_period;
    }
    if(!empty($node->field_cm_moviegroup_short_summar)){
      $sort_summary = $node->field_cm_moviegroup_short_summar['und'][0]['value'];
    }
    elseif(!empty($node->field_cm_movie_short_summary)){
      $sort_summary = $node->field_cm_movie_short_summary['und'][0]['value'];
    }
    if(!empty($node->field_cm_movie_year['und'])){
      $year_name = taxonomy_term_load($node->field_cm_movie_year['und'][0]['target_id']);
      $year = ' |' .' '.$year_name->name;
    }else{
      $year = '';
    }
    if(!empty($node->field_cm_movie_country['und'])){
      $country_name = taxonomy_term_load($node->field_cm_movie_country['und'][0]['target_id']);
      $country = $country_name->name;
    }else{
      $country = '';
    }
    if(!empty($node->field_cm_moviegroup_pictures)){
      $picture_path = $node->field_cm_moviegroup_pictures['und'][0]['uri'];
        $pr_image = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }
    elseif(!empty($node->field_cm_movie_pictures)){
      $picture_path_movie = $node->field_cm_movie_pictures['und'][0]['fid'];
      $file = file_load($picture_path_movie);
      $picture_path = $file->uri;
      $pr_image = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }
     $output ='';
     $output .='<div class="table-responsive">';
        $output .= '<table class="table">';
         $output .= ' <tbody>';
         /********For Movie****/
        if(!empty($node->field_event_corresponding_ref['und'])){
            $movie_node_info = node_load($node->field_event_corresponding_ref['und'][0]['target_id']);
            $line_event = $movie_node_info->field_cm_event_lineup['und'];       
        }
        /*****End Movie**/     
        /****Movie Group Nid****/ 
        if(!empty($node->field_movie_referenced['und'])){
            $movie_node = node_load($node->field_movie_referenced['und'][0]['target_id']);
        }
        if(!empty($movie_node->field_event_corresponding_ref['und'])){
          $event_node = node_load($movie_node->field_event_corresponding_ref['und'][0]['target_id']);
          //drupal_set_message('<pre>'.print_r($event_node->nid, 1).'</pre>');
           $line_event = $event_node->field_cm_event_lineup['und'];
        }
        /****Movie Group Nid****/    
        foreach ($line_event as $row) {
          $event_ref_nid = $row['target_id'];
          $node_movie = node_load($event_ref_nid);    
          $node_event = node_load($node_movie->field_event_corresponding_ref['und'][0]['target_id']);
          $event_title = $node_event->title;
          $path = drupal_get_path_alias('node/'.$node_event->nid);
          $flag = flag_create_link('favorite_', $node_event->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node_event).'</div>';
          if(!empty($node_event->field_cm_event_internal_id['und'])){
              $event_code = $node_event->field_cm_event_internal_id['und'][0]['value'];
          }
          if(!empty($node_event->field_cm_event_time['und'])){
              $event_date = date('l d.m.y', $node_event->field_cm_event_time['und'][0]['value']);
              $event_time = date('g:i a', $node_event->field_cm_event_time['und'][0]['value']);
          }
          if(!empty($node_event->field_cm_event_hall['und'])){
              $hall_id = taxonomy_term_load($node_event->field_cm_event_hall['und'][0]['target_id']);
              $hall_name = $hall_id->name;
          }
          if(!empty($node_event->field_toptix_purchase['und'])){
              $toptix_code = $node_event->field_toptix_purchase['und'][0]['value'];
          }
          $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
          $output .= '<tr class="row-custom-lobby">';
            $output .= '<td>'.'<button data-url="'.$top_link.'" class="toptix-purchase">Puchase</button>'.'</td>';
            $output .='<td>'. $addevent . '</td>';
            $output .='<td>'. $flag . '</td>';
            $output .= '<td>'.$event_code.'</td>';
            $output .= '<td>'.$hall_name.'</td>';
            $output .= '<td>'.l($event_title, $path).'</td>';
            $output .= '<td>'.$event_time.'</td>';
            $output .= '<td>'.$event_date.'</td>';
          $output .= '</tr>';
        }
         $output .= '</table>';
       $output .= '</div>';
      print '<div class="lobby-container">';
        print'<div class="lobby-term-left">';
            print '<div class="lobby-title">';
              print $title;
            print '</div>';
            print '<div class="lobby-length">';
              print $length . $year. ' '.$country;
            print '</div>';
            print '<div class="lobby-summary">';
              print strip_tags($sort_summary);
            print '</div>';
            print $output;
        print '</div>';
        print'<div class="lobby-term-right">';
          print '<div class="image-lobby">';
            print $pr_image;
          print '</div>';
          print '<div class="top-text-blk-wht">';
            print '<span class="white">'.$white_text.'</span>';
            print '<span class="black">'.$black_text.'</span>';
          print '</div>';
        print '</div>';
        print '<div class="clr"></div>';
    print '</div>';
  }
?>

