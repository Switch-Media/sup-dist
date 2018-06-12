//  Copyright © 2017 Switch Media. All rights reserved.

#ifndef SwitchTypes_h
#define SwitchTypes_h

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

// Generic Blocks
typedef void (^CompletionBlock)(void);
typedef void (^BoolCompletionBlock)(BOOL);

#pragma mark State
typedef NS_ENUM(NSInteger, SUPState) {
    /**
     *  Player is opening a stream
     */
    SUPStateOpening,
    /**
     *  Player has started playing
     */
    SUPStateStarted,
    /**
     *  Player is playing
     */
    SUPStatePlaying,
    /**
     *  Player is Paused
     */
    SUPStatePaused,
    /**
     *  Player is playing (resumed from paused state)
     */
    SUPStateResumed,
    
    SUPStateSeeking,
    /**
     *  Player played video to completion.
     */
    SUPStateFinished,
    /**
     *  Player hasnt been configured with a stream url
     */
    SUPStateUndefined,
    /**
     *  Player started buffering
     */
    SUPStateDidStartBuffering,
    /**
     *  Player finished buffering
     */
    SUPStateDidEndBuffering,
    /**
     *  Player started seeking
     */
    SUPStateDidStartSeeking,
    /**
     *  Player finished seek
     */
    SUPStateDidSeekTo
};

#pragma mark Controls
typedef NS_ENUM(NSInteger, SUPControlAction) {
    SUPControlActionRequestFullscreenMode,
    SUPControlActionRequestWindowMode,
    SUPControlActionRequestPlayerDismiss,
    SUPControlActionControlsWillHide,
    SUPControlActionControlsDidHide,
    SUPControlActionControlsWillShow,
    SUPControlActionControlsDidShow,
    SUPControlActionCastExpandedControlsDidShow,
    SUPControlActionCastExpandedControlsDidHide
};

typedef NS_ENUM(NSInteger, SUPControlId) {
    ControlVolume,
    ControlPlayPause,
    ControlSlider,
    ControlFullscreenToggle,
    ControlDismiss,
    ControlFixedSpace,
    ControlCaption,
    ControlLive,
    ControlGoogleCast,
    ControlQuality,
    ControlFlexibleSpace,
    ControlFlexibleSpaceWide,
    ControlAspectRatioFillToggle
};

typedef NS_ENUM(NSInteger, ControlBar) {
    ControlBarTop,
    ControlBarCenter,
    ControlBarBottom
};

#pragma mark Error
typedef NS_ENUM(NSInteger, SUPError) {
    SUPErrorItemFailedErrorCode = 9001
};

#endif /* SwitchTypes_h */
