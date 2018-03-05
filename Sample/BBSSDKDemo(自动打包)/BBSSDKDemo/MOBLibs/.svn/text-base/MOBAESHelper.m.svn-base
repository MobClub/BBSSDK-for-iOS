//
//  MOBAESHelper.m
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import "MOBAESHelper.h"
#import <CommonCrypto/CommonCryptor.h>

static NSString const *kInitVector = @"0123456789abcdef";
static size_t const kKeySize = kCCKeySizeAES128;

@implementation MOBAESHelper

+ (NSData *)cipherOperation:(NSData *)contentData keyData:(NSData *)keyData operation:(CCOperation)operation
//NSData *cipherOperation(NSData *contentData, NSData *keyData, CCOperation operation)
{
    NSUInteger dataLength = contentData.length;
    
    void const *initVectorBytes = [kInitVector dataUsingEncoding:NSUTF8StringEncoding].bytes;
    void const *contentBytes = contentData.bytes;
    void const *keyBytes = keyData.bytes;
    
    size_t operationSize = dataLength + kCCBlockSizeAES128;
    void *operationBytes = malloc(operationSize);
    size_t actualOutSize = 0;
    
    CCCryptorStatus cryptStatus = CCCrypt(operation,
                                          kCCAlgorithmAES,
                                          kCCOptionPKCS7Padding,
                                          keyBytes,
                                          kKeySize,
                                          initVectorBytes,
                                          contentBytes,
                                          dataLength,
                                          operationBytes,
                                          operationSize,
                                          &actualOutSize);
    
    if (cryptStatus == kCCSuccess)
    {
        return [NSData dataWithBytesNoCopy:operationBytes length:actualOutSize];
    }
    free(operationBytes);
    return nil;
}

+ (NSString *)aesEncryptString:(NSString *)content key:(NSString *)key
{
    NSData *contentData = [content dataUsingEncoding:NSUTF8StringEncoding];
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSData *encrptedData = [self aesEncryptData:contentData key:keyData];
    return [encrptedData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
}

+ (NSString *)aesDecryptString:(NSString *)content key:(NSString *)key
{
    NSData *contentData = [[NSData alloc] initWithBase64EncodedString:content options:NSDataBase64DecodingIgnoreUnknownCharacters];
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSData *decryptedData = [self aesDecryptData:contentData key:keyData];
    return [[NSString alloc] initWithData:decryptedData encoding:NSUTF8StringEncoding];
}

+ (NSData *)aesEncryptData:(NSData *)data key:(NSData *)keyData
{
    NSString *hint = [NSString stringWithFormat:@"The key size of AES-%lu should be %lu bytes!", kKeySize * 8, kKeySize];
    NSCAssert(keyData.length == kKeySize, hint);
    return [self cipherOperation:data keyData:keyData operation:kCCDecrypt];
}

+ (NSData *)aesDecryptData:(NSData *)data key:(NSData *)keyData
{
    NSString *hint = [NSString stringWithFormat:@"The key size of AES-%lu should be %lu bytes!", kKeySize * 8, kKeySize];
    NSCAssert(keyData.length == kKeySize, hint);
    return [self cipherOperation:data keyData:keyData operation:kCCDecrypt];
}

@end
