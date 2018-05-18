//
//  BBSThread.h
//  BBSSDK
//
//  Created by liyc on 2017/2/19.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MOBFoundation/MOBFDataModel.h>

/**
 帖子详情
 */
@interface BBSThread : MOBFDataModel

/**
 帖子id
 */
@property (nonatomic ,assign) NSInteger tid;

/**
 版块id
 */
@property (nonatomic ,assign) NSInteger fid;

/**
 版块名字
 */
@property (nonatomic, strong) NSString *forumName;

/**
 标题
 */
@property (nonatomic, copy) NSString *subject;

/**
 设备名
 */
@property (nonatomic, copy) NSString *deviceName;

/**
 热门级别 0，1，2，3  0表示不是热门
 */
@property (nonatomic, assign) NSInteger heatLevel;


/**
 显示顺序 3，2，1 置顶 0 正常 -1 回收站 -2 审核中 -3 审核忽略 -4草稿
 */
@property (nonatomic, assign) NSInteger displayOrder;

/**
 是否精华 分三个等级1，2，3
 */
@property (nonatomic, assign) NSInteger digest;

/**
 是否高亮
 */
@property (nonatomic, assign) BOOL highLight;

/**
 摘要
 */
@property (nonatomic, copy) NSString *summary;

/**
 图片列表
 */
@property (nonatomic, strong) NSArray *images;

/**
 附件地址列表
 */
@property (nonatomic, strong) NSMutableArray *attachments;

/**
 内容html文本
 */
@property (nonatomic, copy) NSString *message;

/**
 作者
 */
@property (nonatomic, copy) NSString *author;

/**
 作者id
 */
@property (nonatomic, assign) NSInteger authorId;

/**
 帖子创建时间
 */
@property (nonatomic, assign) NSInteger createdOn;

/**
 最后评论者提交时间
 */
@property (nonatomic, assign) NSInteger lastPost;

/**
 头像
 */
@property (nonatomic, copy) NSString *avatar;


/**
 用户名
 */
@property (nonatomic, copy) NSString *username;

/**
 回复数
 */
@property (nonatomic, assign) NSInteger replies;

/**
 浏览数
 */
@property (nonatomic, assign) NSInteger views;

/**
 收藏id
 */
@property (nonatomic, assign) NSInteger favid;

/**
 是否已关注
 */
@property (nonatomic, assign) BOOL follow;

/**
 点赞人数
 */
@property (nonatomic, assign) NSInteger recommend_add;

/**
 反对人数
 */
@property (nonatomic, assign) NSInteger recommend_sub;

/**
 收藏次数
 */
@property (nonatomic, assign) NSInteger favtimes;

/**
 分享链接
 */
@property (nonatomic, copy) NSString *threadurl;

/**
 推荐指数
 */
@property (nonatomic, assign) NSInteger recommends;

/**
 板块图片
 */
@property (nonatomic, strong) NSString *forumPic;

/**
 地址简称
 */
@property (nonatomic, copy) NSString *poiTitle;

/**
 经纬度 纬度
 */
@property (nonatomic, assign) float latitude;


/**
 经纬度 经度
 */
@property (nonatomic, assign) float longitude;

/**
 replyshow 如果等于1的时候回复时刷新主题帖
 */
@property (nonatomic, assign) NSInteger replyShow;


#pragma mark - ********* 门户 *********
/**
 文章id
 */
@property (nonatomic, assign) NSInteger aid;

/**
 标题
 */
@property (nonatomic, strong) NSString *title;

/**
 作者id
 */
@property (nonatomic, assign) NSInteger authorid;

/**
 时间
 */
@property (nonatomic, assign) NSInteger dateline;

/**
 查看次数
 */
@property (nonatomic, assign) NSInteger viewnum;

/**
 评论次数
 */
@property (nonatomic, assign) NSInteger commentnum;

/**
 分享次数
 */
@property (nonatomic, assign) NSInteger sharetimes;

/**
 封面图片
 */
@property (nonatomic, strong) NSString *pic;

/**
 鲜花数
 */
@property (nonatomic, assign) NSInteger click1;

/**
 握手数
 */
@property (nonatomic, assign) NSInteger click2;

/**
 雷人数
 */
@property (nonatomic, assign) NSInteger click3;

/**
 路过数
 */
@property (nonatomic, assign) NSInteger click4;

/**
 鸡蛋数
 */
@property (nonatomic, assign) NSInteger click5;

/**
 内容
 */
@property (nonatomic, strong) NSString *content;

/**
 <#Description#>
 */
@property (nonatomic, strong) NSArray *related;

/**
 1-允许评论，0-不允许评论
 */
@property (nonatomic, assign) NSInteger allowcomment;

/**
 搜索专用字段:取值为:thread,user,post,portal
 */
@property (nonatomic, strong) NSString *type;

/**
 栏目名
 */
@property (nonatomic, strong) NSString *catname;

/**
 分享链接
 */
@property (nonatomic, strong) NSString *shareurl;

/**
 门户的原作者
 */
//@property (nonatomic, strong) NSString *author;

/**
 门户的发布者
 */
//@property (nonatomic, strong) NSString *username;

/**
 发布者id
 */
@property (nonatomic, assign) NSInteger originUid;

+ (BBSThread *)threadModelFromDictionary:(NSDictionary *)threadDic;

@end
