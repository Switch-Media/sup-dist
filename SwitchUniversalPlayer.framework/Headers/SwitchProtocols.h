//  Copyright © 2017 Switch Media. All rights reserved.

#ifndef SwitchProtocols_h
#define SwitchProtocols_h

@import AVFoundation;
@import UIKit;

#import "SwitchTypes.h"
@protocol SwitchPlayerControlDelegate;
@protocol SUPConfigurableControl;
@protocol SwitchPlayerDRMDelegate;
@protocol SwitchPlayerDRMDelegateFeeder;
@protocol SwitchPlayerAnalyticsDelegate;
@class SUPControlPadding, SwitchPlayer;

#pragma mark Protocols
@protocol SUPActivityIndicator <NSObject>
- (void)startAnimating;
- (void)stopAnimating;
@end


@protocol SUPConfigurableControl <NSObject>

/**
 *  Whether or not the player controls will display ad breaks in a different colour on the seek bar. Default value is False
 */
@property (nonatomic) BOOL shouldHighlightAdBreaks;

/**
 *  Time in seconds before controls auto-hide, negative values will force controls to remain indefinitely
 */
@property int shouldAutoHideControls;

/**
 *  Shared background color of top and bottom control bars (center bar is always transparent)
 */
@property (nonatomic, strong) UIColor *barBackgroundColor;

/**
 *  Override the default height of the controls top bar. Default is 44 points
 */
@property (nonatomic) double topBarHeight;

/**
 *  Override the default height of the controls bottom bar. Default is 44 points
 */
@property (nonatomic) double bottomBarHeight;

/**
 *  Whether or not the player control bars have a opaque gradient. Default value is False
 */
@property (nonatomic) BOOL barBackgroundAsGradient;

/**
 *  Whether or not the text progress label should be positioned above the slider. Default value is False
 */
@property (nonatomic) BOOL progressLabelAboveSlider;

/**
 *  Override the default alpha value on the control buttons. Default value is 1.0
 */
@property (nonatomic) double controlButtonDefaultAlpha;

/**
 *  Override the pressed alpha value on the control buttons. Default value is 0.8
 */
@property (nonatomic) double controlButtonPressedAlpha;

/**
 *  Override the control show/hide animation style. Options are @"fade" or @"slide". Default style is @"slide"
 */
@property (nonatomic, strong) NSString* controlAnimationStyle;

/**
 *  Override the default font used for slider labels. Default font is system 17.
 */
@property (nonatomic, strong) UIFont* sliderLabelFont;

/**
 *  Available closed captions for media.
 */
@property (nonatomic, strong) AVMediaSelectionGroup *captions;

/**
 *  Set a resume start time for the video. Default is null
 */
@property (nonatomic) double resumeFromTime;

/**
 *  Set additional customData to pass to the Google cast receiver: Default is null
 */
@property (nonatomic, strong) NSDictionary *customDataJSON;

/**
 *  Set additional event data to pass to the Google cast receiver: Default is null
 */
@property (nonatomic, strong) NSDictionary *eventDataJSON;

/**
 *  Whether or not the google cast expanded controller shows when a new cast session starts. Default is true
 */
@property (nonatomic) BOOL autoShowCastExpandedController;

/**
 *  Whether or not to show the ad break marker icons in the cast expanded controller. Default is true
 */
@property (nonatomic) BOOL showAdBreakMarkersInCastExpandedController;


/**
 *  Reset the internal representation of controls
 */
- (void)resetControls;

// register control to bar, controls are drawn on the bar in the order that they are added, from the last 'resetControls'
/**
 *  Register a control with one of the 3 control bars (top/center/bottom)
 *  Controls cannot be duplicated with the exception of Fixed/Flexible Controls
 *
 *  @param control ControlId to register
 *  @param bar     bar to register the control to.
 */
- (void)registerControl:(SUPControlId)control toBar:(ControlBar)bar;

// register control to bar, controls are drawn on the bar in the order that they are added, from the last 'resetControls', and define custom padding for the UI
/**
 *  Register a control with one of the 3 control bars (top/center/bottom)
 *  Controls cannot be duplicated with the exception of Fixed/Flexible Controls
 *
 *  @param control  ControlId to register
 *  @param bar      bar to register the control to.
 *  @param padding  the custom padding object.
 */
