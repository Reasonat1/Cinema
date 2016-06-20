<?php

$plugin = array(
    'single' => TRUE,
    'title' => t('Add Information Block View'),
    'description' => t('Display of view pane'),
    'category' => t('Information Block View'),
    'edit form' => 'information_block_pane_info_block_content_form',
    'render callback' => 'information_block_pane_info_block_content_form_render',
    'admin info' => 'information_block_pane_info_block_content_form_info',
    'defaults' => array(),
    'all contexts' => TRUE,
);

/**
 * Edit form.
 */
function information_block_pane_info_block_content_form($form, &$form_state) {
    $conf = $form_state['conf'];

    $vocabulary = taxonomy_vocabulary_machine_name_load('information_blocks');
    $terms = taxonomy_get_tree($vocabulary->vid);

    $option = array();
     $option = array('0' => '-select-');
    foreach ($terms as $val) {
        $option[$val->tid] = $val->name;
    }
    $type = array('0' => '-select-');
    $form['#prefix'] = '<fieldset id="edit-node-teaser" class="form-wrapper">
                                     <legend><span class="fieldset-legend"><a href="#" class="fieldset-title">Information  Block View Setting</a><span class="summary"></span></span></legend>
                                     <div class="fieldset-wrapper">';

    $form['term'] = array(
        '#type' => 'select',
        '#title' => t('Select Information Block Type'),
        '#options' => $option,
        '#default_value' => $conf['term'],
    );
    
  $form['default_term'] = array(
        '#type' => 'hidden',
        '#title' => '',
       '#default_value' => $conf['default_term'],
       '#attributes' => array('class' => array('default_term')),
    );
        
    $form['block_type'] = array(
        '#type' => 'select',
        '#title' => t('Select Information Block'),
       '#description' => 'choose max 4 block as per desgin',
        '#options' => $type,
        '#default_value' => $conf['term'],
        '#multiple' => TRUE,
        '#validated' => TRUE,
        '#suffix' => '<div id="preview" class="form-wrapper"></div>',
    );

    $form['#suffix'] = '</div></fieldset>';
    return $form;
}

/**
 * Edit form submit function.
 */
function information_block_pane_info_block_content_form_submit($form, &$form_state) {
    $form_state['conf']['term'] = $form_state['values']['term'];
    $form_state['conf']['default_term'] = $form_state['values']['default_term'];
    $form_state['conf']['block_type'] = $form_state['values']['block_type'];    
}

/**
 * Render the panel.
 */
function information_block_pane_info_block_content_form_render($subtype, $conf, $args, $context) {
    if (!empty($context)) {
        if ($context->empty) {
            return;
        }
    }

    global $base_url;
    $content_type = $conf['term'];
    // Render as a block.
    $block = new stdClass();
    $block->module = 'information_block_pane';
    $block->delta = 'bean-type-teaser' . str_replace('-', '_', $conf['term']);
    $bid = isset($conf['default_term']) ? $conf['default_term']: array();
    $output = '';

    $bid = explode(',',$bid);
    foreach ($bid as $val) {
        $block = bean_load($val);
        $icon = isset($block->field_cm_info_block_icon['und'][0]['icon']) ? $block->field_cm_info_block_icon['und'][0]['icon'] : '';
        $body = isset($block->field_cm_info_block_text['und'][0]['value']) ? $block->field_cm_info_block_text['und'][0]['value'] : '';
        $output.="<div class='bean-block'>";
        $output.="<div class='bean-icon'><i aria-hidden='true' class='fa fa-$icon'></i></div>";
        $output.="<div class='bean-title'>$block->label</div>";
        $output.="<div class='bean-body'>$body</div>";
        $output.='</div>';
    }
   
    $block->content = $output;
    return $block;
}

/**
 * Admin info.
 */
function information_block_pane_info_block_content_form_info($subtype, $conf, $contexts) {
    if (!empty($conf)) {
        // return information_block_pane_info_block_content_form_render($subtype, $conf, $args = null, $context = null);
    }
}
