<?php
/**
 * @file
 * cinematheque_feature_event.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cinematheque_feature_event_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__cm_event';
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'title_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
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
        'language' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'domain' => array(
          'weight' => '4',
        ),
        'flag' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
        'scheduled_actions_node' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'domain' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'title_teaser' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'top_gallert_front' => array(
            'weight' => '7',
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
          'grid_3_item_grid_front' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'top_gallery_front' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'list_normal_image_width_front' => array(
            'weight' => '31',
            'visible' => FALSE,
          ),
          'special_grid_front' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'manager' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'language' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'title_teaser' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'search_index' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'top_gallert_front' => array(
            'weight' => '6',
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
          'grid_3_item_grid_front' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'top_gallery_front' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'list_normal_image_width_front' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'special_grid_front' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'manager' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_cm_event';
  $strongarm->value = '2';
  $export['language_content_type_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cm_event';
  $strongarm->value = array(
    0 => 'cinematic-festival-12',
    1 => 'menu-site-main-menu',
  );
  $export['menu_options_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cm_event';
  $strongarm->value = 'menu-site-main-menu:0';
  $export['menu_parent_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cm_event';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cm_event';
  $strongarm->value = '0';
  $export['node_preview_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cm_event';
  $strongarm->value = 0;
  $export['node_submitted_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_cm_event';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_cm_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_tags';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_tags'] = $strongarm;

  return $export;
}
