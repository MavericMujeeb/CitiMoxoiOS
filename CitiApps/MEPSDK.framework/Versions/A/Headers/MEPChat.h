//
//  MEPChat.h
//  MEPSDK
//
//  Copyright © 2020 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MEPChatTag: NSObject

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *value;

@end


/**
- MEPChatTypeGroupChat:moxtra group chat
- MEPChatTypePrivateChat: 1-1 private chat
- MEPChatTypeRelationChat: relation chat
- MEPChatTypeWeChat: WeChat channel
- MEPChatTypeWhatsApp: WhatsApp channel
- MEPChatTypeLiveChat: ACD Live chat
- MEPChatTypeServiceRequest: Service request chat
*/
typedef NS_ENUM(NSUInteger, MEPChatType) {
    MEPChatTypeGroupChat,
    MEPChatTypePrivateChat,
    MEPChatTypeRelationChat,
    MEPChatTypeWeChat,
    MEPChatTypeWhatsApp,
    MEPChatTypeLiveChat,
    MEPChatTypeServiceRequest
};

@interface MEPChat : NSObject

@property (nonatomic, copy, readonly) NSString *chatID;
@property (nonatomic, assign, readonly) MEPChatType chatType;
/**
A boolean value indicating whether chat is active.
*/
@property (nonatomic, assign, readonly) BOOL isActive;
/**
 Topic of this chat.
 */
@property (nonatomic, strong, readonly, nullable) NSString *topic;

/**
When the last feed was posted.
*/
@property (nonatomic, strong, readonly) NSDate *lastFeedTime;

/**
The count of unread feeds in this chat.
*/
@property (nonatomic, assign, readonly) UInt64 unreadFeedsCount;

/**
The content of the last feed.
*/
@property (nonatomic, strong, readonly, nullable) NSString *lastFeedContent;

/**
The user who create the last feed.
*/
@property (nonatomic, strong, readonly, nullable) MEPUser *lastFeedUser;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (void)setTagWithName:(NSString *)name value:(NSString *)value completionHandler:(void(^__nullable)(NSError * __nullable error))completionHandler;
- (void)getTagsWithCompletionHandler:(void(^)(NSArray<MEPChatTag *> *__nullable tagsOrNil, NSError *__nullable errorOrNil))completionHandler;

- (void)getMembersWithCompletion:(void(^__nullable)(NSError * __nullable errorOrNil, NSArray<MEPUser *> *__nullable members))completionHandler;
/**
Fetch cover of this chat
@param completionHandler A block object to be executed when the action completes
*/
- (void)fetchCoverWithCompletionHandler:(void (^__nullable)(NSError * __nullable errorOrNil, UIImage * __nullable image))completionHandler;

@end

NS_ASSUME_NONNULL_END
