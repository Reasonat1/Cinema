<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Custom 2 regions 66.6% and 33.3 %'),
  'category' => t('custom minipanal layout'),
  'icon' => 'tworegion66and33.png',
  'theme' => 'tworegion66and33',
  'css' => 'tworegion66and33.css',
  'regions' =>  array(
    'left' => t('Left side'),
    'right' => t('Right side'),
  ),
);
