//
//  PopoverAction.m
//  Popover
//
//  Created by StevenLee on 2016/12/10.
//  Copyright © 2016年 lifution. All rights reserved.
//

#import "PopoverAction.h"

@interface PopoverAction ()

@property (nonatomic, strong, readwrite) UIImage *image; ///< 图标
@property (nonatomic, copy, readwrite) NSString *title; ///< 标题
@property (nonatomic, copy, readwrite) void(^handler)(PopoverAction *action); ///< 选择回调
@property (nonatomic, strong, readwrite) UIImage *deselectedImage;
@property (nonatomic, strong) UIColor *selectedColor;

@end

@implementation PopoverAction

+ (instancetype)actionWithTitle:(NSString *)title handler:(void (^)(PopoverAction *action))handler {
    return [self actionWithSelectedImage:nil deselectedImage:nil title:title handler:handler];
}

+ (instancetype)actionWithImage:(UIImage *)image title:(NSString *)title handler:(void (^)(PopoverAction *action))handler {
    
    
    return [self actionWithSelectedImage:image deselectedImage:nil title:title handler:handler];
}

+ (instancetype)actionWithSelectedImage:(UIImage *)image deselectedImage:(UIImage *)deselectedImage title:(NSString *)title handler:(void (^)(PopoverAction *action))handler
{
    return [self actionWithSelectedImage:image deselectedImage:deselectedImage title:title selectedTitleColor:nil handler:handler];
}

+ (instancetype)actionWithSelectedImage:(UIImage *)image deselectedImage:(UIImage *)deselectedImage title:(NSString *)title selectedTitleColor:(UIColor *)titleColor handler:(void (^)(PopoverAction *))handler
{
    PopoverAction *action = [[self alloc] init];
    action.image = image;
    action.deselectedImage = deselectedImage;
    action.title = title ? : @"";
    action.handler = handler ? : NULL;
    action.selectedColor = titleColor;
    
    return action;
}

@end
