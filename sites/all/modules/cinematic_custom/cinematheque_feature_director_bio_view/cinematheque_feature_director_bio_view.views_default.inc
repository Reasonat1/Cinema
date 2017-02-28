<?php
/**
 * @file
 * cinematheque_feature_director_bio_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_director_bio_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'director_bio';
  $view->description = 'Displays directors biography and details';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Director Bio';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_cm_person_photo' => 'field_cm_person_photo',
    'field_cm_person_address_name_line' => 'field_cm_person_address_name_line',
    'field_cm_person_body' => 'field_cm_person_body',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_ro_target_id']['id'] = 'field_cm_movie_credits_person_ro_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_ro_target_id']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_ro_target_id']['field'] = 'field_cm_movie_credits_person_ro_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_credits_person_ro_target_id']['relationship'] = 'field_cm_movie_credits_value';
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['id'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['text'] = '[field_cm_movie_credits_person_ro]:';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['settings'] = array(
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
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_cm_person_photo']['id'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['table'] = 'field_data_field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['field'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_person_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_cm_person_first_name']['id'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['table'] = 'field_data_field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['field'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_cm_person_last_name']['id'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['table'] = 'field_data_field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['field'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_cm_person_body']['id'] = 'field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['table'] = 'field_data_field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['field'] = 'field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_body']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Taxonomy term: Term ID */
  $handler->display->display_options['filters']['tid_raw_1']['id'] = 'tid_raw_1';
  $handler->display->display_options['filters']['tid_raw_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid_raw_1']['field'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw_1']['relationship'] = 'field_cm_movie_credits_person_ro_target_id';
  $handler->display->display_options['filters']['tid_raw_1']['value']['value'] = '411';
  $handler->display->display_options['filters']['tid_raw_1']['group'] = 2;
  /* Filter criterion: Taxonomy term: Term ID */
  $handler->display->display_options['filters']['tid_raw']['id'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid_raw']['field'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['relationship'] = 'field_cm_movie_credits_person_ro_target_id';
  $handler->display->display_options['filters']['tid_raw']['value']['value'] = '67';
  $handler->display->display_options['filters']['tid_raw']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_cm_person_photo']['id'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['table'] = 'field_data_field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['field'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_person_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_cm_person_first_name']['id'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['table'] = 'field_data_field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['field'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_person_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_cm_person_last_name']['id'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['table'] = 'field_data_field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['field'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_person_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_last_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['id'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['text'] = '[field_cm_movie_credits_person_ro]:';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_cm_person_body']['id'] = 'field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['table'] = 'field_data_field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['field'] = 'field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'field_cm_movie_credits_person_ro' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'nid' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_movie_credits_person' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_person_photo' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_person_address_name_line' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_person_body' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
  );
  $handler->display->display_options['path'] = 'director-bio';

  /* Display: Director Bio */
  $handler = $view->new_display('panel_pane', 'Director Bio', 'panel_pane_1');
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_cm_movie_credits_person' => 'field_cm_movie_credits_person',
    'field_cm_person_photo' => 'field_cm_person_photo',
    'field_cm_person_first_name' => 'field_cm_person_first_name',
    'field_cm_person_last_name' => 'field_cm_person_last_name',
    'field_cm_movie_credits_person_ro' => 'field_cm_movie_credits_person_ro',
    'field_cm_person_body' => 'field_cm_person_body',
    'nothing' => 'nothing',
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
    'field_cm_movie_credits_person' => array(
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
    'field_cm_person_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_person_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_movie_credits_person_ro' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_person_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_cm_person_photo']['id'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['table'] = 'field_data_field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['field'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_person_photo']['settings'] = array(
    'image_style' => 'person_thumbnail',
    'image_link' => 'content',
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
  $handler->display->display_options['fields']['field_cm_person_last_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['id'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['relationship'] = 'field_cm_movie_credits_value';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['alter']['text'] = '|   [field_cm_movie_credits_person_ro]';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_cm_person_body']['id'] = 'field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['table'] = 'field_data_field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['field'] = 'field_cm_person_body';
  $handler->display->display_options['fields']['field_cm_person_body']['relationship'] = 'field_cm_movie_credits_person_target_id';
  $handler->display->display_options['fields']['field_cm_person_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['field_cm_person_body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_body']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>[field_cm_person_first_name] [field_cm_person_last_name]</strong> <span class="only-desktop">| [field_cm_movie_credits_person_ro]</span>
<div class="body">[field_cm_person_body]</div>';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'right-area';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'field_cm_movie_credits_person_ro' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'nid' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_movie_credits_person' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_person_photo' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_person_address_name_line' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
    'field_cm_person_body' => array(
      'merge_option' => 'merge_unique',
      'separator' => ', ',
    ),
  );
  $export['director_bio'] = $view;

  return $export;
}
