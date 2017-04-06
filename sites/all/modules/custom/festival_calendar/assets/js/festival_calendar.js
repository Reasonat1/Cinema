jQuery(document).ready(function () {
    /*
     * callender event info popup hide show
     */
    jQuery('.calender-full-row .calender-row.inner').click(function () {
        jQuery('#calender-top-popup').remove();
        jQuery('body').append('<div id="calender-top-popup" ></div>');
        var html = jQuery(this).parent().find('.calender-popup').html();
        jQuery('#calender-top-popup').html("");
        jQuery('#calender-top-popup').addClass('visible');
        jQuery('#calender-top-popup').append(html);
        var view_port_width = jQuery(window).width();
        var offset = jQuery(this).offset();
        var toppos = parseFloat(offset.top) + parseFloat(50.00);
        var leftpos = parseFloat(offset.left) + parseFloat(60.00);
 
        var left_view_port = parseFloat(leftpos) + parseFloat(500.00);
        if (left_view_port >= view_port_width) {
            leftpos = parseFloat(leftpos) - parseFloat(500.00);
        }
        jQuery('#calender-top-popup').css('top', toppos + 'px').css('left', leftpos + 'px');
        toptix_purchase_event();       
    });
    /*
     * stop click event over perchage button
     */
    jQuery(".calender-full-row .calender-row.inner .toptix-purchase").click(function(e) {
        e.stopPropagation();
     });
     jQuery(".calender-full-row .calender-row.inner .flag-wrapper .flag").click(function(e) {
        e.stopPropagation();
     });
     
    /**
     * using Ajax filter the  calender event
     */
    jQuery('.calender .calender-filter > p').click(function () {
        jQuery('.calender .calender-filter > p').removeClass('active');
        jQuery(this).addClass('active');
        var filterdate = jQuery(this).find('.filter-date.element-invisible').text();
        url = Drupal.settings.basePath + "ajax_complex_calender";
        jQuery.ajax({
            type: 'post',
            url: url,
            dataType: 'json',
            data: {
                filterdate: filterdate,
            },
            success: function (data) {
                jQuery('.ajax-inner').replaceWith(data.output);
                toptix_purchase_event();

            }
        });
    });

    /**
     * calender scroll effect
     * @param {type} param
     */
    var content_width = 0;
    jQuery('.calender-full-row:first-child .custom-row.calender-row').each(function () {
        content_width = parseInt(content_width) + parseInt(217);
    })
    content_width = parseInt(content_width) +parseInt(20);
    jQuery('.calender-body').css('width', content_width + 'px');
    jQuery('.scroll-date').css('width', jQuery('.ajax-inner').width());
    jQuery('.calender-header').css('width', content_width+57 + 'px');
    var body_width = jQuery(window).width();
    if (content_width > body_width) {
        var sliderLimit = parseInt(content_width) - parseInt(body_width);
        jQuery('.scrollright').click(function () {
            var currentPosition = parseInt(jQuery('.calender-body').css("left"));
            if (currentPosition < 0) 
                currentPosition *= -1;
            if (currentPosition < sliderLimit) {
                jQuery('.calender-body').stop(false, true).animate({left: "-=" + 217}, "slow");
                jQuery('.calender-header').stop(false, true).animate({left: "-=" + 217}, "slow");
				jQuery('.scrollright').toggleClass('inactive');
				jQuery('.scrollleft').toggleClass('inactive');
            }
        });
        jQuery('.scrollleft').click(function () {
            var currentPosition = parseInt(jQuery('.calender-body').css("left"));
            currentPosition *= -1;
            if (currentPosition > 0) {
                jQuery('.calender-body').stop(false, true).animate({left: "+=" +217}, "slow");
                jQuery('.calender-header').stop(false, true).animate({left: "+=" + 217}, "slow");
				jQuery('.scrollright').toggleClass('inactive');
				jQuery('.scrollleft').toggleClass('inactive');
            }
        });
    }else{
        jQuery('.calender-scroll').html('');
    }
jQuery('.calender-row .time').css('margin-top','0');
});

