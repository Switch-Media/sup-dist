# Release Update

## 3.0.0 

### Changes
Refactor OzTAM analytics:
Replace SwitchOztam with OzTAMAnalytics, OzTAMAnalyticsLive, and OzTAMAnalyticsVOD.
For more detail of migration from SwitchOzam to OzTAMAnalytics see migration.md file.
Separate OzTAM from SwitchUniversalPlayer.
OzTAMAnalytics can now be inserted into SwitchUniversalPlayer's analyticsDelegate.

SwitchUnviersalPlayer:
SwitchPlayer instance (without AdEase) can now create from SwitchUniversal player.

Add new functions in SwitchUnviersalPlayer.h
- +(SwitchPlayer *)player
- -(NSString *)versionString

Add new functions in SwitchProtocols.h
- -(void)playerRateChanged:(float)rate
- -(void)playerOpenURL:(NSURL *)url
- -(void)playerExternalPlaybackChanged:(NSDictionary<NSString *,id> *)change
- -(void)playerStateChangedFrom:(SUPState)oldState to:(SUPState)newState
- -(void)playerUpdatedTimedMetadataItems:(NSArray<AVMetadataItem *> *)metadataItems
- -(void)playerUpdatedAdjustedProgress:(double)adjustedProgress
- -(void)playerDidBecomeActiveWithExternalMode:(BOOL)isPlayerPlayingInExternalMode
- -(void)playerWillResignActiveWithExternalMode:(BOOL)isPlayerPlayingInExternalMode
-  -(void)playerBufferLikelyToKeepUp
- -(void)playerBufferEmpty
- -(void)playerBufferFull

Remove properties and functions in SwitchProtocols.h

- oztamDebug
- oztamPublisherIDForLiveStreams
- oztamMediaIDForLiveStreams
- oztamLiveEventStartTime
- oztamLiveEventEndTime
- oztamVendor
- oztamExtraProperties

- -(void)playerWillResignActive:(SwitchPlayer *)player
- -(void)playerDidBecomeActive:(SwitchPlayer *)player

Remove notifications
- SUPSeekPreviousAdCompletedNotification
- SUPPlayerSeekStartNotification
- SUPPlayerSeekedNotification
- SUPTimedMetadataNotification

Remove functions in SwitchPlayer.h
- -(void)prepareForNewEventOnLiveStream:(BOOL)isPreviousEventComplete
- -(void)newEventStartedOnLiveStream:(BOOL)shouldBeginPlayback
- -(void)newEventStartedOnLiveStream

## 2.10.0 @ 23/5/2018

### Resolved

    [SBSAD-290]


### Changes

- Local SwitchPlayer will now hand over collected metadata for Conviva to be used on the google cast receiver.


## 2.8.14 @ 26/4/2018

### Resolved

    [SBSCAST-328], [SBSAD-195]


### Changes

- Conviva session ended before starting once more after chromecast is deactivated.
- Media duration is now passed to chromecast receiver from config data if already connected to cast device on load.


## 2.8.13 @ 29/3/2018

### Resolved

    [SBSAD-255]


### Changes

- Conviva ad events are now sent together with the pod events, before and after.
- Conviva viewed ad pod index added to analytics.
- Metadata key values updated based on conviva feedback.


## 2.8.12 @ 23/2/2018

### Resolved

    [SBSAD-224], [SBSAD-227], [SBSAD-244]


### Changes

- AdPod events added for PodStart and PodEnd.
- Default value for Oztam vendor version updated.
- Fixed bug with ad playing status while chromecasting.


## 2.8.11 @ 29/12/2017

### Resolved

    [FREEV-1248]


### Changes

- ControlAspectRatioFillToggle button added to player. This controls the media fill behaviour in the player view.


## 2.8.10 @ 17/12/2017

### Resolved

    [FREEV-1238]


### Changes

- AppDelegate flags added for home indicator behaviour (iPhoneX), ignoreBottomSafeAreaForHomeIndicator and autoHideHomeIndicator. See inline header comments for more details.


## 2.8.9 @ 15/12/2017

### Resolved

    [SBSAD-206], [SBSAD-178]


### Changes

- Player controls are now able to hide while AirPlay mirroring is active
- resumeWhenBackToForeground added so player can be configured whether or not to resume content automatically as it comes into foreground.


## 2.8.8 @ 05/12/2017

### Resolved

    [SBSAD-179]


### Changes

- Conviva SDK updated to 2.116.0.31784


## 2.8.7 @ 24/11/2017

### Resolved

    [SBSAD-190]


### Changes

- Fix a crash which is caused by Chromecast context image picker


## 2.8.6 @ 16/11/2017

### Resolved

    [SBSAD-190]


### Changes

- Fix a crash when AVPlayer is not properly released


## 2.8.5 @ 14/11/2017

### Resolved

    [AD-1022]


### Changes

- Fix an issue with duplicated adease events from previously closed player


## 2.8.4 @ 09/11/2017

### Resolved

    [SBSAD-181]


### Changes

- Fix an issue with no OzTAM event for VOD content


## 2.8.3 @ 08/11/2017

### Resolved

    [SBSAD-140], [SBSAD-145], [SBSAD-167]



