//
//  MSCQuery.h
//  MSC
//
//  Created by 冯鸿杰 on 2017/10/9.
//  Copyright © 2017年 Mob. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MSCObject;
@class MSCQueryCondition;
@class MSCQueryOrder;

/**
 对象查询类型，输入条件即可得到符合条件的对象集合
 */
@interface MSCQuery : NSObject

/**
 查询条件
 */
@property (nonatomic, strong, readonly) MSCQueryCondition *condition;

/**
 排序
 */
@property (nonatomic, strong, readonly) MSCQueryOrder *order;

/**
 初始化查询

 @param objectName 对象名称
 @return 查询对象
 */
- (instancetype)initWithObjectName:(NSString *)objectName;

/**
 初始化查询
 
 @param objectName 对象名称
 @param targetClass 目标类型，默认为MSCObject，可以指定MSCObject的子类,则find时可以返回指定对象类型
 @return 查询对象
 */
- (instancetype)initWithObjectName:(NSString *)objectName
                       targetClass:(Class)targetClass;

/**
 筛选查找字段

 @param keys 字段名称
 */
- (void)selectKeys:(NSArray<NSString *> *)keys;

/**
 筛选JSON结构字段
 例：表中带有一个叫info的json结构字段，其字段值为{"name":"xxx","age":10},则info为第一个参数，
 其中第二个参数则可以包含name、age字段，
 第三个参数则需要为info字段新起一个字段名字，避免和原有字段名称冲突

 @param key 字段名称
 @param jsonKeys 指定要查找的JSON中的字段名称
 @param newKey 新字段名称
 */
- (void)selectJsonKey:(NSString *)key
             jsonKeys:(NSArray<NSString *> *)jsonKeys
               newKey:(NSString *)newKey;

/**
 包含一个子对象，例如：查询一篇文章（article）所属作者(author)的信息

 @param key 子对象字段名称
 @param subObjectKeys 要查找的子对象字段
 @param newKey 新的字段名称
 */
- (void)includeSubObjectWithKey:(NSString *)key
                  subObjectKeys:(NSArray<NSString *> *)subObjectKeys
                         newKey:(NSString *)newKey;

/**
 查找对象，最多返回100条记录

 @param handler 返回回调
 */
- (void)find:(void (^)(NSArray<MSCObject *> *objects, NSError *error))handler;

/**
 查找对象

 @param offset 偏移量
 @param pageSize 分页大小，默认为100,最大1000
 @param handler 返回回调
 */
- (void)findWithOffset:(NSInteger)offset
              pageSize:(NSInteger)pageSize
               handler:(void (^)(NSArray<MSCObject *> *objects, NSError *error))handler;

/**
 查找第一个对象
 
 @param handler 返回回调
 */
- (void)findFirst:(void (^)(MSCObject *object, NSError *error))handler;

@end
