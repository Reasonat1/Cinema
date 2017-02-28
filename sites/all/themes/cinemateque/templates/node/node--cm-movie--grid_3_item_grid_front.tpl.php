<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
          <a href="<?php print $node_url; ?>">
            <?php if (render($content['field_cm_movie_pictures'])){
              print render($content['field_cm_movie_pictures']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="gradient small"></div>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_mc_teaser_toptxt_blk)){ ?>
                <span class="black"><?php print render($content['field_mc_teaser_toptxt_blk']);?></span>
              <?php } 
              if(!empty($node->field_mc_teaser_toptxt_white)){ ?>
                <span class="white"><?php print render($content['field_mc_teaser_toptxt_white']);?></span>
              <?php } ?>
          </div>
          </a> 
          <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
      </div>
      <a class="all-image" href="<?php print $node_url; ?>"></a>
        <div class="on-image">
          <div class="title-area">
            <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
            <div class="video-link">
              <?php print movie_video_output($node->nid); ?>
            </div>
          </div>
        <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
		  <div class="screaning"><?php print screaning_output($node->nid, 1); ?></div>
        </div>
  </div>


</article>