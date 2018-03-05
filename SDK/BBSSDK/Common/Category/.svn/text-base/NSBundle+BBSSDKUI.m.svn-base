//
//  NSBundle+BBSSDKUI.m
//  BBSSDKUI
//
//  Created by liyc on 2017/2/20.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "NSBundle+BBSSDKUI.h"

@implementation NSBundle (BBSSDKUI)

+(NSBundle *)bbsLoadBundle
{
    static NSBundle *bbsBundle = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        bbsBundle = [[NSBundle alloc] initWithPath:[[NSBundle mainBundle] pathForResource:@"BBSSDKUI" ofType:@"bundle"]];
    });
    return bbsBundle;
}

@end
