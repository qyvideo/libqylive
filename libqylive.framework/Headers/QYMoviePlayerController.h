//
//  QYMoviePlayerController.h
//  QYMediaPlayer
//
//  Created by zengfanping on 10/12/15.
//  Copyright © 2015 ksy. All rights reserved.
//

#import "QYMediaPlayback.h"
#import <MediaPlayer/MediaPlayer.h>
/**
 金山云播放内核提供了跨终端平台的播放器SDK，支持Android/iOS/Flash平台的视频播放需求。金山云播放内核集成有业界一流的高性能H.265/HEVC解码器，提供流畅、低功耗的播放体验。同时SDK提供和系统播放器一致的音视频播放、控制接口，极大地降低了开发门槛。
 
 在任何平台上，金山云播放内核都提供底层开发接口，开发者可自由实现个性的进度条、播放按钮、设置等播放界面元素。金山云提供丰富的播放器调用示例，全部以source code开放，并提供详尽的接口说明文档，让视频应用快速搭建、开发和发布。
 
 金山云播放内核iOS版继承自系统播放器MPMoviePlayerController，适配支持iOS 7.0以上机型，提供系统一致的播放控制接口，在系统播放器基础上新增如下功能：
 
 * 集成金山云高效H.265解码器，解码效率高于开源版本OpenHEVC一倍以上；
 * 支持rmvb/flv/avi/mkv/mov等主流封装格式；
 * 支持HLS/rtmp协议；
 * 完美支持rtmp/http live streaming，结合金山云直播流动态调整功能，实现持续低于2秒的低延时直播体验。

 ## 环境搭建
 QYMediaPlayer依赖如下第三方库：

 * VideoToolbox.framework
 * libz.tbd or libz.dylib
 * libbz2.tbd or libbz2.dylib
 * libstdc++.tbd or libstdc++.dylib

 ## 使用说明
 
 * 开发IDE建议使用Xcode 7，在旧版本Xcode上可能出现其他异常，请直接联系客服人员。
 * 当前iOS framework版本只支持iOS 7.0及以上版本。
 
 ## 联系我们
 当本文档无法帮助您解决在开发中遇到的具体问题，请通过以下方式联系我们，金山云工程师会在第一时间回复您。
 
 __E-mail__:  zengfanping@kingsoft.com
 
 ## 版本信息
 __Version__: 1.0
 
 __Found__: 2015-05-30
 
 */

@interface QYMoviePlayerController : NSObject <QYMediaPlayback>
#pragma mark MPMoviePlayerController 

/**
 @abstract 初始化播放器并设置播放地址
 @param url 视频播放地址，该地址可以是本地地址或者服务器地址.
 @return 返回QYMoviePlayerController对象，该对象的视频播放地址ContentURL已经初始化。此时播放器状态为CBPMoviePlaybackStateStopped.
 
 @discussion 该方法初始化了播放器，并设置了播放地址。但是并没有将播放器对视频文件进行初始化，需要调用 [prepareToPlay]([QYMediaPlayback prepareToPlay])方法对视频文件进行初始化。
 @discussion 当前支持的协议包括：
 
 * http
 * rtmp
 * file, 本地文件
 
 @warning 必须调用该方法进行初始化，不能调用init方法。
 @since Available in QYMoviePlayerController 1.0 and later.
 @return 返回QYMoviePlayerController 实例
 @warning QYMoviePlayerController 当前版本只支持单实例的QYMoviePlayerController对象，多实例将导致播放异常。
 */
- (instancetype)initWithContentURL:(NSURL *)url NS_DESIGNATED_INITIALIZER;

/**
 @abstract 视频文件的URL地址，该地址可以是本地地址或者服务器地址。
 @discussion 当播放器正在播放视频时，设置contenURL将不会导致播放新视频。如果希望播放新视频，需要调用[prepareToPlay]([QYMediaPlayback prepareToPlay])方法.
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, copy) NSURL *contentURL;

/**
 @abstract 包含视频播放内容的VIEW（只读）。
 @discussion view的使用逻辑：
 
 * 可以通过frame设置view大大小
 * 使用[scalingMode]([QYMoviePlayerController scalingMode]) 可以更改视频内容在VIEW中的显示情况

 @see scalingMode
 */
// The view in which the media and playback controls are displayed.
@property (nonatomic, readonly) UIView *view;

// The style of the playback controls. Defaults to MPMovieControlStyleDefault.
/**
 @warning 该属性当前不支持
 */
@property (nonatomic) MPMovieControlStyle controlStyle;

/**
 @abstract 当前播放器的播放状态（只读）。
 @discussion 可以通过该属性获取视频播放情况：
 
 <pre><code>
 typedef NS_ENUM(NSInteger, MPMoviePlaybackState) {
    MPMoviePlaybackStateStopped,           // 播放停止
    MPMoviePlaybackStatePlaying,           // 正在播放
    MPMoviePlaybackStatePaused,            // 播放暂停
    MPMoviePlaybackStateInterrupted,       // 播放被打断
    MPMoviePlaybackStateSeekingForward,    // 向前seeking中
    MPMoviePlaybackStateSeekingBackward    // 向后seeking中
 } NS_DEPRECATED_IOS(3_2, 9_0);
 </code></pre>
 @discussion 通知：
 
 * MPMoviePlayerPlaybackDidFinishNotification，当播放完成时提供通知
 * MPMoviePlayerPlaybackStateDidChangeNotification，当播放状态变化时提供通知
 
 @since Available in QYMoviePlayerController 1.0 and later.
 */
// Returns the current playback state of the movie player.
@property (nonatomic, readonly) MPMoviePlaybackState playbackState;


