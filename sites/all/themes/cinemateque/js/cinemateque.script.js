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
        var html = '<div id="myModal" class="modal fade hamburger" role="dialog"><div class="modal-dialog"><div class="modal-content"> <img src="/sites/all/themes/cinemateque/images/close42.png" class="close" data-dismiss="modal"/><div class="modal-body"></div></div> </div></div>';
        $('body').append(html);
        
     
        $('.hambruger.-menu.navbar-toggle').click(function () {
            var host = $(location).attr('hostname')
            var path = 'http://'+host+'/menu';            
            $('.modal-body').html('');
            $('.modal-body').html('<img src="http://www.volantski.com/season1516/images/loadingIMG.gif" class="popup-loader">');            
            $('.modal-body').load(path+" #main .region-content");
        });

        //$screenheight = $(windows).height()-55;
        //$(".panels-flexible-row-node_page-3 .panels-flexible-region-inside-last").height($screenheight);
      /**
        * news letter check box disabled
        */
        jQuery('.webform-client-form .webform-component--approve-recieving-e-mail .form-checkbox').attr('disabled',true);
     });
    /**
     * Trigger event on ajax complete
     */
     jQuery(document).ajaxComplete(function () {
          jQuery('.webform-client-form .webform-component--approve-recieving-e-mail .form-checkbox').attr('disabled',true);
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
