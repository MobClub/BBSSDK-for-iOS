//
//  MOBAboutUsModel.h
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <MSC/MSCObject.h>

@interface MOBAboutUsModel : MSCObject

@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appIconUrl;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, copy) NSString *copyright;

@end
