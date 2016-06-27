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
  jQuery.get(url, function (respone) {
    self.show_results(respone);
    jQuery(self.anchor).removeClass('throbbing');
  });
};

toptix_dialog.show_results = function(respone) {
  var results = jQuery(respone.results);
  this.data = respone.data;
  if (this.win) {
    this.win.dialog('destroy');
  }
  this.win = results.dialog({
    title: Drupal.t('Events'),
    position: {my:'left+10 center', at:'right bottom', of: this.anchor},
    height: 600,
    width: 600,
  });
  results = this.win.find('.browser-results');
  results.accordion({active: false});
  var date_fields = this.win.find('.filters .date-range input');
  date_fields.datepicker({dateFormat: 'yy-mm-dd'});

  var self = this;
  results.click(function(event){
    var target = event.target;
    if (target.dataset.hasOwnProperty('id')) {
      self.hidden.val(target.dataset.id);
      self.anchor.value = target.textContent;
      self.win.dialog('close');
    }
  });

  this.win.find('.filters button').click(function(){
    self.update_results();
  });
  this.pager = this.win.find('select[name="pager"]');
  this.title_search = this.win.find('input[name="title"]');
  this.date_from = this.win.find('input[name="date_from"]');
  this.date_to = this.win.find('input[name="date_to"]');
};

toptix_dialog.update_results = function() {
  var url = Drupal.settings.basePath + 'content/events-browser?';
  url += 'page=' + this.pager.val() + '&title=' + this.title_search.val();
  url += '&date_range=' + this.date_from.val() + ':' + this.date_to.val();
  var self = this;
  jQuery.get(url, function (data) {
    self.show_results(data);
  });
}
