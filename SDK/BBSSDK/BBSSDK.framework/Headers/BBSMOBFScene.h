//
//  BBSMOBFScene.h
//  BBSSDK
//
//  Created by wukx on 2018/4/19.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BBSMOBFScene : NSObject

/**
 场景信息初始化
 
 @param path 路径,应传入需要恢复的控制器所设定的路径,即控制器在实现UIViewController+MLSDKRestore里面的+[MLSDKPath]时所返回的值。
 @param source 来源标识
 @param params 自定义参数,可传入自定义键值对
 @return 场景对象
 */
- (instancetype)initWithMLSDKPath:(NSString *)path source:(NSString *)source params:(NSDictionary *)params;

/**
 获取路径
 
 @return 路径
 */
- (NSString *)getPath;

/**
 获取来源
 
 @return 来源
 */
- (NSString *)getSource;

/**
 获取自定义参数
 
 @return 自定义参数
 */
- (NSDictionary *)getParams;

/**
 获取mobid
 
 @return MobId
 */
- (NSString *)getMobId;

@end
