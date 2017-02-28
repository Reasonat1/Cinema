<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="list_normal_image_width">
      <div class="left-area">
            <a class="all-image" href="<?php print $node_url; ?>"></a>
            <?php 
			if (render($content['field_cm_movie_pictures'])){
              print render($content['field_cm_movie_pictures']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_mc_teaser_toptxt_blk)){ ?>
                <span class="black"><?php print render($content['field_mc_teaser_toptxt_blk']);?></span>
              <?php } 
              if(!empty($node->field_mc_teaser_toptxt_white)){ ?>
                <span class="white"><?php print render($content['field_mc_teaser_toptxt_white']);?></span>
              <?php } ?>
          </div> 
          <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
          <?php  if(!empty($node->field_cm_movie_videos)){ ?>
            <div class="video-link">
             <?php print movie_video_output($node->nid); ?>
            </div>
            <div class="gradient small"></div>
          <?php } ?>
      </div>
	   
      <div class="right-area">
        <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="credit-duration">
            <?php if ($node->field_cm_movie_meta_credit) { ?>
              <div class="credit-list"><?php print render($content['field_cm_movie_meta_credit']); ?></div>
            <?php } ?>
            <?php if(!empty($node->field_cm_movie_duration)){
              $length_interval = t($node->field_cm_movie_duration['und'][0]['interval']);
              $length_period = t($node->field_cm_movie_duration['und'][0]['period'].'s');
              $length = ' | '.$length_interval.' '.$length_period; ?>
              <div class="duration"><?php print $length; ?>  </div>
            <?php } ?>
        </div>
        <div class="short-summary"><?php print render($content['field_cm_movie_short_summary']); ?>  </div>
        <div class="screaning"><?php print screaning_output($node->nid); ?></div>
      </div>
  </div>


</article>