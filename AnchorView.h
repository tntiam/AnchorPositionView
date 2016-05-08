//
//  AnchorView.h
//  AnchorPositonView
//
//  Created by Tran Trong Nghia on 12/21/15.
//  Copyright © 2015 Tran Trong Nghia. All rights reserved.
//

#ifndef AnchorView_h
#define AnchorView_h

/**
 * create
 */
CG_INLINE CGPoint
cgp(CGFloat x, CGFloat y)
{
    CGPoint p;
    p.x = x;
    p.y = y;
    return p;
}

CG_INLINE CGSize
cgs(CGFloat width, CGFloat height)
{
    CGSize size;
    size.width = width;
    size.height = height;
    return size;
}

CG_INLINE UIEdgeInsets
insets(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right)
{
    UIEdgeInsets insets;
    insets.top = top;
    insets.left = left;
    insets.bottom = bottom;
    insets.right = right;
    return insets;
}

/**
 * Use for anchor of view
 */
CG_INLINE CGPoint
anchorDefault()
{
    return cgp(0.5, 0.5);
}

CG_INLINE CGPoint
anchorLeftCenter()
{
    return cgp(0, 0.5);
}

CG_INLINE CGPoint
anchorLeftTop()
{
    return cgp(0, 0);
}

CG_INLINE CGPoint
anchorLeftBottom()
{
    return cgp(0, 1);
}

CG_INLINE CGPoint
anchorRightCenter()
{
    return cgp(1, 0.5);
}

CG_INLINE CGPoint
anchorRightTop()
{
    return cgp(1, 0);
}

CG_INLINE CGPoint
anchorRightBottom()
{
    return cgp(1, 1);
}

CG_INLINE CGPoint
anchorTopCenter()
{
    return cgp(0.5, 0);
}

CG_INLINE CGPoint
anchorBottomCenter()
{
    return cgp(0.5, 1);
}

/**
 * view
 */
CG_INLINE CGFloat
hidden()
{
    return 0;
}

CG_INLINE CGFloat
show()
{
    return 1;
}

/*
 * screen
 */
CG_INLINE CGRect
screenBounds()
{
    CGRect rect = [UIScreen mainScreen].bounds;
    return rect;
}

CG_INLINE CGSize
screenSize()
{
    CGSize size = screenBounds().size;
    return size;
}

CG_INLINE CGFloat
screenHeight()
{
    CGFloat height = screenSize().height;
    return height;
}

CG_INLINE CGFloat
screenWidth()
{
    CGFloat width = screenSize().width;
    return width;
}

CG_INLINE CGFloat
screenCenterX()
{
    CGFloat centerX = screenWidth() / 2;
    return centerX;
}

CG_INLINE CGFloat
screenCenterY()
{
    CGFloat centerY = screenHeight() / 2;
    return centerY;
}

CG_INLINE CGPoint
screenCenterPoint()
{
    CGPoint point = cgp(screenCenterX(), screenCenterY());
    return point;
}

CG_INLINE CGFloat
screenScale()
{
    CGFloat scale = [UIScreen mainScreen].scale;
    return scale;
}

CG_INLINE CGFloat
screenNativeScale() NS_AVAILABLE_IOS (8_0)
{
    CGFloat nativeScale = [UIScreen mainScreen].nativeScale;
    return nativeScale;
}

CG_INLINE CGRect
screenNativeBounds() NS_AVAILABLE_IOS(8_0)
{
    CGRect nativeBounds = [UIScreen mainScreen].nativeBounds;
    return nativeBounds;
}

CG_INLINE CGFloat
screenBrightness(CGFloat brightness)
{
    [UIScreen mainScreen].brightness = brightness;
    return brightness;
}

CG_INLINE CGFloat
statusBarHeight()
{
    CGFloat height = [UIApplication sharedApplication].statusBarFrame.size.height;
    return height;
}

CG_INLINE CGFloat
navigationBarHeight(UIViewController *viewController)
{
    if (!viewController.navigationController) {
        NSLog(@"'%@' have not yet UINavigationController, height default is 44", NSStringFromClass(viewController.class));
        return 44;
    }
    CGFloat height = viewController.navigationController.navigationBar.frame.size.height;
    return height;
}

/*
 * Device
 */
CG_INLINE BOOL
isRetina()
{
    if (screenScale() > 1) {
        return YES;
    }
    return NO;
}

CG_INLINE BOOL
isiPhone()
{
    return (screenHeight() == 480 && !isRetina());
}

CG_INLINE BOOL
isiPhone4()
{
    return (screenHeight() == 480 && isRetina());
}

CG_INLINE BOOL
isiPhone5()
{
    return (screenHeight() == 568);
}

CG_INLINE BOOL
isiPhone6()
{
    return (screenHeight() == 667);
}

