<?php
$handle = fopen('form_data.txt', 'w');
if (!$handle) {
  exit();
}
if (!isset($_POST)) {
  $_POST = array();
}
$_POST['mydata'] = 34;
fprintf($handle, print_r($_POST, TRUE));
