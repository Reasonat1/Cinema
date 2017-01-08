<?php $results=$view->result; 

if(!empty($results[0]->node_field_data_field_cm_event_lineup_nid)){
  $tagetId = $results[0]->node_field_data_field_cm_event_lineup_nid;
  $node = node_load($tagetId);



if ($node->type=='cm_movie_group') {
	$output='<div class="movie-group-list">';
foreach ($node->field_movie_referenced['und'] as $movie_array) {
	$movie_node=node_load($movie_array['target_id']);
	$alias = drupal_get_path_alias('node/'.$movie_node->nid);
	$flag = '<span class="flag-event">'.flag_create_link('favorite_', $movie_node->nid).'</span>';
	if(!empty($movie_node->field_cm_movie_pictures)){
         
		  $picture_path_movie=file_load($movie_node->field_cm_movie_pictures['und'][0]['fid']);
          $image_movie = '<img src="' . image_style_url('lobby', $picture_path_movie->uri) . '" alt="" />';
        }else{
            $image_movie = '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
        }
 $output .= '<div class="row"><div class="image-lobby"><div class="flag-movie">'.$flag.'</div>';
 $output .= l($image_movie, $alias, array('attributes' => array('class' =>'link-image'),'html' => true));
	if(!empty($movie_node->field_cm_movie_meta_credit['und'])){
	$credits=$movie_node->field_cm_movie_meta_credit['und'][0]['value'];
	} else $credits='';
	if(!empty($movie_node->field_cm_movie_year['und'])){
      $year_name = taxonomy_term_load($movie_node->field_cm_movie_year['und'][0]['target_id']);
      $year = $year_name->name;
    }else{
      $year = '';
    }
	
	if(!empty($movie_node->field_cm_movie_country['und'])){
      $country_name = taxonomy_term_load($movie_node->field_cm_movie_country['und'][0]['target_id']);
      $country = $country_name->name;
    }else{
      $country = '';
    }
	
	if(!empty($movie_node->field_cm_movie_language['und'])){
      $lang_name = taxonomy_term_load($movie_node->field_cm_movie_language['und'][0]['target_id']);
      $lang = $lang_name->name;
    }else{
      $lang = '';
    }
	if(!empty($movie_node->field_cm_movie_subtitle['und'])){
      $subtitle_name = taxonomy_term_load($movie_node->field_cm_movie_subtitle['und'][0]['target_id']);
      $subtitle = t('Subtitle').': '.$subtitle_name->name;
    }else{
      $subtitle = '';
    }
	if(!empty($movie_node->field_cm_movie_duration)){
      $length_interval = t($movie_node->field_cm_movie_duration['und'][0]['interval']);
      $length_period = t($movie_node->field_cm_movie_duration['und'][0]['period'].'s');
      $length = $length_interval.' '.$length_period;

    } else {
		 $length ='';
	}
 $output .= '<div class="lobby-title">'.l($movie_node->title, $alias).'</div></div>';
 $output .= '<div class="under-image">';
 $output .= '<div class="movie-details">';
                                    $output .= ($credits)?'<span class="credits td-border-right">'.$credits.'</span>':'';
                                    $output .= ($country || $year)?'<span class="year td-border-right">'.$country.' '.$year.'</span>':'';
                                    $output .= ($length)?'<span class="length td-border-right">'.$length.'</span>':'';
                                    $output .= ($lang)?'<span class="language td-border-right">'.$lang.'</span>':'';
                                    $output .= ($subtitle)?'<span class="subtitle">'.$subtitle.'</span>':'';
   $output .= '</div>';
 
	if(!empty($movie_node->field_cm_movie_body['und'][0]['value'])){
          $summary_movie = truncate_utf8($movie_node->field_cm_movie_body['und'][0]['value'], 250, $wordsafe = FALSE, $add_ellipsis = true, $min_wordsafe_length = 1);
        }else{
            $summary_movie = '';
        }
 $output .= '<div class="lobby-summary">'.strip_tags($summary_movie).'</div></div></div>';
}
 $output .= '</div>';
 $rows.=$output;
 

 }
}
?>


<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>