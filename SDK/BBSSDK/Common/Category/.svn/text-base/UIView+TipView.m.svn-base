//
//  UIView+TipView.m
//  BBSSDKUI
//
//  Created by liyc on 2017/3/3.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "UIView+TipView.h"
#import <objc/runtime.h>
#import "Masonry.h"
#import "UIColor+Common.h"
#import "UIButton+Common.h"
#import "UIImage+BBSFunction.h"

@interface UIView ()

@property (nonatomic, strong) TipView *tipView;

@end

@implementation UIView (TipView)

- (void)setTipView:(TipView *)tipView
{
    objc_setAssociatedObject(self,
                             @selector(tipView),
                             tipView,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (TipView *)tipView
{
    return objc_getAssociatedObject(self, _cmd);
}

- (void)configureTipViewWithTipMessage:(NSString *)tipString hasData:(BOOL)hasData
{
    [self configureTipViewWithTipMessage:tipString
                                 hasData:hasData
                             noDataImage:[UIImage BBSImageNamed:@"/Common/wnr3@2x.png"]];
}

- (void)configureTipViewWithTipMessage:(NSString *)tipString
                               hasData:(BOOL)hasData
                           noDataImage:(UIImage *)noDataImage
{
    [self configureTipViewWithTipMessage:tipString
                                 hasData:hasData
                             noDataImage:noDataImage
                                hasError:NO
                       reloadButtonBlock:nil];
}

- (void)configureTipViewWithTipMessage:(NSString *)tipString
                               hasData:(BOOL)hasData
                              hasError:(BOOL)hasError
                     reloadButtonBlock:(void (^)(id))block
{
    [self configureTipViewWithTipMessage:tipString
                                 hasData:hasData
                             noDataImage:[UIImage BBSImageNamed:@"/Common/wnr3@2x.png"]
                                hasError:hasError
                       reloadButtonBlock:block];
}

- (void)configureTipViewWithFrame:(CGRect)frame
                       tipMessage:(NSString *)tipString
                      noDataImage:(UIImage *)noDataImage
                          hasData:(BOOL)hasData
                         hasError:(BOOL)hasError
                reloadButtonBlock:(void (^)(id sender))block
{
    UIImage *image = noDataImage;
    if (!image)
    {
        image = [UIImage BBSImageNamed:@"/Common/wnr3@2x.png"];
    }
    [self configureTipViewWithFrame:frame
                         tipMessage:tipString
                                 hasData:hasData
                             noDataImage:image
                                hasError:hasError
                       reloadButtonBlock:block];
}

- (void)configureTipViewWithError:(NSError *)error
                          hasData:(BOOL)hasData
                reloadButtonBlock:(void (^)(id))block
{
    if (hasData)
    {
        if (self.tipView)
        {
            self.tipView.hidden = YES;
            [self.tipView removeFromSuperview];
        }
    }
    else
    {
        if (!self.tipView)
        {
            self.tipView = [[TipView alloc] initWithFrame:self.bounds];
        }
        self.tipView.hidden = NO;
        [self.tipViewContainer addSubview:self.tipView];
        
        NSString *tipString;
        
        if (error.code == - 1009)
        {
            tipString = @"ag_unable_to_connect";
            
            [self.tipView tipViewWithTipMessag:tipString
                                       hasData:hasData
                                   noDataImage:nil
                                      hasError:YES
                                    errorImage:[UIImage BBSImageNamed:@"/Common/wnr3@2x.png"]
                             reloadButtonBlock:block];
        }
        else
        {
            tipString = @"ag_sorry_no_related_data_found";
            
            [self.tipView tipViewWithTipMessag:tipString
                                       hasData:hasData
                                   noDataImage:[UIImage BBSImageNamed:@"/Common/wwl@2x.png"]
                                      hasError:NO
                                    errorImage:nil
                             reloadButtonBlock:block];
        }
        
    }
    
}


#pragma mark - Private

- (void)configureTipViewWithTipMessage:(NSString *)tipString
                               hasData:(BOOL)hasData
                           noDataImage:(UIImage *)noDataImage
                              hasError:(BOOL)hasError
                     reloadButtonBlock:(void (^)(id))block
{
    if (hasData)
    {
        if (self.tipView)
        {
            self.tipView.hidden = YES;
            [self.tipView removeFromSuperview];
        }
    }
    else
    {
        if (!self.tipView)
        {
            self.tipView = [[TipView alloc] initWithFrame:self.bounds];
        }
        self.tipView.hidden = NO;
        [self.tipViewContainer addSubview:self.tipView];
        
        [self.tipView tipViewWithTipMessag:tipString
                                   hasData:hasData
                               noDataImage:noDataImage
                                  hasError:hasError
                                errorImage:[UIImage BBSImageNamed:@"/Common/wnr3@2x.png"]
                         reloadButtonBlock:block];
    }
}

- (void)configureTipViewWithFrame:(CGRect)frame
                       tipMessage:(NSString *)tipString
                          hasData:(BOOL)hasData
                      noDataImage:(UIImage *)noDataImage
                         hasError:(BOOL)hasError
                reloadButtonBlock:(void (^)(id))block
{
    if (hasData)
    {
        if (self.tipView)
        {
            self.tipView.hidden = YES;
            [self.tipView removeFromSuperview];
        }
    }
    else
    {
        if (!self.tipView)
        {
            self.tipView = [[TipView alloc] initWithFrame:frame];
        }
        self.tipView.hidden = NO;
        [self.tipViewContainer addSubview:self.tipView];
        
        [self.tipView tipViewWithTipMessag:tipString
                                   hasData:hasData
                               noDataImage:noDataImage
                                  hasError:hasError
                                errorImage:noDataImage
                         reloadButtonBlock:block];
    }
}

- (UIView *)tipViewContainer
{
    UIView *tipViewContainer = self;
    for (UIView *aView in [self subviews])
    {
        if ([aView isKindOfClass:[UITableView class]])
        {
            tipViewContainer = aView;
        }
    }
    return tipViewContainer;
}

@end

@interface TipView ()

@property (nonatomic, strong) UITapGestureRecognizer *tap;
@property (nonatomic, strong) UIImageView *tipImageView;
@property (nonatomic, strong) UILabel *tipLabel;
//@property (nonatomic, strong) UIButton *reloadButton;
@property (nonatomic, copy) void (^reloadButtonBlock)(id sender);

@end

@implementation TipView

#pragma mark - Init

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        self.backgroundColor = [UIColor clearColor];
        [self configureUI];
    }
    return self;
}

