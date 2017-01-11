<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
      	    <?php if (render($content['field_cm_person_photo'])){
              print render($content['field_cm_person_photo']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/user-default.png">';
            } ?>
            <div class="gradient very-small"></div>
      </div>
      <div class="on-image">
        <h2 class="name"><a href="<?php print $node_url; ?>"><?php print render($content['field_cm_person_first_name']); print (" "); print render($content['field_cm_person_last_name']);?></a></h2>
        <div class="job-title"><?php print render($content['field_cm_person_job_title']); ?>  </div>
      </div>
  </div>


</article>