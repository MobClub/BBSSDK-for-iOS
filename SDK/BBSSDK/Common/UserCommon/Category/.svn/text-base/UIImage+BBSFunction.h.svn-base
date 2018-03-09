//
//  UIImage+BBSFunction.h
//  BBSSDKUI
//
//  Created by liyc on 2017/2/20.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (BBSFunction)

+ (UIImage*)BBSImageNamed:(NSString*)name;

// 回复和发帖之前的图片尺寸处理
- (UIImage *)scaleImage;

// 处理cell上的图片
- (void)processImageForCellResult:(void(^)(UIImage *image))result;

- (UIImage *)cropImageWithX:(CGFloat)x y:(CGFloat)y width:(CGFloat)width height:(CGFloat)height;

- (UIImage *)BBSImageRotation:(UIImageOrientation)orientation;

@end
