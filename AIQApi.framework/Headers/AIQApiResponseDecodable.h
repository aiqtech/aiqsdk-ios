//
//  AIQApiResponseDecodable.h
//  AIQApi
//
//  Created by Khang Toh on 4/4/2019.
//  Copyright © 2019 AIQ. All rights reserved.
//

#ifndef AIQApiResponseDecodable_h
#define AIQApiResponseDecodable_h

#import <Foundation/Foundation.h>

/**
 Objects conforming to AIQAPIResponseDecodable can be automatically converted
 from a JSON dictionary that was returned from the AIQ API.
 */
@protocol AIQApiResponseDecodable <NSObject>

/**
 Parses response from AIQ API (in JSON format; represented as
 an `NSDictionary`) into an instance of the class.
 
 @param response - dictionary that represents the JSON object of this type
 
 @return The object represented by the JSON dictionary or nil if the object is not decodeable
 */
+ (nullable instancetype)decodedObjectFromAPIResponse:(nullable NSDictionary *)response;

/**
 The raw JSON response used to create the object. This can be useful for accessing
 fields that haven't yet been made into native properties in the SDK.
 */
@property (nonatomic, readonly, nonnull, copy) NSDictionary *allResponseFields;

@end


#endif /* AIQApiResponseDecodable_h */
