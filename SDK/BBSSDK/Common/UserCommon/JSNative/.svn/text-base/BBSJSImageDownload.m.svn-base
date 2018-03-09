//
//  BBSJSImageDownload.m
//  BBSSDKUI
//
//  Created by liyc on 2017/3/12.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSJSImageDownload.h"
#import <MOBFoundation/MOBFImageGetter.h>
#import "NSString+md5.h"
#import "BBSUIMacro.h"

#define ImagePath(fileURL) [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:fileURL]

@interface BBSJSImageDownload()

@property (nonatomic, strong) MOBFJSContext *jsContext;

@property (nonatomic, strong) NSArray *imageArray;

@property (nonatomic, strong) NSMutableDictionary *urlDictionary;//key:索引号 value:图片地址

@property (nonatomic) BOOL isImageViewer;

@property (nonatomic, strong) UIWebView *webView;

@property (nonatomic) NSInteger index;

@end

@implementation BBSJSImageDownload

- (instancetype)initWithJSContext:(MOBFJSContext *)jsContext imageArray:(NSArray *)imageArray isImageViewer:(BOOL)isImageViewer webView:(UIWebView *)webView
{
    self = [super init];
    if (self) {
        _jsContext = jsContext;
        _imageArray = imageArray;
        _isImageViewer = isImageViewer;
        _webView = webView;
        
        _urlDictionary = [[NSMutableDictionary alloc] init];
        [self downloadImages];
    }
    
    return self;
}

- (void)downloadImages
{
    __weak typeof(self) theDownload = self;
    
    MOBFImageGetter *imgGetter = [MOBFImageGetter sharedInstance];
    
    if ([_imageArray isKindOfClass:[NSArray class]]) {
        [_imageArray enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            
            [theDownload.urlDictionary setObject:@(idx) forKey:obj];
            
            [imgGetter getImageDataWithURL:[NSURL URLWithString:obj] result:^(NSData *imageData, NSError *error) {
                
                if (imageData && !error)
                {
                    [theDownload setURL:obj imageData:imageData isImageViewer:theDownload.isImageViewer];
                }
                else
                {
                    NSLog(@"data length :%zd,%@",imageData.length,error);
                }
            }];
        }];
    }
}

- (void)setCurrentIndex:(NSInteger)currentIndex url:(NSString *)url
{
    __weak typeof(self) theDownload = self;
    MOBFImageGetter *imgGetter = [MOBFImageGetter sharedInstance];
    self.index = currentIndex;
    NSString *urlStr = self.imageArray[self.index];
    
    [imgGetter getImageDataWithURL:[NSURL URLWithString:urlStr] result:^(NSData *imageData, NSError *error) {
        
        if (imageData && !error)
        {
            [theDownload setURL:urlStr imageData:imageData isImageViewer:theDownload.isImageViewer];
        }
        else
        {
            NSLog(@"data length :%zd,%@",imageData.length,error);
        }
    }];
}

#pragma mark - private methods
- (void)setURL:(NSString *)urlStr imageData:(NSData *)imageData isImageViewer:(BOOL)isImageViewer
{
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *filePath = ImagePath([NSString md5:urlStr]);
    if (![fileManager fileExistsAtPath:filePath]) {
        [fileManager createFileAtPath:filePath contents:nil attributes:nil];
        [imageData writeToFile:filePath atomically:NO];
    }
    
    NSInteger index = [self.urlDictionary[urlStr] integerValue];
    [self nativeShowImage:index url:[NSString md5:urlStr] imgSrc:filePath isImageViewer:isImageViewer];
}

/**
 展示图片
 */
- (void)nativeShowImage:(NSInteger)idx url:(NSString *)url imgSrc:(NSString *)path isImageViewer:(BOOL)isImageViewer
{
    NSString *showImageCall = [NSString stringWithFormat:@"BBSSDKNative.showImage('%zd', '%@', '%@', %@);", idx, url, path, [NSNumber numberWithBool:isImageViewer]];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.webView stringByEvaluatingJavaScriptFromString:showImageCall];
    });
}

-(void)saveImageWithUrl:(NSString *)imageURL{
    // 读取沙盒路径图片
    //    NSString *aPath3=[NSString stringWithFormat:@"%@/Documents/%@.png",NSHomeDirectory(),@"test"];
    // 拿到沙盒路径图片
    UIImage *imgFromUrl3=[[UIImage alloc]initWithContentsOfFile:ImagePath([NSString md5:imageURL])];
    // 图片保存相册
    UIImageWriteToSavedPhotosAlbum(imgFromUrl3, self, nil, nil);
    //    return imgFromUrl3;
}

- (void)saveImage
{
    [self saveImageWithUrl:self.imageArray[self.index]];
}

@end
