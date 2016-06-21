<?php
/**
 * @file
 * Theme functions
 */

// Include all files from the includes directory.
$includes_path = dirname(__FILE__) . '/includes/*.inc';
foreach (glob($includes_path) as $filename) {
  require_once dirname(__FILE__) . '/includes/' . basename($filename);
}

/**
 * Implements template_preprocess_page().
 */
function cinemateque_preprocess_page(&$variables) {
  // Add copyright to theme.
  if ($copyright = theme_get_setting('copyright')) {
    $variables['copyright'] = check_markup($copyright['value'], $copyright['format']);
  }
}

function cinemateque_preprocess_views_view(&$vars) {
  $view = &$vars['view'];
  // Make sure it's the correct view
  if ($view->name == 'lobby') {
    // add needed javascript
    drupal_add_js(drupal_get_path('module', 'cinematic_toptix') . '/esrojsapi.js');
    drupal_add_js(drupal_get_path('module', 'cinematic_toptix') . '/frame.js');

          
  }
}