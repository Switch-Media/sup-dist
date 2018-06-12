//  Copyright © 2017 Switch Media. All rights reserved.

@import Foundation;
#import "SwitchProtocols.h"

@interface SwitchAnalyticsDelegateManager : NSObject <SwitchPlayerAnalyticsDelegate>
@property (nonatomic, copy, readonly) NSArray<id<SwitchPlayerAnalyticsDelegate>> *delegates;
- (instancetype)initWithDelegates:(NSArray<id<SwitchPlayerAnalyticsDelegate>> *)delegates;

- (void)addDelegate:(id<SwitchPlayerAnalyticsDelegate>)delegate;
- (void)removeDelegate:(id<SwitchPlayerAnalyticsDelegate>)delegate;
- (void)removeDelegatesWithClass:(Class)delegateClass;
- (NSDictionary *)chromecastMetadata;
@end
