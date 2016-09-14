<?php
//unset($elements['links']);
//unset($elements['language']);
unset($content['links']);
unset($content['language']);
//dpm(get_defined_vars());
?>
<div class="node-title-teaser node-title-teaser-cm-movie node-title-teaser-content-type">
	<div class="node-cm-movie-year"><?php print $content['field_cm_movie_year'][0]['#markup'];?></div>
	<?php $nodeurl = url('node/'. $node->nid);?>
	<a href="<?php print $nodeurl;?>">
		<div class="node-title-teaser-title">
		  <h3><?php print $title;?></h3>
		</div>
	</a>
</div>