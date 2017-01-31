<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
      	    <?php if (render($content['field_cm_person_photo'])){
              print render($content['field_cm_person_photo']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="gradient very-small"></div>
      </div>
      <a class="all-image" href="<?php print $node_url; ?>">
        <div class="on-image">
          <h2 class="name"><?php print render($content['field_cm_person_first_name']); print (" "); print render($content['field_cm_person_last_name']);?></h2>
        <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
          <div class="job-title"><?php print render($content['field_cm_person_job_title']); ?>  </div>
        </div>
      </a>
  </div>


</article>