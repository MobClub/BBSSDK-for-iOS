//
//  UIView+TipView.h
//  BBSSDKUI
//
//  Created by liyc on 2017/3/3.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TipView;

@interface UIView (TipView)

/**
 *  配置一个TipView
 *
 *  @param tipString 提示信息
 *  @param hasData   是否有数据
 */
- (void)configureTipViewWithTipMessage:(NSString *)tipString hasData:(BOOL)hasData;

/**
 *  配置一个TipView(新增：可以自定义没有数据时候的图片)
 *
 *  @param tipString   提示信息
 *  @param hasData     是否有数据
 *  @param noDataImage 没有数据的图片
 */
- (void)configureTipViewWithTipMessage:(NSString *)tipString
                               hasData:(BOOL)hasData
                           noDataImage:(UIImage *)noDataImage;

/**
 *  配置一个TipView(新增：添加网络错误时候的可点击刷新按钮)
 *
 *  @param tipString 提示信息
 *  @param hasData   是否有数据
 *  @param hasError  是否有错误
 *  @param block     按钮回调
 */
- (void)configureTipViewWithTipMessage:(NSString *)tipString
                               hasData:(BOOL)hasData
                              hasError:(BOOL)hasError
                     reloadButtonBlock:(void (^)(id sender))block;

/**
 *  配置一个TipView(新增：添加自定义Frame)
 *
 *  @param frame        Frame
 *  @param tipString    提示信息
 *  @param noDataImage  没有数据的图片
 *  @param hasData      是否有数据
 *  @param hasError     是否有错误
 *  @param block        按钮回调
 */
- (void)configureTipViewWithFrame:(CGRect)frame
                       tipMessage:(NSString *)tipString
                      noDataImage:(UIImage *)noDataImage
                          hasData:(BOOL)hasData
                         hasError:(BOOL)hasError
                reloadButtonBlock:(void (^)(id sender))block;

/**
 配置一个TipView
 
 @param error   error
 @param hasData 是否有数据
 @param block   按钮回调
 */
- (void)configureTipViewWithError:(NSError *)error
                          hasData:(BOOL)hasData
                reloadButtonBlock:(void (^)(id sender))block;

@end

@interface TipView : UIView

- (void)tipViewWithTipMessag:(NSString *)tipString
                     hasData:(BOOL)hasData
                 noDataImage:(UIImage *)noDateImage
                    hasError:(BOOL)hasError
                  errorImage:(UIImage *)errorImage
           reloadButtonBlock:(void (^)(id))block;

@end
