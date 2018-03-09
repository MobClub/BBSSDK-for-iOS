//
//  WKExpressionTool.m
//  WKExpressionInput
//
//  Created by chuxiao on 2017/10/13.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUIExpressionTool.h"
#import "BBSUIExpressionViewConfiguration.h"
static NSDictionary *expressionDictionary;
@implementation BBSUIExpressionTool

+ (NSAttributedString *)generateAttributeStringWithOriginalString:(NSString *)originalString fontSize:(CGFloat)fontSize
{
    NSError *error = NULL;
    NSMutableAttributedString *resultAttrString = [[NSMutableAttributedString alloc] initWithString:originalString];
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"\\[[a-zA-Z0-9\u4e00-\u9fa5]{1,}\\]" options:NSRegularExpressionAllowCommentsAndWhitespace error:&error];
    

    NSArray *results = [regex matchesInString:originalString options:NSMatchingReportCompletion range:NSMakeRange(0, originalString.length)];
    if (results) {
        for (NSTextCheckingResult *result in results.reverseObjectEnumerator) {
            NSRange resultRange = [result rangeAtIndex:0];
            
            NSString *stringResult = [originalString substringWithRange:resultRange];
            
            NSLog(@"%s %@\n", __FUNCTION__, stringResult);
            
            NSAttributedString *expressionAttrString = [self getAttributeStringWithExpressionString:stringResult fontSize:fontSize];
            
            [resultAttrString replaceCharactersInRange:resultRange withAttributedString:expressionAttrString];
        }
        
    }
    return resultAttrString;
}

+ (NSString *)getExpressionStringWithImageName:(NSString *)imageName
{
    static NSDictionary *dicExpressions = nil;
    if (! dicExpressions)
    {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"BBSSDKUI.bundle/Emoji/emoji" ofType:@"json"];
        
        // 根据文件路径读取数据
        NSData *jdata = [[NSData alloc] initWithContentsOfFile:path];
        
        // 格式化成json数据
        dicExpressions = [NSJSONSerialization JSONObjectWithData:jdata options:kNilOptions error:nil];
    }
    
    if (dicExpressions[@"default"][imageName])
    {
        return dicExpressions[@"default"][imageName];
    }
    if (dicExpressions[@"coolmonkey"][imageName])
    {
        return dicExpressions[@"coolmonkey"][imageName];
    }
    if (dicExpressions[@"grapeman"][imageName])
    {
        return dicExpressions[@"grapeman"][imageName];
    }

    return @"";
}

/**
 *  通过表情生成富文本
 *
 *  @param expressionString 表情名
 *  @param fontSize         对应字体大小
 *
 *  @return 富文本
 */
+ (NSAttributedString *)getAttributeStringWithExpressionString:(NSString *)expressionString fontSize:(CGFloat)fontSize
{
   
    NSString *imageName = [self getExpressionStringWithImageName:expressionString];
    
    BBSUIExpressionTextAttachment *attachment = [[BBSUIExpressionTextAttachment alloc] initWithData:nil ofType:nil];
    UIImage *image = [UIImage imageNamed:imageName];
    attachment.image = image;
    attachment.text = [BBSUIExpressionTool getExpressionStringWithImageName:imageName];
    attachment.bounds = CGRectMake(0, 0, fontSize, fontSize);
    NSAttributedString *appendAttributeStr = [NSAttributedString attributedStringWithAttachment:attachment];
    
    return appendAttributeStr;

}

- (NSString *)getImageNameWithExpressionName:(NSString *)expressionName
{
    if (!expressionDictionary) {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"ExpressionNameList.plist" ofType:nil];
        expressionDictionary = [NSDictionary dictionaryWithContentsOfFile:path];
    }
    NSString *imageName = expressionDictionary[expressionName];
    
    return imageName;
}

@end
