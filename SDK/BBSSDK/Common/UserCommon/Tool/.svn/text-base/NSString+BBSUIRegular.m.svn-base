//
//  NSString+MAXCommon.m
//  CrazyStory
//
//  Created by youzu_Max on 2017/2/6.
//  Copyright © 2017年 youzu. All rights reserved.
//

#import "NSString+BBSUIRegular.h"

@implementation NSString (BBSUIRegular)

- (BOOL)isEmpty
{
    NSMutableString *str = [self mutableCopy];
    CFStringTrimWhitespace((__bridge CFMutableStringRef)str);
    return [str isEqualToString:@""];
}

//判断是否是手机号码或者邮箱
- (BOOL)isPhoneNumber
{
    NSString *phoneRegex = @"^1[3|4|5|7|8][0-9]\\d{8}$";
//    NSString *phoneRegex = @"^1(3[0-9]|4[57]|5[0-35-9]|7[0135678]|8[0-9])\\d{8}$" ;
    NSPredicate *phoneTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", phoneRegex];
    return [phoneTest evaluateWithObject:self];
}

- (BOOL)isEmail
{
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:self];
}

- (BOOL)isPassword
{
    BOOL matchLength = (self.length > 0 && self.length < 100);
    BOOL matchSymol1 = ([self rangeOfString:@"\\"].location == NSNotFound);
    BOOL matchSymol2 = ([self rangeOfString:@" "].location == NSNotFound);
    BOOL matchSymol3 = ([self rangeOfString:@"'"].location == NSNotFound);
    BOOL matchSymol4 = ([self rangeOfString:@"\""].location == NSNotFound);
    if (matchLength && matchSymol1 && matchSymol2 && matchSymol3 && matchSymol4)
    {
        return YES;
    }
    
    return NO;
}

- (BOOL)isUserName
{
    if (self.length>=3 && self.length<=15 && [self rangeOfString:@"@"].location == NSNotFound)
    {
        return YES;
    }
    else
    {
        return NO;
    }
}

+ (NSString *)localTimeStringWithDate:(NSDate *)date
{
    NSTimeZone *timeZone = [NSTimeZone timeZoneForSecondsFromGMT:8];
    NSTimeInterval interval = [timeZone secondsFromGMT];
    NSDate *GMTDate = [date dateByAddingTimeInterval:-interval];
    NSDateFormatter * dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"yyyy-MM-dd HH:mm:ss" ;
    NSString * dateStr = [dateFormatter stringFromDate:GMTDate];
    return dateStr ;
}

- (CGFloat)heightInTextViewWithFontSize:(CGFloat)fontSize width:(CGFloat)width
{
    UITextView *detailTextView = [[UITextView alloc]initWithFrame:CGRectMake(0, 0, width, 0)];
    detailTextView.font = [UIFont systemFontOfSize:fontSize];
    detailTextView.text = self;
    CGSize deSize = [detailTextView sizeThatFits:CGSizeMake(width,CGFLOAT_MAX)];
    return deSize.height;
}

- (NSInteger)charNumber{
    
    NSInteger strlength = 0;
    char* p = (char*)[self cStringUsingEncoding:NSUTF8StringEncoding];
    for (int i=0 ; i<[self lengthOfBytesUsingEncoding:NSUTF8StringEncoding] ;i++) {
        if (*p) {
            if(*p == '\xe4' || *p == '\xe5' || *p == '\xe6' || *p == '\xe7' || *p == '\xe8' || *p == '\xe9')
            {
                strlength--;
            }
            p++;
            strlength++;
        }
        else {
            p++;
        }
    }
    return strlength;
}

- (BOOL)isObjectID
{
    NSString *objectIDRegex = @"^[a-z0-9]{24}$";
    NSPredicate *objectIDTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", objectIDRegex];
    return [objectIDTest evaluateWithObject:self];
}

@end
