var toptix_basket_url = null;
(function($) {
  if ($.cookie('toptix_basket') == null) {
    $.cookie('toptix_basket', 0);
  }
  // this will run on $(document).ready()
  Drupal.behaviors.toptix_basket_frame = {
    
    attach: function(context, settings) {
      var self = this;
      $('.toptix-basket').click(function(event) {
        if ($.cookie('toptix_basket') == 0) {
          toptix_basket_url = settings.toptix_userpage;
        }
        else {
          // url is : http://tickets.jer-cin.org.il/Order.aspx%26culture=en-US
          toptix_basket_url = this.dataset.url;
        }
        $esro.getCustomerDetails('toptix_callback_basket_get_customer');
      });
    },
  };

})(jQuery);

$esro.attachEventHandler('basketChanged', function(basket) {
  console.log(basket);
  jQuery.cookie('toptix_basket', basket.Tickets.length);
});

function toptix_navigationHandler(pageName) {
  console.log('esro navigation:' + pageName);
  if (pageName == 'DEFAULT') {
    var frame = jQuery('#toptix-frame-wrapper');
    frame.dialog('close');
  }
}
$esro.attachEventHandler('navigationRequired', toptix_navigationHandler);

function toptix_callback_basket_get_customer(result) {
  if (result.HasError) {
    // ?
  }
  toptix_open_basket_frame();
}

function toptix_open_basket_frame() {
  // wrapper div for <esro:frame
  var frame = jQuery('#toptix-frame-wrapper');
  $esro.gotoUrl(toptix_basket_url);
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
