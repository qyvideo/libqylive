//
//  QYMediaPlayback.h
//  QYMediaPlayer
//
//  Created by zengfanping on 10/12/15.
//  Copyright © 2015 qyvideo. All rights reserved.
//

#import <MediaPlayer/MediaPlayer.h>



@protocol QYMediaPlayback



// Prepares the current queue for playback, interrupting any active (non-mixible) audio sessions.
// Automatically invoked when -play is called if the player is not already prepared.
- (void)prepareToPlay;



// Returns YES if prepared for playback.
@property(nonatomic, readonly) BOOL isPreparedToPlay;



// Plays items from the current queue, resuming paused playback if possible.
- (void)play;



// Pauses playback if playing.
- (void)pause;



// Ends playback. Calling -play again will start from the beginnning of the queue.
- (void)stop;



// The current playback time of the now playing item in seconds.
@property(nonatomic) NSTimeInterval currentPlaybackTime;

// Posted when the prepared state changes of an object conforming to the MPMediaPlayback protocol changes.
// This supersedes MPMoviePlayerContentPreloadDidFinishNotification.
MP_EXTERN NSString *const MPMediaPlaybackIsPreparedToPlayDidChangeNotification NS_DEPRECATED_IOS(3_2, 9_0);

@end
