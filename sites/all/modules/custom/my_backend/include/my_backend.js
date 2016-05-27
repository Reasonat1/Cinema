 jQuery(document).ready(function() {

    var hamburgergpopupmenu = jQuery('.panels-flexible-row.panels-flexible-row-custom_front_panel-4.clearfix.popup.region').html();
    jQuery('.modal-body').append(hamburgergpopupmenu);
    
    /**
     * callender event info popup hide show
     */
    jQuery('.calender-full-row .calender-row.inner').click(function(){
         jQuery(this).parent().find('.calender-popup').addClass('visible');         
     });
    jQuery('.close-calender-popup').click(function(){
        jQuery(this).parent().removeClass('visible');                                             
    });
    
    /*
     * On ready add class active to first child
     */
    jQuery('.calender-filter > p:first-child').addClass('active');
    /**
     * using Ajax filter the  calender event
     */
    jQuery('.calender-filter > p').click(function(){
        jQuery('.calender-filter > p').removeClass('active');
        jQuery(this).addClass('active');
       var filterdate = jQuery(this).find('.filter-date.element-invisible').text();
       url = Drupal.settings.basePath + "ajax_complex_calender";
       jQuery.ajax({
           type : 'post',
           url : url,
          dataType:'json',
         data : {
               filterdate : filterdate, 
           },
         success:function(data){
        // alert(data.output);
         jQuery('.ajax-inner').replaceWith(data.output);
          }
       });
    });
    
});

jQuery( document ).ajaxStop(function() {
        jQuery('.calender-full-row .calender-row.inner').click(function(){
           jQuery(this).parent().find('.calender-popup').addClass('visible');         
       });
       jQuery('.close-calender-popup').click(function(){
           jQuery(this).parent().removeClass('visible');                                             
       });    
});
