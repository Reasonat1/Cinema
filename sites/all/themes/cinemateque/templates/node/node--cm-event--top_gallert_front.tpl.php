<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="top_gallert_front">
    <div class="full-screen-image">
      <div class="gallery">
            <?php print render($content['field_cm_event_images']); ?>
            <div class="gradient"></div>
      </div>
    </div>
    <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
    <div class="text-main-image">
      <div class="wrapper">
        <div class="slide-left-ct">
          <div class="slide-big-text film-title"><?php print render($content['field_cm_event_lineup']); ?></div>
          <div class="slide-small-text extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
          <div class="slide-small-text short-title"><?php print render($content['field_cm_event_short_title']); ?></div>
          <div class="slide-small-text time"><?php print render($content['field_cm_event_time']); ?></div>
          <div class="purchase"><?php print render($content['field_toptix_purchase']); ?></div>
        </div>
      </div>
    </div>
  </div>

</article>


<script>
    jQuery(function(){  
      jQuery('.gallery .field-name-field-cm-event-images .field-items').owlCarousel({
        rtl: true,
        autoplay:false,
        autoplayTimeout:5000,
        autoplayHoverPause:true,
        loop:true,
        margin:0,
        nav: true,
        responsive:{
          0:{
            items:1
          }
        }
      }); 
    });
</script>