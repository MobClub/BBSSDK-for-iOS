//
//  BBSUICacheManager.h
//  BBSSDKUI
//
//  Created by liyc on 2017/4/24.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BBSUICacheManager : NSObject

+ (BBSUICacheManager *)sharedInstance;

/**
 置顶版块
 */
@property (nonatomic, strong) NSArray *stickForums;

/**
 搜索历史
 */
@property (nonatomic, strong) NSArray<NSString *> *searchHistories;

/**
 是否喜欢//本地存储
 */
@property (nonatomic, strong) NSMutableDictionary *likedThreadDictionary;

- (NSMutableDictionary *)getLikedThreadDictionaryWithUid:(NSNumber *)uid;
- (void)setLikedThreadDictionary:(NSMutableDictionary *)likedThreadDictionary uid:(NSNumber *)uid;

- (NSArray *)getStickForumsWithUid:(NSNumber *)uid;
- (void)setStickForums:(NSArray *)stickForums uid:(NSNumber *)uid;

- (NSArray *)getSearchHistoriesWithUid:(NSNumber *)uid;
- (void)setSearchHistories:(NSArray *)histories Uid:(NSNumber *)uid;
@end
