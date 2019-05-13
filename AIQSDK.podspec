#
#  Be sure to run `pod spec lint AIQSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "AIQSDK"
  s.version      = "0.2.5"
  s.summary      = "AIQSDK is the iOS SDK for AIQ's computer vision platform."
  s.description  = <<-DESC
                   The AIQ SDK for iOS provides frameworks to utilze AIQ's computer vision platform:
                   * AIQApi       - iOS SDK Client for AIQ's platform API at https://api.aiq.tech
                   DESC
  s.homepage     = 'https://github.com/aiqtech/aiqsdk-ios'
  s.license      = { :type => "AIQ Platform LICENSE", :file => "LICENSE" }
  s.author       = { 'AIQ' => 'tech@aiq.tech' }
  s.source       = { 
                      :git => "https://github.com/aiqtech/aiqsdk-ios.git", 
                      :tag => s.version.to_s 
                   }
  
  s.ios.deployment_target = '8.0'
  s.preserve_paths = '*.framework'
  s.default_subspec = 'AIQApi'

  s.subspec 'AIQApi' do |ss|
    ss.vendored_frameworks = "AIQApi.framework"
  end

end
