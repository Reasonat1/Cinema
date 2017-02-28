<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="top_gallery_front">
    <div class="full-screen-image-front">
      <div class="gallery">
            <?php 
			$event_movie=$event_video='';
			if (render($content['field_cm_event_images'])){
              print render($content['field_cm_event_images']); 
            }else if(!empty($node->field_cm_event_lineup)){
			$event_movie = movie_image_output($node->field_cm_event_lineup['und'][0]['target_id'], 'slide_show');
			$event_video = movie_video_output($node->field_cm_event_lineup['und'][0]['target_id']);
            print $event_movie.'<div class="gradient"></div>';
            }
			else {
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
      </div>
    </div>
    <div class="text-main-image">
      <div class="wrapper">
	  <div class="slide-right-ct">
        <div class="video-link">
		        <?php print $event_video; ?>
          </div>
		</div>
		
    <div class="slide-left-ct">
		  <?php $movie_tile=(!empty($content['field_cm_event_lineup'][0]['#markup']))?$content['field_cm_event_lineup'][0]['#markup']:''; 
		  if (($movie_tile!=$title) && (!empty($content['field_cm_event_lineup'][0]['#markup']))): ?>
          <div class="slide-small-text film-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></div>
		  <?php endif;?>
          <div class="slide-big-text film-title"><a href="<?php print $node_url; ?>"><?php print (render($content['field_cm_event_lineup']))?render($content['field_cm_event_lineup']):$title; ?></a></div>
          <div class="slide-small-text extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
		  <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';

			if ($event_start_date>time()):?>
          <div class="slide-small-text time"><?php print render($content['field_cm_event_time']); ?></div>
          <?php if(empty($node->field_tickets_sold_out['und'][0]['value'])){ ?>
            <div class="purchase"><?php print render($content['field_toptix_purchase']); ?></div>
          <?php } else{ ?>
            <div class="purchase"><div class="sold-out"><?php print t("sold out");?></div>
          <?php } ?>
		  <?php endif;?>
        </div>
      </div>
    </div>
  </div>

</article>