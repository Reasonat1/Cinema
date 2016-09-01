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
            else{
                $(".screen-search").remove();
            }
        });

        $(".popup-close-button").click(function() {
                $(".screen-search").remove();
        });
/*
        $(document).click(function(event) { 
          if(!$(event.target).closest('.center .center').length) {
              $(".screen-search").remove();             
          }        
        }); */
     /*** Removed  | bar***/
    var tempBar = $('.i18n-en .view-id-movie_top_pane_view.view-display-id-panel_pane_2 .slide-movie-year .crdt').text().slice(0,-2)
    var barHtml = $('.i18n-en .view-id-movie_top_pane_view.view-display-id-panel_pane_2 .slide-movie-year .mnts').html();
    if(barHtml == ''){
        $('.i18n-en .view-id-movie_top_pane_view.view-display-id-panel_pane_2 .slide-movie-year .crdt').text(tempBar);
    }
     /****Add class in Movie Events table****/
     $('.view-id-movie_top_pane_view.view-display-id-panel_pane_7 table tbody tr').addClass('up-events-item-movie');

     /*****Rename Minitue***/
        $('.i18n-he .pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.length-movie').each(function () {
            $(this).html($(this).html().replace('minute',' דקות '));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .pane-panopoly-database-search-search-database-results .lobby-length').each(function () {
            $(this).html($(this).html().replace('minute','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-user-flagged-content .lobby-length').each(function () {
            $(this).html($(this).html().replace('minute','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-display-id-panel_pane_6 .views-field-nothing .field-content').each(function () {
            $(this).html($(this).html().replace('minute','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-display-id-panel_pane_4 .views-field-nothing .field-content').each(function () {
            $(this).html($(this).html().replace('minute','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-display-id-panel_pane_2 .views-field-nothing .slide-movie-year').each(function () {
            $(this).html($(this).html().replace('minute','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .pane-event-ct-view-panel-pane-3 .views-field-nothing .slide-movie-year').each(function () {
            $(this).html($(this).html().replace('m',' דקות '));
        });
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
		upcoming_events_header_visibility();

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
  
	function upcoming_events_header_visibility() {
		//Flags initially set to hide the respective headers
		var event_date_flag = true;
		var event_time_flag = true;
		var event_hall_flag = true;
		var event_title_flag = true;
		var event_id_flag = true;
		var event_purchase_flag = true;
        var event_title1_flag = true;
		jQuery(".up-events-item-movie").each(function(index) {
			if( !$(this).children('.views-field-field-cm-event-time').children('.hide-div').length ){
				event_date_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
			if( !$(this).children('.views-field-field-cm-event-time-1').children('.hide-div').length ){
				event_time_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
			if( !$(this).children('.views-field-field-cm-event-hall').children('.hide-div').length ){
				event_hall_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
			if( !$(this).children('.views-field-title').children('.hide-div').length ){
				event_title_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
            if( !$(this).children('.views-field-title-1').children('.hide-div').length ){
				event_title1_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
			if( !$(this).children('.views-field-field-cm-event-internal-id').children('.hide-div').length ){
				event_id_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
			if( !$(this).children('.views-field-field-toptix-purchase').children('.hide-div').length ){
				event_purchase_flag = false; // data for one row is visible. no need to hide the header. unset the flag.
			}
		});	
		// validation. if the flag is still set, hide the header
		if( event_date_flag ){
			$('thead th.views-field-field-cm-event-time').hide();
            $('td.views-field-field-cm-event-time').hide();
		}
		if( event_time_flag ){
		   $('th.views-field-field-cm-event-time-1').hide();
           $('td.views-field-field-cm-event-time-1').hide();
		}
		if( event_hall_flag ){
		   $('thead th.views-field-field-cm-event-hall').hide();
           $('td.views-field-field-cm-event-hall').hide();
		}
		if( event_title_flag ){
		   $('thead th.views-field-title').hide();
           $('td.views-field-title').hide();
		}
        if( event_title1_flag ){
		   $('thead th.views-field-title-1').hide();
           $('td.views-field-title-1').hide();
		}
		if( event_id_flag ){
		   $('thead th.views-field-field-cm-event-internal-id').hide();
           $('td.views-field-field-cm-event-internal-id').hide();
		}
		if( event_purchase_flag ){
		   $('th.views-field-field-toptix-purchase').hide();
           $('td.views-field-field-toptix-purchase').hide();
		}
	}

})(jQuery);
