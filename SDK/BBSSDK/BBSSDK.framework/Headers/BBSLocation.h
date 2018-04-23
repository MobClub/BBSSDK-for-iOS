//
//  BBSLocation.h
//  BBSSDK
//
//  Created by mob on 2018/4/16.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BBSLocationCoordinate : NSObject

/**
 纬度
 */
@property(nonatomic, assign)float latitude;


/**
 经度
 */
@property(nonatomic, assign)float longitude;

- (instancetype)initWithLatitude:(float)latitude longitude:(float)longitude;

@end


@interface BBSLocation : NSObject


/**
 地址显示名称(简称)
 */
@property(nonatomic, copy)NSString *poiTitle;


/**
 详细地址
 */
@property(nonatomic, copy)NSString *address;


/**
 经纬度
 */
@property(nonatomic, strong)BBSLocationCoordinate *coordinate;


- (instancetype)initWithPOITitle:(NSString *)poiTitle
                         address:(NSString *)address
                        latitude:(float)latitude
                       longitude:(float)longitude;

@end
