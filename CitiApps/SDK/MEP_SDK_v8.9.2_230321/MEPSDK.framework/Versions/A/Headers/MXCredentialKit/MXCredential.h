//
//  MXCredential.h
//  MXCredentialKit
//
//  Created by Rookie Zinc on 2018/9/4.
//  Copyright © 2018 rookiezn. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, MXCredentialType)
{
    MXCredentialTypePassword,
    MXCredentialTypeInvalid
};

@interface MXCredential : NSObject

/**
 see MXCredentialType
 */
@property (nonatomic, assign, readonly) MXCredentialType type;

/**
 Used to identify a credential
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 The data of this credential. This property will be nil if it is invalidated, such as after deleted
 */
@property (nonatomic, strong, readonly) id data;

@end
