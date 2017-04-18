<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_special_3_item">
      <div class="image-wrapper">
        <div class="image">
            <a class="all-image" href="<?php print $node_url; ?>"></a>
              <?php if (render($content['field_cm_movie_pictures'])){
                print render($content['field_cm_movie_pictures']); 
              }
              else{
                print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
              } ?>
              <div class="gradient very-small"></div>
              <div class="top-text-blk-wht">
                <?php  if(!empty($node->field_mc_teaser_toptxt_blk)){ ?>
                  <span class="black"><?php print render($content['field_mc_teaser_toptxt_blk']);?></span>
                <?php } 
                if(!empty($node->field_mc_teaser_toptxt_white)){ ?>
                  <span class="white"><?php print render($content['field_mc_teaser_toptxt_white']);?></span>
                <?php } ?>
              </div>
              <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
              <div class="on-image">
                <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
                <div class="video-link">
                  <?php print movie_video_output($node->nid); ?>
                </div>
                <div class="screaning"><?php print screaning_output($node->nid, 1, TRUE); ?></div>
              </div>
      </div>
    </div>
      <div class="short-text">
              <?php if ($GLOBALS['_domain']['domain_id'] == 1 ){ 
                if(!empty($node->field_cm_movie_short_summary['und'])){ 
                  print render($content['field_cm_movie_short_summary']);
                }
              } else if(!empty($node->field_short_summary_festival['und'])){ 
                  print $node->field_short_summary_festival['und'][0]['value'];
                } else if(!empty($node->field_cm_movie_short_summary['und'])){ 
                  print render($content['field_cm_movie_short_summary']);
                }?>
      </div>
  </div>


</article>
