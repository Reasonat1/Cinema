<?php
/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-api-page-results.tpl.php. This and the parent template are dependent
 * on one another, sharing the markup for definition lists.
 *
 * View mode is set in the Search page settings. If you select
 * "Themed as search results", then this template will be used for theming the
 * individual results. Any other view mode will bypass this template.
 *
 * Available variables:
 * - $index: The search index this search is based on.
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result.
 * - $info: String of all the meta information ready for print. Applies
 *   only if the result is a node.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $classes: CSS classes for this list element.
 *
 * Default keys within $info_split:
 * - $info_split['user']: Author of the entity, where an author exists.
 *   Depends on permission.
 * - $info_split['date']: Last update of the entity, if the 'updated'
 *   field exists. Short formatted.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array applies where the search result is a node, so it is
 * recommended to check for its existence before printing.
 * Where the result is a node, the default keys of 'user' and 'date'
 * will always exist.
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess_search_api_page_result()
 */
?>
<!--<li class="search-result">
  <h3 class="title">
<?php // print $url ? l($title, $url['path'], $url['options']) : check_plain($title); ?>
  </h3>
  <div class="search-snippet-info">
<?php // if ($snippet) : ?>
      <p class="search-snippet"><?php // print $snippet;    ?></p>
<?php // endif; ?>
<?php // if ($info) : ?>
      <p class="search-info"><?php // print $info;    ?></p>
<?php // endif; ?>
  </div>
