//  Copyright © 2018 Switch Media. All rights reserved.

#import <Foundation/Foundation.h>
#import "SwitchProtocols.h"
#import "OzTAMAnalyticsTypes.h"
#import "OzTAMService.h"
#import "OzTAMAnalytics.h"
#import "OzTAMAnalyticsLive.h"
#import "OzTAMAnalyticsVOD.h"
#import "OzTAMResource.h"
#import "OzTAMConfig.h"
@import AVFoundation;

/**
 For a live stream that contains epoch time metadata attached in the stream
 */
extern NSString * _Nonnull const OzTAMMediaTypeLive;

/**
 For a live stream that does NOT contain epoch time metadata attached in the stream
 */
extern NSString * _Nonnull const OzTAMMediaTypeLiveReal;

/**
 For a VOD content stream
 */
extern NSString * _Nonnull const OzTAMMediaTypeVod;


