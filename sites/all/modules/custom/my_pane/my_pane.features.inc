<?php
/**
 * @file
 * my_pane.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function my_pane_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function my_pane_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
