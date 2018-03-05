//
//  MOBVersionUpdateModel.h
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <MSC/MSCObject.h>

@interface MOBVersionUpdateModel : MSCObject

@property (nonatomic, copy) NSString *updateMessage;
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, assign) NSTimeInterval updateTime;
@property (nonatomic, assign) NSInteger version;

@end
