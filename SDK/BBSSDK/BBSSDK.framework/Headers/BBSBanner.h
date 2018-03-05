//
//  BBSBanner.h
//  BBSSDK
//
//  Created by liyc on 2017/8/10.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <MOBFoundation/MOBFoundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@interface BBSBanner : MOBFDataModel

/**
 标题
 */
@property (nonatomic, copy) NSString *title;

/**
 类型
 */
@property (nonatomic, copy) NSString *btype;

/**
 图片URL
 */
@property (nonatomic, copy) NSString *picture;

/**
 链接地址
 */
@property (nonatomic, copy) NSString *link;

/**
 帖子所属版块id
 */
@property (nonatomic, assign) NSInteger fid;

/**
 帖子主题id
 */
@property (nonatomic, assign) NSInteger tid;

/**
 转换model

 @param bannerDic 字典
 @return model
 */
+ (BBSBanner *)bannerModelFromDictionary:(NSDictionary *)bannerDic;

@end
