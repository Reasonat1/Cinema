(function ($) {
	Drupal.behaviors.view_navigation = {
  attach: function (context, settings) {
	  $('a.button-next-title').hide();
	$('div.button-next').hover(function(){
		$('a.button-next').hide();
		$('a.button-next-title').show();
	}, function(){
		$('a.button-next').show();
		$('a.button-next-title').hide();
	});
	$('a.button-prev-title').hide();
	$('div.button-prev').hover(function(){
		$('a.button-prev').hide();
		$('a.button-prev-title').show();
	}, function(){
		$('a.button-prev').show();
		$('a.button-prev-title').hide();
	});
}
};
})(jQuery);
