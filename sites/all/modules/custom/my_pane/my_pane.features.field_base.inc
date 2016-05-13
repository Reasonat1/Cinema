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

  // Exported field_base: 'field_basic_gallery_duration'
  $field_bases['field_basic_gallery_duration'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_gallery_duration',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_basic_gallery_items'
  $field_bases['field_basic_gallery_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_gallery_items',
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

  // Exported field_base: 'field_basic_gallery_pager'
  $field_bases['field_basic_gallery_pager'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_basic_gallery_pager',
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

  return $field_bases;
}
