import BL

public struct FoxPlayerSPMDependencies {
    public private(set) var text = "Hello, World!"

    public init() {
        BLCore.sharedManager()
    }
}
