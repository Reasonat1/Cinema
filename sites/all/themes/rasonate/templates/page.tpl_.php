
<!------------/// TOP MENU START HERE ------->
<div class="top_menu container-fluid">
    <!-------/// LOGO PART ---->
    <div class="col-sm-4">
        <a href="<?php print $front_page; ?>" class="navbar-brand" rel="home" title="<?php print t('Home'); ?>">
            <?php if ($logo): ?>
                <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" id="logo" />
            <?php endif; ?>
            <?php if ($site_name): ?>
                <span class="site-name"></span>
            <?php endif; ?>
        </a>
    </div>
    <!-------/// LOGO PART END HERE --->
    <!-------//// MENU START ---->
    <div class="col-sm-8 top_menu">
        <!--------/// LEFT  PART --->
        <div class="col-sm-6 inner_menu">
            <?php print theme('links__system_main_menu', array('links' => $main_menu)); ?>
        </div>
        <!---------/// LEFT PART END  HERE --->
        <!-------///  RIGHT PART ---->
        <div class="col-sm-6 top_menu_left_part">
            <ul>
                <li><a href="#"><img src="<?php print path_to_theme();?>/images/search_icon.png" /></a></li>
                <li><a href="#"><img src="<?php print path_to_theme();?>/images/user_icon.png" /></a></li>
                <li><a href="#"><img src="<?php print path_to_theme();?>/images/buy_icon.png" /></a></li>
                <li><a href="#"><img src="<?php print path_to_theme();?>/images/help_icon.png" /></a></li>
                <li><a href="#"><img src="<?php print path_to_theme();?>/images/e-icon.png" /></a></li>
            </ul>
        </div>
        <!----------//// RIGHT PART END HERE ---->
    </div>

    <!---------/// MENU END HERE =---->

</div>

<!-------/// TOP MENU END HEREE ----->
<!--------/// IMAGE SILDER START ---->
<div class="container-fluid silder_main">
    <!-----------/// INNER SILDER ---->
    <?php if($page['nivo_slideshow']){
        print render($page['nivo_slideshow']);
    } ?>

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
            <div class="col-sm-4">Lorem</div>
            <div class="col-sm-3 border_radius_maain">Lorem</div>
            <i class="fa fa-calendar-plus-o gray_new_bg" aria-hidden="true"></i>
            <i class="fa fa-heart-o gray_new_bg" aria-hidden="true"></i>

        </div>
        <!-------/// RIGHT PART END --->



    </div>

</div>

<!-----/// SILDER END HERE ---->
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
        <p>example</p>
    </div>
    <!----------//// TABLE INNER CONTENT ---->
    <div class="row nav_2015">
        <ul>
            <li>2015gr</li>
            <li>survived</li>
            <li>New</li>
            <li class="clear">come</li>
        </ul>
    </div>
    <div class="row">
        <!---------mid contant--------->

        <!-------/// LEFT PART ---->
        <div class="col-sm-2 font_size_bld">
            <ul>
                <li class="border_extra"><i class="fa fa-heart-o" aria-hidden="true"></i>survived</li>
                <li><i class="fa fa-facebook" aria-hidden="true"></i>survived</li>
                <li><i class="fa fa-whatsapp" aria-hidden="true"></i>survived</li>     
            </ul>
            <ul class="first_li_margin">
                <li class="border_extra">dummy text</li>
                <li>dummy text</li>
                <li>dummy text</li>
                <li>dummy text</li>
                <li>dummy text</li>
            </ul>
        </div>

        <!---- /// LEFT PART END HERE --->
        <!-------/// RIGHT PART START HERE --->
        <div class="col-sm-8">
            <h4>What is Lorem Ipsum?</h4>
            Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


        </div>
        <!---------/// RIGHT PART END HERE ---->

    </div>

    <!---------//// TABLE INNER CONTENT EN HERE ---->

</div>
<!----------/// INNER CONTENT END HERE --->

