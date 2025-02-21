/*
 Copyright (c) 2019, Apple Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 1.  Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2.  Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.
 
 3.  Neither the name of the copyright holder(s) nor the names of any contributors
 may be used to endorse or promote products derived from this software without
 specific prior written permission. No license is granted to the trademarks of
 the copyright holders even if such marks are included in this software.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <ResearchKit/ORKDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ORKBodyItemStyle) {
    /**
     text style body item
     */
    ORKBodyItemStyleText,
    
    /**
     bullet style body item
     */
    ORKBodyItemStyleBulletPoint,
    
    /**
     image style body item
     */
    ORKBodyItemStyleImage,
    
    /**
     horizontal rule
     */
    ORKBodyItemStyleHorizontalRule,
    
    /**
     tag label
     */
    ORKBodyItemStyleTag
} ORK_ENUM_AVAILABLE;

@class ORKLearnMoreItem;

ORK_CLASS_AVAILABLE
@interface ORKBodyItem : NSObject <NSSecureCoding, NSCopying>

- (instancetype)initWithText:(nullable NSString *)text detailText:(nullable NSString *)detailText image:(nullable UIImage *)image learnMoreItem:(nullable ORKLearnMoreItem *)learnMoreItem bodyItemStyle:(ORKBodyItemStyle)bodyItemStyle;

- (instancetype)initWithText:(nullable NSString *)text detailText:(nullable NSString *)detailText image:(nullable UIImage *)image learnMoreItem:(nullable ORKLearnMoreItem *)learnMoreItem bodyItemStyle:(ORKBodyItemStyle)bodyItemStyle useCardStyle:(BOOL)useCardStyle;

- (instancetype)initWithHorizontalRule;

@property (nonatomic, nullable) NSString *text;

@property (nonatomic, nullable) NSString *detailText;

@property (nonatomic, nullable) UIImage *image;

@property (nonatomic, nullable) ORKLearnMoreItem *learnMoreItem;

@property (nonatomic) ORKBodyItemStyle bodyItemStyle;

@property (nonatomic) BOOL useCardStyle;

@property (nonatomic) BOOL useSecondaryColor;

@end

NS_ASSUME_NONNULL_END
