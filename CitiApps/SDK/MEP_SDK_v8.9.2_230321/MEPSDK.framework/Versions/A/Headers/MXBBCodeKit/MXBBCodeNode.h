//
//  MXBBCodeNode.h
//  MXBBCodeKit
//
//  Created by rookie on 2020/6/30.
//  Copyright © 2020 Moxtra. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MXBBCodeNodeType)
{
    MXBBCodeNodeRoot,
    MXBBCodeNodeText,
    MXBBCodeNodeBold,
    MXBBCodeNodeItalic,
    MXBBCodeNodeUnderline,
    MXBBCodeNodeStrikeThrough,
    MXBBCodeNodeSize,
    MXBBCodeNodeColor,
    MXBBCodeNodeCenter,
    MXBBCodeNodeLeft,
    MXBBCodeNodeRight,
    MXBBCodeNodeQuote,
    MXBBCodeNodeLink,
    MXBBCodeNodeImage,
    MXBBCodeNodeOrderedList,
    MXBBCodeNodeUnorderedList,
    MXBBCodeNodeLi,
    MXBBCodeNodeList,
    MXBBCodeNodeListItem,
    MXBBCodeNodeCode,
    MXBBCodeNodeTable,
    MXBBCodeNodeTableRow,
    MXBBCodeNodeTableCell,
    MXBBCodeNodeTableHeaderCell,
    MXBBCodeNodeYoutube,
    MXBBCodeNodeButton,
    MXBBCodeNodeFrame
};

typedef NSString *MXBBCodeAttributeKey;

@interface MXBBCodeNode : NSObject

@property (nonatomic, assign) MXBBCodeNodeType type;
@property (nonatomic, strong, nullable) NSDictionary<MXBBCodeAttributeKey, __kindof NSObject *> *attributes;
@property (nonatomic, strong, nullable) NSString *text;
@property (nonatomic, strong, nullable) NSArray<MXBBCodeNode *> *children;
@property (nonatomic, weak, nullable) MXBBCodeNode *parent;
@property (nonatomic, assign) float defaultFontSize;

@property (nonatomic, strong, readonly) NSString *flatPlainText;

@end

#define _MXBBCodeAttributeDefine(_t) static MXBBCodeAttributeKey const _t = @#_t
#define MXBBCodeAttributeDefine(_t) _MXBBCodeAttributeDefine(MXBBCodeAttribute##_t)

MXBBCodeAttributeDefine(Size);
MXBBCodeAttributeDefine(Color);
MXBBCodeAttributeDefine(Link);
MXBBCodeAttributeDefine(Width);
MXBBCodeAttributeDefine(Height);
MXBBCodeAttributeDefine(ButtonType);
MXBBCodeAttributeDefine(Payload);
MXBBCodeAttributeDefine(ClientID);
MXBBCodeAttributeDefine(LinkType);

NS_ASSUME_NONNULL_END
