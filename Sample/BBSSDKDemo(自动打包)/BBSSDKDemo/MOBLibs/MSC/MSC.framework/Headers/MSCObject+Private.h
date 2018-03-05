//
//  MSCObject+Private.h
//  MSC
//
//  Created by 冯鸿杰 on 2017/10/11.
//

#import "MSCObject.h"

@interface MSCObject ()

/**
 对象名称
 */
@property (nonatomic, copy) NSString *objectName;

/**
 对象标识
 */
@property (nonatomic, copy) NSString *objectId;

/**
 更新字段
 */
@property (nonatomic, strong) NSMutableDictionary *updateFields;

@end
