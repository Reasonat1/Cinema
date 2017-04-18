<?php
/**
 * @file
 * panopoly_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function panopoly_users_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_profile|user|user|form';
  $field_group->group_name = 'group_user_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Profile',
    'weight' => '3',
    'children' => array(
      0 => 'field_user_about',
      1 => 'field_user_picture',
      2 => 'field_first_name',
      3 => 'field_last_name',
      4 => 'field_mobile',
      5 => 'field_address',
      6 => 'field_city',
      7 => 'field_zip',
      8 => 'picture',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'User Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-user-profile',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_profile|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('User Profile');

  return $field_groups;
}
