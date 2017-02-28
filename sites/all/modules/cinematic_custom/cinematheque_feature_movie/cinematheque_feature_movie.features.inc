<?php
/**
 * @file
 * cinematheque_feature_movie.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cinematheque_feature_movie_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function cinematheque_feature_movie_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorite".
  $flags['favorite_'] = array(
    'entity_type' => 'node',
    'title' => 'Favorite',
    'global' => 0,
    'types' => array(
      0 => 'cm_event',
      1 => 'cm_movie',
    ),
    'flag_short' => 'Set as Favorite ',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Set as unfavorite ',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'one_item_static_front' => 'one_item_static_front',
      'list_normal_image_width_front' => 'list_normal_image_width_front',
      'list_wide_image_front' => 'list_wide_image_front',
      'grid_3_item_grid_front' => 'grid_3_item_grid_front',
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'print' => 0,
      'title_teaser' => 0,
      'top_gallery_front' => 0,
      'special_grid_front' => 0,
      'manager' => 0,
      'title_credit_description' => 0,
      'featured' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'cinematheque_feature_movie',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function cinematheque_feature_movie_node_info() {
  $items = array(
    'cm_movie' => array(
      'name' => t('Movie'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Admin Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