<!-------/// TESTIMONIAL  GY Background ---->
<div class="container-fluid gray_bg_tsetmonial">
    <!----------/// inner testIMONIAL start --->
    <section id="carousel">    				
        <div class="container">
            <div class="row">
                <div class="col-md-8 col-md-offset-2">
                    <div class="quote"><i class="fa fa-quote-left fa-4x"></i></div>
                    <div class="carousel slide" id="fade-quote-carousel" data-ride="carousel" data-interval="3000">
                        <!-- Carousel indicators -->
                        <ol class="carousel-indicators">
                            <li data-target="#fade-quote-carousel" data-slide-to="0"></li>
                            <li data-target="#fade-quote-carousel" data-slide-to="1"></li>
                            <li data-target="#fade-quote-carousel" data-slide-to="2" class="active"></li>
                            <li data-target="#fade-quote-carousel" data-slide-to="3"></li>
                            <li data-target="#fade-quote-carousel" data-slide-to="4"></li>
                            <li data-target="#fade-quote-carousel" data-slide-to="5"></li>
                        </ol>
                        <!-- Carousel items -->
                        <div class="carousel-inner">
                            <div class="item">
                                <div class="profile-circle" style="background-color: rgba(0,0,0,.2);"></div>
                                <blockquote>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quidem, veritatis nulla eum laudantium totam tempore optio doloremque laboriosam quas, quos eaque molestias odio aut eius animi. Impedit temporibus nisi accusamus.</p>
                                </blockquote>	
                            </div>
                            <div class="item">
                                <div class="profile-circle" style="background-color: rgba(77,5,51,.2);"></div>
                                <blockquote>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quidem, veritatis nulla eum laudantium totam tempore optio doloremque laboriosam quas, quos eaque molestias odio aut eius animi. Impedit temporibus nisi accusamus.</p>
                                </blockquote>
                            </div>
                            <div class="active item">
                                <div class="profile-circle" style="background-color: rgba(145,169,216,.2);"></div>
                                <blockquote>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quidem, veritatis nulla eum laudantium totam tempore optio doloremque laboriosam quas, quos eaque molestias odio aut eius animi. Impedit temporibus nisi accusamus.</p>
                                </blockquote>
                            </div>
                            <div class="item">
                                <div class="profile-circle" style="background-color: rgba(77,5,51,.2);"></div>
                                <blockquote>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quidem, veritatis nulla eum laudantium totam tempore optio doloremque laboriosam quas, quos eaque molestias odio aut eius animi. Impedit temporibus nisi accusamus.</p>
                                </blockquote>
                            </div>
                            <div class="item">
                                <div class="profile-circle" style="background-color: rgba(77,5,51,.2);"></div>
                                <blockquote>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quidem, veritatis nulla eum laudantium totam tempore optio doloremque laboriosam quas, quos eaque molestias odio aut eius animi. Impedit temporibus nisi accusamus.</p>
                                </blockquote>
                            </div>
                            <div class="item">
                                <div class="profile-circle" style="background-color: rgba(77,5,51,.2);"></div>
                                <blockquote>
                                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quidem, veritatis nulla eum laudantium totam tempore optio doloremque laboriosam quas, quos eaque molestias odio aut eius animi. Impedit temporibus nisi accusamus.</p>
                                </blockquote>
                            </div>
                        </div>
                    </div>
                </div>							
            </div>
        </div>
    </section>
    <!----------/// inner testiMONAIL END HERE ---->    

</div>

<!----------/// TESTIMONIAL  GY Background END ---->

<!-----------//// BOTTOM CONTENT ---->
<div class="container">
    <div class="col-sm-6 text_width_addjust">
        <div class="col-sm-5 text_style">
            <ul>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
            </ul> 
        </div>
        <div class="col-sm-7 font_size_bold">
            <ul>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
                <li>Lorem Ipsum</li>
            </ul> 

        </div>   
    </div>

</div>

<!---------//// BOTTOM CONTENT ENDHERE ---->
<!-------------/// SECOND TESTIMONIAL ---->
<div class="container second_testimonial">
    <div id="tcb-testimonial-carousel" class="carousel slide" data-ride="carousel">
        <!-- Indicators -->
        <ol class="carousel-indicators">
            <li data-target="#tcb-testimonial-carousel" data-slide-to="0" class="active"></li>
            <li data-target="#tcb-testimonial-carousel" data-slide-to="1"></li>
            <li data-target="#tcb-testimonial-carousel" data-slide-to="2"></li>
        </ol>
        <!-- Wrapper for slides -->
        <div class="carousel-inner">
            <div class="item active">
                <div class="row">
                    <div class="col-xs-12">
                        <figure class="clearfix">
                            <div class="col-md-2 col-sm-2 col-xs-12"><img class="img-responsive media-object" src="https://s3.amazonaws.com/uifaces/faces/twitter/mantia/128.jpg"> </div>
                            <div class="col-md-10 col-sm-10 col-xs-12">
                                <figcaption class="caption">
                                    <p class="text-brand lead no-margin">I can't wait to test this out.</p>
                                    <p><span class="glyphicon glyphicon-thumbs-up"></span> This is a testimonial window. Feedback of user can be displayed here.</p>
                                    <blockquote class="no-margin">
                                        <p>Someone Famous</p> <small><cite title="Source Title"><i class="glyphicon glyphicon-globe"></i> www.example1.com</cite></small> </blockquote>
                                </figcaption>
                            </div>
                        </figure>
                    </div>
                </div>
            </div>
            <div class="item">
                <div class="row">
                    <div class="col-xs-12">
                        <figure class="clearfix">
                            <div class="col-md-2 col-sm-2 col-xs-12"><img class="img-responsive media-object" src="https://s3.amazonaws.com/uifaces/faces/twitter/adhamdannaway/128.jpg"> </div>
                            <div class="col-md-10 col-sm-10 col-xs-12">
                                <figcaption class="caption">
                                    <p class="text-brand lead no-margin">I can't wait to test this out.</p>
                                    <p><span class="glyphicon glyphicon-thumbs-up"></span> This is a testimonial window. Feedback of user can be displayed here.</p>
                                    <blockquote class="no-margin">
                                        <p>Someone Famous</p> <small><cite title="Source Title"><i class="glyphicon glyphicon-globe"></i> www.example1.com</cite></small> </blockquote>
                                </figcaption>
                            </div>
                        </figure>
                    </div>
                </div>
            </div>
            <div class="item">
                <div class="row">
                    <div class="col-xs-12">
                        <figure class="clearfix">
                            <div class="col-md-2 col-sm-2 col-xs-12"><img class="img-responsive media-object" src="https://s3.amazonaws.com/uifaces/faces/twitter/brad_frost/128.jpg"> </div>
                            <div class="col-md-10 col-sm-10 col-xs-12">
                                <figcaption class="caption">
                                    <p class="text-brand lead no-margin">I can't wait to test this out.</p>
                                    <p><span class="glyphicon glyphicon-thumbs-up"></span> This is a testimonial window. Feedback of user can be displayed here.</p>
                                    <blockquote class="no-margin">
                                        <p>Someone Famous</p> <small><cite title="Source Title"><i class="glyphicon glyphicon-globe"></i> www.example1.com</cite></small> </blockquote>
                                </figcaption>
                            </div>
                        </figure>
                    </div>
                </div>
            </div>
        </div>
        <!-- Controls -->
        <a class="left carousel-control" href="#tcb-testimonial-carousel" data-slide="prev"> <span class="glyphicon glyphicon-chevron-left"></span> </a>
        <a class="right carousel-control" href="#tcb-testimonial-carousel" data-slide="next"> <span class="glyphicon glyphicon-chevron-right"></span> </a>
    </div>

