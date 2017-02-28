<?php
/**
 * @file
 *   Class definition for views matrix plugin.
 */

/**
 * @class
 *   Views Plugin Class
 */
class views_matrix_plugin_style_matrix extends views_plugin_style {

  /**
   * The row weights for click sorting.
   *
   * Maps y field values to their respective "weights" (i.e., values according
   * to which the sorting should be performed).
   *
   * Set externally to get this configuration into
   * views_matrix_plugin_style_matrix::compareRows().
   *
   * @var array
   */
  public $sort_weights = array();

  /**
   * Whether row (click) sorting should be done ascending or descending.
   *
   * Set externally to get this configuration into
   * views_matrix_plugin_style_matrix::compareRows().
   *
   * @var bool
   */
  public $sort_asc;

  public function option_definition() {
    $options = parent::option_definition();

    $options['sticky'] = array('default' => FALSE);
    $options['xconfig'] = array('default' => array(
      'field' => '',
      'sort' => '',
      'class' => '',
    ));
    $options['yconfig'] = array('default' => array(
      'field' => '',
      'sort' => '',
      'class' => '',
    ));
    $options['sortable_headers'] = array('default' => FALSE, 'bool' => TRUE);
    $options['header_init_sort'] = array('default' => 'asc');
    $options['hide_empty_columns'] = array('default' => FALSE, 'bool' => TRUE);
    $options['hide_empty_rows'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['sticky'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable Drupal style "sticky" table headers (Javascript)'),
      '#default_value' => !empty($this->options['sticky']),
      '#description' => t('The sticky header function only applies to column headers.'),
    );

    $field_options = $this->display->handler->get_field_labels(TRUE);

    $form['xconfig'] = array(
      '#type' => 'fieldset',
      '#title' => t('Column header'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    $form['xconfig']['field'] = array(
      '#type' => 'select',
      '#title' => t('Field'),
      '#description' => t('Select the field to display in the column header.'),
      '#options' => $field_options,
      '#default_value' => $this->options['xconfig']['field'],
    );

    $form['xconfig']['sort'] = array(
      '#type' => 'select',
      '#title' => t('Sort'),
      '#description' => t('Select the method to sort the field by.'),
      '#options' => array('asc' => t('Ascending'), 'dsc' => t('Descending')),
      '#default_value' => $this->options['xconfig']['sort'],
    );

    $form['xconfig']['class'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class'),
      '#description' => t('You may use token substitutions from the rewriting section in this class.'),
      '#default_value' => $this->options['xconfig']['class']
    );

    $form['yconfig'] = array(
      '#type' => 'fieldset',
      '#title' => t('Row header'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    $form['yconfig']['field'] = array(
      '#type' => 'select',
      '#title' => t('Field'),
      '#description' => t('Select the field to display in the row header.'),
      '#options' => $field_options,
      '#default_value' => $this->options['yconfig']['field'],
    );

    $form['yconfig']['sort'] = array(
      '#type' => 'select',
      '#title' => t('Sort'),
      '#description' => t('Select the method to sort the field by.'),
      '#options' => array('asc' => t('Ascending'), 'dsc' => t('Descending')),
      '#default_value' => $this->options['yconfig']['sort'],
    );

    $form['yconfig']['class'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class'),
      '#description' => t('You may use token substitutions from the rewriting section in this class.'),
      '#default_value' => $this->options['yconfig']['class']
    );

    $form['sortable_headers'] = array(
      '#type' => 'checkbox',
      '#title' => t('Make column headers sort links'),
      '#description' => t('Emulates the same behavior for the column headers as in an ordinary table. Only makes sense if there will be exactly one result and field value per cell.'),
      '#default_value' => !empty($this->options['sortable_headers']),
    );

    $form['header_init_sort'] = array(
      '#type' => 'select',
      '#title' => t('Inital sorting direction'),
      '#description' => t('Direction of the initial sort when a header is clicked for the first time.'),
      '#options' => array('asc' => t('Ascending'), 'desc' => t('Descending')),
      '#default_value' => isset($this->options['header_init_sort']) ? $this->options['header_init_sort'] : 'asc',
      '#dependency' => array(
        'edit-style-options-sortable-headers' => array(1),
      ),
    );

    $form['hide_empty_columns'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide empty columns'),
      '#description' => t('A column will be empty when "hide with empty" is checked for fields that are displayed and there are no results with data.'),
      '#default_value' => $this->options['hide_empty_columns'],
    );

    $form['hide_empty_rows'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide empty rows'),
      '#description' => t('A row will be empty when "hide with empty" is checked for fields that are displayed and there are no results with data.'),
      '#default_value' => $this->options['hide_empty_rows'],
    );
  }

  /**
   * Validate row and colum header configuration set. This is only used during
   * runtime. parent::validate() cannot be used because it breaks the Views
   * UI.
   */
  public function canRender() {

    $errors = parent::validate();

    if (empty($this->options['xconfig']['field']) || empty($this->options['yconfig']['field'])) {
      // Do not save without x field or y field.
      $errors[] = t('Style @style requires an x and y field to be defined.', array('@style' => $this->definition['title']));
    }
    else {
      // Check if fields exist still.
      $options = $this->display->handler->get_field_labels(TRUE);

      if (!isset($options[$this->options['xconfig']['field']]) || !isset($options[$this->options['yconfig']['field']])) {
        $errors[] = t('An x or y field is defined, but not does not exist.');
      }
    }

    return $errors;
  }

  /**
   * Return the class of the field headers.
   */
  function headerClasses($dimension, $row_index = NULL) {
    $field_handler = @$this->view->field[$this->options["{$dimension}config"]['field']];
    if (empty($field_handler)) return array();
    $classes = explode(' ', $this->options["{$dimension}config"]['class']);
    foreach ($classes as &$class) {
      $class = $field_handler->tokenize_value($class, $row_index);
      $class = views_clean_css_identifier($class);
    }
    return $classes !== FALSE ? $classes : array();
  }

  /**
   * Compares two matrix rows, according to the active click sort.
   *
   * @param mixed $a
   *   The first row's y value.
   * @param mixed $b
   *   The second row's y value.
   *
   * @return int
   *   An integer less than, equal to or greater than 0, if $a should be ordered
   *   before, equally to or after $b, respectively.
   */
  public function compareRows($a, $b) {
    $a = isset($this->sort_weights[$a]) ? "{$this->sort_weights[$a]}" : '';
    $b = isset($this->sort_weights[$b]) ? "{$this->sort_weights[$b]}" : '';
    $ret = strnatcmp($a, $b);
    return $this->sort_asc ? $ret : -$ret;
  }
}
