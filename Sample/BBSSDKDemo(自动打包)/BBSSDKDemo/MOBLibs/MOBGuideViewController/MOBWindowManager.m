//
//  MOBWindowManager.m
//  MOBGuideViewController
//
//  Created by LeeJay on 2018/1/10.
//  Copyright © 2018年 Mob. All rights reserved.
//

#import "MOBWindowManager.h"

@interface MOBWindowManager ()

/**
 *  正在使用的窗口集合
 */
@property (nonatomic, strong) NSMutableSet *useWindowSet;

@end

@implementation MOBWindowManager

- (instancetype)init
{
    if (self = [super init])
    {
        self.useWindowSet = [NSMutableSet set];
    }
    return self;
}

+ (UIWindow *)getWindow
{
    UIWindow *window = nil;
    
    MOBWindowManager *manger = [self _defaultManager];
    if (manger.useWindowSet.count > 0)
    {
        window = manger.useWindowSet.anyObject;
    }
    else
    {
        window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        [manger.useWindowSet addObject:window];
    }
    
    window.windowLevel = [UIApplication sharedApplication].keyWindow.windowLevel + 1;
    
    return window;
}

+ (void)closeWindow:(UIWindow *)window
            animate:(BOOL)animate
         completion:(void (^) (void))completion
{
    MOBWindowManager *manger = [self _defaultManager];
    if ([manger.useWindowSet containsObject:window])
    {
        if (animate)
        {
            [UIView animateWithDuration:1.0f delay:0.0f options:UIViewAnimationOptionCurveEaseOut animations:^{
                
                window.transform = CGAffineTransformMakeScale(1.6, 1.6);
                window.alpha = 0.0;
                
            } completion:^(BOOL finished) {
                
                [window resignKeyWindow];
                window.hidden = YES;
                //释放根视图控制器
                window.rootViewController = nil;
                
                [manger.useWindowSet removeObject:window];
                
                if (completion)
                {
                    completion();
                }
            }];
        }
        else
        {
            [window resignKeyWindow];
            window.hidden = YES;
            //释放根视图控制器
            window.rootViewController = nil;
            [manger.useWindowSet removeObject:window];
            if (completion)
            {
                completion();
            }
        }
    }
}

#pragma mark - Private

+ (MOBWindowManager *)_defaultManager
{
    static MOBWindowManager *manager = nil;
    static dispatch_once_t predicate;
        dispatch_once(&predicate, ^{
        manager = [[MOBWindowManager alloc] init];
    });
    return manager;
}

@end
