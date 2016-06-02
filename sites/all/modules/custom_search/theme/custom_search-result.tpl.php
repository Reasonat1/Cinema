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
                $image_path=$variables['result']['node']->field_featured_image['und'][0]['filename']; 
             }
             else{
                 $image_path=$GLOBALS['base_url']. '/sites/default/files/no_image.jpg';
             }
             }
             else{
                 $image_path=$GLOBALS['base_url']. '/sites/default/files/no_image.jpg';
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


<style>
    .search-results.node-results {
    padding: 0 !important;
}
    
    .pro-grid{
margin:10px auto;
background: rgb(227, 227, 227) none repeat scroll 0% 0%;
padding: 0.5% ;
border: 3px double rgb(183, 183, 183);}
    
 .pro-grid:nth-child(odd){background: transparent}   
    .pro-grid li:nth-child(1){ width:10% !important; }
    .pro-grid li{ width:44%; display: inline-block; vertical-align: middle;  margin-bottom: 0;}
    .pro-grid li .pro-img {
    max-width: 100%;
    background: #f6f6f6;
    padding: 2px;
    border: 1px solid #BFBFBF;
    border-radius: 4px;
    -webkit-border-radius: 4px;
}

.pro-grid li .title {
text-align: left;
text-transform: uppercase;
font-size: 14px;
}

.pro-grid li .title a{ color:#333 !important}

.pro-grid li .search-view-mode p {
    font-size: 13px !important;
    margin: 0 !important;
    line-height: 1.25 !important;
    overflow: hidden;
    text-overflow: ellipsis;
    max-height: 56px;
    -webkit-line-clamp: 2;
    -webkit-box-orient: vertical;
    line-clamp: 2;
    box-orient: vertical;
}
.search-result:nth-child(even){ background: #fff}
 .search-result:nth-child(odd){ background: #f5f5f5}

@media(max-device-width:420px){
    .pro-grid{ padding: 10px }
    .pro-grid li:nth-child(1){ width:40% !important; margin: auto; }
    .pro-grid li{ width:100%; display: block; vertical-align: middle;  margin-bottom: 0;}
}
    </style>