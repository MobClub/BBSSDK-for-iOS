 (function($) {
  // 计算时间差
  function timeDiff(time){
  var diffdate = new Date().getTime() - time*1000;
  var days = Math.floor(diffdate/(24*3600*1000));
  var leave1 = diffdate%(24*3600*1000);
  var hours = Math.floor(leave1/(3600*1000));
  
  var leave2 = leave1%(3600*1000);
  var minutes = Math.floor(leave2/(60*1000));
  var leave3 = leave2%(60*1000);
  var seconds = Math.round(leave3/1000);
  return (days && days > 0) ? days + "天前" : (hours && hours > 0) ? hours + "小时前" : (minutes && minutes > 0) ? minutes + "分钟前" : "刚刚";
  }
  /*获取主题帖子详情*/
  function getForumThreadDetails(callback) {
  $mob.ext.getForumThreadDetails(callback);
  }
  
  /*
   * 获取主题帖子回帖列表
   * @param authorId {number} 需要筛选的用户id，默认0（不筛选）
   * */
  function getPosts(fid, tid, page, pageSize,authorId, callback) {
  
  $mob.ext.getPosts(fid, tid, page, pageSize,authorId,callback);
  
  }
  
  /*点击头像后，前往作者详情*/
  function openAuthor(authorId) {
  //TODO 实现native交互，跳转作者的界面
  $mob.native.openAuthor(authorId);
  }
  
  /*
   * 喜欢文章
   * */
  function likeArticle(fid,tid,callback) {
  //TODO 实现native交互，喜欢文章，返回结果（Boolean）给h5前端
  $mob.ext.likeArticle(fid, tid, callback);
  }
  
  /*打开图片*/
  function openImage(imgList,index) {
  //TODO 实现native交互，跳转打开图片的界面
  $mob.native.openImage(imgList, index);
  }
  
  /*打开附件*/
  function openAttachment(attachment) {
  //TODO 实现native交互，跳转打开附件的界面
  $mob.native.openAttachment(attachment);
  }
  
  /* 跳转链接 */
  function openHref(href) {
  $mob.native.openHref(href);
  }
  
  /* 获取图片集合地址和当前索引 */
  function getImageUrlsAndIndex(callback) {
  $mob.ext.getImageUrlsAndIndex(callback);
  }
  
  /*设置当前页面图片地址和index*/
  function setCurrentImageSrc(imgSrc, index) {
  $mob.native.setCurrentImageSrc(imgSrc, index);
  }
  
  /* 下载图片，imgUrlList为界面所有的img标签对应的图片链接 */
  function downloadImages(imgUrlList) {
  $mob.native.downloadImages(imgUrlList);
  }
  
  /* 显示图片，替换imgUrl对应的img标签的src值为imgSrc，其中imgSrc为Native已经下载好的本地图片地址 */
  function showImage(index, imgUrlMD5, imgSrc, isImageViewer) {
  //TODO H5实现此方法，并进行图片替换操作
  
  //        alert(imgSrc);
  if (isImageViewer) {
  if (imgSrc) {
  $(".photo-browser .photo-browser-swiper-container .swiper-slide").eq(index).find("img").attr("src", imgSrc);
  } else {
  $(".photo-browser .photo-browser-swiper-container .swiper-slide").eq(index).find("img").attr("src", "img/default_pic_error.png");
  }
  } else {
  if (imgSrc) {
  $("."+imgUrlMD5).attr("src",imgSrc)
  $("."+imgUrlMD5).attr("src_flag",'1')
  } else{
  $("."+imgUrlMD5).attr("src",'../assets/images/default_pic_error.png')
  }
  }
  }
  
  function bindCommentImgEvent(li){
  var myPhotoBrowserStandalone;
  var imgList = [];
  var downloadImgList = [];
  $.each($(li).find(".center img"), function(index, item){
         imgList.push(item.src);
         var lastIndex = item.src.lastIndexOf(".");
         if (lastIndex > 0) {
         downloadImgList.push(item.src);
         item.src_link = md5(item.src);
         // item.src = "img/default_pic.png";
         item.srcset = "";
         }
         $(item).off("click").on("click", function(){
                                 //                    myPhotoBrowserStandalone.open(index);
                                 openImage(imgList,index);
                                 });
         });
  if (imgList.length > 0) {
  //                    myPhotoBrowserStandalone = $.photoBrowser({
  //                        photos : imgList,
  //                        onSlideChangeEnd: function(swiper){
  //                            BBSSDKNative.setCurrentImageSrc($(swiper.slides[swiper.activeIndex]).find("img").attr("src"),swiper.activeIndex);
  //                        }
  //                    });
  BBSSDKNative.downloadImages(downloadImgList);
  }
  }
  
  function likeThread(){
  details.article.recommend_add++
  }
  
  /*
   * 添加新的评论
   * @param data {Object} 评论内容
   * @param authorId {number} 楼主编号
   * */
  function addNewCommentHtml(data, authorId){
  // if($(".common-content ul").find("li").length < 10){
  //     prePostLists.push(data);
  //     if (data.message) {
  //         data.message = data.message.replace(/<img/g, '<img dz-imgshow').replace(/<a /g, '<a dz-ahref class="external"');
  //     }
  //     var html = "";
  //     html += '<li><div class="header row"><div class="left">\
  //                 <div class="headimg"><img src="'+ data.avatar +'"></div>\
  //                 <div class="userinfo">\
  //                     <h3><span>'+ data.author +'</span>'+ (data.authorId == authorId ? '<span class="tip">楼主</span>' : '') +'</h3>\
  //                 </div>\
  //             </div>\
  //             <div class="right">\
  //                 <span class="category">'+ data.position +'楼</span>\
  //             </div></div><div class="center"><p>'+ data.message +'</p>';
  //             if(data.prePost){
  //                 html += '<div class="reply"><p class="sub"><strong>引用：</strong>'+ data.prePost.author +'于'+ timeDiff(data.prePost.createdOn) +'发表的：'+ data.prePost.message +'</p></div>';
  //             }
  //             html += '<div class="bottom"><span>'+ timeDiff(data.createdOn) +'</span><span>来自 '+data.deviceName+'</span><span class="tip" reply-data="'+ $(".common-content ul").find("li").length +'">回复</span></div></li>';
  //     $(".common-content ul").append(html);
  //     bindCommentImgEvent($(".common-content ul li").last());
  // }else{
  //     return;
  // }
  details.article.replies++
  details.commentList.push(data)//将data插入即可
  }
  
  /* 渲染评论列表 */
  var _PAGE = null, _FID , _TID, _T;
  var prePostLists = [];
  function getCommonHtml(page,fid,tid,authorId,Isfilter){
  _PAGE = page;
  _FID = fid;
  _TID = tid;
  
  var filterId = Isfilter ? authorId : 0;
  
  // 加载flag
  var loading = false;
  // 每次加载添加多少条目
  var itemsPerLoad = 10;
  
  var pagecout = 1;
  
  /*获取主题帖子回帖列表*/
  var getthisPosts = function (fid, tid, page, pageSize){
  prePostLists = [];
  pagecout = page + 1;
  getPosts(fid, tid, page, pageSize, filterId, function(data){
           
           $mob.native.log("-------llllllll----"+ data)
           
           if(data){
           // 获取数据成功
           var html = "";
           $.each(data,function(index, item){
                  if (item.message) {
                  item.message = item.message.replace(/<img/g, '<img dz-imgshow').replace(/<a /g, '<a dz-ahref class="external"');
                  }
                  
                  html += '<li><div class="header row"><div class="left">\
                  <div class="headimg"><img src="'+ item.avatar +'"></div>\
                  <div class="userinfo">\
                  <h3><span>'+ item.author +'</span>'+ (item.authorId == authorId ? '<span class="tip">楼主</span>' : '') +'</h3>\
                  </div>\
                  </div>\
                  <div class="right">\
                  <span class="category">'+ item.position +'楼</span>\
                  </div></div><div class="center"><p>'+ item.message +'</p>';
                  if(item.prePost){
                  html += '<div class="reply"><p class="sub"><strong>引用：</strong>'+ item.prePost.author +'于'+ timeDiff(item.prePost.createdOn) +'发表的：'+ item.prePost.message +'</p></div>';
                  }
//                  html += '<div class="bottom"><span>'+ timeDiff(item.createdOn) +'</span><span>来自 '+item.deviceName+'</span><span class="tip" reply-data="'+ index +'">回复</span></div></li>';
                  //==
                  html += '<div class="bottom"><span>'+ timeDiff(item.createdOn) +'</span>'+ (item.isPlug == true ? '' : '<span>来自 '+item.deviceName+'</span>') + '<span class="tip" reply-data="'+ index +'">回复</span></div></li>';
                  var prePostdata = item;
                  prePostLists.push(prePostdata);
                  });
           $(".common-content ul").append(html);
           $(document).off("click").on("click","[reply-data]",function(){
                                       BBSSDKNative.replyComment(prePostLists[$(this).attr("reply-data")]);
                                       });
           $.each($(".common-content ul").find("li"), function(index, item){
                  bindCommentImgEvent(item);
                  });
           
           $(".dz-loading-over span").text("以上已为全部内容");
           if (data.length != pageSize) {
           $.detachInfiniteScroll($('.infinite-scroll'));
           $('.infinite-scroll-preloader').remove();
           $(".dz-loading-over").show();
           } else {
           $(".dz-loading-over").hide();
           }
           }else{
           // 获取数据失败
           $.detachInfiniteScroll($('.infinite-scroll'));
           $('.infinite-scroll-preloader').remove();
           $(".dz-loading-over").show();
           }
           });
  
  };
  //预先加载10条
  getthisPosts(fid,tid, pagecout, itemsPerLoad);
  
  $(_PAGE).off('infinite').on('infinite', function(){
                              if (loading) return;
                              loading = true;
                              // 模拟1s的加载过程
                              _T = setTimeout(function() {
                                              // 重置加载flag
                                              loading = false;
                                              
                                              // 添加新条目
                                              getthisPosts(fid,tid, pagecout, itemsPerLoad);
                                              $.refreshScroller();
                                              }, 1000);
                              
                              });
  }
  
  /* 刷新评论列表 */
  function updateCommentHtml(authorId,filter){
  if(_PAGE && _FID && _TID){
  $(".common-content ul").html("");
  $(".content").scrollTop(0);
  window.clearTimeout(_T);
  getCommonHtml(_PAGE,_FID,_TID,authorId,filter);
  }else{
  return;
  }
  }
  
  /*
   * 回复方法
   * @param prepost {Object} 回复内容
   */
  function replyComment(prepost){
  $mob.native.replyComment(prepost);
  }
  
  /**
   * press 回调
   * @param  {[type]} img [description]
   * @return {[type]}     [description]
   */
  function pressImgCallback(img){
  $mob.native.pressImgCallback(img)
  }
  
  /*
   * 关注文章作者
   * @param flag {number} 0为关注，1为取消关注
   * */
  function followAuthor(authorId,flag,callback) {
  //TODO 实现native交互，关注文章作者，返回结果（Boolean）给h5前端
  // console.log(authorId + "&&&&" + flag);
  // callback(true)
  $mob.ext.followAuthor(authorId, flag, callback);
  }
  
  /*界面跳转到评论模块*/
  function goComment() {
  details.goComment()
  }
  
  /* 打开导航地图 */
  function showAddress(address){
  $mob.native.showAddress(address);
  }
  
  /*定义BBSSDKNative全局属性*/
  window.BBSSDKNative = {
  getForumThreadDetails: getForumThreadDetails,
  getPosts: getPosts,
  openImage: openImage,
  openAttachment: openAttachment,
  openHref: openHref,
  getImageUrlsAndIndex: getImageUrlsAndIndex,
  setCurrentImageSrc: setCurrentImageSrc,
  downloadImages: downloadImages,
  showImage: showImage,
  getCommonHtml: getCommonHtml,
  updateCommentHtml: updateCommentHtml,
  replyComment: replyComment,
  addNewCommentHtml: addNewCommentHtml,
  pressImgCallback: pressImgCallback,
  openAuthor:openAuthor,
  followAuthor:followAuthor,
  likeArticle:likeArticle,
  //2017-08-23新增接口
  goComment:goComment,
  likeThread:likeThread,
  showAddress:showAddress
  }
  })(Zepto);
