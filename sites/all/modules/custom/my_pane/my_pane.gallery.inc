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
   'panopoly_caruosel' => array(
      'label' => t('caruosel'),
      'description' => t('A wonderfully widget for caruosel field'),
      'default_widget' => 'panopoly_caruosel_form',
      'default_formatter' => 'panopoly_caruosel_default',
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
 * Implements hook_field_is_empty()
 */
function my_pane_field_is_empty($item, $field) {
  if (empty($item['title']) && empty($item['link']) && empty($item['description']) && empty($item['fid'])) {
    return TRUE;
  }
  return FALSE;
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
    'panopoly_caruosel_form' => array(
      'label' => t('Caruosel'),
      'field types' => array('panopoly_caruosel'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
    ),
  );
}
/**
 * Implements hook_field_settings_form()
 */
function my_pane_field_settings_form($field, $instance, $has_data) {
  $form = array();
  $defaults = field_info_field_settings($field['type']);
  $settings = array_merge($defaults, $field['settings']);

  $scheme_options = array();
  foreach (file_get_stream_wrappers(STREAM_WRAPPERS_WRITE_VISIBLE) as $scheme => $stream_wrapper) {
    $scheme_options[$scheme] = $stream_wrapper['name'];
  }
  $form['uri_scheme'] = array(
    '#type' => 'radios',
    '#title' => t('Upload destination'),
    '#options' => $scheme_options,
    '#default_value' => $settings['uri_scheme'],
    '#description' => t('Select where the final files should be stored. Private file storage has significantly more overhead than public files, but allows restricted access to files within this field.'),
  );

  // When the user sets the scheme on the UI, even for the first time, it's
  // updating a field because fields are created on the "Manage fields"
  // page. So image_field_update_field() can handle this change.
  $form['default_image'] = array(
    '#title' => t('Default image'),
    '#type' => 'managed_file',
    '#description' => t('If no image is uploaded, this image will be shown on display.'),
    '#default_value' => $field['settings']['default_image'],
    '#upload_location' => $settings['uri_scheme'] . '://default_images/',
  );

  return $form;
}

/**
 * Implements hook_field_instance_settings_form()
 */
function my_pane_field_instance_settings_form($field, $instance) {
  $form = image_field_instance_settings_form($field, $instance);
  return $form;
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
    'panopoly_caruosel_default' => array(
      'label' => t('Default'),
      'field types' => array('panopoly_caruosel'),
      'settings' => array(
        'image_style' => 'panopoly_image_spotlight',
      ),
    ),   
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function my_pane_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $element = array();

  if ($display['type'] == 'panopoly_gallery_default') {
    $element['image_style'] = array(
      '#title' => t('Image style'),
      '#type' => 'select',
      '#options' => image_style_options(),
      '#default_value' => $settings['image_style'],
      '#required' => TRUE,
    );
  }
    if ($display['type'] == 'panopoly_caruosel_default') {
    $element['image_style'] = array(
      '#title' => t('Image style'),
      '#type' => 'select',
      '#options' => image_style_options(),
      '#default_value' => $settings['image_style'],
      '#required' => TRUE,
    );
  }
  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function my_pane_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = t('Image Style: @style', array('@style' => $settings['image_style']));
  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function my_pane_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
    if ($instance['widget']['type'] == 'panopoly_gallery_form') {
        // Include the Spotlight Rotation time setting
        $duration_field = field_get_items('fieldable_panels_pane', $entity, 'field_custom_gallery_duration');
        if ($duration_field) {
          $duration_field = reset($duration_field);
          $duration = $duration_field['value'];
        }
        if (empty($duration)) {
          $duration = variable_get('my_pane_gallery_rotation_time', 4);
        }

        $pager_style = 'full'; // Default to the Full pager if field isn't filled out (i.e., legacy data).
        $pager_style_field = field_get_items('fieldable_panels_pane', $entity, 'field_custom_gallery_pager');
        if ($pager_style_field) {
          $pager_style_field = reset($pager_style_field);
          $pager_style = $pager_style_field['value'];
        }

        $element = array();
        $settings = $display['settings'];
        $formatter = $display['type'];

        // Load the images and filter out slides with missing images.
        foreach ($items as $delta => $item_data) {
          if (!empty($item_data['uuid']) && module_exists('uuid')) {
            $image_entity = entity_uuid_load('file', array($item_data['uuid']));
            $image = file_load(array_pop($image_entity)->fid);
          }
          else {
            $image = (object)$item_data;
          }
          if (empty($image->uri) || !file_exists($image->uri)) {
            unset($items[$delta]);
          }
          else {
            $items[$delta]['image'] = $image;
          }
        }

        // Assemble the spotlight wrapper
        // $element[0] rather than $element because hook_field_formatter_view()
        // expects a renderable array for the $items, as an array of child elements
        // keyed by numeric indexes starting from 0.
        $element[0] = array(
          '#theme' => 'panopoly_gallery_wrapper',
          '#items' => $items,
          '#settings' => $settings,
          '#formatter' => $formatter,
          '#duration' => $duration,
          '#pager_style' => $pager_style,
          '#entity_type' => $entity_type,
          '#entity' => $entity,
          'slides' => array(),
        );

        // Assemble the spotlight items (rendered in panopoly_spotlight_wrapper())
        foreach ($items as $delta => $item_data) {
          $element[0]['slides'][] = array(
            '#theme' => 'panopoly_gallery_view',
            '#items' => $item_data,
            '#delta' => $delta,
            '#settings' => $settings,
            '#entity_type' => $entity_type,
            '#entity' => $entity,
          );
        }
    }
   if ($instance['widget']['type'] == 'panopoly_caruosel_form') {

        $element = array();
        $settings = $display['settings'];
        $formatter = $display['type'];

        // Load the images and filter out slides with missing images.
        foreach ($items as $delta => $item_data) {
          if (!empty($item_data['uuid']) && module_exists('uuid')) {
            $image_entity = entity_uuid_load('file', array($item_data['uuid']));
            $image = file_load(array_pop($image_entity)->fid);
          }
          else {
            $image = (object)$item_data;
          }
          if (empty($image->uri) || !file_exists($image->uri)) {
            unset($items[$delta]);
          }
          else {
            $items[$delta]['image'] = $image;
          }
        }

        // Assemble the spotlight wrapper
        // $element[0] rather than $element because hook_field_formatter_view()
        // expects a renderable array for the $items, as an array of child elements
        // keyed by numeric indexes starting from 0.
        $element[0] = array(
          '#theme' => 'panopoly_caruosel_wrapper',
          '#items' => $items,
          '#settings' => $settings,
          '#formatter' => $formatter,
          '#entity_type' => $entity_type,
          '#entity' => $entity,
          'slides' => array(),
        );

        // Assemble the spotlight items (rendered in panopoly_spotlight_wrapper())
        foreach ($items as $delta => $item_data) {
          $element[0]['slides'][] = array(
            '#theme' => 'panopoly_caruosel_view',
            '#items' => $item_data,
            '#delta' => $delta,
            '#settings' => $settings,
            '#entity_type' => $entity_type,
            '#entity' => $entity,
          );
        }
    }
  return $element;
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

    $element['subtitle'] = array(
      '#title' => t('Subtitle'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['subtitle']) ? $items[$delta]['subtitle'] : NULL,
    );
    
    $element['link_title'] = array(
      '#title' => t('Link Title'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['link_title']) ? $items[$delta]['link_title'] : NULL,
    );
    
    $element['link'] = array(
      '#title' => t('Link'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['link']) ? $items[$delta]['link'] : NULL,
    );

    $element['fid'] = array(
      '#title' => t('Image'),
      '#type' => 'media',
      '#upload_location' => file_field_widget_uri($field, $instance),
      '#default_value' => isset($items[$delta]['fid']) ? $items[$delta]['fid'] : NULL,
    );

    $element['alt'] = array(
      '#title' => t('Alt text'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['alt']) ? $items[$delta]['alt'] : NULL,
      '#required' => TRUE,
    );

    $element['description'] = array(
      '#title' => t('Description'),
      '#type' => 'textarea',
      '#rows' => '2',
      '#resizable' => FALSE,
      '#default_value' => isset($items[$delta]['description']) ? $items[$delta]['description'] : NULL,
    );
  }
    if ($instance['widget']['type'] == 'panopoly_caruosel_form') {
      
    // Make it a multipart form
    $form['#attributes']['enctype'] = 'multipart/form-data';

    $element['fid'] = array(
      '#title' => t('Image'),
      '#type' => 'media',
      '#upload_location' => file_field_widget_uri($field, $instance),
      '#default_value' => isset($items[$delta]['fid']) ? $items[$delta]['fid'] : NULL,
    );
    
//    $element['link_title'] = array(
//      '#title' => t('Link Title'),
//      '#type' => 'textfield',
//      '#default_value' => isset($items[$delta]['link_title']) ? $items[$delta]['link_title'] : NULL,
//    );
   $element['new_tab'] = array(
      '#title' => t('Check  to open link in new tab'),
      '#type' => 'checkbox',
      '#default_value' => isset($items[$delta]['new_tab']) ? $items[$delta]['new_tab'] : NULL,
    );
      
    $element['link'] = array(
      '#title' => t('Link Url'),
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]['link']) ? $items[$delta]['link'] : NULL,
    );

  }

  return $element;
}

