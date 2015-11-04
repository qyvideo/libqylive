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
    QYVideoDimension_16_9__1280x720,
    /// 4 : 3 横纵比，640 x 480 分辨率
    QYVideoDimension_4_3__640x480,
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


#pragma mark - QYPublisher State

/*!
 * @abstract  推流状态
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
    /// 连接出错
    QYStreamStateError,
    /// QYAuthFailed
    QYStreamStateQYAuthFailed,
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