- (void)configureUI
{
    [self addSubview:self.tipImageView];
    [_tipImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(self);
        make.bottom.equalTo(self.mas_centerY);
    }];
    
    [self addSubview:self.tipLabel];
    [_tipLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.centerX.equalTo(self);
        make.top.equalTo(_tipImageView.mas_bottom).offset(20);
        make.height.mas_equalTo(50);
    }];
}

#pragma mark - Getters

- (UIImageView *)tipImageView
{
    if (!_tipImageView)
    {
        _tipImageView = [[UIImageView alloc] initWithFrame:CGRectZero];
        _tipImageView.userInteractionEnabled = YES;
    }
    return _tipImageView;
}

- (UILabel *)tipLabel
{
    if (!_tipLabel)
    {
        _tipLabel = [[UILabel alloc] initWithFrame:CGRectZero];
        _tipLabel.backgroundColor = [UIColor clearColor];
        _tipLabel.numberOfLines = 0;
        _tipLabel.font = [UIFont systemFontOfSize:15];
        _tipLabel.textColor = [UIColor lightGrayColor];
        _tipLabel.textAlignment = NSTextAlignmentCenter;
        _tipLabel.userInteractionEnabled = YES;
    }
    return _tipLabel;
}

- (void)tipViewWithTipMessag:(NSString *)tipString
                     hasData:(BOOL)hasData
                 noDataImage:(UIImage *)noDateImage
                    hasError:(BOOL)hasError
                  errorImage:(UIImage *)errorImage
           reloadButtonBlock:(void (^)(id))block
{
    if (hasData)
    {
        [self removeFromSuperview];
        return;
    }
    self.alpha = 1.0;
    
    _reloadButtonBlock = nil;
    
    if (hasError)
    { // 加载失败 刷新按钮
//        if (!_reloadButton)
//        {
//            _reloadButton = [UIButton buttonWithTitle:nil
//                                           titleColor:[UIColor colorFormString:@"#09A9EC"]
//                                      backgroundColor:nil
//                                                 font:15
//                                               target:self
//                                               action:@selector(reloadButtonClicked:)
//                                            superView:nil];
//            _reloadButton.layer.borderColor = [UIColor colorFormString:@"#09A9EC"].CGColor;
//            _reloadButton.layer.cornerRadius = 5;
//            _reloadButton.layer.borderWidth = 1;
//            [self addSubview:_reloadButton];
//            [_reloadButton mas_makeConstraints:^(MASConstraintMaker *make) {
//                make.centerX.equalTo(self);
//                make.top.equalTo(_tipLabel.mas_bottom).offset(20);
//                make.size.mas_equalTo(CGSizeMake(125, 40));
//            }];
//        }
//        [_reloadButton setTitle:@"ag_refresh" forState:0];
//        _reloadButton.hidden = NO;
//        _reloadButtonBlock = block;
//        
//        if (errorImage)
//        {
//            [_tipImageView setImage:errorImage];
//        }
        
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(reloadButtonClicked:)];
        tap.numberOfTapsRequired = 1;
        [_tipImageView addGestureRecognizer:tap];
        
        _reloadButtonBlock = block;
        
        if (errorImage)
        {
            [_tipImageView setImage:errorImage];
        }

        
    }
    else
    { // 空白数据
//        if (_reloadButton)
//        {
//            _reloadButton.hidden = YES;
//        }
        
        if (noDateImage)
        {
            [_tipImageView setImage:noDateImage];
        }
    }
    _tipLabel.text = tipString;
}

- (void)reloadButtonClicked:(id)sender
{
    self.hidden = YES;
    [self removeFromSuperview];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (_reloadButtonBlock)
        {
            _reloadButtonBlock(sender);
        }
    });
}

@end
