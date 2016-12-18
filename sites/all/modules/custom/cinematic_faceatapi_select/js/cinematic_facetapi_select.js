/**
 * @file
 * Handles Facet API Select ajax functionality.
 */
(function ($) {
  Drupal.behaviors.facetapiSelect = {
    attach: function(context) {
		if ($('body').hasClass('page-search-results') {
      $(".facetapi-select-submit").hide();
var defoultForm=getUrlVars();
var uri=document.location.pathname;
var mybutton='<form id="filter_button" action="'+uri+'"><button class="form-submit btn btn-default btn-primary" type="submit">Submit</button></form>';
var url=[];

if ($('#filter_button').length==0)
$('.panels-flexible-row-node_page-3').append(mybutton);

$.each(defoultForm, function(index, value) {
$('#filter_button').prepend('<input type="hidden" name="'+value+'" value="'+defoultForm[value]+'" />');
});

      $('.facetapi-select').change(function() {
	$('.facetapi-select').each(function(index) {
        var id = $(this).attr('id');
        var elem = document.getElementById(id);
		var query = elem.options[elem.selectedIndex].value.split('=');
	if (query[query.length-1] && query[query.length-1] !=uri) { 
	$("[name='f\["+index+"\]']").remove();	
	$('#filter_button').prepend('<input type="hidden" name="f['+index+']" value="'+decodeURIComponent(query[query.length-1])+'" />');
	}
		});
      });
	  
function getUrlVars()
{
    var vars = [], hash;
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
		if (hash[0]!=window.location.href){
        vars.push(decodeURIComponent(hash[0]));
        vars[decodeURIComponent(hash[0])] = decodeURIComponent(hash[1]);}
    }
    return vars;
		}}
    }
  };
})(jQuery);