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
					if(empty($movienode->field_cm_movie_pictures) && empty($movienode->field_cm_moviegroup_pictures)) $variables['classes_array'][] = 'noheaderimage';	
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
    if($term->vocabulary_machine_name == 'tags' && empty($term->field_image_term)) $variables['classes_array'][] = 'noheaderimage';  
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
    $header = drupal_get_http_header("status");
    if($header == "404 Not Found") {
        $vars['theme_hook_suggestions'][] = 'page__404';
    }
    if($header == "403 Forbidden") {
        $vars['theme_hook_suggestions'][] = 'node__403';
    }
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
      global $language;
      $lang  = $language->language;
      if ($lang == 'en') {
          $vars['nav_title'] = date('l | d.m.y', strtotime($vars['nav_title']));
      }
      if ($lang == 'he') {
          
          $vars['nav_title'] =(isset($_GET['date']))? format_date(strtotime($_GET['date']), 'custom', 'l | d.m.y'):format_date(time(), 'custom', 'l | d.m.y');
      }
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

function cinemateque_form_user_profile_form_alter(&$form, $form_state) {
   unset($form['locale']);
}

function cinemateque_metatag_pattern_alter(&$pattern, &$types, $tag_name) {
	if (!empty($types['node']->type) && $types['node']->type=='cm_event') {
	$replacement_array=array(
	'field_cm_event_short_description'=>array('cm_movie'=>'field_cm_movie_short_summary', 'cm_movie_group'=>'field_cm_moviegroup_short_summar'), 
	'field_cm_event_images'=>array('cm_movie'=>'field_cm_movie_pictures', 'cm_movie_group'=>'field_cm_moviegroup_pictures'),
	);
	foreach ($replacement_array as $key=>$value){
		if (empty($types['node']->$key) && !empty($types['node']->field_cm_event_lineup['und'])){
			$myNode=node_load($types['node']->field_cm_event_lineup['und'][0]['target_id']);
			$types['node']->$key = $myNode->$value[$myNode->type];
		}
	  }
	}
}

function cinemateque_node_view_alter(&$build) {
	if (!empty($build['field_cm_event_lineup']) && !empty($build['field_cm_event_lineup'][0]['node']) && drupal_is_front_page()){
		$target_id=$build['field_cm_event_lineup']['#items'][0]['target_id'];
		$build['field_cm_event_lineup'][0]['node'][$target_id]['#parentTitle']=$build['field_cm_event_lineup']['#object']->title; 
	}
}

function cinemateque_form_user_login_block_alter(&$form) {
  $newlinks = l(t('Forgotten password?'), 'user/password');
  $form['links']['#markup'] = $newlinks;

  return $form;
}



