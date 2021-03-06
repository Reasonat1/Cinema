<?php
/**
 * @file
 * Theme hooks for Radix.
 */

// Include all files from the includes directory.
$includes_path = dirname(__FILE__) . '/includes/*.inc';
foreach (glob($includes_path) as $filename) {
  require_once dirname(__FILE__) . '/includes/' . basename($filename);
}

/**
 * Implements template_preprocess_html().
 */
function radix_preprocess_html(&$variables) {
  global $base_url;

//  // Add Bootstrap JS from CDN if bootstrap library is not installed.
  if (!module_exists('bootstrap_library')) {
    $base = parse_url($base_url);
    //$url = $base['scheme'] . '://netdna.bootstrapcdn.com/bootstrap/3.1.1/js/bootstrap.min.js';
    $jquery_ui_library = drupal_get_library('system', 'ui');
    $jquery_ui_js = reset($jquery_ui_library['js']);
    drupal_add_js('/sites/all/themes/cinemateque/js/bootstrap.min.js', array(
      'type' => 'external',
      // We have to put Bootstrap after jQuery, but before jQuery UI.
      'group' => JS_LIBRARY,
      'weight' => $jquery_ui_js['weight'] - 1,
    ));
  }
  if (module_exists('path')) {
    $alias = drupal_get_path_alias(str_replace('/edit','',$_GET['q']));
    if ($alias != $_GET['q']) {
      $template_filename = 'html';              
      foreach (explode('/', $alias) as $path_part) {
       $template_filename = $template_filename . '__' . $path_part;
        $variables['theme_hook_suggestions'][] = $template_filename;
      }
    }
//    print_r($variables);
//    die;
  }
//
//  // Add support for the Modenizr module.
//  // Load modernizr.js only if modernizr module is not present.
//  if (!module_exists('modernizr')) {
//    drupal_add_js(drupal_get_path('theme', 'radix') . '/assets/js/modernizr.js');
//  }

  // Add meta for Bootstrap Responsive.
  // <meta name="viewport" content="width=device-width, initial-scale=1.0">
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );
  drupal_add_html_head($element, 'bootstrap_responsive');

  // Add some custom classes for panels pages.
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $variables['is_panel'] = TRUE;

    // Get the current panel display and add some classes to body.
    if ($display = panels_get_current_page_display()) {
      $variables['classes_array'][] = 'panel-layout-' . $display->layout;

      // Add a custom class for each region that has content.
      $regions = array_keys($display->panels);
      foreach ($regions as $region) {
        $variables['classes_array'][] = 'panel-region-' . $region;
      }
    }
  }
}

/**
 * Implements hook_css_alter().
 */
function radix_css_alter(&$css) {
  // Unset some panopoly css.
  if (module_exists('panopoly_admin')) {
    $panopoly_admin_path = drupal_get_path('module', 'panopoly_admin');
    if (isset($css[$panopoly_admin_path . '/panopoly-admin.css'])) {
      unset($css[$panopoly_admin_path . '/panopoly-admin.css']);
    }
  }

  if (module_exists('panopoly_magic')) {
    $panopoly_magic_path = drupal_get_path('module', 'panopoly_magic');
    if (isset($css[$panopoly_magic_path . '/css/panopoly-modal.css'])) {
      unset($css[$panopoly_magic_path . '/css/panopoly-modal.css']);
    }
  }

  // Unset some core css.
  unset($css['modules/system/system.menus.css']);

  // Remove radix stylesheets if it is not the default theme.
  if (variable_get('theme_default', '') != 'radix') {
    unset($css[drupal_get_path('theme', 'radix') . '/assets/css/radix.style.css']);
  }
}

/**
 * Implements hook_js_alter().
 */
function radix_js_alter(&$javascript) {
  // Add radix-modal when required.
  if (module_exists('ctools')) {
    $ctools_modal = drupal_get_path('module', 'ctools') . '/js/modal.js';
    $radix_modal = drupal_get_path('theme', 'radix') . '/assets/js/radix.modal.js';
    if (!empty($javascript[$ctools_modal]) && empty($javascript[$radix_modal])) {
      $javascript[$radix_modal] = array_merge(
        drupal_js_defaults(), array('group' => JS_THEME, 'data' => $radix_modal));
    }
  }

  // Add radix-field-slideshow when required.
  if (module_exists('field_slideshow')) {
    $field_slideshow = drupal_get_path('module', 'field_slideshow') . '/field_slideshow.js';
    $radix_field_slideshow = drupal_get_path('theme', 'radix') . '/assets/js/radix.slideshow.js';
    if (!empty($javascript[$field_slideshow]) && empty($javascript[$radix_field_slideshow])) {
      $javascript[$radix_field_slideshow] = array_merge(
        drupal_js_defaults(), array('group' => JS_THEME, 'data' => $radix_field_slideshow));
    }
  }

  // Add radix-progress when required.
  $progress = 'misc/progress.js';
  $radix_progress = drupal_get_path('theme', 'radix') . '/assets/js/radix.progress.js';
  if (!empty($javascript[$progress]) && empty($javascript[$radix_progress])) {
    $javascript[$radix_progress] = array_merge(
      drupal_js_defaults(), array('group' => JS_THEME, 'data' => $radix_progress));
  }
  
}

