<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="list_wide_image">
      <div class="left-area">
            <?php if (render($content['field_cm_moviegroup_pictures'])){
              print render($content['field_cm_moviegroup_pictures']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_movie_group_top_text_black)){ ?>
                <span class="black"><?php print render($content['field_movie_group_top_text_black']);?></span>
              <?php } 
              if(!empty($node->field_movie_group_top_text_white)){ ?>
                <span class="white"><?php print render($content['field_movie_group_top_text_white']);?></span>
              <?php } ?>
          </div> 
      </div>
      <div class="right-area">
		<div class="screaning"><?php print screaning_output($node->nid, 'movie_group'); ?></div>
        <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
        <div class="only-duration"><?php print render($content['field_cm_moviegroup_duration']); ?>  </div>
        <div class="short-summary"><?php print render($content['field_cm_moviegroup_short_summar']); ?>  </div>
      </div>
  </div>


</article>