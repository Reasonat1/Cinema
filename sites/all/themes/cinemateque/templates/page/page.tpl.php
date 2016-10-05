<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>

<!--<script src="/misc/jquery.js" type="text/javascript"></script>-->
<?php print render($page['overlay']); ?>
<script type='text/javascript'>
    jQuery.noConflict();
</script> 
<div class="responsive-menu-wrapper">
    <ul id="site-main-menu" class="site-custom-menu menu nav navbar-nav col-md-4">
        <?php print render($site_main_menu); ?>
    </ul>
</div>
<header id="header" class="header" role="header">
    <div class="container-fluid">
        <nav class="navbar navbar-default" role="navigation">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header">
                <!-- Trigger the modal with a button -->
                <button  class="hambruger -menu navbar-toggle">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <?php
                if (!empty($festival_site_logo)) {
                    $logo = $festival_site_logo;
                }
				if ($site_name || $logo): ?>
                    <a href="<?php print $front_page; ?>" class="navbar-brand" rel="home" title="<?php print t('Home'); ?>">
                        <?php if ($logo): ?>
                            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" id="logo" />
                        <?php endif; ?>
                        <?php if ($site_name && $GLOBALS['_domain']['domain_id'] == 1 ): ?>
                            <span class="site-name"><?php print $site_name; ?></span>
                        <?php endif; ?>
                    </a>
                <?php endif; ?>
                <?php
                if ($festival_site_info):
                    print $festival_site_info;
                endif;
                ?>
                <div class="responsive-hamburger hambruger">
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </div>
            </div> <!-- /.navbar-header -->
            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="navbar-collapse">
                <?php
                if (!empty($festival_site_info)) {
                    $main_menu = $festival_site_menu;
                }
				if ($main_menu): ?>
                    <ul id="main-menu" class="site-custom-menu menu nav navbar-nav col-md-4">
                        <?php print render($main_menu); ?>
                    </ul>
                    <ul class="col-md-3 header-right">
                        <li class="search">
                            <span></span>
                        </li>
                        <?php 
                            global $user;
                            if ($user->uid > 0){ ?>
                            <li class="favorite">
                                <a href="/user/<?php print $user->uid ?>">favorite</a>
                            </li>
                        <?php  } ?>
                    <?php endif; ?>
                    <?php if ($search_form): ?>
                        <?php
                        //$block = module_invoke('block', 'block_view', '5');
                        $block = module_invoke('cm_extra', 'block_view', 'icons');
                        print render($block['content']); //print $search_form; 
                        ?>

                    </ul>
                    <?php
                    $block2 = module_invoke('locale', 'block_view', 'language'); 
                    ?>
                <?php endif; ?>
            </div><!-- /.navbar-collapse -->
        </nav><!-- /.navbar -->
    </div> <!-- /.container -->
</header>

<?php if ($is_front): ?>
    <?php print render($page['featured']); ?>
<?php endif; ?>
<div id="main-wrapper">
    <div id="main" class="main">
        <div class="container">
         <!--   <?php if ($breadcrumb): ?>
                <div id="breadcrumb" class="visible-desktop">
                    <?php print $breadcrumb; ?>
                </div>
            <?php endif; ?> -->
            <?php if ($messages): ?>
                <div id="messages">
                    <?php print $messages; ?>
                </div>
            <?php endif; ?>
            <div id="page-header">        <?php if ($title): ?>

                    <div class="page-header">
                        <h1 class="title"><?php print $title; ?></h1>
                    </div>
                <?php endif; ?>
                <?php if ($tabs): ?>
                    <div class="tabs">
                        <?php print render($tabs); ?>
                    </div>
                <?php endif; ?>
                <?php if ($action_links): ?>
                    <ul class="action-links">
                        <?php print render($action_links); ?>
                    </ul>
                <?php endif; ?>
            </div>
        </div>

        <div id="content" class="container">

            <div class="search_new"> <div style="clear:both"> </div><?php print render($page['featured']); ?> </div>

            <?php print render($page['content']); ?>
        </div>
    </div> <!-- /#main -->
</div> <!-- /#main-wrapper -->

<footer id="footer" class="footer" role="footer">
    <div class="container-fluid">
        <div class="row">
            <?php print render($page['footer1']); ?>
            <?php print render($page['footer2']); ?>
        </div>
    </div>
    <?php if (0): ?>
        <div class="container">
            <?php if ($copyright): ?>
                <small class="copyright pull-left"><?php print $copyright; ?></small>
            <?php endif; ?>
            <small class="pull-right"><a href="#"><?php print t('Back to Top'); ?></a></small>
        </div>
    <?php endif; ?>
</footer>