/**
 * Implements template_preprocess_page().
 */
function radix_preprocess_page(&$variables) {
  // Determine if the page is rendered using panels.
  $variables['is_panel'] = FALSE;
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $variables['is_panel'] = TRUE;
  }

  // Make sure tabs is empty.
  if (empty($variables['tabs']['#primary']) && empty($variables['tabs']['#secondary'])) {
    $variables['tabs'] = '';
  }

  // Theme action links as buttons.
  if (!empty($variables['action_links'])) {
    foreach (element_children($variables['action_links']) as $key) {
      $variables['action_links'][$key]['#link']['localized_options']['attributes'] = array(
        'class' => array('btn', 'btn-primary', 'btn-sm'),
      );
    }
  }

  // Add search_form to theme.
  $variables['search_form'] = '';
  if (module_exists('search') && user_access('search content')) {
    $search_box_form = drupal_get_form('search_form');
    $search_box_form['basic']['keys']['#title'] = 'Search';
    $search_box_form['basic']['keys']['#title_display'] = 'invisible';
    $search_box_form['basic']['keys']['#size'] = 20;
    $search_box_form['basic']['keys']['#attributes'] = array('placeholder' => 'Search');
    $search_box_form['basic']['keys']['#attributes']['class'][] = 'form-control';
    $search_box_form['basic']['submit']['#value'] = t('Search');
    $search_box_form['#attributes']['class'][] = 'navbar-form';
    $search_box_form['#attributes']['class'][] = 'navbar-right';
    $search_box = drupal_render($search_box_form);
    $variables['search_form'] = (user_access('search content')) ? $search_box : NULL;
  }

  // Format and add main menu to theme.
  $variables['main_menu'] = _radix_dropdown_menu_tree(variable_get('menu_main_links_source', 'main-menu'), array(
    'min_depth' => 1,
    'max_depth' => 2,
  ));
   // Format and add site main menu to theme.
  $variables['site_main_menu'] = _radix_dropdown_menu_tree(variable_get('menu-site-main-menu_links_source', 'menu-site-main-menu'), array(
    'min_depth' => 1,
    'max_depth' => 2,
  ));
    $variables['festival_site_main_menu'] = _radix_dropdown_menu_tree(variable_get('menu-site-main-menu_links_source', 'cinematic-festival-12'), array(
    'min_depth' => 1,
    'max_depth' => 2,
  ));
