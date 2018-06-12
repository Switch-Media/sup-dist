
//  Copyright © 2018 Switch Media. All rights reserved.

#ifndef OzTAMAnalyticsTypes_h
#define OzTAMAnalyticsTypes_h
@import AVFoundation;
/**
 The parser that read an AVMetadataItem and generates a date object
 @discusion reading the epoch time from the live stream metadata item, the time will be used for OzTAM tracking
 @param item AVMetadataItem item that to be parsed into an NSDate object
 */
typedef NSDate * _Nullable (^ID3TagParser)(AVMetadataItem * _Nonnull item);

#endif /* OzTAMAnalyticsTypes_h */
