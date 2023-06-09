//
//  AppDelegate.swift
//  CitiApps
//
//  Created by Balaji Babu Modugumudi on 16/01/23.
//

import UIKit
import Flutter
import FlutterPluginRegistrant

@main
class AppDelegate: FlutterAppDelegate {

    private (set) var appSettings: AppSettings!
    
    lazy var flutterEngine = FlutterEngine()
    var controller : FlutterViewController!

    override func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        initializeDependencies()
        return super.application(application, didFinishLaunchingWithOptions: launchOptions)
    }
    
    override func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey: Any] = [:]) -> Bool {
        if let scheme = url.scheme,
            scheme.localizedCaseInsensitiveCompare("com.citi.acsdemo") == .orderedSame,
            let view = url.host {
            var parameters: [String: String] = [:]
            URLComponents(url: url, resolvingAgainstBaseURL: false)?.queryItems?.forEach {
                parameters[$0.name] = $0.value
            }
        }
        // Required for AAD Authentication
        return true
    }

    // MARK: Private Functions
    private func initializeDependencies() {
        appSettings = AppSettings()
        
        flutterEngine.run(withEntrypoint: nil, initialRoute: "/screen_contact_center")
        
        GeneratedPluginRegistrant.register(with: self.flutterEngine)
        
        controller = FlutterViewController(engine: flutterEngine, nibName: nil, bundle: nil)

        UINavigationBar.appearance().tintColor = .white
        UITabBar.appearance().tintColor = .white
    }
}

