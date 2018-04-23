(function() {
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

    /*点击头像后，前往作者详情*/
    function openAuthor(authorId) {
        //TODO 实现native交互，跳转作者的界面
        console.log(authorId);
    }
    
    /*
     * 喜欢文章
     * */
    function likeArticle(aid,callback) {
        //TODO 实现native交互，喜欢文章，返回结果（Boolean）给h5前端
        console.log(aid);
        $mob.native.log('aksdjfk');
        $mob.ext.likeArticle(aid, callback);
    }
	
    /*打开图片*/
    function openImage(imgList,index) {
        //TODO 实现native交互，跳转打开图片的界面
        $mob.native.openImage(imgList, index);
    }

    /*打开附件*/
    function openAttachment(attachment) {
        //TODO 实现native交互，跳转打开附件的界面
//        $mob.native.log('hahahhahahahaha');
        $mob.native.openAttachment(attachment);
    }

    /* 跳转链接 */
    function openHref(href) {
    	//TODO 实现native交互，跳转到链接：href
        $mob.native.openHref(href);
    }
    /* 跳转相关资讯 */
    function openRelatedArticle(href){
        $mob.native.openRelatedArticle(href);
    }
    
    /* 下载图片，iimgList为界面所有的img标签对应的图片链接 */
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

    /* 获取图片集合地址和当前索引 
    * 设置hideNav为true时不显示头
    */
    function getImageUrlsAndIndex(callback,hideNav) {
        //TODO 由Native返回对象{imageUrls:[], index:0}
        callback({imageUrls:["https://ss1.bdstatic.com/70cFuXSh_Q1YnxGkpoWK1HF6hhy/it/u=949197531,2432970866&fm=23&gp=0.jpg",
        "https://ss1.bdstatic.com/70cFuXSh_Q1YnxGkpoWK1HF6hhy/it/u=1738350124,1182499903&fm=23&gp=0.jpg",
        "https://ss1.bdstatic.com/70cFuXSh_Q1YnxGkpoWK1HF6hhy/it/u=1497794588,1167065085&fm=23&gp=0.jpg"
        ], index:0});
        if(hideNav){
            $(".photo-browser .bar").hide();
            $(".bar-nav~.content").css({"top": "0"});
        }
    }
    
    /**
     * press 回调
     * @param  {[type]} img [description]
     * @return {[type]}     [description]
     */
    function pressImgCallback(img){
        console.log(img);
    }


    /*设置当前页面图片地址和index*/
    function setCurrentImageSrc(imgSrc, index) {
        //TODO 由Native去实现图片界面切换后的界面状态
    }

    /*获取门户文章详情*/
    function getNewsArticleDetails (callback) {
        $mob.ext.getNewsArticleDetails(callback);
    }
    /*
     * 获取文章回帖列表
     * */
    function getComments(aid, page,pageSize,callback) {
        $mob.ext.getComments(aid, page, pageSize ,callback);
    }
 
    /*
     * 添加新的评论
     * @param data {Object} 评论内容
     * @param authorId {number} 楼主编号
     * */
    function addNewCommentHtml(data, authorId){
        details.article.commentnum++
        details.commentList.unshift(data)//将data插入即可
    }
 
    /*界面跳转到评论模块*/
    function goComment() {
        details.goComment()
    }
 
    /*点击头像后，前往作者详情*/
    function openAuthor(authorId) {
        //TODO 实现native交互，跳转作者的界面
        $mob.native.openAuthor(authorId);
    }
 
    function showAddress(address){
        $mob.native.showAddress(address);
    }
 
    /*定义BBSSDKNative全局属性*/
    window.BBSSDKNative = {
        openImage: openImage,
        openAttachment: openAttachment,
        openHref: openHref,
        getImageUrlsAndIndex: getImageUrlsAndIndex,
        setCurrentImageSrc: setCurrentImageSrc,
        downloadImages: downloadImages,
        showImage: showImage,
        pressImgCallback: pressImgCallback,
        openAuthor:openAuthor,
        
        getNewsArticleDetails :getNewsArticleDetails,
        getComments:getComments,
        openRelatedArticle:openRelatedArticle,
        addNewCommentHtml: addNewCommentHtml, //新增评论
        likeArticle:likeArticle,
        goComment:goComment,
        openAuthor:openAuthor,
        showAddress:showAddress
    }
})();
