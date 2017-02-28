<?php
/**
 * @file
 * cinematheque_feature_person_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_person_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'person_ct_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Person CT View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Person Top Pane */
  $handler = $view->new_display('panel_pane', 'Person Top Pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Person Top Pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_cm_person_photo']['id'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['table'] = 'field_data_field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['field'] = 'field_cm_person_photo';
  $handler->display->display_options['fields']['field_cm_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_person_photo']['settings'] = array(
    'image_style' => 'person_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_cm_person_first_name']['id'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['table'] = 'field_data_field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['field'] = 'field_cm_person_first_name';
  $handler->display->display_options['fields']['field_cm_person_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_first_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_first_name']['hide_empty'] = TRUE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_cm_person_last_name']['id'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['table'] = 'field_data_field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['field'] = 'field_cm_person_last_name';
  $handler->display->display_options['fields']['field_cm_person_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_last_name']['hide_alter_empty'] = FALSE;
  /* Field: Content: Profession */
  $handler->display->display_options['fields']['field_cm_person_type']['id'] = 'field_cm_person_type';
  $handler->display->display_options['fields']['field_cm_person_type']['table'] = 'field_data_field_cm_person_type';
  $handler->display->display_options['fields']['field_cm_person_type']['field'] = 'field_cm_person_type';
  $handler->display->display_options['fields']['field_cm_person_type']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-top-info">
       <div class="person-picture">[field_cm_person_photo]</div>
       <div class="person-name">[field_cm_person_first_name]  [field_cm_person_last_name]</div>
       <div class="person-job">[field_cm_person_type]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Country */
  $handler->display->display_options['fields']['field_cm_person_address_country']['id'] = 'field_cm_person_address_country';
  $handler->display->display_options['fields']['field_cm_person_address_country']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_country']['field'] = 'field_cm_person_address_country';
  $handler->display->display_options['fields']['field_cm_person_address_country']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_country']['alter']['text'] = '</br>[field_cm_person_address_country]
';
  $handler->display->display_options['fields']['field_cm_person_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_country']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_country']['display_name'] = 1;
  /* Field: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['id'] = 'field_cm_person_address_administrative_area';
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['field'] = 'field_cm_person_address_administrative_area';
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_administrative_area']['display_name'] = 1;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cm_person_address_locality']['id'] = 'field_cm_person_address_locality';
  $handler->display->display_options['fields']['field_cm_person_address_locality']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_locality']['field'] = 'field_cm_person_address_locality';
  $handler->display->display_options['fields']['field_cm_person_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_locality']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_locality']['alter']['text'] = '[field_cm_person_address_locality], ';
  $handler->display->display_options['fields']['field_cm_person_address_locality']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_locality']['hide_empty'] = TRUE;
  /* Field: Content: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['id'] = 'field_cm_person_address_thoroughfare';
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['field'] = 'field_cm_person_address_thoroughfare';
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['alter']['text'] = '[field_cm_person_address_thoroughfare], ';
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_thoroughfare']['hide_empty'] = TRUE;
  /* Field: Content: Address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_cm_person_address_premise']['id'] = 'field_cm_person_address_premise';
  $handler->display->display_options['fields']['field_cm_person_address_premise']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_premise']['field'] = 'field_cm_person_address_premise';
  $handler->display->display_options['fields']['field_cm_person_address_premise']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_premise']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_premise']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_premise']['element_label_colon'] = FALSE;
  /* Field: Content: Address with phone number */
  $handler->display->display_options['fields']['field_cm_person_address_data']['id'] = 'field_cm_person_address_data';
  $handler->display->display_options['fields']['field_cm_person_address_data']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_data']['field'] = 'field_cm_person_address_data';
  $handler->display->display_options['fields']['field_cm_person_address_data']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_data']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_data']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data']['selected_phone_type'] = '2';
  /* Field: Content: Address with phone number */
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['id'] = 'field_cm_person_address_data_1';
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['field'] = 'field_cm_person_address_data';
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['alter']['text'] = '<div class="phone">Phone: [field_cm_person_address_data_1]</div>';
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_1']['selected_phone_type'] = '1';
  /* Field: Content: Address with phone number */
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['id'] = 'field_cm_person_address_data_2';
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['field'] = 'field_cm_person_address_data';
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['alter']['text'] = '<div class="mobile">Mobile: [field_cm_person_address_data_2]</div>';
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_2']['selected_phone_type'] = '3';
  /* Field: Content: Address with phone number */
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['id'] = 'field_cm_person_address_data_3';
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['table'] = 'field_data_field_cm_person_address';
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['field'] = 'field_cm_person_address_data';
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['label'] = '';
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['alter']['text'] = '<div class="fax">Fax: [field_cm_person_address_data_3]</div>';
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_person_address_data_3']['selected_phone_type'] = '4';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website']['alter']['text'] = ' <div class="website"><a href="http://[field_website]" target="_blank">[field_website]</a></div>';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_website']['group_column'] = '';
  /* Field: Content: E-mail adress */
  $handler->display->display_options['fields']['field_e_mail_adress']['id'] = 'field_e_mail_adress';
  $handler->display->display_options['fields']['field_e_mail_adress']['table'] = 'field_data_field_e_mail_adress';
  $handler->display->display_options['fields']['field_e_mail_adress']['field'] = 'field_e_mail_adress';
  $handler->display->display_options['fields']['field_e_mail_adress']['label'] = '';
  $handler->display->display_options['fields']['field_e_mail_adress']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_e_mail_adress']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_e_mail_adress']['alter']['text'] = '<div class="email">[field_e_mail_adress]</div>';
  $handler->display->display_options['fields']['field_e_mail_adress']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_e_mail_adress']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="col-1 col">
    <div class="col-container col-container-1">
      [field_cm_person_address_thoroughfare] [field_cm_person_address_premise] [field_cm_person_address_locality] [field_cm_person_address_administrative_area] [field_cm_person_address_country]
  </div>