### Changes

- Fix false playing state reported immediately before the pre-roll starts
- Fix video playback failures not reported
- Fix bitrate info is not displayed when player is brought to foreground
- Update Google Cast SDK to from 3.3 to 3.5
- Update GoogleAds IMA iOS SDK from 3.5 to 3.6


## 2.8.1 @ 23/10/2017

### Resolved

    [MAD-24]



### Changes

- Custom images can now be assigned to each google cast UI component. If more than one `SwitchCastImage` is added, the image with the matching `imageType` or closest matching size orientation will be used.
  - See example usage of `Custom Cast Images`
  - note: We have logged an issue with Google on the component matching, this should hopefully be resolved shortly with an iOS Cast-SDK update. https://issuetracker.google.com/issues/66861640



### Example

- Custom Cast Images

  ```objective-c
  
  SwitchCastImage *landscapeDialogImage = [[SwitchCastImage alloc] initWithURL:[NSURL URLWithString:@"http://www.sbs.com.au/guide/sites/sbs.com.au.guide/files/styles/full/public/midnight-sun-promo.jpg?itok=6aUQBP3W"] imageType:GCKMediaMetadataImageTypeCastDialog width:704 height:396];
  SwitchCastImage *portraitBackgroundImage = [[SwitchCastImage alloc] initWithURL:[NSURL URLWithString:@"https://www.sbs.com.au/guide/sites/sbs.com.au.guide/files/styles/single/public/midnight-sun-helicopter.jpg?itok=2BxHyTI9&mtime=1480569375"] imageType:GCKMediaMetadataImageTypeBackground width:220 height:290];
  SwitchCastImage *landscapeBackgroundImage = [[SwitchCastImage alloc] initWithURL:[NSURL URLWithString:@"https://www.sbs.com.au/guide/sites/sbs.com.au.guide/files/styles/body_image/public/albin-grenholm.jpg?itok=qZe4itTk&mtime=1480554253"] imageType:GCKMediaMetadataImageTypeBackground width:700 height:394];
  SwitchCastImage *miniControllerImage = [[SwitchCastImage alloc] initWithURL:[NSURL URLWithString:@"https://videocdn-sbs.akamaized.net/u/video/SBS/managed/images/2016/11/24/816603203893_11240211_Midninhtsun_programslarge.jpg"] imageType:GCKMediaMetadataImageTypeMiniController width:460 height:258];
  
  NSMutableArray<SwitchCastImage*> *castImages = [NSMutableArray new];
  [castImages addObject:landscapeDialogImage];
  [castImages addObject:portraitBackgroundImage];
  [castImages addObject:landscapeBackgroundImage];
  [castImages addObject:miniControllerImage];
  
  player.castImages = [castImages copy];
  ```



## 2.8.0 @ 16/10/2017

### Resolved

    [SBSAD-159], [SBSAD-170], [SBSAD-167], [SBSAD-140], [SBSAD-166], [SBSAD-159], [SBSAD-143]
    [SBSAD-144], [SBSAD-142], [SBSAD-141]
    [MAD-35], [AD-1083]



### Changes

- Add `SwitchAnalyticsDelegateManager` to manage multiple analytics delegates. 
  - See example usage of `BasicAnalytics`
- Switch application to background will no longer pause the player if the player is currently using AirPlay
- `ConvivaAnalytcis` has been moved inside of SDK in this version, see example usage below
  - New constructor function `initWithServerURL:customKey:`
  - `start` function has been removed



### Examples

- Multiple analytics delegates

  ```objective-c
  ConvivaAnalytics *convivaAnalytics = [[ConvivaAnalytics alloc] initWithServerURL:serverURL customKey:key];

  // BasicAnalytics applys to protocol `SwitchPlayerAnalyticsDelegate`
  BasicAnalytics *basicAnalytics = [BasicAnalytics new];

  SwitchAnalyticsDelegateManager *analyticsManager = [[SwitchAnalyticsDelegateManager alloc] initWithDelegates:@[convivaAnalytics, basicAnalytics]];

  SwitchUniversalPlayer *sharedInstance = [SwitchUniversalPlayer sharedInstance];
  sharedInstance.analyticsDelegate = analyticsManager;
  ```

  ​

- `ConvivaAnalytics`

  ```objective-c
  ConvivaAnalytics *convivaAnalytics = [[ConvivaAnalytics alloc] initWithServerURL:serverURL customKey:key];
  convivaAnalytics.debug = isDebug;   
  convivaAnalytics.viewerID = <#viewer ID#>;
  convivaAnalytics.serverResource = <#server resource#>;
  convivaAnalytics.assetName = <#asset name#>;
  convivaAnalytics.applicationName = <#application name#>;
  convivaAnalytics.isLiveStream = <#is live stream#>;
  convivaAnalytics.streamDuration = <#stream duration#>;

  SwitchAnalyticsDelegateManager *analyticsManager = [[SwitchAnalyticsDelegateManager alloc] initWithDelegates:@[convivaAnalytics]];

  SwitchUniversalPlayer *sharedInstance = [SwitchUniversalPlayer sharedInstance];
  sharedInstance.analyticsDelegate = analyticsManager;
  ```
