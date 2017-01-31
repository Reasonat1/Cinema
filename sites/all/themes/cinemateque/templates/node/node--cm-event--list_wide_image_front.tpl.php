<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php   
    $event_date = format_date($node->field_cm_event_time['und'][0]['value'], 'custom', 'l | d.m.y');   
    $event_date_mobile = date('d.m.y', $node->field_cm_event_time['und'][0]['value']);
    $event_time = date('G:i', $node->field_cm_event_time['und'][0]['value']);
	$event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
  ?>
  <div class="list_wide_image with-image">
      <div class="left-area">
	  <a href="<?php print $node_url; ?>">
            <?php if (render($content['field_cm_event_images'])){
              print render($content['field_cm_event_images']); 
            }
            else if(!empty($node->field_cm_event_lineup)){
			$event_movie = movie_image_output($node->field_cm_event_lineup['und'][0]['target_id']);
            print $event_movie;
            }
			else {
              print '<img src="/sites/all/themes/cinemateque/images/default-image-pane-2.png">';
            } ?>
            <div class="top-text-blk-wht">
              <?php  if(!empty($node->field_event_top_text_black)){ ?>
                <span class="black"><?php print render($content['field_event_top_text_black']);?></span>
              <?php } 
              if(!empty($node->field_event_top_text_white)){ ?>
                <span class="white"><?php print render($content['field_event_top_text_white']);?></span>
              <?php } ?>
          </div> 
		  </a>
          <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
      </div>
      <div class="right-area">
        <div class="table-responsive">
		<?php if ($event_start_date>time()):?>
          <table class="table">
            <tbody>
              <tr>
                <td class="date only-desktop"><?php print $event_date; ?></td>
                <td class="date only-mobile"><?php print $event_date_mobile; ?><div class="time"><?php print $event_time; ?></div></td>
                <td class="time only-desktop"><?php print $event_time; ?><div class="code only-mobile"><?php print render($content['field_cm_event_hall']); ?></div></td>
                <td class="hall"><?php print render($content['field_cm_event_hall']); ?></td>
                <td class="code only-desktop"><?php print render($content['field_cm_event_internal_id']); ?></td>
                <td class="like-flag only-desktop"><?php print flag_create_link('favorite_', $node->nid); ?> </td>
                <td class="add-event only-desktop"><?php print _return_addthisevent_markup($node); ?></td>
                <td class="purchase"><?php print render($content['field_toptix_purchase']);?></td>
              </tr>
            </tbody>
			<?php endif;?>
          </table>
        </div>
        <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="extra-text"><?php print render($content['field_homepage_extra_text']); ?></div>
        <div class="details"><?php print render($content['field_cm_event_short_description']); ?></div>
        <div class="movie-details"><?php print render($content['field_cm_event_lineup']); ?>  </div>
      </div>
  </div>


</article>