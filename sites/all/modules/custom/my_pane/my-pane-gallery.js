Drupal.settings.gallery_settings = Drupal.settings.gallery_settings || {};

(function ($) {

    $('.custom-slideshow').cycle({
        fx: 'scrollHorz',
        prev: '#prev2',
        next: '#next2',
    });

    $('.caruosel-slideshow').cycle({
        fx: 'scrollHorz',
        prev: '#prev',
        next: '#next',
    });

    //on hover stop the slideshow
    $(".caruosel-slideshow").mouseover(function () {
        $(this).cycle('pause');
    }).mouseout(function () {
        $(this).cycle('resume');
    });

    //on hover stop the slideshow
    $(".custom-slideshow").mouseover(function () {
        $(this).cycle('pause');
    }).mouseout(function () {
        $(this).cycle('resume');
    });

    $(document).ajaxComplete(function () {
        $('.custom-slideshow').cycle({
            fx: 'scrollHorz',
            prev: '#prev2',
            next: '#next2',
        });
        $('.caruosel-slideshow').cycle({
            fx: 'scrollHorz',
            prev: '#prev',
            next: '#next',
        });
        // hide/show field based on content selection
        if ($('.form-item-content-type select').val() != 'cm_event' && $('.form-item-content-type select').val() != 'cm_movie' && $('.form-item-content-type select').val() != 'cm_movie_group') {
            $('.form-item-top-black-title').hide();
            $('.form-item-top-white-title').hide();
            $('.form-item-movie-image').hide();
            $('.form-item-movie-image-side').hide();
            $('.form-item-movie-title').hide();
            $('.form-item-movie-metainfo').hide();
            $('.form-item-upcomming-event').hide();
            $('.form-item-movie-teaser-text-').hide();
        } else {
            $('.form-item-top-black-title').show();
            $('.form-item-top-white-title').show();
            $('.form-item-movie-image').show();
            $('.form-item-movie-image-side').show();
            $('.form-item-movie-title').show();
            $('.form-item-movie-metainfo').show();
            $('.form-item-upcomming-event').show();
            $('.form-item-movie-teaser-text-').show();
        }
        if ($('.form-item-content-type select').val() == 'cm_article') {
            $('.form-item-top-black-title').show();
            $('.form-item-top-white-title').show();
        }
        if ($('.form-item-node-id select').val() == '0') {
            var type = $('.form-item-content-type select').val();
            node_type_ajax(type);
        }

        $('.form-item-content-type select').off('change').on('change', function () {
            if ($(this).val() != 'cm_event' && $(this).val() != 'cm_movie' && $(this).val() != 'cm_movie_group') {
                $('.form-item-top-black-title').hide();
                $('.form-item-top-white-title').hide();
                $('.form-item-movie-image').hide();
                $('.form-item-movie-image-side').hide();
                $('.form-item-movie-title').hide();
                $('.form-item-movie-metainfo').hide();
                $('.form-item-upcomming-event').hide();
                $('.form-item-movie-teaser-text-').hide();
            } else {
                $('.form-item-top-black-title').show();
                $('.form-item-top-white-title').show();
                $('.form-item-movie-image').show();
                $('.form-item-movie-image-side').show();
                $('.form-item-movie-title').show();
                $('.form-item-movie-metainfo').show();
                $('.form-item-upcomming-event').show();
                $('.form-item-movie-teaser-text-').show();
            }
            if ($(this).val() == 'cm_article') {
                $('.form-item-top-black-title').show();
                $('.form-item-top-white-title').show();
            }
            node_type_ajax($(this).val());
        });

        /**
         * Bean type block acc to Information term type
         */
        if ($('.form-item-block-type select').val() == null && $('#preview').text().length == '0') {
            var type = $('.form-item-term select').val();
            term_type_ajax(type);
        }
        if ($('.form-item-term select').val() == '0') {
            $('.form-item-block-type select').attr('disabled', true);
        }

        $('.form-item-term select').off('change').on('change', function () {
            term_type_ajax($(this).val());
            $('.form-item-block-type select').removeAttr('disabled');
        });

        $('.form-item-block-type select').off('click').on('click', function () {
            var val = $(this).val();
            var newval = val.join(',')
            $('.default_term').val(newval);
            var result = newval.split(' ');
            bean_type_order_ajax(result);
        });

        if ($('.default_term').val() != '' && $('#preview').text().length == '0') {
            var row = $('.default_term').val();
            var result = row.split(' ');
            bean_type_order_ajax(result);
        }
        /**
         * 
         * @param {type} type
         * @returns {undefined}
         * Dragrable Bean Information Block
         */
        var blocklist = $('#preview');

        blocklist.sortable({
            // Only make the .preview child elements support dragging.
            handle: '.tabledrag-handle',
            update: function () {
                $('.bean-block', blocklist).each(function (index, elem) {
                    var $listItem = $(elem),
                            newIndex = $listItem.index();
                    // Persist the new indices.
                    var bid = [];
                    $('.bean-block .bid').each(function () {
                        bid.push($(this).text());
                    });
                    $('.default_term').val(bid);
                });
            }
        });

    });
    
    /**
     * Add fa-3x class in footer bean type block
     */
    $('.bean-icon i').each(function () {
        $(this).addClass('fa-2x');
    });
})(jQuery);

function node_type_ajax(type) {
    var default_nid = jQuery('.node_id_default').val();
    var url = Drupal.settings.basePath + "ajax/content-type/node";
    jQuery.ajax({
        type: 'post',
        url: url,
        dataType: 'json',
        data: {
            content_type: type,
            default_nid: default_nid
        },
        success: function (data) {
            jQuery('.form-item-node-id select').html(data.output);
        }
    });
}

function term_type_ajax(type) {
    var default_term = jQuery('.default_term').val();
    if (default_term != '') {
        var default_term = default_term.split(' ');
    }
    var url = Drupal.settings.basePath + "ajax/term-type/term";
    jQuery.ajax({
        type: 'post',
        url: url,
        dataType: 'json',
        data: {
            term_type: type,
            default_term: default_term,
        },
        success: function (data) {
            jQuery('.form-item-block-type select').html(data.output);
        }
    });
}

function bean_type_order_ajax(order) {
    var url = Drupal.settings.basePath + "ajax/bean-type/order";
    jQuery.ajax({
        type: 'post',
        url: url,
        dataType: 'json',
        data: {
            bean_order: order,
        },
        success: function (data) {
            jQuery('#preview.form-wrapper').html(data.output);
        }
    });
}