CG_INLINE BOOL
isiPhone6P()
{
    return (screenHeight() == 736);
}

CG_INLINE BOOL
isiPad()
{
    return (screenHeight() >= 1024);
}

CG_INLINE BOOL
isiPadRetina()
{
    return (isiPad() && isRetina());
}

/**
 * Device System
 */
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define IS_IOS_6_LESSER                             isiOS6_Lesser()
#define IS_IOS_6                                    isiOS6()
#define IS_IOS_6_AFTER                              isiOS6_After()

#define IS_IOS_7_LESSER                             isiOS7_Lesser()
#define IS_IOS_7                                    isiOS7()
#define IS_IOS_7_AFTER                              isiOS7_After()

#define IS_IOS_8_LESSER                             isiOS8_Lesser()
#define IS_IOS_8                                    isiOS8()
#define IS_IOS_8_AFTER                              isiOS8_After()

#define IS_IOS_9_LESSER                             isiOS9_Lesser()
#define IS_IOS_9                                    isiOS9()
#define IS_IOS_9_AFTER                              isiOS9_After()

CG_INLINE BOOL
isiOS6_Lesser()
{
    BOOL isiOS6 = SYSTEM_VERSION_LESS_THAN(@"6.0");
    return isiOS6;
}

CG_INLINE BOOL
isiOS6()
{
    BOOL isiOS6 = (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0") && SYSTEM_VERSION_LESS_THAN(@"7.0"));
    return isiOS6;
}

CG_INLINE BOOL
isiOS6_After()
{
    BOOL isiOS6 = SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0");
    return isiOS6;
}

CG_INLINE BOOL
isiOS7_Lesser()
{
    BOOL isiOS7 = SYSTEM_VERSION_LESS_THAN(@"7.0");
    return isiOS7;
}

CG_INLINE BOOL
isiOS7()
{
    BOOL isiOS7 = (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0") && SYSTEM_VERSION_LESS_THAN(@"8.0"));
    return isiOS7;
}

CG_INLINE BOOL
isiOS7_After()
{
    BOOL isiOS7 = SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0");
    return isiOS7;
}

CG_INLINE BOOL
isiOS8_Lesser()
{
    BOOL isiOS8 = SYSTEM_VERSION_LESS_THAN(@"8.0");
    return isiOS8;
}

CG_INLINE BOOL
isiOS8()
{
    BOOL isiOS8 = (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0") && SYSTEM_VERSION_LESS_THAN(@"9.0"));
    return isiOS8;
}

CG_INLINE BOOL
isiOS8_After()
{
    BOOL isiOS8 = SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"9.0");
    return isiOS8;
}

CG_INLINE BOOL
isiOS9_Lesser()
{
    BOOL isiOS9 = SYSTEM_VERSION_LESS_THAN(@"9.0");
    return isiOS9;
}

CG_INLINE BOOL
isiOS9()
{
    BOOL isiOS9 = (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"9.0") && SYSTEM_VERSION_LESS_THAN(@"10.0"));
    return isiOS9;
}

CG_INLINE BOOL
isiOS9_After()
{
    BOOL isiOS9 = SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"10.0");
    return isiOS9;
}

/**
 * Color
 */
CG_INLINE UIColor*
RGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a)
{
    return [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a];
}

CG_INLINE UIColor*
RGB(CGFloat r, CGFloat g, CGFloat b)
{
    return RGBA(r, g, b, 1);
}

CG_INLINE UIColor*
hexColorAlpha(char c, CGFloat a)
{
    return [UIColor colorWithRed:((float)((c & 0xFF0000) >> 16))/255.0 green:((float)((c & 0xFF00) >> 8))/255.0 blue:((float)(c & 0xFF))/255.0 alpha:a];
}

CG_INLINE UIColor*
hexColor(char c)
{
    return hexColorAlpha(c, 1.0);
}

/**
 * NSString
 */
CG_INLINE NSString*
tran(NSString *key) {
    NSString *string = NSLocalizedString(key, nil);
    return string;
}

/**
 * Keyboard
 */
CG_INLINE CGRect
rectKeyboard(NSNotification *notification) {
    CGRect rectBegin = [notification.userInfo[UIKeyboardFrameBeginUserInfoKey] CGRectValue];
    CGRect rectEnd = [notification.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    CGRect rect = (screenHeight() == rectBegin.origin.y) ? rectEnd : rectBegin;
    return rect;
}

CG_INLINE CGFloat
heightKeyboard(NSNotification *notification) {
    CGRect rect = rectKeyboard(notification);
    CGFloat height = rect.size.height;
    return height;
}

CG_INLINE CGFloat
durationKeyboard(NSNotification *notification) {
    CGFloat duration = [notification.userInfo[UIKeyboardAnimationDurationUserInfoKey] floatValue];
    return duration;
}

#endif /* AnchorView_h */
