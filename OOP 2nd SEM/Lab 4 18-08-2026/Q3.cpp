#include <iostream>
#include <string>
using namespace std;

class ParkingSlot {
private:
    int slotNumber;
    string vehicleNumber;
    bool isOccupied;

public:
    // Constructor using explicit assignment
    ParkingSlot(int slot, string vehicle, bool status) {
        slotNumber = slot;
        vehicleNumber = vehicle;
        isOccupied = status;
    }

    // Friend function declaration
    friend void checkSlot(const ParkingSlot &slot);
};

// Friend function definition
void checkSlot(const ParkingSlot &slot) {
    cout << "\n--- Parking Slot Info ---" << endl;
    cout << "Slot Number: " << slot.slotNumber << endl;
    
    if (slot.isOccupied) {
        cout << "Occupancy Status: Occupied" << endl;
        cout << "Vehicle Number: " << slot.vehicleNumber << endl;
    } 
    else {
        cout << "Occupancy Status: Available" << endl;
    }
}

int main() {
    int slot;
    string vehicle = "N/A";
    char choice;
    bool occupied = false;

    cout << "Enter Slot Number: ";
    cin >> slot;
    cout << "Is the slot occupied? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        occupied = true;
        cin.ignore();
        cout << "Enter Vehicle Number: ";
        getline(cin, vehicle);
    }

    ParkingSlot slot1(slot, vehicle, occupied);
    checkSlot(slot1);

    return 0;
}