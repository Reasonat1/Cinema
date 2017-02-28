<?php
/**
 * @file
 * cinematheque_feature_movie.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cinematheque_feature_movie_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_private|node|cm_movie|form';
  $field_group->group_name = 'group_private';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_movie';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Private Field',
    'weight' => '25',
    'children' => array(
      0 => 'field_cm_movie_distributor',
      1 => 'field_cm_movie_showid',
      2 => 'field_cm_movie_tech_info',
      3 => 'field_cm_movie_tech_screen_forma',
      4 => 'field_cm_movie_genre',
      5 => 'field_cm_movie_alt_title',
      6 => 'field_cm_movie_tags',
      7 => 'field_event_corresponding_ref',
      8 => 'field_movie_corresponding_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-private field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_private|node|cm_movie|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Private Field');

  return $field_groups;
}
