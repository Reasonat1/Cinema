(function($) {
  Drupal.behaviors.toptix_select = {
    attach: function(context, settings) {
      $('.field-name-field-toptix-purchase input.browser + .description')
        .click(function(){
          var anchor = $(this).prev().get(0);
          $(anchor).addClass('throbbing').css('background-repeat', 'no-repeat');
          toptix_dialog.setup(anchor);
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
  
  var pos = {of: this.anchor};
  if (document.dir == 'rtl') {
    pos.my = 'right+10 center';
    pos.at = 'left bottom';
  }
  else {
    pos.my = 'left+10 center';
    pos.at = 'right bottom';
  }
  this.win = results.dialog({
    title: Drupal.t('Events'),
    position: pos,
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
      // better to dispatch event
      self.update_date(target.dataset.id);
      self.update_status(target.dataset.id);
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

toptix_dialog.setup_dates = function(data) {
  var dates = [];
  dates.push({
    raw_date: data.ActualEventDate,
    name: 'field_cm_event_time[und][0][value]'
  });
  dates.push({
    raw_date: data.EndDate,
    name: 'field_cm_event_time[und][0][value2]'
  });
  if (typeof(data.EndSaleAt) == 'undefined') {
    data.EndSaleAt = '';
    window.alert(Drupal.t('Please set Sale end date manually'));
  }
  dates.push({
    raw_date: data.StartSaleFrom,
    name: 'field_cm_sale_time[und][0][value]'
  });
  dates.push({
    raw_date: data.EndSaleAt,
    name: 'field_cm_sale_time[und][0][value2]'
  });
  return dates;
}

toptix_dialog.update_date = function (id) {
  var data = this.data[id];
  var dates = this.setup_dates(data);

  for (var iter = 0; iter < dates.length; iter++) {
    var input_date = '';
    var inputtime = '';
    var datefield = jQuery('input[name="' + dates[iter].name + '[date]"]');
    var timefield = jQuery('input[name="' + dates[iter].name + '[time]"]');
    if (dates[iter].raw_date) {
      var extract = dates[iter].raw_date.match(/(.+) - ([^:]+:[^:]+)/);
      input_date = extract[1];
      input_time = extract[2];
    }
    datefield.val(input_date);
    timefield.val(input_time);
  }
}

toptix_dialog.update_status = function (id) {
  var data = this.data[id];
  var field = jQuery('input[name="field_tickets_sold_out[und]"]');
  if (field.length) {
    field.prop('checked', (data.SoldOut != 'False'));
  }
  field = jQuery('input[name="field_include_ticket_sale[und]"]');
  if (field.length) {
    field.prop('checked', !(data.SaleStatus != 'Open'));
  }
}
