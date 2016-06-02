<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Custom 2 regions 50% and 50%'),
  'category' => t('custom minipanal layout'),
  'icon' => 'tworegion50and50.png',
  'theme' => 'tworegion50and50',
  'css' => 'tworegion50and50.css',
  'regions' =>  array(
    'left' => t('Left side'),
    'right' => t('Right side'),
  ),
);
