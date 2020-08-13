#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIDatePicker.h>)
//
//  UIDatePicker.h
//  UIKit
//
//  Copyright (c) 2006-2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIDatePickerMode) {
    UIDatePickerModeTime,           // Displays hour, minute, and optionally AM/PM designation depending on the locale setting (e.g. 6 | 53 | PM)
    UIDatePickerModeDate,           // Displays month, day, and year depending on the locale setting (e.g. November | 15 | 2007)
    UIDatePickerModeDateAndTime,    // Displays date, hour, minute, and optionally AM/PM designation depending on the locale setting (e.g. Wed Nov 15 | 6 | 53 | PM)
    UIDatePickerModeCountDownTimer, // Displays hour and minute (e.g. 1 | 53)
} API_UNAVAILABLE(tvos);

typedef NS_ENUM(NSInteger, UIDatePickerStyle) {
    /// Automatically pick the best style available for the current platform & mode.
    UIDatePickerStyleAutomatic,
    /// Use the wheels (UIPickerView) style.
    UIDatePickerStyleWheels,
    /// Use a compact style for the date picker. Editing occurs in an overlay.
    UIDatePickerStyleCompact,
} API_AVAILABLE(ios(13.4)) API_UNAVAILABLE(tvos, watchos);

UIKIT_EXTERN API_AVAILABLE(ios(2.0)) API_UNAVAILABLE(tvos) @interface UIDatePicker : UIControl <NSCoding>
@property (nonatomic) UIDatePickerMode datePickerMode; // default is UIDatePickerModeDateAndTime

@property (nullable, nonatomic, strong) NSLocale   *locale;   // default is [NSLocale currentLocale]. setting nil returns to default
@property (null_resettable, nonatomic, copy)   NSCalendar *calendar; // default is [NSCalendar currentCalendar]. setting nil returns to default
@property (nullable, nonatomic, strong) NSTimeZone *timeZone; // default is nil. use current time zone or time zone from calendar

@property (nonatomic, strong) NSDate *date;        // default is current date when picker created. Ignored in countdown timer mode. for that mode, picker starts at 0:00
@property (nullable, nonatomic, strong) NSDate *minimumDate; // specify min/max date range. default is nil. When min > max, the values are ignored. Ignored in countdown timer mode
@property (nullable, nonatomic, strong) NSDate *maximumDate; // default is nil

@property (nonatomic) NSTimeInterval countDownDuration; // for UIDatePickerModeCountDownTimer, ignored otherwise. default is 0.0. limit is 23:59 (86,399 seconds). value being set is div 60 (drops remaining seconds).
@property (nonatomic) NSInteger      minuteInterval;    // display minutes wheel with interval. interval must be evenly divided into 60. default is 1. min is 1, max is 30

- (void)setDate:(NSDate *)date animated:(BOOL)animated; // if animated is YES, animate the wheels of time to display the new date

/// Request a style for the date picker. If the style changed, then the date picker may need to be resized and will generate a layout pass to display correctly.
@property (nonatomic, readwrite, assign) UIDatePickerStyle preferredDatePickerStyle API_AVAILABLE(ios(13.4)) API_UNAVAILABLE(tvos, watchos);

/// The style that the date picker is using for its layout. This property always returns a concrete style (never automatic).
@property (nonatomic, readonly, assign) UIDatePickerStyle datePickerStyle API_AVAILABLE(ios(13.4)) API_UNAVAILABLE(tvos, watchos);

@end

NS_ASSUME_NONNULL_END


#else
#import <UIKitCore/UIDatePicker.h>
#endif
