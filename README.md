# aiqsdk-ios
AIQSDK is a cocoapod for AIQ's iOS SDK.

## Integration using Cocoapods

AIQSDK is structure with subspecs with the default being AIQApi, the iOS library for using AIQ's API.

Just with any other Cocoapod's project, to use AIQ's API for your iOS application, all you need is to include AIQSDK in your podfile.

Using [CocoaPods](https://cocoapods.org), add to your podfile:

```
pod 'AIQSDK'
```

Run `pod install` to download AIQSDK and install it into your project. AIQSDK currently has no third party dependencies.

Initialization
---------------
In your App Delegate, initialise the SDK with the App ID and secret you obtained from the [AIQ Dashboard Portal](https://dashboard.aiq.tech):

```objc
    #import <AIQApi/AIQApi.h>
```

```objc
    [AIQApi initializeWithAppKey:@"appID" appSecret:@"appSecret"];
```

Search using Image
----------------
AS part of AIQAiq framework, you can easily make API calls to AIQ's platform API using AIQApiClient.

This is especially useful when you have built your own camera / scanner view.
```objc
    [[AIQApiClient sharedClient] scanWithImage:[UIImage imageWithData:imageData] 
                               withCompletion:^(AIQScanAPIResponse * _Nullable result, NSError * _Nullable error)
    {                  
        // no matches found
        if (error) {
            // handle it
            // display no image found
        } else {

            if (result.payloadUrl)
            {
                NSURL *payloadURL = [NSURL URLWithString:result.payloadUrl];
                // present and load trigger url in your webview controller
            }
        }
    }];
```      

Search using Url
----------------
AS part of AIQAiq framework, you can easily make API calls to AIQ's platform API using AIQApiClient.

This is especially useful when you have built your own camera / scanner view.
```objc
    [[AIQApiClient sharedClient] scanWithUrl:imageUrl 
                              withCompletion:^(AIQScanAPIResponse * _Nullable result, NSError * _Nullable error)
    {                  
        // no matches found
        if (error) {
            // handle it
            // display no image found
        } else {

            if (result.payloadUrl)
            {
                NSURL *payloadURL = [NSURL URLWithString:result.payloadUrl];
                // present and load trigger url in your webview controller
            }
        }
    }];
```      
     
     


