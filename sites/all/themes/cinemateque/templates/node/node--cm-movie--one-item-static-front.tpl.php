<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php if(!empty($node->field_cm_movie_pictures)){ ?>
      <div class="one-item-static">
        <div class="image">
          <?php print render($content['field_cm_movie_pictures']); ?>
          <div class="gradient small"></div>
        </div>
        <div class="on-image">
            <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        </div>
        <div class="top-text-blk-wht">
          <?php if(!empty($node->field_mc_teaser_toptxt_blk)){ ?>
            <span class="black"><?php print render($content['field_mc_teaser_toptxt_blk']);?></span>
          <?php } 
          if(!empty($node->field_mc_teaser_toptxt_white)){ ?>
            <span class="white"><?php print render($content['field_mc_teaser_toptxt_white']);?></span>
          <?php } ?>
        </div> 
        <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
      </div>
    <?php } ?>


</article>