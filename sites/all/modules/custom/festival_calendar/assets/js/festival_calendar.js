(function ($) {
	Drupal.behaviors.festival_calendar = {
  attach: function (context, settings) {
	  
	$(document).ready(function(){
	var eventLinkglobal=localStorage.getItem('eventLinktemp');
	if (eventLinkglobal){
	var eventLinkg=eventLinkglobal.split(',');
	$('#edit-field-cm-event-time-value-value-day').val(eventLinkg[2]);
	$('#edit-field-cm-event-time-value-value-month').val(parseInt(eventLinkg[1]));
	$('#edit-field-cm-event-time-value-value-year').val(eventLinkg[0]).change();
	window.localStorage.clear();
	}
	var hallPanel =$('.view-festival-calendar .view-display-id-block_1');
	var hall =$('.view-festival-calendar .view-display-id-block_1').find('.views-row');
	var hallWidth=hall.width();
	var hallHeight=hall.height();
	var hallPanelWidth = hallWidth*6*1.1;
	var hallCount=hall.length;
	var hallLength=hallCount*hallWidth;
	hallPanel.width(hallPanelWidth).height(hallHeight);
	hallPanel.find('.view-content').width(hallPanelWidth).height(hallHeight);
	if (hallCount>6){
		var controlButtons = '<div class="hall-next"><span>More Halls</span><i class="fa fa-angle-right" aria-hidden="true"></i></div><div class="hall-prev"><i class="fa fa-angle-left" aria-hidden="true"></i><span>More Halls</span></div>';
	hallPanel.after(controlButtons);
	}
	$('.view-header', context).delegate('.hall-next', 'click',function(){
		var panelPosition=parseInt(hallPanel.find('.views-row-first').css('margin-left'));
		if(panelPosition>0-hallLength+hallWidth*6) {
		hallPanel.find('.views-row-first').css('margin-left', panelPosition-hallWidth+'px');
		events_table(hallLength, hallWidth);}
	});
	$('.view-header', context).delegate('.hall-prev', 'click',function(){
		var panelPosition=parseInt(hallPanel.find('.views-row-first').css('margin-left'));
		if(panelPosition<0) {
		hallPanel.find('.views-row-first').css('margin-left', panelPosition+hallWidth+'px');
		 events_table(hallLength, hallWidth);}
	});
	
	$('*').click(function(e) {
		if($(e.target).closest('.popup-layout').length === 0 && $(e.target).closest('.popup-element-title').length === 0 && $(e.target).closest('.ui-dialog-titlebar').length === 0) {
		$('.popup-element-body[style*="display: block"]').find('a.popup-close-button').click();
		}
        
    });
	
	$(".page-festival-calendar .table-responsive tbody").each(function(){
            $(this).children("tr").hide();
            $(this).children("tr:lt(3)").show();
        });
	 window.setTimeout( function() {events_table(hallLength, hallWidth);}, 10 );
$('.calendar-filter').click(function(event) {
	event.stopPropagation();
	event.preventDefault();
	var eventLink=$(this).attr('href').replace("/festival-calendar/","").split('-');
	var pathName = window.location.pathname;
	if (pathName.indexOf("20")>0){
	localStorage.setItem('eventLinktemp', eventLink);
	document.location.href = '/festival-calendar';
	return false;
	}
	$('#edit-field-cm-event-time-value-value-day').val(eventLink[2]);
	$('#edit-field-cm-event-time-value-value-month').val(parseInt(eventLink[1]));
	$('#edit-field-cm-event-time-value-value-year').val(eventLink[0]).change();
	return false;
});

$(document)
  .ajaxStart(function () {
    $(".load-inner").addClass('loading');
  })
  .ajaxStop(function () {
    $(".load-inner").removeClass('loading');
  });
	});
function events_table(hallLength, hallWidth){
	var hallPanel =$('.view-festival-calendar .view-display-id-block_1');
	var myPanels=$("div[class*='hall-panel-']");
	var panelPosition=parseInt(hallPanel.find('.views-row-first').css('margin-left'));
	$.each(myPanels, function(index, item) {
		var classList = $(item).attr('class').split(/\s+/);
	$.each(classList, function(ind, item_class) {
		if (~item_class.indexOf("hall-panel-")){
			var event_position=$('.'+item_class).position();
			var event_position_l=parseInt($('.'+item_class).css('margin-left'));
			var hall_top=event_position.top;
			var hall_panel=$('.view-festival-calendar .view-display-id-block_1').find('.views-row-first');
			var hal_panel_y=hall_panel.position().top;
			var event_class=item_class.replace("hall-panel-","");
			var myEventPosition = (event_position_l ? event_position_l : event_position.left);
			if (hall_top != hal_panel_y || myEventPosition<0) {$('.'+event_class).hide();} else {$('.'+event_class).show();}
			$('.'+event_class).css({left: myEventPosition, position: 'absolute'});
			
		}
		});
});
	if(panelPosition<=0-hallLength+hallWidth*6) {$('.hall-next').hide();} else {$('.hall-next').show();}
	if(panelPosition>=0) {$('.hall-prev').hide();} else {$('.hall-prev').show();}

}

}
};
})(jQuery);
