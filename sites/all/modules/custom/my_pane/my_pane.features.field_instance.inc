<?php
/**
 * @file
 * my_pane.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function my_pane_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'fieldable_panels_pane-gallery-field_custom_gallery_duration'
  $field_instances['fieldable_panels_pane-gallery-field_custom_gallery_duration'] = array(
    'bundle' => 'gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_custom_gallery_duration',
    'label' => 'Slide Duration',
    'required' => 0,
    'settings' => array(
      'max' => 60,
      'min' => 1,
      'prefix' => '',
      'suffix' => 'seconds',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-gallery-field_custom_gallery_items'
  $field_instances['fieldable_panels_pane-gallery-field_custom_gallery_items'] = array(
    'bundle' => 'gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'my_pane',
        'settings' => array(
          'image_style' => 'custom_gallery_slider',
        ),
        'type' => 'panopoly_gallery_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_custom_gallery_items',
    'label' => 'Items',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'general',
      'file_extensions' => 'jpg jpeg gif png',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'my_pane',
      'settings' => array(),
      'type' => 'panopoly_gallery_form',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'fieldable_panels_pane-gallery-field_custom_gallery_pager'
  $field_instances['fieldable_panels_pane-gallery-field_custom_gallery_pager'] = array(
    'bundle' => 'gallery',
    'default_value' => array(
      0 => array(
        'value' => 'full',
      ),
    ),
    'deleted' => 0,
    'description' => 'How would you like the pager to appear?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_custom_gallery_pager',
    'label' => 'Pager Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

    // Exported field_instance:
  // 'fieldable_panels_pane-sponser-field_custom_sponser_image'
  $field_instances['fieldable_panels_pane-sponser-field_custom_sponser_image'] = array(
    'bundle' => 'sponser',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'panopoly_image_full',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_custom_sponser_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'general',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 1,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(
          'panopoly_image_full' => 'panopoly_image_full',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

      // Exported field_instance:
  // 'fieldable_panels_pane-caruosel-field_custom_caruosel_sponser'
  $field_instances['fieldable_panels_pane-caruosel-field_custom_caruosel_sponser'] = array(
       'bundle' => 'caruosel',
     'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'panopoly_image_full',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_custom_caruosel_sponser',
    'label' => 'Sopnser Caruosel image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'general',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Items');
  t('Pager Style');
  t('Slide Duration');
  t('Image');
  t('Sopnser Caruosel image');


  return $field_instances;
}