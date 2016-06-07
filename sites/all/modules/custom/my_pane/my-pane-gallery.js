Drupal.settings.gallery_settings = Drupal.settings.gallery_settings || {};

(function ($) {

$('.custom-slideshow').cycle({
    fx: 'scrollHorz',
    prev:    '#prev2', 
    next:    '#next2', 
  });

$('.caruosel-slideshow').cycle({
    fx: 'scrollHorz',
    prev:    '#prev', 
    next:    '#next', 
  });
  
$(".caruosel-slideshow").mouseover(function(){
    $(this).cycle('pause');
}).mouseout(function(){
    $(this).cycle('resume');
});
    
  $( document ).ajaxComplete(function() {
        $('.custom-slideshow').cycle({
            fx: 'scrollHorz',
            prev:    '#prev2', 
            next:    '#next2', 
          });
      $('.caruosel-slideshow').cycle({
            fx: 'scrollHorz',
            prev:    '#prev', 
            next:    '#next', 
       });
  });
  
})(jQuery);
