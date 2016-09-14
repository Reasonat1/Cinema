/*
 * Custom js for search result page
 * creatd by Robin Singh
 */

jQuery(document).ready(function () {
    jQuery('select').select2();
    jQuery('select option').each(function () { 
        if (jQuery(this).text().includes("(-)")) {
            jQuery("#RemoveFilters").append('<a href="' + jQuery(this).val() + '">' + jQuery(this).text().replace(/\(-\)/, "") + '</a>');
        }
    });
});