- (void)registerControl:(SUPControlId)control toBar:(ControlBar)bar withPadding:(SUPControlPadding *)padding;

/**
 *  Manually hide control item if it exists
 *
 *  @param control  ControlId to hide
 */
- (void)hideControlItem:(SUPControlId)control;

/**
 *  Manually show control item if it exists
 *
 *  @param control  ControlId to show
 */
- (void)showControlItem:(SUPControlId)control;

/**
 *  Process and redraw the registered controls, required once all controls
 *  are registered, if a control is registered after redrawControls is called,
 *  redraw controls will need to be called again for the changes to visibly take effect
 */
- (void)redrawControls;

/**
 *  Register a custom class to take the place of the loading indicator.
 *  If not called the default loading indicator is used.
 *
 *  @param indicatorClass Class that implements SUPActivityIndicator protocol
 */
- (void)registerLoadingIndicator:(Class<SUPActivityIndicator>)indicatorClass;

/**
 *  Change active captions.
 */
- (void)selectCaptionAtPosition:(NSInteger)pos;

/**
 *  Disable captions.
 */
- (void)disableCaptions;

/**
 *  UI update request when fullscreen is automated in landscape mode.
 */
- (void)rotateToFullscreen;

/**
 *  UI update request when fullscreen is automated in portrait mode.
 */
- (void)rotateToCreative;

/**
 *  Resume playback time when rendition has changed.
 */
- (void)resumeRendition;

/**
 *  Returns a nested array of the adbreak start and end times.
 */
- (NSArray *)getAdBreakTimes;

/**
 *  Open the google cast expanded controller.
 */
- (void)openCastExpandedController;

/**
 *  Set the button text label for when an ad is playering. Default is 'More info'
 */
- (void)setAdLinkText:(NSString *)adLinkText;

/**
 *  Set the background image that appears in the player when in cast mode. If not set, the player will display the default casting media image.
 */
- (void)setBackgroundImageForCastMode:(NSString *)mediaImageURL;
@end

@protocol SwitchPlayerControlDelegate <NSObject>
/**
 *  Provides a callback from the internal player controls that the user performed
 *  an action that needs to be performed. the callback provides a way to tell
 *  the controls that the action was handled, successfully or not.
 *
 *  @param player player associated with the controls
 *  @param action action requested
 *  @param onCompletionBlock     call back block to controls to indicate the control was handled and completed.
 */
- (void)player:(SwitchPlayer *)player requestedAction:(SUPControlAction)action onCompletion:(BoolCompletionBlock)onCompletionBlock;

/**
 *  Indicate the current presentation status of the player.
 *
 *  @return is the player presented fullscreen or not.
 */
- (BOOL)isPlayerPresentedFullscreen;
@end

@protocol SwitchPlayerDRMDelegate <NSObject>

/**
 *  Retrieve the DRM Context
 *
 *  @param keyIdentifier NSString unique identifier that identifies both the DRM type and Content
 *
 *  @return NSData DRMContext
 */
- (NSData *)drmContextForKeyIdentifier:(NSString *)keyIdentifier;

/**
 *  Retrieve the key for the media
 *  FIXME: need to fix incorrect case for parameters
 *
 *  @param resourceUrl NSURL keyRequestUrl
 *  @param keyIdentifier NSString keyIdentifier
 *  @param challenge NSData keyChallenge
 *  @param feeder SwitchPlayerDRMDelegateFeeder DRM feeder used to pass back the key data.
 */
- (void)drmKeyRequestForResourceUrl:(NSURL *)resourceUrl
                      KeyIdentifier:(NSString *)keyIdentifier
                          Challenge:(NSData *)challenge
                          DRMFeeder:(id<SwitchPlayerDRMDelegateFeeder>)feeder;

@end

@protocol SwitchPlayerDRMDelegateFeeder <NSObject>

/**
 *  Pass back the key data from a key request
 *
 *  @param response NSData key request response data
 */
- (void)setKeyResponse:(NSData *)response;

@end

@protocol SwitchPlayerAnalyticsDelegate <NSObject>
@optional

/**
 *  The player has been initialised
 *  @param versionNumber NSString the version number of switch player
 */
