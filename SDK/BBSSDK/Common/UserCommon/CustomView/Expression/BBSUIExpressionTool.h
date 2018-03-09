//
//  WKExpressionTool.h
//  WKExpressionInput
//
//  Created by chuxiao on 2017/10/13.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BBSUIExpressionTool : NSObject

+ (NSAttributedString *)generateAttributeStringWithOriginalString:(NSString *)originalString fontSize:(CGFloat)fontSize;

+ (NSString *)getExpressionStringWithImageName:(NSString *)imageName;

@end
