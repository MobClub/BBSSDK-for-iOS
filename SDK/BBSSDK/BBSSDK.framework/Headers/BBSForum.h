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

@end
