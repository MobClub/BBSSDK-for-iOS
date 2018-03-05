//
//  UIButton+Common.h
//  BBSSDKUI
//
//  Created by liyc on 2017/3/3.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (Common)

/**
 *  快速创建一个有标题的Button（无frame，适用于Masonry）
 *
 *  @param title           文字
 *  @param titleColor      文字颜色
 *  @param backgroundColor 背景颜色
 *  @param font            文字大小
 *  @param target          target
 *  @param action          事件处理
 *  @param view            加到的父视图
 *
 *  @return Button
 */
+ (instancetype)buttonWithTitle:(NSString *)title
                     titleColor:(UIColor *)titleColor
                backgroundColor:(UIColor *)backgroundColor
                           font:(CGFloat)font
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view;

/**
 *  快速创建一个有标题的Button（有frame）
 *
 *  @param frame           frame大小
 *  @param title           文字
 *  @param titleColor      文字颜色
 *  @param backgroundColor 背景颜色
 *  @param font            文字大小
 *  @param target          target
 *  @param action          事件处理
 *  @param view            加到的父视图
 *
 *  @return Button
 */
+ (instancetype)buttonWithFrame:(CGRect)frame
                          title:(NSString *)title
                     titleColor:(UIColor *)titleColor
                backgroundColor:(UIColor *)backgroundColor
                           font:(CGFloat)font
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view;

/**
 *  快速创建一个有前景图的Button（无frame，适用于Masonry）
 *
 *  @param imageName 图片名称
 *  @param target    target
 *  @param action    事件处理
 *  @param view      加到的父视图
 *
 *  @return Button
 */
+ (instancetype)buttonWithImageName:(NSString *)imageName
                             target:(id)target
                             action:(SEL)action
                          superView:(UIView *)view;

/**
 *  快速创建一个有前景图的Button（有frame）
 *
 *  @param frame     frame大小
 *  @param imageName 图片名称
 *  @param target    target
 *  @param action    事件处理
 *  @param view      加到的父视图
 *
 *  @return Button
 */
+ (instancetype)buttonWithFrame:(CGRect)frame
                      imageName:(NSString *)imageName
                         target:(id)target
                         action:(SEL)action
                      superView:(UIView *)view;

@end
