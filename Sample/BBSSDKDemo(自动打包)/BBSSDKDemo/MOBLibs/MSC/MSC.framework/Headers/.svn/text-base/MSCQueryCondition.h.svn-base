//
//  MSCQueryCondition.h
//  MSC
//
//  Created by 冯鸿杰 on 2017/10/10.
//

#import <Foundation/Foundation.h>

/**
 查询条件
 */
@interface MSCQueryCondition : NSObject

/**
 使某个字段值等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id value))equal;

/**
 使某个字段值不等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id value))notEqual;

/**
 使某个字段值大于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id value))greaterThan;

/**
 使某个字段值小于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id value))lessThan;

/**
 使某个字段值大于或等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id value))greaterThanOrEqual;

/**
 使某个字段值小于或等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id value))lessThanOrEqual;

/**
 判断数组字段是否包含某个元素
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, id element))arrayContains;

/**
 使JSON字段某个字段等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, NSString *jsonKey, id value))jsonEqual;

/**
 使JSON字段某个字段不等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, NSString *jsonKey, id value))jsonNotEqual;

/**
 使JSON字段某个字段大于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, NSString *jsonKey, id value))jsonGreaterThan;

/**
 使JSON字段某个字段小于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, NSString *jsonKey, id value))jsonLessThan;

/**
 使JSON字段某个字段大于或等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, NSString *jsonKey, id value))jsonGreaterThanOrEqual;

/**
 使JSON字段某个字段小于或等于指定值
 
 @return 处理block
 */
- (MSCQueryCondition* (^)(NSString *key, NSString *jsonKey, id value))jsonLessThanOrEqual;

/**
 条件并集操作
 
 @return 条件对象
 */
- (MSCQueryCondition* (^)(MSCQueryCondition *otherCondition))orWith;




@end
