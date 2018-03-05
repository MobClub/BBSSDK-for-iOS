//
//  MOBSDKKeyModel.m
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import "MOBSDKKeyModel.h"
#import "MOBAESHelper.h"
#import "MOBLibsContext.h"
/*
ShareSDK =         {
    QQ =             {
        AppKey = 1106559702;
        AppSecret = BZb8GfEO1WWz2LWw;
    };
    SinaWeibo =             {
        AppKey = 1715635922;
        AppSecret = 89c715a733c8966a7c5ef01ce01af346;
        RedirectUri = "http://www.mob.com";
    };
    WeChat =             {
        AppKey = wxd7022e7c3ae69877;
        AppSecret = fbf8566435d677ed559de6e5bdcfd471;
    };
};
*/
@implementation MOBSDKKeyModel

- (instancetype)initWithDict:(NSDictionary *)dict mobAppSecret:(NSString *)mobAppSecret
{
    self = [super init];
    if (self)
    {
        if ([MOBLibsContext sharedInstance].debugLog)
        {
            NSLog(@"%@", dict);
        }
        
        NSDictionary *shareSDKDict = dict[@"ShareSDK"];
        
        NSDictionary *qqDict = shareSDKDict[@"QQ"];
        if ([qqDict isKindOfClass:[NSDictionary class]])
        {
            self.qqAppId = qqDict[@"AppKey"];
            // 解密
            NSString *decondStr = qqDict[@"AppSecret"];
            self.qqAppSecret = [MOBAESHelper aesDecryptString:decondStr key:mobAppSecret];
        }
        
        NSDictionary *wechatDict = shareSDKDict[@"WeChat"];
        if ([wechatDict isKindOfClass:[NSDictionary class]])
        {
            self.weChatAppId = wechatDict[@"AppKey"];
            // 解密
            NSString *decondStr = wechatDict[@"AppSecret"];
            self.weChatAppSecret = [MOBAESHelper aesDecryptString:decondStr key:mobAppSecret];
        }
        
        NSDictionary *weiboDict = shareSDKDict[@"SinaWeibo"];
        if ([weiboDict isKindOfClass:[NSDictionary class]])
        {
            self.weiBoAppKey = weiboDict[@"AppKey"];
            // 解密
            NSString *decondStr = weiboDict[@"AppSecret"];
            self.weiBoAppSecret = [MOBAESHelper aesDecryptString:decondStr key:mobAppSecret];
            self.weiBoRedirectUri = weiboDict[@"RedirectUri"];
        }
    }
    return self;
}

@end
