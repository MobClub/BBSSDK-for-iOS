//
//  BBSInformation.h
//  BBSSDK
//
//  Created by chuxiao on 2017/7/17.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <MOBFoundation/MOBFoundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@interface BBSInformation : MOBFDataModel

/**
 通知类型
 */
@property (nonatomic, copy, readonly) NSString *type;

/**
 通知内容
 */
@property (nonatomic, copy, readonly) NSString *note;

/**
 消息id
 */
@property (nonatomic, copy, readonly) NSString *noid;

/**
 消息发送日期
 */
@property (nonatomic, assign, readonly) NSInteger dateline;

@property (nonatomic, copy, readonly) NSString *avatar;

@property (nonatomic, assign, readonly) NSInteger authorid;

@property (nonatomic, assign, readonly) NSInteger fid;

@property (nonatomic, assign, readonly) NSInteger tid;

@property (nonatomic, copy, readonly) NSString *title;

@property (nonatomic, copy, readonly) NSString *author;

/**
 是否已读 0：已读，1：未读
 */
@property (nonatomic, strong, readonly) NSNumber *isnew;

+ (BBSInformation *)inforMationWithDictionary:(NSDictionary *)dictionary;

@end