</li>-->
<?php if ($variables['item']->type == 'cm_movie' or $variables['item']->type == 'cm_movie_group') { ?>
    <li class="<?php print $classes; ?> cm_movie"<?php print $attributes; ?> >
        <ul class="pro-grid">

            <li>
                <?php
//             echo '<pre>';
//                print_r($variables['item']->type);
                if (isset($variables['url']['options']['entity']->field_featured_image['und'][0]['filename'])) {
                    if ($variables['url']['options']['entity']->field_featured_image['und'][0]['filename'] != "") {
                        $image_path = $GLOBALS['base_url'] . '/sites/default/files/' . $variables['url']['options']['entity']->field_featured_image['und'][0]['filename'];
                    } else {
                        $image_path = $GLOBALS['base_url'] . '/' . path_to_theme() . '/no_image.jpg';
                    }
                } else {
                    $image_path = $GLOBALS['base_url'] . '/' . path_to_theme() . '/no_image.jpg';
                }
                ?>
                <img src="<?php print $image_path ?>" class="pro-img"/>
            </li>

            <li>
                <?php // print render($title_prefix); ?>
                <h1 class="title"<?php print $title_attributes; ?>>   
                    <?php print $url ? l($title, $url['path'], $url['options']) : check_plain($title); ?>
                  <!--<a href="<?php // print $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['HTTP_HOST'].'/'.$variables['url']['path'];    ?>"> <?php // print_r($variables['url']['options']['entity']->title);    ?></a>-->
                </h1>
<!--            </li>
            <li>-->
                <?php // print render($title_suffix); ?>
                <div class="search-view-mode">
                    <?php
                    if (isset($variables['url']['options']['entity']->body['und'][0]['value'])) {
                        print($variables['url']['options']['entity']->body['und'][0]['value']);
                    }
                    ?>
                    <?php // print($variables['result']['node']->rendered); ?>
                </div>
                <div class="search-snippet-info">
                    <?php if ($snippet) : ?>
                        <p class="search-snippet"><?php // print $snippet;    ?></p>
                    <?php endif; ?>
                    <?php if ($info) : ?>
                        <p class="search-info"><?php print $info; ?>
                            <span class="fa fa-heart-o"> </span> 
                            <span class="fa fa-calendar-o"> </span>
                            <span class="purchase-btn"> Purchase </span>
                        </p>
                    <?php endif; ?>
                </div>
            </li>

        </ul>



    </li>
    <?php
}else
if ($variables['item']->type == 'cm_event') {
    ?>
    <li class="<?php print $classes; ?> cm_event"<?php print $attributes; ?>>
        <ul class="pro-grid">

            <li>
                <?php
//             echo '<pre>';
                print_r($variables['item']->type);
                if (isset($variables['url']['options']['entity']->field_featured_image['und'][0]['filename'])) {
                    if ($variables['url']['options']['entity']->field_featured_image['und'][0]['filename'] != "") {
                        $image_path = $GLOBALS['base_url'] . '/sites/default/files/' . $variables['url']['options']['entity']->field_featured_image['und'][0]['filename'];
                    } else {
                        $image_path = $GLOBALS['base_url'] . '/' . path_to_theme() . '/no_image.jpg';
                    }
                } else {
                    $image_path = $GLOBALS['base_url'] . '/' . path_to_theme() . '/no_image.jpg';
                }
                ?>
                <img src="<?php print $image_path ?>" class="pro-img"/>
            </li>

            <li>
                <div class="search-snippet-info">
                    <?php if ($snippet) : ?>
                        <p class="search-snippet"><?php // print $snippet;    ?></p>
                    <?php endif; ?>
                    <?php if ($info) : ?>
                        <p class="search-info"><?php print $info; ?>
                        <span class="fa fa-heart-o"> </span> 
                            <span class="fa fa-calendar-o"> </span>
                            <span class="purchase-btn"> Purchase </span>
                        </p>
                    <?php endif; ?>
                </div>
                
                <?php // print render($title_prefix); ?>
                <h1 class="title"<?php print $title_attributes; ?>>   
                    <?php print $url ? l($title, $url['path'], $url['options']) : check_plain($title); ?>
                  <!--<a href="<?php // print $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['HTTP_HOST'].'/'.$variables['url']['path'];   ?>"> <?php // print_r($variables['url']['options']['entity']->title);   ?></a>-->
                </h1>
                <div class="search-view-mode">
                    <?php
                    if (isset($variables['url']['options']['entity']->body['und'][0]['value'])) {
                        print($variables['url']['options']['entity']->body['und'][0]['value']);
                    }
                    ?>
                    <?php // print($variables['result']['node']->rendered); ?>
                </div>
            </li>
<!--            <li>
                <?php // print render($title_suffix); ?>
            </li>-->

        </ul>



    </li>
    <?php
} else
if ($variables['item']->type == 'cm_person') {
    ?>
    <li class="<?php print $classes; ?> cm_person"<?php print $attributes; ?>>
        <ul class="pro-grid">

            <li>
                <?php
//             echo '<pre>';
                print_r($variables['item']->type);
                if (isset($variables['url']['options']['entity']->field_featured_image['und'][0]['filename'])) {
                    if ($variables['url']['options']['entity']->field_featured_image['und'][0]['filename'] != "") {
                        $image_path = $GLOBALS['base_url'] . '/sites/default/files/' . $variables['url']['options']['entity']->field_featured_image['und'][0]['filename'];
                    } else {
                        $image_path = $GLOBALS['base_url'] . '/' . path_to_theme() . '/no_image.jpg';
                    }
                } else {
                    $image_path = $GLOBALS['base_url'] . '/' . path_to_theme() . '/no_image.jpg';
                }
                ?>
                <img src="<?php print $image_path ?>" class="pro-img"/>
            </li>

            <li>
                <?php // print render($title_prefix);  ?>
                <h1 class="title"<?php print $title_attributes; ?>>   
                    <?php print $url ? l($title, $url['path'], $url['options']) : check_plain($title); ?>
                  <!--<a href="<?php // print $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['HTTP_HOST'].'/'.$variables['url']['path'];   ?>"> <?php // print_r($variables['url']['options']['entity']->title);   ?></a>-->
                </h1>
            </li>
            <li>
                <?php // print render($title_suffix);  ?>
                <div class="search-view-mode">
                    <?php
                    if (isset($variables['url']['options']['entity']->body['und'][0]['value'])) {
                        print($variables['url']['options']['entity']->body['und'][0]['value']);
                    }
                    ?>
                    <?php // print($variables['result']['node']->rendered); ?>
                </div>
            </li>

        </ul>
    </li>
    <?php
} else {
    
}
?>