/**
 * Implements hook_field_validate().
 */
function my_pane_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  foreach ($items as $delta => $item) {
    if (!my_pane_field_is_empty($item, $field) && empty($item['fid'])) {
      $errors[$field['field_name']][$langcode][$delta][] = array(
        'error' => 'my_pane_gallery_image_required',
        'message' => t('!name field is required.', array('!name' => t('Image'))),
      );
    }
  }
}
/**
 * Implements hook_field_presave()
 */
function my_pane_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  // We need to set presave values if fids are not set. This shouldn't effect save operations
  // form API validation will prevent this from ever happening unless previewing.
  if (!empty($items)) {
    foreach ($items as &$item) {
      if (empty($item['fid'])) {
        $fid = variable_get('my_pane_default_' . $entity->bundle . '_fid', NULL);

        if (!empty($fid)) {
          $item['fid'] = $fid;
        }
      }
    }
    image_field_presave($entity_type, $entity, $field, $instance, $langcode, $items);
  }
}
/**
 * Implements hook_field_load().
 */
function my_pane_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  $entity_items_copy = $items;
  image_field_load($entity_type, $entities, $field, $instances, $langcode, $items, $age);
  // image_field_load() will overwrite 'title' with the image title. Here we
  // return it to the item title.
  foreach ($entity_items_copy as $entity_id => $items_copy) {
    foreach ($items_copy as $delta => $item) {
     // $items[$entity_id][$delta]['title'] = $item['title'];
    }
  }
}

