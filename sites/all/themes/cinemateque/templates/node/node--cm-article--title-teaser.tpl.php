<?php
//unset($elements['links']);
//unset($elements['language']);
unset($content['links']);
unset($content['language']);
//dpm(get_defined_vars());
?>
<?php if($field_cm_article_subtitle){ ?> <div class="teaser-with-sub"> <?php } ?>
	<div class="node-title-teaser node-title-teaser-cm-article node-title-teaser-content-type">
			<?php $nodeurl = url('node/'. $node->nid);?>
			<a href="<?php print $nodeurl;?>">
				<div class="node-title-teaser-title">
				  <h3><?php print $title;?> </h3>
				<?php if($field_cm_article_subtitle){ ?>
					<div class="node-title-teaser-sub-title">
					  <?php print $field_cm_article_subtitle[0]['safe_value'];?>
					</div>
				<?php } ?>	 	  
				</div>
			</a>
	</div>
<?php if($field_cm_article_subtitle){ ?> </div> <?php } ?>
