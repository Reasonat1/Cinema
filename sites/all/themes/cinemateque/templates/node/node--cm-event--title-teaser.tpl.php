<?php
//unset($elements['links']);
//unset($elements['language']);
unset($content['links']);
unset($content['language']);
//dpm(get_defined_vars());
?>
<div class="node-title-teaser node-title-teaser-cm-event">
	<div class="node-title-teaser-title">
	   <h3><?php print l($title,'node/'.$nid);?></h3>
	<?php if($field_cm_event_subtitle){ ?>
		<div class="node-title-teaser-sub-title">
		<?php print $field_cm_event_subtitle[0]['safe_value'];?>
		</div>
	<?php } ?>	  
	</div>
	<?php print l('<span class="click-arrow" />','node/'.$nid,array('html' => TRUE));?>
	
</div>