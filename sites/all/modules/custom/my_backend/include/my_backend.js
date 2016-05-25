 jQuery(document).ready(function() {

    var hamburgergpopupmenu = jQuery('.panels-flexible-row.panels-flexible-row-custom_front_panel-4.clearfix.popup.region').html();
    jQuery('.modal-body').append(hamburgergpopupmenu);
    jQuery('.calender-full-row .calender-row.inner').click(function(){
         jQuery(this).parent().find('.calender-popup').addClass('visible');         
     });
    jQuery('.close-calender-popup').click(function(){
        jQuery(this).parent().removeClass('visible');                                             
    });
});
