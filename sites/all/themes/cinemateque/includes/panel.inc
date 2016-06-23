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
	}else{
	  $tid = $variables['pane']->configuration['fieldable_panels_pane']->field_which_lobby_to_show_['und'][0]['tid'];	
	}
	//dpm($variables['content']['#fieldable_panels_pane']);
	
	$display = $variables['content']['#fieldable_panels_pane']->field_select_lobby_view['und'][0]['value'];  // $display = $variables['pane']->configuration['fieldable_panels_pane']->field_select_lobby_view['und'][0]['value'];
	
	if($display == 'List Lobby View') {
	  $output = views_embed_view('lobby', 'panel_pane_1' ,($tid)); //set second argument for list display
	}else{
	  $output = views_embed_view('lobby', 'panel_pane_2' ,($tid)); //set second argument for grid display 
	}
	//dpm(get_defined_vars());
	$variables['content'] = array('the_only_output' => array('#markup' => $output));
	//$variables['content'] = array('output' => array('#markup' => $output));
  }
}