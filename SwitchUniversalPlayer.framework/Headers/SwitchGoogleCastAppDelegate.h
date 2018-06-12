//  Copyright © 2017 Switch Media. All rights reserved.

@import UIKit;

@interface SwitchGoogleCastAppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@property (copy, nonatomic) NSString *googleCastReceiverAppID;
@property (nonatomic) BOOL googleCastDebugLoggingEnabled;

/**
 *  If set to YES this allows the player (and other views) to take over the full screen on devices without a hardware home button (iPhoneX).
 */
@property (nonatomic) BOOL ignoreBottomSafeAreaForHomeIndicator;

/**
 *  If set to YES the home indicator will automatically fade after each view controller appears.
 */
@property (nonatomic) BOOL autoHideHomeIndicator;

- (void)setCastControlBarsEnabled:(BOOL)notificationsEnabled;
- (BOOL)castControlBarsEnabled;
- (BOOL)areCastMiniControlsVisible;


/**
 * @brief Provide the main view controller of the application to construct Google Cast UI
 * @discussion Default implementation requires following things to be defined:
 *
 *  - a storyboard named as `Main`
 *
 *  - a navigation controller named as `MainNavigation` in above storyboard
 *
 *  Override this function to provide view controller that you want
 *
 * @return main UIViewController
 */
- (UIViewController *)mainViewController;

@end
