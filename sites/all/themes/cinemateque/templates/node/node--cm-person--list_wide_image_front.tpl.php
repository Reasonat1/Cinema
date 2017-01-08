<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="list_wide_image">
      <div class="left-area">
            <?php if (render($content['field_cm_person_photo'])){
              print render($content['field_cm_person_photo']); 
            }
            else{
              print '<img src="/sites/all/themes/cinemateque/images/user-default.png">';
            } ?>
      </div>
      <div class="right-area">
        <h2 class="name"><a href="<?php print $node_url; ?>"><?php print render($content['field_cm_person_first_name']); print (" "); print render($content['field_cm_person_last_name']);?></a></h2>
        <div class="job-title"><?php print render($content['field_cm_person_job_title']); ?>  </div>
        <div class="short-summary"><?php print render($content['field_cm_person_body']); ?>  </div>
      </div>
  </div>


</article>