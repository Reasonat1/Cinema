(function ($) {
    $(document).ajaxComplete(function () {
        // hide/show field based on content selection
        if ($('.form-item-content-type select').val() != 'cm_event' && $('.form-item-content-type select').val() != 'cm_movie' && $('.form-item-content-type select').val() != 'cm_movie_group') {
            $('.form-item-top-black-title').hide();
            $('.form-item-top-white-title').hide();
            $('.form-item-movie-image').hide();
            $('.form-item-movie-image-side').hide();
            //$('.form-item-movie-title').hide();
            $('.form-item-movie-metainfo').hide();
            $('.form-item-upcomming-event').hide();
            //$('.form-item-movie-teaser-text-').hide();
        } else {
            $('.form-item-top-black-title').show();
            $('.form-item-top-white-title').show();
            $('.form-item-movie-image').show();
            $('.form-item-movie-image-side').show();
            //$('.form-item-movie-title').show();
            $('.form-item-movie-metainfo').show();
            $('.form-item-upcomming-event').show();
            //$('.form-item-movie-teaser-text-').show();
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
                //$('.form-item-movie-title').hide();
                $('.form-item-movie-metainfo').hide();
                $('.form-item-upcomming-event').hide();
                //$('.form-item-movie-teaser-text-').hide();
            } else {
                $('.form-item-top-black-title').show();
                $('.form-item-top-white-title').show();
                $('.form-item-movie-image').show();
                $('.form-item-movie-image-side').show();
                //$('.form-item-movie-title').show();
                $('.form-item-movie-metainfo').show();
                $('.form-item-upcomming-event').show();
                //$('.form-item-movie-teaser-text-').show();
            }
            if ($(this).val() == 'cm_article') {
                $('.form-item-top-black-title').show();
                $('.form-item-top-white-title').show();
            }
            node_type_ajax($(this).val());
        });

    });

})(jQuery);

//function node_type_ajax(type) {
//    var default_nid = jQuery('.node_id_default').val();
//    var url = Drupal.settings.basePath + "ajax/content-type/node";
//    jQuery.ajax({
//        type: 'post',
//        url: url,
//        dataType: 'json',
//        data: {
//            content_type: type,
//            default_nid: default_nid
//        },
//        success: function (data) {
//            jQuery('.form-item-node-id select').html(data.output);
//        }
//    });
//}

function node_type_ajax(type) {
    var default_nid = jQuery('.node_id_default').val();
    var url = Drupal.settings.basePath + "node/autocomplete";
    console.log(url);
    
    jQuery.ajax({
        type: 'post',
        url: url,
        dataType: 'json',
        data: {
            content_type: type,
            default_nid: default_nid
        },
        success: function (data) {
             console.log(data);
            jQuery('.form-item-node-id').html(data.output);
        }
    });
}