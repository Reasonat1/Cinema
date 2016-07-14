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
        

        $screenheight = $(window).height()-50;
        $fullscreenheight = $(window).height();
        if ($(".page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").height() > $screenheight){
            $(".page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").height($screenheight);
        }
        if ($(".front .pane-bundle-gallery").height() > $fullscreenheight){
            $(".front .pane-bundle-gallery").height($fullscreenheight);
        }
        if ($(".node-type-cm-event .panels-flexible-row-node_page-3").height() > $screenheight){
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
            $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
        }
        if ($(".node-type-cm-movie-group .panels-flexible-row-node_page-3").height() > $screenheight){
            $(".node-type-cm-movie-group .panels-flexible-row-node_page-3").css("height",$screenheight);
            $(".movie-group-slide-container").height($screenheight);
        }
        if ($(".node-type-cm-movie .panels-flexible-row-node_page-3").height() > $screenheight){
                $(".node-type-cm-movie .panels-flexible-row-node_page-3").css("height",$screenheight);
        }
        $(window).resize(function() {
            $(".page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").css("height","auto");
            $screenheight = $(window).height()-50;
            $fullscreenheight = $(window).height();
            if ($(".page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").height() > $screenheight){
                $(".page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").css("height",$screenheight);
            }
            $(".front .pane-bundle-gallery").css("height","auto");
            if ($(".front .pane-bundle-gallery").height() > $fullscreenheight){
                $(".front .pane-bundle-gallery").css("height",$fullscreenheight);
            }
            if ($(".node-type-cm-event .panels-flexible-row-node_page-3").height() > $screenheight){
                $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
                $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
                $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
            }
            $(".node-type-cm-movie-group .panels-flexible-row-node_page-3").css("height","auto");
            if ($(".node-type-cm-movie-group .panels-flexible-row-node_page-3").height() > $screenheight){
                $(".node-type-cm-movie-group .panels-flexible-row-node_page-3").css("height",$screenheight);
                $(".movie-group-slide-container").css("height",$screenheight);
            }
            if ($(".node-type-cm-movie .panels-flexible-row-node_page-3").height() > $screenheight){
                $(".node-type-cm-movie .panels-flexible-row-node_page-3").css("height",$screenheight);
            }
        });

  /*      $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
        $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
        $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
        $(".node-type-cm-movie-group .panels-flexible-row-node_page-3, .node-type-cm-movie .panels-flexible-row-node_page-3, .page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").height($screenheight);
        $(".movie-group-slide-container").height($screenheight);
        $fullscreenheight = $(window).height();
        $(".front .pane-bundle-gallery").height($fullscreenheight);
       
        $(window).resize(function() {
        	$screenheight = $(window).height()-50;
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .panels-flexible-region-inside").height($screenheight);
            $(".node-type-cm-event .panels-flexible-row-node_page-3 .pane-event-ct-view-panel-pane-1").height($screenheight);
            $(".node-type-cm-event .views-slideshow-cycle-main-frame").height($screenheight);
            $(".node-type-cm-movie-group .panels-flexible-row-node_page-3, .node-type-cm-movie .panels-flexible-row-node_page-3, .page-term-lobby .panels-flexible-row-node_page-1 .pane-lobby-panel-pane-3").height($screenheight);
            $(".movie-group-slide-container").height($screenheight);
            $fullscreenheight = $(window).height();
            $(".front .pane-bundle-gallery").height($fullscreenheight);
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
        $imagebigermovie = ($(".node-type-cm-movie .views_slideshow_cycle_main img").height() - $screenheight)/2;
        if ($imagebiger>0){
            $(".node-type-cm-event .views_slideshow_cycle_main img").css("top",$imagebiger*-1);
        }
        if ($imagebigermovie>0){
            $(".node-type-cm-movie .views_slideshow_cycle_main img").css("top",$imagebigermovie*-1);
        }
        $(window).resize(function() {
            $imagebiger = ($(".node-type-cm-event .views_slideshow_cycle_main img").height() - $screenheight)/2;
            $imagebigermovie = ($(".node-type-cm-movie .views_slideshow_cycle_main img").height() - $screenheight)/2;
            if ($imagebiger>0){
                $(".node-type-cm-event .views_slideshow_cycle_main img").css("top",$imagebiger*-1);
            }
            if ($imagebigermovie>0){
                $(".node-type-cm-movie .views_slideshow_cycle_main img").css("top",$imagebigermovie*-1);
            }
        });

      /     $(window).scroll(function (event) {
                var scroll = $(window).scrollTop();
                if (scroll >= $('.calender-filter').offset().top){
                    $('body').addClass('fixed-header-calendar');
                }
            });
*/
        if (($("body").hasClass("page-node-3261")) || ($("body").hasClass("page-node-3284"))){
            $(document).ready(function() {
              $('.calender-filter').scrollToFixed({ marginTop: 50});
              $('.calender-filter-date, .calender-scroll').scrollToFixed({ marginTop: 120});
              $('.calender-header').scrollToFixed({ marginTop: 160});
            });
        }



    });

})(jQuery);