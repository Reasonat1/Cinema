<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Custom 1 regions fullwidth'),
  'category' => t('custom minipanal layout'),
  'icon' => 'onecolfullwidth.png',
  'theme' => 'onecolfullwidth',
  'css' => 'onecolfullwidth.css',
  'regions' => array('middle' => t('Middle column')),
);
