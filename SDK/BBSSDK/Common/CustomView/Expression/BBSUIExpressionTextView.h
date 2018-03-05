//
//  WKExpressionTextView.h
//  WKExpressionInput
//
//  Created by chuxiao on 2017/10/13.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BBSUIExpressionTextView;
@protocol BBSUIExpressionTextViewDelegate <UITextViewDelegate>

/**
 有内容输入
 */
- (void)expressionTextDidChange:(BBSUIExpressionTextView *)textView textLength:(NSInteger)length;

@end


@interface BBSUIExpressionTextView : UITextView 

@property (nonatomic, strong) NSString *originalString;//用于粘贴复制的字符串
@property (nonatomic, assign) CGFloat defaultFontSize;
@property (nonatomic, weak) id<BBSUIExpressionTextViewDelegate> expressionDelegate;


- (void)setExpressionWithImageName:(NSString *)imageName fontSize:(CGFloat)fontSize;

- (void)textChanged;

- (NSString *)parseAttributeTextToNormalString:(NSAttributedString *)attributedString;

@end
