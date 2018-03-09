//
//  BBSUIMacro.h
//  BBSSDKUI
//
//  Created by liyc on 2017/2/16.
//  Copyright © 2017年 MOB. All rights reserved.
//

#ifndef BBSUIMacro_h
#define BBSUIMacro_h

#define NavigationBar_Height 64

#define DZSUIColorFromHex(s)  [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s &0xFF00) >>8))/255.0 blue:((s &0xFF))/255.0 alpha:1.0]

#define DZSUI_MainColor 0x88BE66
#define DZSUI_BackgroundColor DZSUIColorFromHex(0xF2F4F7)

#define DZSUIScreen_width [UIScreen mainScreen].bounds.size.width
#define DZSUIScreen_height [UIScreen mainScreen].bounds.size.height

#define BBS_LEFT(view)      (view).frame.origin.x
#define BBS_TOP(view)       (view).frame.origin.y
#define BBS_WIDTH(view)     (view).frame.size.width
#define BBS_HEIGHT(view)    (view).frame.size.height
#define BBS_RIGHT(view)     (BBS_LEFT(view) + BBS_WIDTH(view))
#define BBS_BOTTOM(view)    (BBS_TOP(view) + BBS_HEIGHT(view))

//notification
#define DZSDidCreateContextNotification @"DZSDidCreateContextNotification"

#define BBSUIAlert(_S_, ...)     [[[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil] show]


#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...)
#endif


#import "NSBundle+BBSSDKUI.h"
#import "UIImage+BBSFunction.h"
#import <MOBFoundation/MOBFoundation.h>
#import "SVProgressHUD.h"

#endif /* BBSUIMacro_h */
