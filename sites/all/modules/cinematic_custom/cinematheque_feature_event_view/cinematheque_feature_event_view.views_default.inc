<?php
/**
 * @file
 * cinematheque_feature_event_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_event_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_ct_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event CT View';
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
    'cm_event' => 'cm_event',
  );

  /* Display: Event Slideshow Pane */
  $handler = $view->new_display('panel_pane', 'Event Slideshow Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'full-screen-image';
  $handler->display->display_options['display_description'] = 'Event Slideshow Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'event_ct_view:panel_pane_9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images & Teasers */
  $handler->display->display_options['fields']['field_cm_event_images']['id'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['table'] = 'field_data_field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['field'] = 'field_cm_event_images';
  $handler->display->display_options['fields']['field_cm_event_images']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_images']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_images']['alter']['text'] = '<div class="movie-group-slide-container">
<div class="gradient"></div>
    <div class="movie-group-slide">
       <div class="wrapper-image"><div class="content"> [field_cm_event_images]</div></div>
    </div>
<div class="image-alt-title">
       <span class="grp-alt"> [field_cm_event_images-alt] </span>
       <span class="grp-title">[field_cm_event_images-title] </span>
   </div>
</div>';
  $handler->display->display_options['fields']['field_cm_event_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_event_images']['settings'] = array(
    'image_style' => 'slide_show',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_cm_event_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_images']['delta_offset'] = '0';
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
  /* Filter criterion: Content: Images &amp; Teasers (field_cm_event_images:alt) */
  $handler->display->display_options['filters']['field_cm_event_images_alt']['id'] = 'field_cm_event_images_alt';
  $handler->display->display_options['filters']['field_cm_event_images_alt']['table'] = 'field_data_field_cm_event_images';
  $handler->display->display_options['filters']['field_cm_event_images_alt']['field'] = 'field_cm_event_images_alt';
  $handler->display->display_options['filters']['field_cm_event_images_alt']['operator'] = 'not empty';
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

  /* Display: Event Head content Pane */
  $handler = $view->new_display('panel_pane', 'Event Head content Pane', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Event Head content Pane';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['alter']['text'] = '[field_cm_movie_meta_credit] | ';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['empty'] = '<div class="hide-div-credit"></div>';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['hide_empty'] = TRUE;
  /* Field: Content: Main event credit */
  $handler->display->display_options['fields']['field_main_event_credit']['id'] = 'field_main_event_credit';
  $handler->display->display_options['fields']['field_main_event_credit']['table'] = 'field_data_field_main_event_credit';
  $handler->display->display_options['fields']['field_main_event_credit']['field'] = 'field_main_event_credit';
  $handler->display->display_options['fields']['field_main_event_credit']['label'] = '';
  $handler->display->display_options['fields']['field_main_event_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_main_event_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_main_event_credit']['alter']['text'] = '[field_cm_movie_meta_credit] | ';
  $handler->display->display_options['fields']['field_main_event_credit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_event_credit']['empty'] = '<div class="hide-div-credit"></div>';
  $handler->display->display_options['fields']['field_main_event_credit']['hide_empty'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$event_node = node_load($data->nid);
if(!empty($event_node->field_cm_event_lineup[\'und\'])){
    $node = node_load($event_node->field_cm_event_lineup[\'und\'][0][\'target_id\']);
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
}
?>
<script>
    jQuery(\'a.lightboxed\').colorbox({iframe:true, width:"540px", height:"440px"});
</script>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_lobby']['label'] = '';
  $handler->display->display_options['fields']['field_lobby']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lobby']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Short Title */
  $handler->display->display_options['fields']['field_cm_event_short_title']['id'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['table'] = 'field_data_field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['field'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_short_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['text'] = '[field_lobby]  | [field_cm_event_short_title]';
  $handler->display->display_options['fields']['field_cm_event_short_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h1>[title]</h1>
';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title_1]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Event Duration */
  $handler->display->display_options['fields']['field_cm_event_duration']['id'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['table'] = 'field_data_field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['field'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['alter']['text'] = '[field_cm_event_duration-interval] minutes';
  $handler->display->display_options['fields']['field_cm_event_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = '[field_cm_movie_duration-interval] minutes';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '[field_cm_event_duration]';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_cm_event_duration]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_cm_movie_duration]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby_1']['id'] = 'field_lobby_1';
  $handler->display->display_options['fields']['field_lobby_1']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby_1']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby_1']['label'] = '';
  $handler->display->display_options['fields']['field_lobby_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lobby_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lobby_1']['settings'] = array(
    'link' => 1,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_lobby_1']['delta_offset'] = '0';
  /* Field: Lobby list */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Lobby list';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
$taxonomy_array=array();
$field_field_lobby=(!empty($data->field_field_lobby_1))?$data->field_field_lobby_1:$data->field_field_lobby;
foreach ($field_field_lobby as $key => $tid_value) {
	$date=strtotime(taxonomy_term_load($tid_value[\'raw\'][\'target_id\'])->field_cm_lobby_active_date[\'und\'][0][\'value2\']);
	if ($date>time()) $taxonomy_array[]=$tid_value[\'rendered\'][\'#markup\'];
}
print (implode(", ",$taxonomy_array));
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_lobby_1';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = '[field_lobby_1]';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[php_2]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[php_2]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
    $event_node = node_load($data->nid);
    $event_node_title = $event_node->title;
    //$event_short_title = $event_node->field_cm_event_short_title[\'und\'][0][\'value\'];
    $event_title =  $event_node_title;
    if(!empty($event_node->field_cm_event_lineup[\'und\'])){
        $movie_node = node_load($event_node->field_cm_event_lineup[\'und\'][0][\'target_id\']);
        $movie_title = $movie_node->title;
        $path = drupal_get_path_alias(\'node/\'.$movie_node->nid);
        if($movie_title == $event_title){
                print \'<div class="slide-movie-title movies-title slide-big-text">\'. t($movie_title) .\'</div>\';
        }else{
               print \'<div class="slide-movie-title events-title slide-small-text">\' . t($event_title) . \'</div>\';
                print \'<div class="slide-movie-title movies-title slide-big-text">\'. t($movie_title) .\'</div>\';
        }
    }else{
        print \'<div class="slide-movie-title movies-title slide-big-text">\'. t($event_title) .\'</div>\';
    }
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_2']['id'] = 'views_conditional_2';
  $handler->display->display_options['fields']['views_conditional_2']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_2']['if'] = 'field_main_event_credit';
  $handler->display->display_options['fields']['views_conditional_2']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional_2']['equalto'] = '[field_main_event_credit]';
  $handler->display->display_options['fields']['views_conditional_2']['then'] = '[field_main_event_credit]';
  $handler->display->display_options['fields']['views_conditional_2']['or'] = '[field_cm_movie_meta_credit]';
  $handler->display->display_options['fields']['views_conditional_2']['strip_tags'] = 0;
  /* Field: Content: Trailer */
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['id'] = 'field_cm_moviegroup_videos';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['table'] = 'field_data_field_cm_moviegroup_videos';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['field'] = 'field_cm_moviegroup_videos';
  $handler->display->display_options['fields']['field_cm_moviegroup_videos']['relationship'] = 'field_cm_event_lineup_target_id';
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
  /* Field: Content: Trailers */
  $handler->display->display_options['fields']['field_cm_movie_videos']['id'] = 'field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos']['table'] = 'field_data_field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos']['field'] = 'field_cm_movie_videos';
  $handler->display->display_options['fields']['field_cm_movie_videos']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_videos']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_videos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_videos']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_videos']['alter']['text'] = '<div class="play-button"></div>
<div class="video-wrapper">
<div class="close-button"></div>
[field_cm_movie_videos]
</div>';
  $handler->display->display_options['fields']['field_cm_movie_videos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_videos']['empty'] = '[field_cm_moviegroup_videos]';
  $handler->display->display_options['fields']['field_cm_movie_videos']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_videos']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_cm_movie_videos']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_cm_movie_videos']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="slide-over-content text-main-image">
  <div class="wrapper">
    <div class="slide-right-ct">
       [field_cm_movie_videos]
    </div>
    <div class="slide-left-ct">
        <div class="slide-eve-lobby slide-small-text">[php_2]</div>
          [php_1]
        <div class="slide-movie-year slide-small-text"><span class="crdt">[views_conditional_2]  </span><span class="mnts"> [views_conditional]</span> </div>
    </div>
    <div class="ctr"></div>
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_language']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Event Details Pane */
  $handler = $view->new_display('panel_pane', 'Event Details Pane', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'Event Details Pane';
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
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_hall']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Short Title */
  $handler->display->display_options['fields']['field_cm_event_short_title']['id'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['table'] = 'field_data_field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['field'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_short_title']['element_label_colon'] = FALSE;
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_label_colon'] = FALSE;

  /* Display: Event favorite links */
  $handler = $view->new_display('panel_pane', 'Event favorite links', 'panel_pane_4');
  $handler->display->display_options['display_description'] = 'Event favorite links';
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

  /* Display: First referenced  Movie In Event Ct */
  $handler = $view->new_display('panel_pane', 'First referenced  Movie In Event Ct', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Other Screenings';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['display_description'] = 'First referenced  Movie In Event Ct';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_cm_event_lineup' => 'field_cm_event_lineup',
    'title_1' => 'title_1',
    'field_cm_event_time' => 'field_cm_event_time',
    'field_cm_event_time_1' => 'field_cm_event_time_1',
    'field_cm_event_hall' => 'field_cm_event_hall',
    'field_cm_event_internal_id' => 'field_cm_event_internal_id',
    'field_toptix_purchase' => 'field_toptix_purchase',
    'ops' => 'ops',
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
    'field_cm_event_lineup' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
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
    'field_cm_event_time_1' => array(
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
    'field_toptix_purchase' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['id'] = 'field_cm_event_internal_id_1';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
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
    'cm_event' => 'cm_event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Event first referenced movie description */
  $handler = $view->new_display('panel_pane', 'Event first referenced movie description', 'panel_pane_6');
  $handler->display->display_options['display_description'] = 'Event first referenced movie description';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_language']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['text'] = '| [field_cm_movie_language]';
  $handler->display->display_options['fields']['field_cm_movie_language']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['id'] = 'field_cm_moviegroup_duration';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['table'] = 'field_data_field_cm_moviegroup_duration';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['field'] = 'field_cm_moviegroup_duration';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['alter']['text'] = '[field_cm_moviegroup_duration-interval] minutes';
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_moviegroup_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = '| [field_cm_movie_duration-interval] minutes';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['text'] = '| [field_cm_movie_subtitle] subtitles';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_cm_movie_year']['id'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['table'] = 'field_data_field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['field'] = 'field_cm_movie_year';
  $handler->display->display_options['fields']['field_cm_movie_year']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_year']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_year']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_year']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Country origin */
  $handler->display->display_options['fields']['field_cm_movie_country']['id'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['table'] = 'field_data_field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['field'] = 'field_cm_movie_country';
  $handler->display->display_options['fields']['field_cm_movie_country']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_country']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['alter']['text'] = '| [field_cm_movie_country]';
  $handler->display->display_options['fields']['field_cm_movie_country']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_country']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_country']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_country']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_cm_movie_country] [field_cm_movie_year] [field_cm_movie_duration] [field_cm_moviegroup_duration][field_cm_movie_language] <span class="sub-title">[field_cm_movie_subtitle]</span>  ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Movie Referenced */
  $handler->display->display_options['fields']['field_movie_referenced']['id'] = 'field_movie_referenced';
  $handler->display->display_options['fields']['field_movie_referenced']['table'] = 'field_data_field_movie_referenced';
  $handler->display->display_options['fields']['field_movie_referenced']['field'] = 'field_movie_referenced';
  $handler->display->display_options['fields']['field_movie_referenced']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_movie_referenced']['label'] = '';
  $handler->display->display_options['fields']['field_movie_referenced']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_movie_referenced']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_movie_referenced']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_movie_referenced']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'print (\'<div class="pan-title">\'. t(\'About the series\').\' </div>\');';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_movie_referenced';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[php]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Long summary */
  $handler->display->display_options['fields']['field_cm_movie_body']['id'] = 'field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['table'] = 'field_data_field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['field'] = 'field_cm_movie_body';
  $handler->display->display_options['fields']['field_cm_movie_body']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_body']['alter']['text'] = '[body] [field_cm_movie_body]';
  $handler->display->display_options['fields']['field_cm_movie_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Event Movie Ref Event Content */
  $handler = $view->new_display('block', 'Event Movie Ref Event Content', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Event Movie Ref Event Content';
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: favorite_ */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favorite_';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['id'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['table'] = 'field_data_field_event_corresponding_ref';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['field'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['relationships']['field_event_corresponding_ref_target_id']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Time of Event */
  $handler->display->display_options['fields']['field_cm_event_time']['id'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = 'Date';
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
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = 'Time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'panopoly_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['label'] = 'Event ID';
  /* Field: Content: toptix purchase */
  $handler->display->display_options['fields']['field_toptix_purchase']['id'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['table'] = 'field_data_field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['field'] = 'field_toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['fields']['field_toptix_purchase']['label'] = 'Toptix Purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
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
  $handler->display->display_options['filters']['type']['relationship'] = 'field_event_corresponding_ref_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cm_event' => 'cm_event',
  );

  /* Display: Event Below Info  */
  $handler = $view->new_display('panel_pane', 'Event Below Info ', 'panel_pane_7');
  $handler->display->display_options['display_description'] = 'Event Below Info ';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
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
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops_1']['label'] = '';
  $handler->display->display_options['fields']['ops_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops_1']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_class'] = 'add-event';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$node = node_load($row->nid);
print _return_addthisevent_markup($node);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="circle"></span>
<span class="circle"></span>
<span class="circle"></span>
<div class="flag-calendar hide">
<div class="flag">
[ops_1]
</div>
<div class="calendar add-event">
[php_1]
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'only-mobile mobile-points';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_cm_event_time_3']['id'] = 'field_cm_event_time_3';
  $handler->display->display_options['fields']['field_cm_event_time_3']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_3']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_3']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_3']['alter']['text'] = '[field_cm_event_time_2]</br>
[field_cm_event_time_3]';
  $handler->display->display_options['fields']['field_cm_event_time_3']['element_class'] = 'only-mobile';
  $handler->display->display_options['fields']['field_cm_event_time_3']['element_label_class'] = 'only-mobile';
  $handler->display->display_options['fields']['field_cm_event_time_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_3']['settings'] = array(
    'format_type' => 'time_full_format',
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
  $handler->display->display_options['fields']['field_cm_event_time_1']['id'] = 'field_cm_event_time_1';
  $handler->display->display_options['fields']['field_cm_event_time_1']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['field'] = 'field_cm_event_time';
  $handler->display->display_options['fields']['field_cm_event_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['alter']['text'] = '<span class="day-same-width">[field_cm_event_time_1]</span> | [field_cm_event_time_4]';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_class'] = 'only-desktop date';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_class'] = 'only-desktop date';
  $handler->display->display_options['fields']['field_cm_event_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time_1']['settings'] = array(
    'format_type' => 'only_day',
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
  $handler->display->display_options['fields']['field_cm_event_time']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_time']['element_class'] = 'only-desktop time';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_class'] = 'only-desktop time';
  $handler->display->display_options['fields']['field_cm_event_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_time']['settings'] = array(
    'format_type' => 'time_full_format',
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
  $handler->display->display_options['fields']['field_cm_event_internal_id_1']['hide_empty'] = TRUE;
  /* Field: Content: Hall */
  $handler->display->display_options['fields']['field_cm_event_hall']['id'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['table'] = 'field_data_field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['field'] = 'field_cm_event_hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_hall']['alter']['text'] = '[field_cm_event_hall]
<div class="only-mobile">[field_cm_event_internal_id_1] </div>';
  $handler->display->display_options['fields']['field_cm_event_hall']['element_class'] = 'hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['element_label_class'] = 'hall';
  $handler->display->display_options['fields']['field_cm_event_hall']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_hall']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Short Title */
  $handler->display->display_options['fields']['field_cm_event_short_title']['id'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['table'] = 'field_data_field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['field'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_short_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['element_label_colon'] = FALSE;
  /* Field: Content: Screening table remarks */
  $handler->display->display_options['fields']['field_cm_event_comment']['id'] = 'field_cm_event_comment';
  $handler->display->display_options['fields']['field_cm_event_comment']['table'] = 'field_data_field_cm_event_comment';
  $handler->display->display_options['fields']['field_cm_event_comment']['field'] = 'field_cm_event_comment';
  $handler->display->display_options['fields']['field_cm_event_comment']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_comment']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_class'] = 'only-desktop title';
  $handler->display->display_options['fields']['views_conditional']['element_label_class'] = 'only-desktop title';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_event_comment';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '[field_cm_event_comment] ';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_cm_event_comment] ';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Cinematheque event ID */
  $handler->display->display_options['fields']['field_cm_event_internal_id']['id'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['table'] = 'field_data_field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['field'] = 'field_cm_event_internal_id';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_class'] = 'only-desktop code';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_label_class'] = 'only-desktop code';
  $handler->display->display_options['fields']['field_cm_event_internal_id']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_class'] = 'only-desktop like-flag';
  $handler->display->display_options['fields']['ops']['element_label_class'] = 'only-desktop flag';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_class'] = 'only-desktop add-event';
  $handler->display->display_options['fields']['php']['element_label_class'] = 'only-desktop';
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
  $handler->display->display_options['fields']['field_toptix_purchase']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_toptix_purchase']['type'] = 'toptix_purchase';
  $handler->display->display_options['fields']['field_toptix_purchase']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Tickets sold out */
  $handler->display->display_options['fields']['field_tickets_sold_out']['id'] = 'field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['table'] = 'field_data_field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['field'] = 'field_tickets_sold_out';
  $handler->display->display_options['fields']['field_tickets_sold_out']['label'] = '';
  $handler->display->display_options['fields']['field_tickets_sold_out']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['alter']['text'] = '<div class="sold-out">Sold out</div>';
  $handler->display->display_options['fields']['field_tickets_sold_out']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['empty'] = '[field_toptix_purchase]';
  $handler->display->display_options['fields']['field_tickets_sold_out']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_tickets_sold_out']['type'] = 'list_key';
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
  /* Filter criterion: Content: Time of Event -  start date (field_cm_event_time) */
  $handler->display->display_options['filters']['field_cm_event_time_value']['id'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['table'] = 'field_data_field_cm_event_time';
  $handler->display->display_options['filters']['field_cm_event_time_value']['field'] = 'field_cm_event_time_value';
  $handler->display->display_options['filters']['field_cm_event_time_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_cm_event_time_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_cm_event_time_value']['default_date'] = 'now';

  /* Display: Event Body Part */
  $handler = $view->new_display('panel_pane', 'Event Body Part', 'panel_pane_8');
  $handler->display->display_options['display_description'] = 'Event Body Part';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Details */
  $handler->display->display_options['fields']['field_cm_event_body']['id'] = 'field_cm_event_body';
  $handler->display->display_options['fields']['field_cm_event_body']['table'] = 'field_data_field_cm_event_body';
  $handler->display->display_options['fields']['field_cm_event_body']['field'] = 'field_cm_event_body';
  $handler->display->display_options['fields']['field_cm_event_body']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_body']['element_class'] = 'aaa';
  $handler->display->display_options['fields']['field_cm_event_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_body']['hide_empty'] = TRUE;

  /* Display: Event Slideshow from line up Pane */
  $handler = $view->new_display('panel_pane', 'Event Slideshow from line up Pane', 'panel_pane_9');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'full-screen-image';
  $handler->display->display_options['display_description'] = 'Event Slideshow Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['required'] = TRUE;
  /* Relationship: Content: Pictures (field_cm_movie_pictures:fid) */
  $handler->display->display_options['relationships']['field_cm_movie_pictures_fid']['id'] = 'field_cm_movie_pictures_fid';
  $handler->display->display_options['relationships']['field_cm_movie_pictures_fid']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['relationships']['field_cm_movie_pictures_fid']['field'] = 'field_cm_movie_pictures_fid';
  $handler->display->display_options['relationships']['field_cm_movie_pictures_fid']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_movie_pictures']['id'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['table'] = 'field_data_field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['field'] = 'field_cm_movie_pictures';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['alter']['text'] = '<div class="wrapper-image">[field_cm_movie_pictures]</div>';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cm_movie_pictures']['settings'] = array(
    'file_view_mode' => 'top_gallery_front',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_cm_movie_pictures']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_pictures']['delta_offset'] = '0';
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['id'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['table'] = 'field_data_field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['field'] = 'field_cm_moviegroup_pictures';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['label'] = '';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['alter']['text'] = '<div class="wrapper-image">[field_cm_moviegroup_pictures]</div>';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cm_moviegroup_pictures']['element_class'] = 'wrapper-image';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
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
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Test Event Head content Pane */
  $handler = $view->new_display('panel_pane', 'Test Event Head content Pane', 'panel_pane_10');
  $handler->display->display_options['display_description'] = 'Test Event Head content Pane';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['id'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['table'] = 'field_data_field_cm_event_lineup';
  $handler->display->display_options['relationships']['field_cm_event_lineup_target_id']['field'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['relationship'] = 'field_cm_event_lineup_target_id';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_1']['id'] = 'translation_1';
  $handler->display->display_options['relationships']['translation_1']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_1']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_1']['label'] = 'Main Translations';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: leading credit text */
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['id'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['table'] = 'field_data_field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['field'] = 'field_cm_movie_meta_credit';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_meta_credit']['element_label_colon'] = FALSE;
  /* Field: Content: Main event credit */
  $handler->display->display_options['fields']['field_main_event_credit']['id'] = 'field_main_event_credit';
  $handler->display->display_options['fields']['field_main_event_credit']['table'] = 'field_data_field_main_event_credit';
  $handler->display->display_options['fields']['field_main_event_credit']['field'] = 'field_main_event_credit';
  $handler->display->display_options['fields']['field_main_event_credit']['label'] = '';
  $handler->display->display_options['fields']['field_main_event_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_main_event_credit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_event_credit']['hide_empty'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$event_node = node_load($data->nid);
if(!empty($event_node->field_cm_event_lineup[\'und\'])){
    $node = node_load($event_node->field_cm_event_lineup[\'und\'][0][\'target_id\']);
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
}
?>
<script>
    jQuery(\'a.lightboxed\').colorbox({iframe:true, width:"540px", height:"440px"});
</script>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby']['id'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_lobby']['label'] = '';
  $handler->display->display_options['fields']['field_lobby']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lobby']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lobby']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_lobby']['delta_offset'] = '0';
  /* Field: Content: Short Title */
  $handler->display->display_options['fields']['field_cm_event_short_title']['id'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['table'] = 'field_data_field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['field'] = 'field_cm_event_short_title';
  $handler->display->display_options['fields']['field_cm_event_short_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_short_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_short_title']['alter']['text'] = '[field_lobby]  | [field_cm_event_short_title]';
  $handler->display->display_options['fields']['field_cm_event_short_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'translation_1';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h1>[title]</h1>
';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title_1]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Event Duration */
  $handler->display->display_options['fields']['field_cm_event_duration']['id'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['table'] = 'field_data_field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['field'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['field_cm_event_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_event_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['alter']['text'] = '[field_cm_event_duration-interval]m';
  $handler->display->display_options['fields']['field_cm_event_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_event_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cm_event_duration']['click_sort_column'] = 'interval';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_cm_movie_duration']['id'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['table'] = 'field_data_field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['field'] = 'field_cm_movie_duration';
  $handler->display->display_options['fields']['field_cm_movie_duration']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_duration']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['text'] = '[field_cm_movie_duration-interval]m';
  $handler->display->display_options['fields']['field_cm_movie_duration']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_duration']['click_sort_column'] = 'interval';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_cm_event_duration';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '[field_cm_event_duration]';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_cm_event_duration]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_cm_movie_duration]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Lobby */
  $handler->display->display_options['fields']['field_lobby_1']['id'] = 'field_lobby_1';
  $handler->display->display_options['fields']['field_lobby_1']['table'] = 'field_data_field_lobby';
  $handler->display->display_options['fields']['field_lobby_1']['field'] = 'field_lobby';
  $handler->display->display_options['fields']['field_lobby_1']['label'] = '';
  $handler->display->display_options['fields']['field_lobby_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lobby_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lobby_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_lobby_1';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = '[field_lobby_1]';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[field_lobby_1]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_lobby]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
    $event_node = node_load($data->nid);
    $event_title = $event_node->title;
    if(!empty($event_node->field_cm_event_lineup[\'und\'])){
        $movie_node = node_load($event_node->field_cm_event_lineup[\'und\'][0][\'target_id\']);
        $movie_title = $movie_node->title;
        $path = drupal_get_path_alias(\'node/\'.$movie_node->nid);
        if($movie_title == $event_title){
                print \'<div class="slide-movie-title movies-title"><h2>\'. t($movie_title) .\'</h2></div>\';
        }else{
                print \'<div class="slide-movie-title events-title">\' . t($event_title) . \'</div>\';
                print \'<div class="slide-movie-title movies-title"><h2>\'. t($movie_title) .\'</h2></div>\';
        }
    }else{
        print \'<div class="slide-movie-title movies-title"><h2>\'. t($event_title) .\'</h2></div>\';
    }
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_2']['id'] = 'views_conditional_2';
  $handler->display->display_options['fields']['views_conditional_2']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_2']['if'] = 'field_main_event_credit';
  $handler->display->display_options['fields']['views_conditional_2']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional_2']['equalto'] = '[field_main_event_credit]';
  $handler->display->display_options['fields']['views_conditional_2']['then'] = '[field_main_event_credit]';
  $handler->display->display_options['fields']['views_conditional_2']['or'] = '[field_cm_movie_meta_credit]';
  $handler->display->display_options['fields']['views_conditional_2']['strip_tags'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="slide-over-content">
    <div class="slide-left-ct">
        <div class="slide-eve-lobby">[views_conditional_1]</div>
          [php_1]
        <div class="slide-movie-year">[views_conditional_2] <span class="view-bar"> [views_conditional]</span> </div>
    </div>
    <div class="slide-right-ct">
        [php]
    </div>
    <div class="ctr"></div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_cm_movie_language']['id'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['table'] = 'field_data_field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['field'] = 'field_cm_movie_language';
  $handler->display->display_options['fields']['field_cm_movie_language']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_language']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_language']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_language']['delta_offset'] = '0';
  /* Field: Content: Subtitle Languge */
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['id'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['table'] = 'field_data_field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['field'] = 'field_cm_movie_subtitle';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['relationship'] = 'field_cm_event_lineup_target_id';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cm_movie_subtitle']['delta_offset'] = '0';
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $export['event_ct_view'] = $view;

  return $export;
}
