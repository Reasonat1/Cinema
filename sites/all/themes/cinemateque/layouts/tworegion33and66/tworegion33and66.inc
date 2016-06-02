<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Custom 2 regions 33.3% and 66.6 %'),
  'category' => t('custom minipanal layout'),
  'icon' => 'tworegion33and66.png',
  'theme' => 'tworegion33and66',
  'css' => 'tworegion33and66.css',
  'regions' =>  array(
    'left' => t('Left side'),
    'right' => t('Right side'),
  ),
);
