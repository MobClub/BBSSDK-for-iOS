//
//  BBSFans.h
//  BBSSDK
//
//  Created by chuxiao on 2017/7/12.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@interface BBSFans : MOBFDataModel

/**
 会员id
 */
@property (nonatomic, assign, readonly) NSInteger uid;

/**
 是否双向关注 1，0

 1是双向关注
 */
@property (nonatomic, strong, readonly) NSNumber *mutual;

/**
 代表当前用户是否关注了对方
 */
@property (nonatomic, strong, readonly) NSNumber *isFollow;

/**
 性别（0:保密，1:男，2:女）
 */
@property (nonatomic, assign, readonly) NSInteger gender;

/**
 头像
 */
@property (nonatomic, copy, readonly) NSString *avatar;

/**
 用户名
 */
@property (nonatomic, copy, readonly) NSString *userName;

+ (BBSFans *)fansFromDictionary:(NSDictionary *)dic;

@end
