<?php
//unset($elements['links']);
//unset($elements['language']);
unset($content['links']);
unset($content['language']);
//dpm(get_defined_vars());
?>
<div class="node-title-teaser node-title-teaser-cm-movie-group node-title-teaser-content-type">
	<?php $nodeurl = url('node/'. $node->nid);?>
	<a href="<?php print $nodeurl;?>">
		<div class="node-title-teaser-title">
		  <h3><?php print $title;?> </h3>
		</div>
	</a>
</div>