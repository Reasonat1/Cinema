<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" version="XHTML+RDFa 1.0" dir="ltr"
  xmlns:esro="toptix.com">

<head profile="http://www.w3.org/1999/xhtml/vocab">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title> example page </title>
  <script type="text/javascript" src="http://jer-cin.reasonat.com/profiles/panopoly/modules/contrib/jquery_update/replace/jquery/1.8/jquery.min.js?v=1.8.3"></script>
<script type="text/javascript" src="http://jer-cin.reasonat.com/misc/jquery.once.js?v=1.2"></script>
<script type="text/javascript" src="http://tickets.jer-cin.org.il/iframe/esrojsapi.js"></script>
<script type="text/javascript" src="http://jer-cin.reasonat.com/example_esro.js"></script>
</head>
<body>
  <div>
    <esro:frame href="http://tickets.jer-cin.org.il/integrationsample/info.htm" width="800" height="100" />
  </div>
  <form enctype="multipart/form-data" action="/example_esro.php" method="post" accept-charset="UTF-8">
    <?php
      $incr = 0;
      $error = '';
      if (isset($_POST) and isset($_POST['incr'])) {
        $incr = $_POST['incr'] + 1;
        $error = $_POST['error'];
      }
    ?>
    <label> incr: <input type="text" value="<?php print $incr;?>" name="incr"/> </label>
    <br>
    <label> error: <input type="text" value="<?php print $error;?>" name="error"/> </label>
    <br>
    <input type="submit" id="edit-submit" name="op" value="Increment" class="form-submit" />
    <a href="/example_esro.php"> reset </a>
  </form>
</body>
</html>
