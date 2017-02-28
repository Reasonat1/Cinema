<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="grid_3_item">
      <div class="image">
            <a href="<?php print $node->field_link['und'][0]['display_url']; ?>">
            <?php if (render($content['field_main_image'])){
              print render($content['field_main_image']); 
            }
			       else {
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="gradient small"></div> 
            </a>
      </div>
      <a class="all-image" href="<?php print $node->field_link['und'][0]['display_url']; ?>">
        <div class="on-image">
          <?php if ($node->field_show_title){
            if ($node->field_show_title['und'][0]['value'] != 0) { ?>
                <h2 class="title"><?php print $title; ?></h2>
          <?php } 
          } ?>
          <div class="extra-text"><?php print render($content['field_sub_title']); ?></div>
          <div class="screaning">
            <div class="table-responsive">
              <table class="table">
                <tbody>
                  <tr class="row-custom-lobby">
                    <?php if(!empty($node->field_cm_event_time['und'])){ 
                        $event_date_mobile = format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'd.m.y'); ?>
                        <td class="date only-desktop"><?php print format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'l d.m.y | '); ?></td>
                        <td class="date only-mobile"><?php print $event_date_mobile; ?><div class="time"><?php print date('H:i', $node->field_cm_event_time['und'][0]['value']); ?></div></td>
                        <td class="time only-desktop"><?php print date('H:i', $node->field_cm_event_time['und'][0]['value']); ?></td>
                    <?php } 
                    $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
                    if ($event_start_date>time()):?>
                      <td class="purchase"><?php print render($content['field_toptix_purchase']); ?></td>
                    <?php endif;?>
                  </tr>
                </tbody>
              </table>
            </div>
          </div>
        </div>
      </a>
  </div>


</article>
