//
//  BBSUIProcessHUD.m
//  BBSSDKUI
//
//  Created by youzu_Max on 2017/4/25.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUIProcessHUD.h"
#import "Masonry.h"
#import "BBSUIMacro.h"

@interface BBSUIProcessHUD()

@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UIView *backgroundView;
@property (nonatomic, strong) UILabel *alertLabel;
@property (nonatomic, strong) UIImageView *processView;
@property (nonatomic, strong) UIImage *failedImage;
@property (nonatomic, strong) UIImage *successImage;
@property (nonatomic, strong) UIActivityIndicatorView *inditorView;

@end

@implementation BBSUIProcessHUD

+ (instancetype)shareInstance
{
    static BBSUIProcessHUD *shareInstance = nil ;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        shareInstance = [[BBSUIProcessHUD alloc] init];
    });
    return shareInstance ;
}

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        [self setup];
    }
    return self;
}

- (void)setup
{
    CGSize size = [UIScreen mainScreen].bounds.size ;
    self.window = [[UIWindow alloc] initWithFrame:CGRectMake((size.width-179)/2.0,size.height/2.0-109,179, 109)];
    self.window.backgroundColor = [UIColor clearColor];
    self.window.windowLevel = UIWindowLevelAlert + 1 ;
    
    self.backgroundView = [[UIView alloc] initWithFrame:self.window.bounds];
    //    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(test)];
    //    [self.backgroundView addGestureRecognizer:tap];
    self.backgroundView .backgroundColor = DZSUIColorFromHex(0xF2F4F7);
    self.backgroundView .alpha = 0.75 ;
    self.backgroundView .layer.cornerRadius = 12 ;
    [self.window addSubview:_backgroundView];
    
    _failedImage = [UIImage BBSImageNamed:@"/Common/process_fail@2x.png"];
    self.processView = [[UIImageView alloc] initWithImage:_failedImage];
    [_backgroundView addSubview:_processView];
    [_processView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(_backgroundView);
        make.top.equalTo(_backgroundView).offset(24);
//        make.height.mas_equalTo(_failedImage.size.height);
//        make.width.mas_equalTo(_failedImage.size.width);
    }];
    
    self.alertLabel = [[UILabel alloc] init];
    self.alertLabel.text = @"" ;
    self.alertLabel.textColor = DZSUIColorFromHex(0x3A4045);
    self.alertLabel.font = [UIFont systemFontOfSize:12];
    [_backgroundView addSubview:_alertLabel];
    [_alertLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(_backgroundView);
        make.top.equalTo(_processView.mas_bottom).offset(18);
    }];

}

+ (void) showSuccessInfo:(NSString *)info delay:(CGFloat)delay
{
    if (![BBSUIProcessHUD shareInstance].window)
    {
        [[BBSUIProcessHUD shareInstance] setup];
    }
    [BBSUIProcessHUD shareInstance].alertLabel.text = info;
    [BBSUIProcessHUD shareInstance].processView.image = [UIImage BBSImageNamed:@"/Common/success@2x.png"];
    //    [[BBSUIProcessHUD shareInstance].processView mas_updateConstraints:^(MASConstraintMaker *make) {
    //        make.width.equalTo(@0);
    //    }];
    [[BBSUIProcessHUD shareInstance].window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [BBSUIProcessHUD dismiss];
    });
}

+ (void) showFailInfo:(NSString *)info delay:(CGFloat)delay
{
    if (![BBSUIProcessHUD shareInstance].window)
    {
        [[BBSUIProcessHUD shareInstance] setup];
    }
    [BBSUIProcessHUD shareInstance].alertLabel.text = info;
//    [[BBSUIProcessHUD shareInstance].processView mas_updateConstraints:^(MASConstraintMaker *make) {
//        make.width.equalTo(@0);
//    }];
    [[BBSUIProcessHUD shareInstance].window makeKeyAndVisible];
    if (delay == 0) {
        delay = 3;
    }
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [BBSUIProcessHUD dismiss];
    });
}

+ (void) showProcessHUDWithInfo:(NSString *)info
{
//    if (![BBSUIProcessHUD shareInstance].window)
//    {
//        [[BBSUIProcessHUD shareInstance] setup];
//    }
//    [BBSUIProcessHUD shareInstance].alertLabel.text = info;
////    [BBSUIPostProcessHUD shareInstance].backgroundView.backgroundColor = [UIColor blackColor];
//    [[BBSUIPostProcessHUD shareInstance].processView mas_updateConstraints:^(MASConstraintMaker *make) {
//        make.width.equalTo(@([BBSUIPostProcessHUD shareInstance].processImageWidth));
//    }];
//    [[BBSUIPostProcessHUD shareInstance].window makeKeyAndVisible];
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [BBSUIPostProcessHUD dismiss];
//    });
}

+ (void) dismiss
{
    [[BBSUIProcessHUD shareInstance].window resignKeyWindow];
    [BBSUIProcessHUD shareInstance].window = nil;
}


@end
