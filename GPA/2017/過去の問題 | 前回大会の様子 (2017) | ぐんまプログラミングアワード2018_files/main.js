(function($){
    $(document).ready(function(){

        (function(){
            var setting = {
                booklet: '#mybooklet',
                prev: '#mybooklet-prev',
                next: '#mybooklet-next',
                click: 'click',
            };

            $('<img src="img/question-2017-q1.png">');
            $('<img src="img/question-2017-q2.png">');
            $('<img src="img/question-2017-q3.png">');
            $('<img src="img/question-2017-q4.png">');
            $('<img src="img/question-2017-q5.png">');
            $('<img src="img/question-2017-q6.png">');
            $('<img src="img/question-2017-q7.png">');
            $('<img src="img/question-2017-q8.png">');
            $('<img src="img/question-2017-q9.png">');
            $('<img src="img/question-2017-q10.png">');
            $('<img src="img/question-2017-q11.png">');
            $('<img src="img/question-2017-q12.png">');
            $('<img src="img/question-2017-close-answer-example.png">');
            $('<img src="img/question-2017-open-answer-example.png">');
            $('<img src="img/question-2017-img-001.png">');
            $('<img src="img/question-2017-img-002.png">');
            $('<img src="img/question-2017-img-003.png">');
            $('<img src="img/question-2017-img-004.png">');

            var $booklet = $(setting.booklet);
            var $bookletPage = $booklet.find('.mybooklet-page');
            var page = 0;
            var pageLength = $booklet.find('.mybooklet-page').length;
            var maxHeight = 0;
            var inAnimete = false;

            var setPage = function(p){
                if (p < 0 || pageLength <= p) { return; }
                if (inAnimete) { return; }
                $bookletPage.css({'z-index':0});
                $bookletPage.eq(page).css({'z-index':1});
            };
            var flipPage = function(p){
                if (p < 0 || pageLength <= p) { return; }
                if (p == page) { return; }
                if (inAnimete) { return; }
                closePage(0);
                inAnimete = true;
                if (p < page) {
                    // similar to prevPage
                    $booklet.height(maxHeight);
                    var $pPage = $bookletPage.eq(p); // diff (1/2)
                    var $cPage = $bookletPage.eq(page);
                    var $prevPageA = $pPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    var $prevPageB = $pPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    var $prevPageC = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    var $prevPageD = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    $prevPageA.addClass('prevPageA');
                    $prevPageB.addClass('prevPageB');
                    $prevPageC.addClass('prevPageC');
                    $prevPageD.addClass('prevPageD');
                    $booklet.append($prevPageA);
                    $booklet.append($prevPageD); // append order is very important.
                    $booklet.append($prevPageC);
                    $booklet.append($prevPageB);
                    $prevPageA.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $prevPageA.remove(); });
                    $prevPageB.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $prevPageB.remove(); });
                    $prevPageC.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $prevPageC.remove(); });
                    $prevPageD.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){
                        $prevPageD.remove();
                        page = p; // diff (1/2)
                        $bookletPage.css({'z-index':0});
                        $bookletPage.eq(page).css({'z-index':1});
                        inAnimete = false;
                    });
                    $prevPageA.addClass('aniPrevPageA');
                    $prevPageB.addClass('aniPrevPageB');
                    $prevPageC.addClass('aniPrevPageC');
                    $prevPageD.addClass('aniPrevPageD');
                }
                if (page < p) {
                    // similar to nextPage
                    $booklet.height(maxHeight);
                    var $cPage = $bookletPage.eq(page);
                    var $nPage = $bookletPage.eq(p); // diff (1/2)
                    var $nextPageA = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    var $nextPageB = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    var $nextPageC = $nPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    var $nextPageD = $nPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                    $nextPageA.addClass('nextPageA');
                    $nextPageB.addClass('nextPageB');
                    $nextPageC.addClass('nextPageC');
                    $nextPageD.addClass('nextPageD');
                    $booklet.append($nextPageA);
                    $booklet.append($nextPageD); // append order is very important.
                    $booklet.append($nextPageB);
                    $booklet.append($nextPageC);
                    $nextPageA.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $nextPageA.remove(); });
                    $nextPageB.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $nextPageB.remove(); });
                    $nextPageC.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $nextPageC.remove(); });
                    $nextPageD.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){
                        $nextPageD.remove();
                        page = p; // diff (1/2)
                        $bookletPage.css({'z-index':0});
                        $bookletPage.eq(page).css({'z-index':1});
                        inAnimete = false;
                    });
                    $nextPageA.addClass('aniNextPageA');
                    $nextPageB.addClass('aniNextPageB');
                    $nextPageC.addClass('aniNextPageC');
                    $nextPageD.addClass('aniNextPageD');
                }
            };
            var prevPage = function(){
                if (page < 1) { return; }
                if (inAnimete) { return; }
                closePage(0);
                inAnimete = true;
                $booklet.height(maxHeight);
                var $pPage = $bookletPage.eq(page-1);
                var $cPage = $bookletPage.eq(page);
                var $prevPageA = $pPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                var $prevPageB = $pPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                var $prevPageC = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                var $prevPageD = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                $prevPageA.addClass('prevPageA');
                $prevPageB.addClass('prevPageB');
                $prevPageC.addClass('prevPageC');
                $prevPageD.addClass('prevPageD');
                $booklet.append($prevPageA);
                $booklet.append($prevPageD); // append order is very important.
                $booklet.append($prevPageC);
                $booklet.append($prevPageB);
                $prevPageA.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $prevPageA.remove(); });
                $prevPageB.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $prevPageB.remove(); });
                $prevPageC.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $prevPageC.remove(); });
                $prevPageD.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){
                    $prevPageD.remove();
                    page--;
                    $bookletPage.css({'z-index':0});
                    $bookletPage.eq(page).css({'z-index':1});
                    inAnimete = false;
                });
                $prevPageA.addClass('aniPrevPageA');
                $prevPageB.addClass('aniPrevPageB');
                $prevPageC.addClass('aniPrevPageC');
                $prevPageD.addClass('aniPrevPageD');
            };
            var nextPage = function(){
                if (pageLength-1 <= page) { return; }
                if (inAnimete) { return; }
                closePage(0);
                inAnimete = true;
                $booklet.height(maxHeight);
                var $cPage = $bookletPage.eq(page);
                var $nPage = $bookletPage.eq(page+1);
                var $nextPageA = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                var $nextPageB = $cPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                var $nextPageC = $nPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                var $nextPageD = $nPage.clone().removeClass('mybooklet-page').addClass('mybooklet-page-flip').wrap('<div />').parent().addClass('mybooklet-page-flip-w').height(maxHeight);
                $nextPageA.addClass('nextPageA');
                $nextPageB.addClass('nextPageB');
                $nextPageC.addClass('nextPageC');
                $nextPageD.addClass('nextPageD');
                $booklet.append($nextPageA);
                $booklet.append($nextPageD); // append order is very important.
                $booklet.append($nextPageB);
                $booklet.append($nextPageC);
                $nextPageA.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $nextPageA.remove(); });
                $nextPageB.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $nextPageB.remove(); });
                $nextPageC.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){ $nextPageC.remove(); });
                $nextPageD.on('animationend webkitAnimationEnd oAnimationEnd mozAnimationEnd transitionend webkitTransitionEnd oTransitionEnd mozTransitionEnd', function(){
                    $nextPageD.remove();
                    page++;
                    $bookletPage.css({'z-index':0});
                    $bookletPage.eq(page).css({'z-index':1});
                    inAnimete = false;
                });
                $nextPageA.addClass('aniNextPageA');
                $nextPageB.addClass('aniNextPageB');
                $nextPageC.addClass('aniNextPageC');
                $nextPageD.addClass('aniNextPageD');
            };
            var openPage = function(){
                var $cPage = $bookletPage.eq(page);
                maxHeight = $bookletPage.attr('data-qah');
                $bookletPage.animate({'height':maxHeight+'px'});
                $cPage.find('.mybooklet-page-open-w').css({'display':'none'});
                $cPage.find('.mybooklet-page-i-answer').slideDown();
                $booklet.height(maxHeight);
                $booklet.addClass('open');
            };
            var closePage = function(d){
                var duration = (d == undefined) ? 500 : d;
                var $cPage = $bookletPage.eq(page);
                maxHeight = $bookletPage.attr('data-qh');
                $bookletPage.animate({'height':maxHeight+'px'});
                $cPage.find('.mybooklet-page-open-w').css({'display':'block'});
                $cPage.find('.mybooklet-page-i-answer').slideUp(duration);
                $booklet.height(maxHeight);
                $booklet.removeClass('open');
            };
            var getPage = function(){
                return p;
            };
            var resize = function(){
                var p, h;
                var openD   = $bookletPage.eq(page).find('.mybooklet-page-open-w').css('display');
                var answerD = $bookletPage.eq(page).find('.mybooklet-page-i-answer').css('display');

                p = [];
                $bookletPage.css({'height':'auto','visibility':'hidden'});
                $bookletPage.find('.mybooklet-page-open-w').css({'display':'block'});
                $bookletPage.find('.mybooklet-page-i-answer').css({'display':'none'});
                $.each($bookletPage,function(i,j){
                    p.push($(j).height());
                });
                h = Math.max.apply(null, p);
                $bookletPage.attr('data-qh',h);

                p = [];
                $bookletPage.find('.mybooklet-page-open-w').css({'display':'none'});
                $bookletPage.find('.mybooklet-page-i-answer').css({'display':'block'});
                $.each($bookletPage,function(i,j){
                    p.push($(j).height());
                });
                h = Math.max.apply(null, p);
                $bookletPage.attr('data-qah',h);

                if (answerD == 'block') {
                    maxHeight = $bookletPage.attr('data-qah');
                } else {
                    maxHeight = $bookletPage.attr('data-qh');
                }

                $bookletPage.find('.mybooklet-page-open-w').css({'display':'block'});
                $bookletPage.find('.mybooklet-page-i-answer').css({'display':'none'});
                $bookletPage.eq(page).find('.mybooklet-page-open-w').css('display',openD);
                $bookletPage.eq(page).find('.mybooklet-page-i-answer').css('display',answerD);
                $bookletPage.css({'height':maxHeight+'px','visibility':'visible'});
                $booklet.height(maxHeight);
            };

            setTimeout(function(){
                resize();
                $bookletPage.eq(page).css({'z-index':1});
            },500); // easy

            $(window).on('resize',function(){ resize(); });
            $('#mybooklet-prev').on(setting.click, function(){ prevPage(); });
            $('#mybooklet-next').on(setting.click, function(){ nextPage(); });
            for (i=0; i<12; i++) {
                (function(i){
                    $('.mybooklet-p-'+i).on(setting.click, function(){
                        if (inAnimete) { return; }
                        flipPage(i);
                        $('.pager a').removeClass('active');
                        $('.pager-upper a:eq('+i+')').addClass('active');
                        $('.pager-lower a:eq('+i+')').addClass('active');
                    });
                })(i);
            }
            $('.pager-upper a:eq(0)').addClass('active');
            $('.pager-lower a:eq(0)').addClass('active');
            $('.open-answer-example').on(setting.click, function(){ openPage(); });
            $('.close-answer-example').on(setting.click, function(){ closePage(); });

        })();

    });
})(jQuery);