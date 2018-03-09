//
//  WKExpressionView.m
//  WKExpressionInput
//
//  Created by chuxiao on 2017/10/13.
//  Copyright © 2017年 MOB. All rights reserved.
//

#import "BBSUIExpressionView.h"
#import "BBSUIExpressionViewConfiguration.h"
#import "BBSUIExpressionCell.h"
#import "BBSUIExpressionSelectKindButton.h"

@interface BBSUIExpressionView ()<UICollectionViewDelegate,
                                 UICollectionViewDataSource,UICollectionViewDelegateFlowLayout
                                 >

@property (nonatomic, strong) NSDictionary *expressionDictionary;
@property (nonatomic, strong) NSDictionary *dicCurrentExpression;

@property (nonatomic, strong) BBSUIExpressionSelectKindButton *currentSelKindBtn;
@property (nonatomic, strong) UIScrollView *expressionSelectSV;

@end

@implementation BBSUIExpressionView


- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self configure];
    }
    return self;
}


- (NSDictionary *)expressionDictionary
{
    if (! _expressionDictionary)
    {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"BBSSDKUI.bundle/Emoji/emoji" ofType:@"json"];
        
        // 根据文件路径读取数据
        NSData *jdata = [[NSData alloc] initWithContentsOfFile:path];
        
        // 格式化成json数据
        _expressionDictionary = [NSJSONSerialization JSONObjectWithData:jdata options:kNilOptions error:nil];
    }
    
    return _expressionDictionary;
}

- (void)layoutSubviews
{
    self.expressionSelectSV.frame = CGRectMake(0, CGRectGetMaxY(self.collectionView.frame), self.collectionView.frame.size.width, 42);
}

- (void)configure
{
    _dicCurrentExpression = self.expressionDictionary[@"default"];
    
    CGFloat expressionSelectSVH = 42;
    
    //1.初始化layout
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
    layout.itemSize =CGSizeMake(expressionSelectSVH, expressionSelectSVH);
    self.collectionView = [[UICollectionView alloc] initWithFrame:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height - expressionSelectSVH) collectionViewLayout:layout];
    self.collectionView.backgroundColor = [UIColor whiteColor];
    [self.collectionView registerClass:[BBSUIExpressionCell class] forCellWithReuseIdentifier:cellIdentifier];
    
    [self addSubview:self.collectionView];
    self.collectionView.delegate = self;
    self.collectionView.dataSource = self;
    
    self.expressionSelectSV = [[UIScrollView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(self.collectionView.frame), self.collectionView.frame.size.width, expressionSelectSVH)];
    self.expressionSelectSV.backgroundColor = [self colorWithHexString:@"0xF2F3F7"];
    for (int i = 0; i < [self.expressionDictionary allKeys].count; i ++)
    {
        BBSUIExpressionSelectKindButton *button = [[BBSUIExpressionSelectKindButton alloc] initWithFrame:CGRectMake(expressionSelectSVH * i, 0, expressionSelectSVH, expressionSelectSVH)];
        
        NSString *imageName;
        UIColor *btnColor;
        NSString *kindName;
        if (i == 0)
        {
            imageName = @"BBSSDKUI.bundle/Emoji/default/01.gif";
            kindName = @"default";
            btnColor = [self colorWithHexString:@"0xFFFFFF"];
            _currentSelKindBtn = button;
        }
        else if (i == 1)
        {
            imageName = @"BBSSDKUI.bundle/Emoji/coolmonkey/01.gif";
            kindName = @"coolmonkey";
            btnColor = [UIColor clearColor];
        }
        else
        {
            imageName = @"BBSSDKUI.bundle/Emoji/grapeman/01.gif";
            kindName = @"grapeman";
            btnColor = [UIColor clearColor];
        }
        
        [button setBackgroundColor:btnColor];
        [button setImage:[UIImage imageNamed:imageName] forState:UIControlStateNormal];
        button.imageEdgeInsets = UIEdgeInsetsMake(8, 8, 8, 8);
        button.kindName = kindName;
        [self.expressionSelectSV addSubview:button];
        
        [button addTarget:self action:@selector(onSelectExpressionKindAction:) forControlEvents:UIControlEventTouchUpInside];
    }
    
    self.expressionSelectSV.contentOffset = CGPointMake([self.expressionDictionary allKeys].count * expressionSelectSVH, expressionSelectSVH);
    [self addSubview:self.expressionSelectSV];
}



