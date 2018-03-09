//
//  BBSUIModelToObject.h
//  BBSSDKUI
//
//  Created by liyc on 2017/3/15.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BBSSDK/BBSThread.h>
#import <BBSSDK/BBSPost.h>
#import <BBSSDK/BBSThreadAttachment.h>

@interface BBSUIModelToObject : NSObject

/**
 字典化
 
 @param model 帖子model
 @return 字典
 */
+ (NSDictionary *)objectFromThreadModel:(BBSThread *)model;

/**
 字典化
 
 @param model 评论model
 @return 字典
 */
+ (NSDictionary *)objectFromPostModel:(BBSPost *)model;

/**
 字典化

 @param model 附件model
 @return 字典
 */
+ (NSDictionary *)objectFromAttachmentModel:(BBSThreadAttachment *)model;

@end
