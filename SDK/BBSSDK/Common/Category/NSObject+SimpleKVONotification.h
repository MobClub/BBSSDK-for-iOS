//
//  NSObject+SimpleKVONotification.h
//  BBSSDKDemo
//
//  Created by chuxiao on 2017/9/6.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^KTKvoBlock)(__weak id obj, id oldValue, id newValue);
typedef void (^KTNotificationBlock)(NSNotification *notification);

@interface NSObject (SimpleKVONotification)

- (void)addObserverForKeyPath:(NSString *)keyPath block:(KTKvoBlock)block;
- (void)removeObserverBlocksForKeyPath:(NSString *)keyPath;
- (void)removeAllObserverBlocks;
- (void)addNotificationForName:(NSString *)name block:(KTNotificationBlock)block;
- (void)removeNotificationBlocksForName:(NSString *)name;
- (void)removeAllNotificationBlocks;

@end
