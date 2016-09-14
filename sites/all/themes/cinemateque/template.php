<?php
/**
 * @file
 * Theme functions
 */

// Include all files from the includes directory.
$includes_path = dirname(__FILE__) . '/includes/*.inc';
foreach (glob($includes_path) as $filename) {
  require_once dirname(__FILE__) . '/includes/' . basename($filename);
}

/**
 * Implements template_preprocess_html().
 */
function cinemateque_preprocess_html(&$variables) {
	if ($node = menu_get_object()) {
	    switch($node->type) {
		  case 'cm_event':
			drupal_add_js(drupal_get_path('module', 'my_utilities') . '/include/my_utilities.js');
			if(empty($node->field_cm_event_images)) {
			  if(!empty($node->field_cm_event_lineup)) {
				if($movienode = node_load($node->field_cm_event_lineup['und'][0]['target_id'])) {
					if(empty($movienode->field_cm_movie_pictures)) $variables['classes_array'][] = 'noheaderimage';	
				}
			  
			  }else{
				$variables['classes_array'][] = 'noheaderimage';	
			  }
			  
			}
		  break;
		  case 'cm_article':
			if(empty($node->field_cm_article_image)) $variables['classes_array'][] = 'noheaderimage';
		  break;
		  case 'cm_movie':
			drupal_add_js(drupal_get_path('module', 'my_utilities') . '/include/my_utilities.js');
			if(empty($node->field_cm_movie_pictures)) $variables['classes_array'][] = 'noheaderimage';
		  break;
		  case 'cm_movie_group':
			drupal_add_js(drupal_get_path('module', 'my_utilities') . '/include/my_utilities.js');
			if(empty($node->field_cm_moviegroup_pictures)) $variables['classes_array'][] = 'noheaderimage';
		  break;
		  default:
		  
		  break;
	    }
	}
	
	if(arg(0) == 'taxonomy' && arg(1) == 'term' && $term = taxonomy_term_load(arg(2))) {
		if($term->vocabulary_machine_name == 'lobby' && empty($term->field_cm_lobby_media)) $variables['classes_array'][] = 'noheaderimage';	
	}
}
/**
 * Implements template_preprocess_page().
 */
function cinemateque_preprocess_page(&$variables) {
  // Add copyright to theme.
  if ($copyright = theme_get_setting('copyright')) {
    $variables['copyright'] = check_markup($copyright['value'], $copyright['format']);
  }
  /*  if(('3261' == arg(1)) || ('3284' == arg(1))){
    drupal_add_js('sites/all/themes/cinemateque/js/jquery-scrolltofixed-min.js');
  }*/
}

function cinemateque_preprocess_views_view(&$vars) {
  $view = &$vars['view'];
  // Make sure it's the correct view
  if ($view->name == 'lobby') {
    // add needed javascript
    drupal_add_js(drupal_get_path('module', 'cinematic_toptix') . '/esrojsapi.js');
    drupal_add_js(drupal_get_path('module', 'cinematic_toptix') . '/frame.js');      
  }
}
function cinemateque_preprocess_date_views_pager(&$vars) {
  if($vars['plugin']->view->name=='custom_calendar_floating_pane'){
	$vars['nav_title'] = date('l | d.m.y', strtotime($vars['nav_title']));
  } 
}

function cinemateque_facetapi_select_select_option($variables) {
  if ($variables['show_count']) {
    $variables['facet_text'] .= ' (' . $variables['facet_count'] . ')';
  }
  return $variables;
}

function cinemateque_form_facetapi_select_facet_form_alter(&$form, &$form_state, $form_id) {
  //return;
  if ($form['facets']['#options']) {
    $default_value = array();
    foreach ($form['facets']['#options'] as $key => &$value) {
      if ($value['is_active']) {
        $default_value[] = $key;
      }
      $value = $value['facet_text'];
    }
    if ($default_value) {
      $form['facets']['#default_value'] = $default_value;
    }
  }
  $form['facets']['#empty_option'] = $form['facets']['#empty_option']['facet_text'];
}
