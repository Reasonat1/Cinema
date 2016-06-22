<?php
//unset($elements['links']);
//unset($elements['language']);
unset($content['links']);
unset($content['language']);
//dpm(get_defined_vars());
?>
<div class="node-title-teaser node-title-teaser-cm-movie">
	<div class="node-cm-movie-year"><?php print $content['field_cm_movie_year'][0]['#markup'];?></div>
	<div class="node-title-teaser-title">
	  <h3><?php print l($title,'node/'.$nid);?></h3>
	</div>
	<?php print l('<span class="click-arrow" />','node/'.$nid,array('html' => TRUE));?>
</div>