//
//  OTSubscriber.h
//  OpenTok iOS SDK
//
//  Copyright (c) 2014 Tokbox, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class OTSubscriberKit;

/**
 * Renders OpenTok streams, and provides a UIView that renders video and
 * provides some simple end-user controls.
 */
@interface OTSubscriber : OTSubscriberKit

/**
 * The view containing a playback buffer for associated video data. Add this
 * view to your view heirarchy to display a video stream.
 */
@property(readonly) UIView* _Nullable view;

/**
* The scaling of the rendered video, as defined by the
* <OTVideoViewScaleBehavior> enum. The default value is
* OTVideoViewScaleBehaviorFill. Set it to OTVideoViewScaleBehaviorFit to
* have the video shrink, as needed, so that the entire video is visible
* (with pillarboxing).
*/
@property(nonatomic) OTVideoViewScaleBehavior viewScaleBehavior;

@end

/** @name OTSubscriberKitDelegate */

/**
 * OTSubscriberDelegate extends OTSubscriberKitDelegate with additional
 * optional callbacks specific to the OTSubscriber implementation.
 * Currently, there is only one additional callback, but others may be
 * added in a future release.
 */

@protocol OTSubscriberDelegate <OTSubscriberKitDelegate>

@optional
/**
 * Sent when a frame of video has been decoded. Although the
 * subscriber will connect in a relatively short time, video can take
 * more time to synchronize. This message is sent after the
 * <[OTSubscriberKitDelegate subscriberDidConnectToStream:]> message is sent.
 * @param subscriber The subscriber that generated this event.
 */
- (void)subscriberVideoDataReceived:(nonnull OTSubscriber*)subscriber;

@end
