<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_special_3_item">
      <div class="image-wrapper">
        <div class="image">
            <a href="<?php print $node->field_link['und'][0]['display_url']; ?>">
              <?php 
			            if (render($content['field_main_image'])){
                    print render($content['field_main_image']); 
                  }
			            else {
                    print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
                  } ?>
              <div class="gradient very-small"></div>
            </a>
        </div>
          <div class="on-image">
          <?php if ($node->field_show_title){
            if ($node->field_show_title['und'][0]['value'] != 0) { ?>
                  <h2 class="title"><a href="<?php print $node->field_link['und'][0]['display_url']; ?>"><?php print $title; ?></a></h2>
            <?php } 
            } ?>
            <div class="short-title"><?php print render($content['field_sub_title']); ?></div>
			 <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
			if ($event_start_date>time()):?>
            <div class="date"><?php print render($content['field_cm_event_time']); ?>  </div>
            <div class="purchase"><?php print render($content['field_toptix_purchase']); ?></div>
			<?php endif;?>
          </div>
      </div>
      <div class="short-text">
        <?php print render($content['field_homepage_extra_text']);?>
      </div>
  </div>


</article>
