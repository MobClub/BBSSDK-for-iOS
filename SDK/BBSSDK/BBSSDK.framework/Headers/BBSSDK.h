//
//  BBSSDK.h
//  BBSSDK
//
//  Created by liyc on 2017/2/14.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFoundation.h>
#import "BBSUser.h"
#import "BBSThread.h"
#import "BBSPost.h"
#import "BBSFans.h"
#import "BBSComment.h"
#import "BBSInformation.h"
#import "BBSLocation.h"

@interface BBSSDK : NSObject


//---

/**
 是否用插件

 @return BOOL
 */
+(BOOL)isUsePlug;

/**
 BBSSDK 版本号

 @return 版本号
 */
+ (NSString *)sdkVersion;

/**
 获取全局配置
 
 @param result 回调
 */
+ (void)getGlobalSettings:(void(^)(NSDictionary *settings, NSError *error))result;


/**
 获取版块列表
 
 @param fup 上级论坛id 预留字段，暂时不用
 @param result 回调
 */
+ (void)getForumListWithFup:(NSInteger)fup
                     result:(void (^)(NSArray *forumsList, NSError *error))result;

/**
 获取帖子列表

 @param fid 板块id
 @param orderType 排序依据 ：createdOn 按照发帖时间排序.lastPost 按照回帖时间排序。
 @param selectType displayOrder 置顶,digest 精华,heats 热门，latest 最新
 @param pageIndex 页索引
 @param pageSize 每页请求大小
 @param result 回调
 */
+ (void)getThreadListWithFid:(NSInteger)fid
                   orderType:(NSString *)orderType
                  selectType:(NSString *)selectType
                   pageIndex:(NSInteger)pageIndex
                    pageSize:(NSInteger)pageSize
                      result:(void (^)(NSArray *threadList, NSError *error))result;

/**
 搜索
 
 @param type 主题：thread，评论：post，用户：user，全部:all。默认为主题
 @param wd 搜索关键词
 @param pageIndex 页码，默认第一页
 @param pageSize 默认 20 每页，最大支持50每页
 @param result 结果
 */
+ (void)searchWithType:(NSString *)type
                    wd:(NSString *)wd
             pageIndex:(NSInteger)pageIndex
              pageSize:(NSInteger)pageSize
                result:(void (^)(NSArray *threadList, NSError *error))result;

//MARK:获取评论列表
/**
 获取评论列表

 @param fid 板块id
 @param tid 帖子id
 @param authorId 楼主id
 @param pageIndex 页索引
 @param pageSize 页大小
 @param result 回调
 */
+ (void)getPostListWithFid:(NSInteger)fid
                       tid:(NSInteger)tid
                  authorId:(NSInteger)authorId
                 pageIndex:(NSInteger)pageIndex
                  pageSize:(NSInteger)pageSize
                    result:(void (^)(NSArray *postList, NSError *error))result;


/**
 上传图片
 
 @param imagePath 需要上传的图片路径
 @param result 回调
 */
+ (void)uploadImageWithContentPath:(NSString *)imagePath result:(void(^)(NSString *url, NSError *error))result;


/**
 发帖
 
 @param fid 帖子版块id
 @param subject 标题
 @param message 内容html
 @param result 回调
 */
+ (void)postThreadWithFid:(NSInteger)fid
                  subject:(NSString *)subject
                  message:(NSString *)message
              isanonymous:(NSInteger)isanonymous
            hiddenreplies:(NSInteger)hiddenreplies
                   result:(void(^)(NSError *))result __deprecated_msg("discard form v2.4.0，please use postThreadWithFid:subject:message:isanonymous:hiddenreplies:location:result:");

/**
 发帖
 
 @param fid 帖子版块id
 @param subject 标题
 @param message 内容html
 @param location 定位信息 可空
 @param result 回调
 */
+ (void)postThreadWithFid:(NSInteger)fid
                  subject:(NSString *)subject
                  message:(NSString *)message
              isanonymous:(NSInteger)isanonymous
            hiddenreplies:(NSInteger)hiddenreplies
                 location:(BBSLocation *)location
                   result:(void(^)(NSError *))result;

