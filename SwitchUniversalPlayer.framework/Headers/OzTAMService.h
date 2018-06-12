//
//  OzTAMService.h
//  OzTAMService
//
//  Copyright © 2015 OzTAM. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol OzTAMCallback < NSObject >

- (double)getMediaPosition;

@end


@interface OzTAMService : NSObject

- (instancetype)initWithPublisherId:(NSString *) publisherId
                      vendorVersion: (NSString *) vendorVersion
                     productionService:(bool) productionService
                     verboseLogging:(bool) verboseLogging;

- (instancetype)initWithPublisherId:(NSString *) publisherId
                      vendorVersion:(NSString *) vendorVersion
                     productionService:(bool) productionService
                     verboseLogging:(bool) verboseLogging
                     useHTTPS:(bool) useHTTPS;

- (void)adBegin;

- (void)adComplete;

- (void)beginPlaybackWithPublisherId:(NSString*) publisherId mediaId:(NSString *)mediaId
                     url:(NSString *)url
                        mediaDuration:(float)mediaDuration
                        callbackObject:(id<OzTAMCallback>)positionCallback
              properties:(NSDictionary *)properties
                     mediaType:(NSString *)mediaType;

- (void)complete;

- (NSString *)getVersion;

- (NSString *)getSessionID;

- (void)haltProgress;

- (void)onProgressFunction:(NSTimer*)timer;

- (void)resumeProgress;

- (void)seekBegin;

- (void)seekComplete;

- (void)startSessionWithMediaId:(NSString *)mediaId
                    url:(NSString *)url
                    mediaDuration:(float)mediaDuration
                    mediaType:(NSString *)mediaType;

- (void)stop;


@end


FOUNDATION_EXPORT NSString *const PROP_ALT_MEDIA_ID;

FOUNDATION_EXPORT NSString *const PROP_SERIES_ID;

FOUNDATION_EXPORT NSString *const PROP_EPISODE_ID;

FOUNDATION_EXPORT NSString *const PROP_SERIES_NAME;

FOUNDATION_EXPORT NSString *const PROP_EPISODE_NAME;

FOUNDATION_EXPORT NSString *const PROP_CHANNEL;

FOUNDATION_EXPORT NSString *const PROP_CLASSIFICATION;

FOUNDATION_EXPORT NSString *const PROP_DVB_TRIPLET;

FOUNDATION_EXPORT NSString *const PROP_POST_CODE;

FOUNDATION_EXPORT NSString *const PROP_PROGRAM_ID;

FOUNDATION_EXPORT NSString *const PROP_PROGRAM_NAME;

FOUNDATION_EXPORT NSString *const PROP_GENRE;

FOUNDATION_EXPORT NSString *const PROP_DEMO1;

FOUNDATION_EXPORT NSString *const PROP_DEMO2;

FOUNDATION_EXPORT NSString *const PROP_DEMO3;

FOUNDATION_EXPORT NSString *const PROP_DEVICE_ID;

FOUNDATION_EXPORT NSString *const PROP_CONNECTION_TYPE;

FOUNDATION_EXPORT NSString *const PROP_STREAMING_TYPE;

FOUNDATION_EXPORT NSString *const PROP_LATITUDE;

FOUNDATION_EXPORT NSString *const PROP_LONGITUDE;

FOUNDATION_EXPORT NSString *const PROP_ORIGIN_MEDIA_ID;

