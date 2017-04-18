<?php
/**
 * @file
 * Theme and preprocess functions for panels and panes.
 */

/**
 * Implements template_preprocess_panels_pane().
 */
function cinemateque_preprocess_panels_pane(&$variables) { 
  if(isset($variables['content']['#entity_view_mode']['bundle']) && $variables['content']['#entity_view_mode']['bundle'] == 'lobby') { //only for lobby FPP type please:
	if(empty($variables['content']['#fieldable_panels_pane']->field_which_lobby_to_show_)) {
	  $tid = arg(2);
	  if($tid=='ipe' && !empty($variables['display'])) {
		$tid_query=split(':', $variables['display']->storage_id);
		if (!empty($tid_query[0]) && $tid_query[0]=='taxonomy_term') $tid=$tid_query[1];
	  }
	}else{
		//dpm($variables);
	  //$tid = $variables['pane']->configuration['fieldable_panels_pane']->field_which_lobby_to_show_['und'][0]['tid'];	
	  $tid = $variables['content']['field_which_lobby_to_show_']['#items'][0]['tid'];	
	}
	$display = $variables['content']['#fieldable_panels_pane']->field_select_lobby_view['und'][0]['value'];  // $display = $variables['pane']->configuration['fieldable_panels_pane']->field_select_lobby_view['und'][0]['value'];
	if($display == 'List Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_1' ,$tid); 
	}
	else if($display == 'Wide List Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_7' ,$tid); 
	}
	else if($display == 'Grid Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_2' ,$tid);  
	}
	else if($display == 'One Item Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_5' ,$tid);  
	}		
	//dpm(get_defined_vars());
	$variables['content'] = array('the_only_output' => array('#markup' => $output));

	
  }
   if(isset($variables['content']['#entity_view_mode']['bundle']) && $variables['content']['#entity_view_mode']['bundle'] == 'sub_term_lobby') { //only for lobby FPP type please:
   //dpm($variables);
   
	$display = $variables['content']['#fieldable_panels_pane']->field_select_style['und'][0]['value'];
	if(empty($variables['content']['#fieldable_panels_pane']->field_which_lobby_to_show_)) {
	  $tid = arg(2);
	  if($tid=='ipe' && !empty($variables['display'])) {
		$tid_query=split(':', $variables['display']->storage_id);
		if (!empty($tid_query[0]) && $tid_query[0]=='taxonomy_term') $tid=$tid_query[1];
	  }
	}else{
		//dpm($variables);
	  //$tid = $variables['pane']->configuration['fieldable_panels_pane']->field_which_lobby_to_show_['und'][0]['tid'];	
	  $tid = $variables['content']['field_which_lobby_to_show_']['#items'][0]['tid'];	
	}
	if($display == 'List Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_6' ,$tid); 
	}
	if($display == 'Wide List Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_12' ,$tid); 
	}
	if($display == 'One Item Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_13' ,$tid); 
	}
	if($display == 'Grid Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_4' ,$tid);  
	}	
	//dpm(get_defined_vars());
	$variables['content'] = array('the_only_output' => array('#markup' => $output));

  }
  //dpm($variables);
  if($variables['pane']->subtype == "search_api_page-search_results" ) { //add select2 to search page for exposed facets
	  $variables['content']['#attached']['js'][] = drupal_get_path('theme', 'cinemateque') . '/js/select2.min.js';
	  $variables['content']['#attached']['js'][] = drupal_get_path('theme', 'cinemateque') . '/js/search-break-facets.script.js';
	  $variables['content']['#attached']['css'][] = drupal_get_path('theme', 'cinemateque') . '/css/select2.min.css';
  }

}