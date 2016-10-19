jQuery(document).ready(function(e) {
           /****Show first 3 rows future event pane*****/
           jQuery('.view-display-id-panel_pane_3 .views-table tbody tr:nth-child(1)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_3 .views-table tbody tr:nth-child(2)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_3 .views-table tbody tr:nth-child(3)').addClass("item-show");    
           jQuery('.view-footer .more-event').click(function(){
                jQuery('.view-display-id-panel_pane_3 .views-table tbody tr.up-events-item-movie').show('slow');
           });
          jQuery('.view-display-id-panel_pane_3 .more-event').hide();
            if(jQuery('.view-display-id-panel_pane_3 .table tbody tr.row-custom-4').length){
                jQuery('.view-display-id-panel_pane_3 .more-event').show();
           }
           jQuery('.view-display-id-panel_pane_5 .table tbody tr:nth-child(1)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_5 .table tbody tr:nth-child(2)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_5 .table tbody tr:nth-child(3)').addClass("item-show");   
           jQuery('.view-display-id-panel_pane_5 .more-event').click(function(){
                jQuery('.view-display-id-panel_pane_5 .table tbody tr.common-row').show('slow');
           });
           jQuery('.view-display-id-panel_pane_5 .more-event').hide();
            if(jQuery('.view-display-id-panel_pane_5 .table tbody tr.row-custom-4').length){
                jQuery('.view-display-id-panel_pane_5 .more-event').show();
           }
           jQuery('.view-display-id-panel_pane_7 .table tbody tr:nth-child(1)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_7 .table tbody tr:nth-child(2)').addClass("item-show");
           jQuery('.view-display-id-panel_pane_7 .table tbody tr:nth-child(3)').addClass("item-show");   
           jQuery('.view-display-id-panel_pane_7 .more-event').click(function(){
                jQuery('.view-display-id-panel_pane_7 .table tbody tr.common-row').show('slow');
           });
           jQuery('.view-display-id-panel_pane_7 .more-event').hide();
            if(jQuery('.view-display-id-panel_pane_7 .table tbody tr.row-custom-4').length){
                jQuery('.view-display-id-panel_pane_7 .more-event').show();
           }
          /****End Show first 3 rows future event pane*****/
           jQuery(".view-id-movie_group_ct.view-display-id-panel_pane_1 .img a>img").unwrap();
           /***Add class in movie group slider****/
           if(jQuery('.movie-group-slide-container .movie-group-slide').length){
				jQuery('.slide-over-content').addClass('image-yes');
			}
           if(jQuery('.movie-group-slide-container .movie-group-slide .file-image .content .panopoly-image-original').length){
				jQuery('.views_slideshow_cycle_main').addClass('image-true');
			}
            if(jQuery('.pane-event-ct-view-panel-pane-1 #views_slideshow_cycle_main_event_ct_view-panel_pane_1 .hide-div').length){
				jQuery('.pane-event-ct-view-panel-pane-1').addClass('without-image-event');
                jQuery('.slide-over-content').addClass('without-image-event-title');
                jQuery(".node-type-cm-event .pane-event-ct-view-panel-pane-3 .view-event-ct-view .views-field-nothing").css("bottom", "1rem");
			}
            
});