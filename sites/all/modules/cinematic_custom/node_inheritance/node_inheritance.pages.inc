<?php

function node_inheritance_edit($form, &$form_state, $node) {
  $form_state['node_inheritance_parent'] = $node;
  $fields = field_info_instances('node', $node->type);

  unset($fields['field_node_inheritance']);
  $options = array();
  foreach ($fields as $name => $info) {
    $options[$name] = $info['label'];
  }
  $form['field_selection'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Field selection'),
    '#description' => t('Choose which fields to override'),
    '#options' => $options,
  );

  $form['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add child'),
  );

  node_inheritance_list($form, $node);
  return $form;
}

function node_inheritance_edit_submit($form, &$form_state) {
  $selection = array();
  $selection['inheritance'] = array();
  $selection['override'] = array();
  foreach ($form_state['values']['field_selection'] as $name => $checked) {
    if ($checked) {
      $selection['override'][$name] = 1;
    }
    else {
      $selection['inheritance'][$name] = 1;
    }
  }
  $parent = $form_state['node_inheritance_parent'];
  $record = array(
    'field_selection' => $selection,
    'parent' => $parent->nid,
  );
  drupal_write_record('node_inheritance', $record);
  $type_url = str_replace('_', '-', $parent->type);
  $form_state['redirect'] = array(
    'node/add/' . $type_url,
    array(
      'query' => array('node_inheritance_config' => $record['id']),
    ),
  );
}

function node_inheritance_list(&$form, $parent) {
  $query = db_select('node_inheritance', 'ni');
  $query->condition('parent', $parent->nid);
  $query->fields('ni');
  $records = $query->execute()->fetchAll();
  if (!$records) {
    return;
  }
  $items = array();
  foreach ($records as $config) {
    $items[] = l('node/' . $config->child, 'node/' . $config->child);
  }
  $form['list'] = array(
    '#theme' => 'item_list',
    '#items' => $items
  );
}
