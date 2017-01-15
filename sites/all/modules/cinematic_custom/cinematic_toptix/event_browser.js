(function($) {
  Drupal.behaviors.toptix_select = {
    attach: function(context, settings) {
      $('.field-name-field-toptix-purchase input.browser + .description')
        .click(function(){
          var anchor = $(this).prev();
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
      toptix_temp_update_date(target.dataset.id);
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

function formatAMPM(date) {
  var hours = date.getHours();
  var minutes = date.getMinutes();
  var ampm = hours >= 12 ? 'pm' : 'am';
  hours = hours % 12;
  hours = hours ? hours : 12; // the hour '0' should be '12'
  minutes = minutes < 10 ? '0'+minutes : minutes;
  var strTime = hours + ':' + minutes + ' ' + ampm;
  return strTime;
}

function toptix_temp_update_date(id) {
  var data = toptix_dialog.data[id];

  jQuery('input[name="title"]').val(data.title);
  if (typeof data.DetailedText != 'undefined') {
    jQuery('textarea[name="field_cm_event_body[und][0][value]"').val(data.DetailedText);
    //console.log(data.DetailedText);
  }

  var actual_date = new Date(data.ActualEventDate.substring(0,10));
  //var time = actual_date.getHours() + ':' + actual_date.getMinutes();

  var time = new Date();

  time.setHours(data.ActualEventDate.substring(11,13));
  time.setMinutes(data.ActualEventDate.substring(14,16));
  var actual_time = formatAMPM(time);
  var timeto = time;
  timeto.setHours(time.getHours()+2);
  var actual_time2 = formatAMPM(timeto);
  
  var date_name = 'field_cm_event_time[und][0][value]';
  var date_name2 = 'field_cm_event_time[und][0][value2]';
  var datefield = jQuery('input[name="' + date_name + '[date]"]');
  var datefield2 = jQuery('input[name="' + date_name2 + '[date]"]');
  
  //datefield.datepicker('setDate', actual_date);
  var format = datefield.datepicker('option', 'dateFormat');
  //alert(datefield.datepicker({ dateFormat: 'M d yy' }).val());
  
  if (format == null) {
    format = 'M d yy';
  }
  //var actual_date = jQuery.datepicker.formatDate(format, actual_date);
  var insert_date = jQuery.datepicker.formatDate('M d yy', actual_date);
  datefield.val(insert_date);
  datefield2.val(insert_date);

  //jQuery('input[name="' + date_name + '[time]"]').timeEntry('setTime', time);
  var timefield = jQuery('input[name="' + date_name + '[time]"]');
  var timefield2 = jQuery('input[name="' + date_name2 + '[time]"]');
  // timefield.timeEntry('setTime', time);
  timefield.val(actual_time);
  timefield2.val(actual_time2);
  setTimeout(function() {
    timefield
      .blur()
      .click()
      .keydown()
      .keypress();
  }, 5);
}
