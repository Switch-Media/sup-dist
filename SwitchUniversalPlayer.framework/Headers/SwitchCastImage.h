//
//  Copyright © 2017 Switchmedia. All rights reserved.
//

@import Foundation;
@import GoogleCast;

@interface SwitchCastImage : NSObject

@property(nonatomic, strong, readonly) GCKImage *castImage;
@property(nonatomic, assign, readonly) GCKMediaMetadataImageType imageType;

/**
 * Constructs a new SwitchCastImage with the given URL, imageType and dimensions. Designated initializer.
 *
 * @param URL The URL of the image.
 * @param imageType GCKMediaMetadataImageType The image type
 * @param width The width of the image, in pixels.
 * @param height The height of the image, in pixels.
 * @throw NSInvalidArgumentException if the URL is <code>nil</code> or empty, or the dimensions are
 * invalid.
 */
- (instancetype) initWithURL:(NSURL *)URL imageType:(GCKMediaMetadataImageType)imageType width:(NSInteger)width height:(NSInteger)height;


@end
