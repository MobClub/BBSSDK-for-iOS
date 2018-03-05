//
//  MOBVersionUpdateModel.m
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import "MOBVersionUpdateModel.h"

@implementation MOBVersionUpdateModel

@dynamic updateMessage;
@dynamic downloadUrl;
@dynamic updateTime;
@dynamic version;

+ (NSDictionary <NSString *, NSString *> *)propertyMappingDictionary
{
    return [NSDictionary dictionaryWithObjectsAndKeys:@"remind_decs",@"updateMessage",@"download_url",@"downloadUrl",@"update_at",@"updateTime",@"version_code",@"version",nil];
}

@end
