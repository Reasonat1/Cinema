<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

      <div class="one-item-static with-image">
        <div class="image">
          <?php 
          if(!empty($node->field_low_and_wide_for_home_page)){ 
            print render($content['field_low_and_wide_for_home_page']);
          } 
          else if(!empty($node->field_cm_moviegroup_pictures)){ 
            print render($content['field_cm_moviegroup_pictures']);
          } ?>
          <div class="gradient small"></div>
        </div>
        <a class="all-image" href="<?php print $node_url; ?>">
          <div class="on-image">
            <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
          </div>
        </a>
        <div class="top-text-blk-wht">
          <?php  if(!empty($node->field_movie_group_top_text_black)){ ?>
            <span class="black"><?php print render($content['field_movie_group_top_text_black']);?></span>
          <?php } 
          if(!empty($node->field_movie_group_top_text_white)){ ?>
            <span class="white"><?php print render($content['field_movie_group_top_text_white']);?></span>
          <?php } ?>
        </div> 
      </div>


</article>