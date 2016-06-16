<?php
/**
 * @file
 * Variable information
 */

/**
 * Implements hook_variable_info().
 */
function i18n_sync_taxonomy_term_variable_info($options = array()) {
  $variables['i18n_sync_taxonomy_term_[vocabulary_name]'] = array(
    'title' => t('Synchronize fields on translation for vocabulary.', array(), $options),
    'type' => 'multiple',
    'repeat' => array(
      'type' => 'array',
    ),
    'group' => 'i18n',
  );
  return $variables;
}
