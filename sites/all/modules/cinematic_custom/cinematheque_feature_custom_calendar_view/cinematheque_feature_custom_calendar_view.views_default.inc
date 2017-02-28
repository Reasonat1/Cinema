<?php
/**
 * @file
 * cinematheque_feature_custom_calendar_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_custom_calendar_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'custom_calendar_floating_pane';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Custom Calendar Floating Pane';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '-1';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cm_event_time']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['delta_offset'] = '0';
  /* Sort criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['sorts']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Floating agenda pane */
  $handler = $view->new_display('panel_pane', 'Floating agenda pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Floating agenda pane';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No events.';
  $handler->display->display_options['empty']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_cm_event_time']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = '';
  $handler->display->display_options['fields']['field_toptix_purchase']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['arguments']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_cm_event_time_value']['granularity_reset'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_event' => 'cm_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;

  /* Display: Floating agenda Calendar Block */
  $handler = $view->new_display('block', 'Floating agenda Calendar Block', 'block_1');
  $handler->display->display_options['display_description'] = 'Floating agenda Calendar Block';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '0';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_cm_event_time']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['delta_offset'] = '0';
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = '';
  $handler->display->display_options['fields']['field_toptix_purchase']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_toptix_purchase']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Event Date */
  $handler->display->display_options['fields']['field_cm_event_time_1']['id'] = 'field_cm_event_time_1';
  $handler->display->display_options['fields']['field_cm_event_time_1']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['ui_name'] = 'Event Date';
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'raw time hence',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_cm_event_time_1';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '2';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = '0 sec';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[field_toptix_purchase]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Short Title */
  $handler->display->display_options['fields']['field_cm_event_short_title']['id'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['table'] = 'field_data_field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['field'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_short_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_cm_event_short_title']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_cm_event_short_title]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[title] ';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['date_argument']['use_fromto'] = 'no';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cm_event_time.field_cm_event_time_value' => 'field_data_field_cm_event_time.field_cm_event_time_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_event' => 'cm_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $export['custom_calendar_floating_pane'] = $view;

  return $export;
}
