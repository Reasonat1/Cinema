<?php
/**
 * @file
 * Default theme implementation for displaying search results.
 *
 * This template collects each invocation of theme_search_result(). This and the
 * child template are dependent on one another, sharing the markup for
 * definition lists.
 *
 * Note that modules and themes may implement their own search type and theme
 * function completely bypassing this template.
 *
 * Available variables:
 * - $index: The search index this search is based on.
 * - $result_count: Number of results.
 * - $spellcheck: Possible spelling suggestions from Search spellcheck module.
 * - $search_results: All results rendered as list items in a single HTML
 *   string.
 * - $items: All results as it is rendered through search-result.tpl.php.
 * - $search_performance: The number of results and how long the query took.
 * - $sec: The number of seconds it took to run the query.
 * - $pager: Row of control buttons for navigating between pages of results.
 * - $keys: The keywords of the executed search.
 * - $classes: String of CSS classes for search results.
 * - $page: The current Search API Page object.
 * - $no_results_help: Help text to display under the header if no results were
 *   found.
 *
 * View mode is set in the Search page settings. If you select
 * "Themed as search results", then the child template will be used for
 * theming the individual result. Any other view mode will bypass the
 * child template.
 *
 * @see template_preprocess_search_api_page_results()
 */
//echo '<pre>';
//$uri="public://pages/koala.jpg";
//echo file_create_url($uri);
//print_r($search_results);die;
drupal_add_js(drupal_get_path('module', 'cinematic_toptix') . '/frame.js');
?>
<div id="RemoveFilters">

</div>
<div class="<?php print $classes; ?> search_result">
    <?php if ($result_count): ?>
        <?php print render($search_performance); ?>
    <?php endif; ?>
    <?php print render($spellcheck); ?>
    <?php if ($result_count): ?>
                                <!--<h2><?php // print t('Search results');     ?></h2>-->
        <?php print render($pager); ?>
        <ol class="search-results">
            <?php print render($search_results); ?>
        </ol>
        <?php print render($pager); ?>
    <?php else : ?>
        <h2><?php print t('Your search yielded no results.'); ?></h2>
        <?php print $no_results_help; ?>
    <?php endif; ?>
</div>
<style>
    #RemoveFilters{
        clear:both;
        text-align: center;
        margin-bottom: 15px;
    }
    #RemoveFilters a::after {
        content: ' x ';
        clear: both;
        margin-left: 10px !important;
    }


    #RemoveFilters a {
        border-bottom: 1px solid #777;
        padding-bottom: 5px;
        color: #777;margin: 0 10px;
    }

    #RemoveFilters a:hover{
        color: #e41145 !important;
        border-bottom: 1px solid #e41145 !important;
    }
</style>