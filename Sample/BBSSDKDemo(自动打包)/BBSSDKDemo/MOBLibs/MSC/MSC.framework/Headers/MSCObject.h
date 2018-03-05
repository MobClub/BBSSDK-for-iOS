//
//  MSCObject.h
//  MSC
//
//  Created by 冯鸿杰 on 2017/10/9.
//  Copyright © 2017年 Mob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

@class MSCRelation;

/**
 对象类型，用于承载服务器返回数据接口的面对对象类型
 */
@interface MSCObject : MOBFDataModel

/**
 对象名称
 */
@property (nonatomic, copy, readonly) NSString *objectName;

/**
 对象标识
 */
@property (nonatomic, copy, readonly) NSString *objectId;

/**
 创建时间
 */
@property (nonatomic, strong, readonly) NSDate *createAt;

/**
 更新时间
 */
@property (nonatomic, strong, readonly) NSDate *updateAt;

/**
 初始化实例方法

 @param objectName 对象名
 @return 实例对象
 */
- (instancetype)initWithObjectName:(NSString *)objectName;

/**
 保存数据

 @param handler 返回事件处理器
 */
- (void)save:(void (^)(NSError *error))handler;

/**
 保存数据
 
 @param object 对象
 @param handler 返回事件处理器
 */
+ (void)saveWithObject:(MSCObject *)object
               handler:(void(^)(NSError *error))handler;

/**
 移除对象

 @param object 对象
 @param handler 返回事件处理器
 */
+ (void)deleteObject:(MSCObject *)object
             handler:(void (^) (NSError *error))handler;

@end
