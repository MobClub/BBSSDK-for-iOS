//
//  MOBGuideContentView.h
//  MOBGuideViewController
//
//  Created by LeeJay on 2018/1/10.
//  Copyright © 2018年 Mob. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MOBGuideContentView : UIView

/**
 关闭
 
 @param animate 动画
 */
- (void)closeWithAnimate:(BOOL)animate;

/**
 关闭+回调
 
 @param animate 动画
 @param completion 回调
 */
- (void)closeWithAnimate:(BOOL)animate completion:(void (^)(void))completion;

@end
