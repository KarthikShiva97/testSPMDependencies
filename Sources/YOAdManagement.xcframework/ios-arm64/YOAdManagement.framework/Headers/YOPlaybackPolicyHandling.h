/*
 * COPYRIGHT 2020,2022 YOSPACE TECHNOLOGIES LTD. ALL RIGHTS RESERVED.
 * The contents of this file are proprietary and confidential.
 * Unauthorised copying of this file, via any medium is strictly prohibited.
 */

#import <Foundation/Foundation.h>
#import <YOAdManagement/YOAdManagementTypes.h>

/**
 * @brief The YOPlaybackPolicyHandling protocol declares a set of methods to provide playback policy to clients.
 *
 * It is implemented by a policy adapter; policy calls to YOPlaybackPolicyDelegate on the Yospace Session
 * are delegated to this adapter.
 */
@protocol YOPlaybackPolicyHandling <NSObject>

/**
 * Returns to the client whether playback can stop.
 * If a custom implemented playback policy handler is not set on the session, or exception is thrown,
 * a default value of `true` is returned.
 *
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @return `YES` if playback can stop, `NO` otherwise.
 */
- (BOOL) canStop:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline;

/**
 * Returns to the client whether playback can pause.
 * If a custom implemented playback policy handler is not set on the session, or exception is thrown,
 * a default value of `false` for Live, `true` for other playback modes is returned.
 *
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @return `YES` if playback can pause, `NO` otherwise.
 */
- (BOOL) canPause:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline;

/**
 * Returns to the client whether the currently playing advert can be skipped.
 * If a custom implemented playback policy handler is not set on the session, or exception is thrown,
 * a default value of `-1` for Live and `0` for other playback modes is returned.
 *
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @param duration The non-linear stream duration, or zero if the stream is live.
 * @return The delay, in seconds, before the advert can be skipped, or `-1` otherwise.
 */
- (NSTimeInterval) canSkip:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline duration:(NSTimeInterval)duration;

/**
 * Returns to the client the playhead position that the user can seek to.
 * If a custom implemented playback policy handler is not set on the session,  or exception is thrown,
 * the current playhead position is returned for Live and the seek position is returned for other playback modes.
 *
 * @param position The playhead position that the user wishes to seek to, in seconds.
 * @param timeline The stream timeline represented as an array of YOAdBreak objects.
 * @param playhead The current playhead position.
 * @return The actual playhead position that the user can seek to, based on the implemented policy.
 */
- (NSTimeInterval) willSeekTo:(NSTimeInterval)position timeline:(nonnull NSArray*)timeline playhead:(NSTimeInterval)playhead;

/**
 * Returns to the client whether volume can be muted.
 * If a custom implemented playback policy handler is not set on the session,  or exception is thrown,
 * a default value of `true` is returned.
 *
 * @param mute Whether the volume is to be muted or unmuted.
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @return `YES` if volume can be muted, `NO` otherwise.
 */
- (BOOL) canChangeVolume:(BOOL)mute playhead:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline;

/**
 * Returns to the client whether expanding the player to full screen is allowed.
 * If a custom implemented playback policy handler is not set on the session,  or exception is thrown,
 * a default value of `true` is returned.
 *
 * @param fullscreen Whether the video is expanding to fullscreen.
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @return `YES` if full screen is allowed, `NO` otherwise.
 */
- (BOOL) canResize:(BOOL)fullscreen playhead:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline;

/**
 * Returns to the client whether the linear creative can be expanded.
 * If a custom implemented playback policy handler is not set on the session,  or exception is thrown,
 * a default value of `true` is returned.
 *
 * @param expand Whether the creative is expanding or collapsing.
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @return `YES` if the creative can be expanded, `NO` otherwise.
 * @note This method is not applicable to NonLinear creative.
 */
- (BOOL) canResizeCreative:(BOOL)expand playhead:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline;

/**
 * Returns to the client whether the user can click-through.
 * If a custom implemented playback policy handler is not set on the session,  or exception is thrown,
 * a default value of `true` is returned.
 *
 * @param url The click-through URL.
 * @param playhead The current playhead position, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 * @return `YES` if the user can click through, `NO` otherwise.
 */
- (BOOL) canClickThrough:(nonnull NSURL*)url playhead:(NSTimeInterval)playhead timeline:(nonnull NSArray*)timeline;

/**
 * Sets the playback mode that the stream is running in. The policy handler implementation may use this to modify the policy for specific
 * requests, for example allowing pause in video-on-demand but not live playback.
 *
 * @param playbackMode The playback mode for the stream.
 * @see YOPlaybackMode
 */
- (void) setPlaybackMode:(YOPlaybackMode)playbackMode;

/**
 * Indicates that a playback skip operation completed.
 *
 * @param previous The playhead position prior to skipping, in seconds.
 * @param current The playhead position after skipping, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 */
- (void) didSkipFrom:(NSTimeInterval)previous to:(NSTimeInterval)current timeline:(nonnull NSArray*)timeline;

/**
 * Indicates that a playback seek operation completed.
 *
 * @param previous The playhead position prior to seeking, in seconds.
 * @param current The playhead position after seeking, in seconds.
 * @param timeline The stream timeline represented as an array of ad break objects.
 */
- (void) didSeekFrom:(NSTimeInterval)previous to:(NSTimeInterval)current timeline:(nonnull NSArray*)timeline;

@end
