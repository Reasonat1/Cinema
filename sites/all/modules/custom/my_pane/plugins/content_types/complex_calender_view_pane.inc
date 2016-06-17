<?php
function my_pane_complex_calender_view_pane_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Complex Calender View Block'),
    'description' => t('Event Calender'),
    'category' => t('Complex Calender Pane'),
  );
}

function my_pane_complex_calender_view_pane_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = 'Complex Calender View Block';
  $custom = complex_calender_view_block_content();
  
  $block->content = $custom;
  return $block;
}