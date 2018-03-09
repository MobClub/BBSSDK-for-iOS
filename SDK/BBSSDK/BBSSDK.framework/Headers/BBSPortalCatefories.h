//
//  BBSPortalCatefories.h
//  BBSSDK
//
//  Created by chuxiao on 2018/1/22.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@interface BBSPortalCatefories : MOBFDataModel

/**
 分栏id
 */
@property (nonatomic, assign) NSInteger catid;

/**
 父级id
 */
@property (nonatomic, assign) NSInteger upid;

/**
 分栏名
 */
@property (nonatomic, strong) NSString *catname;

/**
 文章数
 */
@property (nonatomic, assign) NSInteger articles;

/**
 1-允许评论，0-不允许评论
 */
@property (nonatomic, assign) NSInteger allowcomment;

/**
 显示顺序
 */
@property (nonatomic, assign) NSInteger displayorder;

/**
 是否禁止发布文章  1禁止发布
 */
@property (nonatomic, assign) NSInteger disallowpublish;

/**
 是否开启栏目  0开启 1关闭
 */
@property (nonatomic, assign) NSInteger closed;

+ (BBSPortalCatefories *)portalCateforiesFromDictionary:(NSDictionary *)dic;

@end
