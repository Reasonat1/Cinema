<?php
function my_backend_panes_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Complex Calender View Block'),
    'description' => t('Event Calender'),
    'category' => t('Complex Calender Pane'),
  );
}

function my_backend_panes_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = 'Complex Calender View Block';
  $custom = complex_calender_view_block_content();
  
  $block->content = array(
  '#markup' => $custom,
  '#attached' => array(
    'css' => array(drupal_get_path('module', 'my_backend') . '/include/my_backend.css'),
    'js' =>  array(drupal_get_path('module', 'my_backend') . '/include/my_backend.js'),
	),
  );
  return $block;
}
