<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Add node teaser view'),
  'description' => t('Display of view pane'),
  'category' => t('Node teaser'),
  'edit form' => 'my_pane_node_content_form',
  'render callback' => 'my_pane_node_content_form_render',
  'admin info' => 'my_pane_node_content_form_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);


/**
 * Edit form.
 */
function my_pane_node_content_form($form, &$form_state) {
 $conf = $form_state['conf'];

 $content_type = db_query("select type,name from node_type")->fetchAll();
 $option = array();
 foreach ($content_type as $val){
     $option[$val->type]= $val->name;
 }

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

  $form['view_mode'] = array(
   '#type' => 'select',
   '#title' => t('Select View Mode'),
   '#description' => t('Choose  the view mode of  the content display'),
  '#options' => array('teaser'=>'Teaser'),
   '#default_value' => $conf['view_mode'],
 );
  
   $form['no_of_content'] = array(
   '#type' => 'textfield',
   '#title' => t('No of item to show'),
   '#description' => t('Enter 0 or leave empty to display all result.'),
   '#default_value' => $conf['no_of_content'],
 );
   $form['sort_order'] = array(
   '#type' => 'select',
   '#title' => t('Sort order '),
   '#options' => array('ASC' => 'ASC','DESC' =>'DESC'),
   '#default_value' => $conf['sort_order'],
 );
$form['#suffix'] = '</div></fieldset>';
 return $form;
}
/**
 * Edit form submit function.
 */
function my_pane_node_content_form_submit($form, &$form_state) {
  $form_state['conf']['content_type'] = $form_state['values']['content_type'];
  $form_state['conf']['view_mode'] = $form_state['values']['view_mode'];
  $form_state['conf']['no_of_content'] = $form_state['values']['no_of_content'];
  $form_state['conf']['sort_order'] = $form_state['values']['sort_order'];
}
/**
 * Render the panel.
 */
function my_pane_node_content_form_render($subtype, $conf, $args, $context) {
    if(!empty($context)){
        if ($context->empty) {
            return;
          }
    }
  
    global $base_url;
    // Render as a block.
    $block = new stdClass();
    $block->module = 'my_pane';
    $block->delta = 'node-teaser' . str_replace('-', '_', $conf['content_type']);
    $output = "";
    
    // for event  type node
    if($conf['content_type'] == 'cm_event'){
        $result = db_query("SELECT n.nid, n.title,n.created,n.changed,et.field_cm_event_time_value As event_start_time, et.field_cm_event_time_value2 As event_end_time,
            ei.field_cm_event_images_fid As event_image, bk.field_mc_teaser_toptxt_blk_value As black_content, wk.field_mc_teaser_toptxt_white_value As white_content
            from node As n
            LEFT JOIN field_data_field_cm_event_time AS et ON et.entity_id = n.nid
            LEFT JOIN field_data_field_cm_event_images AS ei ON ei.entity_id = n.nid
            LEFT JOIN field_data_field_mc_teaser_toptxt_blk AS bk ON bk.entity_id = n.nid
            LEFT JOIN field_data_field_mc_teaser_toptxt_white AS wk ON wk.entity_id = n.nid
            where n.type ='cm_event'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if($no % 2 == 0){  $row_class = 'even'; }else{  $row_class = 'odd';}
            
            // check for event image
            if(!empty($val->event_image)){
                $file = file_load($val->event_image);
                $uri = $file->uri;
                $img_src = file_create_url($uri);
                $imgae = "<img src='$img_src' alt= 'event image'>";
            }else{
                $imgae = "";
            }
            
            // Favorite flag link
            $flag = flag_create_link('favorite_', $val->nid);
            
            // Event time
            if(!empty($val->event_start_time)){
                $date = date('d.m.y',$val->event_start_time);
                $time = date('h:i',$val->event_start_time);
            }
            
            // event black box content
            if(!empty($val->black_content)){
                $data_b = $val->black_content;
                $black_content = "<span class='black-content'>$data_b</span>";
            }
            
            // event white box content
            if(!empty($val->white_content)){
                $data_w = $val->white_content;
                $white_content = "<span class='black-white'>$data_w</span>";
            }

            $html.= "<div class='row-$row_class teaser-row'>";
            $html.= "<div class='event-image'>$imgae</div>";
            $html.= "<div class='event-date-black-white-background'>$black_content $white_content</div>";
            $html.= "<div class='event-flag'>$flag</div>";
            $html.= "<div class='event-title'><span>$val->title</span></div>";
            $html.= "<div class='event-time'><span class='time'>$time</span><span class='date'>$date</span></div>";
            $html.= "</div>";
            $no++;
        }
        $class = $conf['content_type'];
        $output.= "<div class='node-teaser wapper  $class'>";
        $output.= "<div class='inner-wrapper'>";
        $output.= "<div class='content'>";
        $output.=$html;
        $output.= "</div></div></div>";
    }
    
    // for person  type node
    if($conf['content_type'] == 'cm_person'){
        $result = db_query("SELECT n.nid, n.title,n.created,n.changed,cp.field_cm_person_photo_fid As person_photo, cp.field_cm_person_photo_alt As person_photo_alt,
            pb.field_cm_person_body_value As person_description, pf.field_cm_person_first_name_value As first_name, pl.field_cm_person_last_name_value,
            pt.field_cm_person_type_target_id As job_title
            from node As n
            LEFT JOIN field_data_field_cm_person_photo AS cp ON cp.entity_id = n.nid
            LEFT JOIN field_data_field_cm_person_body AS pb ON pb.entity_id = n.nid
            LEFT JOIN field_data_field_cm_person_first_name AS pf ON pf.entity_id = n.nid
           LEFT JOIN field_data_field_cm_person_last_name AS pl ON pf.entity_id = n.nid
           LEFT jOIN field_data_field_cm_person_type As pt ON pt.entity_id = n.nid
            where n.type ='cm_person'")->fetchAll();

        // Build the output of block
        $html = "";
        $no = 1;
        foreach ($result as $val) {
            if($no % 2 == 0){  $row_class = 'even'; }else{  $row_class = 'odd';}
            
            // check for person image
            if(!empty($val->person_photo)){
                $file = file_load($val->person_photo);
                $uri = $file->uri;
                $img_src = file_create_url($uri);
                $imgae = "<img src='$img_src' alt= 'event image'>";
            }else{
                $imgae = "<img src='$base_url/sites/all/themes/cinemateque/images/persion_default.png' alt= 'event image'>";
            }  
            
            //check for job title
            $job_title = '';
            if(!empty($val->job_title)){
                $term = taxonomy_term_load($val->job_title);
                $job_title = $term->name;
            }
            
            //check for description
            $description = '';
            if(!empty($val->person_description)){
                $description = substr($val->person_description, 0, 300);
                $description = $description.'...';
            }
            
            $html.= "<div class='row-$row_class teaser-row'>";
            $html.= "<div class='person-image'>$imgae</div>";
            $html.= "<div class='person-title'><span class='person-name'>$val->title</span><span>$job_title</span></div>";
            $html.= "<div class='person-description'>$description</div>";
            $html.= "</div>";
            $no++;
        }
        $class = $conf['content_type'];
        $output.= "<div class='node-teaser wapper  $class'>";
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
function my_pane_node_content_form_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $content = '<p><b>Node Type:</b> ' . $conf['content_type'] . '</p>';
    $content = '<p><b>View mode:</b> ' . $conf['view_mode'] . '</p>';

    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = $content;
    return $block;
  }
}
