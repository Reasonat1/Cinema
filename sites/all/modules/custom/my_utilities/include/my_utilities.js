jQuery(document).ready(function(e) {

  
           //http://jer-cin.tikkewebsites.com/en/movie/movietest-title
            jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr').hide();
           jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr:lt(3)').show();
           jQuery('.view-event-ct-view.view-display-id-panel_pane_5 tbody tr').hide();
           jQuery('.pane-event-ct-view-panel-pane-5 .pane-title').hide();
           jQuery('.pane-event-ct-view-panel-pane-5 thead').hide();
           jQuery('.view-movie-group-ct.view-display-id-panel_pane_3 tbody tr:lt(3)').show();
          jQuery('.view-footer .more-event .text-close, .more-screening-pane .pane-title').click(function () {
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr').hide();
                      jQuery('.view-movie-group-ct.view-display-id-panel_pane_3 tbody tr').hide();
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr:lt(3)').show();
                      jQuery('.view-movie-group-ct.view-display-id-panel_pane_3 tbody tr:lt(3)').show();
                      jQuery('.view-footer .more-event .text-open').show();
                      jQuery('.view-footer .more-event .text-close').hide();
           });
          jQuery('.view-footer .more-event .text-open-event').click(function () {
                      jQuery('.view-event-ct-view.view-display-id-panel_pane_5 tbody tr').show();
                      jQuery('.pane-event-ct-view-panel-pane-5 .pane-title').show();
                      jQuery('.pane-event-ct-view-panel-pane-5 thead').show();
                      jQuery('.pane-event-ct-view-panel-pane-5 .more-event').addClass("open");
                      jQuery('.view-footer .more-event .text-open-event').hide();
                      jQuery('.view-footer .more-event .text-close-event').css("display","inline-block");
           });
          jQuery('.view-footer .more-event .text-close-event, .more-screening-pane .pane-title').click(function () {
                      jQuery('.view-event-ct-view.view-display-id-panel_pane_5 tbody tr').hide();
                      jQuery('.pane-event-ct-view-panel-pane-5 .pane-title').hide();
                      jQuery('.pane-event-ct-view-panel-pane-5 thead').hide();
                      jQuery('.pane-event-ct-view-panel-pane-5 .more-event').removeClass("open");
                      jQuery('.view-footer .more-event .text-open-event').show();
                      jQuery('.view-footer .more-event .text-close-event').hide();
           });

          jQuery('.pane-movie-top-pane-view-panel-pane-7 .view-footer .more-event .text-open').click(function () {
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr').show();
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 .more-event').addClass("open");
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 .view-footer .more-event .text-open').hide();
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 .view-footer .more-event .text-close').css("display","inline-block");
           });
          jQuery('.pane-movie-top-pane-view-panel-pane-7 .view-footer .more-event .text-close').click(function () {
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr').hide();
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 tbody tr:lt(3)').show();
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 .more-event').removeClass("open");
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 .view-footer .more-event .text-open').show();
                      jQuery('.view-movie-top-pane-view.view-display-id-panel_pane_7 .view-footer .more-event .text-close').hide();
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