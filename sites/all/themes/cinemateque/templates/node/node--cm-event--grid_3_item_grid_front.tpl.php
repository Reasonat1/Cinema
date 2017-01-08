<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
            <?php if (render($content['field_cm_event_images'])){
              print render($content['field_cm_event_images']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="gradient small"></div>
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
      <div class="on-image">
        <h2 class="title"><a href="<?php print $node_url; ?>"><?php print render($content['field_cm_event_lineup']); ?></a></h2>
        <div class="short-title"><?php print render($content['field_cm_event_short_title']); ?></div>
        <div class="date"><?php print render($content['field_cm_event_time']); ?>  </div>
      </div>
  </div>


</article>