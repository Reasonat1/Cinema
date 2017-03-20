<div class="browser-wrapper">
  <div class="filters">
    <?php print render($filters['select_page']); ?>
    <?php print render($filters['title_search']); ?>
    <div class="date-range">
      <?php print render($filters['date_range']); ?>
    </div>
    <button> <?php print t('Update'); ?> </button> 
  </div>

  <div class="browser-results">
  <?php foreach ($items as $item_id => $item) : ?>
    <h3 data-item-id="<?php print $item_id;?>"> <?php print check_plain($item['title']); ?> </h3>
    <?php if (!empty($item['options'])) : ?>
      <div class="item-options"> <?php print $item['options']; ?> </div>
    <?php endif; ?>
  <?php endforeach; ?>
  </div>
</div>