/**
 * Implements hook_field_insert().
 */
function my_pane_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  image_field_insert($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_update().
 */
function my_pane_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {

  // Load the original entity, if $entity->original is not already set.
  // This is done as per http://drupal.org/node/985642 and can be removed when that patch is committed.
  if (empty($entity->original)) {
    $entity->original = entity_load_unchanged($entity_type, $field['id']);
  }

  image_field_update($entity_type, $entity, $field, $instance, $langcode, $items);
}
/**
 * Implements hook_field_delete().
 */
function  my_pane_field_delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
  image_field_delete($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_delete_revision().
 */
function  my_pane_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, &$items) {
  image_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, $items);
}
/**
 * Implements hook_field_prepare_view().
 */
function my_pane_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  // If there are no files specified at all, use the default.
  // TODO - make sure this works
  foreach ($entities as $id => $entity) {
    if (empty($items[$id]) && $field['settings']['default_image']) {
      if ($file = file_load($field['settings']['default_image'])) {
        $items[$id][0] = (array) $file + array(
          'is_default' => TRUE,
          'alt' => '',
          'title' => '',
        );
      }
    }
  }
}
/**
 * Theme function for the gallery wrapper
 */
function theme_panopoly_gallery_wrapper($variables){

  $output = '';
  $items = $variables['element']['#items'];
  $duration = $variables['element']['#duration'];
  $pager_style = $variables['element']['#pager_style'];
  $element = array();
  $output .= '<div class="panopoly-spotlight-widget-wrapper">';
  $output.= '<div class="nav"><a href="#" id="prev2">Prev</a> <a href="#" id="next2">Next</a></div>';
  $output .= "<ul class='custom-slideshow'>".render($variables['element']['slides']). "</ul>";
  
  $output .= '</div>';  // class="panopoly-spotlight-widget-wrapper"

  return $output;
}

