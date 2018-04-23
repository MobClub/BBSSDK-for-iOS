//
//  BBSSDK+ShareSDK.h
//  BBSSDK
//
//  Created by wukx on 2018/4/19.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import "BBSSDK.h"
#import "BBSShareUser.h"

@interface BBSSDK (ShareSDK)

#pragma mark - 一下方法只适用于BBSSDKUI.framework使用
/**
 使用ShareSDK进行第三方授权
 
 @param authType 微信 = wechat；QQ = qq
 @param result   第三方登录返回结果
 */
+ (void)authLoginWithAuthType:(NSString *)authType
                       result:(void(^)(NSInteger state,BBSShareUser *shareUser, NSError *error))result;

/**
 使用ShareSDK 获取激活的平台列表
 
 */
+ (NSArray *)activePlatformsShareSDK;

/**
 使用ShareSDK 设置分享内容
 @param text     文本
 @param images   图片集合
 @param url      网页路径/应用路径
 @param title    标题
 @param type     分享类型
 @param dataDictionary 数据存储字典 如果传入nil将新建
 */
+ (NSMutableDictionary *) setupShareParamsByText:(NSString *)text
                                          images:(id)images
                                             url:(NSURL *)url
                                           title:(NSString *)title
                                            type:(NSInteger)type
                                  dataDictionary:(NSMutableDictionary *)dataDictionary;


/**
 *  使用ShareSDK 分享内容
 *
 *  @param platformType             平台类型
 *  @param parameters               分享参数
 *  @param stateChangedHandler       状态变更回调处理
 */
+ (void)share:(NSInteger)platformType
   parameters:(NSMutableDictionary *)parameters
onStateChanged:(void (^)(NSInteger state, NSDictionary *userData,  NSError *error))stateChangedHandler;

@end
