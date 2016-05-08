var toptix_basket_url = null;
(function($) {
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
  var frame = jQuery('<iframe></iframe>');
  frame.attr('src', toptix_basket_url);
  frame.attr('width', '1024');
  frame.attr('height', '768');
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
