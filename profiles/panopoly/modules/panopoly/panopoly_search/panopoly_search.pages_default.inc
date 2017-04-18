<?php
/**
 * @file
 * panopoly_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function panopoly_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panopoly_search';
  $page->task = 'page';
  $page->admin_title = 'Search Page';
  $page->admin_description = '';
  $page->path = 'search/site/!keywords';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'search content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'keywords' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_search';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Solr Search Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'css_id' => 'solr-search-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'solr',
          'settings' => NULL,
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'search_api_index',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Search',
    'panels_breadcrumbs_paths' => 'search/site',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'flexible:node_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Search Results';
  $display->uuid = 'b369b7fe-466f-4e52-b315-5070800e6d63';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_search_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3d1478d7-0f89-424e-824f-82483bc89651';
  $pane->panel = 'header';
  $pane->type = 'facet';
  $pane->subtype = 'facet';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => 'Filter by Type',
    'delta' => 'Shb0Q1vWgCArrHrjHszTyhl2jaEhIjzW',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3d1478d7-0f89-424e-824f-82483bc89651';
  $display->content['new-3d1478d7-0f89-424e-824f-82483bc89651'] = $pane;
  $display->panels['header'][0] = 'new-3d1478d7-0f89-424e-824f-82483bc89651';
  $pane = new stdClass();
  $pane->pid = 'new-15f4a1d6-8bf1-43cd-8ef3-a8b484aabe79';
  $pane->panel = 'header';
  $pane->type = 'search_current';
  $pane->subtype = 'search_current';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'node',
    'form' => 'advanced',
    'path_type' => 'default',
    'path' => '',
    'override_prompt' => FALSE,
    'prompt' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '15f4a1d6-8bf1-43cd-8ef3-a8b484aabe79';
  $display->content['new-15f4a1d6-8bf1-43cd-8ef3-a8b484aabe79'] = $pane;
  $display->panels['header'][1] = 'new-15f4a1d6-8bf1-43cd-8ef3-a8b484aabe79';
  $pane = new stdClass();
  $pane->pid = 'new-9315ef28-12fb-4ed8-a491-1c628e698406';
  $pane->panel = 'header';
  $pane->type = 'search_box';
  $pane->subtype = 'search_box';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'node',
    'form' => 'simple',
    'path_type' => 'default',
    'path' => '',
    'override_prompt' => FALSE,
    'prompt' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9315ef28-12fb-4ed8-a491-1c628e698406';
  $display->content['new-9315ef28-12fb-4ed8-a491-1c628e698406'] = $pane;
  $display->panels['header'][2] = 'new-9315ef28-12fb-4ed8-a491-1c628e698406';
  $pane = new stdClass();
  $pane->pid = 'new-25ec26bf-8e25-4163-bf5c-406fed80259d';
  $pane->panel = 'header';
  $pane->type = 'views_panes';
  $pane->subtype = 'panopoly_search-search_solr_results';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_string_1',
    ),
    'view_mode' => NULL,
    'widget_title' => '',
    'items_per_page' => NULL,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '25ec26bf-8e25-4163-bf5c-406fed80259d';
  $display->content['new-25ec26bf-8e25-4163-bf5c-406fed80259d'] = $pane;
  $display->panels['header'][3] = 'new-25ec26bf-8e25-4163-bf5c-406fed80259d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panopoly_search_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'panopoly_search';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Database Search Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'css_id' => 'database-search-panel',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Search',
    'panels_breadcrumbs_paths' => 'search/site',
    'panels_breadcrumbs_home' => 1,
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Search Results';
  $display->uuid = '2d27c2cb-916a-4d51-8a64-9eba5a57a81e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_panopoly_search_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-000335c7-2938-4a56-b2a2-421e153a409e';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-pGadwgpawEhPDsG8EB8ZiL5r1UrC6Ja8';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '000335c7-2938-4a56-b2a2-421e153a409e';
  $display->content['new-000335c7-2938-4a56-b2a2-421e153a409e'] = $pane;
  $display->panels['contentmain'][0] = 'new-000335c7-2938-4a56-b2a2-421e153a409e';
  $pane = new stdClass();
  $pane->pid = 'new-2693d0e2-3b32-4ca3-87b6-fa2ccec54399';
  $pane->panel = 'contentmain';
  $pane->type = 'search_current';
  $pane->subtype = 'search_current';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'node',
    'form' => 'advanced',
    'path_type' => 'default',
    'path' => '',
    'override_prompt' => FALSE,
    'prompt' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2693d0e2-3b32-4ca3-87b6-fa2ccec54399';
  $display->content['new-2693d0e2-3b32-4ca3-87b6-fa2ccec54399'] = $pane;
  $display->panels['contentmain'][1] = 'new-2693d0e2-3b32-4ca3-87b6-fa2ccec54399';
  $pane = new stdClass();
  $pane->pid = 'new-dbac3f16-6f98-43f5-a2b3-bb1b0dc363d9';
  $pane->panel = 'contentmain';
  $pane->type = 'search_box';
  $pane->subtype = 'search_box';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'node',
    'form' => 'simple',
    'path_type' => 'default',
    'path' => '',
    'override_prompt' => FALSE,
    'prompt' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dbac3f16-6f98-43f5-a2b3-bb1b0dc363d9';
  $display->content['new-dbac3f16-6f98-43f5-a2b3-bb1b0dc363d9'] = $pane;
  $display->panels['contentmain'][2] = 'new-dbac3f16-6f98-43f5-a2b3-bb1b0dc363d9';
  $pane = new stdClass();
  $pane->pid = 'new-33da23ef-652d-498c-8d3f-53cdff619364';
  $pane->panel = 'sidebar';
  $pane->type = 'facet';
  $pane->subtype = 'facet';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'delta' => 'fA1pg0Ubd1zgx1mvzHkFUGaNoMb4Gs0s',
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '33da23ef-652d-498c-8d3f-53cdff619364';
  $display->content['new-33da23ef-652d-498c-8d3f-53cdff619364'] = $pane;
  $display->panels['sidebar'][0] = 'new-33da23ef-652d-498c-8d3f-53cdff619364';
  $pane = new stdClass();
  $pane->pid = 'new-eb00407b-2238-4361-9a39-e937540cdfa5';
  $pane->panel = 'sidebar';
  $pane->type = 'facet';
  $pane->subtype = 'facet';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'delta' => 'AXM2f5h1FYkWf1syhGV0cP50X1jwDNcZ',
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'eb00407b-2238-4361-9a39-e937540cdfa5';
  $display->content['new-eb00407b-2238-4361-9a39-e937540cdfa5'] = $pane;
  $display->panels['sidebar'][1] = 'new-eb00407b-2238-4361-9a39-e937540cdfa5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panopoly_search'] = $page;

  return $pages;

}