// if ternonmy page is views
    global $base_url;
    global $_domain;
	$term_tid = db_query("SELECT `entity_id` FROM `field_data_field_cm_domain` WHERE `field_cm_domain_value` = :did",array(':did' => $_domain['domain_id']))->fetchField();
	
    $output = "";
    $variables['festival_site_info']  = "";
	
	if($term = taxonomy_term_load($term_tid)) {
		$menu = $term->cinematic_menu;
		$name = $term->name;
		$domain = isset($term->field_cm_domain['und'][0]['value']) ? $term->field_cm_domain['und'][0]['value'] : 1;
		$logo_image = $term->field_cm_festival_logo;
		
		$date = isset($term->field_cm_festival_date['und'][0]['value']) ? strtotime($term->field_cm_festival_date['und'][0]['value']) : '';
		$date2 = isset($term->field_cm_festival_date['und'][0]['value2']) ? strtotime($term->field_cm_festival_date['und'][0]['value2']) : '';
		if(date('m',$date) == date('m',$date2)) {
		  $festivaldates = date('d',$date) . date('-d',$date2) . date('.m.Y',$date2);
		}else{
		  $festivaldates = date('d.m',$date) . date('-d.m',$date2) . date('.Y',$date2);
		}
		//if(!empty($date)){
			//$date = date('d-m.Y',$date);
		//}
		if(!empty($logo_image)){
			$logo_image =$base_url.'/sites/default/files/'.$logo_image['und'][0]['filename'];	
			$variables['festival_site_logo'] = $logo_image;
		}
/*
		$output = "<div class='festival-site'>";
		$output.= "<span class='festive-site-name'>". t($name) ."</span>";
		$output.= "<span class='festive-time'>$festivaldates</span>";
		$output.= "</div>";*/
		$variables['festival_site_info'] = $output;

		// render festival accssociated menu
		if($menu != ''){
		   $menu_source =$menu.'_links_source';
		   $variables['festival_site_menu'] = _radix_dropdown_menu_tree(variable_get($menu_source, $menu), array(
			   'min_depth' => 1,
			   'max_depth' => 2,
			 ));
		}
		
	}

	/*
    $term_page =  arg(0);
    if($term_page == 'taxonomy'){
         $tid =arg(2);
        $texonomy = taxonomy_term_load($tid);
        $menu = $texonomy->cinematic_menu;
        $festival_date = isset($texonomy->field_cm_festival_date['und'][0]['value']) ? $texonomy->field_cm_festival_date['und'][0]['value'] : '';
        $name = $texonomy->name;
        $domain = isset($texonomy->field_cm_domain['und'][0]['value']) ? $texonomy->field_cm_domain['und'][0]['value'] : 1;
        $logo_image = $texonomy->field_cm_festival_logo;
        // this is static for now( $domain = 1 means primary domain)
        $date = '';
        if($festival_date != ''){
            $date = date('d-m.Y',strtotime($festival_date));
        }
       
        if($_domain['is_default'] != '1'  && $domain == $_domain['domain_id']){
                if(!empty($logo_image)){
                    $logo_image =$base_url.'/sites/default/files/'.$logo_image['und'][0]['filename'];	
                    $variables['festival_site_logo'] = $logo_image;
                }
        
                $output = "<div class='festival-site'>";
                $output.="   <span class='festive-site-name'>$name</span>";
                $output.="   <span class='festive-time'>$date</span>";
                $output.= "</div>";
                $variables['festival_site_info'] =$output;
                    
                // texonomy accssociated menu
                if($menu != ''){
                   $menu_source =$menu.'_links_source';
                   $variables['festival_site_menu'] = _radix_dropdown_menu_tree(variable_get($menu_source, $menu), array(
                       'min_depth' => 1,
                       'max_depth' => 2,
                     ));
                }
        }

    }
    
        if(!empty($variables['node'])){

            global $_domain;
            $domains = $variables['node']->domains;
            foreach($domains as $domain){
                if($_domain['domain_id'] == $domain){
                    $term_tid = db_query("SELECT `entity_id` FROM `field_data_field_cm_domain` WHERE `field_cm_domain_value` =$domain ")->fetchField();
                    break;
                }
            }
            if($_domain['is_default'] != '1' && $term_tid != ''){
                $texonomy = taxonomy_term_load($term_tid);
                $menu = $texonomy->cinematic_menu;
                $name = $texonomy->name;
                $domain = isset($texonomy->field_cm_domain['und'][0]['value']) ? $texonomy->field_cm_domain['und'][0]['value'] : 1;
                $logo_image = $texonomy->field_cm_festival_logo;
                $date = isset($texonomy->field_cm_festival_date['und'][0]['value']) ? $texonomy->field_cm_festival_date['und'][0]['value'] : '';
                if(!empty($date)){
                    $date = date('d-m.Y',$date);
                }
                if(!empty($logo_image)){
                    $logo_image =$base_url.'/sites/default/files/'.$logo_image['und'][0]['filename'];	
                    $variables['festival_site_logo'] = $logo_image;
                }

                $output = "<div class='festival-site'>";
                $output.="   <span class='festive-site-name'>$name</span>";
                $output.="   <span class='festive-time'>$date</span>";
                $output.= "</div>";
                $variables['festival_site_info'] =$output;

                // texonomy accssociated menu
                if($menu != ''){
                   $menu_source =$menu.'_links_source';
                   $variables['festival_site_menu'] = _radix_dropdown_menu_tree(variable_get($menu_source, $menu), array(
                       'min_depth' => 1,
                       'max_depth' => 2,
                     ));
                }
            }
    }*/
  // Add a copyright message.
  //$variables['copyright'] = t('Drupal is a registered trademark of Dries Buytaert.');
  $theme_path = drupal_get_path('theme', $GLOBALS['theme']);
  $stylesheet_path = '/'.$theme_path . '/css/domain-'.$_domain['domain_id'].'.css';
  if (!file_exists('/'.$stylesheet_path)) {
	//dpm($stylesheet_path . ' is missing but we try to load it for this domain. please create scss file and use compass watch to generate css file');
  }else{
    drupal_add_css('/'.$stylesheet_path);
  }
  // Display a message if Sass has not been compiled.
//  $theme_path = drupal_get_path('theme', $GLOBALS['theme']);
//  $stylesheet_path = $theme_path . '/assets/stylesheets/screen.css';
//  if (_radix_current_theme() == 'radix') {
//    $stylesheet_path = $theme_path . '/assets/stylesheets/radix-style.css';
//  }
//  if (!file_exists($stylesheet_path)) {
//    drupal_set_message(t('It looks like %path has not been created yet. Run <code>@command</code> in your theme directory to create it.', array(
//      '%path' => $stylesheet_path,
//      '@command' => 'compass watch',
//    )), 'error');
//  }
}
