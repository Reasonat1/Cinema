<?php
/**
 * @file
 * cinematheque_feature_meneger_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_meneger_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_management_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event Management page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Management page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Line up */
  $handler->display->display_options['fields']['field_cm_event_lineup']['id'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['field'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_cm_event_lineup']['delta_offset'] = '0';
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'Event date';
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_1']['id'] = 'field_cm_event_time_1';
  $handler->display->display_options['fields']['field_cm_event_time_1']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = 'Starts at';
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'custom_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_2']['id'] = 'field_cm_event_time_2';
  $handler->display->display_options['fields']['field_cm_event_time_2']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['label'] = 'Ends at';
  $handler->display->display_options['fields']['field_cm_event_time_2']['settings'] = array(
    'format_type' => 'custom_time',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Line up */
  $handler->display->display_options['fields']['field_cm_event_lineup']['id'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['field'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_cm_event_lineup']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_event_lineup']['multi_type'] = 'ul';
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Event Duration */
  $handler->display->display_options['fields']['field_cm_event_duration']['id'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['table'] = 'field_data_field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['field'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Selected Screening Format */
  $handler->display->display_options['fields']['field_cm_event_format']['id'] = 'field_cm_event_format';
  $handler->display->display_options['fields']['field_cm_event_format']['table'] = 'field_data_field_cm_event_format';
  $handler->display->display_options['fields']['field_cm_event_format']['field'] = 'field_cm_event_format';
  $handler->display->display_options['fields']['field_cm_event_format']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: technical comments */
  $handler->display->display_options['fields']['field_cm_event_tech_comment']['id'] = 'field_cm_event_tech_comment';
  $handler->display->display_options['fields']['field_cm_event_tech_comment']['table'] = 'field_data_field_cm_event_tech_comment';
  $handler->display->display_options['fields']['field_cm_event_tech_comment']['field'] = 'field_cm_event_tech_comment';
  $handler->display->display_options['fields']['field_cm_event_tech_comment']['delta_offset'] = '0';
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['path'] = 'admin/dashboard/content/events';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Events management';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['event_management_page'] = $view;

  $view = new view();
  $view->name = 'events_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'events manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events manager';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'views_bulk_operations' => 'views_bulk_operations',
    'language' => 'language',
    'field_cm_event_images' => 'field_cm_event_images',
    'title' => 'title',
    'created' => 'created',
    'field_cm_event_time' => 'field_cm_event_time',
    'field_cm_movie_duration' => 'field_cm_movie_duration',
    'field_cm_event_duration' => 'field_cm_event_duration',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_files' => 'field_cm_event_files',
    'field_lobby' => 'field_lobby',
    'field_cm_event_lineup' => 'field_cm_event_lineup',
    'popup' => 'popup',
    'field_cm_event_files_1' => 'field_cm_event_files_1',
    'status' => 'status',
    'changed' => 'changed',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
    'translate_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_hall' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_files' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_lineup' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'popup' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_files_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'translate_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'cm_event::field_cm_event_lineup' => 'cm_event::field_cm_event_lineup',
          'cm_event::field_tag' => 'cm_event::field_tag',
          'cm_event::field_lobby' => 'cm_event::field_lobby',
        ),
      ),
    ),
  );
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Images & Teasers */
  $handler->display->display_options['fields']['field_cm_event_images']['id'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['table'] = 'field_data_field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['field'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['label'] = 'Image';
  $handler->display->display_options['fields']['field_cm_event_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_images']['settings'] = array(
    'image_style' => 'panopoly_image_thumbnail',
    'image_link' => '',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_event_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'only_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'short_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Event Duration */
  $handler->display->display_options['fields']['field_cm_event_duration']['id'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['table'] = 'field_data_field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['field'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['label'] = 'Duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Hidden files */
  $handler->display->display_options['fields']['field_cm_event_files']['id'] = 'field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files']['table'] = 'field_data_field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files']['field'] = 'field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_files']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_files']['delta_offset'] = '0';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Line up */
  $handler->display->display_options['fields']['field_cm_event_lineup']['id'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['field'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_lineup']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_lineup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_lineup']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_cm_event_lineup']['settings'] = array(
    'view_mode' => 'manager',
    'links' => 1,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_lineup']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_event_lineup']['separator'] = '</br>';
  /* Field: Global: Popup */
  $handler->display->display_options['fields']['popup']['id'] = 'popup';
  $handler->display->display_options['fields']['popup']['table'] = 'popup_views_integration';
  $handler->display->display_options['fields']['popup']['field'] = 'popup';
  $handler->display->display_options['fields']['popup']['label'] = 'Line Up';
  $handler->display->display_options['fields']['popup']['title'] = 'Line up ';
  $handler->display->display_options['fields']['popup']['text'] = '[field_cm_event_lineup]';
  $handler->display->display_options['fields']['popup']['close'] = 1;
  $handler->display->display_options['fields']['popup']['origin'] = 'bottom-left';
  $handler->display->display_options['fields']['popup']['expand'] = 'bottom-left';
  $handler->display->display_options['fields']['popup']['width'] = '300';
  $handler->display->display_options['fields']['popup']['style'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'only_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Manage';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Lobby (field_lobby) (selective) */
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['id'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['field'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['ui_name'] = 'Lobby (field_lobby) (selective)';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['label'] = 'Lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['identifier'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['selective_display_field'] = 'field_lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Hall (field_cm_event_hall) (selective) */
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['id'] = 'field_cm_event_hall_target_id_selective';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['field'] = 'field_cm_event_hall_target_id_selective';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['ui_name'] = 'Hall (field_cm_event_hall) (selective)';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['expose']['label'] = 'Hall';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['expose']['identifier'] = 'field_cm_event_hall_target_id_selective';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['selective_display_field'] = 'field_cm_event_hall';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Movie name at the Line up';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title_1']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['filters']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cm_event_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_event_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['operator_id'] = 'field_cm_event_time_value_op';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['label'] = 'Time of Event -  start date - from';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['operator'] = 'field_cm_event_time_value_op';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['identifier'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_event_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['id'] = 'field_cm_event_time_value_1';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['expose']['operator_id'] = 'field_cm_event_time_value_1_op';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['expose']['label'] = 'Time of Event -  start date - to';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['expose']['operator'] = 'field_cm_event_time_value_1_op';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['expose']['identifier'] = 'field_cm_event_time_value_1';
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_event_time_value_1']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Tickets sold out (field_tickets_sold_out) */
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['id'] = 'field_tickets_sold_out_value';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['table'] = 'field_data_field_tickets_sold_out';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['field'] = 'field_tickets_sold_out_value';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['group'] = 1;
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['expose']['operator_id'] = 'field_tickets_sold_out_value_op';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['expose']['label'] = 'Tickets sold out';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['expose']['operator'] = 'field_tickets_sold_out_value_op';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['expose']['identifier'] = 'field_tickets_sold_out_value';
  $handler->display->display_options['filters']['field_tickets_sold_out_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'cm_event::field_cm_event_lineup' => 'cm_event::field_cm_event_lineup',
          'cm_event::field_tag' => 'cm_event::field_tag',
          'cm_event::field_lobby' => 'cm_event::field_lobby',
        ),
      ),
    ),
  );
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Images & Teasers */
  $handler->display->display_options['fields']['field_cm_event_images']['id'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['table'] = 'field_data_field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['field'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['label'] = 'Image';
  $handler->display->display_options['fields']['field_cm_event_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_images']['settings'] = array(
    'image_style' => 'panopoly_image_thumbnail',
    'image_link' => '',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_event_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'only_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'date_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Event Duration */
  $handler->display->display_options['fields']['field_cm_event_duration']['id'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['table'] = 'field_data_field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['field'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['label'] = 'Duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['empty'] = '[field_cm_movie_duration]';
  $handler->display->display_options['fields']['field_cm_event_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Hidden files */
  $handler->display->display_options['fields']['field_cm_event_files']['id'] = 'field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files']['table'] = 'field_data_field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files']['field'] = 'field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_files']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_files']['delta_offset'] = '0';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Line up */
  $handler->display->display_options['fields']['field_cm_event_lineup']['id'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['field'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_lineup']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_lineup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_lineup']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_cm_event_lineup']['settings'] = array(
    'view_mode' => 'manager',
    'links' => 1,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_lineup']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_event_lineup']['separator'] = '</br>';
  /* Field: Global: Popup */
  $handler->display->display_options['fields']['popup']['id'] = 'popup';
  $handler->display->display_options['fields']['popup']['table'] = 'popup_views_integration';
  $handler->display->display_options['fields']['popup']['field'] = 'popup';
  $handler->display->display_options['fields']['popup']['label'] = 'Line Up';
  $handler->display->display_options['fields']['popup']['title'] = 'Line up ';
  $handler->display->display_options['fields']['popup']['text'] = '[field_cm_event_lineup]';
  $handler->display->display_options['fields']['popup']['close'] = 1;
  $handler->display->display_options['fields']['popup']['origin'] = 'bottom-left';
  $handler->display->display_options['fields']['popup']['expand'] = 'bottom-left';
  $handler->display->display_options['fields']['popup']['width'] = '300';
  $handler->display->display_options['fields']['popup']['style'] = '0';
  /* Field: Content: Tickets sold out */
  $handler->display->display_options['fields']['field_tickets_sold_out']['id'] = 'field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['table'] = 'field_data_field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['field'] = 'field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['alter']['text'] = '✔';
  $handler->display->display_options['fields']['field_tickets_sold_out']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['type'] = 'list_key';
  /* Field: Content: Hidden files */
  $handler->display->display_options['fields']['field_cm_event_files_1']['id'] = 'field_cm_event_files_1';
  $handler->display->display_options['fields']['field_cm_event_files_1']['table'] = 'field_data_field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files_1']['field'] = 'field_cm_event_files';
  $handler->display->display_options['fields']['field_cm_event_files_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_files_1']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_files_1']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'only_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Manage';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content translation: Translate link */
  $handler->display->display_options['fields']['translate_node']['id'] = 'translate_node';
  $handler->display->display_options['fields']['translate_node']['table'] = 'node';
  $handler->display->display_options['fields']['translate_node']['field'] = 'translate_node';
  $handler->display->display_options['fields']['translate_node']['label'] = '';
  $handler->display->display_options['fields']['translate_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['translate_node']['text'] = 'Translate';
  /* Field: Content translation: Translation set node ID */
  $handler->display->display_options['fields']['tnid']['id'] = 'tnid';
  $handler->display->display_options['fields']['tnid']['table'] = 'node';
  $handler->display->display_options['fields']['tnid']['field'] = 'tnid';
  $handler->display->display_options['fields']['tnid']['label'] = 'Translation';
  $handler->display->display_options['fields']['tnid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tnid']['alter']['text'] = '✔';
  $handler->display->display_options['fields']['tnid']['empty'] = '✖';
  $handler->display->display_options['fields']['tnid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['tnid']['empty_zero'] = TRUE;
  $handler->display->display_options['path'] = 'admin/events-manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['events_manager'] = $view;

  $view = new view();
  $view->name = 'manger_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'manger VIEWS';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'manger VIEWS';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Movie-group manger */
  $handler = $view->new_display('page', 'Movie-group manger', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Movie group manager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_cm_moviegroup_pictures' => 'field_cm_moviegroup_pictures',
    'title' => 'title',
    'language' => 'language',
    'field_lobby' => 'field_lobby',
    'field_cm_moviegroup_showid' => 'field_cm_moviegroup_showid',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_moviegroup_pictures' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_moviegroup_showid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['id'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['table'] = 'field_data_field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['field'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['settings'] = array(
    'image_style' => 'apps_logo_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_lobby']['multi_type'] = 'ul';
  /* Field: Content: Toptix Show ID */
  $handler->display->display_options['fields']['field_cm_moviegroup_showid']['id'] = 'field_cm_moviegroup_showid';
  $handler->display->display_options['fields']['field_cm_moviegroup_showid']['table'] = 'field_data_field_cm_moviegroup_showid';
  $handler->display->display_options['fields']['field_cm_moviegroup_showid']['field'] = 'field_cm_moviegroup_showid';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Managment';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie_group' => 'cm_movie_group',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Toptix Show ID (field_cm_moviegroup_showid) */
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['id'] = 'field_cm_moviegroup_showid_value';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['table'] = 'field_data_field_cm_moviegroup_showid';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['field'] = 'field_cm_moviegroup_showid_value';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['operator_id'] = 'field_cm_moviegroup_showid_value_op';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['label'] = 'Toptix Show ID';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['operator'] = 'field_cm_moviegroup_showid_value_op';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['identifier'] = 'field_cm_moviegroup_showid_value';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['autocomplete_field'] = 'field_cm_moviegroup_showid';
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_cm_moviegroup_showid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'admin/movie-group-manger';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Movie group mangment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manager-view';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Movie manger */
  $handler = $view->new_display('page', 'Movie manger', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Movie manager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_cm_movie_year' => 'field_cm_movie_year',
    'field_cm_movie_language' => 'field_cm_movie_language',
    'field_cm_movie_subtitle' => 'field_cm_movie_subtitle',
    'field_lobby' => 'field_lobby',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
    'status' => 'status',
    'language' => 'language',
    'field_cm_movie_showid' => 'field_cm_movie_showid',
    'field_cm_movie_internal_id' => 'field_cm_movie_internal_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_subtitle' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_showid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_internal_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = 'Movie Length';
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['label'] = 'Movie Language';
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_lobby']['multi_type'] = 'ul';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Managment';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'Webpage Language';
  /* Field: Content: Distributor */
  $handler->display->display_options['fields']['field_cm_movie_distributor']['id'] = 'field_cm_movie_distributor';
  $handler->display->display_options['fields']['field_cm_movie_distributor']['table'] = 'field_data_field_cm_movie_distributor';
  $handler->display->display_options['fields']['field_cm_movie_distributor']['field'] = 'field_cm_movie_distributor';
  $handler->display->display_options['fields']['field_cm_movie_distributor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_distributor']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_movie_distributor']['multi_type'] = 'ul';
  /* Field: Content: Topix Show ID */
  $handler->display->display_options['fields']['field_cm_movie_showid']['id'] = 'field_cm_movie_showid';
  $handler->display->display_options['fields']['field_cm_movie_showid']['table'] = 'field_data_field_cm_movie_showid';
  $handler->display->display_options['fields']['field_cm_movie_showid']['field'] = 'field_cm_movie_showid';
  /* Field: Content: Cinematheque Movie ID */
  $handler->display->display_options['fields']['field_cm_movie_internal_id']['id'] = 'field_cm_movie_internal_id';
  $handler->display->display_options['fields']['field_cm_movie_internal_id']['table'] = 'field_data_field_cm_movie_internal_id';
  $handler->display->display_options['fields']['field_cm_movie_internal_id']['field'] = 'field_cm_movie_internal_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie' => 'cm_movie',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Webpage Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Topix Show ID (field_cm_movie_showid) */
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['id'] = 'field_cm_movie_showid_value';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['table'] = 'field_data_field_cm_movie_showid';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['field'] = 'field_cm_movie_showid_value';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['operator_id'] = 'field_cm_movie_showid_value_op';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['label'] = 'Topix Show ID ';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['operator'] = 'field_cm_movie_showid_value_op';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['identifier'] = 'field_cm_movie_showid_value';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['autocomplete_field'] = 'field_cm_movie_showid';
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_showid_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Cinematheque Movie ID (field_cm_movie_internal_id) */
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['id'] = 'field_cm_movie_internal_id_value';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['table'] = 'field_data_field_cm_movie_internal_id';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['field'] = 'field_cm_movie_internal_id_value';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['operator_id'] = 'field_cm_movie_internal_id_value_op';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['label'] = 'Cinematheque Movie ID';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['operator'] = 'field_cm_movie_internal_id_value_op';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['identifier'] = 'field_cm_movie_internal_id_value';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['autocomplete_field'] = 'field_cm_movie_internal_id';
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_internal_id_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'admin/movie-manger';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Movie mangment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manager-view';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Event manger */
  $handler = $view->new_display('page', 'Event manger', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event manager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_cm_event_images' => 'field_cm_event_images',
    'title' => 'title',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_time' => 'field_cm_event_time',
    'field_lobby' => 'field_lobby',
    'field_cm_event_category' => 'field_cm_event_category',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
    'status' => 'status',
    'language' => 'language',
    'field_cm_event_internal_id' => 'field_cm_event_internal_id',
    'field_cm_event_onsale' => 'field_cm_event_onsale',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_hall' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_category' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_internal_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_onsale' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Images & Teasers */
  $handler->display->display_options['fields']['field_cm_event_images']['id'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['table'] = 'field_data_field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['field'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['label'] = 'Image';
  $handler->display->display_options['fields']['field_cm_event_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_images']['settings'] = array(
    'image_style' => 'apps_logo_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cm_event_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_event_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'Event date';
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'panopoly_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_lobby']['multi_type'] = 'ul';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_cm_event_category']['id'] = 'field_cm_event_category';
  $handler->display->display_options['fields']['field_cm_event_category']['table'] = 'field_data_field_cm_event_category';
  $handler->display->display_options['fields']['field_cm_event_category']['field'] = 'field_cm_event_category';
  $handler->display->display_options['fields']['field_cm_event_category']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Managment';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'Webpage Language';
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  /* Field: Content: Active event? */
  $handler->display->display_options['fields']['field_cm_event_onsale']['id'] = 'field_cm_event_onsale';
  $handler->display->display_options['fields']['field_cm_event_onsale']['table'] = 'field_data_field_cm_event_onsale';
  $handler->display->display_options['fields']['field_cm_event_onsale']['field'] = 'field_cm_event_onsale';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
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
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Webpage Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Hall (field_cm_event_hall) */
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['id'] = 'field_cm_event_hall_target_id';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['field'] = 'field_cm_event_hall_target_id';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['expose']['operator_id'] = 'field_cm_event_hall_target_id_op';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['expose']['label'] = 'Hall ';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['expose']['operator'] = 'field_cm_event_hall_target_id_op';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['expose']['identifier'] = 'field_cm_event_hall_target_id';
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_hall_target_id']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  /* Filter criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['filters']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['operator_id'] = 'field_cm_event_time_value_op';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['label'] = 'Time of Event -  start date';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['operator'] = 'field_cm_event_time_value_op';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['identifier'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_time_value']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_cm_event_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Time of Event - end date (field_cm_event_time:value2) */
  $handler->display->display_options['filters']['field_cm_event_time_value2']['id'] = 'field_cm_event_time_value2';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['field'] = 'field_cm_event_time_value2';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_time_value2']['expose']['operator_id'] = 'field_cm_event_time_value2_op';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['expose']['label'] = 'Time of Event - end date';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['expose']['operator'] = 'field_cm_event_time_value2_op';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['expose']['identifier'] = 'field_cm_event_time_value2';
  $handler->display->display_options['filters']['field_cm_event_time_value2']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_time_value2']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_cm_event_time_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Category (field_cm_event_category) */
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['id'] = 'field_cm_event_category_target_id';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['table'] = 'field_data_field_cm_event_category';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['field'] = 'field_cm_event_category_target_id';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['expose']['operator_id'] = 'field_cm_event_category_target_id_op';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['expose']['label'] = 'Category ';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['expose']['operator'] = 'field_cm_event_category_target_id_op';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['expose']['identifier'] = 'field_cm_event_category_target_id';
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_category_target_id']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  /* Filter criterion: Content: Active event? (field_cm_event_onsale) */
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['id'] = 'field_cm_event_onsale_value';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['table'] = 'field_data_field_cm_event_onsale';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['field'] = 'field_cm_event_onsale_value';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['expose']['operator_id'] = 'field_cm_event_onsale_value_op';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['expose']['label'] = 'Active event?';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['expose']['operator'] = 'field_cm_event_onsale_value_op';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['expose']['identifier'] = 'field_cm_event_onsale_value';
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_onsale_value']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  /* Filter criterion: Content: Cinematheque event ID (field_cm_event_internal_id) */
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['id'] = 'field_cm_event_internal_id_value';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['field'] = 'field_cm_event_internal_id_value';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['operator_id'] = 'field_cm_event_internal_id_value_op';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['label'] = 'Cinematheque event ID ';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['operator'] = 'field_cm_event_internal_id_value_op';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['identifier'] = 'field_cm_event_internal_id_value';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    4 => '4',
    5 => '5',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['autocomplete_field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_cm_event_internal_id_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'admin/event-manger';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Event mangment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manager-view';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Article manger */
  $handler = $view->new_display('page', 'Article manger', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Article manager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'name' => 'name',
    'created' => 'created',
    'field_lobby' => 'field_lobby',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
    'status' => 'status',
    'language' => 'language',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'panopoly_day';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Managment';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'Webpage Language';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_article' => 'cm_article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Webpage Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Author Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_field'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['name']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'admin/article-manger';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Article mangment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manager-view';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Person manger */
  $handler = $view->new_display('page', 'Person manger', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Person manager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_cm_person_type' => 'field_cm_person_type',
    'field_cm_person_job_title' => 'field_cm_person_job_title',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
    'status' => 'status',
    'language' => 'language',
    'field_cm_person_photo' => 'field_cm_person_photo',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_person_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_person_job_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_person_photo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_cm_person_photo']['id'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['table'] = 'field_data_field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['field'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_person_photo']['settings'] = array(
    'image_style' => 'apps_logo_small',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Profession */
  $handler->display->display_options['fields']['field_cm_person_type']['id'] = 'field_cm_person_type';
  $handler->display->display_options['fields']['field_cm_person_type']['table'] = 'field_data_field_cm_person_type';
  $handler->display->display_options['fields']['field_cm_person_type']['field'] = 'field_cm_person_type';
  $handler->display->display_options['fields']['field_cm_person_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Job title */
  $handler->display->display_options['fields']['field_cm_person_job_title']['id'] = 'field_cm_person_job_title';
  $handler->display->display_options['fields']['field_cm_person_job_title']['table'] = 'field_data_field_cm_person_job_title';
  $handler->display->display_options['fields']['field_cm_person_job_title']['field'] = 'field_cm_person_job_title';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Managment';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'Webpage Language';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_person' => 'cm_person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Webpage Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Profession (field_cm_person_type) */
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['id'] = 'field_cm_person_type_target_id';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['table'] = 'field_data_field_cm_person_type';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['field'] = 'field_cm_person_type_target_id';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['expose']['operator_id'] = 'field_cm_person_type_target_id_op';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['expose']['label'] = 'Profession';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['expose']['operator'] = 'field_cm_person_type_target_id_op';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['expose']['identifier'] = 'field_cm_person_type_target_id';
  $handler->display->display_options['filters']['field_cm_person_type_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Job title (field_cm_person_job_title) */
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['id'] = 'field_cm_person_job_title_value';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['table'] = 'field_data_field_cm_person_job_title';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['field'] = 'field_cm_person_job_title_value';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['operator_id'] = 'field_cm_person_job_title_value_op';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['label'] = 'Job title ';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['operator'] = 'field_cm_person_job_title_value_op';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['identifier'] = 'field_cm_person_job_title_value';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['autocomplete_field'] = 'field_cm_person_job_title';
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_cm_person_job_title_value']['expose']['autocomplete_dependent'] = 0;
  $handler->display->display_options['path'] = 'admin/person-manger';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Person mangment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manager-view';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['manger_views'] = $view;

  $view = new view();
  $view->name = 'movie_groups_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Movie groups manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Movie groups manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'language' => 'language',
    'field_cm_event_images' => 'field_cm_event_images',
    'title' => 'title',
    'created' => 'created',
    'field_cm_event_time' => 'field_cm_event_time',
    'field_cm_event_duration' => 'field_cm_event_duration',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_files' => 'field_cm_event_files',
    'field_lobby' => 'field_lobby',
    'field_cm_event_lineup' => 'field_cm_event_lineup',
    'status' => 'status',
    'changed' => 'changed',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_hall' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_files' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_lineup' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'cm_movie_group::field_cm_moviegroup_distributor' => 'cm_movie_group::field_cm_moviegroup_distributor',
          'cm_movie_group::field_cm_moviegroup_tags' => 'cm_movie_group::field_cm_moviegroup_tags',
          'cm_movie_group::field_lobby' => 'cm_movie_group::field_lobby',
          'cm_movie_group::field_movie_referenced' => 'cm_movie_group::field_movie_referenced',
        ),
      ),
    ),
  );
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['id'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['table'] = 'field_data_field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['field'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['label'] = 'Image';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['settings'] = array(
    'image_style' => 'panopoly_image_thumbnail',
    'image_link' => '',
    'field_multiple_limit' => '1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['id'] = 'field_cm_moviegroup_duration';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['table'] = 'field_data_field_cm_moviegroup_duration';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['field'] = 'field_cm_moviegroup_duration';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Movie Referenced */
  $handler->display->display_options['fields']['field_movie_referenced']['id'] = 'field_movie_referenced';
  $handler->display->display_options['fields']['field_movie_referenced']['table'] = 'field_data_field_movie_referenced';
  $handler->display->display_options['fields']['field_movie_referenced']['field'] = 'field_movie_referenced';
  $handler->display->display_options['fields']['field_movie_referenced']['label'] = '';
  $handler->display->display_options['fields']['field_movie_referenced']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_movie_referenced']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_movie_referenced']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_movie_referenced']['settings'] = array(
    'view_mode' => 'manager',
    'links' => 1,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_movie_referenced']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_movie_referenced']['separator'] = '</br>';
  /* Field: Global: Popup */
  $handler->display->display_options['fields']['popup']['id'] = 'popup';
  $handler->display->display_options['fields']['popup']['table'] = 'popup_views_integration';
  $handler->display->display_options['fields']['popup']['field'] = 'popup';
  $handler->display->display_options['fields']['popup']['label'] = 'Movie Referenced';
  $handler->display->display_options['fields']['popup']['title'] = 'Movies';
  $handler->display->display_options['fields']['popup']['text'] = '[field_movie_referenced]';
  $handler->display->display_options['fields']['popup']['close'] = 0;
  $handler->display->display_options['fields']['popup']['width'] = '300';
  $handler->display->display_options['fields']['popup']['style'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'only_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Manage';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie_group' => 'cm_movie_group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Lobby (field_lobby) (selective) */
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['id'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['field'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['ui_name'] = 'Lobby (field_lobby) (selective)';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['label'] = 'Lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['identifier'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['selective_display_field'] = 'field_lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Movie Referenced (field_movie_referenced) (selective) */
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['id'] = 'field_movie_referenced_target_id_selective';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['table'] = 'field_data_field_movie_referenced';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['field'] = 'field_movie_referenced_target_id_selective';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['ui_name'] = 'Movie Referenced (field_movie_referenced) (selective)';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['expose']['label'] = 'Movie Referenced';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['expose']['identifier'] = 'field_movie_referenced_target_id_selective';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['selective_display_field'] = 'field_movie_referenced';
  $handler->display->display_options['filters']['field_movie_referenced_target_id_selective']['selective_items_limit'] = '100';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/movies-groups-manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Movie groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['movie_groups_manager'] = $view;

  $view = new view();
  $view->name = 'movies_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Movies manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Movies manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'language' => 'language',
    'field_cm_event_images' => 'field_cm_event_images',
    'title' => 'title',
    'created' => 'created',
    'field_cm_event_time' => 'field_cm_event_time',
    'field_cm_event_duration' => 'field_cm_event_duration',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_files' => 'field_cm_event_files',
    'field_lobby' => 'field_lobby',
    'field_cm_event_lineup' => 'field_cm_event_lineup',
    'status' => 'status',
    'changed' => 'changed',
    'view_node' => 'view_node',
    'edit_node' => 'view_node',
    'delete_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_hall' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_files' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lobby' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_lineup' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '</br>',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'cm_event::field_cm_event_body' => 'cm_event::field_cm_event_body',
          'cm_movie::field_cm_movie_tags' => 'cm_movie::field_cm_movie_tags',
          'cm_movie::field_lobby' => 'cm_movie::field_lobby',
          'cm_movie::field_event_corresponding_ref' => 'cm_movie::field_event_corresponding_ref',
        ),
      ),
    ),
  );
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_movie_pictures']['id'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['field'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['label'] = 'Image';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['settings'] = array(
    'file_view_mode' => 'thubnail',
    'field_multiple_limit' => '1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title for indexing */
  $handler->display->display_options['fields']['field_title_for_indexing']['id'] = 'field_title_for_indexing';
  $handler->display->display_options['fields']['field_title_for_indexing']['table'] = 'field_data_field_title_for_indexing';
  $handler->display->display_options['fields']['field_title_for_indexing']['field'] = 'field_title_for_indexing';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Country origin */
  $handler->display->display_options['fields']['field_cm_movie_country']['id'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['field'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_country']['delta_offset'] = '0';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = 'Subs';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = 'leading';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby_1']['id'] = 'field_lobby_1';
  $handler->display->display_options['fields']['field_lobby_1']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby_1']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby_1']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_lobby_1']['delta_offset'] = '0';
  /* Field: Content: Event Corresponding Ref */
  $handler->display->display_options['fields']['field_event_corresponding_ref']['id'] = 'field_event_corresponding_ref';
  $handler->display->display_options['fields']['field_event_corresponding_ref']['table'] = 'field_data_field_event_corresponding_ref';
  $handler->display->display_options['fields']['field_event_corresponding_ref']['field'] = 'field_event_corresponding_ref';
  $handler->display->display_options['fields']['field_event_corresponding_ref']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_event_corresponding_ref']['settings'] = array(
    'view_mode' => 'manager',
    'links' => 1,
  );
  /* Field: Content: Movie Corresponding Ref */
  $handler->display->display_options['fields']['field_movie_corresponding_ref']['id'] = 'field_movie_corresponding_ref';
  $handler->display->display_options['fields']['field_movie_corresponding_ref']['table'] = 'field_data_field_movie_corresponding_ref';
  $handler->display->display_options['fields']['field_movie_corresponding_ref']['field'] = 'field_movie_corresponding_ref';
  $handler->display->display_options['fields']['field_movie_corresponding_ref']['settings'] = array(
    'link' => 1,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_movie_corresponding_ref']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'only_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Manage';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie' => 'cm_movie',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
    'he' => 'he',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Lobby (field_lobby) (selective) */
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['id'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['field'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['ui_name'] = 'Lobby (field_lobby) (selective)';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['label'] = 'Lobby';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['identifier'] = 'field_lobby_target_id_selective';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['selective_display_field'] = 'field_lobby_1';
  $handler->display->display_options['filters']['field_lobby_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Event Corresponding Ref (field_event_corresponding_ref) (selective) */
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['id'] = 'field_event_corresponding_ref_target_id_selective';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['table'] = 'field_data_field_event_corresponding_ref';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['field'] = 'field_event_corresponding_ref_target_id_selective';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['ui_name'] = 'Event Corresponding Ref (field_event_corresponding_ref) (selective)';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['expose']['label'] = 'Event Corresponding Ref';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['expose']['identifier'] = 'field_event_corresponding_ref_target_id_selective';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['selective_display_field'] = 'field_event_corresponding_ref';
  $handler->display->display_options['filters']['field_event_corresponding_ref_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Movie Corresponding Ref (field_movie_corresponding_ref) (selective) */
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['id'] = 'field_movie_corresponding_ref_target_id_selective';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['table'] = 'field_data_field_movie_corresponding_ref';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['field'] = 'field_movie_corresponding_ref_target_id_selective';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['ui_name'] = 'Movie Corresponding Ref (field_movie_corresponding_ref) (selective)';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['expose']['label'] = 'Movie Corresponding Ref';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['expose']['identifier'] = 'field_movie_corresponding_ref_target_id_selective';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['selective_display_field'] = 'field_movie_corresponding_ref';
  $handler->display->display_options['filters']['field_movie_corresponding_ref_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Year (field_cm_movie_year) (selective) */
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['id'] = 'field_cm_movie_year_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['field'] = 'field_cm_movie_year_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['ui_name'] = 'Year (field_cm_movie_year) (selective)';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['expose']['identifier'] = 'field_cm_movie_year_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['selective_display_field'] = 'field_cm_movie_year';
  $handler->display->display_options['filters']['field_cm_movie_year_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Country origin (field_cm_movie_country) (selective) */
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['id'] = 'field_cm_movie_country_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['field'] = 'field_cm_movie_country_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['ui_name'] = 'Country origin (field_cm_movie_country) (selective)';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['expose']['label'] = 'Country origin';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['expose']['identifier'] = 'field_cm_movie_country_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['selective_display_field'] = 'field_cm_movie_country';
  $handler->display->display_options['filters']['field_cm_movie_country_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Language (field_cm_movie_language) (selective) */
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['id'] = 'field_cm_movie_language_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['field'] = 'field_cm_movie_language_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['ui_name'] = 'Language (field_cm_movie_language) (selective)';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['expose']['identifier'] = 'field_cm_movie_language_target_id_selective';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['selective_display_field'] = 'field_cm_movie_language';
  $handler->display->display_options['filters']['field_cm_movie_language_target_id_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Title for indexing (field_title_for_indexing) */
  $handler->display->display_options['filters']['field_title_for_indexing_value']['id'] = 'field_title_for_indexing_value';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['table'] = 'field_data_field_title_for_indexing';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['field'] = 'field_title_for_indexing_value';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['operator_id'] = 'field_title_for_indexing_value_op';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['label'] = 'Title for indexing';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['operator'] = 'field_title_for_indexing_value_op';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['identifier'] = 'field_title_for_indexing_value';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['autocomplete_field'] = 'field_title_for_indexing';
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_title_for_indexing_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/movies-manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Movies';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['movies_manager'] = $view;

  return $export;
}