/**
 发评论
 
 @param fid 板块id
 @param tid 主贴id
 @param reppid 被回复的帖子id
 @param message 消息内容
 @param result 回调
 */
+ (void)postCommentWithFid:(NSInteger)fid
                       tid:(NSInteger)tid
                    reppid:(NSInteger)reppid
                   message:(NSString *)message
                    result:(void(^)(BBSPost *, NSError *))result __deprecated_msg("discard form v2.4.0，please use postCommentWithFid:tid:reppid:message:location:result:");

/**
 发评论
 
 @param fid 板块id
 @param tid 主贴id
 @param reppid 被回复的帖子id
 @param message 消息内容
 @param location 定位信息 可空
 @param result 回调
 */
+ (void)postCommentWithFid:(NSInteger)fid
                       tid:(NSInteger)tid
                    reppid:(NSInteger)reppid
                   message:(NSString *)message
                   location:(BBSLocation *)location
                    result:(void(^)(BBSPost *, NSError *))result;

/**
 获取贴子详情
 
 @param fid 板块id
 @param tid 主贴id
 @param result 回调
 */
+ (void)getThreadDetailWithFid:(NSInteger)fid
                             tid:(NSInteger)tid
                          result:(void(^)(BBSThread *,NSError *error))result;


/**
 注册接口
 
 @param userName 用户名
 @param email 邮箱
 @param password 密码
 @param result 回调
 */
+ (void)registUserWithUserName:(NSString *)userName
                         email:(NSString *)email
                      password:(NSString *)password
                        result:(void(^)(BBSUser * , NSError *error))result __deprecated_msg("discard form v2.4.0，please use registUserWithUserName:email:password:coordinate:result");

/**
 注册接口
 
 @param userName 用户名
 @param email 邮箱
 @param password 密码
 @param coordinate 经纬度
 @param result 回调
 */
+ (void)registUserWithUserName:(NSString *)userName
                         email:(NSString *)email
                      password:(NSString *)password
                    coordinate:(BBSLocationCoordinate *)coordinate
                        result:(void(^)(BBSUser * , NSError *error))result;

/**
 登录接口
 
 @param userName 用户名
 @param email 邮箱
 @param password 密码
 @param questionid 问题id
 @param answer 问题答案
 @param result 回调
 */
+ (void)loginWithUserName:(NSString *)userName
                    email:(NSString *)email
                 password:(NSString *)password
               questionid:(NSInteger)questionid
                   answer:(NSString *)answer
                   result:(void(^)(BBSUser * ,id res, NSError *error))result __deprecated_msg("discard form v2.4.0，please use loginWithUserName:email:password:questionid:answer:coordinate:result");

/**
 登录接口
 
 @param userName 用户名
 @param email 邮箱
 @param password 密码
 @param questionid 问题id
 @param answer 问题答案
 @param coordinate 经纬度
 @param result 回调
 */
+ (void)loginWithUserName:(NSString *)userName
                    email:(NSString *)email
                 password:(NSString *)password
               questionid:(NSInteger)questionid
                   answer:(NSString *)answer
               coordinate:(BBSLocationCoordinate *)coordinate
                   result:(void(^)(BBSUser * ,id res, NSError *error))result;

/**
 授权登录
 
 @param openid openid微信和qq的唯一标示
 @param unionid 判断是否唯一，如果有一定要带上
 @param authType 授权类型：微信 = wechat；QQ = qq
 @param createNew 如果openid还没有创建账号，1=创建新账号，0=绑定现有账号
 @param userName 用户名
 @param email 邮箱
 @param password 密码
 @param questionId 问答id
 @param answer 问答答案
 */
