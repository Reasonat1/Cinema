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
    $node = node_load($val->entity);
    $default_image = '<img src="/sites/all/themes/cinemateque/images/default-image.png">';
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
      $lengths = $length_intervals.t($length_periods);
    }
    if(!empty($node->field_cm_movie_duration)){
      $length_interval = $node->field_cm_movie_duration['und'][0]['interval'];
      $length_period = $node->field_cm_movie_duration['und'][0]['period'];
      $length =  $length_interval.t($length_period);
    }
    elseif(!empty($node->field_cm_moviegroup_duration)){
      $length_interval = $node->field_cm_moviegroup_duration['und'][0]['interval'];
      $length_period = $node->field_cm_moviegroup_duration['und'][0]['period'];
      $length = $length_interval.t($length_period);
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
              $event_time = date('G:i', $node->field_cm_event_time['und'][0]['value']);
          }
           $output_event .= '<tr class="row-custom-lobby">';
            $output_event .= '<td class="date">'.t($event_date).'</td>';
            $output_event .= '<td class="time">'.$event_time.'</td>';
            if(!empty($node->field_cm_event_hall['und'])){
             // drupal_set_message('<pre>'.print_r($node->field_cm_event_hall, 1).'</pre>');
                $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
                $hall_name = $hall_id->name;
                $output_event .= '<td class="hall">'.t($hall_name).'</td>';
            }
            else{
                $output_event .= '<td class="hall"></td>';
            }
            $output_event .= '<td class="title">';
            if(!empty($event_title)){
              $output_event .= l($event_title, $path);
            }
            $output_event .= '</td>';
            if(!empty($node->field_cm_event_internal_id['und'])){
              $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
              $output_event .= '<td class="code">'.t($event_code).'</td>';
            }
            else{
              $output_event .= '<td class="code"></td>';
            }
            $output_event .='<td class="flag">'. $flag . '</td>';
            $output_event .='<td>'. $addevent . '</td>';
            if(!empty($node->field_toptix_purchase['und'])){
            $toptix_code = $node->field_toptix_purchase['und'][0]['value'];
            $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
            $output_event .= '<td class="purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">'.t("Tickets").'</button>'.'</td>';
            } 
            else{
              $output_event .= '<td class="purchase"></td>';
            }
           $output_event .= '</tr>';
         $output_event .= '</table>';
       $output_event .= '</div>';
    }else{
     $output ='';
     $output .='<div class="table-responsive">';
        $output .= '<table class="table">';
         $output .= ' <tbody>';
         /********For Movie****/
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
        if(!empty($line_event)){
            foreach ($line_event as $row) {
              $event_ref_nid = $row['target_id'];
              if(!empty($row['target_id'])){
                $node_movie = node_load($event_ref_nid);
              } 
              if(!empty($node_movie->field_event_corresponding_ref['und'])){
                $node_event = node_load($node_movie->field_event_corresponding_ref['und'][0]['target_id']);
                if(!empty($node_event->field_cm_event_short_title['und'])){
                  $event_title = t($node_event->field_cm_event_short_title['und'][0]['value']);
                }
                $path = drupal_get_path_alias('node/'.$node_event->nid);
                $flags = flag_create_link('favorite_', $node_event->nid);
              }
              $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node_event).'</div>';
              if(!empty($node_event->field_cm_event_time['und'])){
                  $event_date = date('l d.m.y', $node_event->field_cm_event_time['und'][0]['value']);
                  $event_time = date('G:i', $node_event->field_cm_event_time['und'][0]['value']);
              }

              $output .= '<tr class="row-custom-lobby">';
                $output .= '<td class="date">'.t($event_date).'</td>';
                $output .= '<td class="time">'.$event_time.'</td>';
                if(!empty($node_event->field_cm_event_hall['und'])){
                  $hall_id = taxonomy_term_load($node_event->field_cm_event_hall['und'][0]['target_id']);
                  $hall_name = $hall_id->name;
                  $output .= '<td class="hall">'.t($hall_name).'</td>';
                }
                else{
                  $output .= '<td class="hall"></td>';
                }
                if(!empty($event_title)){
                  $output .= '<td class="title">'.l($event_title, $path).'</td>';
                }
                else{
                  $output .= '<td class="title"></td>';
                }
                if(!empty($node_event->field_cm_event_internal_id['und'])){
                  $event_code = $node_event->field_cm_event_internal_id['und'][0]['value'];
                  $output .= '<td class="code">'.t($event_code).'</td>';
                }
                else{
                  $output .= '<td class="code"></td>';
                }
                $output .='<td class="flag">'. $flags . '</td>';
                $output .='<td class="addevent">'. $addevent . '</td>';
                if(!empty($node_event->field_toptix_purchase['und'])){
                  $toptix_code = $node_event->field_toptix_purchase['und'][0]['value'];
                  $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
                  $output .= '<td class="purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">' . t("Tickets") . '</button>'.'</td>';
                }
                else{
                  $output .= '<td class="purchase"></td>';
                }
                $output .= '</tr>';
            }
        }
         $output .= '</table>';
       $output .= '</div>';
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
          $top_text = $white_text_movie_group . $black_text_movie_group;
        break;
        case "cm_movie":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = t($summary_movie);
          $event_info = $output;
          $duration_info = $movie_credit . $length;
          $top_text = $white_text_movie . $black_text_movie;
        break;
        case "cm_article":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_article, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          if(!empty($node->body['und'][0]['value'])){
            $sort_summary = truncate_utf8($node->body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }
          $top_text = $white_text_article . $black_text_article;
          $event_info = '';
          $duration_info = '';
        break;
          case "cm_event":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_event, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = $summary_event;
          $top_text = $white_text_event . $black_text_event;
          $event_info = $output_event;
          $duration_info = $event_credit . $lengths;
        break;
        default:
          $image = '';
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
