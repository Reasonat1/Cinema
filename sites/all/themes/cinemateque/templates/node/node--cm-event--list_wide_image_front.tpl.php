<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php   
    if(!empty($node->field_cm_event_lineup['und'])){
       $event_ext_nodes = node_load($node->field_cm_event_lineup['und'][0]['target_id']);
    }
    $event_date = '<span class="day-same-width">'.format_date(($node->field_cm_event_time['und'][0]['value']), 'custom', 'l').'</span>';
    $event_date .= format_date($node->field_cm_event_time['und'][0]['value'], 'custom', ' d.m.y');   
    $event_date_mobile = date('d.m.y', $node->field_cm_event_time['und'][0]['value']);
    $event_time = date('H:i', $node->field_cm_event_time['und'][0]['value']);
	$event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
  ?>
  <div class="list_wide_image event">
      <div class="left-area">
	  <a class="all-image" href="<?php print $node_url; ?>"></a>
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
          <div class="views-field-ops"><?php print flag_create_link('favorite_', $node->nid); ?> </div>
          <?php  if(!empty($event_ext_nodes->field_cm_movie_videos)){ ?>
            <div class="video-link">
             <?php print movie_video_output($event_ext_nodes->nid); ?>
            </div>
            <div class="gradient small"></div>
          <?php } ?>
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
                <td class="add-event"><?php print _return_addthisevent_markup($node); ?></td>
                <?php $event_start_date=(!empty($node->field_cm_event_time['und']))?$node->field_cm_event_time['und'][0]['value']:'';
                if ($event_start_date>time()){?>
                    <?php if(empty($node->field_tickets_sold_out['und'][0]['value'])){ ?>
                        <td class="purchase"><?php print render($content['field_toptix_purchase']);?></td>
                    <?php } else{ ?>
                        <td class="purchase"><button class="sold-out"><?php print t("sold out");?></button></td>
                    <?php } ?>
                <?php } else {?>
                  <td class="purchase"></td>
                <?php } ?>
              </tr>
            </tbody>
			<?php endif;?>
          </table>
        </div>
        <?php
        $titlenode = '<h2 class="title"><a href="'.$node_url.'">'.$title.'</a></h2>';
        $path_node = drupal_get_path_alias('node/'.$node->nid);
        if(!empty($node->field_cm_event_lineup['und'])){
          $movietitle = $event_ext_nodes->title;
          if((strtolower($node->title))==(strtolower($event_ext_nodes->title))){
            $titlenode = '';
            $movietitle = l($event_ext_nodes->title, $path_node);
          }
        } 
        print $titlenode;?>
        <?php if(!empty($node->field_cm_event_short_description['und'])){ ?>
          <div class="details"><?php print render($content['field_cm_event_short_description']); ?></div>
        <?php } ?>
        <?php if(!empty($node->field_cm_event_lineup['und'])){ ?>
          <div class="movie-details">
            <h2 class="title title-movie"><?php print $movietitle; ?></h2>
            <?php if($event_ext_nodes->type == 'cm_movie_group'){
              if(!empty($event_ext_nodes->field_cm_moviegroup_duration['und'])){ 
                $length_interval = t($event_ext_nodes->field_cm_moviegroup_duration['und'][0]['interval']);
                $length_period = t($event_ext_nodes->field_cm_moviegroup_duration['und'][0]['period'].'s');
                $duration = $length_interval.' '.$length_period; ?>
                <div class="duration"><?php print $duration; ?></div>
              <?php }
              if(!empty($event_ext_nodes->field_cm_moviegroup_short_summar['und'])){ 
                $summary = $event_ext_nodes->field_cm_moviegroup_short_summar['und'][0]['value'];?>
                <div class="summary"><?php print $summary; ?></div>
              <?php }
            }
            else { 
              if(!empty($event_ext_nodes->field_cm_movie_meta_credit['und'])){ 
                $credit = $event_ext_nodes->field_cm_movie_meta_credit['und'][0]['value']; ?>
                <div class="credit-movie"><?php print $credit; ?></div>
              <?php } 
              if(!empty($event_ext_nodes->field_cm_movie_duration['und'])){ 
                $length_interval = t($event_ext_nodes->field_cm_movie_duration['und'][0]['interval']);
                $length_period = t($event_ext_nodes->field_cm_movie_duration['und'][0]['period'].'s');
                $duration = ' | '.$length_interval.' '.$length_period; ?>
                <div class="duration"><?php print $duration; ?></div>
              <?php } 
              if ($GLOBALS['_domain']['domain_id'] == 1 ){ 
              if(!empty($event_ext_nodes->field_cm_movie_short_summary['und'])){ 
                  $summary = $event_ext_nodes->field_cm_movie_short_summary['und'][0]['value']; ?>
                  <div class="summary"><?php print $summary; ?></div>
                <?php }
              } else if(!empty($event_ext_nodes->field_short_summary_festival ['und'])){ 
                 $summary = $event_ext_nodes->field_short_summary_festival  ['und'][0]['value']; 
               } else if(!empty($event_ext_nodes->field_cm_movie_short_summary ['und'])){ 
                 $summary = $event_ext_nodes->field_cm_movie_short_summary  ['und'][0]['value'];?>
                  <div class="summary"><?php print $summary; ?></div>
                <?php }
            }
            ?>
          </div>
        <?php } ?>
  </div>


</article>