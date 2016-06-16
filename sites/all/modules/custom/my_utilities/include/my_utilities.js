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
           
           if(jQuery('.top-text-blk-wht .white').is(':empty')){
               jQuery('.top-text-blk-wht').hide();
           }
           if(jQuery('.slide-alt-title .grp-title').html(':empty')){
               jQuery('.slide-alt-title').hide();
           }
});