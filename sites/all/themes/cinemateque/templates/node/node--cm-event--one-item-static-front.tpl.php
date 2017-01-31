<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php if(!empty($node->field_cm_event_images) || !empty($node->field_cm_event_lineup)){ ?>
      <div class="one-item-static with-image">
        <div class="image">
          <?php 
        if(!empty($node->field_low_and_wide_for_home_page)) {
          print render($content['field_low_and_wide_for_home_page']); 
        }
		  else if(!empty($node->field_cm_event_images)) {
		  print render($content['field_cm_event_images']); 
		  }
		  else if(!empty($node->field_cm_event_lineup)){
			$event_movie = movie_image_output($node->field_cm_event_lineup['und'][0]['target_id'], 'one_item_static');
            print $event_movie;
            }
		  ?>
          <div class="gradient small"></div>
        </div>
        <a class="all-image" href="<?php print $node_url; ?>"></a>
          <div class="on-image">
              <?php print render($content['field_cm_event_short_title']); ?>
              <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
              <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
              <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
			  if ($event_start_date>time()){
			  print render($content['field_cm_event_time']);
              print render($content['field_toptix_purchase']); }?>
          </div>
        <div class="top-text-blk-wht">
          <?php  if(!empty($node->field_event_top_text_black)){ ?>
            <span class="black"><?php print render($content['field_event_top_text_black']);?></span>
          <?php } 
          if(!empty($node->field_event_top_text_white)){ ?>
            <span class="white"><?php print render($content['field_event_top_text_white']);?></span>
          <?php } ?>
        </div> 
        <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
      </div>
    <?php } ?>
</article>