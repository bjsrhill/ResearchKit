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


#import <Foundation/Foundation.h>

#import <ResearchKit/ORKStep.h>
#import <ResearchKit/ORKDefines.h>

typedef NS_ENUM(NSInteger, ORKCardViewStyle) {
    ORKCardViewStyleDefault,
    ORKCardViewStyleBordered
} ORK_ENUM_AVAILABLE;

NS_ASSUME_NONNULL_BEGIN

@class ORKAnswerFormat;
@class ORKFormItem;
@class ORKLearnMoreItem;

/**
 The `ORKFormStep` class is a concrete subclass of `ORKStep`, used for presenting multiple questions
 on a single scrollable page.
 
 To use `ORKFormStep`, instantiate the object, fill in its properties, and include it
 in a task. Next, create a task view controller for the task and present it.
 When the task completes, the user's answers are encoded in the result hierarchy
 in the task view controller.
 
 Each question in the form is represented by an `ORKFormItem` object. The form items have an
 `optional` property that defaults to `YES`. All required questions need to be answered for the
 Continue button to be enabled. If all the form items are optional, at least one question needs to
 be answered for the Continue button to be enabled. You can allow the user to completely skip a
 form step using the Skip button, even if it has required form items, by setting the form step
 `optional` property to yes.
 
 The form can be broken into sections by using an `ORKFormItem` object that includes only a section
 title.
 
 The result of a form step is an `ORKStepResult` object that includes a child `ORKQuestionResult`
 object for each form item.
 */

ORK_CLASS_AVAILABLE
@interface ORKFormStep : ORKStep

/**
 Returns an initialized form step using the specified identifier, title, and text.
 
 @param identifier    The string that identifies the step (see `ORKStep`).
 @param title         The title of the form (see `ORKStep`).
 @param text          The text shown immediately below the title (see `ORKStep`).
 
 @return As initialized form step object.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                             title:(nullable NSString *)title
                              text:(nullable NSString *)text;

/**
 The array of items in the form.
 
 A form step that contains no items is considered invalid and an exception will be thrown
 when it is presented.
 */
@property (nonatomic, copy, nullable) NSArray<ORKFormItem *> *formItems;

/**
 The property to present the form with all the items in a card view. Default to YES;
 */
@property (nonatomic) BOOL useCardView;

/**
   Footer text to display beneath the last formItem.
*/
@property (nonatomic, copy, nullable) NSString *footerText;

@property (nonatomic) ORKCardViewStyle cardViewStyle;

@end


/**
 The `ORKFormItem` class represents a single item in a form step (`ORKFormStep`), and typically
 represents a question.
 
 To use `ORKFormItem`, instantiate the object, fill in its properties, and incorporate
 it in an `ORKFormStep` object.
 
 Usually, a form item corresponds to either a row or a section header in a form, but
 if the answer format is a choice answer format, it may correspond to an entire
 section.
 
 Each form item generates one question result (`ORKQuestionResult`), which becomes a child of its step's
 result (`ORKStepResult`).
 */
ORK_CLASS_AVAILABLE
@interface ORKFormItem : NSObject <NSSecureCoding, NSCopying>

/**
 Returns an initialized form item using the specified identifier, title, and answer format.
 
 @param identifier    The string that identifies the form item, which should be unique within the form step.
 @param text          The text displayed as a prompt for the form item's question.
 @param answerFormat  The answer format for the form item.
 
 @return An initialized form item.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                              text:(nullable NSString *)text
                      answerFormat:(nullable ORKAnswerFormat *)answerFormat;

/**
 Returns an initialized form item using the specified identifier, title, optionality and answer format.
 
 @param identifier    The string that identifies the form item, which should be unique within the form step.
 @param text          The text displayed as a prompt for the form item's question.
 @param answerFormat  The answer format for the form item.
 @param optional      A Boolean that determines whether the item is optional
 
 @return An initialized form item.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                              text:(nullable NSString *)text
                      answerFormat:(nullable ORKAnswerFormat *)answerFormat
                          optional:(BOOL) optional;

/**
 Returns an initialized form item using the specified identifier, title, optionality and answer format.
 
 @param identifier    The string that identifies the form item, which should be unique within the form step.
 @param text    The text displayed as a prompt for the form item's question.
 @param detailText     The detail text displayed below the form items title
 @param learnMoreItem    The `ORKLearnMoreItem` to be presented when button is pressed.
 @param showsProgress    A Boolean that determines if the formItem will display a progress indicator
 @param answerFormat  The answer format for the form item.
 @param optional      A Boolean that determines whether the item is optional
 
 @return An initialized form item.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                              text:(nullable NSString *)text
                        detailText:(nullable NSString *)detailText
                     learnMoreItem:(nullable ORKLearnMoreItem *)learnMoreItem
                     showsProgress:(BOOL)showsProgress
                      answerFormat:(nullable ORKAnswerFormat *)answerFormat
                           tagText:(nullable NSString *)tagText
                          optional:(BOOL) optional;

/**
 Returns an initialized form item using the specified section title.
 
 @param sectionTitle   The title of the section.
 
 @return An initialized form item for use as a section header in a form.
 */
