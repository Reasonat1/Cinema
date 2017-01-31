jQuery(document).ready(function () {
    /**
     * using Ajax filter the  calender event
     */
    jQuery('.calenders .calender-filter > p').click(function () {
        jQuery(".load-inner").addClass('loading');
        jQuery('.calenders .calender-filter > p').removeClass('active');
        jQuery(this).addClass('active');
        var filterdate = jQuery(this).find('.filter-date.element-invisible').text();
		if (typeof(Storage) !== "undefined") {
			localStorage.setItem("calendar_item", filterdate);
			localStorage.removeItem("languege_change");
		}
        url = Drupal.settings.basePath + "ajax_complex_calender_full_width";
        jQuery.ajax({
            type: 'post',
            url: url,
            dataType: 'json',
            data: {
                filterdate: filterdate,
            },
            success: function (data) {
                var path_url = Drupal.settings.basePath + 'sites/all/modules/flag/theme/flag.js';
                var cal_path = Drupal.settings.basePath + 'sites/all/modules/custom/my_utilities/include/atemay.js';
                var cal_path_ticket = Drupal.settings.basePath + 'sites/all/modules/cinematic_custom/cinematic_toptix/frame.js';
                jQuery('.ajax-inner').replaceWith(data.output);
                jQuery(".load-inner").removeClass('loading');
                jQuery.getScript(path_url, function() {
                    Drupal.behaviors.flagLink.attach(document);
                });
                jQuery.getScript(cal_path);
                jQuery.getScript(cal_path_ticket, function(){Drupal.behaviors.toptix_frame.attach(document);});
            }
        });
    });
	
	if (typeof(Storage) !== "undefined") {
	jQuery('a.language-link').click(function () {
		localStorage.setItem("languege_change", 1);
	});
	var calendar_item=localStorage.getItem("calendar_item");
	var languege_change=localStorage.getItem("languege_change");
	localStorage.removeItem("languege_change");
	localStorage.removeItem("calendar_item");
	if (calendar_item && languege_change) {
		var currentItem=jQuery('.filter-date.element-invisible:contains('+calendar_item+')').parent();
		jQuery(currentItem).click();	
		}
	}
});
/*
jQuery(document).ajaxComplete(function () { //Tom added this to make flag work after ajax
	jQuery.getScript('/sites/all/modules/flag/theme/flag.js', function() {
		Drupal.behaviors.flagLink.attach(document);
		});	
})*/