<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="top_gallery_front">
    <div class="full-screen-image-front">
      <div class="gallery">
      <?php 
			if (render($content['field_main_image'])){
              print render($content['field_main_image']); 
      }
			else {
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
      </div>
    </div>

    <div class="text-main-image">
      <div class="wrapper">
        <div class="slide-right-ct"></div>
        <div class="slide-left-ct">
          <?php if ($node->field_show_title){
            if ($node->field_show_title['und'][0]['value'] != 0) { 
              if ($node->field_link) { ?>
                <div class="slide-big-text title"><a href="<?php print $node->field_link['und'][0]['display_url']; ?>"><?php print $title; ?></a></div>
              <?php } else { ?>
                <div class="slide-big-text title"><?php print $title; ?></div>
              <?php }
            } ?>
          <?php }?>
          <div class="slide-small-text sub-title"><?php print render($content['field_sub_title']); ?></div>
		  <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
			if ($event_start_date>time()):?>
          <div class="slide-small-text time"><?php print render($content['field_cm_event_time']); ?></div>
          <div class="purchase"><?php print render($content['field_toptix_purchase']); ?></div>
		  <?php endif;?>
        </div>
      </div>
    </div>
  </div>

</article>

