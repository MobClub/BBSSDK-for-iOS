//
//  MyBBSViewController.m
//  BBSSDKDemo
//
//  Created by youzu_Max on 2017/6/27.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "MyBBSViewController.h"
#import <BBSSDK/BBSSDK.h>
#import <BBSSDKUI/BBSUIForumHomeViewController.h>

#define BBSUIAlert(_S_, ...)     [[[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil] show]

//#define checkAppkeyUrl @"http://10.18.97.58:8808/api/app/check"
#define checkAppkeyUrl @"http://admin.mob.com/api/app/check"

@interface MyBBSViewController ()

@property (weak, nonatomic) IBOutlet UITextField *appkeyTextField;
@property (weak, nonatomic) IBOutlet UITextField *appSecretTextField;
@property (weak, nonatomic) IBOutlet UIButton *enterMyBBSButton;
@property (weak, nonatomic) IBOutlet UIView *skipView;

@end

@implementation MyBBSViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _enterMyBBSButton.layer.borderWidth = 1;
    _enterMyBBSButton.layer.borderColor = [UIColor colorWithRed:200.0/255 green:215.0/255 blue:235.0/255 alpha:1].CGColor;
    _enterMyBBSButton.layer.cornerRadius = 2.5;
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(skip:)];
    [_skipView addGestureRecognizer:tap];
    
    NSString *appkey = [[MOBFDataService sharedInstance] cacheDataForKey:@"BBSSDK_inner_version_appkey" domain:@"bbs_inner"];
    NSString *appsecret = [[MOBFDataService sharedInstance] cacheDataForKey:@"BBSSDK_inner_version_secret" domain:@"bbs_inner"];
    
    if ([appkey isKindOfClass:NSString.class])
    {
        _appkeyTextField.text = appkey;
    }
    
    if ([appsecret isKindOfClass:NSString.class])
    {
        _appSecretTextField.text = appsecret;
    }
}

- (void)skip:(id)sender
{
    BBSUIForumHomeViewController *vc = [BBSUIForumHomeViewController forumHomeViewControllerWithTitle:@"安卓巴士"];
    [self presentViewController:vc animated:YES completion:nil];
}

- (IBAction)enterMyForum:(id)sender
{
    NSString *appkey = _appkeyTextField.text;
    NSString *secret = _appSecretTextField.text;

    NSMutableDictionary *params = [NSMutableDictionary dictionary];
    params[@"appkey"] = appkey;
    params[@"appsecret"] = secret;
    
    [MOBFHttpService sendHttpRequestByURLString:checkAppkeyUrl method:@"GET" parameters:params headers:nil timeout:30 onResult:^(NSHTTPURLResponse *response, NSData *responseData) {
        
        NSDictionary *body = [MOBFJson objectFromJSONData:responseData];
        
        NSInteger code = [body[@"status"] integerValue];
        
        switch (code)
        {
            case 200:
            {
                id hasApp = body[@"hasApp"];
              
                if([hasApp isKindOfClass:NSNumber.class] && [hasApp integerValue]==0)
                {
                    BBSUIAlert(@"App记录不存在");
                    return ;
                }
                
                id isSet = body[@"isSet"];
                
                if([isSet isKindOfClass:NSNumber.class] && [isSet integerValue]==0)
                {
                    BBSUIAlert(@"未正确安装插件并设置");
                    return ;
                }
                
                id isInitialize = body[@"isInitialize"];
                
                if([isInitialize isKindOfClass:NSNumber.class] && [isInitialize integerValue]==0)
                {
                    BBSUIAlert(@"论坛未初始化");
                    return ;
                }
                
                [BBSSDK setupAppkey:appkey appSecret:secret];
                [self skip:nil];
            }
                break;
            
            case 401:
                BBSUIAlert(@"缺少必要参数");
                break;
                
            default:
                break;
        }
        
    } onFault:^(NSError *error) {
        
        BBSUIAlert(@"网络请求错误 ：%@",error.localizedDescription);
        
    } onUploadProgress:nil];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self.view endEditing:YES];
}

- (void)viewWillDisappear:(BOOL)animated
{
    if (_appkeyTextField.text.length)
    {
        [[MOBFDataService sharedInstance] setCacheData:_appkeyTextField.text forKey:@"BBSSDK_inner_version_appkey" domain:@"bbs_inner"];
    }
    
    if (_appSecretTextField.text.length)
    {
        [[MOBFDataService sharedInstance] setCacheData:_appSecretTextField.text forKey:@"BBSSDK_inner_version_secret" domain:@"bbs_inner"];
    }
}

@end
