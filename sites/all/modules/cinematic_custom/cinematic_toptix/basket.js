var toptix_basket_url = null;
(function($) {
  if ($.cookie('toptix_basket') == null) {
    $.cookie('toptix_basket', 0);
  }
  Drupal.behaviors.toptix_basket_frame = {
    
    attach: function(context, settings) {
      var self = this;
      $('.toptix-basket').click(function(event) {
        toptix_basket_url = this.dataset.url;
        $esro.getCustomerDetails('toptix_callback_basket_get_customer');
      });

    },
  };

})(jQuery);

$esro.attachEventHandler('basketChanged', function(basket) {
  console.log('my basket handler');
  console.log(basket);
  jQuery.cookie('toptix_basket', basket.totalValue);
});

function toptix_navigationHandler(pageName) {
  console.log('esro navigation:' + pageName);
  if (pageName == 'DEFAULT') {
    var target_page = Drupal.settings.basePath + 'user';
    var target_address = 'http://' + window.location.hostname + target_page;
    if (target_address != window.location.href) {
      console.log('navigating to ' + target_page);
      //window.location.href = target_address;
    }
  }
}
$esro.attachEventHandler('navigationRequired', toptix_navigationHandler);

function toptix_callback_basket_get_customer(result) {
  var toptix_user = Drupal.settings.toptix_user;
  if (result.HasError) {
    $esro.customerLoginById(toptix_user, 'toptix_callback_basket_login');
    return;
  }

  if (result.Result.Id == toptix_user) {
    toptix_open_basket_frame();
    return;
  }
  else {
    $esro.customerLoginById(toptix_user, 'toptix_callback_basket_login');
  }
}

function toptix_callback_basket_login(result) {
  console.log('after login');
  console.log(result);
  toptix_open_basket_frame();
}

function toptix_open_basket_frame() {
  var frame = jQuery('#toptix-frame-wrapper');
  $esro.gotoUrl(toptix_basket_url);
  frame.dialog({
    'title': Drupal.t('Tickets basket'),
    'width': 1024,
    'height': 768,
    'modal': true,
    'open': function(event, ui) {
      //event.target.style.width = "1024px";
      //event.target.style.height = "768px";
    }
  });
}
