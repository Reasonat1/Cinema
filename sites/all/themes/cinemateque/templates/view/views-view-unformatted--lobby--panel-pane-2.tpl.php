<?php
/**
 * @file views-exposed-form.tpl.php
 *
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php
  $results=$view->result;
  foreach ($results as $val) {
    $nid = $val->node_taxonomy_index_nid;
    $node = node_load($nid);
    $default_image = '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
     //drupal_set_message('<pre>'.print_r($node, 1).'</pre>');
    $path_node = drupal_get_path_alias('node/'.$node->nid);
    $title = l($node->title, $path_node);
    if(!empty($node->field_mc_teaser_toptxt_white['und'])){
     $white_text_movie = '<span class="white">'. $node->field_mc_teaser_toptxt_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_movie = '';
    }
    if(!empty($node->field_mc_teaser_toptxt_blk['und'])){
     $black_text_movie = '<span class="black">' . $node->field_mc_teaser_toptxt_blk['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_movie = '';
    }
    if(!empty($node->field_movie_group_top_text_white['und'])){
     $white_text_movie_group = '<span class="white">'. $node->field_movie_group_top_text_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_movie_group = '';
    }
    if(!empty($node->field_movie_group_top_text_black['und'])){
     $black_text_movie_group = '<span class="black">' . $node->field_movie_group_top_text_black['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_movie_group ='';
    }
    if(!empty($node->field_article_top_text_white['und'])){
     $white_text_article = '<span class="white">'. $node->field_article_top_text_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_article = '';
    }
    if(!empty($node->field_article_top_text_black['und'])){
     $black_text_article = '<span class="black">' . $node->field_article_top_text_black['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_article = '';
    }
    if(!empty($node->field_event_top_text_white['und'])){
     $white_text_event = '<span class="white">'. $node->field_event_top_text_white['und'][0]['value'] . '</span>'; 
    }else{
      $white_text_event = '';
    }
    if(!empty($node->field_event_top_text_black['und'])){
     $black_text_event = '<span class="black">' . $node->field_event_top_text_black['und'][0]['value'] .'</span>'; 
    }else{
      $black_text_event = '';
    }
    if(!empty($node->field_cm_moviegroup_short_summar)){
      //$summary_movie_group =  truncate_utf8($node->field_cm_moviegroup_short_summar['und'][0]['value'], 50, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
      $summary_movie_group =  $node->field_cm_moviegroup_short_summar['und'][0]['value'];
    }else{
      $summary_movie_group = '';
    }
    if(!empty($node->field_cm_movie_short_summary)){
      //$summary_movie = truncate_utf8($node->field_cm_movie_short_summary['und'][0]['value'], 50, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
      $summary_movie = $node->field_cm_movie_short_summary['und'][0]['value'];
    }else{
      $summary_movie = '';
    }
    if(!empty($node->field_cm_event_body['und'][0]['value'])){
      $summary_event = truncate_utf8($node->field_cm_event_body['und'][0]['value'], 50, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
    }else{
      $summary_event = '';
    }
    /*****Movie group Image****/
    if(!empty($node->field_cm_moviegroup_pictures)){
      $picture_path = $node->field_cm_moviegroup_pictures['und'][0]['uri'];
        $image_movie_group = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
        $image_movie_group = $default_image;
    }
    /*****Movie Image****/
    if(!empty($node->field_cm_movie_pictures)){
      $picture_path_movie = $node->field_cm_movie_pictures['und'][0]['fid'];
      $file = file_load($picture_path_movie);
      $picture_path = $file->uri;
      $image_movie= '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
    $image_movie = $default_image;
    }
    /*****Article group Image****/
    if(!empty($node->field_cm_article_image)){
      $picture_path_article = $node->field_cm_article_image['und'][0]['fid'];
      $file = file_load($picture_path_article);
      $picture_path = $file->uri;
      $image_article = '<img src="' . image_style_url('lobby', $picture_path) . '" alt="" />';
    }else{
      $image_article = $default_image;
    }
    /*****Event Image****/
    if(!empty($node->field_cm_event_images)){
      $picture_path_event = $node->field_cm_event_images['und'][0]['uri'];
      $image_event = '<img src="' . image_style_url('lobby', $picture_path_event) . '" alt="" />';
    }else{
      if(!empty($node->field_cm_event_lineup['und'])){
        $event_ext_node = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
        if($event_ext_node->type == 'cm_movie_group'){
          $picture_path_ext_moviegroup = $event_ext_node->field_cm_moviegroup_pictures['und'][0]['uri'];
          $image_event = '<img src="' . image_style_url('lobby', $picture_path_ext_moviegroup) . '" alt="" />';
        }else if($event_ext_node->type == 'cm_movie'){
          $picture_path_ext_movie = $event_ext_node->field_cm_movie_pictures['und'][0]['fid'];
          $file_ext_movie = file_load($picture_path_ext_movie);
          $picture_path_ext_movie = $file_ext_movie->uri;
          $image_event= '<img src="' . image_style_url('lobby', $picture_path_ext_movie) . '" alt="" />';
        }else{
            $image_event = $default_image;
        }
      } 
    }  
      switch ($node->type) {
        case "cm_movie_group":
          $flag = flag_create_link('favorite_', $node->nid);
          $image = $image_movie_group;
          $sort_summary = $summary_movie_group;
          $top_text = $black_text_movie_group . $white_text_movie_group;
        break;
        case "cm_movie":
          $flag = flag_create_link('favorite_', $node->nid);
          $image = $image_movie;
          $sort_summary = $summary_movie;
          $top_text = $black_text_movie . $white_text_movie;
        break;
        case "cm_article":
          $flag = flag_create_link('favorite_', $node->nid);
          $image = $image_article;
          if(!empty($node->body['und'][0]['summary'])){
            $sort_summary = $node->body['und'][0]['summary'];
          }
          elseif(!empty($node->body['und'][0]['value'])){
            $sort_summary = truncate_utf8($node->body['und'][0]['value'], 50, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
          }else{
            $sort_summary = '';
          }
          $top_text = $black_text_article . $white_text_article;
        break;
          case "cm_event":
          $flag = flag_create_link('favorite_', $node->nid);
          $image = $image_event;
          $sort_summary = $summary_event;
          $top_text = $black_text_event . $white_text_event;
        break;
        default:
          $image = '';
          $sort_summary = '';
          $top_text = '';
      }  
    print '<div class="views-row">';
        print '<div class="views-field views-field-ops">';
            print $flag;
        print '</div>';
        print '<div class="views-field views-field-field-cm-event-images">';
            print $image;
        print '</div>';
        print '<div class="views-field views-field-field-cm-moviegroup-short-summar">';
            print '<span class="field-content">';
                print '<h5 class="title">' . $title . '</h5>';
                print '<div class="short-summery">' . strip_tags($sort_summary) .'</div>';
            print '</span>';
        print '</div>';
        print '<div class="views-field views-field-field-mc-teaser-toptxt-blk top-text-blk-wht">';
            print '<div class="field-content">' . $top_text . '</div>';
        print '</div>';
    print '</div>';
  }
?>
