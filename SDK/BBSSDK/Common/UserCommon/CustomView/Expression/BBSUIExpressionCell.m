//
//  WKExpressionCell.m
//  WKExpressionInput
//
//  Created by chuxiao on 2017/10/13.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUIExpressionCell.h"
#import "BBSUIExpressionViewConfiguration.h"
#import "UIImage+GIF.h"

@implementation BBSUIExpressionCell

- (instancetype)initWithCoder:(NSCoder *)coder
{
    self = [super initWithCoder:coder];
    if (self) {

    }
    return self;
}

- (void)setExpressionName:(NSString *)expressionName
{
    _expressionName = expressionName;
    
    [self.contentView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
    
    NSString *name = expressionName;
    if ([name hasSuffix:@".gif"])
    {
        name = [expressionName substringToIndex:expressionName.length - 4];
    }
    name = [NSString stringWithFormat:@"BBSSDKUI.bundle/Emoji/%@",name];
    
    UIImageView *imgeView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)];
    
    NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:@"gif"];
    NSData *data = [NSData dataWithContentsOfFile:path];
    UIImage *image = [UIImage sd_animatedGIFWithData:data];

    imgeView.image = image;
    
    [self.contentView addSubview:imgeView];
}


- (UIImage *)scaleImage:(UIImage *)originalImage scale:(CGFloat)scale
{
    CGSize size = CGSizeMake(originalImage.size.width * scale, originalImage.size.height * scale);
    UIGraphicsBeginImageContext(size);
    
    [originalImage drawInRect:CGRectMake(0, 0, size.width, size.height)];
    
    UIImage *scaleImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return  scaleImage;
}

- (UIImage *)scaleImage:(UIImage *)originalImage toSize:(CGSize)size
{
    
    UIGraphicsBeginImageContextWithOptions(size, NO, 0.0);
    
    [originalImage drawInRect:CGRectMake(0, 0, size.width, size.height)];
    
    UIImage *scaleImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return  scaleImage;
}

@end
