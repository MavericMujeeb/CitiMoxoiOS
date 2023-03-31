//
//  MEPUser.h
//  MEPSDK
//
//  Copyright © 2020 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface MEPUser : NSObject

/**
 Unique id of this user.
 */
@property (nonatomic, strong, readonly, nullable) NSString *uniqueId;

/**
 Firstname of this user.
 */
@property (nonatomic, strong, readonly, nullable) NSString *firstname;

/**
 Lastname of this user.
 */
@property (nonatomic, strong, readonly, nullable) NSString *lastname;

/**
 Email of this user.
 */
@property (nonatomic, strong, readonly, nullable) NSString *email;

/**
 Title of this user.
 */
@property (nonatomic, strong, readonly, nullable) NSString *title;
/**
Fetch profile image of this user
@param completionHandler A block object to be executed when the action completes
*/
- (void)fetchProfileWithCompletionHandler:(void (^_Nullable)(NSError * _Nullable errorOrNil, UIImage * _Nullable image))completionHandler;

@end

NS_ASSUME_NONNULL_END
