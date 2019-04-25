//
//  AIQApi.h
//  AIQApi
//
//  Created by Khang Toh on 2/4/19.
//  Copyright © 2019 AIQ. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for AIQApi.
FOUNDATION_EXPORT double AIQApiVersionNumber;

//! Project version string for AIQApi.
FOUNDATION_EXPORT const unsigned char AIQApiVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AIQApi/PublicHeader.h>
#import "AIQApiClient.h"
#import "AIQApiAuthToken.h"

@interface AIQApi : NSObject

+ (NSString *)apiVersion;

+ (NSString *)sdkVersion;

+ (AIQApiClient *)sharedApiClient;

+ (void)initializeWithAppKey:(NSString *)appKey appSecret:(NSString *)secret userId:(NSString *)userId;

+ (void)initializeWithAppKey:(NSString *)appKey appSecret:(NSString *)secret;

@end

