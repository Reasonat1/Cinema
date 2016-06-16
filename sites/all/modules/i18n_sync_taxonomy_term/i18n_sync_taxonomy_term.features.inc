<?php
/**
 * @file
 * Feature integration
 */

/**
 * Implements hook_features_pipe_COMPONENT_alter().
 */
function i18n_sync_taxonomy_term_features_pipe_taxonomy_alter(&$pipe, $data, $export) {
  if (!empty($data) && module_exists('variable')) {
    variable_include();
    foreach (variable_list_module('i18n_sync_taxonomy_term') as $variable) {
      if (isset($variable['multiple']) && $variable['multiple'] === 'vocabulary_name') {
        $children = variable_build($variable['name']);
        if (!empty($children['children'])) {
          foreach ($children['children'] as $child_variable) {
            if (in_array($child_variable['index'], $data)) {
              $pipe['variable'][] = $child_variable['name'];
            }
          }
        }
      }
    }
  }
}
