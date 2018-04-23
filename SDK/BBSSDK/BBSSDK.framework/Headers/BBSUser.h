//
//  BBSUser.h
//  BBSSDK
//
//  Created by youzu_Max on 2017/4/18.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BBSUser : NSObject

/**
 登录凭证
 */
@property (nonatomic, copy) NSString *token;

/**
 会员id
 */
@property (nonatomic, strong) NSNumber *uid;

/**
 会员昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 邮箱
 */
@property (nonatomic, copy) NSString *email;

/**
 用户名
 */
@property (nonatomic, copy) NSString *userName;

/**
 性别
 */
@property (nonatomic, strong) NSNumber *gender;

/**
 email是否经过验证
 */
@property (nonatomic, strong) NSNumber *emailStatus;

/**
 是否有头像
 */
@property (nonatomic, strong) NSNumber *avatarStatus;

/**
 注册时间
 */
@property (nonatomic, strong) NSNumber *regDate;

/**
 用户组id
 */
@property (nonatomic, strong) NSNumber *groupId;

/**
 用户头像url
 */
@property (nonatomic, copy) NSString *avatar;

/**
 用户组名
 */
@property (nonatomic, copy) NSString *groupName;

/**
 阅读权限
 */
@property (nonatomic, strong) NSNumber *readAccess;

/**
 允许发帖
 */
@property (nonatomic, strong) NSNumber *allowPost;

/**
 允许回复
 */
@property (nonatomic, strong) NSNumber *allowReply;

/**
 收藏数
 */
@property (nonatomic, strong) NSNumber *favorites;

/**
 粉丝数
 */
@property (nonatomic, strong) NSNumber *followers;

/**
 个人帖子数
 */
@property (nonatomic, strong) NSNumber *threads;

/**
 关注数
 */
@property (nonatomic, strong) NSNumber *firends;

/**
 出生年
 */
@property (nonatomic, strong) NSNumber *birthyear;

/**
 出生月
 */
@property (nonatomic, strong) NSNumber *birthmonth;

/**
 出生日
 */
@property (nonatomic, strong) NSNumber *birthday;

/**
 居住省份
 */
@property (nonatomic, copy) NSString *resideprovince;

/**
 居住城市
 */
@property (nonatomic, copy) NSString *residecity;

/**
 居住行政区
 */
@property (nonatomic, copy) NSString *residedist;

/**
 居住小区
 */
@property (nonatomic, copy) NSString *residecommunity;

/**
 居住小区、写字楼门牌号
 */
@property (nonatomic, copy) NSString *residesuite;

/**
 签名
 */
@property (nonatomic, copy) NSString *sightml;

/**
 消息数
 */
@property (nonatomic, strong) NSNumber *notices;

/**
 是否已经关注了他
 */
@property (nonatomic, strong) NSNumber *follow;

/**
 是否允许匿名发帖
 */
@property (nonatomic, strong) NSNumber *allowAnonymous;

/**
 签到入口地址 当authorid为空的时候提供
 */
@property (nonatomic, copy) NSString *signurl;

/**
 根据res字典初始化属性
 */
- (void) setValueForPropertiesWithDictionary:(NSDictionary *)res;

@end
