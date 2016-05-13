<?php

/**
 * @file
 * A specification for the custom gallery entity that is part of Panopoly Widgets
 */

/**
 * Implements hook_field_info().
 */
function my_pane_field_info() {
  return array(
    'panopoly_gallery' => array(
      'label' => t('Gallery'),
      'description' => t('A wonderfully widgetsal gallery field'),
      'default_widget' => 'panopoly_gallery_form',
      'default_formatter' => 'panopoly_gallery_default',
      'settings' => array(
        'uri_scheme' => variable_get('file_default_scheme', 'public'),
        'default_image' => 1,
      ),
      'instance_settings' => array(
        'file_extensions' => 'jpg jpeg gif png',
        'file_directory' => 'general',
        'max_filesize' => '',
        'alt_field' => 0,
        'title_field' => 0,
        'max_resolution' => '',
        'min_resolution' => '',
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_info().
 */
function my_pane_field_widget_info() {
  return array(
    'panopoly_gallery_form' => array(
      'label' => t('Gallery'),
      'field types' => array('panopoly_gallery'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
    ),
  );
}
/**
 * Implementation of hook_field_formatter_info().
 */
function my_pane_field_formatter_info() {
  return array(
    'panopoly_gallery_default' => array(
      'label' => t('Default'),
      'field types' => array('panopoly_gallery'),
      'settings' => array(
        'image_style' => 'panopoly_image_spotlight',
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function my_pane_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if ($instance['widget']['type'] == 'panopoly_gallery_form') {

    // Make it a multipart form
    $form['#attributes']['enctype'] = 'multipart/form-data';

    // Define the element
    $element['title'] = array(
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['title']) ? $items[$delta]['title'] : NULL,
    );

    $element['link'] = array(
      '#title' => t('Link'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['link']) ? $items[$delta]['link'] : NULL,
    );

    $element['fid'] = array(
      '#title' => t('Image'),
      '#type' => 'managed_file',
      '#upload_location' => file_field_widget_uri($field, $instance),
      '#default_value' => isset($items[$delta]['fid']) ? $items[$delta]['fid'] : NULL,
    );

    $element['alt'] = array(
      '#title' => t('Alt text'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['alt']) ? $items[$delta]['alt'] : NULL,
    );

    $element['description'] = array(
      '#title' => t('Description'),
      '#type' => 'textarea',
      '#rows' => '2',
      '#resizable' => FALSE,
      '#default_value' => isset($items[$delta]['description']) ? $items[$delta]['description'] : NULL,
    );
  }

  return $element;
}