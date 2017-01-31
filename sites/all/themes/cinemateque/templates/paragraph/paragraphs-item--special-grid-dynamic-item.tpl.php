<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<?php 
$imageplace = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_image_place');
$withimage = field_get_items('paragraphs_item', $variables['paragraphs_item'], 'field_with_image');

?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
  	<div class="<?php print $imageplace[0]['value']; print ' '; print $withimage[0]['value'];?>">
  	    <?php hide($content['field_image_place']);
  	    hide($content['field_with_image']);
    	print render($content); ?>
    </div>
  </div>
</div>

<?php

 


 ?>