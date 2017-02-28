<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="list_wide_image content-hp event">
      <div class="left-area">
        <a class="all-image" href="<?php print $node->field_link['und'][0]['display_url']; ?>"></a>
            <?php if (render($content['field_main_image'])){
              print render($content['field_main_image']); 
            }
			       else {
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?> 
      </div>
      <div class="right-area">
          <div class="screaning">
            <div class="table-responsive">
              <table class="table">
                <tbody>
                  <tr class="row-custom-lobby">
                    <?php if(!empty($node->field_cm_event_time['und'])){ 
                        $event_date = '<span class="day-same-width">'.format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'l').'</span>';
                        $event_date .= format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', ' d.m.y'); 
                        $event_date_mobile = format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'd.m.y'); ?>
                        <td class="date only-desktop"><?php print $event_date; ?></td>
                        <td class="date only-mobile"><?php print $event_date_mobile; ?><div class="time"><?php print date('H:i', $node->field_cm_event_time['und'][0]['value']); ?></div></td>
                        <td class="time only-desktop"><?php print date('H:i', $node->field_cm_event_time['und'][0]['value']); ?></td>
                    <?php } ?>
                    <td class="hall"><?php print render($content['field_cm_event_hall']); ?></td>
                    <td class="code only-desktop"></td>
                    <td class="like-flag only-desktop"></td>
                    <td class="add-event only-desktop"></td>
                    <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
                    if ($event_start_date>time()):?>
                      <td class="purchase"><?php print render($content['field_toptix_purchase']); ?></td>
                    <?php endif;?>
                  </tr>
                </tbody>
              </table>
            </div>
          </div>
          <?php if ($node->field_show_title){
            if ($node->field_show_title['und'][0]['value'] != 0) { ?>
                <h2 class="title"><a href="<?php print $node->field_link['und'][0]['display_url']; ?>"><?php print $title; ?></a></h2>
        <?php }
        } ?>
        <div class="only-duration"><?php print render($content['field_sub_title']); ?></div>
        <div class="movie-details"><?php print render($content['field_homepage_extra_text']); ?></div>
      </div>
  </div>
</article>