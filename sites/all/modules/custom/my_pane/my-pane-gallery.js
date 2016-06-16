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
        if ($('select#edit-content-type').val() != 'cm_event' && $('select#edit-content-type').val() != 'cm_movie' && $('select#edit-content-type').val() != 'cm_movie_group') {
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
        if ($('select#edit-content-type').val() == 'cm_article') {
            $('.form-item-top-black-title').show();
            $('.form-item-top-white-title').show();
        }
        if ($('.form-item-node-id select').val() == '0') {
            var type = $('.form-item-content-type select').val();
            node_type_ajax(type);
        }

        $('select#edit-content-type').change(function () {
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