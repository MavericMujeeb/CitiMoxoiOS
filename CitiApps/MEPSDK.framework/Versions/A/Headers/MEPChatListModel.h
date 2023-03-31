//
//  MEPChatListModel.h
//  MEPSDK
//
//  Created by Moxtra on 2020/12/16.
//  Copyright © 2020 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>
@class MEPChat;
@protocol MEPChatListModelDelegate;

NS_ASSUME_NONNULL_BEGIN
@interface MEPChatListModel : NSObject
@property (nonatomic, weak) id<MEPChatListModelDelegate> delegate;
/**
Return an array containing all chats.
*/
- (NSArray<MEPChat *> *)chats;
@end

@protocol MEPChatListModelDelegate<NSObject>
@optional
/**
Tells the delegate that some chats have been created.
@param chatListModel The related chat list model.
@param createdChats  An array containing created chats.
*/
- (void)chatListModel:(MEPChatListModel *)chatListModel didCreateChats:(NSArray<MEPChat *> *)createdChats;

/**
Tells the delegate that some chats have been updated.
@param chatListModel The related chat list model.
@param updatedChats  An array containing updated chats.
*/
- (void)chatListModel:(MEPChatListModel *)chatListModel didUpdateChats:(NSArray<MEPChat *> *)updatedChats;

/**
Tells the delegate that some chats have been deleted.
@param chatListModel The related chat list model.
@param deletedChats  An array containing deleted chats.
*/
- (void)chatListModel:(MEPChatListModel *)chatListModel didDeleteChats:(NSArray<MEPChat *> *)deletedChats;
@end

NS_ASSUME_NONNULL_END
