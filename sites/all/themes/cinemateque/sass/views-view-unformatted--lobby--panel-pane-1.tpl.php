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
     //drupal_set_message('<pre>'.print_r($node->field_cm_event_images, 1).'</pre>');
    $path_node = drupal_get_path_alias('node/'.$node->nid);
    $title = l($node->title, $path_node);
    if(!empty($node->field_mc_teaser_toptxt_white['und'])){
     $white_text_movie = '<span class="white">'. $node->field_mc_teaser_toptxt_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_movie = '';
    }
    if(!empty($node->field_mc_teaser_toptxt_blk['und'])){
     $black_text_movie = '<span class="black">' . $node->field_mc_teaser_toptxt_blk['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_movie = '';
    }
    if(!empty($node->field_movie_group_top_text_white['und'])){
     $white_text_movie_group = '<span class="white">'. $node->field_movie_group_top_text_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_movie_group = '';
    }
    if(!empty($node->field_movie_group_top_text_black['und'])){
     $black_text_movie_group = '<span class="black">' . $node->field_movie_group_top_text_black['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_movie_group ='';
    }
    if(!empty($node->field_article_top_text_white['und'])){
     $white_text_article = '<span class="white">'. $node->field_article_top_text_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_article = '';
    }
    if(!empty($node->field_article_top_text_black['und'])){
     $black_text_article = '<span class="black">' . $node->field_article_top_text_black['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_article = '';
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
      $summary_movie_group =  truncate_utf8($node->field_cm_moviegroup_short_summar['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      $summary_movie_group = '';
    }
    if(!empty($node->field_cm_movie_short_summary)){
      $summary_movie = truncate_utf8($node->field_cm_movie_short_summary['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      $summary_movie = '';
    }
    if(!empty($node->field_cm_event_body['und'][0]['value'])){
      $summary_event = truncate_utf8($node->field_cm_event_body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      $summary_event = '';
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
    /*****Movie group Image****/
    if(!empty($node->field_cm_moviegroup_pictures)){
      $picture_path = $node->field_cm_moviegroup_pictures['und'][0]['uri'];
        $image_movie_group = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }
    /*****Movie Image****/
    if(!empty($node->field_cm_movie_pictures)){
      $picture_path_movie = $node->field_cm_movie_pictures['und'][0]['fid'];
      $file = file_load($picture_path_movie);
      $picture_path = $file->uri;
      $image_movie= '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
    $image_movie = '';
    }
    /*****Article group Image****/
    if(!empty($node->field_cm_article_image)){
      $picture_path_article = $node->field_cm_article_image['und'][0]['fid'];
      $file = file_load($picture_path_article);
      $picture_path = $file->uri;
      $image_article = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
      $image_article = '';
    }
    /*****Event Image****/
    if(!empty($node->field_cm_event_images)){
      $picture_path_event = $node->field_cm_event_images['und'][0]['uri'];
      $image_event = '<img src="' . image_style_url('lobby', $picture_path_event) . '" alt="" />';
    }else{
      $image_event = '';
    }
    if($node->type == 'cm_event'){
    $output_event ='';
     $output_event .='<div class="table-responsive">';
        $output_event .= '<table class="table">';
         $output_event .= ' <tbody>';
          $event_title = (!empty($node->field_cm_event_short_title)) ? $node->field_cm_event_short_title['und'][0]['value'] : $node->title;
          $flag = flag_create_link('favorite_', $node->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node).'</div>';
		  $event_code = '';
          if(!empty($node->field_cm_event_internal_id['und'])){
              $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
          }
          if(!empty($node->field_cm_event_time['und'])){
              $event_date = date('l d.m.y', $node->field_cm_event_time['und'][0]['value']);
              $event_time = date('g:i a', $node->field_cm_event_time['und'][0]['value']);
          }
          if(!empty($node->field_cm_event_hall['und'])){
              $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
              $hall_name = $hall_id->name;
          }
          if(!empty($node->field_toptix_purchase['und'])){
              $toptix_code = $node->field_toptix_purchase['und'][0]['value'];
			  $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
          }else { $top_link = '';}
          
           $output_event .= '<tr class="row-custom-lobby">';
           $output_event .= '<td>'.$event_date.'</td>';
           $output_event .= '<td>'.$event_time.'</td>';
           $output_event .= '<td>'.l($event_title, 'node/'.$node->nid).'</td>';
           $output_event .= '<td>'.$hall_name.'</td>';
           $output_event .= '<td>'.$event_code.'</td>';
           $output_event .='<td>'. $flag . '</td>';
           $output_event .='<td>'. $addevent . '</td>';
           if(!empty($top_link)) $output_event .= '<td>'.'<button data-url="'.$top_link.'" class="toptix-purchase">Puchase</button>'.'</td>';
           $output_event .= '</tr>';
         $output_event .= '</table>';
       $output_event .= '</div>';
    }else{
     $output ='';
     $output .='<div class="table-responsive">';
        $output .= '<table class="table">';
         $output .= ' <tbody>';
         /********For Movie****/
		 $line_event = array();
        if(!empty($node->field_event_corresponding_ref['und'])){
            $movie_node_info = node_load($node->field_event_corresponding_ref['und'][0]['target_id']);
            $line_event = $movie_node_info->field_cm_event_lineup['und'];       
        }
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
		  
          $event_title = (empty($node_event->field_cm_event_short_title)) ? $node_event->title : $node_event->field_cm_event_short_title['und'][0]['value'];
          //$path = drupal_get_path_alias('node/'.$node_event->nid);
          $flag = flag_create_link('favorite_', $node_event->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node_event).'</div>';
          $event_code = '';
		  if(!empty($node_event->field_cm_event_internal_id['und'])){
              $event_code = $node_event->field_cm_event_internal_id['und'][0]['value'];
          }
          if(!empty($node_event->field_cm_event_time['und'])){
              $event_date = date('l d.m.y', $node_event->field_cm_event_time['und'][0]['value']);
              $event_time = date('g:i a', $node_event->field_cm_event_time['und'][0]['value']);
          }
		  $hall_name = '';
          if(!empty($node_event->field_cm_event_hall['und'])){
              $hall_id = taxonomy_term_load($node_event->field_cm_event_hall['und'][0]['target_id']);
              $hall_name = $hall_id->name;
          }
		  $toptix_code = '';
          if(!empty($node_event->field_toptix_purchase['und'])){
              $toptix_code = $node_event->field_toptix_purchase['und'][0]['value'];
          }
          $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
           $output .= '<tr class="row-custom-lobby">';
           $output .= '<td>'.$event_date.'</td>';
           $output .= '<td>'.$event_time.'</td>';
           $output .= '<td>'.l($event_title, 'node/'.$node_event->nid).'</td>';
           if($hall_name) $output .= '<td>'.$hall_name.'</td>';
           if($event_code) $output .= '<td>'.$event_code.'</td>';
           $output .='<td>'. $flag . '</td>';
           $output .='<td>'. $addevent . '</td>';       
           if($toptix_code) $output .= '<td>'.'<button data-url="'.$top_link.'" class="toptix-purchase">Puchase</button>'.'</td>';
           $output .= '</tr>';
        }
         $output .= '</table>';
       $output .= '</div>';
    }  
      switch ($node->type) {
        case "cm_movie_group":
          $image = $image_movie_group;
          $sort_summary = $summary_movie_group;
          $event_info = $output;
          $duration_info = $length . $year. ' '.$country;
          $top_text = $white_text_movie_group . $black_text_movie_group;
        break;
        case "cm_movie":
          $image = $image_movie;
          $sort_summary = $summary_movie;
          $event_info = $output;
          $duration_info = $length . $year. ' '.$country;
          $top_text = $white_text_movie . $black_text_movie;
        break;
        case "cm_article":
          $image = $image_article;
          if(!empty($node->body['und'][0]['value'])){
            $sort_summary = truncate_utf8($node->body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }
          $top_text = $white_text_article . $black_text_article;
          $event_info = '';
          $duration_info = '';
        break;
          case "cm_event":
          $image = $image_event;
          $sort_summary = $summary_event;
          $top_text = $white_text_article . $black_text_article;
          $event_info = $output_event;
          $duration_info = '';
        break;
        default:
          $image = '';
          $sort_summary = '';
          $event_info = '';
          $duration_info = '';
          $top_text = '';
      }
      print '<div class="lobby-container">';
        print'<div class="lobby-term-left">';
            print '<div class="lobby-title">';
              print $title;
            print '</div>';
            print '<div class="lobby-length">';
              print $duration_info;
            print '</div>';
            print '<div class="lobby-summary">';
              print strip_tags($sort_summary);
            print '</div>';
            print $event_info;
        print '</div>';
        print'<div class="lobby-term-right">';
          print '<div class="image-lobby">';
            print $image;
          print '</div>';
          print '<div class="top-text-blk-wht">';
            print $top_text;
          print '</div>';
        print '</div>';
        print '<div class="clr"></div>';
    print '</div>';
  }
?>
