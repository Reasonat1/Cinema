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
        $('.fb-share').click(function(e) {
            e.preventDefault();
            window.open($(this).attr('href'), 'fbShareWindow', 'height=450, width=550, top=' + ($(window).height() / 2 - 275) + ', left=' + ($(window).width() / 2 - 225) + ', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
            return false;
        });


    //  person page
      $(".view-person-ct-view.view-display-id-panel_pane_1 .col").each(function(){
          if ( $(this).children(".col-container").children().length == 0 ) {
              $(this).hide();
          }
      });

 /*******  responsive menu   **********/

    $(".responsive-hamburger").click(function(){
        if ($("body").hasClass("responsive-hamburger-open")){
          $("body").removeClass("responsive-hamburger-open");
        }
        else {
          $("body").addClass("responsive-hamburger-open");
        }
    });

    $("#main-wrapper").click(function(){
        if ($("body").hasClass("responsive-hamburger-open")){
          $("body").removeClass("responsive-hamburger-open");
        }
    });

    $("#site-main-menu a.dropdown-toggle .caret").click(function(){
        if ($(this).parent().parent().hasClass("responsive-open")){
          $(this).parent().parent().removeClass("responsive-open");
        }
        else {
          $("#site-main-menu .dropdown").each(function(){
            $(this).removeClass("responsive-open");
          });
          $(this).parent().parent().addClass("responsive-open");
        }    
    });


    /******  images height   ************/


        $screenheight = $(window).height()-50;
        $fullscreenheight = $(window).height();
        $(".full-screen-image, .full-screen-image .wrapper-image .content").css("max-height",$screenheight);
        $(".front .full-screen-image, .front .full-screen-image .wrapper-image .content").css("max-height",$fullscreenheight);
        $(window).resize(function() {
            $screenheight = $(window).height()-50;
            $fullscreenheight = $(window).height();
            $(".full-screen-image, .wrapper-image .content").css("max-height",$screenheight);
            $(".front .full-screen-image, .front .full-screen-image .wrapper-image .content").css("max-height",$fullscreenheight);
        });


   /********  movie group slide height   ******/

 /*       $(".views-slideshow-cycle-main-frame-row").each(function() {
          if ($(this).css('display') == 'block'){
            $imageheight = $(this, " img").height();
            return false;
          }
        });
        $("#views_slideshow_cycle_teaser_section_movie_group_ct-panel_pane_2").css("height",$imageheight);

        
        $(window).resize(function() {
          $(".views-slideshow-cycle-main-frame-row").each(function() {
            if ($(this).css('display') == 'block'){
              $imageheight = $(this, " img").height();
              return false;
            }
          });
          $("#views_slideshow_cycle_teaser_section_movie_group_ct-panel_pane_2").css("height",$imageheight);
        });
*/

        $(".header-right .search span").click(function() {
            if (!$("div").hasClass("screen-search")){
                $("#header").prepend("<div class='screen-search'></div>");
                $("body").addClass("search");
            }
            else{
                $(".screen-search").remove();
                $("body").removeClass("search");
            }
        });

        $(".popup-close-button").click(function() {
                $(".screen-search").remove();
                $("body").removeClass("search");
        });
/*
        $(document).click(function(event) { 
          if(!$(event.target).closest('.center .center').length) {
              $(".screen-search").remove();             
          }        
        }); */
    /****Add active class in views slide show****/
 /*   $('#views_slideshow_cycle_teaser_section_movie_group_ct-panel_pane_2').cycle({
         fx: 'fade',
         speed: 'slow',
         timeout: 5000,
         before: function(){
               $(this).parent('#views_slideshow_cycle_teaser_section_movie_group_ct-panel_pane_2').find('.active-slide').removeClass('active-slide');
         },
          after: function(){
               $(this).addClass('active-slide');
         }
    });*/
     /*** Removed  | bar***/
    var tempBar = $('.view-id-movie_top_pane_view.view-display-id-panel_pane_2 .slide-movie-year .crdt').text().slice(0,-2)
    var barHtml = $('.view-id-movie_top_pane_view.view-display-id-panel_pane_2 .slide-movie-year .mnts').html();
    if(barHtml == ''){
        $('.view-id-movie_top_pane_view.view-display-id-panel_pane_2 .slide-movie-year .crdt').text(tempBar);
    }
    
    var tempBars = jQuery('.view-id-event_ct_view.view-display-id-panel_pane_3 .slide-movie-year .crdt').text().slice(0,-2)
    var barHtmls = jQuery('.view-id-event_ct_view.view-display-id-panel_pane_3 .slide-movie-year .mnts').html();
    if(barHtmls == ''){
        jQuery('.view-id-event_ct_view.view-display-id-panel_pane_3 .slide-movie-year .crdt').text(tempBars);
    }
    if($('.view-id-movie_top_pane_view.view-display-id-panel_pane_4 .hide-div-movie').length){
        $('.view-id-movie_top_pane_view.view-display-id-panel_pane_4 .sub-title').hide();
    }
     /****Add class in Movie Events table****/
     $('.view-id-movie_top_pane_view.view-display-id-panel_pane_7 table tbody tr').addClass('up-events-item-movie');

     /*****Rename Minitue***/
        $('.i18n-he .pane-movie-group-ct-panel-pane-1 .movie-gorup-item-meta-info span.length-movie').each(function () {
            $(this).html($(this).html().replace('minutes',' דקות '));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .pane-panopoly-database-search-search-database-results .lobby-length').each(function () {
            $(this).html($(this).html().replace('minutes','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-user-flagged-content .lobby-length').each(function () {
            $(this).html($(this).html().replace('minutes','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-display-id-panel_pane_6 .views-field-nothing .field-content').each(function () {
            $(this).html($(this).html().replace('minutes','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-display-id-panel_pane_4 .views-field-nothing .field-content').each(function () {
            $(this).html($(this).html().replace('minutes','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .view-display-id-panel_pane_2 .views-field-nothing .slide-movie-year').each(function () {
            $(this).html($(this).html().replace('minutes','דקות'));
            $(this).html($(this).html().replace('דקות',' דקות '));
        });
        $('.i18n-he .pane-event-ct-view-panel-pane-3 .views-field-nothing .slide-movie-year').each(function () {
            $(this).html($(this).html().replace('minutes',' דקות '));
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
			$('thead th.views-field-field-cm-event-time').css("font-size","0");
       //     $('td.views-field-field-cm-event-time').hide();
		}
		if( event_time_flag ){
		   $('th.views-field-field-cm-event-time-1').css("font-size","0");
        //   $('td.views-field-field-cm-event-time-1').hide();
		}
		if( event_hall_flag ){
		   $('thead th.views-field-field-cm-event-hall').css("font-size","0");
       //   $('td.views-field-field-cm-event-hall').hide();
		}
		if( event_title_flag ){
		   $('thead th.views-field-title').css("font-size","0");
       //    $('td.views-field-title').hide();
		}
        if( event_title1_flag ){
		   $('thead th.views-field-title-1').css("font-size","0");
       //    $('td.views-field-title-1').hide();
		}
		if( event_id_flag ){
		   $('thead th.views-field-field-cm-event-internal-id').css("font-size","0");
       //    $('td.views-field-field-cm-event-internal-id').hide();
		}
		if( event_purchase_flag ){
		   $('th.views-field-field-toptix-purchase').css("font-size","0");
       //    $('td.views-field-field-toptix-purchase').hide();
		}
	}



})(jQuery);
