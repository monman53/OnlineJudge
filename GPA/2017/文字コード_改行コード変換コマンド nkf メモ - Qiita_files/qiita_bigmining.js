!function(e,t){function n(t,n,a){if('undefined'==typeof a&&(a=e),a.addEventListener)a.addEventListener(t,n,!1);else{if(!a.attachEvent)throw new Error('can not add event');a.attachEvent('on'+t,n)}}try{var a=function(e){var t=new Image;t.src=e,t.width=1,t.height=1,t.border=0,t.style.display='none',document.body.appendChild(t)},o=function(e,t,n){var a='/',o=(new Date).getTime(),i=new Date(o+864e5*n),r=i.toUTCString(),d='';d+=e+'='+escape(t),d+='; path='+a,d+=n?'; expires='+r+'; ':'; ',document.cookie=d},i=function(e){if(!document.cookie)return'';for(var t='',n=document.cookie.split('; '),a=0;a<n.length;a++){var o=n[a].split('=');o[0]==e&&(t=unescape(o[1]))}return t},r=function(e,t){t=t||'';var n='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'+t;n=n.split('');for(var a='',o=0;o<e;o++)a+=n[Math.floor(Math.random()*n.length)];return a};n('load',function(){for(var t=(location.href,document.getElementsByClassName('TagList__label')),n='',d=0;d<t.length;d++){var c=t[d];if(!(c.childNodes.length<2)){var l=c.childNodes[1].textContent;''!==l&&(0!==d&&(n+=','),n+=l)}}var s='qiitausr',g=i(s);if(''===g){var m=new Date;o(s,r(11)+'_'+String(m.getTime()),365),g=i(s)}else o(s,g,365);var u='//bigmining.com/dmp',p='?url='+encodeURIComponent(location.href)+'&rurl='+encodeURIComponent(document.referrer),f={};f.server=document.domain,''!==n&&(f.categories=n),p+='&qiita_data='+encodeURIComponent(JSON.stringify(f)).replace(/%20/g,'+'),a(u+p+'&action=pv&'+s+'='+g),e.dg_tag_data=e.dg_tag_data||{},e.dg_tag_data.qiita_search_categories=n,a('//cm.g.doubleclick.net/pixel?google_nid=bigmining_dmp&google_cm&'+s+'='+g),a('https://analytics.twitter.com/i/adsct?p_id=979&p_user_id='+g);var h=document.createElement('script');h.innerHTML='(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({\'gtm.start\':new Date().getTime(),event:\'gtm.js\'});var f=d.getElementsByTagName(s)[0],j=d.createElement(s),dl=l!=\'dataLayer\'?\'&l=\'+l:\'\';j.async=true;j.src=\'//www.googletagmanager.com/gtm.js?id=\'+i+dl;f.parentNode.insertBefore(j,f);})(window,document,\'script\',\'dataLayer\',\'GTM-58Z82M\');',document.body.appendChild(h)})}catch(d){}}(window);