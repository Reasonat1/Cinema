<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
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
          <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
      </div>
      <div class="on-image">
        <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      </div>
  </div>


</article>