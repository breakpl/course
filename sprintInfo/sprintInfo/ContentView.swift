import SwiftUI

@main
struct VersionApp: App {
    @NSApplicationDelegateAdaptor(AppDelegate.self) var appDelegate

    var body: some Scene {
        Settings {
            EmptyView() // No visible UI
        }
    }
}
