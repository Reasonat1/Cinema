<?php
/**
 * @file
 * cinematheque_feature_moviegroup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cinematheque_feature_moviegroup_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cinematheque_feature_moviegroup_node_info() {
  $items = array(
    'cm_movie_group' => array(
      'name' => t('Movie group'),
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
