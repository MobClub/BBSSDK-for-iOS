//
//  UIView+VisualEffects.m
//  BBSSDKUI
//
//  Created by chuxiao on 2017/9/5.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "UIView+VisualEffects.h"

@implementation UIView (VisualEffects)

- (void)backgroundImageWithImage:(UIImage *)image
{
    UIGraphicsBeginImageContext(self.frame.size);
    [image drawInRect:self.bounds];
    UIImage *imageGraphics = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    self.backgroundColor = [UIColor colorWithPatternImage:imageGraphics];
}

- (void)addVisualEffectView
{
    UIBlurEffect *effect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleLight];
    UIVisualEffectView *effectView = [[UIVisualEffectView alloc] initWithEffect:effect];
    effectView.backgroundColor = [UIColor colorWithRed:34/255.0 green:35/255.0 blue:70/255.0 alpha:0.5];
    
    effectView.frame = self.frame;
    [self addSubview:effectView];
}

@end
