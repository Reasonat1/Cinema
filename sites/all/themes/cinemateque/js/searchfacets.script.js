/*
 * Custom js for search result page
 * creatd by Robin Singh
 */

jQuery(document).ready(function () {
    var popup = jQuery(".popup_search").html();
    jQuery(".popup-element-title span").html(popup);
//        jQuery(".popup_search").html(popup_search);
    jQuery(".popup_search").hide();
//        alert(jQuery('.search-api-page-search-form').html());
//        var data = jQuery('.search_new').html();
//        jQuery('.search_new').remove();
//        jQuery('#search-api-page-search-form').append('<div class="search_new">' + data + '</div>');
    jQuery(".search_new").appendTo("#search-api-page-search-form");
    jQuery("#search-api-page-search-form").appendTo(".container:first");
    jQuery('select').select2();
    
    
    jQuery('select option').each(function () {
        if (jQuery(this).text().includes("(-)")) {
            jQuery("#RemoveFilters").append('<a href="' + jQuery(this).val() + '">' + jQuery(this).text() + '</a>');
        }
    });
    jQuery("#RemoveFilters").appendTo(".container:first");
});
