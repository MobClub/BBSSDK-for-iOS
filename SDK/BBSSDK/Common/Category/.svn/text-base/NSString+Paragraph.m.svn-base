//
//  NSString+Paragraph.m
//  BBSSDKUI
//
//  Created by chuxiao on 2017/8/28.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "NSString+Paragraph.h"

@implementation NSString (Paragraph)

+ (NSMutableAttributedString *)stringWithString:(NSString *)string fontSize:(CGFloat)size defaultColorValue:(NSString *)defaultColorValue lineSpace:(CGFloat)lineSpace wordSpace:(CGFloat)wordSpace
{
    if (! string)
    {
        string = @"";
    }
    
    NSString *h5String;
    if (defaultColorValue)
        h5String = [NSString stringWithFormat:@"<span style=\"color:%@\">%@</span>",defaultColorValue,string];
    else
        h5String = string;
    
    NSDictionary *optoins=@{NSDocumentTypeDocumentAttribute:NSHTMLTextDocumentType};
    
    NSData *data = [h5String dataUsingEncoding:NSUnicodeStringEncoding];
    
    NSMutableAttributedString *str = [[NSMutableAttributedString alloc] initWithData:data
                                                                             options:optoins
                                                                  documentAttributes:nil
                                                                               error:nil];
    
    UIFont *font = [UIFont systemFontOfSize:size];
    
    NSMutableParagraphStyle *paragrah = [[NSMutableParagraphStyle alloc] init];
    [paragrah setLineSpacing:lineSpace];
    
    if (size > 0) [str addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, str.length)];
    if (lineSpace > 0) [str addAttribute:NSParagraphStyleAttributeName value:paragrah range:NSMakeRange(0, str.length)];
    if (wordSpace > 0) [str addAttribute:NSKernAttributeName value:@(wordSpace) range:NSMakeRange(0, str.length)];
    
    return str;
}
@end