jQuery(document).ajaxStop(function () {

	
    jQuery('.calender-full-row .calender-row.inner').click(function () {
        jQuery('#calender-top-popup').remove();
        jQuery('body').append('<div id="calender-top-popup" ></div>');        
        var html = jQuery(this).parent().find('.calender-popup').html();
        jQuery('#calender-top-popup').html("");
        jQuery('#calender-top-popup').addClass('visible');
        jQuery('#calender-top-popup').append(html);
        var view_port_width = jQuery(window).width();

        var offset = jQuery(this).offset();
        var toppos = parseFloat(offset.top) + parseFloat(50.00);
        var leftpos = parseFloat(offset.left) + parseFloat(60.00);

        var left_view_port = parseFloat(leftpos) + parseFloat(500.00);
        if (left_view_port >= view_port_width) {
            leftpos = parseFloat(leftpos) - parseFloat(500.00);
        }
        jQuery('#calender-top-popup').css('top', toppos + 'px').css('left', leftpos + 'px');
        toptix_purchase_event();
    });
   /*
     * stop click event over perchage button
     */
    jQuery(".calender-full-row .calender-row.inner .toptix-purchase").click(function(e) {
        e.stopPropagation();
     });   
     jQuery(".calender-full-row .calender-row.inner .flag-wrapper .flag").click(function(e) {
        e.stopPropagation();
     });
     
    /**
     * calender scroll effect
     * @param {type} param
     */
    var content_width = 0;
    jQuery('.calender-full-row:first-child .custom-row.calender-row').each(function () {
        content_width = parseInt(content_width) + parseInt(217);
    })
    content_width = parseInt(content_width) +parseInt(20);
    jQuery('.calender-body').css('width', content_width + 'px');
    jQuery('.scroll-date').css('width', jQuery('.ajax-inner').width());
    jQuery('.calender-header').css('width', content_width+57 + 'px');
    var body_width = jQuery(window).width();
    if (content_width > body_width) {
        var sliderLimit = parseInt(content_width) - parseInt(body_width);
        jQuery('.scrollright').click(function () {
            var currentPosition = parseInt(jQuery('.calender-body').css("left"));
            if (currentPosition < 0)
                currentPosition *= -1;
            if (currentPosition < sliderLimit) {
                jQuery('.calender-body').stop(false, true).animate({left: "-=" + 217}, "slow");
                jQuery('.calender-header').stop(false, true).animate({left: "-=" + 217}, "slow");
            }
        });
        jQuery('.scrollleft').click(function () {
            var currentPosition = parseInt(jQuery('.calender-body').css("left"));
            currentPosition *= -1;
            if (currentPosition > 0) {
                jQuery('.calender-body').stop(false, true).animate({left: "+=" +217}, "slow");
                jQuery('.calender-header').stop(false, true).animate({left: "+=" + 217}, "slow");
            }
        });
    }else{
       jQuery('.calender-scroll').html('');
    }
jQuery('.calender-row .time').css('margin-top','0');
});

function closed() {
    jQuery('.close-calender-popup').parent().parent().removeClass('visible');
}
/**
 *  mobile calender js events
 */
jQuery(document).ready(function () {
    jQuery('.accordian-hall').click(function () {
        if (jQuery(this).hasClass('open')) {
            jQuery(this).removeClass('open');
            jQuery(this).parent().find('.mobile-accordian-content').slideUp(500).hide();
            jQuery(this).find('i').addClass('fa-angle-right');
            jQuery(this).find('i').removeClass('fa-angle-down');
        } else {
            jQuery(this).addClass('open');
            jQuery(this).parent().find('.mobile-accordian-content').slideDown(500).show();
            jQuery(this).find('i').removeClass('fa-angle-right');
            jQuery(this).find('i').addClass('fa-angle-down');
        }
    });

    /**
     * using Ajax filter the  calender event
     */
    jQuery('.mobile-calender .calender-filter > p').click(function () {
        jQuery('.mobile-calender .calender-filter > p').removeClass('active');
        jQuery(this).addClass('active');
        var filterdate = jQuery(this).find('.filter-date.element-invisible').text();
        url = Drupal.settings.basePath + "ajax_complex_calender_mobile";
        jQuery.ajax({
            type: 'post',
            url: url,
            dataType: 'json',
            data: {
                filterdate: filterdate,
            },
            success: function (data) {
                jQuery('.mobile-calender-inner').replaceWith(data.output);
            }
        });
    });
});

