<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
 //dpm($row->nid);
     $node = node_load($row->nid);
    $path_node = drupal_get_path_alias('node/'.$node->nid);
    $flag = flag_create_link('favorite_', $node->nid);
    $default_user_image = '<img src="/sites/all/themes/cinemateque/images/user-default.jpg">';
    $default_image = '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
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
    if(!empty($node->field_cm_movie_duration)){
      $length_interval = t($node->field_cm_movie_duration['und'][0]['interval']);
      $length_period = t($node->field_cm_movie_duration['und'][0]['period'].'s');
      $length = ' | '.$length_interval.' '.$length_period;
    }
    elseif(!empty($node->field_cm_moviegroup_duration)){
      $length_interval = t($node->field_cm_moviegroup_duration['und'][0]['interval']);
      $length_period = t($node->field_cm_moviegroup_duration['und'][0]['period'].'s');
      $length = ' | '.$length_interval.' '.$length_period;
    }
    else{
      $length = '';
    }
    if(!empty($node->field_cm_moviegroup_short_summar)){
      $summary_movie_group =  $node->field_cm_moviegroup_short_summar['und'][0]['value'];
    }else{
      $summary_movie_group = '';
    }
    if(!empty($node->field_cm_movie_short_summary)){
      $summary_movie = $node->field_cm_movie_short_summary['und'][0]['value'];
    }else{
      $summary_movie = '';
    }
    $summary_event = '';
	$summary_event_movie='';
    if(!empty($node->field_cm_event_short_description['und'][0]['value'])){
        $summary_event = '<div class="event_summary">'.$node->field_cm_event_short_description['und'][0]['value'].'</div>';
    }
      if(!empty($node->field_cm_event_lineup['und'])){
        $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
		$path_event_ext_nodes=drupal_get_path_alias('node/'.$event_ext_nodes->nid);
		$summary_event_movie = '<div class="lobby-title">'.$event_ext_nodes->title.'</div>';
    if((strtolower($node->title))==(strtolower($event_ext_nodes->title))){
      $summary_event_movie = '<div class="lobby-title">'.l($event_ext_nodes->title, $path_node).'</div>';
      $title = '';
    }

        if($event_ext_nodes->type == 'cm_movie'){
			
			
			if(!empty($event_ext_nodes->field_cm_movie_year['und'])){
			$movie_year_name = taxonomy_term_load($event_ext_nodes->field_cm_movie_year['und'][0]['target_id']);
			$movie_year = $movie_year_name->name;
			}else{
			$movie_year = '';
			}
			if(!empty($event_ext_nodes->field_cm_movie_country['und'])){
			$movie_country_name = taxonomy_term_load($event_ext_nodes->field_cm_movie_country['und'][0]['target_id']);
			$movie_country = $movie_country_name->name;
			}else{
			$movie_country = '';
			}
			if(!empty($event_ext_nodes->field_cm_movie_duration)){
			$movie_length_interval = t($event_ext_nodes->field_cm_movie_duration['und'][0]['interval']);
			$movie_length_period = t($event_ext_nodes->field_cm_movie_duration['und'][0]['period'].'s');
			$movie_length = ' | '.$movie_length_interval.' '.$movie_length_period;
			}else{
			$movie_length = '';
			}
      if(!empty($event_ext_nodes->field_cm_movie_meta_credit['und'])){
        $movie_credit = $event_ext_nodes->field_cm_movie_meta_credit['und'][0]['value'];
      }else{
        $movie_credit = '';
      } 
			$movie_duration_info = $movie_credit . $movie_length;
			$summary_event_movie .='<div class="lobby-length">'.$movie_duration_info.'</div>';
			
          if(!empty($event_ext_nodes->field_cm_movie_short_summary)){
            $summary_event_movie .= '<div class="lobby-summary">'.$event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'].'</div>';
          }
        }else if($event_ext_nodes->type == 'cm_movie_group'){
          if(!empty($event_ext_nodes->field_cm_moviegroup_short_summar)){
              $summary_event_movie .=  '<div class="lobby-summary">'.$event_ext_nodes->field_cm_moviegroup_short_summar['und'][0]['value'].'</div>';
          }
        }
      } 
    
    if(!empty($node->field_cm_person_body['und'][0]['value'])){
      $summary_person = truncate_utf8($node->field_cm_person_body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      $summary_person = '';
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
 
    if(!empty($node->field_cm_movie_meta_credit['und'])){
      $credit = $node->field_cm_movie_meta_credit['und'][0]['value'];
    }else{
      $credit = '';
    }   
      
    /*****Person Image****/
    if(!empty($node->field_cm_person_photo)){
      $picture_path = $node->field_cm_person_photo['und'][0]['uri'];
        $image_person = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
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
    }
    else if(!empty($node->field_cm_event_lineup['und'])){
        $event_ext_node = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
        if(($event_ext_node->type == 'cm_movie_group') && (!empty($event_ext_node->field_cm_moviegroup_pictures))){
          $picture_path_ext_moviegroup = $event_ext_node->field_cm_moviegroup_pictures['und'][0]['uri'];
          $image_event = '<img src="' . image_style_url('lobby', $picture_path_ext_moviegroup) . '" alt="" />';
        }else if(($event_ext_node->type == 'cm_movie') && (!empty($event_ext_node->field_cm_movie_pictures))){
          $picture_path_ext_movie = $event_ext_node->field_cm_movie_pictures['und'][0]['fid'];
          $file_ext_movie = file_load($picture_path_ext_movie);
          $picture_path_ext_movie = $file_ext_movie->uri;
          $image_event= '<img src="' . image_style_url('lobby', $picture_path_ext_movie) . '" alt="" />';
        }
        else{
          $image_event = $default_image;
        }
    }else{
        $image_event = $default_image;
    }

    if($node->type == 'cm_event'){
    $output_event ='';
     $output_event .='<div class="table-responsive">';
        $output_event .= '<table class="table">';
         $output_event .= ' <tbody>';
         if(!empty($node_event->field_cm_event_short_title['und'])){
            $event_title = $node_event->field_cm_event_short_title['und'][0]['value'];
         }
          $path = drupal_get_path_alias('node/'.$node->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node).'</div>';
          if(!empty($node->field_cm_event_time['und'])){
              $event_date = '<span class="day-same-width">'.format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'l').'</span>';
              $event_date .= format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'd.m.y');
              $event_date_mobile = date('d.m.y', $node->field_cm_event_time['und'][0]['value']);
              $event_time = date('H:i', $node->field_cm_event_time['und'][0]['value']);
          }
          else{
              $event_date = '';
              $event_date_mobile = '';
              $event_time = '';           
          }
           $output_event .= '<tr class="row-custom-lobby">';
            $output_event .= '<td class="date only-desktop">'.$event_date.'</td>';
            $output_event .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
            if(!empty($node->field_cm_event_hall['und'])){
                $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
                $hall_name = $hall_id->name;
                $output_event .= '<td class="hall only-desktop">'.$hall_name.'</td>';
            }
            else{
                $hall_name = '';
                $output_event .= '<td class="hall only-desktop"></td>';
            }
            $output_event .= '<td class="title only-desktop">';
            if(!empty($event_title)){
              $output_event .= l($event_title, $path);
            }
            $output_event .= '</td>';
            if(!empty($node->field_cm_event_hall['und'])){
                $output_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>';
            }
            else{
                $output_event .= '<td class="code"><div class="only-mobile"></div>';
            }
            if(!empty($node->field_cm_event_internal_id['und'])){
              $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
              $output_event .= $event_code.'</td>';
            }
            else{
              $output_event .= '</td>';
            }
            $output_event .='<td class="views-field-ops only-desktop">'. $flag . '</td>';
            $output_event .='<td class="add-event only-desktop">'. $addevent . '</td>';
            $toptix_button = field_view_field('node', $node, 'field_toptix_purchase', 'full');
            $toptix_button = drupal_render($toptix_button);
            $output_event .= '<td class="purchase">' . $toptix_button . '</td>';
           $output_event .= '</tr>';
         $output_event .= '</table>';
       $output_event .= '</div>';
    }else{
     $output ='';
	 $output .= screaning_output($node->nid);
    }  
      switch ($node->type) {
        case "cm_person":
          $image = l($image_person, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true));
          $sort_summary = $summary_person;
          $event_info = '';
          $duration_info = '';
          $top_text = '';
        break;
        case "cm_movie_group":
          $image =  '<div class="image-container-gorup movie-group"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie_group, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $sort_summary = $summary_movie_group;
          $event_info = $output;
          $duration_info = $country . " " . $year . $length;
          $top_text = $black_text_movie_group . $white_text_movie_group;
        break;
        case "cm_movie":
           $image = '<div class="image-container-gorup movie"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $sort_summary = $summary_movie;
          $event_info = $output;
          $duration_info = $credit . " " . $length;
          $top_text = $black_text_movie . $white_text_movie;
        break;
        case "cm_article":
          $image = '<div class="image-container-gorup article"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_article, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          if(!empty($node->body['und'][0]['value'])){
            $sort_summary = truncate_utf8($node->body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }
          $top_text = $black_text_article . $white_text_article;
          $event_info = '';
          $duration_info = '';
        break;
          case "cm_event":
          $image = '<div class="image-container-gorup event"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_event, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $sort_summary = $summary_event;
          $top_text = $black_text_event . $white_text_event;
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
      switch ($node->type) {
      case "cm_event":
        print '<div class="lobby-container event">';
          print'<div class="lobby-term-left">';
            print'<div class="only-mobile">';
              print $event_info;
            print '</div>';
            print '<div class="image-lobby">';
              print $image;
              print '<div class="top-text-blk-wht">';
                print $top_text;
              print '</div>';
            print '</div>';
          print '</div>';
          print'<div class="lobby-term-right">';
              print'<div class="only-desktop">';
                print $event_info;
              print '</div>';
              print '<div class="lobby-title">';
                print $title;
              print '</div>';
              print '<div class="lobby-length">';
                print $duration_info;
              print '</div>';
              print '<div class="lobby-summary-wrapper">';
                print '<div class="lobby-summary">';
                  print t(strip_tags($sort_summary));
                print '</div>';
                print ($summary_event_movie);
              print '</div>';
          print '</div>';
          print '<div class="clr"></div>';
      print '</div>';
      break;
      default:
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
                print $title;
              print '</div>';
              print '<div class="lobby-length">';
                print $duration_info;
              print '</div>';
              print '<div class="lobby-summary-wrapper">';
                print '<div class="lobby-summary">';
                  print t(strip_tags($sort_summary));
                print '</div>';
                print ($summary_event_movie);
              print '</div>';
              print $event_info;
          print '</div>';
          print '<div class="clr"></div>';
      print '</div>';
      break;

    }
?>
