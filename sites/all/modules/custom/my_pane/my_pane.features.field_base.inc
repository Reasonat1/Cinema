<?php
/**
 * @file
 * my_pane.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function my_pane_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_custom_gallery_duration'
  $field_bases['field_custom_gallery_duration'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_gallery_duration',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );
   // Exported field_base: 'field_custom_lobby_term'
  $field_bases['field_custom_lobby_term'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_lobby_term',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );
  // Exported field_base: 'field_custom_gallery_items'
  $field_bases['field_custom_gallery_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_gallery_items',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'my_pane',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'panopoly_gallery',
  );

  // Exported field_base: 'field_custom_gallery_pager'
  $field_bases['field_custom_gallery_pager'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_gallery_pager',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'full' => 'Full pager (slide numbers)',
        'mini' => 'Mini pager (previous/next buttons)',
        'hide' => 'Hidden (no way to manually change the slide)',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_custom_sponser_image'
  $field_bases['field_custom_sponser_image'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_sponser_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );
  
      // Exported field_base: 'field_custom_caruosel_sponser'
  $field_bases['field_custom_caruosel_sponser'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_caruosel_sponser',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );
  
  // Exported field_base: 'field_custom_caruosel_slider'
  $field_bases['field_custom_caruosel_slider'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_caruosel_slider',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'my_pane',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'panopoly_caruosel',
  );
  return $field_bases;
}
