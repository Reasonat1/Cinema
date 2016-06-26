 /**
 * @file
 * Custom scripts for theme.
 */
(function ($) {
    // Add your code here.
    /**
     * Hamburger menu popup
     */
    $(document).ready(function () {
        
        $screenheight = $(window).height()-55;
        $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
        $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
        $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
        $(".node-type-cm-movie-group .panels-flexible-row-node_page-3").height($screenheight);
        $(".node-type-cm-movie-group .panels-flexible-row-node_page-3 .inside").height($screenheight);
        $(".node-type-cm-movie-group .views-slideshow-cycle-main-frame").height($screenheight);

       
        $(window).resize(function() {
        	$screenheight = $(window).height()-55;
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
            $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
        });
    });

})(jQuery);