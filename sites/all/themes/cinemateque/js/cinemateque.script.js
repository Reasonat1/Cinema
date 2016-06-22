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
        $('.hambruger.-menu.navbar-toggle').click(function(){
            $('.modal-body').load( "http://jer-cin.tikkewebsites.com/menu div.region-content" );
    }); 
    
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
