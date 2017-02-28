<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
            <?php if (render($content['field_cm_article_image'])){
              print render($content['field_cm_article_image']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="gradient small"></div>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_article_top_text_black)){ ?>
                <span class="black"><?php print render($content['field_article_top_text_black']);?></span>
              <?php } 
              if(!empty($node->field_article_top_text_white)){ ?>
                <span class="white"><?php print render($content['field_article_top_text_white']);?></span>
              <?php } ?>
          </div> 
      </div>
      <a class="all-image" href="<?php print $node_url; ?>">
        <div class="on-image">
          <h2 class="title"><?php print $title; ?></h2>
          <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
        </div>
      </a>
  </div>


</article>