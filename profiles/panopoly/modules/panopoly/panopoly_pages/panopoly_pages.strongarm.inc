<?php
/**
 * @file
 * panopoly_pages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function panopoly_pages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_popup_authored_enabled_panopoly_landing_page';
  $strongarm->value = 0;
  $export['date_popup_authored_enabled_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__panopoly_landing_page';
  $strongarm->value = array(
    'view_modes' => array(
      'title_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'one_item_static_front' => array(
        'custom_settings' => FALSE,
      ),
      'list_wide_image_front' => array(
        'custom_settings' => FALSE,
      ),
      'list_normal_image_width_front' => array(
        'custom_settings' => FALSE,
      ),
      'grid_3_item_grid_front' => array(
        'custom_settings' => FALSE,
      ),
      'title_credit_description' => array(
        'custom_settings' => FALSE,
      ),
      'top_gallery_front' => array(
        'custom_settings' => FALSE,
      ),
      'special_grid_front' => array(
        'custom_settings' => FALSE,
      ),
      'manager' => array(
        'custom_settings' => TRUE,
      ),
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
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '3',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'metatags' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
        'xmlsitemap' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'language' => array(
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__panopoly_page';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
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
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'title_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'one_item_static_front' => array(
        'custom_settings' => FALSE,
      ),
      'list_wide_image_front' => array(
        'custom_settings' => FALSE,
      ),
      'list_normal_image_width_front' => array(
        'custom_settings' => FALSE,
      ),
      'grid_3_item_grid_front' => array(
        'custom_settings' => FALSE,
      ),
      'title_credit_description' => array(
        'custom_settings' => FALSE,
      ),
      'top_gallery_front' => array(
        'custom_settings' => FALSE,
      ),
      'special_grid_front' => array(
        'custom_settings' => FALSE,
      ),
      'manager' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'domain' => array(
          'weight' => '2',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'metatags' => array(
          'weight' => '10',
        ),
        'redirect' => array(
          'weight' => '8',
        ),
        'xmlsitemap' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'language' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_panopoly_landing_page';
  $strongarm->value = '2';
  $export['language_content_type_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_panopoly_page';
  $strongarm->value = '2';
  $export['language_content_type_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_panopoly_landing_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_panopoly_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_panopoly_landing_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_panopoly_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_panopoly_landing_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_panopoly_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_panopoly_landing_page';
  $strongarm->value = '0';
  $export['node_preview_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_panopoly_page';
  $strongarm->value = '0';
  $export['node_preview_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_panopoly_landing_page';
  $strongarm->value = 0;
  $export['node_submitted_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_panopoly_page';
  $strongarm->value = 0;
  $export['node_submitted_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_panopoly_landing_page';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'manager' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_panopoly_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_panopoly_page';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'search_result' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'manager' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'featured' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_landing_page:default_selection';
  $strongarm->value = 'node:panopoly_landing_page:default:default';
  $export['panelizer_node:panopoly_landing_page:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_landing_page:page_manager_selection';
  $strongarm->value = 'node:panopoly_landing_page:default';
  $export['panelizer_node:panopoly_landing_page:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_landing_page_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:panopoly_landing_page_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_landing_page_allowed_types_default';
  $strongarm->value = 1;
  $export['panelizer_node:panopoly_landing_page_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_page:default_selection';
  $strongarm->value = 'node:panopoly_page:default:default';
  $export['panelizer_node:panopoly_page:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_page:featured_selection';
  $strongarm->value = 'node:panopoly_page:default:featured';
  $export['panelizer_node:panopoly_page:featured_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_page:page_manager_selection';
  $strongarm->value = 'node:panopoly_page:default';
  $export['panelizer_node:panopoly_page:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_page:teaser_selection';
  $strongarm->value = 'node:panopoly_page:default:teaser';
  $export['panelizer_node:panopoly_page:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_page_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:panopoly_page_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:panopoly_page_allowed_types_default';
  $strongarm->value = 1;
  $export['panelizer_node:panopoly_page_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_panopoly_page';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_panopoly_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_panopoly_landing_page';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_panopoly_landing_page'] = $strongarm;

  return $export;
}
