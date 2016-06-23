<?php
/**
 * @file
 * Theme and preprocess functions for panels and panes.
 */

/**
 * Implements template_preprocess_panels_pane().
 */
function cinemateque_preprocess_panels_pane(&$variables) { 
  if(isset($variables['content']['#entity_view_mode']['bundle']) && $variables['content']['#entity_view_mode']['bundle'] == 'lobby') {
	
	$tid = $variables['pane']->configuration['fieldable_panels_pane']->field_which_lobby_to_show_['und'][0]['tid'];
	$display = $variables['pane']->configuration['fieldable_panels_pane']->field_select_lobby_view['und'][0]['value'];
	
	if($display == 'List Lobby View') {
	  $output = views_embed_view($name, $display_id ); //set second argument for list display
	}else{
	  $output = views_embed_view($name, $display_id ); //set second argument for grid display 
	}
	
	$variables['content'] = array('the_only_output' => array('#markup' => $output));
	//$variables['content'] = array('output' => array('#markup' => $output));
  }
}