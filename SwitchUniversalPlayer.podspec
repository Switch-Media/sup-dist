Pod::Spec.new do |s|

  s.name         = "SwitchUniversalPlayer"
  
  s.version      = "3.1.0"

  s.summary      = "iOS universal player"

  s.homepage     = "https://github.com/Switch-Media/sup-dist"

  s.license      = "MIT"

  s.author       = {
    "Aaron Bonham" => "abonham@switch.tv",
    "An xu" => "axu@switch.tv",
    "Damien Oliver" => "doliver@switch.tv",
    "Tyler Yang" => "tyang@switch.tv"
  }

  s.ios.deployment_target = "8.0"

  s.source       = { :git => "https://github.com/Switch-Media/sup-dist.git", :tag => "#{s.version}" }

  s.vendored_framework = 'SwitchUniversalPlayer.framework'

  s.frameworks = 'SystemConfiguration', 'CoreTelephony', 'MobileCoreServices', 'CoreMedia', 'AVFoundation'

  s.dependency "google-cast-sdk", "~> 3.5"

  s.dependency "GoogleAds-IMA-iOS-SDK", "~> 3.6"
end
