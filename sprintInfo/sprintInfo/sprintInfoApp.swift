import Cocoa
import Combine

class AppDelegate: NSObject, NSApplicationDelegate {
    var statusBarItem: NSStatusItem?
    var cancellable: AnyCancellable?

    private var jsonData: String = "Fetching JSON..."
    
    func applicationDidFinishLaunching(_ notification: Notification) {
        // Hide the Dock icon
        NSApplication.shared.setActivationPolicy(.prohibited)
        
        // Create a menu bar item
        statusBarItem = NSStatusBar.system.statusItem(withLength: NSStatusItem.variableLength)
        if let button = statusBarItem?.button {
            button.title = "Loading..."
        }
        
        // Add a dropdown menu
        let menu = NSMenu()
        menu.addItem(NSMenuItem(title: "Quit", action: #selector(quitApp), keyEquivalent: "q"))
        statusBarItem?.menu = menu

        // Fetch and display the version
        fetchVersion()
    }

    func fetchVersion() {
        guard let url = URL(string: "https://synth-api-dev.dev.dynatracelabs.com/synthetic-control/default") else {
            jsonData = "Invalid URL"
            return
        }

        let task = URLSession.shared.dataTask(with: url) { data, response, error in
            if let error = error {
                DispatchQueue.main.async {
                    self.jsonData = "Error: \(error.localizedDescription)"
                }
                return
            }

            guard let data = data, let jsonString = String(data: data, encoding: .utf8) else {
                DispatchQueue.main.async {
                    self.jsonData = "Failed to decode JSON"
                }
                return
            }

            DispatchQueue.main.async {
                self.jsonData = jsonString
            }
        }

        task.resume()
    }


    func updateMenuBar(with title: String) {
        statusBarItem?.button?.title = title
    }

    @objc func quitApp() {
        NSApplication.shared.terminate(self)
    }
}

struct APIResponse: Codable {
    let message: String
    let status: String
    let context: String
    let version: String
    let dataBase: String
    let timestamp: String
    let initializedAt: String
    let dbLastCheckAt: String?
    let dbLastSuccessAt: String?
}
