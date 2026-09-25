#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmartDevice
{
private:
    string deviceId;
    string deviceType;
    string location;
    string status;
    string lastUpdated;

public:
    SmartDevice(string id, string type, string loc, string stat, string time)
        : deviceId(id), deviceType(type), location(loc),
          status(stat), lastUpdated(time)
    {
    }

    void switchOn(string time)
    {
        status = "ON";
        lastUpdated = time;
    }

    void switchOff(string time)
    {
        status = "OFF";
        lastUpdated = time;
    }

    void changeStatus(string newStatus, string time)
    {
        status = newStatus;
        lastUpdated = time;
    }

    void display() const
    {
        cout << "Device ID: " << deviceId
             << " | Type: " << deviceType
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated << endl;
    }
};

int main()
{
    vector<SmartDevice> devices;

    devices.emplace_back("D001", "Light", "Living Room", "OFF", "08:00");
    devices.emplace_back("D002", "Thermostat", "Bedroom", "ON", "08:05");
    devices.emplace_back("D003", "Camera", "Main Door", "ON", "08:10");
    devices.emplace_back("D004", "Door Lock", "Main Door", "LOCKED", "08:15");

    cout << "=== Smart Home Dashboard ===" << endl;

    for (const auto& device : devices)
    {
        device.display();
    }

    devices[0].switchOn("09:00");
    devices[3].changeStatus("UNLOCKED", "09:05");

    cout << "\n=== Updated Home Dashboard ===" << endl;

    for (const auto& device : devices)
    {
        device.display();
    }

    return 0;
}
