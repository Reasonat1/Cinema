<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
            <a href="<?php print $node_url; ?>">
            <?php if (render($content['field_cm_event_images'])){
              print render($content['field_cm_event_images']); 
            }else if(!empty($node->field_cm_event_lineup)){
			$event_movie = movie_image_output($node->field_cm_event_lineup['und'][0]['target_id']);
            print $event_movie;
            }
			else {
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="gradient very-small"></div>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_event_top_text_black)){ ?>
                <span class="black"><?php print render($content['field_event_top_text_black']);?></span>
              <?php } 
              if(!empty($node->field_event_top_text_white)){ ?>
                <span class="white"><?php print render($content['field_event_top_text_white']);?></span>
              <?php } ?>
          </div> 
            </a>
          <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
      </div>
      <a class="all-image" href="<?php print $node_url; ?>">
        <div class="on-image">
          <h2 class="title"><?php print render($content['field_cm_event_lineup']); ?></h2>
          <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
          <div class="short-title"><?php print render($content['field_cm_event_short_title']); ?></div>
		  <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
		  if ($event_start_date>time()):?>
          <div class="date"><?php print render($content['field_cm_event_time']); ?>  </div>
		  <?php endif;?>
        </div>
      </a>
  </div>


</article>
