<?php
/**
 * @file
 * my_pane.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function my_pane_defaultconfig_features() {
  return array(
    'my_pane' => array(
      'strongarm' => 'strongarm',
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function my_pane_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_wysiwyg_default_render';
  $strongarm->value = 'field_attach';
  $export['media_wysiwyg_default_render'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function my_pane_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'media',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'create fieldable caruosel'.
  $permissions['create fieldable caruosel'] = array(
    'name' => 'create fieldable caruosel',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable gallery'.
  $permissions['create fieldable gallery'] = array(
    'name' => 'create fieldable gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable sponser'.
  $permissions['create fieldable sponser'] = array(
    'name' => 'create fieldable sponser',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable caruosel'.
  $permissions['delete fieldable caruosel'] = array(
    'name' => 'delete fieldable caruosel',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable gallery'.
  $permissions['delete fieldable gallery'] = array(
    'name' => 'delete fieldable gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable sponser'.
  $permissions['delete fieldable sponser'] = array(
    'name' => 'delete fieldable sponser',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable caruosel'.
  $permissions['edit fieldable caruosel'] = array(
    'name' => 'edit fieldable caruosel',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable gallery'.
  $permissions['edit fieldable gallery'] = array(
    'name' => 'edit fieldable gallery',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable sponser'.
  $permissions['edit fieldable sponser'] = array(
    'name' => 'edit fieldable sponser',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  return $permissions;
}
