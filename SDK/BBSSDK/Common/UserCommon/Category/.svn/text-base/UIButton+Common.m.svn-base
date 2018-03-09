//
//  UIButton+Common.m
//  BBSSDKUI
//
//  Created by liyc on 2017/3/3.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "UIButton+Common.h"

@implementation UIButton (Common)

+ (instancetype)buttonWithTitle:(NSString *)title
                     titleColor:(UIColor *)titleColor
                backgroundColor:(UIColor *)backgroundColor
                           font:(CGFloat)font
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view
{
    return [self buttonWithFrame:CGRectZero
                           title:title
                      titleColor:titleColor
                 backgroundColor:backgroundColor
                            font:font
                          target:target
                          action:action
                       superView:view];
}

+ (instancetype)buttonWithFrame:(CGRect)frame
                          title:(NSString *)title
                     titleColor:(UIColor *)titleColor
                backgroundColor:(UIColor *)backgroundColor
                           font:(CGFloat)font
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view
{
    return [self buttonWithFrame:frame
                           title:title
                      titleColor:titleColor
                 backgroundColor:backgroundColor
                            font:font
                       imageName:nil
                          target:target
                          action:action
                       superView:view];
}

+ (instancetype)buttonWithImageName:(NSString *)imageName
                             target:(id)target
                             action:(SEL)action
                          superView:(UIView *)view
{
    return [self buttonWithFrame:CGRectZero
                       imageName:imageName
                          target:target
                          action:action
                       superView:view];
}

+ (instancetype)buttonWithFrame:(CGRect)frame
                      imageName:(NSString *)imageName
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view
{
    return [self buttonWithFrame:frame
                           title:nil
                      titleColor:nil
                 backgroundColor:nil
                            font:0
                       imageName:imageName
                          target:target
                          action:action
                       superView:view];
}

#pragma mark - Private

+ (instancetype)buttonWithFrame:(CGRect)frame
                          title:(NSString *)title
                     titleColor:(UIColor *)titleColor
                backgroundColor:(UIColor *)backgroundColor
                           font:(CGFloat)font
                      imageName:(NSString *)imageName
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    
    if (imageName != nil)
    {
        [button setImage:[UIImage imageNamed:imageName] forState:UIControlStateNormal];
    }
    
    if (backgroundColor != nil)
    {
        [button setBackgroundColor:backgroundColor];
    }
    
    if (titleColor != nil)
    {
        [button setTitleColor:titleColor forState:UIControlStateNormal];
    }
    
    if (view != nil)
    {
        [view addSubview:button];
    }
    
    button.frame = frame;
    button.titleLabel.font = [UIFont systemFontOfSize:font];
    [button setTitle:title forState:UIControlStateNormal];
    [button addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    return button;
}

@end
