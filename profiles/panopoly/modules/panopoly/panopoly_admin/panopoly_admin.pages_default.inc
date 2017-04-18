<?php
/**
 * @file
 * panopoly_admin.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function panopoly_admin_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Node Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '56f6d0a5-d0cb-4670-8442-80de25b84871';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-73569090-5f67-47b1-b6a5-634bc8104c2b';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '73569090-5f67-47b1-b6a5-634bc8104c2b';
  $display->content['new-73569090-5f67-47b1-b6a5-634bc8104c2b'] = $pane;
  $display->panels['contentmain'][0] = 'new-73569090-5f67-47b1-b6a5-634bc8104c2b';
  $pane = new stdClass();
  $pane->pid = 'new-17fa67de-e033-46f2-bdd8-a138e91da0e4';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_path';
  $pane->subtype = 'node_form_path';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '17fa67de-e033-46f2-bdd8-a138e91da0e4';
  $display->content['new-17fa67de-e033-46f2-bdd8-a138e91da0e4'] = $pane;
  $display->panels['contentmain'][1] = 'new-17fa67de-e033-46f2-bdd8-a138e91da0e4';
  $pane = new stdClass();
  $pane->pid = 'new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $display->content['new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52'] = $pane;
  $display->panels['contentmain'][2] = 'new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $pane = new stdClass();
  $pane->pid = 'new-2b19ae77-1787-49d2-be6e-c9b5aa01ad68';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_toptix_purchase';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2b19ae77-1787-49d2-be6e-c9b5aa01ad68';
  $display->content['new-2b19ae77-1787-49d2-be6e-c9b5aa01ad68'] = $pane;
  $display->panels['sidebar'][0] = 'new-2b19ae77-1787-49d2-be6e-c9b5aa01ad68';
  $pane = new stdClass();
  $pane->pid = 'new-9c288e22-d43e-4cc4-beab-7de46c7af341';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_alt_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9c288e22-d43e-4cc4-beab-7de46c7af341';
  $display->content['new-9c288e22-d43e-4cc4-beab-7de46c7af341'] = $pane;
  $display->panels['sidebar'][1] = 'new-9c288e22-d43e-4cc4-beab-7de46c7af341';
  $pane = new stdClass();
  $pane->pid = 'new-2240c071-cc17-4e20-9f53-e525edb38a98';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_org_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2240c071-cc17-4e20-9f53-e525edb38a98';
  $display->content['new-2240c071-cc17-4e20-9f53-e525edb38a98'] = $pane;
  $display->panels['sidebar'][2] = 'new-2240c071-cc17-4e20-9f53-e525edb38a98';
  $pane = new stdClass();
  $pane->pid = 'new-403775f0-07dc-4ca4-9a14-6ba8d3926990';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_duration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '403775f0-07dc-4ca4-9a14-6ba8d3926990';
  $display->content['new-403775f0-07dc-4ca4-9a14-6ba8d3926990'] = $pane;
  $display->panels['sidebar'][3] = 'new-403775f0-07dc-4ca4-9a14-6ba8d3926990';
  $pane = new stdClass();
  $pane->pid = 'new-14f1a30e-1f20-46ca-8a21-a680b010fe5e';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_internal_id';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '14f1a30e-1f20-46ca-8a21-a680b010fe5e';
  $display->content['new-14f1a30e-1f20-46ca-8a21-a680b010fe5e'] = $pane;
  $display->panels['sidebar'][4] = 'new-14f1a30e-1f20-46ca-8a21-a680b010fe5e';
  $pane = new stdClass();
  $pane->pid = 'new-c00bdaee-bcc1-45a3-a625-3228ac959509';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_showid';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'c00bdaee-bcc1-45a3-a625-3228ac959509';
  $display->content['new-c00bdaee-bcc1-45a3-a625-3228ac959509'] = $pane;
  $display->panels['sidebar'][5] = 'new-c00bdaee-bcc1-45a3-a625-3228ac959509';
  $pane = new stdClass();
  $pane->pid = 'new-9fc31a64-67e2-458a-98cf-c32a1bdbae71';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_distributor';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '9fc31a64-67e2-458a-98cf-c32a1bdbae71';
  $display->content['new-9fc31a64-67e2-458a-98cf-c32a1bdbae71'] = $pane;
  $display->panels['sidebar'][6] = 'new-9fc31a64-67e2-458a-98cf-c32a1bdbae71';
  $pane = new stdClass();
  $pane->pid = 'new-fc517825-167d-4507-a88a-be83eb69c20a';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_internal_id';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'fc517825-167d-4507-a88a-be83eb69c20a';
  $display->content['new-fc517825-167d-4507-a88a-be83eb69c20a'] = $pane;
  $display->panels['sidebar'][7] = 'new-fc517825-167d-4507-a88a-be83eb69c20a';
  $pane = new stdClass();
  $pane->pid = 'new-f1482ead-ed59-4f17-83eb-d5707400860d';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_time';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'f1482ead-ed59-4f17-83eb-d5707400860d';
  $display->content['new-f1482ead-ed59-4f17-83eb-d5707400860d'] = $pane;
  $display->panels['sidebar'][8] = 'new-f1482ead-ed59-4f17-83eb-d5707400860d';
  $pane = new stdClass();
  $pane->pid = 'new-200a66d3-7075-4b41-8be7-582850682feb';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_lobby';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '200a66d3-7075-4b41-8be7-582850682feb';
  $display->content['new-200a66d3-7075-4b41-8be7-582850682feb'] = $pane;
  $display->panels['sidebar'][9] = 'new-200a66d3-7075-4b41-8be7-582850682feb';
  $pane = new stdClass();
  $pane->pid = 'new-3b6ea85d-90c3-411c-83db-c209f8752251';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_duration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '3b6ea85d-90c3-411c-83db-c209f8752251';
  $display->content['new-3b6ea85d-90c3-411c-83db-c209f8752251'] = $pane;
  $display->panels['sidebar'][10] = 'new-3b6ea85d-90c3-411c-83db-c209f8752251';
  $pane = new stdClass();
  $pane->pid = 'new-373bd769-1e08-4ec5-85b6-0a1d2fc759fd';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Featured image',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '373bd769-1e08-4ec5-85b6-0a1d2fc759fd';
  $display->content['new-373bd769-1e08-4ec5-85b6-0a1d2fc759fd'] = $pane;
  $display->panels['sidebar'][11] = 'new-373bd769-1e08-4ec5-85b6-0a1d2fc759fd';
  $pane = new stdClass();
  $pane->pid = 'new-51126c95-cf51-4ad6-a27a-11e4260d8023';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Content category',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '51126c95-cf51-4ad6-a27a-11e4260d8023';
  $display->content['new-51126c95-cf51-4ad6-a27a-11e4260d8023'] = $pane;
  $display->panels['sidebar'][12] = 'new-51126c95-cf51-4ad6-a27a-11e4260d8023';
  $pane = new stdClass();
  $pane->pid = 'new-e38ab3a3-24d0-4ac2-900e-4ddb0248be0c';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = 'e38ab3a3-24d0-4ac2-900e-4ddb0248be0c';
  $display->content['new-e38ab3a3-24d0-4ac2-900e-4ddb0248be0c'] = $pane;
  $display->panels['sidebar'][13] = 'new-e38ab3a3-24d0-4ac2-900e-4ddb0248be0c';
  $pane = new stdClass();
  $pane->pid = 'new-db628ef7-e4e6-43e4-a63d-3bce32c86485';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_language';
  $pane->subtype = 'node_form_language';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = 'db628ef7-e4e6-43e4-a63d-3bce32c86485';
  $display->content['new-db628ef7-e4e6-43e4-a63d-3bce32c86485'] = $pane;
  $display->panels['sidebar'][14] = 'new-db628ef7-e4e6-43e4-a63d-3bce32c86485';
  $pane = new stdClass();
  $pane->pid = 'new-0fb5af46-1850-4936-826f-eba3d21d8a19';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_include_ticket_sale';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '0fb5af46-1850-4936-826f-eba3d21d8a19';
  $display->content['new-0fb5af46-1850-4936-826f-eba3d21d8a19'] = $pane;
  $display->panels['sidebar'][15] = 'new-0fb5af46-1850-4936-826f-eba3d21d8a19';
  $pane = new stdClass();
  $pane->pid = 'new-66dea124-e365-4e5d-b2dd-7cb583b17e33';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_onsale';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = '66dea124-e365-4e5d-b2dd-7cb583b17e33';
  $display->content['new-66dea124-e365-4e5d-b2dd-7cb583b17e33'] = $pane;
  $display->panels['sidebar'][16] = 'new-66dea124-e365-4e5d-b2dd-7cb583b17e33';
  $pane = new stdClass();
  $pane->pid = 'new-8f0f666e-db1a-4c1e-b0f8-db747dcdba1a';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_format';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 17;
  $pane->locks = array();
  $pane->uuid = '8f0f666e-db1a-4c1e-b0f8-db747dcdba1a';
  $display->content['new-8f0f666e-db1a-4c1e-b0f8-db747dcdba1a'] = $pane;
  $display->panels['sidebar'][17] = 'new-8f0f666e-db1a-4c1e-b0f8-db747dcdba1a';
  $pane = new stdClass();
  $pane->pid = 'new-7800d412-c5aa-4938-bfd9-00eb60d80e50';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 18;
  $pane->locks = array();
  $pane->uuid = '7800d412-c5aa-4938-bfd9-00eb60d80e50';
  $display->content['new-7800d412-c5aa-4938-bfd9-00eb60d80e50'] = $pane;
  $display->panels['sidebar'][18] = 'new-7800d412-c5aa-4938-bfd9-00eb60d80e50';
  $pane = new stdClass();
  $pane->pid = 'new-11436dec-9ca9-4d0a-9c5b-c217d4571b3a';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_movie_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 19;
  $pane->locks = array();
  $pane->uuid = '11436dec-9ca9-4d0a-9c5b-c217d4571b3a';
  $display->content['new-11436dec-9ca9-4d0a-9c5b-c217d4571b3a'] = $pane;
  $display->panels['sidebar'][19] = 'new-11436dec-9ca9-4d0a-9c5b-c217d4571b3a';
  $pane = new stdClass();
  $pane->pid = 'new-3366b07e-34f9-49f4-a9d5-cc65af3abb2b';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_movie_key_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 20;
  $pane->locks = array();
  $pane->uuid = '3366b07e-34f9-49f4-a9d5-cc65af3abb2b';
  $display->content['new-3366b07e-34f9-49f4-a9d5-cc65af3abb2b'] = $pane;
  $display->panels['sidebar'][20] = 'new-3366b07e-34f9-49f4-a9d5-cc65af3abb2b';
  $pane = new stdClass();
  $pane->pid = 'new-1ca80abc-261e-430c-86e2-53c28832b6dd';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_hide_calendar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 21;
  $pane->locks = array();
  $pane->uuid = '1ca80abc-261e-430c-86e2-53c28832b6dd';
  $display->content['new-1ca80abc-261e-430c-86e2-53c28832b6dd'] = $pane;
  $display->panels['sidebar'][21] = 'new-1ca80abc-261e-430c-86e2-53c28832b6dd';
  $pane = new stdClass();
  $pane->pid = 'new-52531d69-c1e2-42e8-b0ea-34ae35867900';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_event_hall';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 22;
  $pane->locks = array();
  $pane->uuid = '52531d69-c1e2-42e8-b0ea-34ae35867900';
  $display->content['new-52531d69-c1e2-42e8-b0ea-34ae35867900'] = $pane;
  $display->panels['sidebar'][22] = 'new-52531d69-c1e2-42e8-b0ea-34ae35867900';
  $pane = new stdClass();
  $pane->pid = 'new-99f6c0bd-36fd-411b-9833-c0be0fab7548';
  $pane->panel = 'sidebar';
  $pane->type = 'panelizer_form_default';
  $pane->subtype = 'panelizer_form_default';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 23;
  $pane->locks = array();
  $pane->uuid = '99f6c0bd-36fd-411b-9833-c0be0fab7548';
  $display->content['new-99f6c0bd-36fd-411b-9833-c0be0fab7548'] = $pane;
  $display->panels['sidebar'][23] = 'new-99f6c0bd-36fd-411b-9833-c0be0fab7548';
  $pane = new stdClass();
  $pane->pid = 'new-9176b962-e64f-44a6-8ebe-e03ebf0f6c3d';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 24;
  $pane->locks = array();
  $pane->uuid = '9176b962-e64f-44a6-8ebe-e03ebf0f6c3d';
  $display->content['new-9176b962-e64f-44a6-8ebe-e03ebf0f6c3d'] = $pane;
  $display->panels['sidebar'][24] = 'new-9176b962-e64f-44a6-8ebe-e03ebf0f6c3d';
  $pane = new stdClass();
  $pane->pid = 'new-6e4a98d8-3738-41b9-8c33-4b4c905c6834';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_author';
  $pane->subtype = 'node_form_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 25;
  $pane->locks = array();
  $pane->uuid = '6e4a98d8-3738-41b9-8c33-4b4c905c6834';
  $display->content['new-6e4a98d8-3738-41b9-8c33-4b4c905c6834'] = $pane;
  $display->panels['sidebar'][25] = 'new-6e4a98d8-3738-41b9-8c33-4b4c905c6834';
  $pane = new stdClass();
  $pane->pid = 'new-e5080753-0b31-4e21-be4b-5d6870ab6074';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_search_additions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 26;
  $pane->locks = array();
  $pane->uuid = 'e5080753-0b31-4e21-be4b-5d6870ab6074';
  $display->content['new-e5080753-0b31-4e21-be4b-5d6870ab6074'] = $pane;
  $display->panels['sidebar'][26] = 'new-e5080753-0b31-4e21-be4b-5d6870ab6074';
  $pane = new stdClass();
  $pane->pid = 'new-891d3a14-8138-42bc-b229-26d60d68f9bc';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_movie_group_top_text_black';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 27;
  $pane->locks = array();
  $pane->uuid = '891d3a14-8138-42bc-b229-26d60d68f9bc';
  $display->content['new-891d3a14-8138-42bc-b229-26d60d68f9bc'] = $pane;
  $display->panels['sidebar'][27] = 'new-891d3a14-8138-42bc-b229-26d60d68f9bc';
  $pane = new stdClass();
  $pane->pid = 'new-6d31d3e4-de44-46c4-bc4a-622f86c8c45f';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_movie_group_top_text_white';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 28;
  $pane->locks = array();
  $pane->uuid = '6d31d3e4-de44-46c4-bc4a-622f86c8c45f';
  $display->content['new-6d31d3e4-de44-46c4-bc4a-622f86c8c45f'] = $pane;
  $display->panels['sidebar'][28] = 'new-6d31d3e4-de44-46c4-bc4a-622f86c8c45f';
  $pane = new stdClass();
  $pane->pid = 'new-eb062275-f67a-4752-8333-1b7e3d54d470';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_cm_moviegroup_tags';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 29;
  $pane->locks = array();
  $pane->uuid = 'eb062275-f67a-4752-8333-1b7e3d54d470';
  $display->content['new-eb062275-f67a-4752-8333-1b7e3d54d470'] = $pane;
  $display->panels['sidebar'][29] = 'new-eb062275-f67a-4752-8333-1b7e3d54d470';
  $pane = new stdClass();
  $pane->pid = 'new-3c2861bd-34a6-4cbf-a6db-58fe49f33ce9';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:cer_settings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 30;
  $pane->locks = array();
  $pane->uuid = '3c2861bd-34a6-4cbf-a6db-58fe49f33ce9';
  $display->content['new-3c2861bd-34a6-4cbf-a6db-58fe49f33ce9'] = $pane;
  $display->panels['sidebar'][30] = 'new-3c2861bd-34a6-4cbf-a6db-58fe49f33ce9';
  $pane = new stdClass();
  $pane->pid = 'new-76ed9453-9018-4cf2-bb89-c24175445bcc';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:cer_store_settings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 31;
  $pane->locks = array();
  $pane->uuid = '76ed9453-9018-4cf2-bb89-c24175445bcc';
  $display->content['new-76ed9453-9018-4cf2-bb89-c24175445bcc'] = $pane;
  $display->panels['sidebar'][31] = 'new-76ed9453-9018-4cf2-bb89-c24175445bcc';
  $pane = new stdClass();
  $pane->pid = 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 32;
  $pane->locks = array();
  $pane->uuid = 'c0926cca-059c-4bb1-bccd-2838ec7a93f2';
  $display->content['new-c0926cca-059c-4bb1-bccd-2838ec7a93f2'] = $pane;
  $display->panels['sidebar'][32] = 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fb4920fb-24fa-425e-b6fc-958b5ccd2d52';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function panopoly_admin_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_admin_layout_library';
  $page->task = 'page';
  $page->admin_title = 'Panopoly Layouts';
  $page->admin_description = 'This is the page library that manages page layouts.';
  $page->path = 'admin/panopoly/layouts';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access administration pages',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer panels layouts',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panopoly Layouts',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_admin_layout_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_admin_layout_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Layout Library',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'layout-library',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Layout Library';
  $display->uuid = '2a4bbcf3-712e-44e2-9fd8-270a2fd6e47d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_admin_layout_library_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c481f523-51bb-40ff-99d3-648dc19100a5';
  $pane->panel = 'contentmain';
  $pane->type = 'panels_layouts';
  $pane->subtype = 'panels_layouts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c481f523-51bb-40ff-99d3-648dc19100a5';
  $display->content['new-c481f523-51bb-40ff-99d3-648dc19100a5'] = $pane;
  $display->panels['contentmain'][0] = 'new-c481f523-51bb-40ff-99d3-648dc19100a5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_admin_layout_library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_admin_page_library';
  $page->task = 'page';
  $page->admin_title = 'Panopoly Pages';
  $page->admin_description = 'This is the page library that manages page templates, landing pages, and overridden pages.';
  $page->path = 'admin/panopoly/pages';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access administration pages',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'use page manager',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panopoly Pages',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_admin_page_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_admin_page_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Page Library',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'page-library',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page Library';
  $display->uuid = '7f2efae5-50a7-4f07-b1f7-f8edc2dd9326';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_admin_page_library_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b63313b3-8b80-4161-a97d-78439cda58f9';
  $pane->panel = 'contentmain';
  $pane->type = 'landing_pages';
  $pane->subtype = 'landing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b63313b3-8b80-4161-a97d-78439cda58f9';
  $display->content['new-b63313b3-8b80-4161-a97d-78439cda58f9'] = $pane;
  $display->panels['contentmain'][0] = 'new-b63313b3-8b80-4161-a97d-78439cda58f9';
  $pane = new stdClass();
  $pane->pid = 'new-a19a23d5-56e9-48a3-82f2-bbdf49d4b929';
  $pane->panel = 'contentmain';
  $pane->type = 'overridden_page_templates';
  $pane->subtype = 'overridden_page_templates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a19a23d5-56e9-48a3-82f2-bbdf49d4b929';
  $display->content['new-a19a23d5-56e9-48a3-82f2-bbdf49d4b929'] = $pane;
  $display->panels['contentmain'][1] = 'new-a19a23d5-56e9-48a3-82f2-bbdf49d4b929';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_admin_page_library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_admin_pane_library';
  $page->task = 'page';
  $page->admin_title = 'Panopoly Panes';
  $page->admin_description = 'This is the pane library for the site. See all of the panes you can add to your pages.';
  $page->path = 'admin/panopoly/panes';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access administration pages',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer page manager',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panopoly Panes',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Dashboard',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_admin_pane_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_admin_pane_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Pane Library',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'pane-library',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Pane Library';
  $display->uuid = '195ed3e8-b724-48fd-9057-9f5f54aa6a47';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_admin_pane_library_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a';
  $pane->panel = 'contentmain';
  $pane->type = 'general_panes';
  $pane->subtype = 'general_panes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a';
  $display->content['new-ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a'] = $pane;
  $display->panels['contentmain'][0] = 'new-ad96a6eb-e0f3-44c3-b4ef-5d359f13c21a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_admin_pane_library'] = $page;

  return $pages;

}
