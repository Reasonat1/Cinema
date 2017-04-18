<?php

/**
 * @file
 * Radix theme implementation to display a node.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<article class="screaning-only <?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']); ?>
      <div class="screaning"><?php print screaning_output($node->nid); ?></div>
  </div>

</article>
