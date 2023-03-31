//
//  MEPMeet.h
//  MEPSDK
//
//  Copyright © 2020 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MEPUser;
@interface MEPMeet : NSObject

/**
The id of this meet.
*/
@property (nonatomic, copy, readonly) NSString *meetID;

/**
Topic of the meet.
*/
@property (nonatomic, copy, readonly) NSString *topic;

/**
has password.
*/
@property (nonatomic, readonly) BOOL hasPassword;

/**
password of the meet.
*/
@property (nonatomic, copy, readonly, nullable) NSString *password;

/**
Is meeting in progress.
*/
@property (nonatomic, assign, readonly) BOOL isInProgress;

/**
Agenda of the meet.
*/
@property (nonatomic, copy, readonly) NSString *agenda;

/**
 Start time of this meet. If the meet has not started yet, the value in this property will be nil.
 */
@property (nonatomic, strong, readonly, nullable) NSDate *startTime;

/**
 End time of this meet. If the meet has not ended yet, the value in this property will be nil.
 */
@property (nonatomic, strong, readonly, nullable) NSDate *endTime;

/**
 Scheduled start time of this meet. If the meet was not scheduled, the value in this property will be nil.
 */
@property (nonatomic, strong, readonly, nullable) NSDate *scheduledStartTime;

/**
 Scheduled end time of this meet. If the meet was not scheduled, the value in this property will be nil.
 */
@property (nonatomic, strong, readonly, nullable) NSDate *scheduledEndTime;

/**
Host of the meet.
*/
@property (nonatomic, strong) MEPUser *host;

/**
Particiapnts of the meet
 */
@property (nonatomic, strong, readonly) NSArray<MEPUser *> *participants;

@end

NS_ASSUME_NONNULL_END