+ (void)authLoginWithOpenid:(NSString *)openid
                    unionid:(NSString *)unionid
                   authType:(NSString *)authType
                  createNew:(NSNumber *)createNew
                   userName:(NSString *)userName
                      email:(NSString *)email
                   password:(NSString *)password
                 questionId:(NSNumber *)questionId
                     answer:(NSString *)answer
                     result:(void(^)(BBSUser *user, id res, NSError *error))result __deprecated_msg("discard form v2.4.0，please use authLoginWithOpenid:unionid:authType:createNew:userName:email:password:questionId:answer:coordinate:result:");

/**
 授权登录
 
 @param openid openid微信和qq的唯一标示
 @param unionid 判断是否唯一，如果有一定要带上
 @param authType 授权类型：微信 = wechat；QQ = qq
 @param createNew 如果openid还没有创建账号，1=创建新账号，0=绑定现有账号
 @param userName 用户名
 @param email 邮箱
 @param password 密码
 @param questionId 问答id
 @param answer 问答答案
 @param coordinate 经纬度
 */
+ (void)authLoginWithOpenid:(NSString *)openid
                    unionid:(NSString *)unionid
                   authType:(NSString *)authType
                  createNew:(NSNumber *)createNew
                   userName:(NSString *)userName
                      email:(NSString *)email
                   password:(NSString *)password
                 questionId:(NSNumber *)questionId
                     answer:(NSString *)answer
                 coordinate:(BBSLocationCoordinate *)coordinate
                     result:(void(^)(BBSUser *user, id res, NSError *error))result;


/**
 登出
 
 @param result 回调
 */
+ (void)logout:(void(^)(NSError *error))result;

/**
 重置密码/忘记密码

 @param email 邮箱地址
 @param userName 用户名
 @param result 回调
 */
+ (void)resetPasswordWithEmail:(NSString *)email 
                      userName:(NSString *)userName
                        result:(void (^)(NSError *error))result;

/**
 重发认证邮件

 @param email 邮件地址
 @param userName 用户名
 @param result 回调
 */
+ (void)sendIdentyEmail:(NSString *)email
               userName:(NSString *)userName
                 result:(void (^)(NSError *))result;

/**
 修改用户信息

 @param gender 性别索引 0保密 1男 2女  -1代表不传递
 @param birthday 生日 格式1988-01-02
 @param residence 地址 比如：苏州市-姑苏区
 @param sightml 个性签名
 @param avatarBigUrl 用户头像url，大尺寸 200*200
 @param avatarMiddleUrl 用户头像url，中尺寸 120*120
 @param avatarSmallUrl 用户头像url，小尺寸 48*48
 @param result 回调
 */
+ (void)editUserInfoWithGender:(NSInteger)gender
                      birthday:(NSString *)birthday
                     residence:(NSString *)residence
                       sightml:(NSString *)sightml
                  avatarBigUrl:(NSString *)avatarBigUrl
               avatarMiddleUrl:(NSString *)avatarMiddleUrl
                avatarSmallUrl:(NSString *)avatarSmallUrl
                        result:(void (^)(BBSUser *, NSError *))result;

/**
 上传头像

 @param imagePath 头像沙盒路径
 @param result 回调
 */
+ (void)uploadAvatarWithContentPath:(NSString *)imagePath
                             scales:(NSArray *)scales
                             result:(void(^)(NSArray *urlsDic, NSError *error))result;

/**
 获取个人详情页信息
 
 @param authorid 如果传值，就是查询对方的 计数，值为uid
 @param time 时间戳
 @param result 回调
 */
+ (void)getProfileInfoWithAuthorid:(NSInteger)authorid
                           time:(NSString *)time
                         result:(void(^)(BBSUser *user,NSError *error))result;

/**
 获取个人信息
 
 @param userName 用户名
 @param result 回调
 */
+ (void)getUserInfoWithUserName:(NSString *)userName
                         result:(void (^)(BBSUser *, NSError *))result;

/**
 获取好友列表
 
 @param authorid 需要查看的用户uid 可选
 @param pageIndex 页索引号，非必要参数，默认为1, 如果不传用0代替
 @param pageSize 每页大小，非必要参数，默认为10，最大不超过20, 如果不传用0代替
 @param result 回调
 */