</div>
<!------------SECOND TESTIMONIL END HERE ---->

<!---------------/// FOOTER FOUR BOX ---->
<div class="container-fluid footer_bottom_image">
    <div class="container">
        <!---------/// PART 1 --->
        <div class="col-sm-3">
            <img src="<?php print path_to_theme();?>/images/phone_icon.png" />
            <p> Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</p>

        </div>
        <!--------/// PART 1 END --->
        <!---------/// PART 1 --->
        <div class="col-sm-3">
            <img src="<?php print path_to_theme();?>/images/q-icon.png" />
            <p> Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</p>
        </div>
        <!--------/// PART 1 END --->
        <!---------/// PART 1 --->
        <div class="col-sm-3">
            <img src="<?php print path_to_theme();?>/images/icon-3.png" />
            <p> Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</p>
        </div>
        <!--------/// PART 1 END --->
        <!---------/// PART 1 --->
        <div class="col-sm-3">
            <img src="<?php print path_to_theme();?>/images/direction_icon.png" />
            <p> Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.</p>
        </div>
        <!--------/// PART 1 END --->


    </div>

</div>

<!----------/// FOOTER FOURE BOX END HERE ---->
<!----------/// FOOTER BOTTOM AGAIN ---->
<div class="container-fluid footer_second">

    <div class="col-sm-6 mid_comtent_main">
        <div class="col-sm-6">
            <img src="<?php print path_to_theme();?>/images/footer_icon.png" />
        </div>
        <div class="col-sm-6">
            <div class="col-sm-4">
                <img src="<?php print path_to_theme();?>/images/fb.jpg" />
            </div>
            <div class="col-sm-4">
                <img src="<?php print path_to_theme();?>/images/you_tube.jpg" />
            </div>
            <div class="col-sm-4">
                <img src="<?php print path_to_theme();?>/images/what_s_up.jpg"  />
            </div>

        </div>

    </div>

    <!----------//// MID FOOTER START ---->
    <div class="col-sm-9 mid_comtent_main">
        <div class="row">
            <div class="col-xs-3 footer_form_text">
                <h1>Lorem Ipsum </h1>
            </div>
            <div class="col-xs-2">
                <input type="text" class="form-control" placeholder=".col-xs-2">
            </div>
            <div class="col-xs-2">
                <input type="text" class="form-control" placeholder=".col-xs-3">
            </div>
            <div class="col-xs-2">
                <input type="text" class="form-control" placeholder=".col-xs-4">
            </div>
            <div class="col-xs-1">
                <button type="button" class="btn btn-default">Default</button>
            </div> 

        </div>

        <div class="row">
            <div class="radio">
                <label>
                    <input type="radio" name="optionsRadios" id="optionsRadios1" value="option1" checked>
                    Option one is this and that&mdash;be sure to include why it's great
                </label>
            </div>
        </div>

    </div>

    <!-----------/// MID FOOTER START END HERE --->





</div>
<!-----------/// FOOTER BOTTOM END HEREE ---->
<!---------/// footer bottom ---->
<div class="container-fluid footer_bottom">

    <div class="col-sm-6">Lorem Ipsum is simply dummy text | Lorem Ipsum </div>
    <div class="col-sm-6 text-right">Lorem Ipsum is simply dummy text | Lorem Ipsum </div>


</div>
<!----------/// Footer Bottom end here ---->