jQuery(document).ajaxComplete(function () {
    jQuery('.accordian-hall').click(function () {
        if (jQuery(this).hasClass('open')) {
            jQuery(this).removeClass('open');
            jQuery(this).parent().find('.mobile-accordian-content').slideUp(500).hide();
            jQuery(this).find('i').addClass('fa-angle-right');
            jQuery(this).find('i').removeClass('fa-angle-down');
        } else {
            jQuery(this).addClass('open');
            jQuery(this).parent().find('.mobile-accordian-content').slideDown(500).show();
            jQuery(this).find('i').removeClass('fa-angle-right');
            jQuery(this).find('i').addClass('fa-angle-down');
        }
    });
				//Drupal.attachBehaviors($(context)); //fix ajax link elements loaded after ajax
				jQuery.getScript('/sites/all/modules/flag/theme/flag.js', function() {
					Drupal.behaviors.flagLink.attach(document);
					});	
})

/*
 * toptix purchase event over event popup
 */
function toptix_purchase_event(){
    var toptix_event_url = null;
    var toptix_active_button = {original_text:'', item: null};

    jQuery('.toptix-purchase').click(function(event) {
      toptix_event_url = this.dataset.url;
      toptix_active_button.item = this;
      toptix_active_button.original_text = jQuery(this).text();
      jQuery(this).text(Drupal.t('Loading...'));
      $esro.getCustomerDetails('toptix_callback_get_customer');
    });
}

(function ($) {
	$(document).ready(function(){
	var hallPanel =$('.view-festival-calendar .view-display-id-block_1');
	var hall =$('.view-festival-calendar .view-display-id-block_1').find('.views-row');
	var hallWidth=hall.width();
	var hallHeight=hall.height();
	var hallPanelWidth = hallWidth*6*1.1;
	var hallCount=hall.length;
	var hallLength=hallCount*hallWidth;
	hallPanel.width(hallPanelWidth).height(hallHeight)
	if (hallCount>6){
		var controlButtons = '<div class="hall-next">Next</div><div class="hall-prev">Prev</div>';
	hallPanel.after(controlButtons);
	}
	$('.view-header').delegate('.hall-next', 'click',function(){
		var panelPosition=parseInt(hallPanel.find('.view-content').css('margin-left'));
		if(panelPosition>0-hallLength+hallWidth*6)
		hallPanel.find('.view-content').css('margin-left', panelPosition-hallWidth+'px');
	events_table();
	});
	$('.view-header').delegate('.hall-prev', 'click',function(){
		var panelPosition=parseInt(hallPanel.find('.view-content').css('margin-left'));
		if(panelPosition<0)
		hallPanel.find('.view-content').css('margin-left', panelPosition+hallWidth+'px');
	events_table();
	});
	events_table();
	
	});
function events_table(){
	var myPanels=$("div[class*='hall-panel-']");
	$.each(myPanels, function(index, item) {
		var classList = $(item).attr('class').split(/\s+/);
	$.each(classList, function(ind, item_class) {
		if (~item_class.indexOf("hall-panel-")){
			var event_position=$('.'+item_class).position();
			var hall_top=event_position.top;
			var hall_panel=$('.view-festival-calendar .view-display-id-block_1').find('.view-content');
			var hal_panel_y=hall_panel.position().top;
			var event_class=item_class.replace("hall-panel-","");
			$('.'+event_class).offset({ left : event_position.left});
			if (hall_top != hal_panel_y) {$('.'+event_class).hide();} else {$('.'+event_class).show();}
		}
		});
});}
})(jQuery);
