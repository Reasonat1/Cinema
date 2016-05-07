/**
 * @file
 * Custom scripts for theme.
 */
(function ($) {
  // Add your code here.

})(jQuery);
  jQuery(window).scroll(function() { 
   if( jQuery(window).scrollTop() >29 && !(jQuery('#header').hasClass('sticky-header')))
    {
     jQuery('#header').addClass('sticky-header');
    }
  else if (jQuery(window).scrollTop() == 0){
    jQuery('#header').removeClass('sticky-header');
  }
});
