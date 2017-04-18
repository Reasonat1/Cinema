<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
   <?php if(!empty($node->field_cm_event_lineup['und'])){
       $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
    } ?>
  <div class="grid_special_3_item event">
        <div class="image-wrapper">
              <div class="image">
                    <a class="all-image" href="<?php print $node_url; ?>"></a>
                    <?php 
			               if (render($content['field_cm_event_images'])){
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
                      <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
                      <div class="on-image">
                          <?php 
                          $movie_tile=(!empty($content['field_cm_event_lineup'][0]['#markup']))?$content['field_cm_event_lineup'][0]['#markup']:''; 
                          if (($movie_tile!=$title) && (!empty($content['field_cm_event_lineup'][0]['#markup']))): ?>
                            <div class="slide-small-text film-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></div>
                          <?php endif;?>
                          <div class="slide-big-text film-title title">
                            <a href="<?php print $node_url; ?>">
                              <?php print (render($content['field_cm_event_lineup']))?render($content['field_cm_event_lineup']):$title; ?>
                            </a>
                          </div> 
                          <div class="short-title title"><?php print render($content['field_cm_event_short_title']); ?></div>
                          <?php if(!empty($node->field_cm_event_lineup['und'])){
                            if(!empty($event_ext_nodes->field_cm_movie_videos)){ ?>
                            <div class="video-link">
                              <?php print movie_video_output($event_ext_nodes->nid); ?>
                            </div>
                          <?php } 
                          } ?>
                          <div class="screaning">
                            <div class="date"><?php print render($content['field_cm_event_time']); ?></div> 
                            <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
                              if ($event_start_date>time()):?>
                                <?php if(empty($node->field_tickets_sold_out['und'][0]['value'])){ ?>
                                  <div class="purchase">
                                       <?php $toptix_code = $node->field_toptix_purchase['und'][0]['value'];
                                       $top_link = 'http://tickets.jer-cin.org.il/loader.aspx/?target=hall.aspx?event='.$toptix_code.''; ?>
                                       <button data-url="<?php print $top_link; ?>" class="toptix-purchase"><?php print t("TICKETS"); ?></button>
                                  </div>
                                <?php } else{ ?>
                                  <div class="purchase"><div class="sold-out"><?php print t("sold out");?></div></div>
                                <?php } ?>
                              <?php endif;?>
                            </div>
                      </div> 
              </div>
      </div>
      <div class="short-text">
        <?php print render($content['field_cm_event_short_description']);
        if(!empty($node->field_cm_event_lineup['und'])){
          $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
          if ($GLOBALS['_domain']['domain_id'] == 1 ){ 
            if(!empty($event_ext_nodes->field_cm_movie_short_summary['und'])){ 
              print $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'];
            }
          } else if(!empty($event_ext_nodes->field_short_summary_festival['und'])){ 
              print $event_ext_nodes->field_short_summary_festival['und'][0]['value'];
            } else  if(!empty($event_ext_nodes->field_cm_movie_short_summary['und'])){ 
              print $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value'];
            }        
        } ?>
      </div>
</div>
</article>
