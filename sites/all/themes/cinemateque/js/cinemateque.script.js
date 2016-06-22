/**
 * @file
 * Custom scripts for theme.
 */
(function ($) {
    // Add your code here.
    /**
     * Hamburger menu popup
     */
    $(document).ready(function () {
        
        $('#myModal').remove();
        var html = '<div id="myModal" class="modal fade hamburger" role="dialog"><div class="modal-dialog">Modal content <div class="modal-content"> <img src="http://localhost/localsetup/jercin/sites/all/themes/cinemateque/images/close42.png" class="close" data-dismiss="modal"/><div class="modal-body"></div></div> </div></div>';
        $('body').append(html);
        
        $('.hambruger.-menu.navbar-toggle').click(function () {
            $('.modal-body').html('');
            $('.modal-body').html('<img src="http://www.volantski.com/season1516/images/loadingIMG.gif" class="popup-loader">');            
            $('.modal-body').load("http://jer-cin.tikkewebsites.com/menu div.region-content");
        });

    });

})(jQuery);
jQuery(window).scroll(function () {
    if (jQuery(window).scrollTop() > 29 && !(jQuery('#header').hasClass('sticky-header')))
    {
        jQuery('#header').addClass('sticky-header');
    }
    else if (jQuery(window).scrollTop() == 0) {
        jQuery('#header').removeClass('sticky-header');
    }
});
