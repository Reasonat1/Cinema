<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Custom 3 regions 33.3%'),
  'category' => t('custom minipanal layout'),
  'icon' => 'threeregion33.3.png',
  'theme' => 'threeregion33.3',
  'css' => 'threeregion33.3.css',
  'regions' =>  array(
    'left' => t('Left side'),
    'middel' => t('Middel'),    
    'right' => t('Right side'),
  ),
);