- (void)playerInit:(NSString *)versionNumber;

/**
 *  The player is loading a media configuration
 *
 *  @param configURL NSString the URL of the config
 */
- (void)playerLoadingConfig:(NSString *)configURL;

/**
 *  The player is opening a Video URL
 *
 */
- (void)playerOpenURL:(NSURL *)url;

/**
 *  The player is opening a stream
 *
 *  @param streamURL NSString the URL of the stream
 */
- (void)playerLoadingStream:(NSString *)streamURL;

/**
 *  There was a problem parsing the config
 *
 *  @param errorDescription NSString a description of the error that occured
 */
- (void)playerConfigParseError:(NSString *)errorDescription;

/**
 *  The player has found no ads in the config
 */
- (void)playerConfigNoAdsFound;

/**
 *  The configuration has been parsed and ads have been found
 *
 *  @param totalAds int the total number of ads found
 */
- (void)playerConfigAdsFound:(int)totalAds;

/**
 *  The streaming protocol that the player will be using during this session
 *
 *  @param streamProtocol NSString name of the streaming protocol. e.g. HLS, DASH
 */
- (void)playerStreamingProtocol:(NSString *)streamProtocol;

/**
 *  The player has an issue loading the stream content
 *
 *  @param errorDescription NSString a description of the error that occured
 */
- (void)playerStreamLoadingError:(NSString *)errorDescription;

/**
 *  The player has detected the length of the media content
 *
 *  @param streamDuration double media duration in seconds
 */
- (void)playerDetectedStreamDuration:(double)streamDuration;

/**
 *  The player has selected a new rendition profile to stream
 *
 *  @param renditionProfileName NSString the name of the new rendition profile
 */
- (void)playerStreamRenditionSelected:(NSString *)renditionProfileName;

/**
 *  The user has selected a new subtitle track to display
 *
 *  @param subtitleTrackName NSString the title of the new subtitle track
 */
- (void)playerStreamSubtitledSelected:(NSString *)subtitleTrackName;

/**
 *  The player had a problem loading the subtitle track
 *
 *  @param errorDescription NSString a description of the error that occured
 */
- (void)playerSubtitleLoadingError:(NSString *)errorDescription;

/**
 *  Thge player had a problem opening an ad tracking URL
 *
 *  @param errorDescription NSString a description of the error that occured
 */
- (void)playerAdTrackingURLError:(NSString *)errorDescription;

/**
 *  The player has changed rate
 *
 *  @param rate float current player rate
 */
- (void)playerRateChanged:(float)rate;

/**
 *  The player has changed the external playback, such as cast to Airplay or back to device screen
 *
 *  @param change NSDictionary changes data
 */
- (void)playerExternalPlaybackChanged:(NSDictionary<NSString *,id> *)change;

/**
 *  player state changed
 *  @param oldState previous sate
 *  @param newState new state
 */
- (void)playerStateChangedFrom:(SUPState)oldState to:(SUPState)newState;


/**
 *  The player has moved to a different bitrate profile
 *
 *  @param newBitrate NSString the name of the new stream bitrate
 */
- (void)playerStreamBitrateChanged:(double)newBitrate;

/**
 *  A group of adverts(ad pod) is starting
 *
 *  @param podDuration double the duration of the ad pod
 *  @param podPosition NSString the position of the ad pod that was viewed
 *  @param podIndex NSInteger the index of the ad pod within the all ad pods in the content
 *  @param viewedPodIndex NSInteger the index of the ad pod that has been viewed
 */
- (void)playerAdPodStart:(double)podDuration podPosition:(NSString *)podPosition podIndex:(NSInteger)podIndex viewedPodIndex:(NSInteger)viewedPodIndex;

/**
 *  An ad pod has ended
 *
 *  @param podDuration double the duration of the ad pod
 *  @param podPosition NSString the position of the ad pod that was viewed
 *  @param podIndex NSInteger the index of the ad pod within the all ad pods in the content
 *  @param viewedPodIndex NSInteger the index of the ad pod that has been viewed
 */
- (void)playerAdPodEnd:(double)podDuration podPosition:(NSString *)podPosition podIndex:(NSInteger)podIndex viewedPodIndex:(NSInteger)viewedPodIndex;

