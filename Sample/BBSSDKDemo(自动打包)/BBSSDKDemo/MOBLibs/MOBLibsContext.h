//
//  MOBLibsContext.h
//  MOBLibs
//
//  Created by LeeJay on 2018/1/30.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MOBSDKKeyModel, MOBAboutUsViewController;

@interface MOBLibsContext : NSObject

/**
 初始化单例
 */
+ (instancetype)sharedInstance;

/**
 开启打印日志 default NO
 */
@property (nonatomic, assign) BOOL debugLog;

/**
 分享 key 等
 */
@property (nonatomic, strong, readonly) MOBSDKKeyModel *keyModel;

/**
 关于我们页面
 */
@property (nonatomic, strong, readonly) MOBAboutUsViewController *aboutVC;

/**
 展示 GuideVC （创建一个MOBGuideImages蓝色文件夹，不需要设置版本控制去展示，内部已经处理完）
 */
- (void)showGuideVC;

/**
 是否是新版本
 */
@property (nonatomic, assign, readonly) BOOL isNewVersion;

/**
 展示版本更新
 */
- (void)showUpdateVersionAlert;

@end
