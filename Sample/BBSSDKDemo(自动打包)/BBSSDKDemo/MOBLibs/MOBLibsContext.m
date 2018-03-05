//
//  MOBLibsContext.m
//  MOBLibs
//
//  Created by LeeJay on 2018/1/30.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import "MOBLibsContext.h"
#import "MOBGuideViewController.h"
#import "MOBAESHelper.h"
#import "MOBSDKKeyModel.h"
#import "MOBVersionUpdateModel.h"
#import <MSC/MSCQuery.h>
#import <MSC/MSCQueryCondition.h>
#import <MSC/MSCQueryOrder.h>
#import "MOBAboutUsViewController.h"
#import <MOBFoundation/MOBFoundation.h>

static NSString *const MOBGuideImagesKey = @"MOBGuideImages";
static NSString *const MOBVersionCodesKey = @"MOBVersionCodes";

@interface MOBLibsContext () <UIAlertViewDelegate>

@property (nonatomic, strong) MOBSDKKeyModel *keyModel;
@property (nonatomic, copy) NSDictionary *infoPlistDict;
@property (nonatomic, assign) NSInteger versionCode;
@property (nonatomic, strong) MOBAboutUsViewController *aboutVC;
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, assign) BOOL isNewVersion;

@end

@implementation MOBLibsContext

+ (instancetype)sharedInstance
{
    static id instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

- (MOBAboutUsViewController *)aboutVC
{
    if (!_aboutVC)
    {
        _aboutVC = [[MOBAboutUsViewController alloc] init];
    }
    return _aboutVC;
}

- (NSDictionary *)infoPlistDict
{
    if (!_infoPlistDict)
    {
        NSString *url = [[NSBundle mainBundle] pathForResource:@"Info" ofType:@"plist"];
        _infoPlistDict = [NSDictionary dictionaryWithContentsOfFile:url];
    }
    return _infoPlistDict;
}

- (NSInteger)versionCode
{
    if (!_versionCode)
    {
        if (self.infoPlistDict[@"VersionCode"])
        {
            _versionCode = [self.infoPlistDict[@"VersionCode"] integerValue];
        }
        else
        {
            _versionCode = NSNotFound;
        }
    }
    return _versionCode;
}

- (BOOL)isNewVersion
{
    if (!_isNewVersion)
    {
        NSMutableArray *versions = [[MOBFDataService sharedInstance] cacheDataForKey:MOBVersionCodesKey domain:@"MOBLibs"];
        NSMutableArray *newVersions = [NSMutableArray array];
        if ([versions containsObject:@(self.versionCode)])
        {
            _isNewVersion = NO;
        }
        else
        {
            _isNewVersion = YES;
            if (versions.count)
            {
                [newVersions addObject:versions];
            }
            [newVersions addObject:@(self.versionCode)];
            [[MOBFDataService sharedInstance] setCacheData:newVersions forKey:MOBVersionCodesKey domain:@"MOBLibs"];
        }
    }
    return _isNewVersion;
}

- (MOBSDKKeyModel *)keyModel
{
    if (!_keyModel)
    {
        NSString *str = self.infoPlistDict[@"MOBAppSecret"];
        NSString *appSecret = str.length > 16 ? [str substringToIndex:16] : str;
        NSDictionary *dict = self.infoPlistDict[@"SDKConfig"];
        if ([dict isKindOfClass:[NSDictionary class]])
        {
            _keyModel = [[MOBSDKKeyModel alloc] initWithDict:dict mobAppSecret:appSecret];
        }
    }
    return _keyModel;
}

- (void)showGuideVC
{
    if (!self.isNewVersion)
    {
        return;
    }
    
    NSString *path = [[NSBundle mainBundle] pathForResource:MOBGuideImagesKey ofType:nil];
    NSArray *files = [[NSFileManager defaultManager] subpathsAtPath:path];
    
    if (!files.count)
    {
        if (self.debugLog)
        {
            NSLog(@"请在项目的工程里添加蓝色文件夹MOBGuideImages或者MOBGuideImages文件夹下没有文件");
        }
    }
    else
    {
        NSMutableArray *images = [NSMutableArray array];
        for (NSString *imageName in files)
        {
            NSString *file = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@/%@", MOBGuideImagesKey, imageName] ofType:nil];
            UIImage *image = [UIImage imageWithContentsOfFile:file];
            if (image)
            {
                [images addObject:image];
            }
        }
        
        MOBGuideViewController *vc = [[MOBGuideViewController alloc] init];
        [vc showWithImages:images];
    }
}

- (void)showUpdateVersionAlert
{
    [self _checkAppUpdate:^(MOBVersionUpdateModel *appUpdate, NSError *error) {
        if (!error)
        {
            if (self.versionCode == NSNotFound)
            {
                if (self.debugLog)
                {
                    NSLog(@"请在Info.plist文件中配置你的VersionCode");
                }
            }
            else
            {
                if (appUpdate.version > self.versionCode)
                {
                    _downloadUrl = appUpdate.downloadUrl;
                    [self _showAlertWithMessage:appUpdate.updateMessage];
                }
            }
        }
    }];
}

- (void)_showAlertWithMessage:(NSString *)message
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"版本更新"
                                                    message:message
                                                   delegate:self
                                          cancelButtonTitle:@"取消"
                                          otherButtonTitles:@"更新", nil];
    [alert show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 1)
    {
        if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:_downloadUrl]])
        {
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:_downloadUrl]];
        }
    }
}

- (void)_checkAppUpdate:(void (^) (MOBVersionUpdateModel *appUpdate, NSError *error))handler;
{
    MSCQuery *query = [[MSCQuery alloc] initWithObjectName:@"version_remind" targetClass:[MOBVersionUpdateModel class]];
    [query selectKeys:@[@"is_constraint", @"remind_decs", @"download_url", @"update_at", @"version_code"]];
    query.condition.equal(@"platform",@(2));
    query.order.desc(@"update_at");
    
    [query find:^(NSArray<MOBVersionUpdateModel *> *objects, NSError *error) {
        
        if (error)
        {
            if (handler)
            {
                if (self.debugLog)
                {
                    NSLog(@"%@", error);
                }
                handler(nil, error);
            }
        }
        else
        {
            if (handler)
            {
                if (objects && objects.count > 0)
                {
                    MOBVersionUpdateModel *appUpdate = objects.firstObject;
                    if (self.debugLog)
                    {
                        NSLog(@"%@", [appUpdate dictionaryValue]);
                    }
                    handler(appUpdate, nil);
                }
                else
                {
                    if (self.debugLog)
                    {
                        NSLog(@"没有数据");
                    }
                    handler(nil, nil);
                }
            }
        }
    }];
}

@end
