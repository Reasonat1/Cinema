<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="top_gallert_front">
    <div class="full-screen-image-front movie">
      <div class="gallery">
            <?php print render($content['field_cm_moviegroup_pictures']); ?>
      </div>
    </div>
    <div class="text-main-image">
      <div class="wrapper">
        <div class="slide-left-ct">
          <h2 class="title slide-big-text"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
		  <div class="screaning"><?php print screaning_output($node->nid, 'movie_group'); ?></div>
        </div>
      </div>
    </div>
  </div>

</article>