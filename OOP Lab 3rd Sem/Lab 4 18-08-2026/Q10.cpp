#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
private:
    string deviceName;
    string deviceType;
    bool powerStatus;

public:
    // Constructor using explicit assignment
    SmartDevice(string name, string type, bool status) {
        deviceName = name;
        deviceType = type;
        powerStatus = status;
    }

    friend class HomeController;
};

class HomeController {
public:
    void displayInfo(const SmartDevice &dev) {
        cout << "\n--- Device Information ---" << endl;
        cout << "Device Name: " << dev.deviceName << endl;
        cout << "Device Type: " << dev.deviceType << endl;
    }

    void turnOn(SmartDevice &dev) {
        dev.powerStatus = true;
        cout << dev.deviceName << " has been turned ON." << endl;
    }

    void turnOff(SmartDevice &dev) {
        dev.powerStatus = false;
        cout << dev.deviceName << " has been turned OFF." << endl;
    }

    void displayStatus(const SmartDevice &dev) {
        cout << dev.deviceName << " Power Status: " 
             << (dev.powerStatus ? "ON" : "OFF") << endl;
    }
};

int main() {
    string name, type;
    char choice;
    bool status = false;

    cout << "Enter Device Name: ";
    getline(cin, name);
    cout << "Enter Device Type: ";
    getline(cin, type);
    cout << "Is the device currently ON? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        status = true;
    }

    SmartDevice device(name, type, status);
    HomeController controller;

    controller.displayInfo(device);
    controller.displayStatus(device);

    cout << "\n--- Controller Modifications ---" << endl;
    
    controller.turnOn(device);
    controller.displayStatus(device);

    controller.turnOff(device);
    controller.displayStatus(device);

    return 0;
}