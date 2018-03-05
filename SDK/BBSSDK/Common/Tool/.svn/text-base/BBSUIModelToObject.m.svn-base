//
//  BBSUIModelToObject.m
//  BBSSDKUI
//
//  Created by liyc on 2017/3/15.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUIModelToObject.h"

@implementation BBSUIModelToObject

+ (NSDictionary *)objectFromThreadModel:(BBSThread *)model
{
    NSMutableDictionary *mutableDic = [NSMutableDictionary dictionary];
    
    [mutableDic setObject:[NSNumber numberWithInteger:model.tid] forKey:@"tid"];
    
    [mutableDic setObject:[NSNumber numberWithInteger:model.fid] forKey:@"fid"];
    
    if (model.subject) {
        [mutableDic setObject:model.subject forKey:@"subject"];
    }
    
    if (model.summary) {
        [mutableDic setObject:model.summary forKey:@"summary"];
    }
    
    if (model.images) {
        [mutableDic setObject:model.images forKey:@"images"];
    }
    
//    if (model.attachments) {
//        [mutableDic setObject:model.attachments forKey:@"attachments"];
//    }
    
    if (model.author) {
        [mutableDic setObject:model.author forKey:@"author"];
    }
    
    [mutableDic setObject:[NSNumber numberWithInteger:model.authorId] forKey:@"authorId"];
    
    if (model.avatar) {
        [mutableDic setObject:model.avatar forKey:@"avatar"];
    }
    
//    if (model.message) {
//        [mutableDic setObject:model.message forKey:@"message"];
//    }
    
//    if (model.attachments) {
////        [mutableDic setObject:model.attachments forKey:@"attachments"];
//        NSMutableArray *attachmentDicArrary = [NSMutableArray array];
//        if ([model.attachments isKindOfClass:[NSArray class]]) {
//            [model.attachments enumerateObjectsUsingBlock:^(BBSThreadAttachment *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//                if ([obj isKindOfClass:[BBSThreadAttachment class]]) {
//                    if ([BBSUIModelToObject objectFromAttachmentModel:obj]) {
//                        [attachmentDicArrary addObject:[BBSUIModelToObject objectFromAttachmentModel:obj]];
//                    }
//                }
//            }];
//        }
//        [mutableDic setObject:attachmentDicArrary forKey:@"attachments"];
//    }else{
//        [mutableDic setObject:[NSMutableArray array] forKey:@"attachments"];
//    }
    
    [mutableDic setObject:[NSNumber numberWithInteger:model.createdOn] forKey:@"createdOn"];
    
    [mutableDic setObject:[NSNumber numberWithInteger:model.replies] forKey:@"replies"];
    
    [mutableDic setObject:[NSNumber numberWithInteger:model.views] forKey:@"views"];
    
    return mutableDic;
}

+ (NSDictionary *)objectFromPostModel:(BBSPost *)model
{
    NSMutableDictionary *postDic = [NSMutableDictionary dictionary];
    
    [postDic setObject:@(model.fid) forKey:@"fid"];
    
    [postDic setObject:@(model.tid) forKey:@"tid"];
    
    [postDic setObject:@(model.pid) forKey:@"pid"];
    
    if (model.message) {
        [postDic setObject:model.message forKey:@"message"];
    }
    
    if (model.author) {
        [postDic setObject:model.author forKey:@"author"];
    }
    
    if (model.avatar) {
        [postDic setObject:model.avatar forKey:@"avatar"];
    }
    
    [postDic setObject:@(model.authorId) forKey:@"authorId"];
    
    [postDic setObject:@(model.createdOn) forKey:@"createdOn"];
    
    [postDic setObject:@(model.position) forKey:@"position"];
    
    if (model.prePost) {
        [postDic setObject:[BBSUIModelToObject objectFromPostModel:model.prePost] forKey:@"prePost"];
    }
    
    postDic[@"deviceName"] = model.deviceName;
    
    return postDic;
}

+ (NSDictionary *)objectFromAttachmentModel:(BBSThreadAttachment *)model
{
    NSMutableDictionary *attachmentDic = [NSMutableDictionary dictionary];
    
    if (model.fileName)
    {
        [attachmentDic setObject:model.fileName forKey:@"fileName"];
    }
    
    [attachmentDic setObject:@(model.createdOn) forKey:@"createdOn"];
    
    [attachmentDic setObject:@(model.fileSize) forKey:@"fileSize"];
    
    [attachmentDic setObject:@(model.readPerm) forKey:@"readPerm"];
    
    [attachmentDic setObject:@(model.isImage) forKey:@"isImage"];
    
    [attachmentDic setObject:@(model.width) forKey:@"width"];
    
    [attachmentDic setObject:@(model.uid) forKey:@"uid"];
    
    if (model.url) {
        [attachmentDic setObject:model.url forKey:@"url"];
    }
    
//    if (model.filePath) {
//        [attachmentDic setObject:model.filePath forKey:@"filePath"];
//    }
    
    NSString *caches=[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject];
    NSString *filePath=[caches stringByAppendingPathComponent:[NSString stringWithFormat:@"%@", model.fileName]];
    NSString *extension = [model.fileName pathExtension];
    if (extension) {
        [attachmentDic setObject:extension forKey:@"extension"];
    }
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if ([fileManager fileExistsAtPath:filePath])
    {
        [attachmentDic setObject:filePath forKey:@"filePath"];
    }
    
    return attachmentDic;
}


@end
