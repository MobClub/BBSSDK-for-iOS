Pod::Spec.new do |s|
  s.name                  = 'mob_bbssdk'
  s.version               = "2.5.0"
  s.summary               = 'BBSSDK把你的论坛搬到手机上，简单配置完成后，即可快速初始化您的论坛SDK，集成生成App，开启您的移动时代。'
  s.license               = 'MIT'
  s.author                = { "mob" => "mobproducts@163.com" }

  s.homepage              = 'http://www.mob.com'
  s.source                = { :git => "https://github.com/MobClub/BBSSDK-for-iOS.git", :tag => s.version.to_s }
  s.platform              = :ios
  s.ios.deployment_target = "8.0"
  s.default_subspecs      = 'BBSSDK'
  s.dependency 'MOBFoundation'


    # 核心模块
    s.subspec 'BBSSDK' do |sp|
        sp.vendored_frameworks   = 'SDK/BBSSDK/BBSSDK.framework'
    end


    # BBSSDK提供的时尚版UI
    s.subspec 'BBSSDKUI' do |sp|
    	sp.vendored_frameworks = 'SDK/BBSSDK/BBSSDKUI/BBSSDKUI.framework'
    	sp.resources = 'SDK/BBSSDK/BBSSDKUI/BBSSDKUI.bundle'
      
      sp.dependency 'mob_bbssdk/BBSSDK'
      sp.dependency 'mob_linksdk'
      sp.dependency 'mob_sharesdk'
      sp.dependency 'mob_sharesdk/ShareSDKPlatforms/QQ'
      sp.dependency 'mob_sharesdk/ShareSDKPlatforms/SinaWeibo'
      sp.dependency 'mob_sharesdk/ShareSDKPlatforms/WeChat'   #（微信sdk不带支付的命令）

      sp.frameworks = "CoreData", "JavaScriptCore"
      sp.libraries = "icucore", "z", "libc++.tbd", "sqlite3"

      # 使用到第三方库
      sp.dependency "SDWebImage", "~> 4.2.1"
      sp.dependency "UITableView+FDTemplateLayoutCell", "~> 1.6"
      sp.dependency "Masonry", "~> 1.1.0"
      sp.dependency "MBProgressHUD", "~> 1.1.0"
      sp.dependency "SVProgressHUD", "~> 2.2.2"
      sp.dependency "MJRefresh", "~> 3.1.15"
      sp.dependency "YYImage", "~> 1.0.4"

      # 使用高德地图
      sp.dependency "AMap2DMap"
      sp.dependency "AMapSearch"

  	end


  	# BBSSDK提供的简约版UI
  	s.subspec 'BBSSDKUI_WF' do |sp|
    	sp.vendored_frameworks = 'SDK/BBSSDK/BBSSDKUI_WF/BBSSDKUI.framework'
    	sp.resources = 'SDK/BBSSDK/BBSSDKUI_WF/BBSSDKUI.bundle'
      sp.dependency 'mob_bbssdk/BBSSDK'
      sp.dependency 'mob_linksdk'
      sp.dependency 'mob_sharesdk'
      sp.dependency 'mob_sharesdk/ShareSDKPlatforms/QQ'
      sp.dependency 'mob_sharesdk/ShareSDKPlatforms/SinaWeibo'
      sp.dependency 'mob_sharesdk/ShareSDKPlatforms/WeChat'   #（微信sdk不带支付的命令）

      sp.frameworks = "CoreData", "JavaScriptCore"
      sp.libraries = "icucore", "z", "stdc++.6.0.9", "sqlite3"

      # 使用到第三方库
      sp.dependency "SDWebImage", "~> 4.2.1"
      sp.dependency "UITableView+FDTemplateLayoutCell", "~> 1.6"
      sp.dependency "Masonry", "~> 1.1.0"
      sp.dependency "MBProgressHUD", "~> 1.1.0"
      sp.dependency "SVProgressHUD", "~> 2.2.2"
      sp.dependency "MJRefresh", "~> 3.1.15"
      sp.dependency "YYImage", "~> 1.0.4"

      # 使用高德地图
      sp.dependency "AMap2DMap"
      sp.dependency "AMapSearch"
  	end
end