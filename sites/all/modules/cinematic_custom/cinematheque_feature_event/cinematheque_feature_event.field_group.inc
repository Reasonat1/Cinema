<?php
/**
 * @file
 * cinematheque_feature_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cinematheque_feature_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|cm_event|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_items';
  $field_group->data = array(
    'label' => 'Event content',
    'weight' => '47',
    'children' => array(
      0 => 'field_cm_event_body',
      1 => 'field_cm_event_format',
      2 => 'field_cm_event_short_description',
      3 => 'field_cm_event_comment',
      4 => 'field_main_event_credit',
      5 => 'field_event_top_text_black',
      6 => 'field_event_top_text_white',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|cm_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|cm_event|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_items';
  $field_group->data = array(
    'label' => 'Event details',
    'weight' => '46',
    'children' => array(
      0 => 'field_cm_event_short_title',
      1 => 'field_cm_event_subtitle',
      2 => 'field_cm_event_time',
      3 => 'field_cm_event_onsale',
      4 => 'field_cm_event_internal_id',
      5 => 'field_cm_event_status',
      6 => 'field_cm_event_movie_status',
      7 => 'field_cm_event_movie_key_status',
      8 => 'field_cm_event_duration',
      9 => 'field_homepage_extra_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_details|node|cm_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_items|node|cm_event|form';
  $field_group->group_name = 'group_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Items',
    'weight' => '3',
    'children' => array(
      0 => 'group_details',
      1 => 'group_toptix',
      2 => 'group_content',
      3 => 'group_other',
      4 => 'group_references',
      5 => 'group_media',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-items field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_items|node|cm_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|cm_event|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_items';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '49',
    'children' => array(
      0 => 'field_cm_event_images',
      1 => 'field_cm_event_files',
      2 => 'field_low_and_wide_for_home_page',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_media|node|cm_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|cm_event|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_items';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '51',
    'children' => array(
      0 => 'field_cm_event_tech_comment',
      1 => 'field_cm_event_hide_calendar',
      2 => 'cer_store_settings',
      3 => 'field_search_additions',
      4 => 'domain',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-other field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_other|node|cm_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_references|node|cm_event|form';
  $field_group->group_name = 'group_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_items';
  $field_group->data = array(
    'label' => 'References',
    'weight' => '48',
    'children' => array(
      0 => 'field_cm_event_lineup',
      1 => 'field_cm_event_category',
      2 => 'field_cm_event_hall',
      3 => 'field_tag',
      4 => 'cer_settings',
      5 => 'field_lobby',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-references field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_references|node|cm_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_toptix|node|cm_event|form';
  $field_group->group_name = 'group_toptix';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cm_event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_items';
  $field_group->data = array(
    'label' => 'Toptix',
    'weight' => '50',
    'children' => array(
      0 => 'field_include_ticket_sale',
      1 => 'field_toptix_purchase',
      2 => 'field_tickets_sold_out',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-toptix field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_toptix|node|cm_event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Event content');
  t('Event details');
  t('Items');
  t('Media');
  t('Other');
  t('References');
  t('Toptix');

  return $field_groups;
}
