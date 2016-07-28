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
        $(".movie-group-slide-container").css("max-height",$screenheight);
        $(".node-type-cm-movie .panels-flexible-region-node_page-slider-inside").css("max-height",$screenheight);
        $(".node-type-cm-movie .views_slideshow_cycle_main .content").css("max-height",$screenheight);
        $(".node-type-cm-event .panels-flexible-region-node_page-slider-inside").css("max-height",$screenheight);
        $(".node-type-cm-event .views_slideshow_cycle_main .content").css("max-height",$screenheight);
        $(".front .custom-slideshow").css("max-height",$fullscreenheight);


        $(window).resize(function() {
            $screenheight = $(window).height()-50;
            $fullscreenheight = $(window).height();
            $(".movie-group-slide-container").css("max-height",$screenheight);
            $(".node-type-cm-movie .panels-flexible-region-node_page-slider-inside").css("max-height",$screenheight);
            $(".node-type-cm-movie .views_slideshow_cycle_main .content").css("max-height",$screenheight);
            $(".front .custom-slideshow").css("max-height",$fullscreenheight);
            $(".node-type-cm-event .panels-flexible-region-node_page-slider-inside").css("max-height",$screenheight);
            $(".node-type-cm-event .views_slideshow_cycle_main .content").css("max-height",$screenheight);
        });


/*
        if (($("body").hasClass("page-node-3261")) || ($("body").hasClass("page-node-3284"))){
            $(document).ready(function() {
              $('.calender-filter').scrollToFixed({ marginTop: 50});
              $('.calender-filter-date, .calender-scroll').scrollToFixed({ marginTop: 120});
              $('.calender-header').scrollToFixed({ marginTop: 160});
            });
            $.ajax({
                complete: function() {
              $('.calender-filter').scrollToFixed({ marginTop: 50});
              $('.calender-filter-date, .calender-scroll').scrollToFixed({ marginTop: 120});
              $('.calender-header').scrollToFixed({ marginTop: 160});                },
            });

        }
*/
    if (($("body").hasClass("page-node-3261")) || ($("body").hasClass("page-node-3284"))){
        $(document).scroll(function(e) {
            var detectrange = 50;
            $scroll_pos = $(this).scrollTop();
            var scrolltop = $(window).scrollTop() + detectrange;
            if ((scrolltop > $(".calender-filter").offset().top)){
                $("body").addClass('scroll-calendar');
            }
            if($scroll_pos <= 0) {
                $("body").removeClass('scroll-calendar');
            }
        });
    }


    });

})(jQuery);