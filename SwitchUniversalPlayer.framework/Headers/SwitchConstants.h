//  Copyright © 2017 Switch Media. All rights reserved.

@import Foundation;
#import "SwitchTypes.h"

#pragma mark Helpers
@interface SwitchConstants : NSObject
+ (NSString *)SUPStateAsString:(SUPState)state;
@end

#pragma mark Control UI padding object
@interface SUPControlPadding : NSObject
@property NSInteger top;
@property NSInteger bottom;
@property NSInteger left;
@property NSInteger right;
- (instancetype)init;
- (instancetype)initWithTop:(NSInteger)padTop Left:(NSInteger)padLeft Bottom:(NSInteger)padBottom Right:(NSInteger)padRight;
@end

@interface SUPPaddingLookup : NSObject
@property (nonatomic, strong) SUPControlPadding *padding;
@property (nonatomic) ControlBar controlBar;
@property (nonatomic) SUPControlId controlId;
@end

/**
 *  Previous SUPState on SUPStateChangedNotification
 */
FOUNDATION_EXPORT NSString *const SUPNotificationOldStateKey;
/**
 *  New/Current SUPstate on SUPStateChangedNotification
 */
FOUNDATION_EXPORT NSString *const SUPNotificaitonNewStateKey;

/**
 *  Fired when the player transitions between SUPStates
 */
FOUNDATION_EXPORT NSString *const SUPStateChangedNotification;

/**
 *  Fired when the player user actions may need to send an action beacon
 */
FOUNDATION_EXPORT NSString *const SUPActionBeaconNotification;

/**
 *  Fired when the player time aligns with an ad tracking event time
 */
FOUNDATION_EXPORT NSString *const SUPAdTrackingEventNotification;

/**
 *  Fired when the user has finished watching an adease ad
 */
FOUNDATION_EXPORT NSString *const SUPAdCompletedNotification;

/**
 *  Error Key for SUPErrorOccuredNotification
 */
FOUNDATION_EXPORT NSString *const SUPNotificationErrorKey;

/**
 *  Error Domain for SUP
 */
FOUNDATION_EXPORT NSString *const SUPErrorDomain;

/**
 *  Fired when a loading error occured.
 */
FOUNDATION_EXPORT NSString * const SUPLoadingErrorOccuredNotification;

/**
 *  Loading Error reason Key in UserInfo SUPLoadingErrorOccuredNotification
 */
FOUNDATION_EXPORT NSString *const SUPLoadingReasonKey;

/**
 *  Fired when a player error occured.
 */
FOUNDATION_EXPORT NSString *const SUPErrorOccuredNotification;

/**
 *  Progress Key in UserInfo SUPTickNotification
 */
FOUNDATION_EXPORT NSString *const SUPNotificationProgressKey;

/**
 *  Duration Key in UserInfo SUPTickNotification
 */
FOUNDATION_EXPORT NSString *const SUPNotificationDurationKey;

/**
 *  Buffer Key in UserInfo SUPTickNotification
 */
FOUNDATION_EXPORT NSString *const SUPNotificationBufferKey;

/**
 *  Fired every second while the player is playing
 */
FOUNDATION_EXPORT NSString *const SUPTickNotification;

/**
 *  Fired after captions have been detected in the media stream
 */
FOUNDATION_EXPORT NSString *const SUPCaptionsDetectedNotification;

/**
 *  Fired when the user selects a new captions track
 */
FOUNDATION_EXPORT NSString *const SUPCaptionsChangedNotification;

/**
 *  Fired when an event needs to be passed to the OzTam session
 */
FOUNDATION_EXPORT NSString *const SUPOztamNotification;

/**
 *  Fired when the external display is changed into or out of AirPlay mode
 */
FOUNDATION_EXPORT NSString *const SUPExternalDisplayNotification;

/**
 *  Fired when the user is scrubbing
 */
FOUNDATION_EXPORT NSString *const SUPPlayerSeekingNotification;

/**
 *  Fired when the user has connected or disconnected from google cast device
 */
FOUNDATION_EXPORT NSString *const SUPGoogleCastNotification;

/**
 *  Fired when the player is switching to local playback
 */
FOUNDATION_EXPORT NSString *const SUPPlayerSwitchingToLocalNotification;

/**
 *  Fired when the player is switching to remote playback normally a chromecast device
 */
FOUNDATION_EXPORT NSString *const SUPPlayerSwitchingToRemoteNotification;
