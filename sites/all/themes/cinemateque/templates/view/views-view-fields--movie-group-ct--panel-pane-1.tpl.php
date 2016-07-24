<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
 //dpm($row);
 //dpm($fields);
 $state = (isset($fields['field_cm_movie_pictures']->content)) ? 'haspic' : 'nopic';
?>
   
<div class="movie-group-item">
  <div class="movie-group-item-header state-<?php print $state; ?>">
    <?php if(isset($fields['field_cm_movie_pictures']->content) && (isset($fields['field_mc_teaser_toptxt_blk']->content) || isset($fields['field_mc_teaser_toptxt_white']->content))) { ?>
      <div class="top-text-blk-wht">
        <span class="black"><?php print $fields['field_mc_teaser_toptxt_blk']->content;?></span>
        <span class="white"><?php print $fields['field_mc_teaser_toptxt_white']->content;?></span>
      </div>		
	<?php } ?>
	
	<div class="flag"><?php if(isset($fields['ops']->content)) { print $fields['ops']->content; } ?></div>
	
    <div class="movie-group-item-header-img">
	  <?php if(isset($fields['field_cm_movie_pictures']->content)) print l($fields['field_cm_movie_pictures']->content,'node/' . $row->nid,array('html' => TRUE)); ?>
    <div class="title-movie <?php print $state; ?>"><?php print $fields['title_1']->content; ?></div>
	</div>
  </div>
  <div class="under-image">
    <div class="movie-gorup-item-meta-info">
      <?php print $fields['nothing_1']->content; ?> 
    </div>
    <div class="movie-gorup-item-teaser-txt">
      <?php
	  if(!empty($fields['field_cm_movie_body']->content)){
              print $fields['field_cm_movie_body']->content;
	  }else{
              print $fields['field_cm_movie_short_summary']->content;
	  }
      ?>
    </div>
  </div>
</div>
