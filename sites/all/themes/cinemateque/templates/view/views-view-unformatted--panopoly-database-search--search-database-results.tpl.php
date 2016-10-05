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
    global $language ;
    $lang_name = isset($language->language) ? $language->language : '';
    if($lang_name == ''){
      $lang_name = 'en';
    }
    $node = node_load($val->entity);
    $default_image = '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
    $default_user_image = '<img src="/sites/all/themes/cinemateque/images/user-default.jpg">';
    $path_node = drupal_get_path_alias('node/'.$node->nid);
    $flag = flag_create_link('favorite_', $node->nid);
    $titles = t($node->title);
    $title = l($titles, $path_node);
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
    if(!empty($node->field_event_top_text_white['und'])){
     $white_text_event = '<span class="white">'. $node->field_event_top_text_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_event = '';
    }
    if(!empty($node->field_event_top_text_black['und'])){
     $black_text_event = '<span class="black">' . $node->field_event_top_text_black['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_event = '';
    }
    if(!empty($node->field_cm_event_duration)){
      $length_intervals = $node->field_cm_event_duration['und'][0]['interval'];
      $length_periods = $node->field_cm_event_duration['und'][0]['period'];
      $lengths = $length_intervals.' '.t($length_periods);
    }
    if(!empty($node->field_cm_movie_duration)){
      $length_interval = $node->field_cm_movie_duration['und'][0]['interval'];
      $length_period = $node->field_cm_movie_duration['und'][0]['period'];
      $length =  $length_interval.' '.t($length_period);
    }
    elseif(!empty($node->field_cm_moviegroup_duration)){
      $length_interval = $node->field_cm_moviegroup_duration['und'][0]['interval'];
      $length_period = $node->field_cm_moviegroup_duration['und'][0]['period'];
      $length = $length_interval.' '.t($length_period);
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
    if(!empty($node->field_cm_event_short_description['und'][0]['value'])){
        $summary_event = truncate_utf8($node->field_cm_event_short_description['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      if(!empty($node->field_cm_event_lineup['und'])){
        $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
        if($event_ext_nodes->type == 'cm_movie'){
          if(!empty($event_ext_nodes->field_cm_movie_short_summary)){
            $summary_event = truncate_utf8($event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }
        }else if($event_ext_nodes->type == 'cm_movie_group'){
          if(!empty($event_ext_nodes->field_cm_moviegroup_short_summar)){
              $summary_event =  truncate_utf8($event_ext_nodes->field_cm_moviegroup_short_summar['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }
        }else{
            $summary_event = '';
        }
      } 
    }
    
    
    if(!empty($node->field_cm_person_body['und'][0]['value'])){
      $summary_person = truncate_utf8($node->field_cm_person_body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      
      $summary_person = '';
    }
    if(!empty($node->field_main_event_credit['und'])){
      $event_credit = $node->field_main_event_credit['und'][0]['value'] . " | " ;
    }else{
      $event_credit = '';
    }
    if(!empty($node->field_cm_movie_meta_credit['und'])){
      $movie_credit = $node->field_cm_movie_meta_credit['und'][0]['value'] . " | " ;
    }else{
      $movie_credit = '';
    }
    if(!empty($node->field_cm_movie_year['und'])){
      $year_name = taxonomy_term_load($node->field_cm_movie_year['und'][0]['target_id']);
      $year = $year_name->name;
    }else{
      $year = '';
    }
    if(!empty($node->field_cm_movie_country['und'])){
      $country_name = taxonomy_term_load($node->field_cm_movie_country['und'][0]['target_id']);
      $country = $country_name->name;
    }else{
      $country = '';
    }
    if(!empty($node->field_cm_person_first_name)){
      $first_name =  $node->field_cm_person_first_name['und'][0]['value'];
    }else{
      $first_name = '';
    }
    if(!empty($node->field_cm_person_last_name)){
      $last_name =  $node->field_cm_person_last_name['und'][0]['value'];
    }else{
      $last_name = '';
    }
    if(!empty($node->field_cm_person_job_title)){
      $job_title =  $node->field_cm_person_job_title['und'][0]['value'];
    }else{
      $job_title = '';
    }
    /*****Person Image****/
    if(!empty($node->field_cm_person_photo)){
      $picture_path = $node->field_cm_person_photo['und'][0]['uri'];
        $image_person = '<img src="' . image_style_url('person_thumbnail', $picture_path) . '" alt="" />';
    }else{
      $image_person = $default_user_image;
    }
    /*****Movie group Image****/
    if(!empty($node->field_cm_moviegroup_pictures)){
      $picture_path = $node->field_cm_moviegroup_pictures['und'][0]['uri'];
        $image_movie_group = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
      $image_movie_group = $default_image;
    }
    /*****Movie Image****/
    if(!empty($node->field_cm_movie_pictures)){
      $picture_path_movie = $node->field_cm_movie_pictures['und'][0]['fid'];
      $file = file_load($picture_path_movie);
      $picture_path = $file->uri;
      $image_movie= '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
      $image_movie = $default_image;
    }
    /*****Article group Image****/
    if(!empty($node->field_cm_article_image)){
      $picture_path_article = $node->field_cm_article_image['und'][0]['fid'];
      $file = file_load($picture_path_article);
      $picture_path = $file->uri;
      $image_article = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
      $image_article = $default_image;
    }
    /*****Event Image****/
    if(!empty($node->field_cm_event_images)){
      $picture_path_event = $node->field_cm_event_images['und'][0]['uri'];
      $image_event = '<img src="' . image_style_url('lobby', $picture_path_event) . '" alt="" />';
    }else{
      if(!empty($node->field_cm_event_lineup['und'])){
        $event_ext_node = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
        if($event_ext_node->type == 'cm_movie_group'){
          $picture_path_ext_moviegroup = $event_ext_node->field_cm_moviegroup_pictures['und'][0]['uri'];
          $image_event = '<img src="' . image_style_url('lobby', $picture_path_ext_moviegroup) . '" alt="" />';
        }else if($event_ext_node->type == 'cm_movie'){
          $picture_path_ext_movie = $event_ext_node->field_cm_movie_pictures['und'][0]['fid'];
          $file_ext_movie = file_load($picture_path_ext_movie);
          $picture_path_ext_movie = $file_ext_movie->uri;
          $image_event= '<img src="' . image_style_url('lobby', $picture_path_ext_movie) . '" alt="" />';
        }
      }else{
            $image_event = $default_image;
        } 
    }
    if($node->type == 'cm_event'){
    $output_event ='';
     $output_event .='<div class="table-responsive">';
        $output_event .= '<table class="table">';
         $output_event .= ' <tbody>';
         if(!empty($node_event->field_cm_event_short_title['und'])){
            $event_title = t($node_event->field_cm_event_short_title['und'][0]['value']);
         }
          $path = drupal_get_path_alias('node/'.$node->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node).'</div>';
          if(!empty($node->field_cm_event_time['und'])){
              $event_date = date('l d.m.y', $node->field_cm_event_time['und'][0]['value']);
              $event_date_mobile = date('d.m.y', $node->field_cm_event_time['und'][0]['value']);
              $event_time = date('G:i', $node->field_cm_event_time['und'][0]['value']);
          }
           $output_event .= '<tr class="row-custom-lobby">';
            $output_event .= '<td class="date only-desktop">'.t($event_date).'</td>';
            $output_event .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
            if(!empty($node->field_cm_event_hall['und'])){
             // drupal_set_message('<pre>'.print_r($node->field_cm_event_hall, 1).'</pre>');
                $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
                $hall_name = $hall_id->name;
                $output_event .= '<td class="hall only-desktop">'.t($hall_name).'</td>';
            }
            else{
                $hall_name = "";
                $output_event .= '<td class="hall only-desktop"></td>';
            }
            $output_event .= '<td class="title only-desktop">';
            if(!empty($event_title)){
              $output_event .= l($event_title, $path);
            }
            $output_event .= '</td>';
            if(!empty($node->field_cm_event_internal_id['und'])){
              $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
              $output_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
            }
            else{
              $output_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
            }
            $output_event .='<td class="flag only-desktop">'. $flag . '</td>';
            $output_event .='<td class="add-event only-desktop">'. $addevent . '</td>';
            if(!empty($node->field_toptix_purchase['und'])){
            $toptix_code = $node->field_toptix_purchase['und'][0]['value'];
            $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
            $output_event .= '<td class="purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">'.t("TICKETS").'</button>'.'</td>';
            } 
            else{
              $output_event .= '<td class="purchase"></td>';
            }
           $output_event .= '</tr>';
         $output_event .= '</table>';
       $output_event .= '</div>';
    }
    if($node->type == 'cm_movie_group'){
    $result = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0') WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$node->nid') )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie_group'))))) ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
    $row_count = count($result);
    $output ='';
    $output .='<div class="table-responsive">';
      $output .= '<table class="table">';
        $output .= ' <tbody>';
        foreach($result as $val){
          $movie_group_event_nid = $val->nid;
          $movie_group_event_info = node_load($movie_group_event_nid);
          $flag_moviegroup_event = flag_create_link('favorite_', $movie_group_event_info->nid);
          $event_title = t($movie_group_event_info->title);
          $path = drupal_get_path_alias('node/'.$movie_group_event_info->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($movie_group_event_info).'</div>';
          if(!empty($movie_group_event_info->field_cm_event_time['und'])){
           $event_date = date('l d.m.y', $movie_group_event_info->field_cm_event_time['und'][0]['value']);
           $event_date_mobile = date('d.m.y', $movie_group_event_info->field_cm_event_time['und'][0]['value']);
           $event_time = date('G:i', $movie_group_event_info->field_cm_event_time['und'][0]['value']);
          }
          $output .= '<tr class="row-custom-lobby">';
           $output .= '<td class="date only-desktop">'.t($event_date).'</td>';
           $output .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
           if(!empty($movie_group_event_info->field_cm_event_hall['und'])){
               $hall_id = taxonomy_term_load($movie_group_event_info->field_cm_event_hall['und'][0]['target_id']);
               $hall_name = $hall_id->name;
               $output .= '<td class="hall only-desktop">'.t($hall_name).'</td>';
           }
           else{
               $hall_name = "";
               $output .= '<td class="hall only-desktop"></td>';
           }
           $output .= '<td class="title only-desktop">';
           if(!empty($event_title)){
             $output .= l($event_title, $path);
           }
           $output .= '</td>';
           if(!empty($movie_group_event_info->field_cm_event_internal_id['und'])){
             $event_code = $movie_group_event_info->field_cm_event_internal_id['und'][0]['value'];
             $output .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
           }
           else{
             $output .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
           }
           $output .='<td class="flag only-desktop">'. $flag_moviegroup_event . '</td>';
           $output .='<td class="add-event only-desktop">'. $addevent . '</td>';
           if(!empty($movie_group_event_info->field_toptix_purchase['und'])){
           $toptix_code = $movie_group_event_info->field_toptix_purchase['und'][0]['value'];
           $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
           $output .= '<td class="purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">'.t("TICKETS").'</button>'.'</td>';
           } 
           else{
             $output .= '<td class="purchase"></td>';
           }
          $output .= '</tr>';
        }
        $output .= ' </tbody>';
      $output .= '</table>';
    $output .= '</div>';  
    }
    if($node->type == 'cm_movie'){
    $results = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value
    FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0')
    WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$node->nid' ) )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie')) AND (node.language IN  ('$lang_name')))))
    ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
    $row_count = count($results);
    $output_movie_event ='';
    $output_movie_event .='<div class="table-responsive">';
      $output_movie_event .= '<table class="table">';
        $output_movie_event .= ' <tbody>';
        foreach($results as $val){
          $movie_event_nid = $val->nid;
          $movie_event_info = node_load($movie_event_nid);
          $flag_moviegroup_event = flag_create_link('favorite_', $movie_event_info->nid);
          $event_title = t($movie_event_info->title);
         $path = drupal_get_path_alias('node/'.$movie_event_info->nid);
         $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($movie_event_info).'</div>';
         if(!empty($movie_event_info->field_cm_event_time['und'])){
          $event_date = date('l d.m.y', $movie_event_info->field_cm_event_time['und'][0]['value']);
          $event_date_mobile = date('d.m.y', $movie_event_info->field_cm_event_time['und'][0]['value']);
          $event_time = date('G:i', $movie_event_info->field_cm_event_time['und'][0]['value']);
         }
          $output_movie_event .= '<tr class="row-custom-lobby">';
           $output_movie_event .= '<td class="date only-desktop">'.t($event_date).'</td>';
           $output_movie_event .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
           if(!empty($movie_event_info->field_cm_event_hall['und'])){
               $hall_id = taxonomy_term_load($movie_event_info->field_cm_event_hall['und'][0]['target_id']);
               $hall_name = $hall_id->name;
               $output_movie_event .= '<td class="hall only-desktop">'.t($hall_name).'</td>';
           }
           else{
               $hall_name = "";
               $output_movie_event .= '<td class="hall only-desktop"></td>';
           }
           $output_movie_event .= '<td class="title only-desktop">';
           if(!empty($event_title)){
             $output_movie_event .= l($event_title, $path);
           }
           $output_movie_event .= '</td>';
           if(!empty($movie_event_info->field_cm_event_internal_id['und'])){
             $event_code = $movie_event_info->field_cm_event_internal_id['und'][0]['value'];
             $output_movie_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
           }
           else{
             $output_movie_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
           }
           $output_movie_event .='<td class="flag only-desktop">'. $flag_moviegroup_event . '</td>';
           $output_movie_event .='<td class="add-event only-desktop">'. $addevent . '</td>';
           if(!empty($movie_event_info->field_toptix_purchase['und'])){
           $toptix_code = $movie_event_info->field_toptix_purchase['und'][0]['value'];
           $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
           $output_movie_event .= '<td class="purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">'.t("TICKETS").'</button>'.'</td>';
           } 
           else{
             $output_movie_event .= '<td class="purchase"></td>';
           }
          $output_movie_event .= '</tr>';
        }
        $output_movie_event .= ' </tbody>';
      $output_movie_event .= '</table>';
    $output_movie_event .= '</div>';  
    }

      switch ($node->type) {
        case "cm_person":
          $image = '<div class="person-left-sec"><div class="person-img">'.l($image_person, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)) .'</div><div class="lobby-title">'. l($first_name .' '. $last_name, $path_node).'</div><div class="job-title">'. $job_title.'</div></div>';
          $title = '';
          $sort_summary = t($summary_person);
          $event_info = '';
          $duration_info = '';
          $top_text = '';
        break;
        case "cm_movie_group":
          $image =  '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie_group, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = t($summary_movie_group);
          $event_info = $output;
          $duration_info = $country . " " . $year . $length;
          $top_text = $black_text_movie_group . $white_text_movie_group;
        break;
        case "cm_movie":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = t($summary_movie);
          $event_info = $output_movie_event;
          $duration_info = $movie_credit . $length;
          $top_text = $black_text_movie . $white_text_movie;
        break;
        case "cm_article":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_article, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          if(!empty($node->body['und'][0]['value'])){
            $sort_summary = truncate_utf8($node->body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }
          $top_text = $black_text_article . $white_text_article;
          $event_info = '';
          $duration_info = '';
        break;
          case "cm_event":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_event, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = $summary_event;
          $top_text = $black_text_event . $white_text_event;
          $event_info = $output_event;
          $duration_info = $event_credit . $lengths;
        break;
        default:
          $image = $default_user_image;
          $title = '';
          $sort_summary = '';
          $event_info = '';
          $duration_info = '';
          $top_text = '';
      }
      print '<div class="lobby-container">';
        print'<div class="lobby-term-left">';
          print '<div class="image-lobby">';
            print $image;
          print '</div>';
          print '<div class="top-text-blk-wht">';
            print $top_text;
          print '</div>';
        print '</div>';
        print'<div class="lobby-term-right">';
            print '<div class="lobby-title">';
              print t($title);
            print '</div>';
            print '<div class="lobby-length">';
              print $duration_info;
            print '</div>';
            print $event_info;
            print '<div class="lobby-summary">';
              print t(strip_tags($sort_summary));
            print '</div>';
        print '</div>';
        print '<div class="clr"></div>';
    print '</div>';
  }
?>
