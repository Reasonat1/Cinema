jQuery(document).ready(function(e) {
           //http://jer-cin.tikkewebsites.com/en/movie/movietest-title
           jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr:lt(3)').show();
           jQuery('.view-event-ct-view.view-display-id-panel_pane_5 tbody tr:lt(3)').show();
           jQuery('.view-movie-group-ct.view-display-id-panel_pane_3 tbody tr:lt(3)').show();
           jQuery('.view-footer .more-event').click(function () {
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr:lt(10)').show();
                      jQuery('.view-event-ct-view.view-display-id-panel_pane_5 tbody tr:lt(10)').show();
                      jQuery('.view-movie-group-ct.view-display-id-panel_pane_3 tbody tr:lt(10)').show();
                      jQuery('.view-footer .more-event').hide();
           });
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