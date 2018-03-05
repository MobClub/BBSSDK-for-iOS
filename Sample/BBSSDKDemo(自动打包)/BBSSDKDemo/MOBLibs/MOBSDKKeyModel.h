//
//  MOBSDKKeyModel.h
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOBSDKKeyModel : NSObject

/**
 微信 AppId
 */
@property (nonatomic, copy) NSString *weChatAppId;

/**
 微信 AppSecret
 */
@property (nonatomic, copy) NSString *weChatAppSecret;

/**
 qq AppSecret
 */
@property (nonatomic, copy) NSString *qqAppId;

/**
 qq AppSecret
 */
@property (nonatomic, copy) NSString *qqAppSecret;

/**
 WeiBo AppKey
 */
@property (nonatomic, copy) NSString *weiBoAppKey;

/**
 WeiBo AppSecret
 */
@property (nonatomic, copy) NSString *weiBoAppSecret;

/**
 WeiBo RedirectUri
 */
@property (nonatomic, copy) NSString *weiBoRedirectUri;

- (instancetype)initWithDict:(NSDictionary *)dict mobAppSecret:(NSString *)mobAppSecret;

@end
