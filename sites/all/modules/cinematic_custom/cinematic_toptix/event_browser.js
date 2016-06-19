(function($) {
  Drupal.behaviors.toptix_select = {
    attach: function(context, settings) {
      $('.field-name-field-toptix-purchase input.browser')
        .click(function(){
          $(this).addClass('throbbing').css('background-repeat', 'no-repeat');
          toptix_dialog.setup(this);
        });
      toptix_dialog.hidden = $('.field-name-field-toptix-purchase input[type="hidden"]')
    },
  };
})(jQuery);

var toptix_dialog = {anchor: null, win: null, hidden: null};

toptix_dialog.setup = function(anchor) {
  var url = Drupal.settings.basePath + 'content/events-browser';
  this.anchor = anchor;
  var self = this;
  jQuery.get(url, function (data) {
    self.show_results(data);
    jQuery(self.anchor).removeClass('throbbing');
  });
};

toptix_dialog.show_results = function(data) {
  var results = jQuery(data);
  if (this.win) {
    this.win.dialog('destroy');
  }
  this.win = results.dialog({
    title: Drupal.t('Events'),
    position: {my:'right center', at:'left bottom', of: this.anchor},
    height: 400
  });
  results = this.win.find('.browse-results');
  results.accordion({active: false});

  var self = this;
  results.click(function(event){
    var target = event.target;
    if (target.dataset.hasOwnProperty('id')) {
      self.hidden.val(target.dataset.id);
      self.anchor.value = target.textContent;
      self.win.dialog('close');
    }
  });

  this.pager = this.win.find('select[name="pager"]');
  this.pager.change(function() {
    self.update_results();
  });
  this.order = this.win.find('select[name="order"]');
  this.order.change(function() {
    self.update_results();
  });
};

toptix_dialog.update_results = function() {
  var url = Drupal.settings.basePath + 'content/events-browser?';
  url += 'page=' + this.pager.val() + '&order=' + this.order.val();
  var self = this;
  jQuery.get(url, function (data) {
    self.show_results(data);
  });
}
