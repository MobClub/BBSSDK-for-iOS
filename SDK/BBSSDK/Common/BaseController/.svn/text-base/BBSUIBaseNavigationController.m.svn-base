//
//  BBSUIBaseNavigationController.m
//  BBSSDKUI
//
//  Created by liyc on 2017/2/16.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUIBaseNavigationController.h"

@interface BBSUIBaseNavigationController ()<UIGestureRecognizerDelegate>

@end

@implementation BBSUIBaseNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.interactivePopGestureRecognizer.delegate =  self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer {
    if (self.viewControllers.count <= 1 ) {
        return NO;
    }
    
    return YES;
}

@end
