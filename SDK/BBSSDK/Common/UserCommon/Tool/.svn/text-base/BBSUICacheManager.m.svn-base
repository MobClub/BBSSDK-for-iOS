//
//  BBSUICacheManager.m
//  BBSSDKUI
//
//  Created by liyc on 2017/4/24.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUICacheManager.h"

#define CACHE_BASE_PATH(path) [NSString stringWithFormat:@"%@/Library/Caches/%@", NSHomeDirectory(), path]

static const NSString *BBSUIStickForumsCacheName = @"StickForums";
static const NSString *BBSUISearchHistoryCacheName = @"SearchHistory";
static const NSString *BBSUILikedThreadCacheName = @"LikedThread";

@implementation BBSUICacheManager

//@synthesize stickForums = _stickForums;
@synthesize searchHistories = _searchHistories;

+ (BBSUICacheManager *)sharedInstance
{
    static BBSUICacheManager *sharedCache = nil;
    static dispatch_once_t sharedCachePredicate;
    dispatch_once(&sharedCachePredicate, ^{
        
        sharedCache = [[BBSUICacheManager alloc] init];
        
    });
    
    return sharedCache;
}

//- (NSArray *)stickForums
//{
//    if (!_stickForums)
//    {
//        @try
//        {
//            _stickForums = [NSKeyedUnarchiver unarchiveObjectWithFile:CACHE_BASE_PATH(BBSUIStickForumsCacheName)];
//        }
//        @catch (NSException *exception)
//        {
//            
//        }
//    }
//    
//    return _stickForums;
//}
//
//
//- (void)setStickForums:(NSArray *)stickForums
//{
//    _stickForums = stickForums;
//    
//    //写入缓存
//    NSString *path = CACHE_BASE_PATH(BBSUIStickForumsCacheName);
//    if (_stickForums)
//    {
//        @try
//        {
//            [NSKeyedArchiver archiveRootObject:_stickForums
//                                        toFile:path];
//        }
//        @catch (NSException *exception)
//        {
//            
//        }
//    }
//    else
//    {
//        [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
//    }
//}

- (NSArray *)getStickForumsWithUid:(NSNumber *)uid
{
    @try
    {
        NSString *cachePath = [NSString stringWithFormat:@"%@_%@",BBSUIStickForumsCacheName,uid];
        _stickForums = [NSKeyedUnarchiver unarchiveObjectWithFile:CACHE_BASE_PATH(cachePath)];
    }
    @catch (NSException *exception)
    {
        
    }
    
    return _stickForums;
}

- (void)setStickForums:(NSArray *)stickForums uid:(NSNumber *)uid
{
    _stickForums = stickForums;
    
    NSString *cachePath = [NSString stringWithFormat:@"%@_%@",BBSUIStickForumsCacheName,uid];
    NSString *path = CACHE_BASE_PATH(cachePath);
    if (_stickForums)
    {
        @try
        {
            [NSKeyedArchiver archiveRootObject:_stickForums
                                        toFile:path];
        }
        @catch (NSException *exception)
        {
            
        }
    }
    else
    {
        [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
    }
}

- (NSArray *)searchHistories {
    @try
    {
        _searchHistories = [NSKeyedUnarchiver unarchiveObjectWithFile:CACHE_BASE_PATH(BBSUISearchHistoryCacheName)];
    }
    @catch (NSException *exception)
    {
        
    }
    return _searchHistories;
}

- (void)setSearchHistories:(NSArray<NSString *> *)searchHistories
{
    _searchHistories = searchHistories;
    
    NSString *path = CACHE_BASE_PATH(BBSUISearchHistoryCacheName);
    if (_searchHistories)
    {
        @try
        {
            [NSKeyedArchiver archiveRootObject:_searchHistories
                                        toFile:path];
        }
        @catch (NSException *exception)
        {
            
        }
    }
    else
    {
        [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
    }
}

- (NSArray *)getSearchHistoriesWithUid:(NSNumber *)uid{
    @try
    {
        NSString *cachePath = [NSString stringWithFormat:@"%@_%@",BBSUISearchHistoryCacheName,uid];
        _searchHistories = [NSKeyedUnarchiver unarchiveObjectWithFile:CACHE_BASE_PATH(cachePath)];
    }
    @catch (NSException *exception)
    {
        
    }
    return _searchHistories;
}

- (void)setSearchHistories:(NSArray *)histories Uid:(NSNumber *)uid{
    _searchHistories = histories;
    
    NSString *cachePath = [NSString stringWithFormat:@"%@_%@",BBSUISearchHistoryCacheName,uid];
    NSString *path = CACHE_BASE_PATH(cachePath);
    if (_searchHistories)
    {
        @try
        {
            [NSKeyedArchiver archiveRootObject:_searchHistories
                                        toFile:path];
        }
        @catch (NSException *exception)
        {
            
        }
    }
    else
    {
        [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
    }
}

- (NSMutableDictionary *)getLikedThreadDictionaryWithUid:(NSNumber *)uid
{
    NSDictionary *tmpLikedThreadDic = [NSDictionary dictionary];
    @try
    {
        NSString *cachePath = [NSString stringWithFormat:@"%@_%@",BBSUILikedThreadCacheName,uid];
        tmpLikedThreadDic = [NSKeyedUnarchiver unarchiveObjectWithFile:CACHE_BASE_PATH(cachePath)];
    }
    @catch (NSException *exception)
    {
        
    }
    
    if (!_likedThreadDictionary) {
        _likedThreadDictionary = [NSMutableDictionary dictionaryWithDictionary:tmpLikedThreadDic];
    }
    
    return _likedThreadDictionary;
}

- (void)setLikedThreadDictionary:(NSMutableDictionary *)likedThreadDictionary uid:(NSNumber *)uid
{
    _likedThreadDictionary = likedThreadDictionary;
    
    NSString *cachePath = [NSString stringWithFormat:@"%@_%@",BBSUILikedThreadCacheName,uid];
    NSString *path = CACHE_BASE_PATH(cachePath);
    if (_likedThreadDictionary)
    {
        @try
        {
            [NSKeyedArchiver archiveRootObject:_likedThreadDictionary
                                        toFile:path];
        }
        @catch (NSException *exception)
        {
            
        }
    }
    else
    {
        [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
    }
}

@end
