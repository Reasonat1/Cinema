<?php
/**
 * @file
 * cinematheque_feature_movie_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_movie_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events_by_movie';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'events by movie';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_toptix_purchase' => 'field_toptix_purchase',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_toptix_purchase' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Line up (field_cm_event_lineup) */
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
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

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_cm_event_lineup_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Line up (field_cm_event_lineup)',
    ),
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['events_by_movie'] = $view;

  $view = new view();
  $view->name = 'movie_top_pane_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Movie CT View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'איתחול';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_cm_movie_pictures' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_cm_movie_pictures' => 'field_cm_movie_pictures',
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_on_click'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['fixed_height'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_movie_pictures']['id'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['field'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_cm_movie_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_limit'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['multi_type'] = 'ol';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'הכל';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie' => 'cm_movie',
  );

  /* Display: Movie Slidshow */
  $handler = $view->new_display('panel_pane', 'Movie Slidshow', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'full-screen-image';
  $handler->display->display_options['display_description'] = 'Movie Slidshow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_movie_pictures']['id'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['field'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['text'] = '<div class="wrapper-image">[field_cm_movie_pictures]</div>';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['settings'] = array(
    'file_view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_cm_movie_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_limit'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['multi_type'] = 'ol';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="gradient"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Movie Head content Pane */
  $handler = $view->new_display('panel_pane', 'Movie Head content Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_lobby_target_id']['id'] = 'field_lobby_target_id';
  $handler->display->display_options['relationships']['field_lobby_target_id']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['relationships']['field_lobby_target_id']['field'] = 'field_lobby_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['label'] = '';
  $handler->display->display_options['fields']['field_lobby']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lobby']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Country origin */
  $handler->display->display_options['fields']['field_cm_movie_country']['id'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['field'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_country']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_country']['delta_offset'] = '0';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = '[field_cm_movie_duration-interval] minutes';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Trailers */
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['id'] = 'field_cm_movie_videos_1';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['table'] = 'field_data_field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['field'] = 'field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['alter']['text'] = '<div class="play-button"></div>
<div class="video-wrapper">
<div class="close-button"></div>
[field_cm_movie_videos_1]
</div>';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['settings'] = array(
    'file_view_mode' => 'default',
    'field_multiple_limit' => '1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_videos_1']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$node = node_load($data->nid);
if(!empty($node->field_cm_movie_videos[\'und\'])){
    $filetype = $node->field_cm_movie_videos[\'und\'][0][\'filemime\'];
    if($filetype == \'video/mp4\'){
        $path_mp4 = file_create_url($node->field_cm_movie_videos[\'und\'][0][\'uri\']);
        print \'<a class="lightboxed" href="\'.$path_mp4.\'">\'.\'Play Video\'.\'</a>\';   
    }
    if($filetype == \'video/youtube\'){
        $path_tube = file_create_url($node->field_cm_movie_videos[\'und\'][0][\'uri\']);
        $sort = \'http://www.youtube.com/v/\'.substr($path_tube, 31);
        $new_path = $sort.\'?fs=1&amp;width=540&amp;height=440;autoplay=1&amp;hl=en_US1&amp;iframe=true&amp;rel=0\';
        print \'<a class="colorbox-load" href="\'.$new_path.\'">\'.\'Play Video\'.\'</a>\';
    }
    if($filetype == \'video/vimeo\'){
        $path_vimeo = file_create_url($node->field_cm_movie_videos[\'und\'][0][\'uri\']);
        $sort_vimeo = \'http://player.vimeo.com/video/\'.substr($path_vimeo, 17);
        $new_path_vimeo = $sort_vimeo.\'?fs=1&amp;width=540&amp;height=440;autoplay=1&amp;hl=en_US1&amp;iframe=true&amp;rel=0"\';
        print \'<a class="colorbox-load" href="\'.$new_path_vimeo.\'">\'.\'Play Video\'.\'</a>\';
    }
}
?>
<script>
    jQuery(\'a.lightboxed\').colorbox({iframe:true, width:"540px", height:"440px"});
</script>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['text'] = '[field_cm_movie_meta_credit] |';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['empty'] = '<div class="hide-div-credit"></div>';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['hide_empty'] = TRUE;
  /* Field: Taxonomy term: Active category dates */
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['id'] = 'field_cm_lobby_active_date';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['table'] = 'field_data_field_cm_lobby_active_date';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['field'] = 'field_cm_lobby_active_date';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['relationship'] = 'field_lobby_target_id';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['label'] = '';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_cm_lobby_active_date';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'DATE_STAMP';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[field_lobby]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Lobby list */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Lobby list';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$taxonomy_array=array();
foreach ($data->field_field_lobby as $key => $tid_value) {
	$date=strtotime(taxonomy_term_load($tid_value[\'raw\'][\'target_id\'])->field_cm_lobby_active_date[\'und\'][0][\'value2\']);
	if ($date>time()) $taxonomy_array[]=$tid_value[\'rendered\'][\'#markup\'];
	
}
print (implode(", ",$taxonomy_array));
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="slide-over-content text-main-image">
   <div class="wrapper">
    <div class="slide-right-ct">
[field_cm_movie_videos_1]
    </div>
    <div class="slide-left-ct">
        <div class="slide-eve-lobby slide-small-text">[php_1]</div>
        <div class="slide-movie-title slide-big-text">[title]</div>
        <div class="slide-movie-year slide-small-text"><span class="crdt">[field_cm_movie_meta_credit] </span><span class="mnts">[field_cm_movie_duration]</span></div>
    </div>
    <div class="ctr"></div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Movie CT Body Content */
  $handler = $view->new_display('panel_pane', 'Movie CT Body Content', 'panel_pane_4');
  $handler->display->display_options['display_description'] = 'Movie CT Body Content';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'movie-title-heder';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['text'] = '[field_cm_movie_meta_credit] |';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['element_label_colon'] = FALSE;
  /* Field: Content: Country origin */
  $handler->display->display_options['fields']['field_cm_movie_country']['id'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['field'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_country']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_country']['delta_offset'] = '0';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['alter']['text'] = '[field_cm_movie_year]  | ';
  $handler->display->display_options['fields']['field_cm_movie_year']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = ' [field_cm_movie_duration-interval] minutes |';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['text'] = '[field_cm_movie_language] | ';
  $handler->display->display_options['fields']['field_cm_movie_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['empty'] = '<span class="hide-div-movie"></span>';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_limit'] = 'All';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_cm_movie_country] [field_cm_movie_year][field_cm_movie_duration] [field_cm_movie_language]<span class="sub-title"> | [field_cm_movie_subtitle] subtitles </span>  ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Long summary */
  $handler->display->display_options['fields']['field_cm_movie_body']['id'] = 'field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['table'] = 'field_data_field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['field'] = 'field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_body']['element_label_colon'] = FALSE;

  /* Display: Movie Trailers */
  $handler = $view->new_display('panel_pane', 'Movie Trailers', 'panel_pane_5');
  $handler->display->display_options['display_description'] = 'Movie Trailers';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Trailers */
  $handler->display->display_options['fields']['field_cm_movie_videos']['id'] = 'field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos']['table'] = 'field_data_field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos']['field'] = 'field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_videos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_videos']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_videos']['type'] = 'media_colorbox';
  $handler->display->display_options['fields']['field_cm_movie_videos']['settings'] = array(
    'file_view_mode' => 'default',
    'colorbox_view_mode' => 'default',
    'fixed_width' => '150',
    'fixed_height' => '150',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'title',
    'audio_playlist' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_videos']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Similar By Terms: Nid */
  $handler->display->display_options['arguments']['similar_nid']['id'] = 'similar_nid';
  $handler->display->display_options['arguments']['similar_nid']['table'] = 'node';
  $handler->display->display_options['arguments']['similar_nid']['field'] = 'similar_nid';
  $handler->display->display_options['arguments']['similar_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['similar_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['similar_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['similar_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['similar_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['similar_nid']['vocabularies'] = array(
    'tags' => 'tags',
    'film_status' => 'film_status',
    'movie_key_status' => 'movie_key_status',
    'panopoly_categories' => 0,
    'year' => 0,
    'country_origin' => 0,
    'languages' => 0,
    'screening_format' => 0,
    'profession' => 0,
    'technical_formats' => 0,
    'genre' => 0,
    'events_categories' => 0,
    'status' => 0,
    'countries' => 0,
    'festival' => 0,
    'lobby' => 0,
  );
  $handler->display->display_options['arguments']['similar_nid']['include_args'] = 0;

  /* Display: Movie terms referenced */
  $handler = $view->new_display('panel_pane', 'Movie terms referenced', 'panel_pane_6');
  $handler->display->display_options['display_description'] = 'Movie terms referenced';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'ul';
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'panopoly_categories' => 0,
    'country_origin' => 0,
    'events_categories' => 0,
    'festival' => 0,
    'film_status' => 0,
    'genre' => 0,
    'hall' => 0,
    'information_blocks' => 0,
    'languages' => 0,
    'lobby' => 0,
    'media_folders' => 0,
    'movie_key_status' => 0,
    'person_type' => 0,
    'profession' => 0,
    'status' => 0,
    'supported_formats' => 0,
    'supported_tech_formats' => 0,
    'tags' => 0,
    'year' => 0,
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['allow']['panopoly_magic_display_type'] = 0;

  /* Display: Movie Upcoming Event */
  $handler = $view->new_display('panel_pane', 'Movie Upcoming Event', 'panel_pane_7');
  $handler->display->display_options['display_description'] = 'Movie Upcoming Event';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_cm_event_time' => 'field_cm_event_time',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_time' => array(
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<?php
$view = views_get_current_view();
 $page_total = count($view->result);
if($page_total >3){
print \'<div class="wrapper-more"><div class="more-event"><span class="only-mobile">  -  </span><span class="text text-open">\'. t(\'More Screenings\'). \'</span><span class="text text-close">\'. t(\'Less Screenings\'). \'</span><span class="only-mobile">  -  </span></div></div>\';
}
?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id_1']['id'] = 'field_cm_event_lineup_target_id_1';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id_1']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id_1']['field'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_2']['id'] = 'field_cm_event_time_2';
  $handler->display->display_options['fields']['field_cm_event_time_2']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_2']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_3']['id'] = 'field_cm_event_time_3';
  $handler->display->display_options['fields']['field_cm_event_time_3']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_3']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_3']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_3']['alter']['text'] = '[field_cm_event_time_3]</br>
[field_cm_event_time_2]';
  $handler->display->display_options['fields']['field_cm_event_time_3']['element_class'] = 'only-mobile';
  $handler->display->display_options['fields']['field_cm_event_time_3']['element_label_class'] = 'only-mobile';
  $handler->display->display_options['fields']['field_cm_event_time_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_3']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_4']['id'] = 'field_cm_event_time_4';
  $handler->display->display_options['fields']['field_cm_event_time_4']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_4']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_4']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_4']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'Date';
  $handler->display->display_options['fields']['field_cm_event_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['alter']['text'] = '<span class="day-same-width">[field_cm_event_time]</span> | [field_cm_event_time_4]';
  $handler->display->display_options['fields']['field_cm_event_time']['element_class'] = 'only-desktop date';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_time']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'only_day',
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
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = 'Time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_class'] = 'only-desktop time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_time_1']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_time_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['id'] = 'field_cm_event_internal_id_1';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['element_label_colon'] = FALSE;
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['text'] = '[field_cm_event_hall]
<div class="only-mobile">[field_cm_event_internal_id_1]</div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['element_class'] = 'hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Event';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['title_1']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['title_1']['hide_empty'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Screening table remarks */
  $handler->display->display_options['fields']['field_cm_event_comment']['id'] = 'field_cm_event_comment';
  $handler->display->display_options['fields']['field_cm_event_comment']['table'] = 'field_data_field_cm_event_comment';
  $handler->display->display_options['fields']['field_cm_event_comment']['field'] = 'field_cm_event_comment';
  $handler->display->display_options['fields']['field_cm_event_comment']['label'] = 'Event';
  $handler->display->display_options['fields']['field_cm_event_comment']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_comment']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_cm_event_comment']['element_class'] = 'only-desktop title';
  $handler->display->display_options['fields']['field_cm_event_comment']['element_label_colon'] = FALSE;
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['label'] = 'Code';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_class'] = 'only-desktop code';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['hide_empty'] = TRUE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_class'] = 'only-desktop like-flag';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_class'] = 'only-desktop add-event';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$node = node_load($row->nid);
print _return_addthisevent_markup($node);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = '';
  $handler->display->display_options['fields']['field_toptix_purchase']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_toptix_purchase']['element_class'] = 'purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_toptix_purchase']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_toptix_purchase']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Tickets sold out */
  $handler->display->display_options['fields']['field_tickets_sold_out']['id'] = 'field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['table'] = 'field_data_field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['field'] = 'field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['label'] = 'Tickets';
  $handler->display->display_options['fields']['field_tickets_sold_out']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['alter']['text'] = '<div class="sold-out">Sold out</div>';
  $handler->display->display_options['fields']['field_tickets_sold_out']['empty'] = '[field_toptix_purchase]';
  $handler->display->display_options['fields']['field_tickets_sold_out']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['type'] = 'list_key';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['sorts']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Line up (field_cm_event_lineup) */
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cm_event_lineup_target_id']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['type']['relationship'] = 'field_cm_event_lineup_target_id_1';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie' => 'cm_movie',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['filters']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_cm_event_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_cm_event_time_value']['default_date'] = 'now';

  /* Display: Movie favorite links */
  $handler = $view->new_display('panel_pane', 'Movie favorite links', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Movie favorite links';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  $export['movie_top_pane_view'] = $view;

  $view = new view();
  $view->name = 'test_view_for_movie_credit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Movie Credit View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Movie Credits (field_cm_movie_credits) */
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['id'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['table'] = 'field_data_field_cm_movie_credits';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['field'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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

  /* Display: Movie CT for Credit Part */
  $handler = $view->new_display('panel_pane', 'Movie CT for Credit Part', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'credits-view';
  $handler->display->display_options['display_description'] = 'Movie CT for Credit Part';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php 
global $base_url;
if($results[0]->node_node_language==\'he\'){
     $trans_node=node_load($results[0]->nid)->tnid;
     $trans = translation_node_get_translations($trans_node);
if(!empty($trans)){
       $title = $trans[\'en\']->title;  
       $path = drupal_get_path_alias(\'node/\'.$trans_node, \'en\');	   
        print \'<div class="translated-movie-title">\'. t(\'Movie title\'). \':  \';
        print \'<a href="\'.$base_url.\'/en/\'.$path.\'">\'.  $title .\'</a>\';
        print \'</div>\';
    }   
} else {
	$original_node=node_load($results[0]->nid);
	$original_title_id = field_get_items(\'node\', $original_node, \'field_original_title\');
	if(isset($original_title_id[0])){$original_title = field_view_value(\'node\', $original_node, \'field_original_title\', $original_title_id[0])[\'#markup\'];
	print \'<div class="translated-movie-title">\'. t(\'Original title\'). \':  \';
	print \'<span class="field-content original-title">\'.$original_title.\'</span>\';
	print \'</div>\';}
}
?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Movie Credits (field_cm_movie_credits) */
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['id'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['table'] = 'field_data_field_cm_movie_credits';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['field'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['id'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['table'] = 'field_data_field_cm_movie_credits_person';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['field'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['relationship'] = 'field_cm_movie_credits_value';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['id'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['text'] = '[field_cm_movie_credits_person_ro]:';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_class'] = 'profession';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['id'] = 'field_cm_movie_credits_person_ro_1';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$node = node_load($row->nid_1);
$trans = translation_node_get_translations($node->tnid);
if(!empty($trans)){
      if($node->language == \'he\')  {
        $title = $trans[\'en\']->title;  
       $path = drupal_get_path_alias(\'/en/node/\'.$node->tnid);  
        print \'<div class="translated-movie-title">\'. t(\'Movie title\'). \':  \';
        print \'<a href="\'.$path.\'">\'.  $title .\'</a>\';
       print \'</div>\';
    }   
} 
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'translation';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Person */
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['id'] = 'field_cm_movie_credits_person';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['table'] = 'field_data_field_cm_movie_credits_person';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['field'] = 'field_cm_movie_credits_person';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_cm_person_first_name']['id'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['table'] = 'field_data_field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['field'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_cm_person_last_name']['id'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['table'] = 'field_data_field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['field'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['text'] = '[field_cm_person_first_name] [field_cm_person_last_name]';
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_cm_person_last_name']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[title]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_cm_person_last_name]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'cm_movie' => 'cm_movie',
  );
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'field_cm_movie_credits_person_ro' => array(
      'merge_option' => 'filter',
      'separator' => '<br />',
    ),
    'field_cm_movie_credits_person' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_movie_credits_person_ro_1' => array(
      'merge_option' => 'first_value',
      'separator' => ', ',
    ),
  );

  /* Display: Event CT for Credit Part */
  $handler = $view->new_display('panel_pane', 'Event CT for Credit Part', 'panel_pane_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'credit-view';
  $handler->display->display_options['display_description'] = 'Event CT for Credit Part';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Content: Movie Credits (field_cm_movie_credits) */
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['id'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['table'] = 'field_data_field_cm_movie_credits';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['field'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_cm_movie_credits_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['id'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['table'] = 'field_data_field_cm_movie_credits_person';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['field'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_target_id']['relationship'] = 'field_cm_movie_credits_value';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['relationships']['translation']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['id'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['text'] = '[field_cm_movie_credits_person_ro]:';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_class'] = 'profession';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['id'] = 'field_cm_movie_credits_person_ro_1';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Person */
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['id'] = 'field_cm_movie_credits_person';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['table'] = 'field_data_field_cm_movie_credits_person';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['field'] = 'field_cm_movie_credits_person';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_cm_person_first_name']['id'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['table'] = 'field_data_field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['field'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_person_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_cm_person_last_name']['id'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['table'] = 'field_data_field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['field'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_person_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['text'] = '[field_cm_person_first_name] [field_cm_person_last_name]';
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_cm_person_last_name']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '5';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[title]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_cm_person_last_name]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Line up */
  $handler->display->display_options['fields']['field_cm_event_lineup']['id'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['field'] = 'field_cm_event_lineup';
  $handler->display->display_options['fields']['field_cm_event_lineup']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_event_lineup']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_lineup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_lineup']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_cm_event_lineup']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_event_lineup']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'field_cm_movie_credits_person_ro' => array(
      'merge_option' => 'filter',
      'separator' => '<br />',
    ),
    'field_cm_movie_credits_person' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_movie_credits_person_ro_1' => array(
      'merge_option' => 'first_value',
      'separator' => ', ',
    ),
  );
  $export['test_view_for_movie_credit'] = $view;

  return $export;
}
