(function($) {
  $(document).ready(function() {
    toptix_basket_setup();
    toptix_purchase_setup();
  });
}) (jQuery);

var toptix_basket_setup = null;
(function($) {
  if ($.cookie('toptix_basket') == null) {
    $.cookie('toptix_basket', 0);
  }
  toptix_basket_setup = function(context, settings) {
    $('button.basket').click(function(event) {
      if ($.cookie('toptix_basket') == 0) {
        var message = $('<div></div>');
        message.text(Drupal.t('You have not added any items to purchase yet'));
        message.dialog({modal: true, title: Drupal.t('Tickets basket')});
        return;
      }
      toptix_open_basket_frame(this.dataset.url);
    });
  };
})(jQuery);

$esro.attachEventHandler('basketChanged', function(basket) {
  console.log('my basket handler');
  console.log(basket);
  jQuery.cookie('toptix_basket', basket.Tickets.length);
});


function toptix_open_basket_frame(basket_url) {
  // wrapper div for <esro:frame
  var frame = jQuery('#toptix-frame-wrapper');
  $esro.gotoUrl(basket_url);
  frame.dialog({
    'title': Drupal.t('Tickets basket'),
    'width': 1024,
    'height': 768,
    'modal': true,
    'open': function(event, ui) {
      event.target.style.width = "1024px";
      event.target.style.height = "768px";
    }
  });
}

var toptix_active_button = {original_text:'', item: null};
var toptix_purchase_setup = null;
(function($) {
  toptix_purchase_setup = function(context, settings) {
    var self = this;
    $('button.purchase').click(function(event) {
      toptix_active_button.item = this;
      toptix_active_button.original_text = $(this).text();
      $(this).text(Drupal.t('Loading...'));
      toptix_open_frame(this.dataset.url);
    });
  };
})(jQuery);

function toptix_open_frame(event_url) {
  var frame = jQuery('#toptix-frame-wrapper');
  $esro.gotoUrl(event_url);
  frame.dialog({
    'title': Drupal.t('Purchase tickets'),
    'width': 1024,
    'height': 768,
    'modal': true,
    'open': function(event, ui) {
      event.target.style.width = "1024px";
      event.target.style.height = "768px";
    }
  });
  jQuery(toptix_active_button.item).text(toptix_active_button.original_text);
}
