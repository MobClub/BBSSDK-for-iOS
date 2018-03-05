//
//  MSCConnection.h
//  MSC
//
//  Created by 冯鸿杰 on 2017/10/9.
//  Copyright © 2017年 Mob. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 MSC连接器，主要用于与服务器进行交互并获取数据。
 */
@interface MSCConnection : NSObject

/**
 获取共享的MSC连接器

 @return MSC连接器实例对象
 */
+ (instancetype)sharedConnection;

@end
