//
//  QYMoviePlayerController.h
//  QYMediaPlayer
//
//  Created by zengfanping on 10/12/15.
//  Copyright © 2015 qyvideo. All rights reserved.
//

#import "QYMediaPlayback.h"
#import <MediaPlayer/MediaPlayer.h>



@interface QYMoviePlayerController : NSObject <QYMediaPlayback>
#pragma mark MPMoviePlayerController 



- (instancetype)initWithContentURL:(NSURL *)url NS_DESIGNATED_INITIALIZER;



@property (nonatomic, copy) NSURL *contentURL;



// The view in which the media and playback controls are displayed.
@property (nonatomic, readonly) UIView *view;

// The style of the playback controls. Defaults to MPMovieControlStyleDefault.


@property (nonatomic) MPMovieControlStyle controlStyle;



// Returns the current playback state of the movie player.
@property (nonatomic, readonly) MPMoviePlaybackState playbackState;




// Returns the network load state of the movie player.
@property (nonatomic, readonly) MPMovieLoadState loadState;



// Indicates if a movie should automatically start playback when it is likely to finish uninterrupted based on e.g. network conditions. Defaults to YES.
@property (nonatomic) BOOL shouldAutoplay;



// Determines how the content scales to fit the view. Defaults to MPMovieScalingModeAspectFit.
@property (nonatomic) MPMovieScalingMode scalingMode;



// The duration of the movie, or 0.0 if not known.
@property (nonatomic, readonly) NSTimeInterval duration;


// Posted when the playback state changes, either programatically or by the user.
MP_EXTERN NSString * const MPMoviePlayerPlaybackStateDidChangeNotification NS_DEPRECATED_IOS(3_2, 9_0);

// Posted when movie playback ends or a user exits playback.
MP_EXTERN NSString * const MPMoviePlayerPlaybackDidFinishNotification NS_DEPRECATED_IOS(2_0, 9_0);

// Posted when the network load state changes.
MP_EXTERN NSString * const MPMoviePlayerLoadStateDidChangeNotification NS_DEPRECATED_IOS(3_2, 9_0);

#pragma mark QYMoviePlayerController New Feature


// A description of the error encountered.
- (BOOL)isPlaying;

@end
