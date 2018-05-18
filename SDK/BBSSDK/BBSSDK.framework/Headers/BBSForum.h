//
//  BBSForum.h
//  BBSSDK
//
//  Created by liyc on 2017/2/21.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@interface BBSForum : MOBFDataModel

//====

/**
 fup 父板块id
 */
@property (nonatomic, assign) NSInteger fup;

/**
 今日帖子数量
 */
@property (nonatomic, assign) NSInteger todayposts;


/**
 版块id
 */
@property (nonatomic, readonly) NSInteger fid;

/**
 版块名称
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 版块类别，group:分类 forum:普通论坛 sub:子论坛
 */
@property (nonatomic, copy, readonly) NSString *type;

/**
 显示顺序
 */
@property (nonatomic, readonly) NSInteger displayOrder;

/**
 论坛介绍信息
 */
@property (nonatomic, copy, readonly) NSString *forumDescription;

/**
 论坛图片地址
 */
@property (nonatomic, copy, readonly) NSString *forumPic;

/**
 是否允许发帖
 */
@property (nonatomic, readonly)       NSInteger allowPost;

/**
 是否允许评论
 */
@property (nonatomic, readonly)       NSInteger allowReply;

/**
 显示状态
 */
@property (nonatomic, readonly)       NSInteger status;

/**
 背景大图
 */
@property (nonatomic, copy)         NSString *forumBigPic;

/**
 是否允许匿名发帖（0:不允许，1:允许）
 */
@property (nonatomic, assign) NSInteger allowAnonymous;

/**
 版块分组标题
 */
@property (nonatomic, strong, readonly) NSString *groupName;

/**
 是否展开
 */
@property (nonatomic, assign) BOOL isExpect;
/**
 是否编辑
 */
@property (nonatomic, assign) BOOL hasEdited;

@end
