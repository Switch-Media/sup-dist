//  Copyright © 2018 Switch Media. All rights reserved.

@import Foundation;

@interface OzTAMConfig : NSObject

/**
 Vendor name and Vendor version number for indentifing your app in OzTAM, verndorVersion must not be empty
 */
@property (nonatomic, nonnull, copy) NSString *vendorVersion;

/**
 Designated initializer
 @param vendorVersion NSString Vendor name and version number for indentifing your app in OzTAM
 */
- (instancetype _Nonnull )initWithVendorVersion:(NSString * _Nonnull)vendorVersion;

/**
 Disabled initializer: use initWithVendorVersion: instead
 */
- (instancetype _Nonnull )init __attribute((unavailable("use initWithVendorVersion:")));
@end
