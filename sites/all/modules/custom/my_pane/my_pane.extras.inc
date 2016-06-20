<?php

function ajax_my_pane_nodes_oftype_autocomplete_callback($type,$string = "") {
  $matches = array();
  if ($string) {
    $result = db_select('node')
      ->fields('node', array('title', 'type', 'nid'))
      ->condition('title', db_like($string) . '%', 'LIKE')
      ->range(0, 10)
      ->execute();
    foreach ($result as $node) {
      // In the simplest case (see user_autocomplete), the key and the value are
      // the same. Here we'll display the uid along with the username in the
      // dropdown.
      $matches[$node->nid] = check_plain($node->title) . " [$node->type : $node->nid]";
    }
  }

  drupal_json_output($matches);
}