//
//  NSString+md5.m
//  BBSSDKUI
//
//  Created by liyc on 2017/3/6.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "NSString+md5.h"
#import<CommonCrypto/CommonDigest.h>

@implementation NSString (md5)

+(NSString *)md5:(NSString *)input
{
    const char *cStr = [input UTF8String];
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    CC_MD5( cStr, (CC_LONG)strlen(cStr), digest ); // This is the md5 call
    
    NSMutableString *output = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    
    for(int i = 0; i < CC_MD5_DIGEST_LENGTH; i++)
        [output appendFormat:@"%02x", digest[i]];
    
    return  output;
}

@end
