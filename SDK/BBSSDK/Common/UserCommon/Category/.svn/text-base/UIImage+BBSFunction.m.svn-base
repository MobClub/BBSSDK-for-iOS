//
//  UIImage+BBSFunction.m
//  BBSSDKUI
//
//  Created by liyc on 2017/2/20.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "UIImage+BBSFunction.h"
#import "NSBundle+BBSSDKUI.h"

@implementation UIImage (BBSFunction)

+(UIImage *)BBSImageNamed:(NSString *)name
{
    if ([NSBundle bbsLoadBundle] == [NSBundle mainBundle]) {
        
        return [UIImage imageNamed:name];
    }
    
    NSRange range = [name rangeOfString:[NSString stringWithFormat:@".%@",[name pathExtension]]];
    if (range.location != NSNotFound)
    {
        NSString *fileName = [name substringToIndex:range.location];
        NSString *path = [[NSBundle bbsLoadBundle] pathForResource:fileName ofType:[name pathExtension]];
        return [UIImage imageWithContentsOfFile:path];
    }
    
    return nil;
}

- (UIImage *)scaleImage
{
    CGSize size = CGSizeMake(CGImageGetWidth(self.CGImage), CGImageGetHeight(self.CGImage));
    
    CGSize scaled;
    
    if (size.height/size.width<2 && size.height/size.width>1 && size.height > 1280)
    {
        scaled.height = 1280;
        scaled.width = size.width *(1280.0/size.height);
    }
    else if (size.width/size.height<2 && size.width/size.height>1 && size.width > 1280)
    {
        scaled.width = 1280;
        
        scaled.height = size.height * (1280.0/size.width);
    }
    else if (size.height/size.width>2 && size.width>720)
    {
        scaled.width = 720 ;
        scaled.height = size.height *(720.0/size.width);
    }
    else if (size.width/size.height>2 && size.height>720)
    {
        scaled.height = 720;
        scaled.width = size.width *(720.0/size.height);
    }
    else
    {
        scaled = size ;
    }
    
    CGFloat rate = size.width/self.size.width;
    
    CGSize scaleSize = CGSizeMake(scaled.width/rate, scaled.height/rate);
    
    UIGraphicsBeginImageContext(scaleSize);
    // 绘制改变大小的图片
    [self drawInRect:CGRectMake(0,0, scaleSize.width, scaleSize.height)];
    // 从当前context中创建一个改变大小后的图片
    UIImage* scaledImage =UIGraphicsGetImageFromCurrentImageContext();
    // 使当前的context出堆栈
    UIGraphicsEndImageContext();

//     CGSize endSize = CGSizeMake(CGImageGetWidth(scaledImage.CGImage), CGImageGetHeight(scaledImage.CGImage));
    
//    NSLog(@"%@",NSStringFromCGSize(endSize));
    
    return scaledImage;
}

- (void)processImageForCellResult:(void(^)(UIImage *image))result
{
    CGRect rect ;
    
    CGFloat imageWidth = self.size.width;
    CGFloat imageHeight = self.size.height;
    
    if (imageWidth > imageHeight)
    {
        rect.origin.x = (imageWidth - imageHeight)/2.0;
        rect.origin.y = 0;
        rect.size.width = imageHeight;
        rect.size.height = imageHeight;
    }
    else
    {
        rect.origin.x = 0;
        rect.origin.y = (imageHeight - imageWidth)/2.0;;
        rect.size.width = imageWidth;
        rect.size.height = imageWidth;
    }
    
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
       
        CGImageRef newImageRef = CGImageCreateWithImageInRect(self.CGImage, rect);
        
        UIImage *newImage = [UIImage imageWithCGImage:newImageRef];
        
        if (result)
        {
            result(newImage);
        }
    });
}

- (UIImage *)cropImageWithX:(CGFloat)x y:(CGFloat)y width:(CGFloat)width height:(CGFloat)height {
    CGRect rect = CGRectMake(x, y, width, height);
    CGImageRef imageRef = CGImageCreateWithImageInRect(self.CGImage, rect);
    UIImage *image = [UIImage imageWithCGImage:imageRef];
    return image;
}

- (UIImage *)BBSImageRotation:(UIImageOrientation)orientation
{
    long double rotate = 0.0;
    CGRect rect;
    float translateX = 0;
    float translateY = 0;
    float scaleX = 1.0;
    float scaleY = 1.0;
    
    switch (orientation) {
        case UIImageOrientationLeft:
            rotate = M_PI_2;
            rect = CGRectMake(0, 0, self.size.height, self.size.width);
            translateX = 0;
            translateY = -rect.size.width;
            scaleY = rect.size.width/rect.size.height;
            scaleX = rect.size.height/rect.size.width;
            break;
        case UIImageOrientationRight:
            rotate = 3 * M_PI_2;
            rect = CGRectMake(0, 0, self.size.height, self.size.width);
            translateX = -rect.size.height;
            translateY = 0;
            scaleY = rect.size.width/rect.size.height;
            scaleX = rect.size.height/rect.size.width;
            break;
        case UIImageOrientationDown:
            rotate = M_PI;
            rect = CGRectMake(0, 0, self.size.width, self.size.height);
            translateX = -rect.size.width;
            translateY = -rect.size.height;
            break;
        default:
            rotate = 0.0;
            rect = CGRectMake(0, 0, self.size.width, self.size.height);
            translateX = 0;
            translateY = 0;
            break;
    }
    
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    //做CTM变换
    CGContextTranslateCTM(context, 0.0, rect.size.height);
    CGContextScaleCTM(context, 1.0, -1.0);
    CGContextRotateCTM(context, rotate);
    CGContextTranslateCTM(context, translateX, translateY);
    
    CGContextScaleCTM(context, scaleX, scaleY);
    //绘制图片
    CGContextDrawImage(context, CGRectMake(0, 0, rect.size.width, rect.size.height), self.CGImage);
    
    UIImage *newPic = UIGraphicsGetImageFromCurrentImageContext();
    
    return newPic;
}

@end
