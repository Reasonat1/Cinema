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
        $(".front .custom-slideshow, .front .custom-slideshow li").css("max-height",$fullscreenheight);
        $(".node-type-cm-article .view-article-ct-panes.view-display-id-panel_pane_1").css("max-height",$screenheight);
        $(".node-type-webform .view-webform-ct-panes.view-display-id-panel_pane_1").css("max-height",$screenheight);


        $(window).resize(function() {
            $screenheight = $(window).height()-50;
            $fullscreenheight = $(window).height();
            $(".movie-group-slide-container").css("max-height",$screenheight);
            $(".node-type-cm-movie .panels-flexible-region-node_page-slider-inside").css("max-height",$screenheight);
            $(".node-type-cm-movie .views_slideshow_cycle_main .content").css("max-height",$screenheight);
            $(".front .custom-slideshow, .front .custom-slideshow li").css("max-height",$fullscreenheight);
            $(".node-type-cm-event .panels-flexible-region-node_page-slider-inside").css("max-height",$screenheight);
            $(".node-type-cm-event .views_slideshow_cycle_main .content").css("max-height",$screenheight);
            $(".node-type-cm-article .view-article-ct-panes.view-display-id-panel_pane_1").css("max-height",$screenheight);
            $(".node-type-webform .view-webform-ct-panes.view-display-id-panel_pane_1").css("max-height",$screenheight);
        });

        $(".header-right .search span").click(function() {
            if (!$("div").hasClass("screen-search")){
                $("#header").prepend("<div class='screen-search'></div>");
            }
        });

        $(".popup-close-button").click(function() {
                $(".screen-search").remove();
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

       /******Hide Other screening ****/
    if($('.pane-event-ct-view-panel-pane-5 .view-content .hide-table').length){
        $('.pane-event-ct-view-panel-pane-5 h2.pane-title').hide();
    }
    if($('.view-display-id-panel_pane_1 .view-content .views_slideshow_cycle_slide .views-field-field-cm-event-images img').length){
        $('.pane-event-ct-view-panel-pane-9').hide();
    }
      /*****Table Header hide if empty value*******/
        if($('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-time .hide-div').length){
             $('.view-event-ct-view thead th.views-field-field-cm-event-time').hide();
        }
        if($('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-time-1 .hide-div').length){
            $('.view-event-ct-view thead th.views-field-field-cm-event-time-1').hide();
        }
        if($('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-hall .hide-div').length){
            $('.view-event-ct-view thead th.views-field-field-cm-event-hall').hide();
        }
        if($('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-short-title .hide-div').length){
            $('.view-event-ct-view thead th.views-field-field-cm-event-short-title').hide();
        }
        if($('.view-event-ct-view tr.item-show-1 .views-field-field-cm-event-internal-id .hide-div').length){
            $('.view-event-ct-view thead th.views-field-field-cm-event-internal-id').hide();
        }
        if($('.view-event-ct-view tr.item-show-1 .views-field-field-toptix-purchase .hide-div').length){
            $('.view-event-ct-view thead th.views-field-field-toptix-purchase').hide();
        }
        /** if short event title is empty print reference Movie title*/
        $('#cm-event-node-form .form-item-field-cm-event-lineup-und-0-target-id').on('click', function(){
            str = $('#cm-event-node-form .form-item-field-cm-event-lineup-und-0-target-id #edit-field-cm-event-lineup-und-0-target-id').val();
            var tempStr = str.split('(');
            var mainStr = tempStr[0];
            if( !$('#cm-event-node-form #edit-field-cm-event-short-title-und-0-value').val() ) {
                $('#cm-event-node-form #edit-field-cm-event-short-title-und-0-value').val(mainStr);
            }
            if( !$('#cm-event-node-form .pane-node-form-title .form-item-title #edit-title').val() ) {
                 $('#cm-event-node-form .pane-node-form-title .form-item-title #edit-title').val(mainStr);
            } 
        });
        $( ".pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.field-content span:last-child" ).addClass('no-space-bar');
        $('.pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.field-content span.no-space-bar').each(function () {
            var tempStrs = $(this).text().slice(0,-3)
            $(this).text(tempStrs);
        });

    });

   /******Hide Other screening ****/
    if($('.hide-table').length){
        $('.pane-event-ct-view-panel-pane-5 h2.pane-title').hide();
    }

  document.addEventListener("DOMContentLoaded", function() {
      var elements = document.getElementsByTagName("INPUT");
      for (var i = 0; i < elements.length; i++) {
          elements[i].oninvalid = function(e) {
              e.target.setCustomValidity("");
              if (!e.target.validity.valid) {
                  var message = Drupal.t('Please fill out this field');
                  e.target.setCustomValidity(message);
              }
              if (e.target.validity.typeMismatch) {
                  var message = Drupal.t('Please fill out a valid email');
                  e.target.setCustomValidity(message);
              }
          };
          elements[i].oninput = function(e) {
              e.target.setCustomValidity("");
          };
      }

  })

})(jQuery);

