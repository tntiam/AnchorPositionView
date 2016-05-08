//
//  UIView+AnchorPostionView.h
//  AnchorPositonView
//
//  Created by Tran Trong Nghia on 12/18/15.
//  Copyright © 2015 Tran Trong Nghia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AnchorView.h"

typedef NS_ENUM(NSInteger, DebugDrawColor) {
    DebugDrawColorNone = 0,
    DebugDrawColorBlack,
    DebugDrawColorDarkGray,
    DebugDrawColorLightGray,
    DebugDrawColorWhite,
    DebugDrawColorRed,
    DebugDrawColorGreen,
    DebugDrawColorBlue,
    DebugDrawColorCyan,
    DebugDrawColorYellow,
    DebugDrawColorMagenta,
    DebugDrawColorOrange,
    DebugDrawColorPurple,
    DebugDrawColorBrown,
    DebugDrawColorClear
};

@interface UIView (AnchorPostionView)
@property (assign, nonatomic) CGSize sizeView;
@property (assign, nonatomic) CGPoint anchorPoint;
@property (assign, nonatomic) CGPoint position;

@property (assign, readonly, nonatomic) CGPoint positonInPoint;
@property (assign, readonly, nonatomic) CGFloat widthLeftOfAnchorPoint;
@property (assign, readonly, nonatomic) CGFloat widthRightOfAnchorPoint;
@property (assign, readonly, nonatomic) CGFloat heightTopOfAnchorPoint;
@property (assign, readonly, nonatomic) CGFloat heightBottomOfAnchorPoint;

@property (assign, nonatomic) DebugDrawColor debugDrawColor;

@property (assign, readonly, nonatomic) CGFloat radiusCircleInSizeOfView; // get MIN(w, h) / 2
@property (assign, readonly, nonatomic) CGFloat radiusCircleOutSizeOfView; // get MAX(w, h) /2

@property (assign, readonly, nonatomic) CGPoint centerPointOfView;

- (instancetype)initAnchorViewWithSize:(CGSize)sizeView;
+ (UIView *)anchorViewWithSize:(CGSize)sizeView;

@end