+ (void)getFirendsWithAuthorid:(NSNumber *)authorid
                  pageIndex:(NSInteger)pageIndex
                   pageSize:(NSInteger)pageSize
                     result:(void(^)(NSArray<BBSFans *> *, NSError *))result;

/**
 获取粉丝列表
 
 @param authorid 需要查看的用户uid 可选
 @param pageIndex 页索引号，非必要参数，默认为1, 如果不传用0代替
 @param pageSize 每页大小，非必要参数，默认为10，最大不超过20, 如果不传用0代替
 @param result 回调
 */
+ (void)getFollowersWithAuthorid:(NSNumber *)authorid
                    pageIndex:(NSInteger)pageIndex
                     pageSize:(NSInteger)pageSize
                       result:(void(^)(NSArray<BBSFans *> *, NSError *))result;

/**
 关注
 
 @param followuid 被关注用户id
 @param result 回调
 */
+ (void)followWithFollowuid:(NSInteger)followuid
                 result:(void (^)(NSError *))result;

/**
 取消关注
 
 @param followuid 被关注用户id
 @param result 回调
 */
+ (void)unfollowWithFollowuid:(NSInteger)followuid
                   result:(void (^)(NSError *))result;

/**
 获取消息列表
 
 @param result 结果回调
 @param pageIndex 页索引号，非必要参数，默认为1, 如果不传用0代替
 @param pageSize 每页大小，非必要参数，默认为10，最大不超过20, 如果不传用0代替
 */
+ (void)getNotificationsWithPageIndex:(NSInteger)pageIndex
                         pageSize:(NSInteger)pageSize
                           result:(void(^)(NSArray<BBSInformation *> *array, NSError *))result;

/**
 获取个人帖子列表
 
 @param authorid 如果传这个参数就是查询别人的帖子列表，对方的uid
 @param pageIndex 页索引号，非必要参数，默认为1, 如果不传用0代替
 @param pageSize 每页大小，非必要参数，默认为10，最大不超过20, 如果不传用0代替
 @param result 回调
 */
+ (void)getUserThreadListWithAuthorid:(NSNumber *)authorid
                         pageIndex:(NSInteger)pageIndex
                          pageSize:(NSInteger)pageSize
                            result:(void(^)(NSArray<BBSThread *> *array, NSError *))result;

/**
 获取收藏帖子列表
 
 @param pageIndex 页索引号，非必要参数，默认为1, 如果不传用0代替
 @param pageSize 每页大小，非必要参数，默认为10，最大不超过20, 如果不传用0代替
 @param result 回调
 */
+ (void)getUserThreadFavoritesWithPageIndex:(NSInteger)pageIndex
                               pageSize:(NSInteger)pageSize
                                 result:(void(^)(NSArray<BBSThread *> *array, NSError *))result;



/**
 获取签到地址
 
 @param type 1：时尚版（专业），2：简约版（专业）
 @param userUid 用户ID
 @param enterSignUrl 签到入口地址可从获取个人详情页信息接口获得
 @param time 请求时间戳
 @param result 回调
 */
+ (void)getSginUrlWithType:(NSString *)type userUid:(NSNumber *)userUid enterSignUrl:(NSString *)enterSignUrl time:(NSTimeInterval )time Result:(void(^)(NSString *sginUrl, NSError *))result;

/**
 喜欢帖子
 
 @param fid 板块id
 @param tid 主题id
 @param result 回调
 */
+ (void)likeThreadWithFid:(NSInteger)fid
                      tid:(NSInteger)tid
                     result:(void(^)(NSError *))result;

/**
 收藏帖子
 
 @param fid 板块id
 @param tid 主题id
 @param result 回调
 */
+ (void)favoriteThreadWithFid:(NSInteger)fid
                            tid:(NSInteger)tid
                         result:(void(^)(NSDictionary *favorite, NSError *error))result;

/**
 取消收藏帖子
 
 @param favid 收藏帖子的favid，注意：支持用","符合隔开，进行多id的提交
 @param result 回调
 */
+ (void)unFavoriteThreadWithFavid:(NSString *)favid
                           result:(void(^)(NSError *))result;