/**
 *  The user has viewed an ad event
 *
 *  @param adID NSString the ID of the ad that was viewed
 *  @param adEventType NSString the position of the ad that was viewed
 *  @param adEventTime double the time that this event was viewed
 *  @param adIndex int the index of the ad within the ad group total
 */
- (void)playerAdViewEvent:(NSString *)adID adEventType:(NSString *)adEventType
              adEventTime:(double)adEventTime adIndex:(int)adIndex adPositionType:(NSString *)adPositionType;

/**
 *  UI user action while an ad was playing
 *
 *  @param adID NSString the ID of the ad
 *  @param adEventType NSString the position of the ad
 *  @param adActionTime double the start time of the action
 */
- (void)playerAdActionEvent:(NSString *)adID adEventType:(NSString *)adEventType adActionTime:(double)adActionTime;

/**
 *  The user has opened an ad
 *
 *  @param adID NSString the ID of the ad that was opened
 *  @param adTrackingURL NSString the ad URL that the player will open
 */
- (void)playerAdClickEvent:(NSString *)adID adTrackingURL:(NSString *)adTrackingURL;

/**
 *  The player has started buffering
 */
- (void)playerStreamBufferStart;

/**
 *  The player has finished buffering
 */
- (void)playerStreamBufferStop;

/**
 *  The player is starting playback from a particular time
 *
 *  @param resumeFromTime double the time to begin playback from
 */
- (void)playerIsStartingFromTime:(double)resumeFromTime;

/**
 *  The player was paused
 */
- (void)playerPaused;

/**
 *  The player has started to play
 */
- (void)playerPlaying;

/**
 *  The player has started seeking
 *
 *  @param seekStartTime double the time of the player when the seek was started
 */
- (void)playerSeekStart:(double)seekStartTime;

/**
 *  The player has finished seeking
 *
 *  @param seekStopTime double the destination time of the user seek
 */
- (void)playerSeekStop:(double)seekStopTime;

/**
 *  The player received new timed metadata items
 *
 *  @param metadataItems NSArray of AVMetadataItem
 */
- (void)playerUpdatedTimedMetadataItems:(NSArray<AVMetadataItem *> *)metadataItems;

/**
 *  The player updated adjustedProgress
 *
 *  @param adjustedProgress double adjusted progress without the ads duration
 */
- (void)playerUpdatedAdjustedProgress:(double)adjustedProgress;

/**
 *  The player has changed volume
 *
 *  @param newVolume float the new volume level the player has been set to. Values range from 0.0 to 1.0
 */
- (void)playerVolumeChanged:(float)newVolume;

/**
 *  The player entered fullscreen playback
 */
- (void)playerEnteredFullscreen;

/**
 *  The player exited fullscreen playback
 */
- (void)playerExitedFullscreen;

/**
 *  The player was closed
 */
- (void)playerDismissed;

/**
 *  A google cast event has occured in relation to the local player
 *
 *  @param castEventDescription NSString a description of the cast event, e.g. SessionStarted, CastDisconnected etc
 */
- (void)playerGoogleCastEvent:(NSString *)castEventDescription;

/**
 *  The player will resign active. Implement to handle UIApplicationWillResignActiveNotification
 *
 *  @param isPlayerPlayingInExternalMode YES if player currently casting in external device, such as ChromeCast or Airplay
 */
- (void)playerWillResignActiveWithExternalMode:(BOOL)isPlayerPlayingInExternalMode;

/**
 *  The player did become active. Implement to handle UIApplicationDidBecomeActiveNotification
 *
 *  @param isPlayerPlayingInExternalMode YES if player currently casting in external device, such as ChromeCast or Airplay
 */
- (void)playerDidBecomeActiveWithExternalMode:(BOOL)isPlayerPlayingInExternalMode;

/**
 *  Player likely play through without stalling
 */
- (void)playerBufferLikelyToKeepUp;

/**
 *  Player has consumed all buffered media
 */
- (void)playerBufferEmpty;

/**
 *  Internal media buffer is full
 */
- (void)playerBufferFull;

/**
 *  Metadata to be passed to chromecast receiver
 */
- (NSDictionary *)chromecastMetadata;



@end

#endif /* Protocols_h */
