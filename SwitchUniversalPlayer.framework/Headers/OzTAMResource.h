//  Copyright © 2018 Switch Media. All rights reserved.

#import <Foundation/Foundation.h>
#import "OzTAMAnalyticsTypes.h"

@interface OzTAMResource : NSObject

/**
 Designated initializer for OzTAMResource
 
 @param mediaID NSString If you do not have the media ID use publisherID as mediaID.
 
 @param publisherID NSString An OzTAM issued string that uniquely identifies the publisher of the video.
 For Live Streaming, a unique publierherId is required for each channel.
 
 @param id3TagParser ID3TagParser It is for media type OzTAMMediaTypeLive only.
 When the player receives an AVMetadataItem from the stream, you will need to extract
 an ID 3 epoch time from that metadata item.
 return nil. if fail to extract the date or the media type is not OzTAMMediaTypeLive.
 
 @param dvrWindow NSTimeInterval The DVR window time for the live stream, recommend to pass in 120 seconds.
 Do not pass in an negative number.
 */
- (instancetype _Nonnull )initWithMediaID:(NSString * _Nonnull)mediaID
                                      url:(NSURL * _Nonnull)url
                                mediaType:(NSString * _Nonnull)mediaType
                              publisherID:(NSString * _Nonnull)publisherID
                               properties:(NSDictionary <NSString *, id> * _Nonnull)properties
                             id3TagParser:(ID3TagParser _Nonnull )id3TagParser
                                dvrWindow:(NSTimeInterval) dvrWindow;

/**
 Disabled initializer: use initWithMediaID:url:mediaType:publisherID:properties:id3TagParser:dvrWindow: instead
 */
- (instancetype _Nonnull )init __attribute((unavailable("init not allowed")));

/**
 Uniquely identifies the media across publishers
 */
@property (nonatomic, nonnull, copy) NSString *mediaID;

/**
 Media types are OzTAMMediaTypeLive, OzTAMMediaTypeLiveReal, and OzTAMMediaTypeVod
 */
@property (nonatomic, nonnull, copy) NSString *mediaType;

/**
 An OzTAM issued string that uniquely identifies the publisher of the video
 For Live Streaming, a unique publierherId is required for each channel
 */
@property (nonatomic, nonnull, copy) NSString *publisherID;

/**
 A dictionary object contains the program detail of a stream
 These key-value pairs will get send to OzTAM server as program metadata. A full list of keys is in OzTAMService.h file.
 */
@property (nonatomic, nonnull, copy) NSDictionary <NSString *, id> *properties;

/**
 The stream url
 */
@property (nonatomic, nullable, strong) NSURL *url;

/**
 The starting time of the stream, useful for VOD stream
 */
@property (nonatomic, nullable, strong) NSDate *startTime;

/**
 The end time of the stream, useful for VOD stream
 */
@property (nonatomic, nullable, strong) NSDate *endTime;

/**
 The DVR window time for the live stream
 */
@property (nonatomic) NSTimeInterval dvrWindow;

/**
 The duration of the stream
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 The ID3 Tag parser that parser the AVMetadataItem into NSDate
 */
@property (nonatomic, nonnull, copy) ID3TagParser id3TagParser;
@end
