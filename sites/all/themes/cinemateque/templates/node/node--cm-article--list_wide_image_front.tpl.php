<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="list_wide_image">
      <div class="left-area">
            <a class="all-image" href="<?php print $node_url; ?>"></a>
            <?php if (render($content['field_cm_article_image'])){
              print render($content['field_cm_article_image']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_article_top_text_black)){ ?>
                <span class="black"><?php print render($content['field_article_top_text_black']);?></span>
              <?php } 
              if(!empty($node->field_article_top_text_white)){ ?>
                <span class="white"><?php print render($content['field_article_top_text_white']);?></span>
              <?php } ?>
          </div> 
      </div>
      <div class="right-area">
        <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="sub-title"><?php print render($content['field_cm_article_subtitle']); ?>  </div>
        <div class="short-summary"><?php print render($content['field_short_sammary_article']); ?>  </div>
      </div>
  </div>


</article>