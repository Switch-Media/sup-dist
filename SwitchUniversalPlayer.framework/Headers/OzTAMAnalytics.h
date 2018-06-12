//  Copyright © 2018 Switch Media. All rights reserved.

#import <Foundation/Foundation.h>
#import "SwitchProtocols.h"
#import "OzTAMService.h"
#import "OzTAMResource.h"
#import "OzTAMConfig.h"
@import AVFoundation;

/**
 The concrete base class for OzTAM analytics.
 */
@interface OzTAMAnalytics : NSObject <SwitchPlayerAnalyticsDelegate, OzTAMCallback>

/**
 The OzTAMConfig only stores vendor version which it should be the apps name and version number.
 */
@property (nonatomic, nonnull, strong, readonly) OzTAMConfig *config;

/**
 The OzTAMResource contents all the data needed for the OzTAMAnalytics object.
 */
@property (nonatomic, nonnull, strong, readonly) OzTAMResource *resource;

/**
 The OzTAMResource service object.
 */
@property (nonatomic, nonnull, strong, readonly) OzTAMService *service;

/**
 Pass NO for using OzTAM debug server
 */
@property (nonatomic, readonly) BOOL isProduction;

/**
 OzTAMService session ID
 */
@property (nonatomic, nonnull, copy, readonly) NSString *sessionID;

/**
 Designated initializer for OzTAMAnalytics
*/
- (instancetype _Nonnull )initWithConfig:(OzTAMConfig * _Nonnull)config
                                resource:(OzTAMResource * _Nonnull)resource
                            isProduction:(BOOL)isProduction;

/**
 Disabled initializer: use initWithConfig:resource:isProduction: instead
 */
- (instancetype _Nonnull )init __attribute((unavailable("use initWithConfig:resource:isProduction:")));

/**
 Start the OzTAM server
 */
- (void)startServer;

/**
 Update the resource object
 @param resource OzTAMResource OzTAM resource object
 @param completePrevious BOOL Passin YES to complete the current OzTAM session 
 */
- (void)updateResource:(OzTAMResource *_Nonnull)resource shouldCompletePrevious:(BOOL)completePrevious;

/**
 Stop the OzTAM session
 */
- (void)stop;

@end

