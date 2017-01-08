<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="top_gallery_front">
    <div class="full-screen-image-front">
      <div class="gallery">
            <?php print render($content['field_cm_event_images']); ?>
      </div>
    </div>
    <div class="text-main-image">
      <div class="wrapper">
        <div class="slide-left-ct">
          <div class="slide-big-text film-title"><a href="<?php print $node_url; ?>"><?php print render($content['field_cm_event_lineup']); ?></a></div>
          <div class="slide-small-text short-title only-desktop"><?php print render($content['field_cm_event_short_title']); ?></div>
          <div class="slide-small-text time"><?php print render($content['field_cm_event_time']); ?></div>
          <div class="purchase"><?php print render($content['field_toptix_purchase']); ?></div>
        </div>
      </div>
    </div>
  </div>

</article>


<script>
    jQuery(function(){  
      jQuery('.more-items .gallery .field-name-field-cm-event-images .field-items').owlCarousel({
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