jQuery(document).ready(function(e) {
           jQuery('.view-display-id-panel_pane_3 .views-table tbody tr:nth-child(1)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_3 .views-table tbody tr:nth-child(2)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_3 .views-table tbody tr:nth-child(3)').addClass("item-show");    
           jQuery('.view-footer .more-event').click(function(){
                 jQuery('.view-display-id-panel_pane_3 .views-table tbody tr.up-events-item-movie').show('slow');
           });
           
           jQuery('.view-display-id-panel_pane_5 .table tbody tr:nth-child(1)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_5 .table tbody tr:nth-child(2)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_5 .table tbody tr:nth-child(3)').addClass("item-show");   
           jQuery('.view-display-id-panel_pane_5 .more-event').click(function(){
                 jQuery('.view-display-id-panel_pane_5 .table tbody tr.common-row').show('slow');
           });
           jQuery('.view-display-id-panel_pane_5 .more-event').hide();
            if(jQuery('.view-display-id-panel_pane_5 .table tbody tr.row-custom-4').length){
                      jQuery('view-display-id-panel_pane_5 .more-event').show();
           }
           jQuery(".view-id-movie_group_ct.view-display-id-panel_pane_1 .img a>img").unwrap();
           
           //if(!jQuery.trim( jQuery('.top-text-blk-wht .white').html() ) == true){
           //    jQuery('.top-text-blk-wht').hide();
           //}
           if(!jQuery.trim( jQuery(".slide-alt-title .grp-title").html() ) == true){
               jQuery('.slide-alt-title').hide();
           }
           if(!jQuery.trim( jQuery("td.views-field-field-toptix-purchase").html() ) == true){
               jQuery('th.views-field-field-toptix-purchase').hide();
           }
                      if(!jQuery.trim( jQuery("td.views-field-field-cm-event-internal-id").html() ) == true){
               jQuery('th.views-field-field-cm-event-internal-id').hide();
           }
           if(!jQuery.trim( jQuery("td.views-field-field-cm-event-hall").html() ) == true){
               jQuery('th.views-field-field-cm-event-hall').hide();
           }
           if(!jQuery.trim( jQuery("td.views-field-title").html() ) == true){
               jQuery('th.views-field-title').hide();
           }
           if(!jQuery.trim( jQuery("td.views-field-field-cm-event-time").html() ) == true){
               jQuery('th.views-field-field-cm-event-time').hide();
           }
           if(!jQuery.trim( jQuery("td.views-field-field-cm-event-time-1").html() ) == true){
               jQuery('th.views-field-field-cm-event-time-1').hide();
           }
           if(jQuery('.movie-group-slide-container .movie-group-slide').length){
				jQuery('.slide-over-content').addClass('image-yes');
			}
           if(jQuery('.movie-group-slide-container .movie-group-slide . file-image .content .panopoly-image-original').length){
				jQuery('.views_slideshow_cycle_main').addClass('image-true');
			}
            
});