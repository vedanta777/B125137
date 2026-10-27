#include <iostream>
using namespace std;

// Base class ParkingSlot
class ParkingSlot {
protected:
    int hours;
public:
    ParkingSlot(int h) {
        hours = h;
    }
    
    virtual void calculateFee() {
        cout << "Base parking fee calculation." << endl;
    }
};

// Derived class TwoWheelerSlot
class TwoWheelerSlot : public ParkingSlot {
public:
    TwoWheelerSlot(int h) : ParkingSlot(h) {}

    // Calculate fee at Rs. 10 per hour with 10% discount if > 5 hours
    void calculateFee() override {
        double fee = hours * 10.0;
        if (hours > 5) {
            fee = fee - (fee * 0.10); // Apply 10% discount
        }
        cout << "Two-Wheeler Fee for " << hours << " hours: Rs. " << fee << endl;
    }
};

// Derived class FourWheelerSlot
class FourWheelerSlot : public ParkingSlot {
public:
    FourWheelerSlot(int h) : ParkingSlot(h) {}

    // Calculate fee at Rs. 30 per hour with 10% discount if > 5 hours[cite: 1]
    void calculateFee() override {
        double fee = hours * 30.0;
        if (hours > 5) {
            fee = fee - (fee * 0.10); // Apply 10% discount
        }
        cout << "Four-Wheeler Fee for " << hours << " hours: Rs. " << fee << endl;
    }
};

int main() {
    int h;
    cout << "Enter parking duration in hours: ";
    cin >> h;

    TwoWheelerSlot tw(h);
    FourWheelerSlot fw(h);

    cout << "\n--- Parking Fee Details ---" << endl;
    tw.calculateFee();
    fw.calculateFee();

    return 0;
}