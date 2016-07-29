jQuery(document).ready(function () {
    /**
     * using Ajax filter the  calender event
     */
    jQuery('.calenders .calender-filter > p').click(function () {
        jQuery(".load-inner").addClass('loading');
        jQuery('.calenders .calender-filter > p').removeClass('active');
        jQuery(this).addClass('active');
        var filterdate = jQuery(this).find('.filter-date.element-invisible').text();
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
                jQuery('.ajax-inner').replaceWith(data.output);
                jQuery(".load-inner").removeClass('loading');
                jQuery.getScript(path_url, function() {
                    Drupal.behaviors.flagLink.attach(document);
                });
                jQuery.getScript(cal_path);
            }
        });
    });
    /*****Table Header hide if empty value*******/
        if(jQuery('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-time .hide-div').length){
            jQuery('.view-event-ct-view thead th.views-field-field-cm-event-time').hide();
        }
        if(jQuery('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-time-1 .hide-div').length){
            jQuery('.view-event-ct-view thead th.views-field-field-cm-event-time-1').hide();
        }
        if(jQuery('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-hall .hide-div').length){
            jQuery('.view-event-ct-view thead th.views-field-field-cm-event-hall').hide();
        }
        if(jQuery('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-short-title .hide-div').length){
            jQuery('.view-event-ct-view thead th.views-field-field-cm-event-short-title').hide();
        }
        if(jQuery('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-internal-id .hide-div').length){
            jQuery('.view-event-ct-view thead th.views-field-field-cm-event-internal-id').hide();
        }
        if(jQuery('.view-event-ct-view tr.item-show-1 .views-field-field-toptix-purchase .hide-div').length){
            jQuery('.view-event-ct-view thead th.views-field-field-toptix-purchase').hide();
        }
    /** if short event title is empty print reference Movie title*/
    jQuery('#cm-event-node-form .form-item-field-cm-event-lineup-und-0-target-id').on('click', function(){
        str = jQuery('#cm-event-node-form .form-item-field-cm-event-lineup-und-0-target-id #edit-field-cm-event-lineup-und-0-target-id').val();
        var tempStr = str.split('(');
        var mainStr = tempStr[0];
        if( !jQuery('#cm-event-node-form #edit-field-cm-event-short-title-und-0-value').val() ) {
            jQuery('#cm-event-node-form #edit-field-cm-event-short-title-und-0-value').val(mainStr);
        }
        if( !jQuery('#cm-event-node-form .pane-node-form-title .form-item-title #edit-title').val() ) {
             jQuery('#cm-event-node-form .pane-node-form-title .form-item-title #edit-title').val(mainStr);
        } 
    });
    jQuery( ".pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.field-content span" ).last().addClass( "no-space-bar");
    var tempStrs = jQuery('.pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.field-content span.no-space-bar').text().slice(0,-3)
    jQuery('.pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.field-content span.no-space-bar').text(tempStrs);
});

jQuery(document).ajaxComplete(function () { //Tom added this to make flag work after ajax
	jQuery.getScript('/sites/all/modules/flag/theme/flag.js', function() {
		Drupal.behaviors.flagLink.attach(document);
		});	
})