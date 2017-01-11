<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
            <a href="<?php print $node_url; ?>">
            <?php if (render($content['field_cm_event_images'])){
              print render($content['field_cm_event_images']); 
            }else if(!empty($node->field_cm_event_lineup)){
              $lineup_id = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
              $picture_path_event=file_load($lineup_id->field_cm_movie_pictures['und'][0]['fid']);
              print '<img src="' . image_style_url('lobby', $picture_path_event->uri) . '" alt="" />';
            }
            else{
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
      <a href="<?php print $node_url; ?>">
        <div class="on-image">
          <h2 class="title"><?php print render($content['field_cm_event_lineup']); ?></h2>
          <div class="short-title"><?php print render($content['field_cm_event_short_title']); ?></div>
          <div class="date"><?php print render($content['field_cm_event_time']); ?>  </div>
        </div>
      </a>
  </div>


</article>
