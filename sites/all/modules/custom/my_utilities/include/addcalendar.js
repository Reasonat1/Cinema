(function ($) {
$(document).ready(function () { 
localStorage.setItem('_calendar', 0);
	$('.add-event').delegate('.atcb-link', 'click', function(){
		var myList=$(this).next('.atcb-list').css('visibility');
		var myCalendar = localStorage.getItem('_calendar');
		if (myCalendar==0) {
		localStorage.setItem('_calendar', 1);
		} else {
			localStorage.setItem('_calendar', 0);
			setTimeout(function(){
			$(':focus').blur();
			},50); 
		}
	});
	$('.atcb-link').blur(function(){
		localStorage.setItem('_calendar', 0);
		});
});
})(jQuery);
