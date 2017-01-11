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
            <div class="gradient very-small"></div>
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
      <a href="<?php print $node_url; ?>">
        <div class="on-image">
          <h2 class="title"><?php print $title; ?></h2>
        </div>
        </a>
  </div>


</article>