(function ($) {

    $(document).ajaxComplete(function () {
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