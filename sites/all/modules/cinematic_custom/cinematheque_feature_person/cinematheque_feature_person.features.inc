<?php
/**
 * @file
 * cinematheque_feature_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cinematheque_feature_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cinematheque_feature_person_node_info() {
  $items = array(
    'cm_person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
