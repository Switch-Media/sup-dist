//  Copyright © 2017 Switch Media. All rights reserved.

@import UIKit;
@import AVFoundation;
@import GoogleCast;

#import "SwitchTypes.h"
#import "SwitchProtocols.h"

@class AssetLoaderDelegate, SUPPaddingLookup, SUPControlPadding, SwitchCastImage, Rendition;
@interface SwitchPlayer : UIView <SUPConfigurableControl>

@property (nonatomic, strong) NSArray *trackingUrls;
@property (nonatomic, strong) NSArray *ads;
@property (nonatomic, strong) NSArray<Rendition *> *renditions;

/**
 *  Control delegate provides a way for the internal controls to understand how they are being presented
 */
@property (nonatomic, weak) id<SwitchPlayerControlDelegate> delegate;

/**
 *  DRM delegate to pass keys for FPS streams
 */
@property (nonatomic, weak) id<SwitchPlayerDRMDelegate> DRMDelegate;

/**
 *  AV Player object exposed for external analytic SDKs.
 */
@property (nonatomic, strong) AVPlayer *player;

/**
 *  Whether or not the media is currently playing on a external google cast device.
 */
@property (nonatomic) BOOL isPlayingOnGoogleCast;

/**
 *  Media meta data required to use google cast.
 */
@property (nonatomic, strong) GCKMediaMetadata *googleCastMediaMetadata;

/**
 *  Media information required to use google cast.
 */
@property (nonatomic, strong) GCKMediaInformation *googleCastMediaInfo;

/**
 *  Whether or not the google cast feature should be enabled in the player. Default value is true.
 */
@property (nonatomic) BOOL googleCastEnabled;

/**
 *  Custom media images to use in google cast components
 */
@property (nonatomic, strong) NSArray<SwitchCastImage *> *castImages;

/**
 * Whether or not the player will resume playing when the app moves back into the foreground.
 * Default is true
 */
@property (nonatomic) BOOL resumeWhenBackToForeground;

@property double duration;
@property double currentPlaybackTime;
@property double renditionStartTime;
@property double peakBitrate;
@property (nonatomic, copy) NSURL *currentStreamURL;
@property (nonatomic, strong) AssetLoaderDelegate *loaderDelegate;
@property (nonatomic) BOOL active;
@property (nonatomic, copy) NSString *certificateUrl;
@property (nonatomic, copy) NSString *keyUrl;
@property (nonatomic, copy) NSString *mpdKeyUrl;
@property (nonatomic) GCKMediaStreamType castStreamType;
@property (nonatomic, copy) NSString *castContentType;
@property (nonatomic, copy) NSString *skippedAdID;

/**
 *  Configure the player directly with a stream URL
 *
 *  @param streamUrl HLS stream URL
 */
- (void)openStreamUrl:(NSURL *)streamUrl;

/**
 *  Configure the player directly with a stream URL and the configuration object
 *
 *  @param streamUrl HLS stream URL
 *  @param config Configuration object
 */
- (void)openStreamUrl:(NSURL *)streamUrl withConfig:(NSObject *)config;


/**
 *  Configure the player directly with a stream URL and the configuration object
 *
 *  @param rendition HLS stream URL
 *  @param config Configuration object
 */
- (void)openRendition:(NSObject *)rendition withConfig:(NSObject *)config;

/**
 *  Start Playing
 */
- (void)play;

/**
 *  Pause/Stop the player
 */
- (void)pause;

/**
 *  Seek to desired position
 *
 *  @param positionInSeconds desired position in seconds
 *  @param onCompletion      callback block when seek is complete
 */
- (void)seekTo:(double)positionInSeconds onCompletion:(CompletionBlock)onCompletion;

/**
 *  Universal Player Version
 *
 *  @return version string.
 */
- (NSString *)versionString;

/**
 *  Select caption track at available index
 */
- (void)selectCaptionAtPosition:(NSInteger)pos;

/**
 *  Disable captions
 */
- (void)disableCaptions;

/**
 *  Stop and dismiss the player object
 */
- (void)dismiss;

/**
 *  Call this when the airplay availability needs to be refreshed
 */
- (void)refreshAirplayButton;

/**
 *  Returns YES if stream is currently playing over AirPlay.
 */
- (BOOL)isAirplayActive;

/**
 *  Returns YES if the media is currently playing on an external device such as Google Chrome Cast or AirPlay.
 */
- (BOOL)isPlayingOnExternalMode;

/** 
 *  Provides method to add additional customData passed to the receiver
 *
 * @param customDataJSON JSONSerialisable object to append to the customData which is passed by the sender to Cast receiver
 */
- (void)appendCustomData:(NSDictionary *)customDataJSON;

/**
 Returns array of language codes for the current media captions tracks.
 */
- (NSArray*) getCaptionsLanguageCodes;

/**
 Set the resize gravity behaviour for the AVPlayerLayer.
 */
- (void) setResizeGravity:(AVLayerVideoGravity)resizeGravity;

/**
 Get the resize gravity behaviour for the AVPlayerLayer.
 */
- (AVLayerVideoGravity) getResizeGravity;

@end
