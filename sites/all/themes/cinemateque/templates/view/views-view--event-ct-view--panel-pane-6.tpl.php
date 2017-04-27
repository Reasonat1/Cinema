<?php $results=$view->result; 

if(!empty($results[0]->node_field_data_field_cm_event_lineup_nid)){
  $tagetId = $results[0]->node_field_data_field_cm_event_lineup_nid;
  $node = node_load($tagetId);


if ($node->type=='cm_movie_group') {
	$output='<div class="movie-group-list">';
foreach ($node->field_movie_referenced['und'] as $movie_array) {
	$base_node = node_load($movie_array['target_id']);
	$trans = translation_node_get_translations($base_node->tnid);
	
	$movie_id = ($trans)?($node->language == 'he')?$trans['he']->nid:$trans['en']->nid:$movie_array['target_id'];
	
	$movie_node=node_load($movie_id);
	$alias = drupal_get_path_alias('node/'.$movie_node->nid);
	$flag = '<span class="flag-event">'.flag_create_link('favorite_', $movie_node->nid).'</span>';
	if(!empty($movie_node->field_cm_movie_pictures)){
         
		  $picture_path_movie=file_load($movie_node->field_cm_movie_pictures['und'][0]['fid']);
          $image_movie = '<img src="' . image_style_url('movie-group_613x380_', $picture_path_movie->uri) . '" alt="" />';
        }else{
            $image_movie = '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
        }
	$white_text_event = (!empty($movie_node->field_mc_teaser_toptxt_white['und']))?'<span class="white">'. $movie_node->field_mc_teaser_toptxt_white['und'][0]['value'] . '</span>':''; 
    $black_text_event = (!empty($movie_node->field_mc_teaser_toptxt_blk['und']))?'<span class="black">' . $movie_node->field_mc_teaser_toptxt_blk['und'][0]['value'] .'</span>':'';
 $output .= '<div class="row"><div class="image-lobby"><div class="flag-movie">'.$flag.'</div>';
 $output .= l($image_movie, $alias, array('attributes' => array('class' =>'link-image'),'html' => true));
 $output .= '<div class="top-text-blk-wht">';
 $output .= $black_text_event . $white_text_event;
 $output .= '</div>';
 $output .= '<div class="gradient small"></div>';
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
      $lang = t($lang_name->name);
    }else{
      $lang = '';
    }
	if(!empty($movie_node->field_cm_movie_subtitle['und'])){
      $subtitle_name = taxonomy_term_load($movie_node->field_cm_movie_subtitle['und'][0]['target_id']);
      $subtitle = t('@languages subtitles', array('@languages' => t($subtitle_name->name)));
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
          $summary_movie = $movie_node->field_cm_movie_body['und'][0]['value'];
        }else{
            $summary_movie = '';
        }
 $output .= '<div class="lobby-summary">'.$summary_movie.'</div>';
 //credits



if ($node->language=='he') {
	$original_title=(!empty($movie_node->tnid))?node_load(translation_node_get_translations($movie_node->tnid)['en']->nid)->title:'';
	$original_label=t('English name');
	$original_marckup= ($original_title)?'<div class="credit-inner">
            <div class="views-field views-field-field-cm-movie-credits-person-ro profession">'. $original_label . ': ' .'</div>
            <div class="views-field views-field-views-conditional">' . $original_title . '</div>
        </div>':'';
} 
else {
	$original_label=t('Original title');
	$original_title=field_get_items('node', $movie_node, 'field_original_title')[0]['value'];
	$original_marckup= ($original_title)?'<div class="credit-inner">
            <div class="views-field views-field-field-cm-movie-credits-person-ro profession">'. $original_label . ': ' .'</div>
            <div class="views-field views-field-views-conditional">' . $original_title . '</div>
        </div>':'';
}
$items = field_get_items('node', $movie_node, 'field_cm_movie_credits');
$profession_array = array();
foreach ($items as $item) {
    $fc = field_collection_field_get_entity($item);
    if(isset($fc->field_cm_movie_credits_person_ro['und'])){$profession = taxonomy_term_load($fc->field_cm_movie_credits_person_ro['und'][0]['target_id']);
    $profession_name = $profession->name;} else {$profession_name='';}
    $person_node = node_load($fc->field_cm_movie_credits_person['und'][0]['target_id']);
    $path_node = drupal_get_path_alias('node/'.$person_node->nid);
    $first = (!empty($person_node->field_cm_person_first_name['und']))? $person_node->field_cm_person_first_name['und'][0]['value']:'';
    $last = (!empty($person_node->field_cm_person_last_name['und']))? $person_node->field_cm_person_last_name['und'][0]['value']:'';
    $name  = $first .' '.$last;
    if(!empty($person_node->field_cm_person_first_name)){
        $full_name = $name;
    }else{
        $full_name = $person_node->title;
    }
    $lolo = $profession_name.': ' .$full_name.'<br />';
	if (!array_key_exists ($profession_name, $profession_array)){
	  $profession_array[$profession_name] = array();
	}
    $profession_array[$profession_name][] = t(l($full_name, $path_node));
}
    $output_row = '<div class="credits-view movie-group-item-credit">';
    $output_row .= $original_marckup;
    foreach($profession_array as $key => $value) {
        $output_row .= '<div class="credit-inner">';
            $output_row .= '<div class="views-field views-field-field-cm-movie-credits-person-ro profession">'. $key . ':</div>';
            $output_row .= '<div class="views-field-views-conditional"><span>'.implode(", ",$value) . '</span></div>';
       $output_row .= '</div>';
    }
    $output_row .= '</div>';
	$output .= $output_row;
	$output .= '</div></div>';
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