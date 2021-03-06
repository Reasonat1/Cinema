<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('minipanel 2 region 50% width tamplate'),
  'description' => t('Shows a minipanel tamplate with basic configuration options.'),
  'category' => t('Mini Panel Template'),
  'edit form' => 'my_pane_minipanel_2_region_tamplate_edit_form',
  'render callback' => 'my_pane_minipanel_2_region_tamplate_render',
  'admin info' => 'my_pane_minipanel_2_region_tamplate_admin_info',
);

/**
 * 'admin info' callback for panel pane.
 */
function my_pane_minipanel_2_region_tamplate_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = 'Custom mini panel : 2 region with 50%  width each';
    return $block;
  }
}

/**
 * 'Edit form' callback for the content type.
 */
function my_pane_minipanel_2_region_tamplate_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
 
  $form['minipanel_title'] = array(
    '#title' => t('Mini Panel Name'),
    '#description' => t('The human readable name of the minipanel pane.'),
    '#type' => 'textfield',
    '#default_value' => $conf['minipanel_tile'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function my_pane_minipanel_2_region_tamplate_edit_form_submit($form, &$form_state) {
      $name = $form['minipanel_title']['#value'];
       $lower_str = strtolower($name);
       $string = str_replace(" ","_",$lower_str);
       $myStr = preg_replace('/[^A-Za-z0-9\-]/', '', $string);
       $mini_machine_name = substr($myStr, 0, 30);

       $form_state['conf']['minipanel_title'] = $mini_machine_name;
       
        $mini = new stdClass();
        $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
        $mini->api_version = 1;
        $mini->name = $mini_machine_name;
        $mini->category = '';
        $mini->admin_title = $name;
        $mini->admin_description = '';
        $mini->requiredcontexts = array();
        $mini->contexts = array();
        $mini->relationships = array();
        $display = new panels_display();
        $display->layout = 'tworegion50and50';
        $display->layout_settings = array();
        $display->panel_settings = array(
          'style_settings' => array(
            'default' => NULL,
            'left' => NULL,
            'right' => NULL,
          ),
        );
        $display->cache = array();
        $display->title = '';
        $display->uuid = 'ffa7e9af-5e34-4a60-bb07-42acc20c7648';
        $display->content = array();
        $display->panels = array();
        $display->hide_title = PANELS_TITLE_FIXED;
        $display->title_pane = '0';
        $mini->display = $display;


       $custom_mini = panels_mini_save($mini);
       return $custom_mini;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
//function my_pane_minipanel_2_region_tamplate_render($subtype, $conf, $panel_args, $context = NULL) {
//  $block =  panels_mini_block_view($conf['minipanel_title']);
//  print $block['content'];
//}