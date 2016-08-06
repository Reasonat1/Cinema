/*
 * Custom js for search result page
 * creatd by Robin Singh
 */

jQuery(document).ready(function () {
    var popup = jQuery(".popup_search").html();
    jQuery(".popup-element-title span").html(popup);
    jQuery(".popup_search").hide();
    jQuery(".search_new").appendTo("#search-api-page-search-form");
    jQuery("#search-api-page-search-form").appendTo(".container:first");
           /******Hide Other screening ****/
    if(jQuery('.pane-event-ct-view-panel-pane-5 .view-content .hide-table').length){
        jQuery('.pane-event-ct-view-panel-pane-5 h2.pane-title').hide();
    }
});
