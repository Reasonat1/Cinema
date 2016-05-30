 jQuery(document).ready(function() {

    var hamburgergpopupmenu = jQuery('.panels-flexible-row.panels-flexible-row-custom_front_panel-4.clearfix.popup.region').html();
    jQuery('.modal-body').append(hamburgergpopupmenu);
    
    /*
     * callender event info popup hide show
     */
     jQuery('.calender-full-row .calender-row.inner').click(function(){
         var html = jQuery(this).parent().find('.calender-popup').html();    
         jQuery('#calender-top-popup').html("");
         jQuery('#calender-top-popup').addClass('visible');
         jQuery('#calender-top-popup').append(html);
         var view_port_width = jQuery(window).width();
         
         var offset =  jQuery(this).offset();
         var toppos = parseFloat(offset.top) + parseFloat(50.00);
         var leftpos = parseFloat(offset.left) + parseFloat(60.00);
         
         var left_view_port =  parseFloat(leftpos) + parseFloat(500.00);
         if(left_view_port >= view_port_width){
             leftpos = parseFloat(leftpos) - parseFloat(500.00);
         }
          jQuery('#calender-top-popup').css('top',toppos+'px').css('left',leftpos+'px');
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
    
    /**
     * calender scroll effect
     * @param {type} param
     */
    var content_width = 0;
    jQuery('.calender-full-row:first-child .custom-row.calender-row').each(function(){
        content_width = parseInt(content_width) + parseInt(240);
    })

    jQuery('.calender-body').css('width', content_width+'px');
    jQuery('.calender-header').css('width', content_width+'px');
    var body_width = jQuery(window).width();
    if(content_width > body_width){
        var sliderLimit = parseInt(content_width)-parseInt(body_width);
        jQuery('.scrollleft').click(function(){
              var currentPosition = parseInt(jQuery('.calender-body').css("left"));
              if(currentPosition<0)currentPosition*=-1;
              if(currentPosition < sliderLimit){  
                jQuery('.calender-body').stop(false,true).animate({left:"-="+240}, "slow");
                jQuery('.calender-header').stop(false,true).animate({left:"-="+240}, "slow");
            }
        });
    }

});

jQuery( document ).ajaxStop(function() {
        jQuery('.calender-full-row .calender-row.inner').click(function(){
         var html = jQuery(this).parent().find('.calender-popup').html();    
         jQuery('#calender-top-popup').html("");
         jQuery('#calender-top-popup').addClass('visible');
         jQuery('#calender-top-popup').append(html);
         var view_port_width = jQuery(window).width();
         
         var offset =  jQuery(this).offset();
         var toppos = parseFloat(offset.top) + parseFloat(50.00);
         var leftpos = parseFloat(offset.left) + parseFloat(60.00);
         
         var left_view_port =  parseFloat(leftpos) + parseFloat(500.00);
         if(left_view_port >= view_port_width){
             leftpos = parseFloat(leftpos) - parseFloat(500.00);
         }
          jQuery('#calender-top-popup').css('top',toppos+'px').css('left',leftpos+'px');
     });
   /**
     * calender scroll effect
     * @param {type} param
     */
     var content_width = 0;
    jQuery('.calender-full-row:first-child .custom-row.calender-row').each(function(){
        content_width = parseInt(content_width) + parseInt(240);
    })

    jQuery('.calender-body').css('width', content_width+'px');
    jQuery('.calender-header').css('width', content_width+'px');
    var body_width = jQuery(window).width();
    if(content_width > body_width){
        var sliderLimit = parseInt(content_width)-parseInt(body_width);
        jQuery('.scrollleft').click(function(){
              var currentPosition = parseInt(jQuery('.calender-body').css("left"));
              if(currentPosition<0)currentPosition*=-1;
              if(currentPosition < sliderLimit){  
               jQuery('.calender-body').stop(false,true).animate({left:"-="+240}, "slow");
               jQuery('.calender-header').stop(false,true).animate({left:"-="+240}, "slow");
           }
        });
    }
    
});

jQuery(window).load(function() {
    jQuery('.flexslider').flexslider({
            animation: "slide"
    });
});

function closed(){
  jQuery('.close-calender-popup').parent().parent().removeClass('visible');
}