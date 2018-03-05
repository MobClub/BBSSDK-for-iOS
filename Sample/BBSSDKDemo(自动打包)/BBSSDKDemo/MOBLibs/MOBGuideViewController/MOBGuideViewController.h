//
//  MOBGuideViewController.h
//  MOBGuideViewController
//
//  Created by LeeJay on 2018/1/10.
//  Copyright © 2018年 Mob. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MOBGuideContentView;

@interface MOBGuideViewController : UIViewController

/**
 小圆点
 */
@property (nonatomic, strong, readonly) UIPageControl *pageControl;

/**
 关闭回调
 */
@property (nonatomic, copy) void (^closeCompletionHandler) (void);

/**
 用图片展示

 @param images 图片数组
 */
- (void)showWithImages:(NSArray <UIImage *> *)images;

/**
 用MOBGuideContentView展示

 @param contentViews MOBGuideContentView数组
 */
- (void)showWithGuideContentViews:(NSArray <MOBGuideContentView *> *)contentViews;

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
