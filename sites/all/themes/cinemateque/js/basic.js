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

        /****  person page  ***/
      $(".view-person-ct-view.view-display-id-panel_pane_1 .col").each(function(){
          if ( $(this).children(".col-container").children().length == 0 ) {
              $(this).hide();
          }
      });

/****Search page Read more***/
    $('#search-main-page .lobby-term-right .table-responsive tbody tr').css('display','none');  
    $('#search-main-page .lobby-term-right .table-responsive tbody').each(function () {
        $(this).children('tr:lt(3)').show();
            $(this).parent().parent().children('.view-footer').children().click(function(){
                $(this).parent().parent().children('.table').children('tbody').children('tr:lt(13)').show();
                $(this).hide();
            })
    });
 /*******  responsive menu   **********/

    $(".responsive-hamburger").click(function(){
        if ($("body").hasClass("responsive-hamburger-open")){
          $("body").removeClass("responsive-hamburger-open");
        }
        else {
          $("body").addClass("responsive-hamburger-open");
          $("body").removeClass("search-overlay");
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
        $(".full-screen-image, .full-screen-image .wrapper-image .content, .full-screen-image .wrapper-image .content li").css("max-height",$screenheight);
        $(".front .full-screen-image, .front .full-screen-image .wrapper-image .content").css("max-height",$fullscreenheight);
       /* $imgspace = ($(".full-screen-image img").height() - $screenheight)/(-2);
        if ($imgspace < 0){
          $(".full-screen-image img").css("margin-top",$imgspace);
        }
*/
        $(window).resize(function() {
            $screenheight = $(window).height()-50;
            $fullscreenheight = $(window).height();
            $(".full-screen-image, .full-screen-image .wrapper-image .content, .full-screen-image .wrapper-image .content li").css("max-height",$screenheight);
            $(".front .full-screen-image, .front .full-screen-image .wrapper-image .content").css("max-height",$fullscreenheight);
  /*          $imgspace = ($(".full-screen-image img").height() - $screenheight)/(-2);
            if ($imgspace < 0){
              $(".full-screen-image img").css("margin-top",$imgspace);
            }*/
        });

/*********  claendat pane on slider  

        $calendarheight = ($screenheight - $(".pane-custom-calendar-floating-pane-panel-pane-1").height())/2+50;
        if ($calendarheight > 50){
          $(".pane-custom-calendar-floating-pane-panel-pane-1").css("top",$calendarheight);
        }

        $(window).resize(function() {
          $calendarheight = ($screenheight - $(".pane-custom-calendar-floating-pane-panel-pane-1").height())/2+50;
          if ($calendarheight > 50){
            $(".pane-custom-calendar-floating-pane-panel-pane-1").css("top",$calendarheight);
          }
          else{
            $(".pane-custom-calendar-floating-pane-panel-pane-1").css("top","50");
          }
        });
******/
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
/********  videos  ********/

        $(".slide-right-ct .play-button").click(function(ev) {
            $(".slide-right-ct .video-wrapper").addClass("play");
            $("body").addClass("play");
            $(".media-youtube-player")[0].src += "&enablejsapi=1&version=3&playerapiid=ytplayer&autoplay=1";
            ev.preventDefault();
            $("video").play();
        });

        $('.video-wrapper').on('click', function(e) {
          if($(e.target).closest('.video-wrapper .content').length == 0) {
            $(".slide-right-ct .video-wrapper").removeClass("play");
            $("body").removeClass("play");
            $(".media-youtube-player")[0].contentWindow.postMessage('{"event":"command","func":"' + 'stopVideo' + '","args":""}', '*');  
            e.preventDefault();
            

          }
      });

/********  mini calendar  ********/

        $(".front .float-calendar-wrapper").removeClass("hide-float");
        $(".front").addClass("show-float-calendar");
        $(".not-front body").addClass("hide-float-calendar");

        $(".float-calendar-wrapper .close").click(function() {
            $(".float-calendar-wrapper").addClass("hide-float");
            $("body").addClass("hide-float-calendar");
            $("body").removeClass("show-float-calendar");
        });

        $(".header-right .today").click(function() {
            $(".float-calendar-wrapper").toggleClass("hide-float");
            $("body").toggleClass("hide-float-calendar");
            $("body").toggleClass("show-float-calendar");
            $("body").removeClass("responsive-hamburger-open");
            $("body").removeClass("search-overlay");
        });

        /*$(".calendar-agenda-items").css("width",$(".view-custom-calendar-floating-pane").width());*/
        var halfscreen = ($(window).height())/2; 
        $(".view-custom-calendar-floating-pane.view-display-id-block_1 .view-content").css("max-height",halfscreen);

        $(window).resize(function() {
          /*$(".calendar-agenda-items").css("width",$(".view-custom-calendar-floating-pane").width());*/
          var halfscreen = ($(window).height())/2 
          $(".view-custom-calendar-floating-pane.view-display-id-block_1 .view-content").css("max-height",halfscreen);
        });




/*******  calendar fixed  area*********/

        
          $(window).scroll(function() {
                $targetScroll = $('body').position().top+$(".view-article-ct-panes").height();
                $currentScroll = $('html').scrollTop() || $('body').scrollTop();
                if ($currentScroll >= $targetScroll){
                    $('.filter-wrapper').addClass("fixedPos");
                }
                else{
                    $('.filter-wrapper').removeClass("fixedPos");
                }                
          });

        $(window).resize(function() {
          $(window).scroll(function() {
                $targetScroll = $('body').position().top+$(".view-article-ct-panes").height();
                $currentScroll = $('html').scrollTop() || $('body').scrollTop();
                if ($currentScroll >= $targetScroll){
                    $('.filter-wrapper').addClass("fixedPos");
                }
                else{
                    $('.filter-wrapper').removeClass("fixedPos");
                }                
          });
        });

        if ($(window).width() < 768){
          $filterwidth = $(".calender-filter p").size()*70+30;
          $(".calender-filter").css("width",$filterwidth);
          $maxleft = ($filterwidth - $(window).width())*(-1)-30; 
          $left = 0;
          $i = 0;
          $('.calender-filter p').each(function () {
            if (!$(this).hasClass("active")){
              $i ++;
            }
            if ($(this).hasClass("active")){
              return false;            
            }
          });
          $left = $left + (-70)*($i-1);
          if ($left < $maxleft){
              $left = $maxleft;
          }
          if ($left > 0){
              $left = 0;
          }
          $(".i18n-en .calender-filter").css("margin-left",$left);
          $(".i18n-he .calender-filter").css("margin-right",$left);
          $(".calender-filter p").click(function(){
            $left = 0;
            $i = 0
            $('.calender-filter p').each(function () {
              if (!$(this).hasClass("active")){
                $i ++;
              }
              if ($(this).hasClass("active")){
                return false;            
              }
            });
            $left = $left + (-70)*($i-1);
            if ($left < $maxleft){
              $left = $maxleft;
            }
            if ($left > 0){
              $left = 0;
            }
            $(".i18n-en .calender-filter").css("margin-left",$left);
            $(".i18n-he .calender-filter").css("margin-right",$left);
          });
          $(".nextday").click(function(){
            if ($left > $maxleft){
              $left = $left - 70;
              if ($left < $maxleft){
                $left = $maxleft;
              }
              $(".i18n-en .calender-filter").css("margin-left",$left);
              $(".i18n-he .calender-filter").css("margin-right",$left);   
            }
          });
          $(".prevday").click(function(){
            if ($left < 0){
              $left = $left + 70;
              if ($left > 0){
                $left = 0;
              }
              $(".i18n-en .calender-filter").css("margin-left",$left);
              $(".i18n-he .calender-filter").css("margin-right",$left);
              }
          });
        }

        $(".calender-filter p").click(function(){
            //$("html, body").animate({ scrollTop: $(".calenders").offset().top -60 }, 500);
            $(".filter-wrapper").removeClass("fixedPos");
        });

        $(window).resize(function() {
        if ($(window).width() > 767){
          $(".calender-filter").css("margin","50px auto");
        }
        if ($(window).width() < 768){
          $filterwidth = $(".calender-filter p").size()*70+30;
          $(".calender-filter").css("width",$filterwidth);
          $maxleft = ($filterwidth - $(window).width())*(-1)-30; 
          $left = 0;
          $i = 0;
          $('.calender-filter p').each(function () {
            if (!$(this).hasClass("active")){
              $i ++;
            }
            if ($(this).hasClass("active")){
              return false;            
            }
          });
          $left = $left + (-70)*($i-1);
          if ($left < $maxleft){
              $left = $maxleft;
          }
          if ($left > 0){
              $left = 0;
          }
          $(".i18n-en .calender-filter").css("margin-left",$left);
          $(".i18n-he .calender-filter").css("margin-right",$left);
        }
        });

/********  items of review  *******/
          
        if ($(".view-review-mobile .views-row").length == '1') { 
          $(".view-review-mobile").addClass("one-item");
        }
        else{
          $(".view-review-mobile").addClass("more-items");
        }

        if ($(".full-screen-image .views-row").length == '1') { 
          $(".full-screen-image").addClass("one-item");
        }
        else{
          $(".full-screen-image").addClass("more-items");
        }
        
/******  search overlay  ******/

        $(".header-right .search span").click(function() {
            if ($("body").hasClass("search-overlay")){
                $("body").removeClass("search-overlay");
            }
            else{
                $("body").addClass("search-overlay");
                $("body").removeClass("responsive-hamburger-open");
            }
        });

        $('.region-overlay').on('click', function(e) {
          if($(e.target).closest('#search-api-page-search-form-search-results').length == 0) {
              $("body").removeClass("search-overlay");
          }
      });


      $(document).keyup(function(e) {
           if (e.keyCode == 27) { // escape key maps to keycode `27`
                $("body").removeClass("search-overlay");
          }
      });
/******  big hamburger menu  overlay  ******/

        $(".hambruger.navbar-toggle").click(function() {
            if ($("body").hasClass("hambruger-overlay")){
                $("body").removeClass("hambruger-overlay");
            }
            else{
                $("body").addClass("hambruger-overlay");
            }
        });

        $(".pane-custom .close").click(function() {
                $("body").removeClass("hambruger-overlay");
        });
        

/*

        $(".popup-close-button").click(function() {
                $("body").removeClass("search");
        });
          $(document).click(function(event) { 
            if ($("body").hasClass("search")){
              if(!$(event.target).closest('#popup-active-overlay .center').length) {
                $("body").removeClass("search");
                $(".popup-element-body").css("display","none");
                $(".screen-search").remove();
              }        
            }
        });

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

    /********  Show Title to image in movie slideshow  *******/
    if($('.group-alttab .field-name-field-file-image-title-text').text().length > 0){
        $('.group-alttab .field-name-field-file-image-alt-text').hide();
    }
    else{
        $('.group-alttab').hide();
    }

    /********  english name of the movie  *******/

    var proffesionwidth = $(".credits-view .profession").width()+8;
    $(".i18n-he .view-test-view-for-movie-credit .translated-movie-title a").css("margin-right", proffesionwidth);
    $(".i18n-en .view-test-view-for-movie-credit .translated-movie-title a").css("margin-left", proffesionwidth);

    $(window).resize(function() {
      var proffesionwidth = $(".credits-view .profession").width()+8;
      $(".i18n-he .view-test-view-for-movie-credit .translated-movie-title a").css("margin-right", proffesionwidth);
      $(".i18n-en .view-test-view-for-movie-credit .translated-movie-title a").css("margin-left", proffesionwidth);
    });

    /********  Show Title to image in movie group slideshow  *******/

    $(".views-field-field-cm-moviegroup-pictures .image-alt-title").each(function(){
        $(this).children('.grp-alt').hide();
        if($(this).children('.grp-title').text().length == 0){
             $(this).hide();
        }
    });


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
        $('.i18n-he .pane-movie-group-ct-panel-pane-1 .movie-group-item-meta-info span.length-movie').each(function () {
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
        $( ".pane-movie-group-ct-panel-pane-1 .movie-group-item-meta-info span.field-content span.space-bar:last-child" ).addClass('no-space-bar');
        $('.pane-movie-group-ct-panel-pane-1 .movie-group-item-meta-info span.field-content span.no-space-bar').each(function () {
            var tempStrs = $(this).text().slice(0,-2)
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
