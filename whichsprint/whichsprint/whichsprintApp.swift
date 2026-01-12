import SwiftUI

@main
struct whichsprintApp: App {
    @NSApplicationDelegateAdaptor(AppDelegate.self) var appDelegate

    var body: some Scene {
        Settings {
            EmptyView()
        }
    }
}

class AppDelegate: NSObject, NSApplicationDelegate {
    var statusItem: NSStatusItem?
    var popover = NSPopover()
    
    func applicationDidFinishLaunching(_ notification: Notification) {
        statusItem = NSStatusBar.system.statusItem(withLength: NSStatusItem.variableLength)
        
        if let button = statusItem?.button {
            button.image = createMenuBarImage(text: "311")
            button.action = #selector(togglePopover)
            button.target = self
        }
        
        popover.contentSize = NSSize(width: 300, height: 200)
        popover.behavior = .transient
        popover.contentViewController = NSHostingController(rootView: ContentView())
    }
    
    @objc func togglePopover() {
        if let button = statusItem?.button {
            if popover.isShown {
                popover.performClose(nil)
            } else {
                popover.show(relativeTo: button.bounds, of: button, preferredEdge: .minY)
            }
        }
    }
    
    func createMenuBarImage(text: String) -> NSImage {
        let image = NSImage(size: NSSize(width: 50, height: 22), flipped: false) { rect in
            // Draw logo if available
            if let logo = NSImage(named: "dynatrace_logo") {
                logo.draw(in: rect)
            }
            
            // Draw text
            let paragraphStyle = NSMutableParagraphStyle()
            paragraphStyle.alignment = .center
            
            let attributes: [NSAttributedString.Key: Any] = [
                .font: NSFont.systemFont(ofSize: 12, weight: .medium),
                .foregroundColor: NSColor.white,
                .paragraphStyle: paragraphStyle
            ]
            
            let textRect = NSRect(x: 0, y: -1, width: 50, height: 22)
            text.draw(in: textRect, withAttributes: attributes)
            
            return true
        }
        
        image.isTemplate = false
        return image
    }
}
