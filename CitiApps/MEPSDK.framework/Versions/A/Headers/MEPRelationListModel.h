//
//  MEPRelationListModel.h
//  MEPSDK
//
//  Created by John Hu on 2021/9/26.
//  Copyright © 2021 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MEPRelation;
@protocol MEPRelationListModelDelegate;

@interface MEPRelationListModel : NSObject
@property (nonatomic, weak) id<MEPRelationListModelDelegate> __nullable delegate;

@property (nonatomic, strong) NSArray<MEPRelation *> *__nullable relations;

@end

@protocol MEPRelationListModelDelegate<NSObject>
@optional
/**
Tells the delegate that some relations have been created.
@param relationListModel The related relation list model.
@param createdRelations  An array containing created relations.
*/
- (void)relationListModel:(MEPRelationListModel *)relationListModel didCreateRelations:(NSArray<MEPRelation *> *)createdRelations;

/**
Tells the delegate that some relations have been updated.
 @param relationListModel The related relation list model.
@param updatedRelations  An array containing updated relations.
*/
- (void)relationListModel:(MEPRelationListModel *)relationListModel didUpdateRelations:(NSArray<MEPRelation *> *)updatedRelations;

/**
Tells the delegate that some relations have been deleted.
 @param relationListModel The related relation list model.
@param deletedRelations  An array containing deleted relations.
*/
- (void)relationListModel:(MEPRelationListModel *)relationListModel didDeleteRelations:(NSArray<MEPRelation *> *)deletedRelations;
@end

NS_ASSUME_NONNULL_END