/**
 * Theme function for gallery items
 */
function theme_panopoly_gallery_view($variables) {
  $output = '';
  $title = $variables['element']['#items']['title'];
  $subtitle = $variables['element']['#items']['subtitle'];
  $description = $variables['element']['#items']['description'];
  $link = $variables['element']['#items']['link'];
  $link_title = $variables['element']['#items']['link_title'];
  $alt = $variables['element']['#items']['alt'];
  $settings = $variables['element']['#settings'];
  $delta = $variables['element']['#delta'];

  $image = $variables['element']['#items']['image'];
  $image_markup = theme('image_style', array('style_name' => $settings['image_style'], 'path' => $image->uri, 'alt' => $alt));
    if($link_title == ''){
        $link_title = 'Read More';
    }
     $output = '<li>';
     if ($link) {
        $output .= l($image_markup, $link, array('html' => TRUE));
        $output .= "<div class='pinch'>";
        $output.="<span class='slider-title'>$title</span>";
        $output.="<span class='slider-subtitle'>$subtitle</span>";
        $output.="<span class='slider-readmore'><a href='$link' target='_blank'>$link_title</a></span>";
         $output .= "</div>";
      }
      else {
        $output .= $image_markup;
        $output .= "<div class='pinch'>";
        $output.="<span class='slider-title'>$title</span>";
        $output.="<span class='slider-subtitle'>$subtitle</span>";
        $output.="<span class='slider-readmore'><a href='$link' target='_blank'>Read More</a></span>";
         $output .= "</div>";
      }
       $output .= '</li>';

  return $output;
}


/**
 * Theme function for the caruosel  wrapper
 */
function theme_panopoly_caruosel_wrapper($variables){

  $output = '';
  $items = $variables['element']['#items'];
  $element = array();
  $output .= '<div class="panopoly-spotlight-widget-wrapper">';

  $output.= '<div class="nav"><a href="#" id="prev">Prev</a> <a href="#" id="next">Next</a></div>';
  $output .= "<div class='caruosel-slideshow'>".render($variables['element']['slides']). "</ul>";
  
  $output .= '</div>';

  return $output;
}

/**
 * Theme function for gallery items
 */
function theme_panopoly_caruosel_view($variables) {
  $output = '';
  $link_title = $variables['element']['#items']['link_title'];
  $link_url = $variables['element']['#items']['link'];
  $new_tab = $variables['element']['#items']['new_tab'];
  $alt = $variables['element']['#items']['alt'];
  $settings = $variables['element']['#settings'];
  $delta = $variables['element']['#delta'];

  $image = $variables['element']['#items']['image'];
  $image_markup = theme('image_style', array('style_name' => $settings['image_style'], 'path' => $image->uri, 'alt' => $alt));

  if($new_tab == '1'){
      $attribute = "target='_blank'";
  }else{
      $attribute = '';
  }
     $output = '<li>';
     if(!empty($link_url)){
         $output.= "<a href='$link_url' $attribute>".$image_markup."</a>";
     }else{
         $output.= $image_markup;
     }
//        $output .= "<div class='middel-content'>";
//        $output.="<span class='slider-readmore'><a href='$link_url' target='_blank'>$link_title</a></span>";
//         $output .= "</div>";
       $output.= '</li>';

  return $output;
}