/*
 * COPYRIGHT 2022 YOSPACE TECHNOLOGIES LTD. ALL RIGHTS RESERVED.
 * The contents of this file are proprietary and confidential.
 * Unauthorised copying of this file, via any medium is strictly prohibited.
 */

#import <Foundation/Foundation.h>
#import <YOAdManagement/YOPlaybackPolicyHandling.h>
#import <YOAdManagement/YOAdManagementTypes.h>

@interface YODefaultPlaybackPolicyHandler : NSObject <YOPlaybackPolicyHandling>

@property (nonatomic) YOPlaybackMode playbackMode;

- (instancetype)initWithPlaybackMode:(YOPlaybackMode) playbackMode;

@end

