//  Copyright © 2017 Switchmedia. All rights reserved.

@import Foundation;
#import "SwitchProtocols.h"

@interface ConvivaAnalytics : NSObject <SwitchPlayerAnalyticsDelegate>

/**
 *  Setting debug to true will use the conviva staging endpoints and log event actions. Default value is false.
 */
@property (nonatomic) BOOL debug;

/**
 *  Set the descriptive name for the media asset
 */
@property (nonatomic, copy) NSString *assetName;

/**
 *  Set the application name
 */
@property (nonatomic, copy) NSString *applicationName;

/**
 *  Set the unique viewer ID
 */
@property (nonatomic, copy) NSString *viewerID;

/**
 *  Set the default server resource
 */
@property (nonatomic, copy) NSString *serverResource;

/**
 *  Set to true if the stream is live. Default value is false.
 */
@property (nonatomic) BOOL isLiveStream;

/**
 *  Set the stream duration in seconds.
 */
@property (nonatomic) double streamDuration;

/**
 Custom content metadata
 */
@property (nonatomic, copy) NSDictionary *customMetadata;

/**
 Initialize with given server URL and custom key

 @param serverURL Conviva server url string
 @param customKey Conviva custom key
 @return ConvivaAnalytics
 */
- (instancetype)initWithServerURL:(NSString *)serverURL customKey:(NSString *)customKey NS_DESIGNATED_INITIALIZER; 
- (instancetype)init __attribute((unavailable("use initWithServerURL:customKey: instead")));

@end
