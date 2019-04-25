//
//  AIQApiAuthToken.h
//  AIQApi
//
//  Created by Khang Toh on 2/4/19.
//  Copyright © 2019 AIQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AIQApiResponseDecodable.h"
#import "AIQBlocks.h"

NS_ASSUME_NONNULL_BEGIN

@interface AIQApiAuthToken : NSObject <AIQApiResponseDecodable>

+ (instancetype)token;

+ (void)refresh:(__nullable AIQApiAuthTokenCompletionBlock)completion;

- (BOOL)isValid;

- (BOOL)expired;
@end

NS_ASSUME_NONNULL_END
