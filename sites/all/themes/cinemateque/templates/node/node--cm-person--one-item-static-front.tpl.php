<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

      <div class="one-item-static">
        <div class="image">
          <?php 
          if(!empty($node->field_low_and_wide_for_home_page)){ 
            print render($content['field_low_and_wide_for_home_page']);
          } 
          else{
              print '<img src="/sites/all/themes/cinemateque/images/default-one-item.png">';
          } 
          ?>
          <div class="gradient small"></div>
        </div>
        <a class="all-image" href="<?php print $node_url; ?>">
          <div class="on-image">
            <h2 class="name"><a href="<?php print $node_url; ?>"><?php print render($content['field_cm_person_first_name']); print (" "); print render($content['field_cm_person_last_name']);?></a></h2>
            <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
            <div class="job-title"><?php print render($content['field_cm_person_job_title']); ?>  </div>
          </div>
        </a>
      </div>


</article>