/**
 @abstract 当前网络加载情况
 @discussion 可以通过该属性获取视频加载情况：
 
 <pre><code>
 typedef NS_OPTIONS(NSUInteger, MPMovieLoadState) {
    MPMovieLoadStateUnknown        = 0,        // 加载情况未知
    MPMovieLoadStatePlayable       = 1 << 0,   // 加载完成，可以播放
    MPMovieLoadStatePlaythroughOK  = 1 << 1,   // 加载完成，如果shouldAutoplay为YES，将自动开始播放
    MPMovieLoadStateStalled        = 1 << 2,   // 如果视频正在加载中
 } NS_DEPRECATED_IOS(3_2, 9_0);
 </code></pre>
 @discussion 通知：
 
 * MPMoviePlayerLoadStateDidChangeNotification，当加载状态变化时提供通知
 
 @since Available in QYMoviePlayerController 1.0 and later.
 */
// Returns the network load state of the movie player.
@property (nonatomic, readonly) MPMovieLoadState loadState;

/**
 @abstract 播放视频时是否需要自动播放，默认值为YES。
 @discussion
 * 如果shouldAutoplay值为YES，则调用[prepareToPlay]([QYMediaPlayback prepareToPlay])方法后，播放器完成初始化后将自动调用[play]([QYMediaPlayback play])方法播放视频。
 * 如果shouldAutoplay值为NO，则播放器完成初始化后将等待外部调用[play]([QYMediaPlayback play])方法。
 * 开发者可以监听播放SDK发送的MPMediaPlaybackIsPreparedToPlayDidChangeNotification通知。在收到该通知后进行其他操作并主动调用[play]([QYMediaPlayback play])方法开启播放。
 
 @since Available in QYMoviePlayerController 1.0 and later.
 */
// Indicates if a movie should automatically start playback when it is likely to finish uninterrupted based on e.g. network conditions. Defaults to YES.
@property (nonatomic) BOOL shouldAutoplay;

/**
 @abstract 当前缩放显示模式。
 @discussion 当前支持四种缩放模式：
 
 <pre><code>
 typedef NS_ENUM(NSInteger, MPMovieScalingMode) {
    MPMovieScalingModeNone,       // 无缩放
    MPMovieScalingModeAspectFit,  // 同比适配，某个方向会有黑边
    MPMovieScalingModeAspectFill, // 同比填充，某个方向的显示内容可能被裁剪
    MPMovieScalingModeFill        // 满屏填充，与原始视频比例不一致
 } NS_DEPRECATED_IOS(2_0, 9_0);
 </code></pre>

 @since Available in QYMoviePlayerController 1.0 and later.
 */
// Determines how the content scales to fit the view. Defaults to MPMovieScalingModeAspectFit.
@property (nonatomic) MPMovieScalingMode scalingMode;

/**
 @abstract 当前视频总时长
 @discussion 视频总时长，单位是秒。

 * 如果是直播视频源，总时长为0.
 * 如果该信息未知，总时长默认为0.
 @since Available in QYMoviePlayerController 1.0 and later.
 */
// The duration of the movie, or 0.0 if not known.
@property (nonatomic, readonly) NSTimeInterval duration;


// Posted when the playback state changes, either programatically or by the user.
MP_EXTERN NSString * const MPMoviePlayerPlaybackStateDidChangeNotification NS_DEPRECATED_IOS(3_2, 9_0);

// Posted when movie playback ends or a user exits playback.
MP_EXTERN NSString * const MPMoviePlayerPlaybackDidFinishNotification NS_DEPRECATED_IOS(2_0, 9_0);

// Posted when the network load state changes.
MP_EXTERN NSString * const MPMoviePlayerLoadStateDidChangeNotification NS_DEPRECATED_IOS(3_2, 9_0);

#pragma mark QYMoviePlayerController New Feature
/**
 @abstract 当前播放器是否在播放
 @warning 该方法由金山云引入，不是原生系统接口
 @return 获取[playbackState]([QYMoviePlayerController playbackState])信息，如果当前状态为MPMoviePlaybackStatePlaying，则返回TRUE。其他情况返回FASLE。
 @see playbackState
 @since Available in QYMoviePlayerController 1.0 and later.
 */
// A description of the error encountered.
- (BOOL)isPlaying;

/**
 @abstract 已经加载的数据大小
 @warning 该方法由金山云引入，不是原生系统接口
 @discussion 已经加载的数据大小，单位是兆。
 
 * 已经加载的全部数据大小，包括音频和视频。
 * 数据包括已经播放的，和当前的cache数据。
 
 @since Available in QYMoviePlayerController 1.0 and later.
 */
// The flow size of the movie which has been download, or 0.0 if not known.
@property (nonatomic, readonly) double readSize;

/**
 @abstract buffer为空时，拉取数据所耗的时长
 @warning 该方法由金山云引入，不是原生系统接口
 @discussion 当buffer为空时，开始统计。单位为秒。
 
 * 当MPMoviePlayerLoadStateDidChangeNotification 通知发起；
 * MPMovieLoadState状态为MPMovieLoadStateStalled 开始计时；
 * MPMovieLoadState状态为MPMovieLoadStatePlayable 或者 MPMovieLoadStatePlaythroughOK时，结束计时；
 
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSTimeInterval bufferEmptyDuration;

/**
 @abstract 发起cache的次数
 @warning 该方法由金山云引入，不是原生系统接口
 @discussion 当buffer为空时，统计一次，统计的条件为
 
 * 当MPMoviePlayerLoadStateDidChangeNotification 通知发起
 * MPMovieLoadState 状态为MPMovieLoadStateStalled
 
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSInteger bufferEmptyCount;



/**
 @abstract 视频流server ip
 @warning 该方法由金山云引入，不是原生系统接口
 @discussion 当收到prepared后，即可以查询当前连接的视频流server ip.
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString* serverAddress;


@end
