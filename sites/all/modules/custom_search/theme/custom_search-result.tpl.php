<?php

/**
 * @file
 * Theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * custom_search-results.tpl.php. This and the parent template are
 * dependent to one another sharing the markup for definition lists.
 *
 * Available variables:
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result. Does not apply to user searches.
 * - $info: String of all the meta information ready for print. Does not apply
 *   to user searches.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $type: The type of search, e.g., "node" or "user".
 *
 * Default keys within $info_split:
 * - $info_split['type']: Node type.
 * - $info_split['user']: Author of the node linked to users profile. Depends
 *   on permission.
 * - $info_split['date']: Last update of the node. Short formatted.
 * - $info_split['comment']: Number of comments output as "% comments", %
 *   being the count. Depends on comment.module.
 * - $info_split['upload']: Number of attachments output as "% attachments", %
 *   being the count. Depends on upload.module.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array does not apply to user searches so it is recommended to check
 * for their existence before printing. The default keys of 'type', 'user' and
 * 'date' always exist for node searches. Modules may provide other data.
 *
 *   <?php if (isset($info_split['comment'])) : ?>
 *     <span class="info-comment">
 *       <?php print $info_split['comment']; ?>
 *     </span>
 *   <?php endif; ?>
 *
 * To check for all available data within $info_split, use the code below.
 *
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 *
 * @see template_preprocess_custom_search_result()
 */
?>
<!--<li>
  <h3 class="title">
    <a href="<?php // print $url; ?>"><?php // print $title; ?></a>
  </h3>
  <div class="search-snippet-info">
    <?php // if ($snippet) : ?>
      <p class="search-snippet"><?php // print $snippet; ?></p>
    <?php // endif; ?>
    <?php // if ($info) : ?>
      <p class="search-info"><?php // print $info; ?></p>
    <?php // endif; ?>
  </div>
</li>-->
<li class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <ul class="pro-grid">
        
         <li>
             <?php 
             if(isset($variables['result']['node']->field_featured_image['und'][0]['filename'])){
             if($variables['result']['node']->field_featured_image['und'][0]['filename']!=""){
               $image_path=$GLOBALS['base_url']. '/sites/default/files/'.$variables['result']['node']->field_featured_image['und'][0]['filename']; 
             }
             else{
                 $image_path=$GLOBALS['base_url']. '/'.path_to_theme().'/no_image.jpg';
             }
             }
             else{
                 $image_path=$GLOBALS['base_url']. '/'.path_to_theme().'/no_image.jpg';
             }
             ?>
             <img src="<?php print $image_path?>" class="pro-img"/>
        </li>
        
        <li>
  <?php print render($title_prefix); ?>
  <h1 class="title"<?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h1>
        </li>
        <li>
  <?php print render($title_suffix); ?>
  <div class="search-view-mode">
      <?php 
      if(isset($variables['result']['node']->body['und'][0]['value'])){
      print($variables['result']['node']->body['und'][0]['value']);
      }
      ?>
    <?php // print($variables['result']['node']->rendered); ?>
  </div>
        </li>
       
    </ul>
    
    
  <div class="search-snippet-info">
    <?php if ($snippet): ?>
      <!--<p class="search-snippet"<?php // print $content_attributes; ?>><?php // print $snippet; ?></p>-->
    <?php endif; ?>
    <?php if ($info): ?>
      <p class="search-info"><?php //print $info; ?></p>
    <?php endif; ?>
  </div>
</li>
