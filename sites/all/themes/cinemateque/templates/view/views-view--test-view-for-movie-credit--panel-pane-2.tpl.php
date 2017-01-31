<?php $results=$view->result; 
if(!empty($results[0]->node_field_data_field_cm_event_lineup_nid)){
  $tagetId = $results[0]->node_field_data_field_cm_event_lineup_nid;
  $node = node_load($tagetId);
  
$trans = translation_node_get_translations($node->tnid);
$title_eng='';
if(!empty($trans)){
      if($node->language == 'he')  {
        $titles = $trans['en']->title;  
       $path = drupal_get_path_alias('/en/node/'.$node->tnid);  
        $title_eng = '<div class="translated-movie-title">'. t('Movie title'). ':  ';
        $title_eng .= '<a href="'.$path.'">'.  $titles .'</a>';
        $title_eng .=  '</div>';
    }	
$rows = '<div class="credit-area"><div class="credits-view"><div class="inside">'.$title_eng.$rows.'</div></div></div>';	
} 
else{
$rows = '<div class="credit-area"><div class="credits-view"><div class="inside">'.$rows.'</div></div></div>';  
}

if(!empty($node->field_qoutes)){
$qute_array=array();
foreach ($node->field_qoutes['und'] as $key=>$qute_id) {
	$qute_array[]=$qute_id['value'];
}
$filters = array();
if (count($qute_array)) $filters = array(implode(",", $qute_array));
$view = views_get_view('reviews_field_collection_view');
$view->set_arguments($filters); // Set exposed filters
$view->set_display('default');
$view->pre_execute();
$view->execute();
$view_mobile = views_get_view('reviews_field_collection_view_mobile');
$view_mobile->set_arguments($filters); // Set exposed filters
$view_mobile->set_display('default');
$view_mobile->pre_execute();
$view_mobile->execute();
$rows = '<div class="only-desktop">'.$view->render('default').'</div>'.$rows.'<div class="reviews-mobile only-mobile">'.$view_mobile->render('default').'</div>';
}

 
$filters = array($tagetId);

$view = views_get_view('movie_person_bio');
$view->set_arguments($filters); // Set exposed filters
$view->set_display('block_1');
$view->pre_execute();
$view->execute();
$rows.= $view->render('block_1');
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

<script>
    jQuery(function(){  
      jQuery('.more-items.reviews-mobile .view-content').owlCarousel({
        rtl: true,
        loop:true,
        margin:10,
        navigation:false,
        nav: true,
        responsive:{
          0:{
            items:1
          }
        }
      }); 
    });
</script>