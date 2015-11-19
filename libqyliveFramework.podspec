Pod::Spec.new do |spec|
  spec.name         = 'libqyliveFramework'
  spec.version      = '0.1.11'
  spec.license      = {
:type => 'Proprietary',
:text => <<-LICENSE
      Copyright 2015 QYVideo Ltd. All rights reserved.
      LICENSE
  }
  spec.homepage     = 'http://www.qyvideo.net/'
  spec.authors      = { 'Peng Bin' => 'pengbin@qyvideo.cn' }
  spec.summary      = 'libqylive help you publisher and play live video on ios mobile devices.'
  spec.description  = <<-DESC
    libqylive record live video from camera with software codec, and publish to rtmp server.
  DESC
  spec.platform     = :ios, '7.0'
  spec.requires_arc = true
  spec.frameworks   = 'VideoToolbox'
  spec.ios.library = 'z', 'iconv', 'stdc++.6'
  spec.source = { :git => 'https://github.com/qyvideo/libqylive.git', :tag => 'v0.1.11'}
  spec.preserve_paths      = 'libqylive.framework'
  spec.public_header_files = 'libqylive.framework/Headers'
  spec.vendored_frameworks = 'libqylive.framework'
end