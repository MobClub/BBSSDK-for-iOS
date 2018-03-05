/**
 * Created with JetBrains WebStorm.
 * User: vim888
 * Date: 15/2/28
 * Time: 下午5:35
 * To change this template use File | Settings | File Templates.
 */

var $pluginID = "com.mob.BBSSDK";

/**
 * 流水号
 * @type {number}
 * @private
 */
var _seqId = 0;

/**
 * 扩展类
 */
$mob.ext = function () {};

/**
 * 回调方法集合
 * @type {{}}
 * @private
 */
$mob.ext._callbackFuncs = {};

/**
 * 绑定回调方法
 * @param callback      回调方法
 * @returns {string}    回调方法描述
 * @private
 */
$mob.ext._bindCallbackFunc = function (callback)
{
    var sessionId = new Date().getTime() + _seqId;
    _seqId ++;

    $mob.ext._callbackFuncs [sessionId] = function (data)
    {
        if (callback !== null)
        {
            callback (data);
        }

        delete  $mob.ext._callbackFuncs [sessionId];
        $mob.ext._callbackFuncs [sessionId] = null;
    };

    return "$mob.ext._callbackFuncs[" + sessionId + "]";
};

/**
 * 获取帖子详情
 * @param callback  回调
 */
$mob.ext.getForumThreadDetails = function (callback)
{

    var func = $mob.ext._bindCallbackFunc(callback);
    $mob.native.getForumThreadDetails(func);
};

$mob.ext.getPosts = function (fid, tid, page, pageSize,authorID, callback)
{
    var func = $mob.ext._bindCallbackFunc(callback);
    $mob.native.getPosts(fid, tid, page, pageSize,authorID,func);
}

$mob.ext.getImageUrlsAndIndex = function (callback)
{
    var func = $mob.ext._bindCallbackFunc(callback);
    $mob.native.getImageUrlsAndIndex(func);
}

$mob.ext.followAuthor = function (authorID, flag, callback)
{
    var func = $mob.ext._bindCallbackFunc(callback);
    $mob.native.followAuthor(authorID, flag, func);
}

$mob.ext.likeArticle = function(fid, tid, callback)
{
    var func = $mob.ext._bindCallbackFunc(callback);
    $mob.native.likeArticle(fid, tid, func);
}

