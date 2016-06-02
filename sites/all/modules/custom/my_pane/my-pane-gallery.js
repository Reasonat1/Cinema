Drupal.settings.gallery_settings = Drupal.settings.gallery_settings || {};

(function ($) {

$('.custom-slideshow').cycle({
    fx: 'scrollHorz',
    prev:    '#prev2', 
    next:    '#next2', 
  });

$('.field-name-field-custom-caruosel-sponser .field-items').cycle({
    fx: 'scrollHorz',
    prev:    '#prev', 
    next:    '#next', 
  });
  
  $( document ).ajaxComplete(function() {
        $('.custom-slideshow').cycle({
            fx: 'scrollHorz',
            prev:    '#prev2', 
            next:    '#next2', 
          });
      $('.field-name-field-custom-caruosel-sponser .field-items').cycle({
            fx: 'scrollHorz',
            prev:    '#prev', 
            next:    '#next', 
       });
  });
  
})(jQuery);
