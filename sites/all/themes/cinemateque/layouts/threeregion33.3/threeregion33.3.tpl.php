<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a very simple "one column" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['middle']: The only panel in the layout.
 */
?>
<div class="panel-display panel-1col clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel panel-col  panel-col-left">
    <div><?php print $content['left']; ?></div>
  </div>
    <div class="panel-panel panel-col panel-col-middel">
    <div><?php print $content['middel']; ?></div>
  </div>
    <div class="panel-panel panel-col panel-col-right">
    <div><?php print $content['right']; ?></div>
  </div>
</div>