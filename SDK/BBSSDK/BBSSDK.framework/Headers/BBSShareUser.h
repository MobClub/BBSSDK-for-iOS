//
//  BBSShareUser.h
//  BBSSDK
//
//  Created by wukx on 2018/4/18.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BBSShareUser : NSObject

/**
 *  用户标识
 */
@property (nonatomic, copy) NSString *uid;

/**
 *  昵称
 */
@property (nonatomic, copy) NSString *nickname;

/**
 *  原始数据
 */
@property (nonatomic, strong) NSDictionary *rawData;

@end
