//
//  MOBAboutUsViewController.m
//  MOBLibs
//
//  Created by LeeJay on 2018/1/31.
//  Copyright © 2018年 MOB. All rights reserved.
//

#import "MOBAboutUsViewController.h"
#import <MSC/MSCQuery.h>
#import <MSC/MSCQueryOrder.h>
#import "MOBAboutUsModel.h"
#import <MOBFoundation/MOBFoundation.h>
#import "MOBLibsContext.h"

static NSString *const SPTAboutUsCache = @"AboutUsCache";

@interface MOBAboutUsViewController ()

@property (nonatomic, weak) IBOutlet UIImageView *appIcon;
@property (nonatomic, weak) IBOutlet UILabel *appName;
@property (nonatomic, weak) IBOutlet UILabel *appContent;
@property (weak, nonatomic) IBOutlet UILabel *appCompany;
@property (nonatomic, weak) IBOutlet UILabel *copyright;

@end

@implementation MOBAboutUsViewController

- (void)getAboutUsDataWithResult:(void (^)(MOBAboutUsModel *, NSError *))handler
{
    MSCQuery *query = [[MSCQuery alloc] initWithObjectName:@"about_info" targetClass:[MOBAboutUsModel class]];
    [query selectKeys:@[@"app_name", @"app_icon",@"about_desc",@"company_name",@"copyright"]];
    query.order.desc(@"update_at");
    [query find:^(NSArray<MOBAboutUsModel *> *objects, NSError *error) {
        
        if (error)
        {
            if (handler)
            {
                handler(nil, error);
            }
        }
        else
        {
            if (handler)
            {
                handler(objects.firstObject, nil);
            }
        }
    }];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    [self getAboutUsDataWithResult:^(MOBAboutUsModel *us, NSError *error) {
    
        NSError *usError;
        
        if (!error)
        {
            [[MOBFImageGetter sharedInstance] getImageWithURL:[NSURL URLWithString:us.appIconUrl] result:^(UIImage *image, NSError *error) {
                self.appIcon.image = image;
            }];
            self.appName.text = us.appName;
            self.appContent.text = us.content;
            self.copyright.text = us.copyright;
            self.appCompany.text = us.company;
            
            [[MOBFDataService sharedInstance] setCacheData:[us dictionaryValue] forKey:SPTAboutUsCache domain:@"MOB"];
            if ([MOBLibsContext sharedInstance].debugLog)
            {
                NSLog(@"about = %@", [us dictionaryValue]);
            }
        }
        else
        {
            NSDictionary *dict = [[MOBFDataService sharedInstance] cacheDataForKey:SPTAboutUsCache domain:@"MOB"];
            if (dict)
            {
                [[MOBFImageGetter sharedInstance] getImageWithURL:[NSURL URLWithString:dict[@"app_icon"]] result:^(UIImage *image, NSError *error) {
                    self.appIcon.image = image;
                }];
                self.appName.text = dict[@"app_name"];
                self.appContent.text = dict[@"about_desc"];
                self.copyright.text = dict[@"copyright"];
                self.appCompany.text = dict[@"company_name"];
                if ([MOBLibsContext sharedInstance].debugLog)
                {
                    NSLog(@"error = %@, 取缓存", error);
                }
            }
            else
            {
                if ([MOBLibsContext sharedInstance].debugLog)
                {
                    NSLog(@"error = %@, 没有数据，没有缓存", error);
                }
                usError = error;
            }
        }
        
        if (self.handler)
        {
            self.handler(usError);
        }
    }];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
