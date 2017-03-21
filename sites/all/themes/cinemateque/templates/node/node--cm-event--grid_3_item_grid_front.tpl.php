<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
   <?php if(!empty($node->field_cm_event_lineup['und'])){
       $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
    } ?>
  <div class="grid_3_item">
      <div class="image">
        <a class="all-image" href="<?php print $node_url; ?>"></a>
        <?php if (render($content['field_cm_event_images'])){
            print render($content['field_cm_event_images']); 
        }else if(!empty($node->field_cm_event_lineup)){
			      $event_movie = movie_image_output($node->field_cm_event_lineup['und'][0]['target_id']);
            print $event_movie;
        } else {
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
        <?php if(!empty($node->field_cm_event_lineup['und'])){
            if(!empty($event_ext_nodes->field_cm_movie_videos)){ ?>
              <div class="video-link">
                <?php print movie_video_output($event_ext_nodes->nid); ?>
              </div>
            <?php } 
          } ?>
        <div class="title-area">
          <?php $movie_tile=(!empty($content['field_cm_event_lineup'][0]['#markup']))?$content['field_cm_event_lineup'][0]['#markup']:''; 
          if (($movie_tile!=$title) && (!empty($content['field_cm_event_lineup'][0]['#markup']))): ?>
            <div class="slide-small-text film-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></div>
          <?php endif;?>
          <div class="slide-big-text film-title"><a href="<?php print $node_url; ?>"><?php print (render($content['field_cm_event_lineup']))?render($content['field_cm_event_lineup']):$title; ?></a></div>
          <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
        </div>
        <div class="screaning">
          <div class="table-responsive">
            <table class="table">
              <tbody>
                  <tr class="row-custom-lobby">
                    <?php if(!empty($node->field_cm_event_time['und'])){ ?>
                        <td class="date only-desktop"><?php print format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'l d.m.y | '); ?></td>
                        <td class="time"><div class="only-mobile"><?php print format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'd.m.y'); ?></div><?php print date('H:i', $node->field_cm_event_time['und'][0]['value']); ?></td>
                    <?php } 
                    $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
                    if ($event_start_date>time()){?>
                        <?php if(empty($node->field_tickets_sold_out['und'][0]['value'])){ ?>
                            <td class="purchase"><?php print render($content['field_toptix_purchase']);?></td>
                        <?php } else{ ?>
                            <td class="purchase"><button class="sold-out"><?php print t("sold out");?></button></td>
                        <?php } ?>
                    <?php } else {?>
                      <td class="purchase"></td>
                    <?php } ?>
                  </tr>
                </tbody>
              </table>
            </div>
          </div>
        </div>
  </div>


</article>