#pragma mark collectionView代理方法

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return [self.dicCurrentExpression allKeys].count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    BBSUIExpressionCell *cell = (BBSUIExpressionCell *)[collectionView dequeueReusableCellWithReuseIdentifier:cellIdentifier forIndexPath:indexPath];
    
    NSString *row = [NSString stringWithFormat:@"%lu",indexPath.row + 1];
    if (row.length == 1)
    {
        row = [@"0" stringByAppendingString:row];
    }
    
    NSString *expressionName = [NSString stringWithFormat:@"%@/%@.gif",_currentSelKindBtn.kindName,row];
    NSString *expressionKey = self.dicCurrentExpression[expressionName];
    
    cell.expressionKey = expressionKey;
    cell.expressionName = expressionName;
    
    return cell;
}

//设置每个item的尺寸
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    return CGSizeMake(35, 35);
}

//设置每个item的UIEdgeInsets
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section
{
    return UIEdgeInsetsMake(10, 10, 10, 10);
}

//设置每个item水平间距
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section
{
    return 10;
}


//设置每个item垂直间距
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section
{
    return 15;
}


- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    BBSUIExpressionCell *cell = (BBSUIExpressionCell *)[collectionView cellForItemAtIndexPath:indexPath];
    [self.delegate expressionView:self didSelectImageName:cell.expressionName];
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    
}

- (void)expressionCellDidSelectDeleteButton:(BBSUIExpressionCell *)cell
{
    if ([self.delegate respondsToSelector:@selector(expressionViewDidSelectDeleteButton:)]) {
        [self.delegate expressionViewDidSelectDeleteButton:self];
    }
}


- (IBAction)didSelectSendButton:(id)sender {
    if ([self.delegate respondsToSelector:@selector(expressionViewDidSelectSendButton:)]) {
        [self.delegate expressionViewDidSelectSendButton:sender];
    }
}


- (void)setSendButtonState:(BOOL)enabled
{
    
}


- (UIImage *)createColorImageWithColor:(UIColor *)color
{
    UIGraphicsBeginImageContext(CGSizeMake(40, 40));
    [color setFill];
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextFillRect(context, CGRectMake(0, 0, 40, 40));
    
    UIImage *colorImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return colorImage;
}

#pragma mark - action

- (void)onSelectExpressionKindAction:(BBSUIExpressionSelectKindButton *)sender
{
    [_currentSelKindBtn setBackgroundColor:[UIColor clearColor]];
    _currentSelKindBtn = sender;
    
    [sender setBackgroundColor:[UIColor whiteColor]];
    self.dicCurrentExpression = self.expressionDictionary[sender.kindName];
    [self.collectionView reloadData];
}

#pragma mark - 16进制颜色
- (UIColor *) colorWithHexString: (NSString *)color
{
    NSString *cString = [[color stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    
    // String should be 6 or 8 characters
    if ([cString length] < 6) {
        return [UIColor clearColor];
    }
    // 判断前缀
    if ([cString hasPrefix:@"0X"])
        cString = [cString substringFromIndex:2];
    if ([cString hasPrefix:@"#"])
        cString = [cString substringFromIndex:1];
    if ([cString length] != 6)
        return [UIColor clearColor];
    // 从六位数值中找到RGB对应的位数并转换
    NSRange range;
    range.location = 0;
    range.length = 2;
    //R、G、B
    NSString *rString = [cString substringWithRange:range];
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    // Scan values
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    
    return [UIColor colorWithRed:((float) r / 255.0f) green:((float) g / 255.0f) blue:((float) b / 255.0f) alpha:1.0f];
}


@end
