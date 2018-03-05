//
//  NSObject+SimpleKVONotification.m
//  BBSSDKDemo
//
//  Created by chuxiao on 2017/9/6.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "NSObject+SimpleKVONotification.h"
#import <objc/runtime.h>

@interface KTObserver : NSObject

@property (nonatomic, copy) KTKvoBlock kvoBlock;
@property (nonatomic, copy) KTNotificationBlock notificationBlock;

- (instancetype)initWithKvoBlock:(KTKvoBlock)kvoBlock;
- (instancetype)initWithNotificationBlock:(KTNotificationBlock)notificationBlock;
- (void)handleNotification:(NSNotification *)notification;

@end

@implementation KTObserver

- (instancetype)initWithKvoBlock:(KTKvoBlock)kvoBlock
{
    if (self = [super init]) {
        _kvoBlock = kvoBlock;
    }
    
    return self;
}

- (instancetype)initWithNotificationBlock:(KTNotificationBlock)notificationBlock
{
    if (self = [super init]) {
        _notificationBlock = notificationBlock;
    }
    
    return self;
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSString *,id> *)change context:(void *)context
{
    if (!self.kvoBlock) {
        return;
    }
    BOOL isPrior = [[change objectForKey:NSKeyValueChangeNotificationIsPriorKey] boolValue];
    if (isPrior) {
        return;
    }
    NSKeyValueChange changeKind = [[change objectForKey:NSKeyValueChangeKindKey] integerValue];
    if (changeKind != NSKeyValueChangeSetting) {
        return;
    }
    id oldVal = [change objectForKey:NSKeyValueChangeOldKey];
    if (oldVal == [NSNull null]) {
        oldVal = nil;
    }
    id newVal = [change objectForKey:NSKeyValueChangeNewKey];
    if (newVal == [NSNull null]) {
        newVal = nil;
    }
    if (oldVal != newVal) {
        self.kvoBlock(object, oldVal, newVal);
    }
}

- (void)handleNotification:(NSNotification *)notification
{
    if (self.notificationBlock) {
        self.notificationBlock(notification);
    }
}

@end

@implementation NSObject (SimpleKVONotification)

static const char KTKvoObserversKey = '\0';

- (void)addObserverForKeyPath:(NSString *)keyPath block:(KTKvoBlock)block
{
    if (!keyPath || !block) {
        return;
    }
    NSMutableDictionary *observersDict = objc_getAssociatedObject(self, &KTKvoObserversKey);
    if (!observersDict) {
        observersDict = [NSMutableDictionary dictionary];
        objc_setAssociatedObject(self, &KTKvoObserversKey, observersDict, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    NSMutableArray *observers = [observersDict objectForKey:keyPath];
    if (!observers) {
        observers = [NSMutableArray array];
        [observersDict setObject:observers forKey:keyPath];
    }
    KTObserver *observer = [[KTObserver alloc] initWithKvoBlock:block];
    [self addObserver:observer forKeyPath:keyPath options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:NULL];
    [observers addObject:observer];
}

- (void)removeObserverBlocksForKeyPath:(NSString *)keyPath
{
    if (!keyPath) {
        return;
    }
    NSMutableDictionary *observersDict = objc_getAssociatedObject(self, &KTKvoObserversKey);
    if (observersDict) {
        NSMutableArray *observers = [observersDict objectForKey:keyPath];
        [observers enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [self removeObserver:obj forKeyPath:keyPath];
        }];
        [observersDict removeObjectForKey:keyPath];
    }
}

- (void)removeAllObserverBlocks
{
    NSMutableDictionary *observersDict = objc_getAssociatedObject(self, &KTKvoObserversKey);
    [observersDict enumerateKeysAndObjectsUsingBlock:^(NSString *key, NSMutableArray *observers, BOOL * _Nonnull stop) {
        [observers enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [self removeObserver:obj forKeyPath:key];
        }];
    }];
    [observersDict removeAllObjects];
}

static const char KTNotificationObserversKey = '\0';

- (void)addNotificationForName:(NSString *)name block:(KTNotificationBlock)block
{
    if (!name || !block) {
        return;
    }
    NSMutableDictionary *observersDict = objc_getAssociatedObject(self, &KTNotificationObserversKey);
    if (!observersDict) {
        observersDict = [NSMutableDictionary dictionary];
        objc_setAssociatedObject(self, &KTNotificationObserversKey, observersDict, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    NSMutableArray *observers = [observersDict objectForKey:name];
    if (!observers) {
        observers = [NSMutableArray array];
        [observersDict setObject:observers forKey:name];
    }
    KTObserver *observer = [[KTObserver alloc] initWithNotificationBlock:block];
    [[NSNotificationCenter defaultCenter] addObserver:observer selector:@selector(handleNotification:) name:name object:nil];
    [observers addObject:observer];
}

- (void)removeNotificationBlocksForName:(NSString *)name
{
    if (!name) {
        return;
    }
    NSMutableDictionary *observersDict = objc_getAssociatedObject(self, &KTNotificationObserversKey);
    if (observersDict) {
        NSMutableArray *observers = [observersDict objectForKey:name];
        [observers enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [[NSNotificationCenter defaultCenter] removeObserver:obj name:name object:nil];
        }];
        [observersDict removeObjectForKey:name];
    }
}

- (void)removeAllNotificationBlocks
{
    NSMutableDictionary *observersDict = objc_getAssociatedObject(self, &KTNotificationObserversKey);
    [observersDict enumerateKeysAndObjectsUsingBlock:^(NSString *key, NSMutableArray *observers, BOOL * _Nonnull stop) {
        [observers enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [[NSNotificationCenter defaultCenter] removeObserver:obj name:key object:nil];
        }];
    }];
    [observersDict removeAllObjects];
}

// 替换dealloc方法，自动注销observer
+ (void)load
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Method originalDealloc = class_getInstanceMethod(self, NSSelectorFromString(@"dealloc"));
        Method newDealloc = class_getInstanceMethod(self, @selector(autoRemoveObserverDealloc));
        method_exchangeImplementations(originalDealloc, newDealloc);
    });
}

- (void)autoRemoveObserverDealloc
{
    if (objc_getAssociatedObject(self, &KTKvoObserversKey) || objc_getAssociatedObject(self, &KTNotificationObserversKey)) {
        [self removeAllObserverBlocks];
        [self removeAllNotificationBlocks];
    }
    // 下面这句相当于直接调用dealloc
    [self autoRemoveObserverDealloc];
}

@end
