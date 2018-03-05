//
//  MOBWindowManager.h
//  MOBGuideViewController
//
//  Created by LeeJay on 2018/1/10.
//  Copyright © 2018年 Mob. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOBWindowManager : NSObject

/**
 显示窗口

 @return 窗口对象
 */
+ (UIWindow *)getWindow;

/**
 关闭窗口

 @param window 窗口对象
 @param animate 是否需要动画
 @param completion 完成回调
 */
+ (void)closeWindow:(UIWindow *)window
            animate:(BOOL)animate
         completion:(void (^) (void))completion;

@end
