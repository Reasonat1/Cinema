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
        
     


        //$screenheight = $(windows).height()-55;
        //$(".panels-flexible-row-node_page-3 .panels-flexible-region-inside-last").height($screenheight);
      /**
        * news letter check box disabled and already check
        */
         jQuery('.webform-client-form .webform-component--approve-recieving-e-mail .form-checkbox').attr('disabled',true);
         jQuery('.webform-client-form .webform-component--approve-recieving-e-mail .form-checkbox').prop('checked', true);
     });
    /**
     * Trigger event on ajax complete
     */
     jQuery(document).ajaxComplete(function () {
           jQuery('.webform-client-form .webform-component--approve-recieving-e-mail .form-checkbox').attr('disabled',true);
           jQuery('.webform-client-form .webform-component--approve-recieving-e-mail .form-checkbox').prop('checked', true);
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
