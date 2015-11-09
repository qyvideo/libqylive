//
//  QYAuthInfo.h
//  QYFramework
//
//  Created by zengfanping on 10/15/15.
//  Copyright © 2015 qyvideo. All rights reserved.
//

#ifndef QYAuthInfo_h
#define QYAuthInfo_h
/**
 仟壹直播推流SDK需要提供鉴权信息，鉴权信息未完成，将导致如下效果：

 * 直播出去的画面出现仟壹logo
 * 直播一段时间后停止播放
 * 以及其他异常现象发生
 
 ## 联系我们
 当本文档无法帮助您解决在开发中遇到的具体问题，请通过以下方式联系我们，仟壹工程师会在第一时间回复您。
 
 __E-mail__:  linsong@qyvideo.cn
  
 */
#ifndef QY_EXTERN
#ifdef __cplusplus
#define QY_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define QY_EXTERN     extern __attribute__((visibility ("default")))
#endif
#endif

@interface QYAuthInfo: NSObject

/**
 @abstract 开发者设置的开发者标识
 @discussion 该信息由仟壹开发者中心提供。
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString *appId;
/**
 @abstract 开发者设置的应用接入信息
 @discussion 该信息由仟壹开发者中心提供。
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString *accessKey;

/**
 @abstract 开发者设置的密钥
 @discussion 加密算法请见setAuthInfo

 可以使用以下方法获取secretKey，其中"iamskey"为用户密钥，需要从仟壹服务器获取。sksign则为secretKey：
 <pre><code>
 
 - (void)initQYAuth
 {
    NSString* timeSeconds = \[ NSString stringWithFormat:@"%d",(int) \[ \[ NSDate date \] timeIntervalSince1970 \] \] ;
    NSString* sk = \[ NSString stringWithFormat:@"iamskey%@", time \] ;
    NSString* sksign = \[ self QYMD5:sk \] ;
 }
 </pre></code>
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString *secretKey;
/**
 @abstract 开发者设置的1970年至今经过的秒数。
 @discussion 参与加密计算，设置由setAuthInfo传入。
 
 可以使用以下方法获取timeSeconds：
 <pre><code>
 NSString* timeSeconds = [NSString stringWithFormat:@"%d",(int)[ \[ NSDate date \] timeIntervalSince1970]];
</pre></code>
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString *timeSeconds;

/**
 @abstract 设备id
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString *mCode;
/**
 @abstract 设备版本信息
 @since Available in QYMoviePlayerController 1.0 and later.
 */
@property (nonatomic, readonly) NSString *sam;

/**
 @abstract 获取认证单例
 @since Available in QYMoviePlayerController 1.0 and later.
 */
+ (QYAuthInfo *)sharedInstance;

/**
 @abstract 设置认证信息
 @param appId 开发者标识，由仟壹开放平台对开发者分配
 @param ak 应用接入信息，与SecretKey对应，由开放平台针对appid分配
 @param skSign 设置加密后的SecretKey，加密方式为SecretKeySign=md5( SecretKey + TimeSec )，其中“+”号表示字符串连接
 @param seconds 1970年至今经过的秒数。
 
 @discussion timeSeconds获取方法：
 <pre><code>
 NSString* timeSeconds = [NSString stringWithFormat:@"%d",(int)[ \[ NSDate date \] timeIntervalSince1970]];
 </pre></code>
 */
- (void)setAuthInfo:(NSString *)appId accessKey:(NSString*) ak secretKeySign:(NSString*) skSign timeSeconds:(NSString*) seconds;

/**
 @abstract 计算MD5的工具函数
 @param  raw 待计算的字符串
 @return raw对应的MD5签名
 @discussion 对CC_MD5的简单包装
 */
+ (NSString *)QYMD5:(NSString*)raw;

@end
#endif /* QYAuthInfo_h */
