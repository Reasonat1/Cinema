<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_special_3_item">
      <div class="image-wrapper">
        <div class="image">
              <?php if (render($content['field_cm_moviegroup_pictures'])){
                print render($content['field_cm_moviegroup_pictures']); 
              }
              else{
                print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
              } ?>
              <div class="gradient very-small"></div>
                    </div>

              <div class="top-text-blk-wht">
                <?php  if(!empty($node->field_movie_group_top_text_black)){ ?>
                  <span class="black"><?php print render($content['field_movie_group_top_text_black']);?></span>
                <?php } 
                if(!empty($node->field_movie_group_top_text_white)){ ?>
                  <span class="white"><?php print render($content['field_movie_group_top_text_white']);?></span>
                <?php } ?>
            </div> 
        <div class="on-image">
          <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        </div>
      </div>
      <div class="short-text">
        <?php print render($content['field_cm_moviegroup_short_summar']);?>
      </div>
  </div>


</article>