//
//  WKExpressionView.h
//  WKExpressionInput
//
//  Created by chuxiao on 2017/10/13.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>
@class BBSUIExpressionView;
@protocol BBSUIExpressionViewDelegate <NSObject>

/**
 点选表情
 */
- (void)expressionView:(BBSUIExpressionView *)expressionView didSelectImageName:(NSString *)imageName;

/**
 删除按钮点击
 */
- (void)expressionViewDidSelectDeleteButton:(BBSUIExpressionView *)expressionView;

/**
 发送按钮点击
 */
- (void)expressionViewDidSelectSendButton:(BBSUIExpressionView *)expressionView;
@end

@interface BBSUIExpressionView : UIView

@property (strong, nonatomic) UICollectionView *collectionView;

@property (weak, nonatomic) id<BBSUIExpressionViewDelegate> delegate;

/**
 *  点击发送按button
 *
 *  @param sender 发送button
 */
- (IBAction)didSelectSendButton:(id)sender;

/**
 *  设置发送按钮状态
 *
 *  @param enable 是否可选
 */
- (void)setSendButtonState:(BOOL)enabled;

@end
