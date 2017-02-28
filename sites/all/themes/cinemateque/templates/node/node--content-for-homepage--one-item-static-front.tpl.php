<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <div class="one-item-static with-image">
        <div class="image">
          <?php 
            if(!empty($node->field_low_and_wide_for_home_page)){ 
              print render($content['field_low_and_wide_for_home_page']);
            } 
            else if(!empty($node->field_main_image)){ 
              print render($content['field_main_image']);
            }
            else{
                print '<img src="/sites/all/themes/cinemateque/images/default-one-item.png">';
            } 
          ?>
          <div class="gradient small"></div>
        </div>
        <a class="all-image" href="<?php print $node->field_link['und'][0]['display_url']; ?>"></a>
          <div class="on-image">
          <?php if ($node->field_show_title){
            if ($node->field_show_title['und'][0]['value'] != 0) { ?>
                <h2 class="title"><a href="<?php print $node->field_link['und'][0]['display_url']; ?>"><?php print $title; ?></a></h2>
              <?php } 
            } ?>
              <div class="extra-text"><?php print render($content['field_sub_title']); ?></div>
              <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
			         if ($event_start_date>time()){?>
			           <div class="date only-desktop"><?php print render($content['field_cm_event_time']); ?></div>
                 <?php $event_date_mobile = format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'd.m.y'); ?>
                 <div class="date only-mobile"><?php print $event_date_mobile; ?><div class="time"><?php print date('H:i', $node->field_cm_event_time['und'][0]['value']); ?></div></div>
                 <?php print render($content['field_toptix_purchase']); 
                }?>
          </div>
      </div>
</article>