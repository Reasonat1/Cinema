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
  <?php foreach ($shows as $show_id => $show) : ?>
    <h3 data-show-id="<?php print $show_id;?>"> <?php print check_plain($show['title']); ?> </h3>
    <div class="events"> <?php print $show['events']; ?> </div>
  <?php endforeach; ?>
  </div>
</div>
