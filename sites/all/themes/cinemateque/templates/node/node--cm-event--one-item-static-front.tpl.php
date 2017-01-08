<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php if(!empty($node->field_cm_event_images)){ ?>
      <div class="one-item-static with-image">
        <div class="image">
          <?php print render($content['field_cm_event_images']); ?>
          <div class="gradient small"></div>
        </div>
        <div class="on-image">
            <?php print render($content['field_cm_event_short_title']); ?>
            <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
            <?php print render($content['field_cm_event_time']);
            print render($content['field_toptix_purchase']); ?>
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