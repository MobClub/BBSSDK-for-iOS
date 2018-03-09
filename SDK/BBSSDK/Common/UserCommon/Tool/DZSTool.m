//
//  DZSTool.m
//  BBSSDKUI
//
//  Created by liyc on 2017/2/21.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "DZSTool.h"

@implementation DZSTool

+ (NSString *)dateStringFromTimeInterval:(NSTimeInterval)timeInterval
{
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:timeInterval];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc]init];
    
    //设定时间格式,这里可以设置成自己需要的格式
    [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm"];
    NSString*currentDateStr = [dateFormatter stringFromDate:date];
    
    return currentDateStr;
}

@end
