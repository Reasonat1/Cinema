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
      <p class="search-snippet"><?php // print $snippet;       ?></p>
<?php // endif; ?>
<?php // if ($info) : ?>
      <p class="search-info"><?php // print $info;       ?></p>
<?php // endif; ?>
  </div>
</li>-->
<?php if ($variables['item']->type == 'cm_movie' or $variables['item']->type == 'cm_movie_group') { ?>
    <li class="<?php print $classes; ?> cm_movie"<?php print $attributes; ?> >
        <ul class="pro-grid">
            <li>
                <?php
//             echo '<pre>';
//                print_r($variables['item']->changed);die;
                if (isset($variables['item']->field_movie_banner_image['und'][0]['uri'])) {
                    if ($variables['item']->field_movie_banner_image['und'][0]['uri'] != "") {
                        $image_path = file_create_url($variables['item']->field_movie_banner_image['und'][0]['uri']);
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
                  <!--<a href="<?php // print $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['HTTP_HOST'].'/'.$variables['url']['path'];       ?>"> <?php // print_r($variables['url']['options']['entity']->title);       ?></a>-->
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
                        <p class="search-snippet"><?php // print $snippet;       ?></p>
                    <?php endif; ?>
                    <?php if ($info) : ?>
                        <p class="search-info"><?php print $info; ?>
                            <!--<span class="fa fa-heart-o"> </span>--> 
                            <!--<span class="fa fa-calendar-o"> </span>-->
                            <span class="views-field-php"><a title="" href="<?php echo $_SERVER['REQUEST_SCHEME'] . '://' . $_SERVER['HTTP_HOST'] . '/' . $variables['url']['path'] ?>" class="addthisevent">Add to Calendar
                                    <span style="display: none;" class="_start"><?php echo date('d-m-Y h:i:s', $variables['item']->changed); ?></span>
                                    <span style="display: none;" class="_start"><?php echo date('d-m-Y h:i:s', $variables['item']->changed); ?></span>
                                    <span style="display: none;" class="_zonecode"><?php echo $variables['item']->title; ?></span>
                                    <span style="display: none;" class="_summary"><?php echo $variables['item']->title; ?></span>
                                    <span style="display: none;" class="_description"><?php echo $variables['item']->title; ?></span>
                                    <span style="display: none;" class="_organizer"><?php echo $variables['item']->name; ?></span>
                                    <span style="display: none;" class="_organizer_email">office@reasonat.com</span>
                                    <span style="display: none;" class="_all_day_event">false</span>
                                    <span style="display: none;" class="_date_format">DD/MM/YYYY</span><span class="addthisevent_icon"></span><span class="addthisevent_dropdown" id="atedrop2-drop"><span class="ateappleical" data-ref="2" onclick="addthisevent.click(this, 'appleical', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Apple Calendar</span><span class="ategoogle" data-ref="2" onclick="addthisevent.click(this, 'google', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Google <em>(online)</em></span><span class="ateoutlook" data-ref="2" onclick="addthisevent.click(this, 'outlook', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Outlook</span><span class="ateoutlookcom" data-ref="2" onclick="addthisevent.click(this, 'outlookcom', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Outlook.com <em>(online)</em></span><span class="ateyahoo" data-ref="2" onclick="addthisevent.click(this, 'yahoo', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Yahoo <em>(online)</em></span><em class="copyx"><em class="brx"></em><em class="frs" data-ref="2" onclick="addthisevent.click(this, 'home');">AddEvent.com</em></em></span></a>
                            </span>
                            <?php if ($variables['item']->field_toptix_purchase['und'][0]['value'] != "") { ?>                             <!--<span class="purchase-btn"> Purchase </span>-->
                                <button class="toptix-purchase" data-url="http://199.203.164.53/loader.aspx/?target=hall.aspx?event=<?php echo $variables['item']->field_toptix_purchase['und'][0]['value'] ?>">Purchase</button>
                                    <!--<input type="button" class="purchase-btn" value="Purchase" style="background: #b59d70 !important;"/>-->
                            <?php } else { ?> 
                                <button class="toptix-purchase" data-url="http://199.203.164.53/loader.aspx/?target=hall.aspx">Purchase</button>
                            <?php } ?>
                        </p>
                    <?php endif; ?>
                </div>
            </li>

        </ul>



    </li>
    <?php
} else
if ($variables['item']->type == 'cm_event') {
    ?>
    <li class="<?php print $classes; ?> cm_event"<?php print $attributes; ?>>
        <ul class="pro-grid">

            <li>
                <?php
//             echo '<pre>';
//               print_r(date('d-m-Y h:i:s',$variables['item']->field_cm_event_time['und'][0]['value']));die;
                if (isset($variables['item']->field_cm_event_images['und'][0]['uri'])) {
                    if ($variables['item']->field_cm_event_images['und'][0]['uri'] != "") {
                        $image_path = file_create_url($variables['item']->field_cm_event_images['und'][0]['uri']);
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
                        <p class="search-snippet"><?php // print $snippet;       ?></p>
                    <?php endif; ?>
                    <?php if ($info) : ?>
                        <p class="search-info"><?php print $info; ?>
                        <!--<span class="fa fa-heart-o"> </span> --> 
                            <!--<span class="fa fa-calendar-o"> </span>-->
                            <span class="views-field-php"><a title=""  href="<?php echo $_SERVER['REQUEST_SCHEME'] . '://' . $_SERVER['HTTP_HOST'] . '/' . $variables['url']['path'] ?>" class="addthisevent">Add to Calendar
                                    <span style="display: none;" class="_start"><?php echo date('d-m-Y h:i:s', $variables['item']->field_cm_event_time['und'][0]['value']); ?></span>
                                    <span style="display: none;" class="_start"><?php echo date('d-m-Y h:i:s', $variables['item']->field_cm_event_time['und'][0]['value2']); ?></span>
                                    <span style="display: none;" class="_zonecode"><?php echo $variables['item']->title; ?></span>
                                    <span style="display: none;" class="_summary"><?php echo $variables['item']->title; ?></span>
                                    <span style="display: none;" class="_description"><?php echo $variables['item']->title; ?></span>
                                    <span style="display: none;" class="_organizer"><?php echo $variables['item']->name; ?></span>
                                    <span style="display: none;" class="_organizer_email">office@reasonat.com</span>
                                    <span style="display: none;" class="_all_day_event">false</span>
                                    <span style="display: none;" class="_date_format">DD/MM/YYYY</span><span class="addthisevent_icon"></span><span class="addthisevent_dropdown" id="atedrop2-drop"><span class="ateappleical" data-ref="2" onclick="addthisevent.click(this, 'appleical', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Apple Calendar</span><span class="ategoogle" data-ref="2" onclick="addthisevent.click(this, 'google', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Google <em>(online)</em></span><span class="ateoutlook" data-ref="2" onclick="addthisevent.click(this, 'outlook', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Outlook</span><span class="ateoutlookcom" data-ref="2" onclick="addthisevent.click(this, 'outlookcom', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Outlook.com <em>(online)</em></span><span class="ateyahoo" data-ref="2" onclick="addthisevent.click(this, 'yahoo', '&amp;dstart=24-05-2016%2021%3A00%3A00&amp;dstart=24-05-2016%2023%3A15%3A00&amp;dzone=40&amp;dsum=TestEvent&amp;ddesc=%26lt%3Bp%26gt%3BThis%20is%20test%20event%26nbsp%3B%26lt%3B%2Fp%26gt%3B&amp;dorga=admin&amp;dorgaem=office%40reasonat.com&amp;dallday=false&amp;dateformat=DD%2FMM%2FYYYY');">Yahoo <em>(online)</em></span><em class="copyx"><em class="brx"></em><em class="frs" data-ref="2" onclick="addthisevent.click(this, 'home');">AddEvent.com</em></em></span></a>
                            </span>
                          <!--<input type="button" class="purchase-btn" value="Purchase" style="background: #b59d70 !important;"/>-->
                            <?php if ($variables['item']->field_toptix_purchase['und'][0]['value'] != "") { ?>                             <!--<span class="purchase-btn"> Purchase </span>-->
                                <button class="toptix-purchase" data-url="http://199.203.164.53/loader.aspx/?target=hall.aspx?event=<?php echo $variables['item']->field_toptix_purchase['und'][0]['value'] ?>">Purchase</button>
                                <!--<input type="button" class="purchase-btn" value="Purchase" style="background: #b59d70 !important;"/>-->
                            <?php } else { ?> 
                                <button class="toptix-purchase" data-url="http://199.203.164.53/loader.aspx/?target=hall.aspx">Purchase</button>
                            <?php } ?>
                        </p>
                    <?php endif; ?>
                </div>

                <?php // print render($title_prefix); ?>
                <h1 class="title"<?php print $title_attributes; ?>>   
                    <?php print $url ? l($title, $url['path'], $url['options']) : check_plain($title); ?>
                  <!--<a href="<?php // print $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['HTTP_HOST'].'/'.$variables['url']['path'];      ?>"> <?php // print_r($variables['url']['options']['entity']->title);      ?></a>-->
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
//                print_r($variables['item']->field_cm_person_photo['und'][0]['uri']);die;
                if (isset($variables['item']->field_cm_person_photo['und'][0]['uri'])) {
                    if ($variables['item']->field_cm_person_photo['und'][0]['uri'] != "") {
                        $image_path = file_create_url($variables['item']->field_cm_person_photo['und'][0]['uri']);
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
                  <!--<a href="<?php // print $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['HTTP_HOST'].'/'.$variables['url']['path'];      ?>"> <?php // print_r($variables['url']['options']['entity']->title);      ?></a>-->
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

