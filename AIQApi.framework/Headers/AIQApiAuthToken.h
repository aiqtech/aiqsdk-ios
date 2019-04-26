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

@interface AIQApiAuthToken : NSObject <AIQApiResponseDecodable, NSCopying>

@property (nonatomic, assign) NSTimeInterval expireIn;
@property (nonatomic, assign) NSTimeInterval expire;
@property (nonatomic, readwrite, nonnull, copy) NSDictionary *allResponseFields;
@property (nonatomic, readwrite, nonnull, copy) NSString *token;

+ (instancetype)token;

+ (void)refresh:(__nullable AIQApiAuthTokenCompletionBlock)completion;

- (BOOL)isValid;

- (BOOL)expired;

+ (void)setToken:(nonnull id)token;

+ (void)clear;

@end

NS_ASSUME_NONNULL_END
