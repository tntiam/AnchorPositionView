//
//  UIView+AnchorPostionView.m
//  AnchorPositonView
//
//  Created by Tran Trong Nghia on 12/18/15.
//  Copyright © 2015 Tran Trong Nghia. All rights reserved.
//

#import "UIView+AnchorPostionView.h"
#import <objc/runtime.h>

static void * kDebugDrawColor = &kDebugDrawColor;
static void * kSize = &kSize;
static void * kAnchorPoint = &kAnchorPoint;
static void * kPosition = &kPosition;

@implementation UIView (AnchorPostionView)
@dynamic debugDrawColor;
@dynamic sizeView;
@dynamic position;
@dynamic positonInPoint;
@dynamic anchorPoint;
@dynamic widthLeftOfAnchorPoint;
@dynamic widthRightOfAnchorPoint;
@dynamic heightBottomOfAnchorPoint;
@dynamic heightTopOfAnchorPoint;
@dynamic radiusCircleInSizeOfView;
@dynamic radiusCircleOutSizeOfView;
@dynamic centerPointOfView;

#pragma mark - INIT
- (instancetype)initAnchorViewWithSize:(CGSize)sizeView
{
    self = [self initWithFrame:CGRectZero];
    if (self) {
        self.frame = ({
            CGRect rect = CGRectZero;
            rect.size = sizeView;
            rect.origin = CGPointZero;
            rect;
        });
        self.sizeView = sizeView;
        self.anchorPoint = anchorDefault();
    }
    return self;
}

+ (UIView *)anchorViewWithSize:(CGSize)sizeView
{
    return [[UIView alloc] initAnchorViewWithSize:sizeView];
}

#pragma mark - CUSTOM PROPERTY
- (void)setDebugDrawColor:(DebugDrawColor)debugDrawColor
{
    objc_setAssociatedObject(self, kDebugDrawColor, @(debugDrawColor), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    UIColor *color = [self debugDrawColor:debugDrawColor];
    if (!color) return;
    self.layer.borderColor = color.CGColor;
    self.layer.borderWidth = 1;
}

- (DebugDrawColor)debugDrawColor
{
    NSNumber *numer = objc_getAssociatedObject(self, kDebugDrawColor);
    DebugDrawColor colorType = [numer integerValue];
    return colorType;
}

- (void)setSizeView:(CGSize)sizeView
{
    NSString *sizeString = NSStringFromCGSize(sizeView);
    objc_setAssociatedObject(self, kSize, sizeString, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (CGSize)sizeView
{
    NSString *sizeString = objc_getAssociatedObject(self, kSize);
    CGSize size = CGSizeFromString(sizeString);
    return size;
}

- (void)setAnchorPoint:(CGPoint)anchorPoint
{
    NSString *anchorString = NSStringFromCGPoint(anchorPoint);
    objc_setAssociatedObject(self, kAnchorPoint, anchorString, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    if (self.sizeView.width == 0 || self.sizeView.height == 0) {
        return;
    }
    
    CGFloat deltaX = self.sizeView.width * anchorPoint.x;
    CGFloat deltaY = self.sizeView.height * anchorPoint.y;
    self.frame = ({
        CGRect rect = self.frame;
        rect.origin.x = self.position.x - deltaX;
        rect.origin.y = self.position.y - deltaY;
        rect;
    });
}

- (CGPoint)anchorPoint
{
    NSString *anchorString = objc_getAssociatedObject(self, kAnchorPoint);
    CGPoint anchor = CGPointFromString(anchorString);
    return anchor;
}

- (void)setPosition:(CGPoint)position
{
    NSString *stringPosition = NSStringFromCGPoint(position);
    objc_setAssociatedObject(self, kPosition, stringPosition, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    if (self.sizeView.width == 0 || self.sizeView.height == 0) {
        return;
    }
    
    CGFloat deltaX = self.sizeView.width * self.anchorPoint.x;
    CGFloat deltaY = self.sizeView.height * self.anchorPoint.y;
    self.frame = ({
        CGRect rect = self.frame;
        rect.origin.x = position.x - deltaX;
        rect.origin.y = position.y - deltaY;
        rect;
    });
}

- (CGPoint)position
{
    NSString *stringPostion = objc_getAssociatedObject(self, kPosition);
    CGPoint positon = CGPointFromString(stringPostion);
    return positon;
}

- (CGPoint)positonInPoint
{
    CGPoint anchorPoint = self.anchorPoint;
    CGSize size = self.sizeView;
    CGFloat pointX = anchorPoint.x * size.width;
    CGFloat pointY = anchorPoint.y * size.height;
    CGPoint positionInPoint = cgp(pointX, pointY);
    return positionInPoint;
}

- (CGFloat)widthLeftOfAnchorPoint
{
    return self.positonInPoint.x;
}

- (CGFloat)widthRightOfAnchorPoint
{
    return self.sizeView.width - self.positonInPoint.x;
}

- (CGFloat)heightTopOfAnchorPoint
{
    return self.positonInPoint.y;
}

- (CGFloat)heightBottomOfAnchorPoint
{
    return self.sizeView.height - self.positonInPoint.y;
}

- (CGFloat)radiusCircleInSizeOfView
{
    return MIN(self.frame.size.width, self.frame.size.height) / 2;
}

- (CGFloat)radiusCircleOutSizeOfView
{
    return MAX(self.frame.size.width, self.frame.size.height) / 2;
}

#pragma mark - PRIVATE METHOD
- (UIColor *)debugDrawColor:(DebugDrawColor)colorType
{
    switch (colorType) {
        case DebugDrawColorBlack:
            return [UIColor blackColor];
        case DebugDrawColorBlue:
            return [UIColor blueColor];
        case DebugDrawColorBrown:
            return [UIColor brownColor];
        case DebugDrawColorClear:
            return [UIColor clearColor];
        case DebugDrawColorCyan:
            return [UIColor cyanColor];
        case DebugDrawColorDarkGray:
            return [UIColor darkGrayColor];
        case DebugDrawColorGreen:
            return [UIColor greenColor];
        case DebugDrawColorLightGray:
            return [UIColor lightGrayColor];
        case DebugDrawColorMagenta:
            return [UIColor magentaColor];
        case DebugDrawColorNone:
            return nil;
        case DebugDrawColorOrange:
            return [UIColor orangeColor];
        case DebugDrawColorPurple:
            return [UIColor purpleColor];
        case DebugDrawColorRed:
            return [UIColor redColor];
        case DebugDrawColorWhite:
            return [UIColor whiteColor];
        case DebugDrawColorYellow:
            return [UIColor yellowColor];
        default:
            break;
    }
    return nil;
}

#pragma mark - PUBLISH METHOD


@end
