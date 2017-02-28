<?php
/**
 * @file
 * cinematheque_feature_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cinematheque_feature_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cinematheque_feature_article_node_info() {
  $items = array(
    'cm_article' => array(
      'name' => t('Article'),
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
