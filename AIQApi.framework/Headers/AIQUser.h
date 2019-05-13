//
//  AIQUser.h
//  AIQApi
//
//  Created by Khang Toh on 1/4/2019.
//  Copyright © 2019 AIQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AIQApiResponseDecodable.h"

NS_ASSUME_NONNULL_BEGIN

/**
 AIQUser request response class for AIQ User API
 */
@interface AIQUserAPIResponse : NSObject <AIQApiResponseDecodable>

@property (nonatomic, readonly, copy) NSString *email;
@property (nonatomic, readonly, copy) NSString *name;
@property (nonatomic, readonly, copy) NSString *gender;
@property (nonatomic, readonly, copy) NSString *birthdate;
@property (nonatomic, readonly, copy) NSString *avatar;
@property (nonatomic, readonly, copy) NSString *token;

@end

/**
 AIQUser main class for AIQUser object
 */
@interface AIQUser : NSObject


@property (nonatomic, readwrite) NSString *AIQUserEmail;
@property (nonatomic, readwrite) NSString *AIQUserPassword;
@property (nonatomic, readwrite) NSString *AIQUserName;
@property (nonatomic, readwrite) NSString *AIQUserBirthdate;
@property (nonatomic, readwrite) NSString *AIQUserAvatar;

@property (nonatomic, readwrite) NSString *AIQUserId;
@property (nonatomic, readwrite) NSString *AIQUserGender;
@property (nonatomic, readwrite) NSString *AIQUserAge;
@property (nonatomic, readwrite) NSString *AIQDeviceType;
@property (nonatomic, readwrite) NSString *AIQDeviceModel;
@property (nonatomic, readwrite) NSString *AIQDeviceVersion;
@property (nonatomic, readwrite) NSString *AIQAppVersion;

@property (nonatomic, readwrite) float AIQUserLat;
@property (nonatomic, readwrite) float AIQUserLng;

+ (instancetype)initFromDictionary:(NSDictionary *)userDictionary;
- (instancetype)initFromDictionary:(NSDictionary *)userDictionary;

- (NSDictionary *)requiredParameters;
- (NSDictionary *)optionalParameters;
- (NSDictionary *)allParameters;
- (NSDictionary *)loginParameters;

@end

NS_ASSUME_NONNULL_END
