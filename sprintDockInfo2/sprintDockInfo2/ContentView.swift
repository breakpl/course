import Cocoa

@main
class AppDelegate: NSObject, NSApplicationDelegate {
    var window: NSWindow!
    var dockLabel: NSTextField!

    func applicationDidFinishLaunching(_ notification: Notification) {
        // Create the main application window
        window = NSWindow(
            contentRect: NSRect(x: 0, y: 0, width: 400, height: 300),
            styleMask: [.titled, .closable, .resizable],
            backing: .buffered,
            defer: false
        )
        window.title = "Dock Item with External Data"
        window.center()
        window.makeKeyAndOrderFront(nil)

        // Create a custom view to simulate a "dock item"
        let dockView = NSView(frame: NSRect(x: 0, y: 0, width: 400, height: 100))
        dockView.wantsLayer = true
        dockView.layer?.backgroundColor = NSColor.lightGray.cgColor

        // Create a label to display the fetched data
        dockLabel = NSTextField(labelWithString: "Fetching data...")
        dockLabel.alignment = .center
        dockLabel.frame = NSRect(x: 10, y: 10, width: 380, height: 80)
        dockView.addSubview(dockLabel)

        // Add the dock view to the main window
        window.contentView?.addSubview(dockView)

        // Fetch data from an external URL
        fetchExternalData()
    }

    func fetchExternalData() {
        let urlString = "https://example.com/api/data" // Replace with your external URL
        guard let url = URL(string: urlString) else {
            dockLabel.stringValue = "Invalid URL"
            return
        }

        let task = URLSession.shared.dataTask(with: url) { [weak self] data, response, error in
            DispatchQueue.main.async {
                if let error = error {
                    self?.dockLabel.stringValue = "Error: \(error.localizedDescription)"
                } else if let data = data, let fetchedString = String(data: data, encoding: .utf8) {
                    self?.dockLabel.stringValue = fetchedString
                } else {
                    self?.dockLabel.stringValue = "Failed to fetch data."
                }
            }
        }
        task.resume()
    }
}
