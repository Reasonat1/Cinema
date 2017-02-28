<?php
/**
 * @file
 * cinematheque_feature_article.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cinematheque_feature_article_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__cm_article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'title_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'one_item_static_front' => array(
        'custom_settings' => TRUE,
      ),
      'list_wide_image_front' => array(
        'custom_settings' => TRUE,
      ),
      'list_normal_image_width_front' => array(
        'custom_settings' => TRUE,
      ),
      'grid_3_item_grid_front' => array(
        'custom_settings' => TRUE,
      ),
      'title_credit_description' => array(
        'custom_settings' => FALSE,
      ),
      'top_gallery_front' => array(
        'custom_settings' => TRUE,
      ),
      'special_grid_front' => array(
        'custom_settings' => TRUE,
      ),
      'manager' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '12',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '13',
        ),
        'flag' => array(
          'weight' => '10',
        ),
        'metatags' => array(
          'weight' => '18',
        ),
        'redirect' => array(
          'weight' => '15',
        ),
        'scheduled_actions_node' => array(
          'weight' => '17',
        ),
        'xmlsitemap' => array(
          'weight' => '16',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'title_teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'top_gallert_front' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'one_item_static' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'one_item_static_front' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'list_wide_image_front' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'list_normal_image_width_front' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'grid_3_item_grid_front' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'special_grid_front' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'manager' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'top_gallery_front' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'language' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'title_teaser' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'top_gallert_front' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'one_item_static' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'one_item_static_front' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'list_wide_image_front' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'list_normal_image_width_front' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'grid_3_item_grid_front' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'special_grid_front' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'manager' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'top_gallery_front' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cm_article';
  $strongarm->value = '2';
  $export['language_content_type_cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cm_article';
  $strongarm->value = array(
    0 => 'cinematic-festival-12',
    1 => 'menu-site-main-menu',
  );
  $export['menu_options_cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cm_article';
  $strongarm->value = 'menu-site-main-menu:0';
  $export['menu_parent_cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cm_article';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cm_article';
  $strongarm->value = '0';
  $export['node_preview_cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cm_article';
  $strongarm->value = 0;
  $export['node_submitted_cm_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_cm_article';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_cm_article'] = $strongarm;

  return $export;
}
