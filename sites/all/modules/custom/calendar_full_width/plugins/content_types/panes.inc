<?php
function calendar_full_width_panes_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Calendar Full Width Block'),
    'description' => t('Calendar'),
    'category' => t('Calendar Full Width Pane'),
  );
}

function calendar_full_width_panes_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = 'Calendar Full Width Block';
  $custom = calendar_full_width_block_content();
  
  $block->content = array(
  '#markup' => $custom,
  );
  return $block;
}