- (instancetype)initWithSectionTitle:(nullable NSString *)sectionTitle;

/**
 Returns an initialized form item using the specified section title.
 
@param sectionTitle   The title of the section.
@param text     The detail text displayed below the form items title
@param learnMoreItem    The `ORKLearnMoreItem` to be presented when button is pressed.
@param showsProgress    A Boolean that determines if the formItem will display a progress indicator
 
@return An initialized form item for use as a section header in a form.
*/

- (instancetype)initWithSectionTitle:(nullable NSString *)sectionTitle
                          detailText:(nullable NSString *)text
                       learnMoreItem:(nullable ORKLearnMoreItem *)learnMoreItem
                       showsProgress:(BOOL)showsProgress;
/**
 A string that identifies the form item.
 
 The identifier should be unique within the form step that contains the form
 item. The identifier is reproduced in the question result object (`ORKQuestionResult`)
 generated for the item.
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/**
 A Boolean value indicating whether the form item is optional.
 
 The default value of this property is `YES`. When the value is `YES`, this form item doesn't need
 to be answered for the Continue button of a step form to be enabled.
 */
@property (nonatomic, getter=isOptional) BOOL optional;

/**
 A localized string that describes the form item.
 
 If the descriptive text is sufficiently short, you can display it as a prompt next to the item.
 If it is too long to display next to the item, you can display it above the item.
 */
@property (nonatomic, copy, readonly, nullable) NSString *text;

@property (nonatomic, copy, nullable) NSString *detailText;

@property (nonatomic) BOOL showsProgress;

@property (nonatomic, copy, nullable) ORKLearnMoreItem *learnMoreItem;

@property (nonatomic, copy, nullable) NSString *tagText;

/**
 A localized string that displays placeholder information for the form item.
 
 You can display placeholder text in a text field or text area to help users understand how to answer the
 item's question. A placeholder string is not appropriate for choice-based answer formats.
 */
@property (nonatomic, copy, nullable) NSString *placeholder;

/**
 The format of the expected answer for the item.
 
 The answer format specifies the type of answer that is expected, in addition to any
 constraints on valid answers.
 
 By default, the answer format is `nil`. The answer format for a form item that represents a section
 header is always `nil`, because no answer is expected.
 */
@property (nonatomic, copy, readonly, nullable) ORKAnswerFormat *answerFormat;

/**
 Returns an form item that can be used for confirming a text entry.
 
 This form item is intended to be used with an `ORKFormStep` in order to confirm a previous
 formItem input. Example usage includes a password or participant identifier that is used to
 anonymously identify a study participant.
 
 Currently, only `ORKTextAnswerFormat` is supported. Unsupported `ORKAnswerFormat` types will
 throw an exception.
 
 The answer format for this item produces an `ORKBooleanQuestionResult` object.
 
 @param identifier      The identifier for the `ORKFormItem` that is returned.
 @param text            The text for the `ORKFormItem` that is returned.
 @param errorMessage    The error message to display if the fields do not match
 
 @return                An `ORKFormItem` with the indicated identifier and text and an ORKAnswerFormat 
                        that is appropriate for confirming the input form item.
 
 */
- (ORKFormItem *)confirmationAnswerFormItemWithIdentifier:(NSString *)identifier
                                                     text:(nullable NSString *)text
                                             errorMessage:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
