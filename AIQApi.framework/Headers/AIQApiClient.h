//
//  AIQApiClient.h
//  AIQApi
//
//  Created by Khang Toh on 2/4/19.
//  Copyright © 2019 AIQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AIQBlocks.h"

@class AIQUser;

NS_ASSUME_NONNULL_BEGIN

/// AIQApiHeaderOptionsGender
/// For indicating user gender for API requests
typedef NS_ENUM(NSUInteger, AIQApiHeaderOptionsGender) {
    AIQApiHeaderOptionsGenderUnspecified = 1,
    AIQApiHeaderOptionsGenderDefault = AIQApiHeaderOptionsGenderUnspecified,
    AIQApiHeaderOptionsGenderFemale,
    AIQApiHeaderOptionsGenderMale
};

/// AIQApiClient
@interface AIQApiClient : NSObject <NSURLSessionTaskDelegate>

+ (instancetype)sharedClient;

+ (instancetype)initializeWithAppKey:(NSString *)appKey appSecret:(NSString *)secret;

+ (instancetype)initializeWithAppKey:(NSString *)appKey appSecret:(NSString *)secret userId:(NSString *)userId;

// Optional user profile methods

+ (void)setUserAge:(NSInteger)age;

+ (void)setUserGender:(AIQApiHeaderOptionsGender)gender;

+ (void)setUserLocationLatitude:(float)lat longitude:(float)lng;

+ (void)setBaseUrl:(NSString*)url;
@end

/**
 AIQApiClient extensions for user related APIs.
 */
@interface AIQApiClient (User)

/**
 Updates an AIQUser using AIQ user API
 
 @param user The AIQUser object
 @param completion  The callback to run with the returned response from the API request.
 */
- (void)updateUserProfile:(AIQUser *)user withCompletion:(AIQUserRequestCompletionBlock)completion;


- (void)updateUserAvatar:(AIQUser *)user
               withImage:(UIImage *)image
          withCompletion:(AIQUserRequestCompletionBlock)completion;

- (void)retrieveUser:(NSString *)userToken withCompletion:(AIQUserRequestCompletionBlock)completion;

- (void)registerUser:(AIQUser *)user withCompletion:(AIQUserRequestCompletionBlock)completion;

- (void)loginUser:(AIQUser *)user withCompletion:(AIQUserLoginCompletionBlock)completion;

- (void)logoutUser:(AIQUser *)user withCompletion:(AIQUserRequestCompletionBlock)completion;

@end


/**
 AIQApiClient extensions for collections related APIs.
 */
@interface AIQApiClient (Collections)
/**
 Retrieves the collections available for an AIQ App
@param completion The AIQCollectionsCompletionBlock callback returns an array in results
 */
- (void)retrieveCollectionsWithCompletion:(AIQCollectionsCompletionBlock)completion;

@end

/**
 AIQApiClient extensions for scan history related APIs.
 */
@interface AIQApiClient (ScanHistory)
- (void)retrieveScanHistoryWithCount:(NSInteger)count
                          withOffset:(NSInteger)offset
                    withCompletion:(AIQScanHistoryCompletionBlock)completion;

@end

/**
 AIQApiClient extensions for scan (searching) related APIs.
 */
@interface AIQApiClient (Scan)

- (void)scanWithUrl:(NSURL *)fileUrl
     withCompletion:(AIQScanCompletionBlock)completion;

- (void)scanWithUrl:(NSURL *)fileUrl
     withCollection:(NSString *)collectionId
     withCompletion:(AIQScanCompletionBlock)completion;

- (void)scanWithImage:(UIImage *)image
     withCompletion:(AIQScanCompletionBlock)completion;

- (void)scanWithImage:(UIImage *)image
       withCollection:(NSString *)collectionId
       withCompletion:(AIQScanCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
