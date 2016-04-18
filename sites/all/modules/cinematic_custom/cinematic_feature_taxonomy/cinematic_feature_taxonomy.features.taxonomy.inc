<?php
/**
 * @file
 * cinematic_feature_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cinematic_feature_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'countries' => array(
      'name' => 'ארצות',
      'machine_name' => 'countries',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'festival' => array(
      'name' => 'פיסטיבל',
      'machine_name' => 'festival',
      'description' => 'פיסטיבל',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
