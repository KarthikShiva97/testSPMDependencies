// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "FoxPlayerSPMDependenciesiOS",
    platforms: [.iOS(.v14)],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "YOAdManagement",
            targets: ["YOAdManagement"]
        ),
        
            .library(
                name: "GoogleIMAiOSWrapper",
                targets: ["GoogleInteractiveMediaAdsiOS"]
            ),
        
            .library(
                name: "OMSDK_Fox",
                targets: ["OMSDK_Fox"]
            )
        
//            .library(
//                name: "GoogleCast",
//                targets: ["GoogleCast"]
//            )
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        
        .binaryTarget(
            name: "YOAdManagement",
            path: "./Sources/YOAdManagement.xcframework"
        ),
        
            .binaryTarget(
                name: "GoogleInteractiveMediaAdsiOS",
                path: "./Sources/GoogleInteractiveMediaAdsiOS.xcframework"
            ),
        
            .binaryTarget(
                name: "OMSDK_Fox",
                path: "./Sources/OMSDK_Fox.xcframework"
            ),
        
//            .binaryTarget(
//                name: "GoogleCast",
//                path: "./Sources/GoogleCast.xcframework"
//            )
    ]
)
