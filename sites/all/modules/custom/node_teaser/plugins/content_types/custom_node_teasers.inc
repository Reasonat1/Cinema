<?php

$plugin = array(
    'single' => TRUE,
    'title' => t('Add node teaser view'),
    'description' => t('Display of view pane'),
    'category' => t('Node teaser'),
    'edit form' => 'node_teaser_node_content_form',
    'render callback' => 'node_teaser_node_content_form_render',
    'admin info' => 'node_teaser_node_content_form_info',
    'defaults' => array(),
    'all contexts' => TRUE,
);

/**
 * Edit form.
 */
function node_teaser_node_content_form($form, &$form_state) {
    $conf = $form_state['conf'];
    //drupal_set_message('<prre>'.print_r($conf, 1).'</pre>');
    $content_type = db_query("select type,name from node_type")->fetchAll();
    $option = array();
    foreach ($content_type as $val) {
        if ($val->type != 'cm_hall' && $val->type != 'book' && $val->type != 'panopoly_landing_page' && $val->type != 'panopoly_page') {
            $option[$val->type] = $val->name;
        }
    }
    $type = array('0' => '-select-');
    $form['#prefix'] = '<fieldset id="edit-node-teaser" class="form-wrapper">
                                     <legend><span class="fieldset-legend"><a href="#" class="fieldset-title">Node Teaser View Setting</a><span class="summary"></span></span></legend>
                                     <div class="fieldset-wrapper">';

    $form['content_type'] = array(
        '#type' => 'select',
        '#title' => t('Select Content Type'),
        '#description' => t('Choose  the content type for teaser dispaly'),
        '#options' => $option,
        '#default_value' => $conf['content_type'],
    );

    $form['node_id_default'] = array(
        '#type' => 'hidden',
        '#default_value' => $conf['node_id'],
        '#attributes' => array('class' => array('node_id_default')),
    );

    $form['node_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Select Node'),
        '#description' => t('Choose  the node to display'),
        '#default_value' => $conf['node_id'],
        '#autocomplete_path' => 'node/title/autocomplete',
        '#prefix' => '<div id="selected_content_type">',
        '#suffix' => '</div>',
    );

    $form['top_black_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Override top black corner text'),
        '#description' => t(''),
        '#default_value' => $conf['top_black_title'],
    );

    $form['top_white_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Override top white corner text'),
        '#description' => t(''),
        '#default_value' => $conf['top_white_title'],
    );

    $form['movie_image'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show movie image'),
        '#description' => t(' if checked show only movie name, teaser text and meta-info'),
        '#default_value' => $conf['movie_image'],
    );

    $form['movie_image_side'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show text to the side of image'),
        '#description' => t(''),
        '#default_value' => $conf['movie_image_side'],
    );

    $form['movie_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Override movie title'),
        '#description' => t(''),
        '#default_value' => $conf['movie_title'],
    );

    $form['movie_metainfo'] = array(
        '#type' => 'textfield',
        '#title' => t('Override movie meta-info'),
        '#description' => t(''),
        '#default_value' => $conf['movie_metainfo'],
    );

    $form['upcomming_event'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show upcoming events'),
        '#description' => t(''),
        '#default_value' => $conf['upcomming_event'],
    );

    $form['movie_teaser_text'] = array(
        '#type' => 'text_format',
        '#title' => t('Movie teaser text'),
        '#description' => t('Eneter the content for overriding the description/teaser text'),
    );

    $form['#suffix'] = '</div></fieldset>';
    
    return $form;
}

/**
 * Edit form submit function.
 */
function node_teaser_node_content_form_submit($form, &$form_state) {
    //drupal_set_message('<prre>'.print_r($form_state, 1).'</pre>');
    $form_state['conf']['content_type'] = $form_state['values']['content_type'];
    $form_state['conf']['node_id'] = $form_state['values']['node_id'];
    $form_state['conf']['top_black_title'] = $form_state['values']['top_black_title'];
    $form_state['conf']['top_white_title'] = $form_state['values']['top_white_title'];
    $form_state['conf']['movie_image'] = $form_state['values']['movie_image'];
    $form_state['conf']['movie_image_side'] = $form_state['values']['movie_image_side'];
    $form_state['conf']['movie_title'] = $form_state['values']['movie_title'];
    $form_state['conf']['movie_metainfo'] = $form_state['values']['movie_metainfo'];
    $form_state['conf']['upcomming_event'] = $form_state['values']['upcomming_event'];
    $form_state['conf']['movie_teaser_text'] = $form_state['values']['movie_teaser_text'];
}

