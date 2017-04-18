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
  $now=time();
  $output_scriens = (false)?'<thead>
           <tr>
           <th class="views-field">'. t('Date') .'</th>
           <th class="views-field">'. t('Time') .'</th>
           <th class="views-field">'. t('Hall') .'</th>
           <th class="views-field">'. t('Event') .'</th>
           <th class="views-field">'. t('Code') .'</th>
           <th class="views-field"></th>
           <th class="views-field"></th>
           <th class="views-field">'. t('TICKETS') .'</th>
           </tr>
           </thead>':'';
  foreach ($results as $val) {
    global $language ;
    $language_name = isset($language->language) ? $language->language : '';
    if($language_name == ''){
      $language_name = 'en';
    }
    $node = node_load($val->entity);
    $default_image = '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
    $default_user_image = '<img src="/sites/all/themes/cinemateque/images/user-default.jpg">';
    $path_node = drupal_get_path_alias('node/'.$node->nid);
    $flag = flag_create_link('favorite_', $node->nid);
    $title = l($node->title, $path_node);
    if(!empty($node->field_cm_event_lineup['und'])){
      $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
    }
    else{
      $event_ext_nodes = '';
    }
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
      $length_periods = $node->field_cm_event_duration['und'][0]['period'].'s';
      $lengths = $length_intervals.' '.t($length_periods);
    }
    else{
      $lengths = '';
    }
    if(!empty($node->field_cm_movie_duration)){
      $length_interval = $node->field_cm_movie_duration['und'][0]['interval'];
      $length_period = $node->field_cm_movie_duration['und'][0]['period'].'s';
      $length =  $length_interval.' '.t($length_period);
    }
    elseif(!empty($node->field_cm_moviegroup_duration)){
      $length_interval = $node->field_cm_moviegroup_duration['und'][0]['interval'];
      $length_period = $node->field_cm_moviegroup_duration['und'][0]['period'].'s';
      $length = $length_interval.' '.t($length_period);
    } else {$length='';}
    if(!empty($node->field_cm_moviegroup_short_summar)){
      $summary_movie_group =  $node->field_cm_moviegroup_short_summar['und'][0]['value'];
    }else{
      $summary_movie_group = '';
    }

    if ($GLOBALS['_domain']['domain_id'] == 1 ){ 
      if(!empty($node->field_cm_movie_short_summary)){
        $summary_movie = $node->field_cm_movie_short_summary['und'][0]['value'];
      }else{
        $summary_movie = '';
      }
    } else if(!empty($node->field_short_summary_festival)){
        $summary_movie = $node->field_short_summary_festival['und'][0]['value'];
      } else if(!empty($node->field_cm_movie_short_summary)){
        $summary_movie = $node->field_cm_movie_short_summary['und'][0]['value'];
      } else{
        $summary_movie = '';
      }


	$summary_event = '';
    if(!empty($node->field_cm_event_short_description['und'][0]['value'])){
        $summary_event = $node->field_cm_event_short_description['und'][0]['value'];
    }else{
      if(!empty($node->field_cm_event_lineup['und']) && false){
        if($event_ext_nodes->type == 'cm_movie'){
          if ($GLOBALS['_domain']['domain_id'] == 1 ){ 
            if(!empty($event_ext_nodes->field_cm_movie_short_summary)){
              $summary_event = $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'];
            }
          } else {
             if(!empty($event_ext_nodes->field_short_summary_festival)){
              $summary_event = $event_ext_nodes->field_short_summary_festival['und'][0]['value'];
            } else if(!empty($event_ext_nodes->field_cm_movie_short_summary)){
              $summary_event = $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'];
            }           
          }

        }else if($event_ext_nodes->type == 'cm_movie_group'){
          if(!empty($event_ext_nodes->field_cm_moviegroup_short_summar)){
              $summary_event =  $event_ext_nodes->field_cm_moviegroup_short_summar['und'][0]['value'];
          }
        }else{
            $summary_event = '';
        }
      } 
    }
   /****New Enhancement for Event node type display movie & movie group content****/
      if(!empty($event_ext_nodes->field_cm_movie_meta_credit['und'])){
        $movie_credit_enhancement = $event_ext_nodes->field_cm_movie_meta_credit['und'][0]['value'] . " | " ;
      }else{
        $movie_credit_enhancement = '';
      }
      if(!empty($event_ext_nodes->field_cm_movie_year['und'])){
        $year_name_enhancement = taxonomy_term_load($event_ext_nodes->field_cm_movie_year['und'][0]['target_id']);
        $year_enhancement = $year_name_enhancement->name;
      }else{
        $year_enhancement = '';
      }
      if(!empty($event_ext_nodes->field_cm_movie_country['und'])){
        $country_name_enhancement = taxonomy_term_load($event_ext_nodes->field_cm_movie_country['und'][0]['target_id']);
        $country_enhancement = $country_name_enhancement->name;
      }else{
        $country_enhancement = '';
      }
      if(!empty($event_ext_nodes->field_cm_movie_duration)){
        $length_interval_enhancement = $event_ext_nodes->field_cm_movie_duration['und'][0]['interval'];
        $length_period_enhancement = $event_ext_nodes->field_cm_movie_duration['und'][0]['period'].'s';
        $length_enhancement =  $length_interval_enhancement.' '.t($length_period_enhancement);
      }
      elseif(!empty($event_ext_nodes->field_cm_moviegroup_duration)){
        $length_interval_enhancement = $event_ext_nodes->field_cm_moviegroup_duration['und'][0]['interval'];
        $length_period_enhancement = $event_ext_nodes->field_cm_moviegroup_duration['und'][0]['period'].'s';
        $length_enhancement = $length_interval_enhancement.' '.t($length_period_enhancement);
      } else {$length_enhancement='';}
      if(!empty($event_ext_nodes->field_cm_moviegroup_short_summar)){
        $summary_movie_group_enhancement =  $event_ext_nodes->field_cm_moviegroup_short_summar['und'][0]['value'];
      }else{
        $summary_movie_group_enhancement = '';
      }

      if ($GLOBALS['_domain']['domain_id'] == 1 ){ 
        if(!empty($event_ext_nodes->field_cm_movie_short_summary)){
          $summary_movie_enhancement = $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'];
        }else{
          $summary_movie_enhancement = '';
        }
      } else if(!empty($event_ext_nodes->field_short_summary_festival)){
          $summary_movie_enhancement = $event_ext_nodes->field_short_summary_festival['und'][0]['value'];
        } else if(!empty($event_ext_nodes->field_cm_movie_short_summary)){
          $summary_movie_enhancement = $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'];
        }else{
          $summary_movie_enhancement = '';
        }


      $sub_lang_title =array();
      $sub_lang_name = '';
      if(!empty($node->field_cm_event_lineup['und'])){
          if(!empty($event_ext_nodes->field_cm_movie_subtitle['und'])){
            foreach($event_ext_nodes->field_cm_movie_subtitle['und'] as $val){
              $sub_id = taxonomy_term_load($val['target_id']);
              $sub_lang_title[] = t($sub_id->name);
            }
          } 
      }
      $sub_lang_title = array_unique($sub_lang_title);
      if(!empty($sub_lang_title)){
        $sub_languages = implode(', ', $sub_lang_title);
        $sub_lang_name = t('@languages subtitles', array('@languages' => $sub_languages));
      }
      $lang_title =array();
      $lang_name = '';
      if(!empty($node->field_cm_event_lineup['und'])){
        if(!empty($event_ext_nodes->field_cm_movie_language['und'])){
          foreach($event_ext_nodes->field_cm_movie_language['und'] as $value){
            $subs_id = taxonomy_term_load($value['target_id']);
            $lang_title[] = t($subs_id->name);
          }
        }
      }
      $lang_title = array_unique($lang_title);
      $lang_name = implode(', ', $lang_title) . " | " ;
    if(!empty($node->field_cm_event_lineup['und'])){
        $enhanment_titles = $event_ext_nodes->title;
        $enhanment_path = drupal_get_path_alias('node/'.$event_ext_nodes->nid);
        $enhanment_title = $enhanment_titles;
      if((strtolower($node->title))==(strtolower($event_ext_nodes->title))){
        $enhanment_title = l($enhanment_titles, $path_node);
        $title = '';
      }
      if($event_ext_nodes->type == 'cm_movie'){
        $duration_info_enhancement = '<div class="enhan-credit-container">'.$movie_credit_enhancement . $length_enhancement .'</div>';
        $summary_enhancement = '<div class="lobby-summary">'.$summary_movie_enhancement.'</div>';
        $enhancement_add = '<div class="enhanment-container"><div class="lobby-title">'.$enhanment_title.'</div><div class="lobby-summary">'.$duration_info_enhancement .$summary_enhancement.'</div></div>';
      }
       else if($event_ext_nodes->type == 'cm_movie_group'){
        $duration_info_enhancement = '<div class="enhan-credit-container">'.$country_enhancement . " " . $year_enhancement . $length_enhancement.'</div>';
        $enhancement_add = '<div class="enhanment-container"><div class="lobby-title">'.$enhanment_title.'</div><div class="lobby-summary">'.$duration_info_enhancement . $summary_movie_group_enhancement.'</div></div>';
      }
      else{
        $enhancement_add = '';
      }
  }
  else{
        $enhancement_add = '';
  }
   /****End New Enhancement for Event node type display movie & movie group content****/
    
    if(!empty($node->field_cm_person_body['und'][0]['summary'])){
      $summary_person = $node->field_cm_person_body['und'][0]['summary'];
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
    if(!empty($node->field_cm_person_type)){
      $job_id = taxonomy_term_load($node->field_cm_person_type['und'][0]['target_id']);
      $job_title =  $job_id->name;
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
        if($event_ext_nodes->type == 'cm_movie_group'){
          $picture_path_ext_moviegroup = $event_ext_nodes->field_cm_moviegroup_pictures['und'][0]['uri'];
          $image_event = '<img src="' . image_style_url('lobby', $picture_path_ext_moviegroup) . '" alt="" />';
        }else if($event_ext_nodes->type == 'cm_movie'){
          $picture_path_ext_movie = $event_ext_nodes->field_cm_movie_pictures['und'][0]['fid'];
          $file_ext_movie = file_load($picture_path_ext_movie);
          $picture_path_ext_movie = $file_ext_movie->uri;
          $image_event= '<img src="' . image_style_url('lobby', $picture_path_ext_movie) . '" alt="" />';
        }
      }else{
            $image_event = $default_image;
        } 
    }
    if($node->type == 'cm_event'){
          $output_event = '';
          $output_event .= '<div class="table-responsive event-table-data">';
          $output_event .= '<table class="table">';
		      $output_event .= '<tbody>';
          if(!empty($node->field_cm_event_short_title['und'])){
            $event_title = t($node->field_cm_event_short_title['und'][0]['value']);
          }
		      $event_title ='';
          $path = drupal_get_path_alias('node/'.$node->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($node).'</div>';
          if(!empty($node->field_cm_event_time['und'])){
              $event_date = '<span class="day-same-width">'.format_date($node->field_cm_event_time['und'][0]['value'], 'custom', 'l').'</span>';
              $event_date .= format_date($node->field_cm_event_time['und'][0]['value'], 'custom', ' d.m.y');
              $event_date_mobile = date('d.m.y', $node->field_cm_event_time['und'][0]['value']);
              $event_time = date('H:i', $node->field_cm_event_time['und'][0]['value']);
          }
          $output_event .= '<tr class="row-custom-lobby">';
          $output_event .= '<td class="date only-desktop">'.$event_date.'</td>';
          $output_event .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
			    if(!empty($node->field_cm_event_hall['und'])){
              $hall_id = taxonomy_term_load($node->field_cm_event_hall['und'][0]['target_id']);
              $hall_name = $hall_id->name;
              $output_event .= '<td class="hall only-desktop">'.t($hall_name).'</td>';
          }
          else{
              $hall_name = "";
              $output_event .= '<td class="hall only-desktop"></td>';
          }
          $output_event .= '<td class="title only-desktop">';
		      if(!empty($node->field_cm_event_comment['und'])){
              $event_title = $node->field_cm_event_comment['und'][0]['value'];
          }
          if(!empty($event_title)){
              $output_event .= l($event_title, $path);
          }
          $output_event .= '</td>';
			    if(!empty($node->field_cm_event_comment['und']) && false){//remark off
              $table_remark = $node->field_cm_event_comment['und'][0]['value'];
              $output_event .= '<td class="table_remark only-desktop">'.t($table_remark).'</td>';
          }
          else{
              $table_remark = "";
              $output_event .= '<td class="table_remark only-desktop"></td>';
          }
          if(!empty($node->field_cm_event_internal_id['und'])){
              $event_code = $node->field_cm_event_internal_id['und'][0]['value'];
              $output_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
          }
          else{
              $output_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
          }
          $output_event .='<td class="views-field-ops only-desktop">'. $flag . '</td>';
          $output_event .='<td class="add-event">'. $addevent . '</td>';
          
          $toptix_button = field_view_field('node', $node, 'field_toptix_purchase', 'full');
          $toptix_button = drupal_render($toptix_button);
          $output_event .= '<td class="purchase">' . $toptix_button . '</td>';

          $output_event .= '</tr>';
          $output_event .= '</tbody>';
          $output_event .= '</table>';
          $output_event .='<div class="view-footer">';
          $output_event .='</div>';
          $output_event .= '</div>';
    }
    if($node->type == 'cm_movie_group'){
    $result = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0') WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$node->nid') )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie_group')))) AND field_data_field_cm_event_time.field_cm_event_time_value > '$now') ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
    $row_count_movie_group_event = count($result);
    $output ='';
    $output .='<div class="table-responsive">';
      $output .= '<table class="table">';
	  if ($row_count_movie_group_event >0){
		   $output .= $output_scriens;
		 }
        $output .= ' <tbody>';
        foreach($result as $val){
          $movie_group_event_nid = $val->nid;
          $movie_group_event_info = node_load($movie_group_event_nid);
          $flag_moviegroup_event = flag_create_link('favorite_', $movie_group_event_info->nid);
          //$event_title = t($movie_group_event_info->title);
          $event_title = '';
          $path = drupal_get_path_alias('node/'.$movie_group_event_info->nid);
          $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($movie_group_event_info).'</div>';
          if(!empty($movie_group_event_info->field_cm_event_time['und'])){
          $event_date = '<span class="day-same-width">'.format_date($movie_group_event_info->field_cm_event_time['und'][0]['value'], 'custom', 'l').'</span>';
           $event_date .= format_date($movie_group_event_info->field_cm_event_time['und'][0]['value'], 'custom', ' d.m.y');
           $event_date_mobile = date('d.m.y', $movie_group_event_info->field_cm_event_time['und'][0]['value']);
           $event_time = date('H:i', $movie_group_event_info->field_cm_event_time['und'][0]['value']);
          }
          $output .= '<tr class="row-custom-lobby">';
           $output .= '<td class="date only-desktop">'.$event_date.'</td>';
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
		   if(!empty($movie_group_event_info->field_cm_event_comment['und'])){
                $event_title = $movie_group_event_info->field_cm_event_comment['und'][0]['value'];
            }
           if(!empty($event_title)){
             $output .= l($event_title, $path);
           }
           $output .= '</td>';
		   
		   if(!empty($movie_group_event_info->field_cm_event_comment['und']) && false){//remark off
                $table_remark = $movie_group_event_info->field_cm_event_comment['und'][0]['value'];
                
                $output .= '<td class="table_remark only-desktop">'.t($table_remark).'</td>';
            }
            else{
                $table_remark = "";
                $output .= '<td class="table_remark only-desktop"></td>';
            }
		   
           if(!empty($movie_group_event_info->field_cm_event_internal_id['und'])){
             $event_code = $movie_group_event_info->field_cm_event_internal_id['und'][0]['value'];
             $output .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
           }
           else{
             $output .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
           }
           $output .='<td class="views-field-ops only-desktop">'. $flag_moviegroup_event . '</td>';
           $output .='<td class="add-event">'. $addevent . '</td>';
           if(!empty($movie_group_event_info->field_toptix_purchase['und'])){
              if(empty($movie_group_event_info->field_tickets_sold_out['und'][0]['value'])){
		            $myOutputgroup = field_view_field('node', $movie_group_event_info, 'field_toptix_purchase', array('type'=>'toptix_purchase','label' => 'hidden'));
                $output .= '<td class="purchase">'.drupal_render($myOutputgroup).'</td>';
              } else{
                $output .= '<td class="purchase"><button class="sold out">'.t("sold out").'</button></td>';
              }
           } 
           else{
             $output .= '<td class="purchase"></td>';
           }
          $output .= '</tr>';
        }
        $output .= ' </tbody>';
      $output .= '</table>';
      $output .='<div class="view-footer">';
      if($row_count_movie_group_event > 3){
        $output .='<div class="more-event event-page"><span class="text text-open">'. t('Show more'). '</span><span class="text text-close">'. t('Show less'). '</span></div>';
      }
      $output .='</div>';
    $output .= '</div>';  
    }
    if($node->type == 'cm_movie'){
    $results = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value
    FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0')
    WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$node->nid' ) )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie')) AND (node.language IN  ('$language_name')))) AND field_data_field_cm_event_time.field_cm_event_time_value > '$now')
    ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
    $row_count = count($results);
    $output_movie_event ='';
    $output_movie_event .='<div class="table-responsive">';
      $output_movie_event .= '<table class="table">';
	  
	  if ($row_count >0){
		   $output_movie_event .= $output_scriens;
		 }
        $output_movie_event .= ' <tbody>';
        foreach($results as $val){
          $movie_event_nid = $val->nid;
          $movie_event_info = node_load($movie_event_nid);
          $flag_moviegroup_event = flag_create_link('favorite_', $movie_event_info->nid);
          //$event_title = t($movie_event_info->title);
          $event_title = '';
         $path = drupal_get_path_alias('node/'.$movie_event_info->nid);
         $addevent = '<div class="views-field views-field-php">'._return_addthisevent_markup($movie_event_info).'</div>';
         if(!empty($movie_event_info->field_cm_event_time['und'])){
          $event_date = '<span class="day-same-width">'.format_date($movie_event_info->field_cm_event_time['und'][0]['value'], 'custom', 'l').'</span>';
          $event_date .= format_date($movie_event_info->field_cm_event_time['und'][0]['value'], 'custom', ' d.m.y');
          $event_date_mobile = date('d.m.y', $movie_event_info->field_cm_event_time['und'][0]['value']);
          $event_time = date('H:i', $movie_event_info->field_cm_event_time['und'][0]['value']);
         }
          $output_movie_event .= '<tr class="row-custom-lobby">';
           $output_movie_event .= '<td class="date only-desktop">'.$event_date.'</td>';
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
		   if(!empty($movie_event_info->field_cm_event_comment['und'])){
                $event_title = $movie_event_info->field_cm_event_comment['und'][0]['value'];
            }
           if(!empty($event_title)){
             $output_movie_event .= l($event_title, $path);
           }
           $output_movie_event .= '</td>';
		   if(!empty($movie_event_info->field_cm_event_comment['und']) && false){//remark off
                $table_remark = $movie_event_info->field_cm_event_comment['und'][0]['value'];
                
                $output_movie_event .= '<td class="table_remark only-desktop">'.t($table_remark).'</td>';
            }
            else{
                $table_remark = "";
                $output_movie_event .= '<td class="table_remark only-desktop"></td>';
            }
           if(!empty($movie_event_info->field_cm_event_internal_id['und'])){
             $event_code = $movie_event_info->field_cm_event_internal_id['und'][0]['value'];
             $output_movie_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
           }
           else{
             $output_movie_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
           }
           $output_movie_event .='<td class="views-field-ops only-desktop">'. $flag_moviegroup_event . '</td>';
           $output_movie_event .='<td class="add-event">'. $addevent . '</td>';
           if(!empty($movie_event_info->field_toptix_purchase['und'])){
              if(empty($movie_event_info->field_tickets_sold_out['und'][0]['value'])){
		            $myOutput = field_view_field('node', $movie_event_info, 'field_toptix_purchase', array('type'=>'toptix_purchase','label' => 'hidden'));
                $output_movie_event .= '<td class="purchase">'.drupal_render($myOutput).'</td>';
              } else{
                $output_movie_event .= '<td class="purchase"><button class="sold-out">'.t("sold out").'</button></td>';
              }
           } 
           else{
             $output_movie_event .= '<td class="purchase"></td>';
           }
          $output_movie_event .= '</tr>';
        }
        $output_movie_event .= ' </tbody>';
      $output_movie_event .= '</table>';
      $output_movie_event .='<div class="view-footer">';
      if($row_count > 3){
        $output_movie_event .='<div class="more-event event-page"><span class="text text-open">'. t('Show more'). '</span><span class="text text-close">'. t('Show less'). '</span></div>';
      }
      $output_movie_event .='</div>';
    $output_movie_event .= '</div>';  
    }

      switch ($node->type) {
        case "cm_person":
          $image = '<div class="person-left-sec"><div class="person-img">'.l($image_person, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)) .'</div><div class="name-job"><div class="lobby-title">'. l($first_name .' '. $last_name, $path_node).'</div><div class="job-title">'. $job_title.'</div></div></div>';
          $title = '';
          $sort_summary = t($summary_person);
          $event_info = '';
          $event_info_movie = '';
          $event_info_movie_group = '';
          $duration_info = '';
          $top_text = '';
          $new_enhancement = '';
          $event_info_movie = '';
        break;
        case "cm_movie_group":
          $image =  '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie_group, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = t($summary_movie_group);
          $event_info_movie_group = $output;
          $event_info_movie = '';
          $event_info = '';
          $duration_info = $country . " " . $year . $length;
          $top_text = $black_text_movie_group . $white_text_movie_group;
          $new_enhancement = '';
        break;
        case "cm_movie":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_movie, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = t($summary_movie);
          $event_info_movie = $output_movie_event;
          $event_info_movie_group = '';
          $event_info = '';
          $duration_info = $movie_credit . $length;
          $top_text = $black_text_movie . $white_text_movie;
          $new_enhancement = '';
        break;
          case "cm_event":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_event, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          $sort_summary = $summary_event;
          $top_text = $black_text_event . $white_text_event;
          $event_info = $output_event;
          $event_info_movie = '';
          $event_info_movie_group = '';
          $duration_info = $event_credit . $lengths;
          $new_enhancement = $enhancement_add;
        break;
        case "cm_article":
          $image = '<div class="image-container-gorup"><div class="flag-new-links">'.$flag.'</div><div class="image-container">'.l($image_article, "$path_node", array('attributes' => array('class' =>'link-image'),'html' => true)).'</div></div>';
          $title = $title;
          if(!empty($node->field_short_sammary_article)){
            $sort_summary =  $node->field_short_sammary_article['und'][0]['value'];
          }else{
            $sort_summary = '';
          }
          $top_text = $black_text_article . $white_text_article;
          $event_info = '';
          $event_info_movie = '';
          $event_info_movie_group = '';
          $duration_info = '';
          $new_enhancement = '';
        break;
        default:
          $image = '';
          $title = '';
          $sort_summary = '';
          $event_info = '';
          $event_info_movie = '';
          $event_info_movie_group = '';
          $duration_info = '';
          $top_text = '';
          $new_enhancement = '';
      }

      switch ($node->type) {
          case "cm_event":
              print '<div id="search-main-page" class="lobby-container '.'container-'.$node->type.'">';
                  print'<div class="lobby-term-left">';
                      print'<div class="only-mobile">';
                          print $event_info;
                      print '</div>'; 
                      print '<div class="image-lobby">';
                          print $image;
                      print '</div>';
                      print '<div class="top-text-blk-wht">';
                          print $top_text;
                      print '</div>';
                  print '</div>';
                  print'<div class="lobby-term-right">';
                      print '<div class="content-type">';
                          print t(node_type_get_name($node));
                      print '</div>';
                      print'<div class="only-desktop">';
			                    print $event_info;
			                    print $event_info_movie_group;
                      print '</div>';
			                print '<div class="lobby-title">';
                          print $title;
                      print '</div>';
                      print '<div class="lobby-length">';
                          print $duration_info;
                      print '</div>';        
                      print '<div class="lobby-summary">';
                          print t(strip_tags($sort_summary));
                      print '</div>';
                      print $event_info_movie;
                      print $new_enhancement;
                  print '</div>';
                  print '<div class="clr"></div>';
              print '</div>';
          break;
          default:
              print '<div id="search-main-page" class="lobby-container '.'container-'.$node->type.'">';
                  print'<div class="lobby-term-left">';
                      print '<div class="image-lobby">';
                          print $image;
                      print '</div>';
                      print '<div class="top-text-blk-wht">';
                          print $top_text;
                      print '</div>';
                  print '</div>';
                  print'<div class="lobby-term-right">';
                      print '<div class="content-type">';
                          print t(node_type_get_name($node));
                      print '</div>';
                      print'<div class="only-desktop">';
                          print $event_info;
                          print $event_info_movie_group;
                      print '</div>';
                      print '<div class="lobby-title">';
                          print $title;
                      print '</div>';
                      print '<div class="lobby-length">';
                          print $duration_info;
                      print '</div>';        
                      print '<div class="lobby-summary">';
                          print t(strip_tags($sort_summary));
                      print '</div>';
                      print $event_info_movie;
                      print $new_enhancement;
                      print'<div class="only-mobile">';
                          print $event_info;
                          print $event_info_movie_group;
                      print '</div>'; 
                  print '</div>';
                  print '<div class="clr"></div>';
              print '</div>';
        }

  }
?>
