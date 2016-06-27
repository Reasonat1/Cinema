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
            }
        });
    });

    /**
     * calender scroll effect
     * @param {type} param
     */
    var content_width = 0;
    jQuery('.calender-full-row:first-child .custom-row.calender-row').each(function () {
        content_width = parseInt(content_width) + parseInt(240);
    })
    content_width = parseInt(content_width) +parseInt(20);
    jQuery('.calender-body').css('width', content_width + 'px');
    jQuery('.calender-header').css('width', content_width + 'px');
    var body_width = jQuery(window).width();
    if (content_width > body_width) {
        var sliderLimit = parseInt(content_width) - parseInt(body_width);
        jQuery('.scrollleft').click(function () {
            var currentPosition = parseInt(jQuery('.calender-body').css("left"));
            if (currentPosition < 0)
                currentPosition *= -1;
            if (currentPosition < sliderLimit) {
                jQuery('.calender-body').stop(false, true).animate({left: "-=" + 240}, "slow");
                jQuery('.calender-header').stop(false, true).animate({left: "-=" + 240}, "slow");
            }
        });
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
    });
    /**
     * calender scroll effect
     * @param {type} param
     */
    var content_width = 0;
    jQuery('.calender-full-row:first-child .custom-row.calender-row').each(function () {
        content_width = parseInt(content_width) + parseInt(240);
    })
    content_width = parseInt(content_width) +parseInt(20);
    jQuery('.calender-body').css('width', content_width + 'px');
    jQuery('.calender-header').css('width', content_width + 'px');
    var body_width = jQuery(window).width();
    if (content_width > body_width) {
        var sliderLimit = parseInt(content_width) - parseInt(body_width);
        jQuery('.scrollleft').click(function () {
            var currentPosition = parseInt(jQuery('.calender-body').css("left"));
            if (currentPosition < 0)
                currentPosition *= -1;
            if (currentPosition < sliderLimit) {
                jQuery('.calender-body').stop(false, true).animate({left: "-=" + 240}, "slow");
                jQuery('.calender-header').stop(false, true).animate({left: "-=" + 240}, "slow");
            }
        });
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