<?php
/**
 * @file
 * cinematheque_feature_moviegroup_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_moviegroup_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'movie_group_ct';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Movie Group CT';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
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
  /* Sort criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['sorts']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['relationship'] = 'field_event_corresponding_ref_target_id';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie_group' => 'cm_movie_group',
  );

  /* Display: Movie Group Content pane */
  $handler = $view->new_display('panel_pane', 'Movie Group Content pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Movie Group Content pane';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['id'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['table'] = 'field_data_field_movie_referenced';
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['field'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['required'] = TRUE;
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['relationship'] = 'field_movie_referenced_target_id';
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'translation';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Link';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_movie_pictures']['id'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['field'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['relationship'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['preserve_tags'] = '<img>';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['settings'] = array(
    'file_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['separator'] = '';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Content: Movie top text white */
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['id'] = 'field_mc_teaser_toptxt_white';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['table'] = 'field_data_field_mc_teaser_toptxt_white';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['field'] = 'field_mc_teaser_toptxt_white';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['label'] = '';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['alter']['text'] = '<span class="white">[field_mc_teaser_toptxt_white] </span>';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['hide_empty'] = TRUE;
  /* Field: Content: Movie top text black */
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['id'] = 'field_mc_teaser_toptxt_blk';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['table'] = 'field_data_field_mc_teaser_toptxt_blk';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['field'] = 'field_mc_teaser_toptxt_blk';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['label'] = '';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['alter']['text'] = '<div class="top-text-blk-wht">
    [field_mc_teaser_toptxt_white]
    <span class="black">[field_mc_teaser_toptxt_blk]</span>
  </div>';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['hide_empty'] = TRUE;
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['relationship'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = 'Purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
global $language;
$node = node_load($row->nid);
$translated_node=(!empty($node->tnid))?node_load(translation_node_get_translations($node->tnid)[$language->language]->nid):$node;
if ($language->language==\'he\') {
	$original_title=(!empty($node->tnid))?node_load(translation_node_get_translations($node->tnid)[\'en\']->nid)->title:\'\';
	$original_label=t(\'English name\');
	$original_marckup= ($original_title)?\'<div class="credit-inner">
            <div class="views-field views-field-field-cm-movie-credits-person-ro profession">\'. $original_label . \': \' .\'</div>
            <div class="views-field views-field-views-conditional">\' . $original_title . \'</div>
        </div>\':\'\';
} 
else {
	$original_label=t(\'Original title\');
	$original_title=field_get_items(\'node\', $translated_node, \'field_original_title\')[0][\'value\'];
	$original_marckup= ($original_title)?\'<div class="credit-inner">
            <div class="views-field views-field-field-cm-movie-credits-person-ro profession">\'. $original_label . \': \' .\'</div>
            <div class="views-field views-field-views-conditional">\' . $original_title . \'</div>
        </div>\':\'\';
}

$items = field_get_items(\'node\', $translated_node, \'field_cm_movie_credits\');
if (!is_array($items)) $items=array();
$profession_array = array();
foreach ($items as $item) {
    $fc = field_collection_field_get_entity($item);
    $profession = taxonomy_term_load($fc->field_cm_movie_credits_person_ro[\'und\'][0][\'target_id\']);
    $profession_name = $profession->name;
    $person_node = node_load($fc->field_cm_movie_credits_person[\'und\'][0][\'target_id\']);
    $path_node = drupal_get_path_alias(\'node/\'.$person_node->nid);
    $first =(!empty($person_node->field_cm_person_first_name[\'und\']))? $person_node->field_cm_person_first_name[\'und\'][0][\'value\']:\'\';
    $last = (!empty($person_node->field_cm_person_last_name[\'und\']))? $person_node->field_cm_person_last_name[\'und\'][0][\'value\']:\'\';
    $name  = $first .\' \'.$last;
    if(!empty($person_node->field_cm_person_first_name)){
        $full_name = $name;
    }else{
        $full_name = $person_node->title;
    }
    $lolo = $profession_name.\': \' .$full_name.\'<br />\';
	if (!array_key_exists ($profession_name, $profession_array)){
	  $profession_array[$profession_name] = array();
	}
    $profession_array[$profession_name][] = t(l($full_name, $path_node));
}
    print \'<div class="table-responsive credits-view">\';
    print $original_marckup;
    foreach($profession_array as $key => $value) {
        print \'<div class="credit-inner">\';
            print \'<div class="views-field views-field-field-cm-movie-credits-person-ro profession">\'. $key . \': \' .\'</div>\';
            print \'<div class="views-field views-field-views-conditional">\' . implode(", ",$value) . \'</div>\';
        print \'</div>\';
    }
    print \'</div>\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="img-like-wrapper">
<div class="gradient small"></div>
	<div class="img movie-group-title-pic-container"><div class="movie-picture-movie-group">[field_cm_movie_pictures]</div><div class="movie-title-movie-group">[title]</div></div>
	<div class="like-btn"><span class="movie-info">[ops]</span></div>
[field_mc_teaser_toptxt_blk]
<div class="custom-node-link">[view_node] </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['text'] = '<span class="space-bar">[field_cm_movie_meta_credit] | </span>';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['type'] = 'text_plain';
  /* Field: Content: Country origin */
  $handler->display->display_options['fields']['field_cm_movie_country']['id'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['field'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_movie_country']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_country']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_country']['delta_offset'] = '0';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_movie_year']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['alter']['text'] = '<span class="space-bar"> [field_cm_movie_country]  [field_cm_movie_year] | </span>';
  $handler->display->display_options['fields']['field_cm_movie_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = '<span class="space-bar length-movie">[field_cm_movie_duration-interval] minutes | </span>';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['preserve_tags'] = '<span></span>';
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['relationship'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['text'] = '<span class="space-bar"> [field_cm_movie_language] | </span>';
  $handler->display->display_options['fields']['field_cm_movie_language']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_limit'] = '5';
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cm_movie_language']['separator'] = '';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['relationship'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['text'] = ' <span class="space-bar"> [field_cm_movie_subtitle] subtitles   </span>';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
  /* Field: Content: Long summary */
  $handler->display->display_options['fields']['field_cm_movie_body']['id'] = 'field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['table'] = 'field_data_field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['field'] = 'field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_cm_movie_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_cm_movie_body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'translation';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_cm_movie_meta_credit] [field_cm_movie_year] [field_cm_movie_duration] [field_cm_movie_language] [field_cm_movie_subtitle]';
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
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Movie Group Slideshow */
  $handler = $view->new_display('panel_pane', 'Movie Group Slideshow', 'panel_pane_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'full-screen-image';
  $handler->display->display_options['display_description'] = 'Movie Group Slideshow';
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
  /* Field: Content: Trailer */
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['id'] = 'field_cm_moviegroup_videos';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['table'] = 'field_data_field_cm_moviegroup_videos';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['field'] = 'field_cm_moviegroup_videos';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['label'] = '';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['alter']['text'] = '<div class="play-button"></div>
<div class="video-wrapper">
<div class="close-button"></div>
[field_cm_moviegroup_videos]
</div>';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['settings'] = array(
    'file_view_mode' => 'default',
  );
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
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['label'] = '';
  $handler->display->display_options['fields']['field_lobby']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lobby']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lobby']['alter']['text'] = '[field_lobby]';
  $handler->display->display_options['fields']['field_lobby']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lobby']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 1,
  );
  /* Field: Taxonomy term: Active category dates */
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['id'] = 'field_cm_lobby_active_date';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['table'] = 'field_data_field_cm_lobby_active_date';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['field'] = 'field_cm_lobby_active_date';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['relationship'] = 'field_lobby_target_id';
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_lobby_active_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_lobby_active_date';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '3';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'DATE_STAMP';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_lobby] ';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Lobby list */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Lobby list';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$taxonomy_array=array();
foreach ($data->field_field_lobby as $key => $tid_value) {
	$date=strtotime(taxonomy_term_load($tid_value[\'raw\'][\'target_id\'])->field_cm_lobby_active_date[\'und\'][0][\'value2\']);
	if ($date>time()) $taxonomy_array[]=$tid_value[\'rendered\'][\'#markup\'];
	
}
print (implode(", ",$taxonomy_array));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['id'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['table'] = 'field_data_field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['field'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['alter']['text'] = '<div class="movie-group-slide-container wrapper-image">
    <div class="movie-group-slide content">
        [field_cm_moviegroup_pictures]
    </div>
    <div class="slide-inner-group text-main-image">
      <div class="wrapper">
    <div class="slide-right-ct">
    </div>
        <div class="slide-left-ct">
          <div class="slide-eve-title slide-small-text">[php] </div>
          <div class="slide-movie-title slide-big-text">[title]</div>
        </div>
    </div>
</div>
   <div class="image-alt-title">
       <span class="grp-alt">[field_cm_moviegroup_pictures-alt]</span>
       <span class="grp-title">[field_cm_moviegroup_pictures-title]</span>
   </div>
</div>';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['settings'] = array(
    'image_style' => 'slide_show',
    'image_link' => '',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="gradient"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Movie Group Upcoming Event */
  $handler = $view->new_display('panel_pane', 'Movie Group Upcoming Event', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Movie Group Upcoming Event';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'up-events-item-movie';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_cm_event_time_1' => 'field_cm_event_time_1',
    'field_cm_event_time' => 'field_cm_event_time',
    'title' => 'title',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_internal_id' => 'field_cm_event_internal_id',
    'ops' => 'ops',
    'php' => 'php',
    'nid' => 'nid',
    'field_toptix_purchase' => 'field_toptix_purchase',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_cm_event_time_1' => array(
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
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_hall' => array(
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
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
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
if( $view->total_rows > 3){
print \'<div class="more-event">\'.t(\'More Screening\').\'</div>\';
}
?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['id'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['table'] = 'field_data_field_event_corresponding_ref';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['field'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_2']['id'] = 'field_cm_event_time_2';
  $handler->display->display_options['fields']['field_cm_event_time_2']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_2']['settings'] = array(
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
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_time_1']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_time_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'custom',
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
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_cm_event_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['alter']['text'] = '<div class="only-mobile">[field_cm_event_time_2]</div>
[field_cm_event_time]';
  $handler->display->display_options['fields']['field_cm_event_time']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
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
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['element_label_colon'] = FALSE;
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['text'] = '[field_cm_event_hall]
<div class="only-mobile">[field_cm_event_internal_id_1]</div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Event Title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['title']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
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
  $handler->display->display_options['fields']['field_cm_event_comment']['element_class'] = 'only-desktop';
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['label'] = 'Event ID';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['empty'] = '<div class="hide-div"></div>';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['ops']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_toptix_purchase']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = 'Tickets';
  $handler->display->display_options['fields']['field_toptix_purchase']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_toptix_purchase']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['sorts']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['relationship'] = 'field_event_corresponding_ref_target_id';
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
  $handler->display->display_options['filters']['type']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_movie_group' => 'cm_movie_group',
  );
  /* Filter criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['filters']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cm_event_time_value']['default_date'] = 'now';

  /* Display: Movie Group Body */
  $handler = $view->new_display('panel_pane', 'Movie Group Body', 'panel_pane_4');
  $handler->display->display_options['display_description'] = 'Movie Group Body';
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
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;

  /* Display: Ricky's old Movie Group Content pane */
  $handler = $view->new_display('panel_pane', 'Ricky\'s old Movie Group Content pane', 'panel_pane_5');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Ricky\'s old Movie Group Content pane';
  $handler->display->display_options['field_language'] = '***DEFAULT_LANGUAGE***';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="movie-grp-title"><h5 >[field_cm_moviegroup_org_title]</h5></div>
<div class="movie-grp-body">[body]</div>';
  $handler->display->display_options['header']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_movie_corresponding_ref_node']['id'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['relationships']['reverse_field_movie_corresponding_ref_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_movie_corresponding_ref_node']['field'] = 'reverse_field_movie_corresponding_ref_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['id'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['table'] = 'field_data_field_event_corresponding_ref';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['field'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_movie_pictures']['id'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['field'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['preserve_tags'] = '"<img><a>"';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['settings'] = array(
    'file_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_cm_movie_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_offset'] = '0';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Content: Movie top text white */
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['id'] = 'field_mc_teaser_toptxt_white';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['table'] = 'field_data_field_mc_teaser_toptxt_white';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['field'] = 'field_mc_teaser_toptxt_white';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['label'] = '';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['alter']['text'] = '<span class="white">[field_mc_teaser_toptxt_white] </span>';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_white']['hide_empty'] = TRUE;
  /* Field: Content: Movie top text black */
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['id'] = 'field_mc_teaser_toptxt_blk';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['table'] = 'field_data_field_mc_teaser_toptxt_blk';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['field'] = 'field_mc_teaser_toptxt_blk';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['label'] = '';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['alter']['text'] = '<div class="top-text-blk-wht">
    [field_mc_teaser_toptxt_white]
    <span class="black">[field_mc_teaser_toptxt_blk]</span>
  </div>';
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mc_teaser_toptxt_blk']['hide_empty'] = TRUE;
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = 'Purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_hall']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_hall']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: date of event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_time']['ui_name'] = 'date of event';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'date of Event';
  $handler->display->display_options['fields']['field_cm_event_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'custom',
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
  $handler->display->display_options['fields']['field_cm_event_time_1']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'custom_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Link';
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
print _return_addthisevent_markup($node);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="img-like-wrapper">
	<div class="img movie-group-title-pic-container"><div class="movie-picture-movie-group">[field_cm_movie_pictures]</div><div class="movie-title-movie-group">[title]</div></div>
	<div class="like-btn"><span class="movie-info">[ops]</span></div>
[field_mc_teaser_toptxt_blk]
<div class="custom-node-link">[view_node] </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Like */
  $handler->display->display_options['fields']['field_like']['id'] = 'field_like';
  $handler->display->display_options['fields']['field_like']['table'] = 'field_data_field_like';
  $handler->display->display_options['fields']['field_like']['field'] = 'field_like';
  $handler->display->display_options['fields']['field_like']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_like']['label'] = '';
  $handler->display->display_options['fields']['field_like']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_like']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_like']['click_sort_column'] = 'likebtn_likes';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = '[field_cm_movie_duration-interval] [field_cm_movie_duration-period] ';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_year']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Country origin */
  $handler->display->display_options['fields']['field_cm_movie_country']['id'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['field'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_country']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_country']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['element_label_colon'] = FALSE;
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['text'] = '[field_cm_movie_subtitle]<span class="bar">|</span>[field_cm_movie_language]<span class="bar">|</span>[field_cm_movie_duration]<span class="bar">|</span>[field_cm_movie_country]  [field_cm_movie_year]<span class="bar">|</span>[field_cm_movie_meta_credit]';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
  /* Field: Content: Short Summary */
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['id'] = 'field_cm_movie_short_summary';
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['table'] = 'field_data_field_cm_movie_short_summary';
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['field'] = 'field_cm_movie_short_summary';
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_short_summary']['settings'] = array(
    'trim_length' => '600',
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
    'cm_movie_group' => 'cm_movie_group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_movie_corresponding_ref_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Old Movie Group Upcoming Event */
  $handler = $view->new_display('panel_pane', 'Old Movie Group Upcoming Event', 'panel_pane_6');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Old Movie Group Upcoming Event';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'up-events-item-movie';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_cm_event_time_1' => 'field_cm_event_time_1',
    'field_cm_event_time' => 'field_cm_event_time',
    'title' => 'title',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_internal_id' => 'field_cm_event_internal_id',
    'ops' => 'ops',
    'php' => 'php',
    'nid' => 'nid',
    'field_toptix_purchase' => 'field_toptix_purchase',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_cm_event_time_1' => array(
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
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cm_event_hall' => array(
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
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
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
if( $view->total_rows > 3){
print \'<div class="more-event">\'.t(\'More Screening\').\'</div>\';
}
?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['id'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['table'] = 'field_data_field_movie_referenced';
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['field'] = 'field_movie_referenced_target_id';
  $handler->display->display_options['relationships']['field_movie_referenced_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['id'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['table'] = 'field_data_field_event_corresponding_ref';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['field'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['relationship'] = 'field_movie_referenced_target_id';
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_2']['id'] = 'field_cm_event_time_2';
  $handler->display->display_options['fields']['field_cm_event_time_2']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_2']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_time_2']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_2']['settings'] = array(
    'format_type' => 'only_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time_1']['id'] = 'field_cm_event_time_1';
  $handler->display->display_options['fields']['field_cm_event_time_1']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_time_1']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_time_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'custom',
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
  $handler->display->display_options['fields']['field_cm_event_time']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_cm_event_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['alter']['text'] = '<div class="only-mobile">[field_cm_event_time_2]</div>
[field_cm_event_time]';
  $handler->display->display_options['fields']['field_cm_event_time']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
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
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['element_label_colon'] = FALSE;
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['text'] = '[field_cm_event_hall]
<div class="only-mobile">[field_cm_event_internal_id_1]</div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title']['label'] = 'Event Title';
  $handler->display->display_options['fields']['title']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['label'] = 'Event ID';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['empty'] = '<div class="hide-div"></div>';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_class'] = 'only-desktop';
  $handler->display->display_options['fields']['ops']['element_label_class'] = 'only-desktop';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_toptix_purchase']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = 'Tickets';
  $handler->display->display_options['fields']['field_toptix_purchase']['empty'] = '<div class="hide-div"></div>';
  $handler->display->display_options['fields']['field_toptix_purchase']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['sorts']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['sorts']['field_cm_event_time_value']['relationship'] = 'field_event_corresponding_ref_target_id';
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
    'cm_movie_group' => 'cm_movie_group',
  );
  $export['movie_group_ct'] = $view;

  return $export;
}