</div>
<div class="col-2 col">
    <div class="col-container col-container-2">
        [field_cm_person_address_data_1]
        [field_cm_person_address_data_2]
        [field_cm_person_address_data_3] 
    </div>
</div>
<div class="col-3 col">
    <div class="col-container col-container-3">
        [field_e_mail_adress]
        [field_website]
    </div>
</div
';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Person Credit Pane */
  $handler = $view->new_display('panel_pane', 'Person Credit Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_cm_movie_credits_person_ro',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_cm_movie_credits_person_field_collection_item']['id'] = 'reverse_field_cm_movie_credits_person_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_cm_movie_credits_person_field_collection_item']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_cm_movie_credits_person_field_collection_item']['field'] = 'reverse_field_cm_movie_credits_person_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_cm_movie_credits_person_field_collection_item']['required'] = TRUE;
  /* Relationship: Field collection item: Entity with the Movie Credits (field_cm_movie_credits) */
  $handler->display->display_options['relationships']['field_cm_movie_credits_node']['id'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['relationships']['field_cm_movie_credits_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_cm_movie_credits_node']['field'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['relationships']['field_cm_movie_credits_node']['relationship'] = 'reverse_field_cm_movie_credits_person_field_collection_item';
  $handler->display->display_options['relationships']['field_cm_movie_credits_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_movie_year_target_id']['id'] = 'field_cm_movie_year_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_year_target_id']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['relationships']['field_cm_movie_year_target_id']['field'] = 'field_cm_movie_year_target_id';
  $handler->display->display_options['relationships']['field_cm_movie_year_target_id']['relationship'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Profession */
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['id'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['table'] = 'field_data_field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['field'] = 'field_cm_movie_credits_person_ro';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['relationship'] = 'reverse_field_cm_movie_credits_person_field_collection_item';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_cm_movie_credits_person_ro']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
  );
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'title_teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['relationship'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['fields']['field_cm_movie_year']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_year']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_cm_movie_year_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_cm_movie_year_target_id';
  $handler->display->display_options['sorts']['name']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'field_cm_movie_credits_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['allow']['panopoly_magic_display_type'] = 0;
  $export['person_ct_view'] = $view;

  return $export;
}
