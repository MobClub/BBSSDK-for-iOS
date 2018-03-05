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


+ (BBSThread *)threadModelFromDictionary:(NSDictionary *)threadDic;

@end
