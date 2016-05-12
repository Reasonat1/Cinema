<?php
/* -----add css and js in drupal------ */
drupal_add_css('https://maxcdn.bootstrapcdn.com/font-awesome/4.6.1/css/font-awesome.min.css', 'external');
drupal_add_css(path_to_theme() . '/css/bootstrap.min.css');
/* -- jQuery library -- */
drupal_add_js(path_to_theme() . '/js/jquery.min.js');
drupal_add_js(path_to_theme() . '/js/bootstrap.min.js');

/* --------base path ------- */
$my_static_banner = path_to_theme();
?>

<div class="header top_menu container-fluid">
     <!-------/// LOGO PART ---->
    <div class="col-sm-4">
        <img src="<?php print $my_static_banner .'/images/top_logo.png'?>" />
    </div>
    <!-------/// LOGO PART END HERE --->
    <?php if ($main_menu): ?>
              <div class="col-sm-8 top_menu">
                    <div class="col-sm-6 inner_menu">
                    <?php
                    print theme('links__system_main_menu', array(
                        'links' => $main_menu,
                        'attributes' => array(
                            'id' => 'main-menu-links',
                            'class' => array('links', 'col-sm-4'),
                        ),
                        'heading' => array(
                            'text' => t('Main menu'),
                            'level' => 'h2',
                            'class' => array('element-invisible'),
                        ),
                    ));
                    ?>
                </div> <!-- /#main-menu -->
            <?php endif; ?>
         
        <!---------/// LEFT PART END  HERE --->
        <!-------///  RIGHT PART ---->
        <div class="col-sm-6 top_menu_left_part">
           <ul>
               <li><a href="#"><img src="<?php print $my_static_banner .'/images/search_icon.png'?>" /></a></li>
               <li><a href="#"><img src="<?php print $my_static_banner .'/images/user_icon.png'?>" /></a></li>
               <li><a href="#"><img src="<?php print $my_static_banner .'/images/buy_icon.png'?>"/></a></li>
               <li><a href="#"><img src="<?php print $my_static_banner.'/images/help_icon.png'?>" /></a></li>
               <li><a href="#"><img src="<?php print $my_static_banner.'/images/e-icon.png'?>" /></a></li>
               
           
           </ul>
        
        </div>
        <!----------//// RIGHT PART END HERE ---->
    </div>
     
</div>
<!--------/// IMAGE SILDER START ---->
<div class="container-fluid silder_main">
<!-----------/// INNER SILDER ---->
<div id="myCarousel" class="carousel slide" data-ride="carousel">
  <!-- Indicators -->
  <ol class="carousel-indicators">
    <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
    <li data-target="#myCarousel" data-slide-to="1"></li>
  </ol>

  <!-- Wrapper for slides -->
  <div class="carousel-inner" role="listbox">
    <div class="item active">
      <img src="<?php print $my_static_banner.'/images/img_chania.jpg'?>" alt="Chania">
    </div>

     </div>

  <!-- Left and right controls -->
  <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>


<!---------/// INNER SILDER END HERE ---->





</div>
<!----------/// IMAGE SILDER END HERE --->

<!---------//// SILDER BOTTOM  TEST START ---->
<div class="container-fluid silder_bottom">
   <div class="container">
        <!----------/// LEFT PART ---->
         <div class="col-sm-7 left_silder_bottom">
              <div class="col-sm-3">LoremIpsum</div>
              <div class="col-sm-3">LoremIpsum</div>
              <div class="col-sm-3">LoremIpsum</div>
              <div class="col-sm-3">LoremIpsum</div>
           
         
         </div>
        <!---------/// LEFT PART END HERE --->
        <!--------/// RIGHT PART --->
         <div class="col-sm-5 right_silder_bottom">
              <div class="col-sm-4">Lorem Ipsum</div>
              <div class="col-sm-3 border_radius_maain">Lorem</div>
              <i class="fa fa-calendar-plus-o gray_new_bg" aria-hidden="true"></i>
              <i class="fa fa-heart-o gray_new_bg" aria-hidden="true"></i>
           
         </div>
        <!-------/// RIGHT PART END --->
        
    
   
   </div>

</div>
<!---------/// INNER CONTENT ---->
<div class="container inner_text_main">
    <p class="col-sm-6 mid_comtent_main">
    It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. 

</p>
<h1>Lorem Ipsum </h1>
<div class="table-responsive">
<table class="table ">
    <thead>
      <tr class="this_font-size">
        <th>Firstname</th>
        <th>Lastname</th>
        <th>Email</th>
        <th>Firstname</th>
        <th>Lastname</th>
        <th>Email</th>
      </tr>
    </thead>
    <tbody>
      <tr class="font_size_table_cont">
        <td>John</td>
        <td>Doe</td>
        <td>john@example.com</td>
        <td>John</td>
        <td>Doe</td>
        <td>
              <div class="col-sm-3 border_radius_maain1">Lorem</div>
              <i class="fa fa-calendar-plus-o gray_new_bg" aria-hidden="true"></i>
              <i class="fa fa-heart-o gray_new_bg" aria-hidden="true"></i></td>
      </tr>
      <tr class="font_size_table_cont">
        <td>Mary</td>
        <td>Moe</td>
        <td>mary@example.com</td>
        <td>John</td>
        <td>Doe</td>
        <td >
              <div class="col-sm-3 border_radius_maain1">Lorem</div>
              <i class="fa fa-calendar-plus-o gray_new_bg" aria-hidden="true"></i>
              <i class="fa fa-heart-o gray_new_bg" aria-hidden="true"></i></td>
      </tr>
      <tr class="font_size_table_cont">
        <td>July</td>
        <td>Dooley</td>
        <td>july@example.com</td>
        <td>John</td>
        <td>Doe</td>
        <td>
              <div class="col-sm-3 border_radius_maain1">Lorem</div>
              <i class="fa fa-calendar-plus-o gray_new_bg" aria-hidden="true"></i>
              <i class="fa fa-heart-o gray_new_bg" aria-hidden="true"></i></td>
      </tr>
      
    </tbody>
      
  </table>

</div>
<div class="row">
<div class="left">
     <?php if ($page['left']): ?>    
            <?php  print render($page['left']); ?>
        <?php endif; ?>
</div>
    
<div class="content">
     
    <?php if ($page['content']):?>    
            <?php  print render($page['content']); ?>
            
    <?php endif; ?>
    
</div>
</div>
<div class="triptych_first">
    <?php if ($page['triptych_first']): ?>    
            <?php  print render($page['triptych_first']); ?>
        <?php endif; ?>
</div>
<div class="footer_secondcolumn">
    <?php if ($page['footer_secondcolumn']): ?>    
            <?php  print render($page['footer_secondcolumn']); ?>
        <?php endif; ?>
</div>
<!------Footer----->
<div class="footer_first">
     <?php if ($page['footer_first']): ?>    
            <?php  print render($page['footer_first']); ?>
        <?php endif; ?>
</div>
<div class="footer">
        <?php if ($page['footer']): ?>    
            <?php  print render($page['footer']); ?>
        <?php endif; ?>
</div>

