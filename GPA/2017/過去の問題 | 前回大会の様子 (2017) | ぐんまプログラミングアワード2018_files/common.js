$(function(){
	
	sideNav();
	mvBtnEntry ();
	pageTop();
	mvHand();
	snsFacebook ();
	smoothScroll ();
	mvFirstView ();
});

$(window).on('load resize',function(){});

function sideNav(){
	
	var show=false;
	if( document.getElementById('side_switch')==null ){ return; }
	
	//show menu
	//reset
	$('#side_switch').removeClass('active');
	$('#side_switch').off('click');
	
	//set event
	$('#side_switch').on('click',function(){
		
		if(!show){
			
			$(this).addClass('active');
			show=true;

		}else{
			
			$(this).removeClass('active');
			$('.side_nav_list').removeClass('active');
			show=false;
		}
	});
	
	//hidden menu
	//reset
	$('body').off('click.menuBtnEvent touchend.menuBtnEvent');
	
	//set event
	$('body').on('click.menuBtnEvent touchend.menuBtnEvent', function(event) {
		
		if (!$(event.target).closest('#side_nav_group').length) {
			
			$('#side_switch').removeClass('active');
			$('.side_nav_list').removeClass('active');
			show=false;
		}
	});
	
	//sub menu
	$('a[href^="#side_nav_list"]').on('click',function(e){
		
		e.preventDefault();
		$('.side_nav_list').removeClass('active');
		$( $(this).attr('href') ).addClass('active');
	});
}

function mvFirstView (){
	
	if( document.getElementById('mv_logo')==null ){ return; }
	
	if( $('#mv_logo').hasClass('firstview') ){
		
		$('#mv_logo').removeClass('firstview');
	}
}

function mvBtnEntry (){
	
	if( document.getElementById('mv_btn_entry')==null ){ return; }
	
	$('#mv_btn_entry').on('click',function(e){
		
		e.preventDefault();
		$('#mv_btns').toggleClass('transform');
		return false;
	});
}

function smoothScroll (){
	
	if( !$('a[href*="#"]')[0] ){ return; }
	
	//load
	if(location.hash){
		
		if( !location.hash.match('#side_nav_list') && !location.hash.match('#formtop') ){ // wak

			$('body,html').stop().animate({ scrollTop:$(location.hash).offset().top });
			return false;
		}
	}

	//click
	$('a[href*="#"]').on('click',function(){
		
		var url = $(this).attr('href');
		var selector = url.slice(url.indexOf('#'));
		
		if( !url.match('#side_nav_list') ){
			
			$('body,html').stop().animate({ scrollTop:$(selector).offset().top });
			return false;
		}
	});
}

function pageTop(){
	
	$('.goto_pagetop a').on('click',function(){
		
		$('body,html').stop().animate({ scrollTop:0 });
		return false;
	});
	
	$(window).on('scroll',function(){
		
		if( $(window).scrollTop() > $(window).height()*2 ){
			
			$('.goto_pagetop').addClass('active');
			
		}else if( $(window).scrollTop() <= $(window).height()*2 ){
			
			$('.goto_pagetop').removeClass('active');
		}
		
		if( $(window).scrollTop()+$(window).height() > $('#footer').offset().top ){
			
			$('.goto_pagetop').addClass('fixed');
			
		}else if( $(window).scrollTop()+$(window).height() <= $('#footer').offset().top ){
			
			$('.goto_pagetop').removeClass('fixed');
		}
	});
}

function mvHand(){
	
	if( document.getElementById('mv_hand')==null ){ return; }
	/*
	var clearID=setTimeout(function(){
		
		$('#mv_hand').addClass('animated bounceIn');
		
	},1000);
	*/
}

function snsFacebook () {

	var windowWidth = $(window).width();
	var htmlStr = $('#sns_facebook').html();
	var timer = null;
	
	$(window).on('load resize',function() {
		
		var resizedWidth = $(window).width();
		if(windowWidth != resizedWidth && resizedWidth < 500) {
			
			clearTimeout(timer);
			timer = setTimeout(function() {
				
				$('#sns_facebook').html(htmlStr);
				window.FB.XFBML.parse();
				windowWidth = $(window).width();
			}, 500);
		}
	});
}

// news cms
(function($){
    $(document).ready(function(){
        $('ul.list_news li.has-more a.more').on('click', function(){
            var $btn = $(this);
            var $detail = $btn.siblings('.detail');
            if ($btn.hasClass('open-btn')) {
                $btn.removeClass('open-btn').addClass('close-btn');
                $detail.slideDown();
            } else {
                $btn.removeClass('close-btn').addClass('open-btn');
                $detail.slideUp();
            }
        });
        $('ul.list_news li.has-more .title').on('click', function(){
            var $title = $(this);
            // option (begin)
            if ($title.children('a').length > 0) {
                return;
            }
            // option (end)
            var $btn = $title.siblings('a.more');
            var $detail = $btn.siblings('.detail');
            if ($btn.hasClass('open-btn')) {
                $btn.removeClass('open-btn').addClass('close-btn');
                $detail.slideDown();
            } else {
                $btn.removeClass('close-btn').addClass('open-btn');
                $detail.slideUp();
            }
        });
    });
})(jQuery);