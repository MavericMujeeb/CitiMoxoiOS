//
//  MXCredentialManager.h
//  MXCredentialKit
//
//  Created by Rookie Zinc on 2018/9/4.
//  Copyright © 2018 rookiezn. All rights reserved.
//

#if __has_include(<MXCredentialManager/MXCredential.h>)
#import <MXCredentialManager/MXCredential.h>
#else
#import "MXCredential.h"
#endif

#import <Security/Security.h>
#import <LocalAuthentication/LocalAuthentication.h>

FOUNDATION_EXPORT NSErrorDomain MXCredentialErrorDomain;
NS_ERROR_ENUM(MXCredentialErrorDomain)
{
    MXCredentialErrorNotFound = 1, // the credential is not found
    MXCredentialErrorDuplicate, // another credential with the same identifier exists
    MXCredentialErrorBadRequest, // parameter is not correct
    MXCredentialErrorOther // other error. You may check `MXCredentialErrorRawStatusCodeKey` in userInfo for further information
};

// used as NSError userInfo key, the corresponding value is NSNumber wrapping OSStatus code.
// See https://developer.apple.com/documentation/security/1542001-security_framework_result_codes?language=objc
FOUNDATION_EXPORT NSErrorUserInfoKey MXCredentialErrorRawStatusCodeKey;

@interface MXCredentialManager : NSObject

// The default credential manager. We may add other managers that storing credentials in iCloud or something like this.
+ (instancetype)defaultManager;

// Get credential
- (void)retrieveCredentialWithType:(MXCredentialType)type
                        identifier:(NSString *)identifier
                        promptText:(NSString *)promptText
                 completionHandler:(void (^)(MXCredential *credential, NSError *error))completionHandler;

// Add credential
- (void)addCredentialWithType:(MXCredentialType)type
                   identifier:(NSString *)identifier
                         data:(id)data
                accessControl:(SecAccessControlRef)accessControl
                  authContext:(LAContext *)authContext
            completionHandler:(void (^)(MXCredential *credential, NSError *error))completionHandler;

// Update credential
- (void)updateCredentialWithType:(MXCredentialType)type
                      identifier:(NSString *)identifier
                            data:(id)data
                   accessControl:(SecAccessControlRef)accessControl
                     authContext:(LAContext *)authContext
               completionHandler:(void (^)(NSError *error))completionHandler;

// Delete credential
- (void)deleteCredentialWithType:(MXCredentialType)type
                      identifier:(NSString *)identifier
                     completionHandler:(void (^)(NSError *error))completionHandler;

#pragma mark - Unavailable

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end
