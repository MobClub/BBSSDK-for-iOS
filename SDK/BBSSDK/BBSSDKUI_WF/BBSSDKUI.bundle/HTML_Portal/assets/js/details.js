
Date.prototype.Format = function (fmt) { //author: meizz
  var o = {
    "M+": this.getMonth() + 1, //月份
    "d+": this.getDate(), //日
    "h+": this.getHours(), //小时
    "m+": this.getMinutes(), //分
    "s+": this.getSeconds(), //秒
    "q+": Math.floor((this.getMonth() + 3) / 3), //季度
    "S": this.getMilliseconds() //毫秒
  };
  if (/(y+)/.test(fmt)) fmt = fmt.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
  for (var k in o)
  if (new RegExp("(" + k + ")").test(fmt)) fmt = fmt.replace(RegExp.$1, (RegExp.$1.length == 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
  return fmt;
}
/*
 *详情页
 * */
var details=new Vue({
    el: '#details',
	data:{
		article:null,//文章详情
		commentList:[],//评论列表
		placeholder:'写评论...',
		sendBtn:false,//发送回复按钮
		bottomAction:true,//底部三个操作图标
		popupBg:false,//弹出层背景
		popupShare:false,//分享的弹出层
		textType:1,//类型0：回复，1：评论
		commentIndex:'',//回复评论的index
		commentText:'',//回复评论的内容
		pageIndex:1,//评论当前页
		pageSize:10,//评论每页数量
		noMore:false,//暂无更多
		loading:false,
		articleLike:false,//喜欢
		onlyAuthor:false,
		authorId:0,
	},
	
	//值发生改变触发
	watch:{
    	
    },
    
    //初始化加载
	created:function(){
		var _this=this
		var loadingOk=true
		document.body.addEventListener('touchstart', function () {}); 
		window.onscroll  = function (){
		    var marginBot = 0;
		    if(_this.onlyAuthor==true){
		    	_this.authorId=_this.article.authorId
		    } else{
		    	_this.authorId=0
		    }
		    if (document.compatMode === "CSS1Compat"){
		        marginBot = document.documentElement.scrollHeight - (document.documentElement.scrollTop+document.body.scrollTop)-  document.documentElement.clientHeight;
		    } else {
		        marginBot = document.body.scrollHeight - document.body.scrollTop-  document.body.clientHeight;
		    }
		    if(marginBot<=0 && loadingOk==true) {
		    	loadingOk=false
		    	if(_this.noMore==true){
    				return
    			}
		    	setTimeout(function(){
		        	_this.loading=true
		        	setTimeout(function(){
			        	_this.loading=false
			        	loadingOk=true
			        	_this.pageIndex++
			        	_this.getCommentList(_this.article.aid, _this.pageIndex, _this.pageSize)
			        },100)
		        },100)
		    }
		}
		
                BBSSDKNative.getNewsArticleDetails(function(detailData) {
//            detailData=JSON.parse(detailData)
			_this.getArticle(detailData)
			_this.getCommentList(detailData.aid,  _this.pageIndex, _this.pageSize)
			
		});
		this.$nextTick(function () {
			$(document).on("click", ".article-text a", function(e){
				e.preventDefault();
				BBSSDKNative.openHref($(this).attr("href"));
			})
			$(document).on("click", "img[src_flag='1']", function(e){
				var imgList=[]
				var md=$(this).attr("src_tag")
				var n=-1
				var i=''
				$("img[src_flag]").each(function(){
					n++
				    imgList.push($(this).attr("src_link"))
				    if(md==$(this).attr("src_tag")){
				    	i=n
				    }
				})
                           $mob.native.log('dddddddddddddd');
				BBSSDKNative.openImage(imgList,i);
			})
		})
		
    },
    methods:{
    	/*获得文章详情*/
    	getArticle: function(detailData){
    		var _this=this
    		var imgList=[]
    		_this.article=detailData
    		_this.$nextTick(function () {
				$(".article-text img").each(function(){
				    $(this).attr("src_link",$(this).attr("src"))
				    $(this).attr("src_tag",md5($(this).attr("src_link")))
				    $(this).addClass(md5($(this).attr("src_link")))
				    $(this).attr("src_flag",'0')
				    $(this).attr("srcset",'')
//				    $(this).attr("src","../assets/images/default_pic.png")
				    imgList.push($(this).attr("src_link"))
				})
			    BBSSDKNative.downloadImages(imgList)
                            //$mob.native.log("===========================");
                            var w = document.getElementById("detail_a").offsetWidth;
                            //$mob.native.log("1===============" + w + "============");
                            var video = document.getElementsByTagName("iframe");
                            for(v in video ){
                            //$mob.native.log("2===============" + v + "============" + w * 0.75);
                            video[v].width = w
                            video[v].height = w*0.75
                            }
			})
    		
    		// console.log(JSON.stringify(this.article, null,2))
    	},
    	/*获得评论列表详情*/
    	getCommentList: function(aid, page, pageSize){
    		var _this=this
    		var imgList=[]
    		
    		BBSSDKNative.getComments(aid, page,pageSize, function(list) {
    			
    			if(list==null&&page<2){
    				_this.commentList=[]
    				_this.noMore=true
    				return
    			}
    			if(list.length<_this.pageSize){
    				_this.noMore=true
    			}
    			for(var i=0; i<list.length; i++){
    				_this.commentList.push(list[i])
    			}
			});
			_this.$nextTick(function () {
                            $(".comment-text img").each(function(){
                                if($(this).attr("src_flag")!='1' && $(this).attr("src_flag")!='0'){
                                    $(this).attr("src_link",$(this).attr("src"))
                                    $(this).attr("src_tag",md5($(this).attr("src_link")))
                                    $(this).addClass(md5($(this).attr("src_link")))
                                    $(this).attr("src_flag",'0')
                                    $(this).attr("srcset",'')
                                    $(this).attr("src","../assets/images/default_pic.png")
                                    imgList.push($(this).attr("src_link"))
                                }
                            })
			    BBSSDKNative.downloadImages(imgList)
			})
    	},
    	/*前往作者详情*/
    	openAuthor: function(authorId){
    		BBSSDKNative.openAuthor(authorId)
    	},
        openRelatedArticle: function(aid){
    		BBSSDKNative.openRelatedArticle(aid)
    	},
    	/*附件*/
    	openAttachment: function(data){
            $mob.native.log('sssssssaaaaaa');
    		BBSSDKNative.openAttachment(data)
    	},
        openAddress: function(data){
            BBSSDKNative.showAddress(data)
        },
    	timeSet: function(time){
            var diffdate = new Date().getTime() - time*1000;
            var days = Math.floor(diffdate/(24*3600*1000));
            var leave1 = diffdate%(24*3600*1000);   
            var hours = Math.floor(leave1/(3600*1000));  

            var leave2 = leave1%(3600*1000);
            var minutes = Math.floor(leave2/(60*1000));
            var leave3 = leave2%(60*1000);
            var seconds = Math.round(leave3/1000);

            var thedate = new Date(time * 1000).Format("MM-dd hh:mm");
            return (days && days > 0) ? thedate : (hours && hours > 0) ? hours + "小时前" : (minutes && minutes > 0) ? minutes + "分钟前" : "刚刚";
        },
        formatView: function(view){
            if(view>=999){
                return '999+'
            }
            return view
        },
        goComment: function(){
            var _this=this
            setTimeout(function(){
                _this.$nextTick(function () {
                        document.getElementById('postTitle').scrollIntoView();
                })
                },100)
        },
        /*喜欢likeArticle*/
    	like: function(aid){
            var _this=this
            if(_this.articleLike==false){
                BBSSDKNative.likeArticle(aid,function(result) {
                    if(result==true){
                            _this.articleLike=true
                            _this.article.click1++
                    }
                    });
            }
    	},
    }
})