/**
 * Render the panel.
 */
function node_teaser_node_content_form_render($subtype, $conf, $args, $context) {
    if (!empty($context)) {
        if ($context->empty) {
            return;
        }
    }
    
    global $base_url;
    $content_type = $conf['content_type'];
    $nid_string = $conf['node_id'];
    $nid_string_parts = explode( "(" , $nid_string );
    $nid_parts = explode( ")" , $nid_string_parts[1]);
    $nid = $nid_parts[0];
    $top_black_title = $conf['top_black_title'];
    $top_white_title = $conf['top_white_title'];
    $movie_image = $conf['movie_image'];
    $movie_image_side = $conf['movie_image_side'];
    $movie_title = $conf['movie_title'];
    $movie_metainfo = $conf['movie_metainfo'];
    $upcomming_event = $conf['upcomming_event'];
    $override_title_text = $conf['override_title_text'];
    $movie_teaser_text = $conf['movie_teaser_text'];
    // Render as a block.
    $block = new stdClass();
    $block->module = 'node_teaser';
    $block->delta = 'node-teaser' . str_replace('-', '_', $conf['content_type']);
    $output = "";

    // for event  type node
    if ($content_type == 'cm_event') {
        $result = db_query("SELECT  DISTINCT n.nid, n.title,n.created,n.changed,et.field_cm_event_time_value As event_start_time, et.field_cm_event_time_value2 As event_end_time,
            bk.field_mc_teaser_toptxt_blk_value As black_content, wk.field_mc_teaser_toptxt_white_value As white_content,sd.field_cm_event_short_description_value As summery
            from node As n
            LEFT JOIN field_data_field_cm_event_time AS et ON et.entity_id = n.nid
            LEFT JOIN field_data_field_mc_teaser_toptxt_blk AS bk ON bk.entity_id = n.nid
            LEFT JOIN field_data_field_mc_teaser_toptxt_white AS wk ON wk.entity_id = n.nid
            LEFT JOIN field_data_field_cm_event_short_description AS sd ON sd.entity_id = n.nid
            where n.type ='cm_event' and n.nid = '$nid'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if ($no % 2 == 0) {
                $row_class = 'even';
            } else {
                $row_class = 'odd';
            }

            // check for movie image
            $class = '';
            if ($movie_image == '0') {
                $event_image = db_query("SELECT  field_cm_event_images_fid from field_data_field_cm_event_images where entity_id = $val->nid")->fetchField();
                // check for event image
                if (!empty($event_image)) {
                    $file = file_load($event_image);
                    $uri = $file->uri;
                    $img_src = file_create_url($uri);
                    $imgae = "<img src='$img_src' alt= 'event image'>";
                } else {
                    $imgae = "";
                }
            } else {
                $class = 'no-image';
                $imgae = "";
            }
            // check if show images to side of text
            if ($movie_image_side == '1') {
                $class.= '  side-image';
            }

            // Favorite flag link
            $flag = flag_create_link('favorite_', $val->nid);

            // Event time
            if (!empty($val->event_start_time)) {
                $date = date('d.m.y', $val->event_start_time);
                $time = date('h:i', $val->event_start_time);
            }
            // event white box content
            if ($top_black_title == '') {
                if (!empty($val->black_content)) {
                    $data_b = $val->black_content;
                    $black_content = "<span class='black-content'>$data_b</span>";
                } else {
                    $black_content = '';
                }
            } else {
                $black_content = "<span class='black-content'>$top_black_title</span>";
            }

           // event white box content
            if ($top_white_title == '') {
                if (!empty($val->white_content)) {
                    $data_w = $val->white_content;
                    $white_content = "<span class='black-white'>$data_w</span>";
                } else {
                    $white_content = '';
                }
            }else{
                $white_content = "<span class='black-white'>$top_white_title</span>";
            }

            // show teaser text
            if (trim($movie_teaser_text['value'] == '')) {
                if (!empty($val->summery)) {
                    $description = substr($val->summery, 0, 600);
                    $description = $description;
                } else {
                    $description = "";
                }
            } else {
                $description = $movie_teaser_text['value'];
            }

            // movie meta information
            if ($movie_metainfo == '') {
                if (!empty($val->movie_duration)) {
                    $movie_duration = "<span>Duration : $val->movie_duration $val->movie_duration_period</span>";
                    if (!empty($val->meta_credit)) {
                        $movie_duration.= "<span class='credit'>Director: $val->meta_credit</span>";
                    }
                } else {
                    $movie_duration = "";
                }
            } else {
                $movie_duration = $movie_metainfo;
            }
        // Event other screening
        if($upcomming_event == 1){
            $results_rel_events = db_query("SELECT DISTINCT node_field_data_field_cm_event_lineup.nid AS node_field_data_field_cm_event_lineup_nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value
            FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') INNER JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0') WHERE (( (node.nid = '$nid' ) )AND(( (node.status = '1') AND (node.type IN  ('cm_event')) AND (node.language IN  ('$lang_name')) ))) ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
            $event_rel_event = '';
            $movie_rel_nid = $results_rel_events[0]->node_field_data_field_cm_event_lineup_nid;
            $node_type = node_load($movie_rel_nid);
            $types = $node_type->type;
            $current_nid = $nid;
             $result_rel_movie_rel_movie = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0')
          WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$movie_rel_nid' ) )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('$types')) AND (node.language IN  ('$lang_name')) )))
          ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
            //$row_count = count($result_rel_movie_rel_movie);
              $event_rel_event .= '<div class="table-responsive">';
               $event_rel_event .= '<table class="table">';
                 $event_rel_event .= '<tbody>';
                 $a= 0;
                 //$row_count = count($result_rel_movie);
                 foreach($result_rel_movie_rel_movie as $val_event){
                   $a++;
                   $node_val_event = node_load($val_event->nid);
                   
                   if($node_val_event->nid !=$current_nid){
                     if(!empty($node_val_event->nid)){
                       $event_title = (!empty($node_val_event->field_cm_event_short_title)) ? $node_val_event->field_cm_event_short_title['und'][0]['value'] : $node_val_event->title;
                       $title_new = t($event_title);
                     }else{
                       $title_new = '<div class="hide-div"></div>';
                     }
                     $path = drupal_get_path_alias('node/'.$node_val_event->nid);
                      $flag_rel_event = flag_create_link('favorite_', $node_val_event->nid);
                      $addevent = '<div class="views-field views-field-php add-event">'._return_addthisevent_markup($node_val_event).'</div>';
                      if(!empty($node_val_event->field_cm_event_internal_id['und'])){
                          $event_code = t($node_val_event->field_cm_event_internal_id['und'][0]['value']);
                      }else{
                        $event_code = '<div class="hide-div"></div>';
                      }
                       if(!empty($node_val_event->field_cm_event_time['und'])){
                         $event_date = date('l d.m.y', $node_val_event->field_cm_event_time['und'][0]['value']);
                         $event_date_mobile = date('d.m.y', $node_val_event->field_cm_event_time['und'][0]['value']);
                       }else{
                          $event_date = '<div class="hide-div"></div>';
                       }
                      if(!empty($node_val_event->field_cm_event_time['und'])){
                          $event_time = date('H:i', $node_val_event->field_cm_event_time['und'][0]['value']);
                      }else{
                          $event_time = '<div class="hide-div"></div>';
                      }
                      if(!empty($node_val_event->field_cm_event_hall['und'])){
                          $hall_id = taxonomy_term_load($node_val_event->field_cm_event_hall['und'][0]['target_id']);
                          $hall_name = t($hall_id->name);
                      }else{
                        $hall_name = '<div class="hide-div"></div>';
                      }
                      if(!empty($node_val_event->field_toptix_purchase['und'])){
                         $toptix_code = $node_val_event->field_toptix_purchase['und'][0]['value'];
                         $top_link = 'http://tickets.jer-cin.org.il/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
                         $puchase = '<button data-url="'.$top_link.'" class="toptix-purchase">'.t('TICKETS').'</button>';
                      }else{
                       $puchase = '<div class="hide-div"></div>';
                      }
                    $event_rel_event .= '<tr class="row-custom-lobby">';
                     $event_rel_event .= '<td class="date only-desktop">'. t($event_date). '</td>';
                     $event_rel_event .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
                     $event_rel_event .= '<td class="hall only-desktop">'. $hall_name .'<div class="only-mobile">'.$event_code.'</td>';
                     $event_rel_event .= '<td class="title only-desktop">'. l($title_new, $path) .'</td>';
                     $event_rel_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
                     $event_rel_event .= '<td class="flag only-desktop">' .$flag_rel_event .'</td>';
                     $event_rel_event .= '<td class="add-event only-desktop">' ._return_addthisevent_markup($node_val_event) .'</td>';
                     $event_rel_event .= '<td class="views-field views-field-field-toptix-purchase last-mobile">'.$puchase.'</td>';
                    $event_rel_event .= '</tr>';
                   }
                 }
                 $event_rel_event .= '</tbody>';
               $event_rel_event .= '</table>';
              $event_rel_event .= '</div>';
        }
        //
            $title = $val->title;
            $alias = $base_url . '/' . drupal_lookup_path('alias', "node/" . $val->nid);
            $html.= "<div class='row-$row_class teaser-row $class'>";
            $html.= "<div class='wrapper-image'><div class='event-image'>$imgae</div>";
            $html.= "<div class='event-date-black-white-background'>$black_content $white_content</div>";
            $html.= "<div class='event-flag'>$flag</div>";
            $html.= "<div class='text-on-image'><div class='event-title'><span>".l($title,'node/'.$val->nid,array('html'=>TRUE))."</span></div>";
            $html.= "<div class='event-time'><span class='time'>$time</span><span class='date'>$date</span><a href='$alias'><span class='ticket'>Ticket</span></a></div></div></div>";
            $html.= "<div class='movie_metainfo'><span>$movie_duration</span></div>";
            $html.= "<div class='event-summery'>$description</div>";
            $html.= "<div class='movie-teaser-related-event'>$event_rel_event</div>";
            $html.= "</div>";
            $no++;
        }

        $output.= "<div class='node-teaser wapper  $content_type'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }

    // for movie  type node
    if ($conf['content_type'] == 'cm_movie') {
        $result = db_query("SELECT  n.nid, n.title,n.created,n.changed,bk.field_mc_teaser_toptxt_blk_value As black_content, wk.field_mc_teaser_toptxt_white_value As white_content,
            md.field_cm_movie_duration_interval As movie_duration,md.field_cm_movie_duration_period As movie_duration_period,mc.field_cm_movie_meta_credit_value As meta_credit,ss.field_cm_movie_short_summary_value As summery
            from node As n
            LEFT JOIN field_data_field_mc_teaser_toptxt_blk As bk ON bk.entity_id = n.nid
            LEFT JOIN field_data_field_mc_teaser_toptxt_white As wk ON wk.entity_id = n.nid
            LEFT JOIN field_data_field_cm_movie_duration As md ON md.entity_id = n.nid
            LEFT JOIN field_data_field_cm_movie_meta_credit AS mc ON mc.entity_id = n.nid
            LEFT JOIN field_data_field_cm_movie_short_summary AS ss ON ss.entity_id = n.nid
            where n.type ='cm_movie' and n.nid = '$nid'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if ($no % 2 == 0) {
                $row_class = 'even';
            } else {
                $row_class = 'odd';
            }

            // check for movie image
            $class = '';
            if ($movie_image == '0') {
                $movie_picture = db_query("SELECT  field_cm_movie_pictures_fid from field_data_field_cm_movie_pictures where entity_id = $val->nid")->fetchField();
                if (!empty($movie_picture)) {
                    $file = file_load($movie_picture);
                    $uri = $file->uri;
                    $img_src = file_create_url($uri);
                    $imgae = "<img src='$img_src' alt= 'event image'>";
                } else {
                    $imgae = "";
                }
            } else {
                $class = 'no-image';
                $imgae = "";
            }

            // check if show images to side of text
            if ($movie_image_side == '1') {
                $class.= '  side-image';
            }


            // Favorite flag link
            $flag = flag_create_link('favorite_', $val->nid);

            // event black box content
            if ($top_black_title == '') {
                if (!empty($val->black_content)) {
                    $data_b = $val->black_content;
                    $black_content = "<span class='black-content'>$data_b</span>";
                } else {
                    $black_content = "";
                }
            } else {
                $black_content = "<span class='black-content'>$top_black_title</span>";
            }


            // event white box content
            if ($top_white_title == '') {
                if (!empty($val->white_content)) {
                    $data_w = $val->white_content;
                    $white_content = "<span class='black-white'>$data_w</span>";
                } else {
                    $white_content = "";
                }
            } else {
                $white_content = "<span class='black-white'>$top_white_title</span>";
            }

            // check for movie video
            $movie_video = db_query("SELECT  field_cm_movie_videos_fid from field_data_field_cm_movie_videos where entity_id = $val->nid")->fetchField();
            if (!empty($movie_video)) {
                $play_icon = "<img src='http://m.airpano.ru/images/play-icon.png' alt= 'play' height='30px' width='30px'>";
            } else {
                $play_icon = "";
            }

            // movie meta information
            if ($movie_metainfo == '') {
                if (!empty($val->movie_duration)) {
                    $movie_duration = "<span>Duration : $val->movie_duration $val->movie_duration_period</span>";
                    if (!empty($val->meta_credit)) {
                        $movie_duration.= "<span class='credit'>Director: $val->meta_credit</span>";
                    }
                } else {
                    $movie_duration = "";
                }
            } else {
                $movie_duration = $movie_metainfo;
            }

            // show teaser text
            if (trim($movie_teaser_text['value'] == '')) {
                if (!empty($val->summery)) {
                    $description = substr($val->summery, 0, 600);
                    $description = $description;
                } else {
                    $description = "";
                }
            } else {
                $description = $movie_teaser_text['value'];
            }

            // override movie title
            if ($movie_title == '') {
                $title = $val->title;
            } else {
                $title = $movie_title;
            }
           //Movie related event
        if($upcomming_event == 1){
               $results = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value
    FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0')
    WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$nid' ) )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie')) AND (node.language IN  ('$lang_name')))))
    ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
            //$row_count = count($results);
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
                  $event_time = date('H:i', $movie_event_info->field_cm_event_time['und'][0]['value']);
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
           //
            $html.= "<div class='row-$row_class teaser-row $class'>";
            $html.= "<div class='wrapper-image'><div class='movie-image'>$imgae</div>";
            $html.= "<div class='movie-date-black-white-background'>$black_content $white_content</div>";
            $html.= "<div class='movie-flag'>$flag</div>";
            $html.= "<div class='text-on-image'><div class='movie-title'><span>".l($title,'node/'.$val->nid,array('html'=>TRUE))."</span></div>";
            $html.= "<div class='movie_play'><span>$play_icon</span></div></div></div>";
            $html.= "<div class='movie_metainfo'><span>$movie_duration</span></div>";
            $html.= "<div class='movie_summery'><span>$description</span></div>";
            $html.= "<div class='movie-teaser-related-event'>$output_movie_event</div>";
            $html.= "</div>";
            $no++;
        }

        $output.= "<div class='node-teaser wapper  $content_type'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }

    // for article node type
    if ($conf['content_type'] == 'cm_movie_group') {
        $result = db_query("SELECT  n.nid, n.title,n.created,n.changed,bk.field_mc_teaser_toptxt_blk_value As black_content, wk.field_mc_teaser_toptxt_white_value As white_content,
            ss.field_cm_moviegroup_short_summar_value As summary	,
            md.field_cm_moviegroup_duration_interval As movigroup_duration,md.field_cm_moviegroup_duration_period As movigroup_duration_period
            from node As n            
            LEFT JOIN field_data_field_mc_teaser_toptxt_blk As bk ON bk.entity_id = n.nid
            LEFT JOIN field_data_field_mc_teaser_toptxt_white As wk ON wk.entity_id = n.nid
            LEFT JOIN field_data_field_cm_moviegroup_short_summar As ss ON ss.entity_id = n.nid
            LEFT JOIN field_data_field_cm_moviegroup_duration As md ON md.entity_id = n.nid
            where n.type ='cm_movie_group' and n.nid = '$nid'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if ($no % 2 == 0) {
                $row_class = 'even';
            } else {
                $row_class = 'odd';
            }

            // check for movie image
            $class = '';
            if ($movie_image == '0') {
                $moviegroup_picture = db_query("SELECT  field_cm_moviegroup_pictures_fid from field_data_field_cm_moviegroup_pictures where entity_id = $val->nid")->fetchField();
                if (!empty($moviegroup_picture)) {
                    $file = file_load($moviegroup_picture);
                    $uri = $file->uri;
                    $img_src = file_create_url($uri);
                    $imgae = "<img src='$img_src' alt= 'event image'>";
                } else {
                    $imgae = "";
                }
            } else {
                $class = 'no-image';
                $imgae = "";
            }

            // check if show images to side of text
            if ($movie_image_side == '1') {
                $class.= '  side-image';
            }


            // Favorite flag link
            $flag = flag_create_link('favorite_', $val->nid);

            // event black box content
            if ($top_black_title == '') {
                if (!empty($val->black_content)) {
                    $data_b = $val->black_content;
                    $black_content = "<span class='black-content'>$data_b</span>";
                } else {
                    $black_content = "";
                }
            } else {
                $black_content = "<span class='black-content'>$top_black_title</span>";
            }


            // event white box content
            if ($top_white_title == '') {
                if (!empty($val->white_content)) {
                    $data_w = $val->white_content;
                    $white_content = "<span class='black-white'>$data_w</span>";
                } else {
                    $white_content = "";
                }
            } else {
                $white_content = "<span class='black-white'>$top_white_title</span>";
            }

            // check for movie video
            $moviegroup_video = db_query("SELECT  field_cm_moviegroup_videos_fid from field_data_field_cm_moviegroup_videos where entity_id = $val->nid")->fetchField();
            if (!empty($moviegroup_video)) {
                $play_icon = "<img src='http://m.airpano.ru/images/play-icon.png' alt= 'play' height='30px' width='30px'>";
            } else {
                $play_icon = "";
            }

            // movie meta information
            if ($movie_metainfo == '') {
                if (!empty($val->movigroup_duration)) {
                    $moviegroup_duration = "<span>Duration : $val->movigroup_duration $val->movigroup_duration_period</span>";
                } else {
                    $moviegroup_duration = "";
                }
            } else {
                $moviegroup_duration = $movie_metainfo;
            }

            // show teaser text
            if (trim($movie_teaser_text['value'] == '')) {
                if (!empty($val->summery)) {
                    $description = substr($val->summery, 0, 600);
                    $description = $description;
                } else {
                    $description = "";
                }
            } else {
                $description = $movie_teaser_text['value'];
            }

            // override movie title
            if ($movie_title == '') {
                $title = $val->title;
            } else {
                $title = $movie_title;
            }
           // Movie group related events
            if($upcomming_event == 1){
                $result = db_query("SELECT DISTINCT node.nid AS nid, field_data_field_cm_event_time.field_cm_event_time_value AS field_data_field_cm_event_time_field_cm_event_time_value FROM {node} node LEFT JOIN {field_data_field_cm_event_lineup} field_data_field_cm_event_lineup ON node.nid = field_data_field_cm_event_lineup.entity_id AND (field_data_field_cm_event_lineup.entity_type = 'node' AND field_data_field_cm_event_lineup.deleted = '0') LEFT JOIN {node} node_field_data_field_cm_event_lineup ON field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = node_field_data_field_cm_event_lineup.nid LEFT JOIN {field_data_field_cm_event_time} field_data_field_cm_event_time ON node.nid = field_data_field_cm_event_time.entity_id AND (field_data_field_cm_event_time.entity_type = 'node' AND field_data_field_cm_event_time.deleted = '0') WHERE (( (field_data_field_cm_event_lineup.field_cm_event_lineup_target_id = '$nid') )AND(( (node.status = '1') AND (node_field_data_field_cm_event_lineup.type IN  ('cm_movie_group'))))) ORDER BY field_data_field_cm_event_time_field_cm_event_time_value ASC")->fetchAll();
                //$row_count = count($result);
                $output_movie_group_event ='';
                $output_movie_group_event .='<div class="table-responsive">';
                    $output_movie_group_event .= '<table class="table">';
                        $output_movie_group_event .= ' <tbody>';
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
                        $event_time = date('H:i', $movie_group_event_info->field_cm_event_time['und'][0]['value']);
                        }
                            $output_movie_group_event .= '<tr class="row-custom-lobby">';
                                $output_movie_group_event .= '<td class="date only-desktop">'.t($event_date).'</td>';
                                $output_movie_group_event .= '<td class="time"><div class="only-mobile">'.$event_date_mobile.'</div>'.$event_time.'</td>';
                                if(!empty($movie_group_event_info->field_cm_event_hall['und'])){
                                $hall_id = taxonomy_term_load($movie_group_event_info->field_cm_event_hall['und'][0]['target_id']);
                                $hall_name = $hall_id->name;
                                $output_movie_group_event .= '<td class="hall only-desktop">'.t($hall_name).'</td>';
                                }
                                else{
                                $hall_name = "";
                                $output_movie_group_event .= '<td class="hall only-desktop"></td>';
                                }
                                $output_movie_group_event .= '<td class="title only-desktop">';
                                if(!empty($event_title)){
                                $output_movie_group_event .= l($event_title, $path);
                                }
                                $output_movie_group_event .= '</td>';
                                if(!empty($movie_group_event_info->field_cm_event_internal_id['und'])){
                                $event_code = $movie_group_event_info->field_cm_event_internal_id['und'][0]['value'];
                                $output_movie_group_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div>'.t($event_code).'</td>';
                                }
                                else{
                                $output_movie_group_event .= '<td class="code"><div class="only-mobile">'.$hall_name.'</div></td>';
                                }
                                $output_movie_group_event .='<td class="flag only-desktop">'. $flag_moviegroup_event . '</td>';
                                $output_movie_group_event .='<td class="add-event only-desktop">'. $addevent . '</td>';
                                if(!empty($movie_group_event_info->field_toptix_purchase['und'])){
                                $toptix_code = $movie_group_event_info->field_toptix_purchase['und'][0]['value'];
                                $top_link = 'http://199.203.164.53/loader.aspx/?target=hall.aspx?event='.$toptix_code.'';
                                $output_movie_group_event .= '<td class="purchase">'.'<button data-url="'.$top_link.'" class="toptix-purchase">'.t("TICKETS").'</button>'.'</td>';
                                } 
                                else{
                                $output_movie_group_event .= '<td class="purchase"></td>';
                            }
                            $output_movie_group_event .= '</tr>';
                        }
                        $output_movie_group_event .= ' </tbody>';
                    $output_movie_group_event .= '</table>';
                $output_movie_group_event .= '</div>';
            }
           //end
            $html.= "<div class='row-$row_class teaser-row $class'>";
            $html.= "<div class='wrapper-image'><div class='moviegroup-image'>$imgae</div>";
            $html.= "<div class='movie-date-black-white-background'>$black_content $white_content</div>";
            $html.= "<div class='moviegroup-flag'>$flag</div>";
            $html.= "<div class='text-on-image'><div class='moviegroup-title'><span>".l($title,'node/'.$val->nid,array('html'=>TRUE))."</span></div>";
            $html.= "<div class='moviegroup_play'><span>$play_icon</span></div></div></div>";
            $html.= "<div class='moviegroup_metainfo'><span>$moviegroup_duration</span></div>";
            $html.= "<div class='moviegroup_summery'><span>$description</span></div>";
            $html.= "<div class='movie-teaser-related-event'>$output_movie_group_event</div>";
            $html.= "</div>";
            $no++;
        }

        $output.= "<div class='node-teaser wapper  $content_type'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }

    // for person  type node
    if ($content_type == 'cm_person') {
        $result = db_query("SELECT n.nid, n.title,n.created,n.changed,cp.field_cm_person_photo_fid As person_photo, cp.field_cm_person_photo_alt As person_photo_alt,
            pb.field_cm_person_body_value As person_description, pf.field_cm_person_first_name_value As first_name, pl.field_cm_person_last_name_value,
            pt.field_cm_person_type_target_id As job_title
            from node As n
            LEFT JOIN field_data_field_cm_person_photo AS cp ON cp.entity_id = n.nid
            LEFT JOIN field_data_field_cm_person_body AS pb ON pb.entity_id = n.nid
            LEFT JOIN field_data_field_cm_person_first_name AS pf ON pf.entity_id = n.nid
           LEFT JOIN field_data_field_cm_person_last_name AS pl ON pf.entity_id = n.nid
           LEFT jOIN field_data_field_cm_person_type As pt ON pt.entity_id = n.nid
            where n.type ='cm_person' and n.nid = '$nid'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if ($no % 2 == 0) {
                $row_class = 'even';
            } else {
                $row_class = 'odd';
            }

            // check for person image
            if (!empty($val->person_photo)) {
                $file = file_load($val->person_photo);
                $uri = $file->uri;
                $img_src = file_create_url($uri);
                $imgae = "<img src='$img_src' alt= 'event image'>";
            } else {
                $imgae = "<img src='$base_url/sites/all/themes/cinemateque/images/persion_default.png' alt= 'event image'>";
            }

            //check for job title
            $job_title = '';
            if (!empty($val->job_title)) {
                $term = taxonomy_term_load($val->job_title);
                $job_title = $term->name;
            }

            //check for description
            if (trim($movie_teaser_text['value'] == '')) {
                if (!empty($val->person_description)) {
                    $description = substr($val->person_description, 0, 600);
                    $description = $description;
                } else {
                    $description = '';
                }
            } else {
                $description = $movie_teaser_text['value'];
            }

            $html.= "<div class='row-$row_class teaser-row'>";
            $html.= "<div class='person-image'>$imgae</div>";
            $html.= "<div class='person-title'>".l("<span class='person-name'>".$val->title."</span><span>$job_title</span>","node/".$val->nid,array('html'=>TRUE))."</div>";
            $html.= "<div class='person-description'>$description</div>";
            $html.= "</div>";
            $no++;
        }

        $output.= "<div class='node-teaser wapper  $content_type'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }

    // for webform  type node
    if ($conf['content_type'] == 'webform') {
        $result = db_query("SELECT  n.nid, n.title,n.created,n.changed
            from node As n
            where n.type ='webform' and n.nid = '$nid'")->fetchAll();

        // show teaser text
        if (trim($movie_teaser_text['value'] != '')) {
            $description = $movie_teaser_text['value'];
        } else {
            $description = '';
        }
        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            $alias = $base_url . '/' . drupal_lookup_path('alias', "node/" . $val->nid);
            if ($no % 2 == 0) {
                $row_class = 'even';
            } else {
                $row_class = 'odd';
            }
            $html.= "<div class='row-$row_class teaser-row'>";
            $html.= "<div class='webform-title'><a href='$alias'>$val->title</a></div>";
            $html.= "<div class='moviegroup_summery'>$description</div>";
            $html.= "</div>";
            $no++;
        }

        $output.= "<div class='node-teaser wapper  $content_type'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }

    // for person  type node
    if ($content_type == 'cm_article') {
        $result = db_query("SELECT n.nid, n.title,n.created,n.changed,sb.field_cm_article_subtitle_value As article_subtitle,db.body_value As summery
            from node As n
           LEFT jOIN field_data_field_cm_article_subtitle As sb ON sb.entity_id = n.nid
            LEFT jOIN field_data_body As db ON db.entity_id = n.nid
            where n.type ='cm_article'  and n.nid = '$nid'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if ($no % 2 == 0) {
                $row_class = 'even';
            } else {
                $row_class = 'odd';
            }

            // check for movie image
            $class = '';
            if ($movie_image == '0') {
                $artical_picture = db_query("SELECT  field_cm_article_image_fid from field_data_field_cm_article_image where entity_id = $val->nid")->fetchField();
                if (!empty($artical_picture)) {
                    $file = file_load($artical_picture);
                    $uri = $file->uri;
                    $img_src = file_create_url($uri);
                    $imgae = "<img src='$img_src' alt= 'event image'>";
                } else {
                    $imgae = "";
                }
            } else {
                $class = 'no-image';
                $imgae = "";
            }

            // check if show images to side of text
            if ($movie_image_side == '1') {
                $class.= '  side-image';
            }


            // Favorite flag link
            $flag = flag_create_link('favorite_', $val->nid);

            // event black box content
            if ($top_black_title == '') {
                if (!empty($val->black_content)) {
                    $data_b = $val->black_content;
                    $black_content = "<span class='black-content'>$data_b</span>";
                } else {
                    $black_content = "";
                }
            } else {
                $black_content = "<span class='black-content'>$top_black_title</span>";
            }


            // event white box content
            if ($top_white_title == '') {
                if (!empty($val->white_content)) {
                    $data_w = $val->white_content;
                    $white_content = "<span class='black-white'>$data_w</span>";
                } else {
                    $white_content = "";
                }
            } else {
                $white_content = "<span class='black-white'>$top_white_title</span>";
            }


            // show teaser text
            if (trim($movie_teaser_text['value'] == '')) {
                if (!empty($val->summery)) {
                    $description = substr($val->summery, 0, 600);
                    $description = $description;
                } else {
                    $description = "";
                }
            } else {
                $description = $movie_teaser_text['value'];
            }

            // override movie title
            if ($movie_title == '') {
                $title = $val->title;
            } else {
                $title = $movie_title;
            }
            $subtitle = $val->article_subtitle;

            $html.= "<div class='row-$row_class teaser-row $class'>";
            $html.= "<div class='article-image'>$imgae</div>";
            $html.= "<div class='article-date-black-white-background'>$black_content $white_content</div>";
            $html.= "<div class='article-flag'>$flag</div>";
            $html.= "<div class='article-title'><span>".l($title,'node/'.$val->nid)."</span></div>";
            $html.= "<div class='article-subtitle'><span>$subtitle</span></div>";
            $html.= "<div class='article-summery'><span>$description</span></div>";
            $html.= "</div>";
            $no++;
        }

        $output.= "<div class='node-teaser wapper  $content_type'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }
    $block->content = $output;
    return $block;
}

/**
 * Admin info.
 */
function node_teaser_node_content_form_info($subtype, $conf, $contexts) {
    if (!empty($conf)) {
        return node_teaser_node_content_form_render($subtype, $conf, $args = null, $context = null);
    }
}

