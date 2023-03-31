//
//  MXBBCodeParser.h
//  MXBBCodeKit
//
//  Created by rookie on 2020/7/1.
//  Copyright © 2020 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class MXBBCodeNode;

NS_ASSUME_NONNULL_BEGIN

@interface MXBBCodeParser : NSObject

+ (MXBBCodeNode *)parse:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
