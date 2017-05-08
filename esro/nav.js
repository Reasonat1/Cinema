alert("hello");
var toptix_setup = {};

$(document).ready(function() {
  toptix_setup.basket();
  toptix_setup.purchase();
  $('button.hide').click(function() {
    var frame = $('#toptix-frame-wrapper');
    frame.hide();
  });
});

if ($.cookie('toptix_basket') == null) {
  $.cookie('toptix_basket', 0);
}

toptix_setup.basket = function () {
  $('button.basket').click(function(event) {
    if ($.cookie('toptix_basket') == 0) {
      alert('You have not added any items to purchase yet');
      return;
    }
    toptix_open_basket_frame(this.dataset.url);
  });
};

function toptix_open_basket_frame(basket_url) {
  // wrapper div for <esro:frame
  var frame = $('#toptix-frame-wrapper');
  $esro.gotoUrl(basket_url);
  frame.show();
}

toptix_setup.purchase = function() {
  $('button.purchase').click(function(event) {
    toptix_open_frame(this.dataset.url);
  });
};

function toptix_open_frame(event_url) {
  var frame = jQuery('#toptix-frame-wrapper');
  $esro.gotoUrl(event_url);
  frame.show();
}

function basketHandler(basket) {
  console.log('my basket handler');
  console.log(basket);
  jQuery.cookie('toptix_basket', basket.Tickets.length);
}
//Attach the basket changed event handler
$esro.attachEventHandler("basketChanged", basketHandler);

function navigationHandler(pageName) {
  console.log('esro navigation:' + pageName);
  if (pageName == 'DEFAULT') {
    var target_page = '/esro/nav.html';
    var target_address = 'http://jer-cin.reasonat.com' + target_page;
    //window.location.href = target_address;
    var frame = $('#toptix-frame-wrapper');
    frame.hide();
  }
}
//Attach the iframe navigated event handler
$esro.attachEventHandler("navigationRequired", navigationHandler);