/**
 设置消息已读
 
 @param noid 消息ID
 @param result 回调
 */
+ (void)readNotificationWithNoid:(NSString *)noid
                           result:(void(^)(NSError *))result;

/**
 删除消息
 
 @param noid 消息ID
 @param result 回调
 */
+ (void)deleteNotificationWithNoid:(NSString *)noid
                             result:(void(^)(NSError *))result;

/**
 获取热帖banner列表

 @param result 回调
 */
+ (void)getBannerList:(void (^)(NSArray *bannnerList, NSError *error))result;

/**
 举报
 
 @param rtype "post"，评论， rid传评论对应的pid   “thread”，主题，rid传主题对应的id
 @param rid 评论对应的pid值，主题对应主题id
 @param fid 版块id
 @param message 举报理由
 @param result 回调
 */
+ (void)accusationWithRtype:(NSString *)rtype
                        rid:(NSInteger)rid 
                        fid:(NSInteger)fid 
                    message:(NSString *)message 
                     result:(void (^)(NSError *error))result;

/**
 预览版设置appkey和secret
 */
+ (void)setupAppkey:(NSString *)appkey appSecret:(NSString *)secret;


#pragma mark - *********** 门户 **********

/**
 获取热帖banner列表
 
 @param result 回调
 */
+ (void)getPortalBannerList:(void (^)(NSArray *bannnerList, NSError *error))result;

/**
 获取帖子列表
 
 @param catid 类别id
 @param result 回调
 */
+ (void)getPortalListWithCatid:(NSInteger)catid
                     pageIndex:(NSInteger)pageIndex
                      pageSize:(NSInteger)pageSize
                        result:(void (^)(NSArray *threadList, NSError *error))result;

/**
 获取当前用户的关注用户的帖子列表

 @param result 回调
 */
+(void)getFollowThreadsListWithPageIndex:(NSInteger)pageIndex
                                pageSize:(NSInteger)pageSize
                                  result:(void (^)(NSArray *followList, NSError *error))result;


/**
 获取门户频道列表
 
 @param result 回调
 */
+ (void)getPortalCategories:(void (^)(NSArray *categories, NSError *error))result;

/**
 获取门户详情
 
 @param aid 文章id
 @param result 回调
 */
+ (void)getPortalDetailWithAid:(NSInteger)aid
                        result:(void(^)(BBSThread *,NSError *))result;

/**
 门户点赞
 
 @param aid 文章id
 @param clickid __nullable 默认1,1鲜花 2握手 3雷人 4路过 5鸡蛋
 @param result 回调
 */
+ (void)likePortalWithAid:(NSInteger)aid
                  clickid:(NSNumber *) clickid
                   result:(void(^)(NSError *))result;

/**
 发评论
 
 @param aid 文章id
 @param uid 用户id
 @param message 消息内容
 @param result 回调
 */
+ (void)postPortalCommentWithAid:(NSInteger)aid
                             uid:(NSInteger)uid
                         message:(NSString *)message
                          result:(void(^)(BBSComment *,NSError *))result  __deprecated_msg("discard form v2.4.0，please use postPortalCommentWithAid:uid:message:location:result:");

/**
 发评论
 
 @param aid 文章id
 @param uid 用户id
 @param message 消息内容
 @param location 定位信息 可空
 @param result 回调
 */
+ (void)postPortalCommentWithAid:(NSInteger)aid
                             uid:(NSInteger)uid
                         message:(NSString *)message
                         location:(BBSLocation *)location
                          result:(void(^)(BBSComment *,NSError *))result;


/**
 获取门户文章评论列表
 
 @param aid 文章id
 @param pageIndex 页索引
 @param pageSize 每页请求大小
 @param result 回调
 */
+ (void)getPortalCommentListWithAid:(NSInteger)aid
                          pageIndex:(NSInteger)pageIndex
                           pageSize:(NSInteger)pageSize
                             result:(void (^)(NSArray *__strong, NSError *__strong))result;


@end
