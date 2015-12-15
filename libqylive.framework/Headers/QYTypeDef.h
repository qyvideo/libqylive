//
//  QYTypeDef.h
//  QYPublisher
//
//  Created by pengbin on 10/15/15.
//  Copyright © 2015 qyvideo. All rights reserved.
//

#ifndef _QYTypeDef_h_
#define _QYTypeDef_h_

#pragma mark - Authorization

/// 设备授权状态
typedef NS_ENUM(NSUInteger, QYDevAuthStatus) {
    /// 还没有确定是否授权
    QYDevAuthStatusNotDetermined = 0,
    /// 设备受限，一般在家长模式下设备会受限
    QYDevAuthStatusRestricted,
    /// 拒绝授权
    QYDevAuthStatusDenied,
    /// 已授权
    QYDevAuthStatusAuthorized
};

#pragma mark - Video Dimension

/// 采集分辨率
typedef NS_ENUM(NSUInteger, QYVideoDimension) {
    /// 16 : 9 横纵比，1280 x 720 分辨率
    QYVideoDimension_16_9__1280x720 = 0,
    /// 16 : 9 横纵比，960 x 540 分辨率
    QYVideoDimension_16_9__960x540,
    /// 4 : 3 横纵比，640 x 480 分辨率
    QYVideoDimension_4_3__640x480,
    /// 16 : 9 横纵比，640 x 360 分辨率
    QYVideoDimension_16_9__640x360,
    /// 4 : 3 横纵比，320 x 240 分辨率
    QYVideoDimension_5_4__352x288,
    /// 自定义分辨率
    //QYVideoDimension_UserDefine,
    /// 默认分辨率，默认为 4 : 3 横纵比，640 x 480 分辨率
    QYVideoDimension_Default = QYVideoDimension_4_3__640x480,
};

#pragma mark - Video Codec ID
/*!
 * @abstract  视频编码器类型
 */
typedef NS_ENUM(NSUInteger, QYVideoCodec) {
    /// 视频编码器 - x264 软件编码器
    QYVideoCodec_X264 = 0,
    /// 视频编码器 - 仟壹265 软件编码器
    QYVideoCodec_QY265,
};

#pragma mark - Video Gravity
/*!
 * @abstract  预览视频的填充方式
 */
typedef NS_ENUM(NSUInteger, QYVideoGravity) {
    /// 保持宽高比，留白边 Preserve aspect ratio; fit within layer bounds.
    QYVideoGravity_ResizeAspect = 0,
    /// 保持宽高比并填充，裁剪边缘 Preserve aspect ratio; fill layer bounds.
    QYVideoGravity_ResizeAspectFill,
    /// 拉伸 Stretch to fill layer bounds.
    QYVideoGravity_Resize,
};

#pragma mark - QYPublisher State

/*!
 * @abstract  采集设备状态
 */
typedef NS_ENUM(NSUInteger, QYCaptureState) {
    /// 设备空闲中
    QYCaptureStateIdle,
    /// 设备工作中
    QYCaptureStateCapturing,
    /// 设备授权被拒绝
    QYCaptureStateDevAuthDenied,
    /// 关闭采集设备中
    QYCaptureStateClosingCapture,
};

/*!
 * @abstract  推流状态
 */
typedef NS_ENUM(NSUInteger, QYStreamState) {
    /// 初始化时状态为空闲
    QYStreamStateIdle = 0,
    /// 连接中
    QYStreamStateConnecting,
    /// 已连接
    QYStreamStateConnected,
    /// 断开连接中
    QYStreamStateDisconnecting,
    /// 推流出错
    QYStreamStateError,
};

/*!
 * @abstract  推流错误码，用于指示推流失败的原因
 */
typedef NS_ENUM(NSUInteger, QYStreamErrorCode) {
    /// 正常无错误
    QYStreamErrorCode_NONE = 0,
    /// QYAuthFailed, SDK 鉴权失败
    QYStreamErrorCode_QYAUTHFAILED,
    /// 当前帧编码失败
    QYStreamErrorCode_ENCODE_FRAMES_FAILED,
    /// 无法打开配置指示的CODEC
    QYStreamErrorCode_CODEC_OPEN_FAILED,
    /// 连接出错，检查地址
    QYStreamErrorCode_CONNECT_FAILED,
    /// 网络连接中断
    QYStreamErrorCode_CONNECT_BREAK,
};

/*!
 * @abstract  网络状况事件码，用于指示当前网络健康状况
 */
typedef NS_ENUM(NSUInteger, QYNetStateCode) {
    /// 正常无错误
    QYNetStateCode_NONE = 0,
    /// 发送包时间过长，( 单次发送超过 500毫秒 ）
    QYNetStateCode_SEND_PACKET_SLOW,
    /// 估计带宽调整，上调
    QYNetStateCode_EST_BW_RAISE,
    /// 估计带宽调整，下调
    QYNetStateCode_EST_BW_DROP,
};

#pragma mark - QY_EXTERN
#ifndef QY_EXTERN
#ifdef __cplusplus
#define QY_EXTERN     extern "C" __attribute__((visibility ("default")))
#else
#define QY_EXTERN     extern __attribute__((visibility ("default")))
#endif
#endif

#endif
