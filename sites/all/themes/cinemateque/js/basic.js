 /**
 * @file
 * Custom scripts for theme.
 */
(function ($) {
	Drupal.behaviors.basicjs = {
  attach: function (context, settings) {
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


/*****  reister block  ********/

if (($("body").hasClass("page-node-4879")) || ($("body").hasClass("page-node-4878"))){
    $('.register-block .group-name-group input').each(function () {
      $(this).val("");
    });
}

/******  message area  ******/

$(".region-messages").css("display","block");

$("#main-wrapper").css("margin-top",$("header").height());
if ($(window).width()>767){
  $(".front #main-wrapper").css("margin-top",$(".region-messages").height());
}
$(".float-calendar-wrapper").css("top",$("header").height()+10);
$(".filter .filter-wrapper").css("margin-top",$("header").height());
$(window).load(function() {
  $("#main-wrapper").css("margin-top",$("header").height());
  if ($(window).width()>767){
    $(".front #main-wrapper").css("margin-top",$(".region-messages").height());
  }
  $(".more-halls").css("top",$("header").height()+120);
});

$(window).resize(function() {
  $("#main-wrapper").css("margin-top",$("header").height());
  if ($(window).width()>767){
    $(".front #main-wrapper").css("margin-top","0");
  }
});

$( document ).ajaxComplete(function() {
  $("#main-wrapper").css("margin-top",$("header").height());
  if ($(window).width()>767){
    $(".front #main-wrapper").css("margin-top",$(".region-messages").height());
  }
  $(".front #main-wrapper").css("margin-top","0");
  $(".float-calendar-wrapper").css("top",$("header").height()+10);
  $(".filter .filter-wrapper").css("margin-top",$("header").height());
  $(".more-halls").css("top",$("header").height()+120);
});

function setAgreeCookie() {
    var expire=new Date();
    expire=new Date(expire.getTime()+86400000);
    document.cookie="MSG=yes; expires="+expire+"; path=/";
}

var visit=GetCookie("MSG");
if (visit=="yes"){
   $('body').addClass('close-message-cookies');
   $("#main-wrapper").css("margin-top",$("header").height());
   if ($(window).width()>767){
    $(".front #main-wrapper").css("margin-top","0");
   }
   $(".float-calendar-wrapper").css("top",$("header").height()+10);
   $(".filter .filter-wrapper").css("margin-top",$("header").height());
   $(window).load(function() {
     $(".more-halls").css("top",$("header").height()+120);
   });
}

$('.view-global-message.view-display-id-block .close-message').click(function(){ 
    setAgreeCookie();
    $('body').addClass('close-message-cookies');
    $("#main-wrapper").css("margin-top",$("header").height());
    if ($(window).width()>767){
      $(".front #main-wrapper").css("margin-top","0");
    }
    $(".float-calendar-wrapper").css("top",$("header").height()+10);
    $(".filter .filter-wrapper").css("margin-top",$("header").height());
    $(".more-halls").css("top",$("header").height()+120);
});

function GetCookie(name) {
    var arg=name+"=";
    var arglen=arg.length;
    var dclen=document.cookie.length;
    var i=0;

    while (i<dclen) {
        var j=i+arglen;
            if (document.cookie.substring(i,j)==arg)
                return "yes";
                i=document.cookie.indexOf(" ",i)+1;
            if (i==0) 
                break;
    }
    return null;
}
/*
$(window).load(function() {
  var i = 1;
  $('.view-global-message.view-display-id-block.more-items .owl-dot').each(function(){
    $(this).children("span").text(i);
    i++;
  });
});*/

/****click shopping card***/

$(".shopping-cart button").click(function(){
  $("div.shopping-cart").addClass("active");
});


$(document).click(function(event) { 
  if(!$(event.target).closest('.shopping-cart button').length) {
    if (!($("div").hasClass("ui-widget-overlay"))){
      $("div.shopping-cart").removeClass("active");
    }
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

    if ($("body").hasClass("page-search")){
      $(".text-center a").click(function(){
        $( document ).ajaxComplete(function() {
          $("html, body").animate({ scrollTop: $(".panels-flexible-row-node_page-4").offset().top},500);
        });
      });
    }

  /*****  min page height  *******/

        $("#main-wrapper").css("min-height",$(window).height()-$("footer").height()-$("header").height()+100);

        $(window).resize(function() {
            $("#main-wrapper").css("min-height",$(window).height()-$("footer").height()-$("header").height()+100);
        });

/******  event page with movie group list  **********/

if ($("div").hasClass("movie-group-list")){
  $(".panels-flexible-row-node_page-5").addClass("with-movie-group-list");
}

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
        $(".full-screen-image, .full-screen-image .wrapper-image .content, .full-screen-image .wrapper-image .content li, .full-screen-image .view-content .views-row").css("max-height",$screenheight);
        $(".full-screen-image-front, .full-screen-image-front .field-item").css("max-height",$screenheight+50);
        $(window).resize(function() {
            $screenheight = $(window).height()-50;
            $(".full-screen-image, .full-screen-image .wrapper-image .content, .full-screen-image .wrapper-image .content li, .full-screen-image .view-content .views-row").css("max-height",$screenheight);
            $(".full-screen-image-front, .full-screen-image-front .field-item").css("max-height",$screenheight+50);
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

        $(".not-front .slide-right-ct .play-button").click(function(ev) {
            $(".slide-right-ct .video-wrapper").addClass("play");
            $("body").addClass("play");
            $(".media-youtube-player")[0].src += "&enablejsapi=1&version=3&playerapiid=ytplayer&autoplay=1";
            ev.preventDefault();
            $("video").play();
        });

        $('.not-front .video-wrapper').on('click', function(e) {
          if($(e.target).closest('.video-wrapper .content').length == 0) {
            $(".slide-right-ct .video-wrapper").removeClass("play");
            $("body").removeClass("play");
            $(".media-youtube-player")[0].contentWindow.postMessage('{"event":"command","func":"' + 'stopVideo' + '","args":""}', '*');  
            e.preventDefault();
            

          }
      });

        $(".front .slide-right-ct .play-button").click(function(ev) {
            var clonedDiv = $(this).parent().children(".video-wrapper").clone();
            clonedDiv.attr("id", "newId");
            $('body').after(cloneDiv);
            $('body footer').after($(this).parent().children(".video-wrapper"));
            $("body > .video-wrapper").addClass("play");
            $("body").addClass("play");
            $(".media-youtube-player")[0].src += "&enablejsapi=1&version=3&playerapiid=ytplayer&autoplay=1";
            ev.preventDefault();
            $("video").play();
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
        if ($(window).width() > 767){
          var halfscreen = $(window).height()-240-$(".region-messages").height(); 
        }
        else{
          var halfscreen = $(window).height()-139-$(".region-messages").height(); 
        }
        $(".view-custom-calendar-floating-pane.view-display-id-block_1 .view-content").css("max-height",halfscreen);

        $( document ).ajaxComplete(function() {
          if ($(window).width() > 767){
            var halfscreen = $(window).height()-240-$(".region-messages").height(); 
          }
          else{
            var halfscreen = $(window).height()-139-$(".region-messages").height(); 
          }
          $(".view-custom-calendar-floating-pane.view-display-id-block_1 .view-content").css("max-height",halfscreen);        
        });

        $(window).resize(function() {
          if ($(window).width() > 767){
            var halfscreen = $(window).height()-240-$(".region-messages").height(); 
          }
          else{
            var halfscreen = $(window).height()-139-$(".region-messages").height(); 
          }
           $(".view-custom-calendar-floating-pane.view-display-id-block_1 .view-content").css("max-height",halfscreen);
        });



/*******  calendar fixed  area*********/

$(window).load(function() {
  $(".calender-filter > p").css("opacity","1");
});

$( document ).ajaxComplete(function() {
  $(".calender-filter > p").css("opacity","1");
});

if ($("body").hasClass("page-node-4284") || $("body").hasClass("page-node-4285") || $("body").hasClass("page-festival-calendar") || $("body").hasClass("page-festival-calendar-mobile")){
        if ($(window).width() < 768){
          $squarewidth = 80;
        }
        if ($(window).width() > 767){
          $squarewidth = 90;
        }
        $(window).resize(function() {
          if ($(window).width() < 768){
            $squarewidth = 80;
          }
          if ($(window).width() > 767){
            $squarewidth = 90;
          }
        });

          $filterwidth = $(".calender-filter p").size()*$squarewidth+30;
          $(".calender-filter").css("width",$filterwidth);
          $maxleft = ($filterwidth - $(".filter-wrapper .inner").width())*(-1)-30;
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
          $left = $left + (-$squarewidth)*($i-1);
          if ($left < $maxleft){
              $left = $maxleft;
          }
          if ($left >= 0){
              $left = 0;
              $(".filter-wrapper .inner").addClass("noleft");
          }
		   if ($left <= $maxleft){
              $left = $maxleft;
              $(".filter-wrapper .inner").addClass("noright");
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
            $left = $left + (-$squarewidth)*($i-1);
            if ($left <= $maxleft){
              $left = $maxleft;
              $(".filter-wrapper .inner").addClass("noright");
            }
            if ($left > $maxleft){
              $(".filter-wrapper .inner").removeClass("noright");
            }
            if ($left >= 0){
              $left = 0;
              $(".filter-wrapper .inner").addClass("noleft");
            }
            if ($left < 0){
              $(".filter-wrapper .inner").removeClass("noleft");
            }
            $(".i18n-en .calender-filter").css("margin-left",$left);
            $(".i18n-he .calender-filter").css("margin-right",$left);
            /*$( document ).ajaxComplete(function() {
              $("html, body").animate({ scrollTop: $(".pane-calendar-full-width-calendar .ajax-inner").offset().top - 200},500);
            });*/
          });
          $(".nextday").click(function(){
            if ($left > $maxleft){
              $left = $left - $squarewidth;
              if ($left <= $maxleft){
                $left = $maxleft;
                $(".filter-wrapper .inner").addClass("noright");
              }
              if ($left < 0){
                  $(".filter-wrapper .inner").removeClass("noleft");
              }
              $(".i18n-en .calender-filter").css("margin-left",$left);
              $(".i18n-he .calender-filter").css("margin-right",$left);   
            }
          });
          $(".prevday").click(function(){
            if ($left < 0){
              $left = $left + $squarewidth;
              if ($left >= 0){
                $left = 0;
                $(".filter-wrapper .inner").addClass("noleft");
              }
              if ($left > $maxleft){
                  $(".filter-wrapper .inner").removeClass("noright");
              }
              $(".i18n-en .calender-filter").css("margin-left",$left);
              $(".i18n-he .calender-filter").css("margin-right",$left);
              }
          });

        $(window).resize(function() {
          $filterwidth = $(".calender-filter p").size()*$squarewidth+30;
          $(".calender-filter").css("width",$filterwidth);
          $maxleft = ($filterwidth - $(".filter-wrapper .inner").width())*(-1)-30; 
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
          $left = $left + (-$squarewidth)*($i-1);
          if ($left < $maxleft){
              $left = $maxleft;
          }
          if ($left > 0){
              $left = 0;
          }
          $(".i18n-en .calender-filter").css("margin-left",$left);
          $(".i18n-he .calender-filter").css("margin-right",$left);
        });

        $( document ).ajaxComplete(function() {
          if ($("body").hasClass("page-festival-calendar")){
            $filterwidth = $(".calender-filter p").size()*$squarewidth+30;
            $(".calender-filter").css("width",$filterwidth);
            $maxleft = ($filterwidth - $(".filter-wrapper .inner").width())*(-1)-30; 
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
            $left = $left + (-$squarewidth)*($i-1);
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

        $(".calender-filter p").click(function(){
            $("html, body").animate({ scrollTop: 0},0);
        });


if ($("#calender-filter").width()<$(".filter-wrapper .inner").width()){
  $(".filter-wrapper .inner").addClass("noright noleft");
  $("#calender-filter").css("margin","0 auto");
}

$( document ).ajaxComplete(function() {
  if ($("#calender-filter").width()<$(".filter-wrapper .inner").width()){
    $(".filter-wrapper .inner").addClass("noright noleft");
    $("#calender-filter").css("margin","0 auto");
  }
});

$(window).resize(function() {
  if ($("#calender-filter").width()<$(".filter-wrapper .inner").width()){
    $(".filter-wrapper .inner").addClass("noright noleft");
    $("#calender-filter").css("margin","0 auto");
  }
});

document.getElementById("calender-filter").addEventListener('touchstart', handleTouchStart, false);        
document.getElementById("calender-filter").addEventListener('touchmove', handleTouchMove, false);

var xDown = null;                                                        
var yDown = null;                                                        

function handleTouchStart(evt) {                                         
    xDown = evt.touches[0].clientX;                                      
    yDown = evt.touches[0].clientY;                                      
};                                                

function handleTouchMove(evt) {
    if ( ! xDown || ! yDown ) {
        return;
    }

    var xUp = evt.touches[0].clientX;                                    
    var yUp = evt.touches[0].clientY;

    var xDiff = xDown - xUp;
    var yDiff = yDown - yUp;

    if ( Math.abs( xDiff ) > Math.abs( yDiff ) ) {/*most significant*/
      if ($("body").hasClass("i18n-en")){
        if ( xDiff > 0 ) {
            if ($left > $maxleft){
              $left = $left - $squarewidth;
              if ($left <= $maxleft){
                $left = $maxleft;
                $(".filter-wrapper .inner").addClass("noright");
              }
              if ($left < 0){
                  $(".filter-wrapper .inner").removeClass("noleft");
              }
              $(".i18n-en .calender-filter").css("margin-left",$left);
            }
        } else {
            if ($left < 0){
              $left = $left + $squarewidth;
              if ($left >= 0){
                $left = 0;
                $(".filter-wrapper .inner").addClass("noleft");
              }
              if ($left > $maxleft){
                  $(".filter-wrapper .inner").removeClass("noright");
              }
              $(".i18n-en .calender-filter").css("margin-left",$left);
            }
        } 
      }                      
      else{
          if ( xDiff > 0 ) {
            if ($left > $maxleft){
              $left = $left + $squarewidth;
              if ($left <= $maxleft){
                $left = $maxleft;
                $(".filter-wrapper .inner").addClass("noright");
              }
              if ($left < 0){
                  $(".filter-wrapper .inner").removeClass("noleft");
              }
              $(".i18n-he .calender-filter").css("margin-right",$left); 
            }
        } else {
            if ($left < 0){
              $left = $left - $squarewidth;
              if ($left >= 0){
                $left = 0;
                $(".filter-wrapper .inner").addClass("noleft");
              }
              if ($left > $maxleft){
                  $(".filter-wrapper .inner").removeClass("noright");
              }
              $(".i18n-he .calender-filter").css("margin-right",$left);
            }
        } 
      }
    } 
    /* reset values */
    xDown = null;
    yDown = null;                                             
};


}

$(".page-festival-calendar-mobile caption").click(function(){
  if($(this).parent().hasClass("hide-table")){
    $(this).children(".fa-angle-down").css("display","none")
    $(this).children(".fa-angle-up").css("display","block")
    $(this).parent().removeClass("hide-table");
  }
  else{
    $(this).children(".fa-angle-down").css("display","block")
    $(this).children(".fa-angle-up").css("display","none")
    $(this).parent().addClass("hide-table");
  }
});

$("*").click(function(){
  $(".view-festival-calendar .views-field-popup .popup-element").each(function(){
    if ($(this).hasClass("popup-element-active")){
      $(this).parent().parent().parent().addClass("popup-open");
    } else{
      $(this).parent().parent().parent().removeClass("popup-open");
    }
  });
});

$( document ).ajaxComplete(function() {
  $("*").click(function(){
    $(".view-festival-calendar .views-field-popup .popup-element").each(function(){
      if ($(this).hasClass("popup-element-active")){
        $(this).parent().parent().parent().addClass("popup-open");
      } else{
        $(this).parent().parent().parent().removeClass("popup-open");
      }
    });
  });
});

/********  items of review  *******/
          
        if ($(".view-review-mobile .views-row").length == '1') { 
          $(".view-review-mobile").addClass("one-item");
        }
        else{
          $(".view-review-mobile").addClass("more-items");
        }

        if ($(".view-global-message.view-display-id-block .views-row").length == '1') { 
          $(".view-global-message.view-display-id-block").addClass("one-item");
        }
        else{
          $(".view-global-message.view-display-id-block").addClass("more-items");
        }

        if ($(".full-screen-image .views-row").length == '1') { 
          $(".full-screen-image").addClass("one-item");
        }
        else{
          $(".full-screen-image").addClass("more-items");
        }

        if ($(".view-reviews-field-collection-view-mobile .views-row").length == '1') { 
          $(".reviews-mobile").addClass("one-item");
        }
        else{
          $(".reviews-mobile").addClass("more-items");
        }

        if ($(".view-footer-credit-slogan-for-mobile.view-display-id-block .views-row").length == '1') { 
          $(".view-footer-credit-slogan-for-mobile.view-display-id-block").addClass("one-item");
        }
        else{
          $(".view-footer-credit-slogan-for-mobile.view-display-id-block").addClass("more-items");
        }

        if ($(".view-footer-credit-slogan-for-mobile.view-display-id-block_2 .views-row").length == '1') { 
          $(".view-footer-credit-slogan-for-mobile.view-display-id-block_2").addClass("one-item");
        }
        else{
          $(".view-footer-credit-slogan-for-mobile.view-display-id-block_2").addClass("more-items");
        }

       $(".node-type-front-page .full-screen-image-front").each(function() {
          if ($(this).children(".gallery").children(".field").children(".field-items").children(".field-item").length == '1') { 
            $(this).addClass("one-item");
          }
          else{
            $(this).addClass("more-items");
          } 
       });
       /* $(window).load(function() {
          $(".node-type-front-page .full-screen-image-front").each(function() {
            $(this).after($(this).children(".gallery").children(".field").children(".field-items").children(".owl-controls"));
          });
      });*/

 /********  front *********/

       $(".estimated").each(function() {
          $(this).parent().remove();
       });

        if ($(".field-name-field-item-top-gallery > .field-items > .field-item").length == '1') { 
          $(".field-name-field-item-top-gallery").addClass("one-item");
        }
        else{
          $(".field-name-field-item-top-gallery").addClass("more-item");
        }

        $(window).load(function() {
          $grouppimage = $(".paragraphs-item-special-grid .group-item3 img").height();
          $(".field-name-field-item-special-grid-2").css("height",$grouppimage);
          $(".field-name-field-lobby-special-grid-2").css("height",$grouppimage);
          $(".special-group").css("height",$grouppimage*2+20);
          $(".group-item3 .short-text").css("height",$grouppimage+20-($grouppimage%24));
          $(".group-item1").each(function() {
            $topheight = $(this).find(".image-wrapper").height();
            $(this).find(".short-text").css("height",$grouppimage*2+20-$topheight-($grouppimage*2+20-$topheight)%24);
          });
          $(".group-item2 .field-name-field-item-special-grid-2").each(function() {
            $topheight = $(this).find(".image-wrapper").height();
            $(this).find(".short-text").css("height",$grouppimage-$topheight-(($grouppimage-$topheight)%24));
          }); 
          $(".group-item2 .field-name-field-lobby-special-grid-2").each(function() {
            $topheight = $(this).find(".image-wrapper").height();
            $(this).find(".short-text").css("height",$grouppimage-$topheight-(($grouppimage-$topheight)%24));
          });   
        });
        
        $(window).resize(function() {
          $grouppimage = $(".paragraphs-item-special-grid .group-item3 img").height();
          $(".field-name-field-item-special-grid-2").css("height",$grouppimage);
          $(".field-name-field-lobby-special-grid-2").css("height",$grouppimage);
          $(".special-group").css("height",$grouppimage*2+20);
          $(".group-item3 .short-text").css("height",$grouppimage+20-($grouppimage%24));
          $(".group-item1").each(function() {
            $topheight = $(this).find(".image-wrapper").height();
            $(this).find(".short-text").css("height",$grouppimage*2+20-$topheight-($grouppimage*2+20-$topheight)%24);
          });
          $(".group-item2 .field-name-field-item-special-grid-2").each(function() {
            $topheight = $(this).find(".image-wrapper").height();
            $(this).find(".short-text").css("height",$grouppimage-$topheight-(($grouppimage-$topheight)%24));
          });  
          $(".group-item2 .field-name-field-lobby-special-grid-2").each(function() {
            $topheight = $(this).find(".image-wrapper").height();
            $(this).find(".short-text").css("height",$grouppimage-$topheight-(($grouppimage-$topheight)%24));
          }); 
        });

/******  dinamic special grid  *******/
        $(window).load(function() {
          $(".paragraphs-item-special-grid-dynamic").css("display","block");
    

          $division1 = $(".division-1 .field-name-field-item-special-dynamic > .field-items > .field-item .image").height();
          if ($division1 > 0){
            $(".division-1 .withoutimage .image").hide();
            $(".division-1 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-1 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division1*2); 
            $(".division-1 .field-name-field-item-special-dynamic .withimage .short-text").css("height",$division1-(($division1-40)%24)); 
            $(".division-1 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $(this).parent().parent().parent().addClass("withoutimage");
              $topheight = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division1*2-$topheight-((($division1*2-$topheight))-40)%24);
            });
          }

          $division2 = $(".division-2 .field-name-field-item-special-dynamic > .field-items > .field-item:nth-child(1) .image").height();
          if ($division2 > 0){
            $(".division-2 .withoutimage .image").hide();
            $(".division-2 .image").css("max-height",0.7*2*$division2);
            $(".division-2 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-2 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division2*2); 
            $(".division-2 .field-name-field-item-special-dynamic > .field-items > .field-item").each(function() {
              $div2imageheight = $(this).find(".image").height();
              $(this).find(".short-text").css("height",$division2*2-$div2imageheight-(($division2*2-$div2imageheight-40)%24)); 
            });
            $(".division-2 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $(this).parent().parent().parent().addClass("withoutimage");
              $topheight2 = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division2*2-$topheight2-((($division2*2-$topheight2))-40)%24);
            });
          }

          $division3 = $(".division-3 .field-name-field-item-special-dynamic > .field-items > .field-item:nth-child(2) .image").height();
          if ($division3 > 0){
            $(".division-3 .withoutimage .image").hide();
            $(".division-3 .image").css("max-height",0.7*2*$division3);
            $(".division-3 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-3 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division3*2); 
            $(".division-3 .field-name-field-item-special-dynamic > .field-items > .field-item").each(function() {
              $div3imageheight = $(this).find(".image").height();
              $(this).find(".short-text").css("height",$division3*2-$div3imageheight-(($division3*2-$div3imageheight-40)%24)); 
            });
            $(".division-3 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $(this).parent().parent().parent().addClass("withoutimage");
              $topheight3 = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division3*2-$topheight3-((($division3*2-$topheight3))-40)%24);
            });
          }

          $division4 = $(".division-4 .field-name-field-item-special-dynamic > .field-items > .field-item .image").height();
          if ($division4 > 0){
            $(".division-4 .withoutimage .image").hide();
            $(".division-4 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-4 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division4*2); 
            $(".division-4 .field-name-field-item-special-dynamic .withimage .short-text").css("height",$division4-(($division4-40)%24)); 
            $(".division-4 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $(this).parent().parent().parent().addClass("withoutimage");
              $topheight4 = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division4*2-$topheight4-((($division4*2-$topheight4))-40)%24);
            });
          }


        });

        $(window).resize(function() {
          $division1 = $(".division-1 .field-name-field-item-special-dynamic > .field-items > .field-item .image").height();
          if ($division1 > 0){
            $(".division-1 .withoutimage .image").hide();
            $(".division-1 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-1 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division1*2); 
            $(".division-1 .field-name-field-item-special-dynamic .withimage .short-text").css("height",$division1-(($division1-40)%24)); 
            $(".division-1 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $topheight = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division1*2-$topheight-((($division1*2-$topheight))-40)%24);
            });
          }

          $division2 = $(".division-2 .field-name-field-item-special-dynamic > .field-items > .field-item:nth-child(1) .image").height();
          if ($division2 > 0){
            $(".division-2 .withoutimage .image").hide();
            $(".division-2 .image").css("max-height",0.7*2*$division2);
            $(".division-2 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-2 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division2*2); 
            $(".division-2 .field-name-field-item-special-dynamic > .field-items > .field-item").each(function() {
              $div2imageheight = $(this).find(".image").height();
              $(this).find(".short-text").css("height",$division2*2-$div2imageheight-(($division2*2-$div2imageheight-40)%24)); 
            });
            $(".division-2 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $topheight2 = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division2*2-$topheight2-((($division2*2-$topheight2))-40)%24);
            });
          }

          $division3 = $(".division-3 .field-name-field-item-special-dynamic > .field-items > .field-item:nth-child(2) .image").height();
          if ($division3 > 0){
            $(".division-3 .withoutimage .image").hide();
            $(".division-3 .image").css("max-height",0.7*2*$division3);
            $(".division-3 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-3 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division3*2); 
            $(".division-3 .field-name-field-item-special-dynamic > .field-items > .field-item").each(function() {
              $div3imageheight = $(this).find(".image").height();
              $(this).find(".short-text").css("height",$division3*2-$div3imageheight-(($division3*2-$div3imageheight-40)%24)); 
            });
            $(".division-3 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $topheight3 = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division3*2-$topheight3-((($division3*2-$topheight3))-40)%24);
            });
          }

          $division4 = $(".division-4 .field-name-field-item-special-dynamic > .field-items > .field-item .image").height();
          if ($division4 > 0){
            $(".division-4 .withoutimage .image").hide();
            $(".division-4 .field-name-field-item-special-dynamic > .field-items > .field-item, .division-4 .field-name-field-item-special-dynamic .grid_special_3_item").css("height",$division4*2); 
            $(".division-4 .field-name-field-item-special-dynamic .withimage .short-text").css("height",$division4-(($division4-40)%24)); 
            $(".division-4 .field-name-field-item-special-dynamic .withoutimage").each(function() {
              $topheight4 = $(this).find(".image-wrapper").height();
              $(this).find(".short-text").css("height",$division4*2-$topheight4-((($division4*2-$topheight4))-40)%24);
            });
          }
        });


        $(".node-type-front-page .screaning tbody").each(function(){
            $(this).children("tr").hide();
            $(this).children("tr:lt(3)").show();
        });

        $(".page-user .lobby-term-right tbody").each(function(){
            $(this).children("tr").hide();
            $(this).children("tr:lt(3)").show();
        });

        $(".page-taxonomy-term .screaning tbody").each(function(){
            $(this).children("tr").hide();
            $(this).children("tr:lt(3)").show();
        });

        $(".page-search .table-responsive tbody").each(function(){
            $(this).children("tr").children("td").hide();
            $(this).children("tr:lt(3)").children("td").show();
        });


        $('.view-footer .more-event .text-open').click(function () {
            $(this).parent().parent().parent().children("table").children("tbody").children("tr").show();
            $(this).parent().addClass("open");
            $(this).parent().children(".text-open").hide();
            $(this).parent().children(".text-close").show();
        });

        $('.view-footer .more-event .text-close').click(function () {
            $(this).parent().parent().parent().children("table").children("tbody").children("tr").hide();
            $(this).parent().parent().parent().children("table").children("tbody").children("tr:lt(3)").show();
            $(this).parent().removeClass("open");
            $(this).parent().children(".text-open").css("display","inline-block");
            $(this).parent().children(".text-close").hide();
        });

        $(this).parent().parent().parent().children("table").children("tbody").children("tr").children("tr").hide();
        $(this).parent().parent().parent().children("table").children("tbody").children("tr:lt(3)").children("tr").show();

        $('.page-search .view-footer .more-event .text-open').click(function () {
            $(this).parent().parent().parent().children("table").children("tbody").children("tr").children("td").show();
        });

        $('.page-search .view-footer .more-event .text-close').click(function () {
            $(this).parent().parent().parent().children("table").children("tbody").children("tr").children("td").hide();
            $(this).parent().parent().parent().children("table").children("tbody").children("tr:lt(3)").children("td").show();

        });

        /******  search overlay  ******/

        $(".header-right .search span").click(function() {
            if ($("body").hasClass("search-overlay")){
                $("body").removeClass("search-overlay");
            }
            else{
                $("body").addClass("search-overlay");
                $("body").removeClass("responsive-hamburger-open");
                $(".float-calendar-wrapper").addClass("hide-float");
                $("body").addClass("hide-float-calendar");
                $("body").removeClass("show-float-calendar");
              }
        });

        $('.region-overlay').on('click', function(e) {
          if($(e.target).closest('.region-overlay form').length == 0) {
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

    if($('.node-type-cm-event .sub-lang').text().length == 0){
        $('.node-type-cm-event .sub-title').hide();
    }

    /********  english name of the movie  *******/

    var proffesionwidth = 0;
    $(".credits-view .profession").each(function(){
      if ($(this).width() > proffesionwidth){
        proffesionwidth = $(this).width();
      }
    });
    proffesionwidth = proffesionwidth + 10;
    $(".credits-view .profession").css("width",proffesionwidth);
    $(".credits-view .views-field-views-conditional").css("width",$(".credits-view").width()-proffesionwidth-10);
    $(".credits-view .views-field-views-conditional").css("display","block");

    $(window).resize(function() {
      var proffesionwidth = 0;
      $(".credits-view .profession").css("width","auto");
      $(".credits-view .profession").each(function(){
        if ($(this).width() > proffesionwidth){
          proffesionwidth = $(this).width();
        }
      });
      proffesionwidth = proffesionwidth + 10;
      $(".credits-view .profession").css("width",proffesionwidth);
      $(".credits-view .views-field-views-conditional").css("width",$(".credits-view").width()-proffesionwidth-10);
      $(".credits-view .views-field-views-conditional").css("display","block");
    });

    /********  Show Title to image in movie group slideshow  *******/

    $(".image-alt-title").each(function(){
        $(this).children('.grp-alt').hide();
        if (($("span").hasClass('grp-title')) || ($("div").hasClass('grp-title'))){
          if(($(this).children('.grp-title').text().length == 1) || ($(this).children('.grp-title').text().length == 0)){
               $(this).hide();
          }
        }
    });

/********  date all over the site  ***********/

/*    var daywidth = 0;
    $(".day-same-width").each(function(){
      if ($(this).width() > daywidth){
        daywidth = $(this).width();
      }
    });
    $(".day-same-width").css("width",daywidth);

    $(".text-open-event").click(function() {
      var daywidth = 0;
      $(".day-same-width").each(function(){
        if ($(this).width() > daywidth){
          daywidth = $(this).width();
        }
      });
      $(".day-same-width").css("width",daywidth);
    });
*/

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
        $('.pane-event-ct-view-panel-pane-5 > .pane-content').hide();
        $('.pane-event-ct-view-panel-pane-5').css("padding-bottom","20px");
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

  }
	}

})(jQuery);


if (jQuery(window).width() > 767){
    jQuery(function(){  
      jQuery('.front .field-name-field-item-top-gallery.more-item > .field-items').owlCarousel({
        rtl: true,
        autoplay:false,
        autoplayTimeout:5000,
        autoplayHoverPause:true,
        loop:true,
        margin:0,
        nav: true,
        responsive:{
          0:{
            items:1
          }
        }
      }); 
    })
}

    jQuery(function(){ 
      isRtl=false;
      if  (jQuery("body").hasClass("i18n-he")){
        isRtl=true;
      } 
      jQuery('.view-global-message.view-display-id-block.more-items .view-content').owlCarousel({
        rtl: isRtl,
        autoplay:true,
        autoplayTimeout:5000,
        autoplayHoverPause:true,
        loop:true,
        dots: true,
        margin:0,
        nav: false,
        animateIn: 'fadeIn', 
        animateOut: 'fadeOut',
        slideSpeed: 300,
        responsive:{
          0:{
            items:1
          }
        }
      }); 
    })


