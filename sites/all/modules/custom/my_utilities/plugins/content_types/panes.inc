<?php
function my_utilities_panes_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Share this View Block'),
    'description' => t('Share'),
    'category' => t('Share This Pane'),
  );
}

function my_utilities_panes_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = 'Share This View Block';
  $custom = share_this_view_block_content();
  
  $block->content = array(
  '#markup' => $custom,
  );
  return $block;
}
