<?php
/**
 * @file
 * cinematic_feature_taxonomy.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cinematic_feature_taxonomy_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_domain'.
  $field_bases['field_domain'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_domain',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
