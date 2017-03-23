<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" version="XHTML+RDFa 1.0" dir="ltr"
  xmlns:esro="toptix.com">

<head profile="http://www.w3.org/1999/xhtml/vocab">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title> example page </title>
<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/jquery/1.8/jquery.min.js?v=1.8.3"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/misc/jquery.once.js?v=1.2"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/ui/minified/jquery.ui.core.min.js?v=1.10.2"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/ui/minified/jquery.ui.widget.min.js?v=1.10.2"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/ui/minified/jquery.ui.tabs.min.js?v=1.10.2"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/external/jquery.cookie.js?v=67fb34f6a866c40d0570"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/ui/minified/jquery.ui.button.min.js?v=1.10.2"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/ui/minified/jquery.ui.dialog.min.js?v=1.10.2"></script>

<script type="text/javascript" src="http://tickets.jer-cin.org.il/iframe/esrojsapi.js"></script>

<script type="text/javascript" src="http://jer-cin.reasonat.com/esro/event.js"></script>
<style>
  #toptix-frame-wrapper {
    display:none;
  }
  body {
    width: 1024px;
    height: 768px;
  }
</style>
<style type="text/css" media="all">
@import url("http://jer-cin.reasonat.com/profiles/panopoly/modules/panopoly/panopoly_core/css/panopoly-jquery-ui-theme.css?om504h");
@import url("http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/ui/themes/base/minified/jquery.ui.accordion.min.css?om504h");
</style>
</head>
<body>
  <?php 
    $base_url = 'http://tickets.jer-cin.org.il/loader.aspx';
    $url = $base_url . '?target=hall.aspx?event=23027&culture=en-US';
  ?>
  <button class="purchase" data-url="<?php print $url;?>"> Purchase </button>
  <?php 
    $url = $base_url . '/Order.aspx'; //?culture=en-US
  ?>
  <button class="basket" data-url="<?php print $url;?>"> Basket </button>
  <div id="toptix-frame-wrapper">
    <esro:frame href="http://tickets.jer-cin.org.il/integrationsample/info.htm" width="1024" height="768" />
  </div>
</body>
</html>
