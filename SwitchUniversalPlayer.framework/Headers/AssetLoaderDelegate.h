//  Copyright © 2017 Switch Media. All rights reserved.

@import UIKit;
@import AVFoundation;

@protocol SwitchPlayerDRMDelegate;

@interface AssetLoaderDelegate: NSObject<AVAssetResourceLoaderDelegate>
@property (nonatomic, weak) id<SwitchPlayerDRMDelegate> drmDelegate;

- (instancetype)initWithDRMDelegate:(id<SwitchPlayerDRMDelegate>)drmDelegate;

- (NSData *)getContentKeyfromKeyServerModuleWithRequest:(NSData *)requestBytes
                                  contentIdentifierHost:(NSString *)assetString
                                      resourceSpecifier:(NSString *)resourceSpecifier
                                            sessionInfo:(NSString *)session
                                                  error:(NSError **)errorOut;
@end
