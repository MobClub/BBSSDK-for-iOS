//
//  MOBAESHelper.h
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MOBAESHelper : NSObject

/**
 AES加密

 @param content 明文
 @param key 秘钥
 @return 密文
 */
+ (NSString *)aesEncryptString:(NSString *)content key:(NSString *)key;

/**
 AES解密

 @param content 密文
 @param key 秘钥
 @return 明文
 */
+ (NSString *)aesDecryptString:(NSString *)content key:(NSString *)key;

/**
 AES加密

 @param data 明文
 @param keyData 秘钥
 @return 明文
 */
+ (NSData *)aesEncryptData:(NSData *)data key:(NSData *)keyData;

/**
 AES解密

 @param data 密文
 @param keyData 秘钥
 @return 明文
 */
+ (NSData *)aesDecryptData:(NSData *)data key:(NSData *)keyData;

@end
