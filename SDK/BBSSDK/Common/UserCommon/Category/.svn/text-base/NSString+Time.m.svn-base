//
//  NSString+Time.m
//  BBSSDKUI
//
//  Created by chuxiao on 2017/8/22.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "NSString+Time.h"

@implementation NSString (Time)

+ (NSString *)timeTextWithOffset:(NSInteger)offset
{
    NSInteger year = 365 * 24 * 60 * 60 ;
    NSInteger month = 30 * 24 * 60 * 60 ;
    NSInteger day = 24 * 60 * 60 ;
    NSInteger hour = 60 * 60 ;
    NSInteger min = 60 ;
    
    if (offset/year)
    {
        return [NSString stringWithFormat:@"%zd年前",offset/year];
    }
    
    if (offset/month)
    {
        return [NSString stringWithFormat:@"%zd月前",offset/month];
    }
    
    if (offset/day)
    {
        return [NSString stringWithFormat:@"%zd天前",offset/day];
    }
    
    if (offset/hour)
    {
        return [NSString stringWithFormat:@"%zd小时前",offset/hour];
    }
    
    if (offset/min)
    {
        return [NSString stringWithFormat:@"%zd分钟前",offset/min];
    }
    
    return [NSString stringWithFormat:@"%zd秒前",offset];
}

+ (NSString *)timeTextWithTimesStamp:(double)timesStamp
{
    NSTimeInterval now = [[NSDate date]timeIntervalSince1970];
    double distanceTime = now - timesStamp;
    NSString * distanceStr;
    
    NSDate * beDate = [NSDate dateWithTimeIntervalSince1970:timesStamp];
    NSDateFormatter * df = [[NSDateFormatter alloc]init];
    [df setDateFormat:@"HH:mm"];
    NSString * timeStr = [df stringFromDate:beDate];
    
    [df setDateFormat:@"dd"];
    NSString * nowDay = [df stringFromDate:[NSDate date]];
    NSString * lastDay = [df stringFromDate:beDate];
    
    if (distanceTime < 60)
    {//小于一分钟
        distanceStr = @"刚刚";
    }
    else if (distanceTime <60*60)
    {//时间小于一个小时
        distanceStr = [NSString stringWithFormat:@"%ld分钟前",(long)distanceTime/60];
    }
    else if(distanceTime <24*60*60 && [nowDay integerValue] == [lastDay integerValue])
    {//时间小于一天
        distanceStr = [NSString stringWithFormat:@"%ld小时前",(long)distanceTime/60/60];
    }
    else if(distanceTime<24*60*60*2 && [nowDay integerValue] != [lastDay integerValue])
    {
        
        if ([nowDay integerValue] - [lastDay integerValue] ==1 || ([lastDay integerValue] - [nowDay integerValue] > 10 && [nowDay integerValue] == 1))
        {
            distanceStr = [NSString stringWithFormat:@"昨天 %@",timeStr];
        }
        else
        {
            [df setDateFormat:@"MM-dd HH:mm"];
            distanceStr = [df stringFromDate:beDate];
        }
        
    }
    else if(distanceTime <24*60*60*365)
    {
        [df setDateFormat:@"MM-dd HH:mm"];
        distanceStr = [df stringFromDate:beDate];
    }
    else
    {
        [df setDateFormat:@"yyyy-MM-dd HH:mm"];
        distanceStr = [df stringFromDate:beDate];
    }
    return distanceStr;
}


@end
