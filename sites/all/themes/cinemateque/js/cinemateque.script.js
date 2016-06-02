/**
 * @file
 * Custom scripts for theme.
 */
(function ($) {
  // Add your code here.
    /**
   * Hamburger menu popup
   */
  $(document).ready(function(){
      var hamburgergpopupmenu = $('.panels-flexible-row.panels-flexible-row-custom_front_panel-4.clearfix.popup.region').html();
      $('.modal-body').append(hamburgergpopupmenu);
  });
  
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
