//
//  NSString+HTML.m
//  BBSSDKUI
//
//  Created by liyc on 2017/9/14.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "NSString+HTML.h"
#import <UIKit/UIKit.h>

@implementation NSString (HTML)

+ (NSString *)attriToStrWithAttri:(NSAttributedString *)attri{
    NSDictionary *tempDic = @{NSDocumentTypeDocumentAttribute:NSHTMLTextDocumentType,
                              NSCharacterEncodingDocumentAttribute:[NSNumber numberWithInt:NSUTF8StringEncoding]};
    NSData *htmlData = [attri dataFromRange:NSMakeRange(0, attri.length)
                         documentAttributes:tempDic
                                      error:nil];
    return [[NSString alloc] initWithData:htmlData
                                 encoding:NSUTF8StringEncoding];
}

+ (NSAttributedString *)strToAttriWithHtmlStr:(NSString *)htmlStr{
    return [[NSAttributedString alloc] initWithData:[htmlStr dataUsingEncoding:NSUnicodeStringEncoding]
                                            options:@{NSDocumentTypeDocumentAttribute:NSHTMLTextDocumentType}
                                 documentAttributes:nil
                                              error:nil];
}


@end
