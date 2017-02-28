<?php
/**
 * @file
 * cinematheque_feature_footer_mobile_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cinematheque_feature_footer_mobile_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'footer_credit_slogan_for_mobile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'footer credit & slogan for mobile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Block: sponsor logos links (field_sponsor_logos_links) */
  $handler->display->display_options['relationships']['field_sponsor_logos_links_value']['id'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['relationships']['field_sponsor_logos_links_value']['table'] = 'field_data_field_sponsor_logos_links';
  $handler->display->display_options['relationships']['field_sponsor_logos_links_value']['field'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['relationships']['field_sponsor_logos_links_value']['delta'] = '-1';
  /* Field: Field collection item: sponsor link */
  $handler->display->display_options['fields']['field_sponsor_link']['id'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['table'] = 'field_data_field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['field'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['relationship'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['fields']['field_sponsor_link']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_link']['type'] = 'link_absolute';
  /* Field: Field collection item: sponsor logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['relationship'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_link]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'sponser_-_big',
    'image_link' => '',
  );
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor_block' => 'sponsor_block',
  );
  /* Filter criterion: Block: Internal, numeric block ID */
  $handler->display->display_options['filters']['bid']['id'] = 'bid';
  $handler->display->display_options['filters']['bid']['table'] = 'bean';
  $handler->display->display_options['filters']['bid']['field'] = 'bid';
  $handler->display->display_options['filters']['bid']['value']['value'] = '13';

  /* Display: sponser */
  $handler = $view->new_display('block', 'sponser', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor_block' => 'sponsor_block',
  );
  /* Filter criterion: Block: Internal, numeric block ID */
  $handler->display->display_options['filters']['bid']['id'] = 'bid';
  $handler->display->display_options['filters']['bid']['table'] = 'bean';
  $handler->display->display_options['filters']['bid']['field'] = 'bid';
  $handler->display->display_options['filters']['bid']['value']['value'] = '12';
  $handler->display->display_options['block_description'] = 'sponser block';

  /* Display: logo block */
  $handler = $view->new_display('block', 'logo block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: sponsor link */
  $handler->display->display_options['fields']['field_sponsor_link']['id'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['table'] = 'field_data_field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['field'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['relationship'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['fields']['field_sponsor_link']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_link']['type'] = 'link_absolute';
  /* Field: Field collection item: sponsor logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['relationship'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_link]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'height_100',
    'image_link' => '',
  );
  $handler->display->display_options['block_description'] = 'logos block';

  /* Display: sponser - festival */
  $handler = $view->new_display('block', 'sponser - festival', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor_block' => 'sponsor_block',
  );
  /* Filter criterion: Block: Internal, numeric block ID */
  $handler->display->display_options['filters']['bid']['id'] = 'bid';
  $handler->display->display_options['filters']['bid']['table'] = 'bean';
  $handler->display->display_options['filters']['bid']['field'] = 'bid';
  $handler->display->display_options['filters']['bid']['value']['value'] = '16';
  $handler->display->display_options['block_description'] = 'sponser block - festival';

  /* Display: logo block - festival */
  $handler = $view->new_display('block', 'logo block - festival', 'block_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: sponsor link */
  $handler->display->display_options['fields']['field_sponsor_link']['id'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['table'] = 'field_data_field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['field'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['relationship'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['fields']['field_sponsor_link']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_link']['type'] = 'link_absolute';
  /* Field: Field collection item: sponsor logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['relationship'] = 'field_sponsor_logos_links_value';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_link]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'height_100',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor_block' => 'sponsor_block',
  );
  /* Filter criterion: Block: Internal, numeric block ID */
  $handler->display->display_options['filters']['bid']['id'] = 'bid';
  $handler->display->display_options['filters']['bid']['table'] = 'bean';
  $handler->display->display_options['filters']['bid']['field'] = 'bid';
  $handler->display->display_options['filters']['bid']['value']['value'] = '17';
  $handler->display->display_options['block_description'] = 'logos block - festival';
  $export['footer_credit_slogan_for_mobile'] = $view;

  return $export;
}
