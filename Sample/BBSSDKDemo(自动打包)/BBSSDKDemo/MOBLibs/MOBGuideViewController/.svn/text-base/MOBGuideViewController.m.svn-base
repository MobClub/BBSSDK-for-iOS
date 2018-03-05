//
//  MOBGuideViewController.m
//  MOBGuideViewController
//
//  Created by LeeJay on 2018/1/10.
//  Copyright © 2018年 Mob. All rights reserved.
//

#import "MOBGuideViewController.h"
#import "MOBWindowManager.h"
#import "MOBGuideContentView.h"
#import "MOBGuideContentView+Private.h"
#import "MOBGuideImageView.h"

#define MOBScreenWidth [UIScreen mainScreen].bounds.size.width
#define MOBScreenHeight [UIScreen mainScreen].bounds.size.height

static NSString *const MOBGuideViewCellId = @"MOBGuideViewCell";

@interface MOBGuideViewController () <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (nonatomic, copy) NSArray *contentViews;
@property (nonatomic, strong) UIPageControl *pageControl;
@property (nonatomic, assign) BOOL needClose;

@end

@implementation MOBGuideViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    [self configure];
}

- (UIPageControl *)pageControl
{
    if (!_pageControl)
    {
        _pageControl = [[UIPageControl alloc] init];
    }
    return _pageControl;
}

- (void)configure
{
    if (@available(iOS 11, *))
    {
        self.collectionView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    }
    
    [self.collectionView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:MOBGuideViewCellId];
    
    self.pageControl.currentPage = 0;
    
    self.pageControl.frame = CGRectMake(MOBScreenWidth / 2 - 15, MOBScreenHeight - 50,  30, 37);
    [self.view addSubview:self.pageControl];
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return self.contentViews.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:MOBGuideViewCellId forIndexPath:indexPath];
    [cell.contentView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
    [cell.contentView addSubview:self.contentViews[indexPath.row]];
    return cell;
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(nonnull UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(nonnull NSIndexPath *)indexPath
{
    return self.view.bounds.size;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    if (self.contentViews.count == 1)
    {
        [self closeWithAnimate:YES];
    }
}

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView
{
    if (_needClose)
    {
        [self closeWithAnimate:YES];
    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    int index = scrollView.contentOffset.x / self.view.bounds.size.width;
    self.pageControl.currentPage = index;
    
    float totalContentOffsetX = (self.contentViews.count - 1) * self.view.bounds.size.width;
    if (scrollView.contentOffset.x > totalContentOffsetX)
    {
        _needClose = YES;
    }
}

- (void)showWithGuideContentViews:(NSArray<MOBGuideContentView *> *)contentViews
{
    if (!contentViews.count)
    {
        return;
    }
    
    for (MOBGuideContentView *contentView in contentViews)
    {
        contentView.controller = self;
    }
    _contentViews = contentViews;
    self.pageControl.numberOfPages = _contentViews.count;
    [self _showOnWindow];
}

- (void)showWithImages:(NSArray<UIImage *> *)images
{
    if (!images.count)
    {
        return;
    }
    
    [MOBGuideImageView class];
    NSMutableArray *contentViews = [NSMutableArray array];
    for (UIImage *image in images)
    {
        NSArray *bundles = [[NSBundle mainBundle] loadNibNamed:@"MOBGuideImageView" owner:self options:nil];
        MOBGuideImageView *guideView = bundles.firstObject;
        guideView.frame = CGRectMake(0, 0, MOBScreenWidth, MOBScreenHeight);
        guideView.imageV.image = image;
        guideView.controller = self;
        [contentViews addObject:guideView];
    }
    _contentViews = contentViews;
    self.pageControl.numberOfPages = _contentViews.count;
    [self _showOnWindow];
}

- (void)closeWithAnimate:(BOOL)animate
{
    [self closeWithAnimate:animate completion:nil];
}

- (void)closeWithAnimate:(BOOL)animate completion:(void (^)(void))completion
{
    [MOBWindowManager closeWindow:self.view.window
                          animate:animate
                       completion:completion];
    
    self.closeCompletionHandler ? self.closeCompletionHandler() : nil;
}

- (void)_showOnWindow
{
    UIWindow *window = [MOBWindowManager getWindow];
    window.rootViewController = self;
    [window makeKeyAndVisible];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
