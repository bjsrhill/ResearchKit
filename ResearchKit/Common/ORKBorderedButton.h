/*
 Copyright (c) 2015, Apple Inc. All rights reserved.
 
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
#import <ResearchKit/ORKTextButton.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ORKBorderedButtonDisabledStyle) {
    /**
     default ResearchKit style
     */
    ORKBorderedButtonDisabledStyleDefault,
    /**
     Styling to match system disabled state
     */
    ORKBorderedButtonDisabledStyleSystemGray
} ORK_ENUM_AVAILABLE;

ORK_CLASS_AVAILABLE

@interface CALayer (ORKCornerCurveContinuousCategory)

- (void)setCornerCurveContinuous;
- (void)setCornerCurveCircular;

@end

@interface ORKBorderedButton : ORKTextButton

/**
 The tint color of the button for UIControlStateNormal
 */
@property (nonatomic) UIColor *normalTintColor;

/**
 The tint color of the button for UIControlStateSelected or UIControlStateHighlighted
 */
@property (nonatomic) UIColor *normalHighlightOrSelectTintColor;

/**
 The tint color of the button for UIControlStateDisabled
 */
@property (nonatomic) UIColor *disableTintColor;

/**
 The style to user for disabled buttons.
 ORKBorderedButtonDisabledStyleSystemGray ignores any set values and applies its own style
 */
@property (nonatomic) ORKBorderedButtonDisabledStyle disabledButtonStyle;

/**
 The delay in fading animation
 */
@property (nonatomic, assign) NSTimeInterval fadeDelay;

- (void)updateBackgroundColor;

@end

NS_ASSUME_NONNULL_END
