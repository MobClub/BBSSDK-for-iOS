//
//  BBSComment.h
//  BBSSDK
//
//  Created by chuxiao on 2018/1/25.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@interface BBSComment : MOBFDataModel

/**
 评论id
 */
@property (nonatomic, assign) NSInteger cid;

/**
 评论对象id
 */
@property (nonatomic, assign) NSInteger ID;

/**
 评论对象的id类型：aid，topicid
 */
@property (nonatomic, strong) NSString *idtype;

/**
 作者
 */
@property (nonatomic, strong) NSString *username;

@property (nonatomic, assign) NSInteger uid;

@property (nonatomic, strong) NSString *avatar;

@property (nonatomic, assign) NSInteger dateline;

/**
 内容
 */
@property (nonatomic, strong) NSString *message;

/**
 评论ip
 */
@property (nonatomic, strong) NSString *postip;

/**
 状态 1审核
 */
@property (nonatomic, assign) NSInteger status;

/**
 设备来自
 */
@property (nonatomic, strong) NSString *fromType;

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


+ (BBSComment *)portalCommentFromDictionary:(NSDictionary *)dic;

@end
