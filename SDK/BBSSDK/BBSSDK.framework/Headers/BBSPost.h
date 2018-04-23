//
//  BBSPost.h
//  BBSSDK
//
//  Created by liyc on 2017/3/1.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

/**
 *  回帖详情
 */
@interface BBSPost : MOBFDataModel

/**
 帖子所属版块id
 */
@property (nonatomic, readonly) NSInteger fid;

/**
 主题帖子id
 */
@property (nonatomic, readonly) NSInteger tid;

/**
 回帖id
 */
@property (nonatomic, assign) NSInteger pid;

/**
 回帖内容（html文本）
 */
@property (nonatomic, copy) NSString *message;

/**
 父评论
 */
@property (nonatomic, strong, readonly) BBSPost *prePost;

/**
 回帖者昵称
 */
@property (nonatomic, copy, readonly) NSString *author;

/**
 回帖者id
 */
@property (nonatomic, readonly) NSInteger authorId;

/**
 回帖者头像URL
 */
@property (nonatomic, copy, readonly) NSString *avatar;

/**
 回帖时间
 */
@property (nonatomic, readonly) NSInteger createdOn;

/**
 回帖楼层/位置
 */
@property (nonatomic, readonly) NSInteger position;

/**
 用户ip
 */
@property (nonatomic, copy) NSString *useIp;

/**
 设备名称
 */
@property (nonatomic, copy) NSString *deviceName;

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
 根据字典返回模型
 */
- (instancetype)initWithDictionary:(NSDictionary *)postDic;

@end
