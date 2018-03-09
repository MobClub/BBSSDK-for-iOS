//
//  BBSThreadAttachment.h
//  DZSDK
//
//  Created by liyc on 2017/3/6.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MOBFoundation/MOBFDataModel.h>

/**
 主题帖子附件
 */
@interface BBSThreadAttachment : MOBFDataModel

/**
 附件名称
 */
@property (nonatomic, copy, readonly) NSString *fileName;

/**
 上传时间
 */
@property (nonatomic, readonly) NSInteger createdOn;

/**
 附件大小
 */
@property (nonatomic, readonly) NSInteger fileSize;

/**
 阅读权限
 */
@property (nonatomic, readonly) NSInteger readPerm;

/**
 是否为图片（1为图片）
 */
@property (nonatomic, readonly) NSInteger isImage;

/**
 若为图片，该字段表示图片宽度
 */
@property (nonatomic, readonly) NSInteger width;

/**
 价格
 */
@property (nonatomic, readonly) NSInteger price;

/**
 会员id
 */
@property (nonatomic, readonly) NSInteger uid;

/**
 附件链接地址
 */
@property (nonatomic, copy) NSString *url;

/**
 附件文件类型(扩展名)
 */
@property (nonatomic, copy) NSString *extension;

#pragma mark - 门户新增
@property (nonatomic, strong) NSString *filename;

@property (nonatomic, strong) NSString *filetype;

@property (nonatomic, assign) NSInteger dateline;

@property (nonatomic, assign) NSInteger thumb;

@property (nonatomic, assign) NSInteger attachid;

@property (nonatomic, assign) NSInteger remote;

@property (nonatomic, assign) NSInteger aid;

@property (nonatomic, assign) NSInteger isimage;

@property (nonatomic, assign) NSInteger filesize;

@end
