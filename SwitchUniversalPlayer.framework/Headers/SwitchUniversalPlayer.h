//  Copyright © 2017 Switch Media. All rights reserved.

@import UIKit;

@class SwitchPlayer;
@protocol SwitchPlayerAnalyticsDelegate;

@interface SwitchUniversalPlayer : NSObject

/**
 *  Create Switch Player
 */
+ (SwitchPlayer *)player;

/**
 *  Configure the player based on switch player config
 *
 *  @param url URL to SwitchUniversalPlayer Config
 */
+ (SwitchPlayer *)playerWithConfigURL:(NSURL *)url;

/**
 *  Configure the player based on switch player config
 *
 *  @param jsonString NSString to SwitchUniversalPlayer Config
 */
+ (SwitchPlayer *)playerWithConfigString:(NSString *)jsonString;

/**
 *  Configure the player based on switch player config
 *
 *  @param jsonObject NSDictionary to SwitchUniversalPlayer Config
 */
+ (SwitchPlayer *)playerWithConfigJson:(NSDictionary *)jsonObject;

/**
 *  Singleton player instance
 */
+ (SwitchUniversalPlayer *)sharedInstance;

/**
 *  Dismiss and close the player
 */
- (void)dismiss;

/**
 *  custom data to pass to the google cast session
 */
- (NSDictionary *)customDataForGoogleCast;

/**
 * current player version
 */
-(NSString *)versionString;

/**
 *  Player analytics delegate
 */
@property (nonatomic) id<SwitchPlayerAnalyticsDelegate> analyticsDelegate;

@end
