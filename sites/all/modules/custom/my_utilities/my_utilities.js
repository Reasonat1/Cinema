jQuery(document).ready(function(e) {
           jQuery('.left-custom-pane-event').wrapAll('<div class="new-parent-left"></div>');
           jQuery('.slide-bottom-content').wrapAll('<div class="slide-parent-content"></div>');
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
});