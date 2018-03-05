//
//  BBSJSImageDownload.h
//  BBSSDKUI
//
//  Created by liyc on 2017/3/12.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MOBFoundation/MOBFJSContext.h>

@interface BBSJSImageDownload : NSObject

- (instancetype)initWithJSContext:(MOBFJSContext *)jsContext imageArray:(NSArray *)imageArray isImageViewer:(BOOL)isImageViewer webView:(UIWebView *)webView;

- (void)setCurrentIndex:(NSInteger)currentIndex url:(NSString *)url;

- (void)saveImage;


@end
