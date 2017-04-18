(function ($) {
	$(document).ready(function(){
	var hallPanel =$('.view-festival-calendar .view-display-id-block_1');
	var hall =$('.view-festival-calendar .view-display-id-block_1').find('.views-row');
	var hallWidth=hall.width();
	var hallHeight=hall.height();
	var hallPanelWidth = hallWidth*6*1.1;
	var hallCount=hall.length;
	var hallLength=hallCount*hallWidth;
	hallPanel.width(hallPanelWidth).height(hallHeight)
	if (hallCount>6){
		var controlButtons = '<div class="hall-next">Next</div><div class="hall-prev">Prev</div>';
	hallPanel.after(controlButtons);
	}
	$('.view-header').delegate('.hall-next', 'click',function(){
		var panelPosition=parseInt(hallPanel.find('.view-content').css('margin-left'));
		if(panelPosition>0-hallLength+hallWidth*6)
		hallPanel.find('.view-content').css('margin-left', panelPosition-hallWidth+'px');
	events_table(hallPanel, hallLength, hallWidth);
	});
	$('.view-header').delegate('.hall-prev', 'click',function(){
		var panelPosition=parseInt(hallPanel.find('.view-content').css('margin-left'));
		if(panelPosition<0)
		hallPanel.find('.view-content').css('margin-left', panelPosition+hallWidth+'px');
	events_table(hallPanel, hallLength, hallWidth);
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
	
	events_table(hallPanel, hallLength, hallWidth);
	
	});
function events_table(hallPanel, hallLength, hallWidth){
	var myPanels=$("div[class*='hall-panel-']");
	var panelPosition=parseInt(hallPanel.find('.view-content').css('margin-left'));
	$.each(myPanels, function(index, item) {
		var classList = $(item).attr('class').split(/\s+/);
	$.each(classList, function(ind, item_class) {
		if (~item_class.indexOf("hall-panel-")){
			var event_position=$('.'+item_class).position();
			var hall_top=event_position.top;
			var hall_panel=$('.view-festival-calendar .view-display-id-block_1').find('.view-content');
			var hal_panel_y=hall_panel.position().top;
			var event_class=item_class.replace("hall-panel-","");
			if (hall_top != hal_panel_y) {$('.'+event_class).hide();} else {$('.'+event_class).show();}
			$('.'+event_class).offset({ left : event_position.left});
			
		}
		});
});
	if(panelPosition<=0-hallLength+hallWidth*6) {$('.hall-next').hide();} else {$('.hall-next').show();}
	if(panelPosition>=0) {$('.hall-prev').hide();} else {$('.hall-prev').show();}

}
})(jQuery);
