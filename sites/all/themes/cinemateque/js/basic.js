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
        $(".node-type-cm-movie-group .panels-flexible-row-node_page-3, .node-type-cm-movie .panels-flexible-row-node_page-3").height($screenheight);
        $(".movie-group-slide-container").height($screenheight);

       
        $(window).resize(function() {
        	$screenheight = $(window).height()-55;
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
            $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
            $(".node-type-cm-movie-group .panels-flexible-row-node_page-3, .node-type-cm-movie .panels-flexible-row-node_page-3").height($screenheight);
            $(".movie-group-slide-container").height($screenheight);
        });

        $screenwidth = $(window).width();
        $(".node-type-cm-event .views_slideshow_cycle_main img, .node-type-cm-movie-group .panels-flexible-row-node_page-3 .views_slideshow_main img").width($screenwidth);
        $(".movie-group-slide-container").width($screenwidth);
        $(window).resize(function() {
            $screenwidth = $(window).width();
            $(".node-type-cm-event .views_slideshow_cycle_main img, .node-type-cm-movie-group .panels-flexible-row-node_page-3 .views_slideshow_main img").width($screenwidth);
            $(".movie-group-slide-container").width($screenwidth);
        });

        $imagebiger = ($(".node-type-cm-event .views_slideshow_cycle_main img").height() - $screenheight)/2;
        if ($imagebiger>0){
            $(".node-type-cm-event .views_slideshow_cycle_main img").css("top",$imagebiger*-1);
        }
        $(window).resize(function() {
        $imagebiger = ($(".node-type-cm-event .views_slideshow_cycle_main img").height() - $screenheight)/2;
            if ($imagebiger>0){
                $(".node-type-cm-event .views_slideshow_cycle_main img").css("top",$imagebiger*-1);
            }
        });
    });

})(jQuery);