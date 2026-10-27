#include <iostream>
using namespace std;

// Base class IrrigationSystem
class IrrigationSystem {
protected:
    double moisture;
public:
    IrrigationSystem(double m) {
        moisture = m;
    }
    
    virtual void calculateWater() {
        cout << "Base water calculation." << endl;
    }
};

// Derived class DripIrrigation
class DripIrrigation : public IrrigationSystem {
public:
    DripIrrigation(double m) : IrrigationSystem(m) {}

    // Drip supplies 2 * (100 - moisture) litres
    void calculateWater() override {
        double water = 2 * (100.0 - moisture);
        cout << "Drip Irrigation requires " << water << " litres of water." << endl;
    }
};

// Derived class SprinklerIrrigation
class SprinklerIrrigation : public IrrigationSystem {
public:
    SprinklerIrrigation(double m) : IrrigationSystem(m) {}

    // Sprinkler supplies 3 * (100 - moisture) litres
    void calculateWater() override {
        double water = 3 * (100.0 - moisture);
        cout << "Sprinkler Irrigation requires " << water << " litres of water." << endl;
    }
};

int main() {
    double moisture;
    cout << "Enter current soil moisture percentage (0 - 100): ";
    cin >> moisture;

    if (moisture < 0 || moisture > 100) {
        cout << "Invalid moisture percentage! Please enter between 0 and 100." << endl;
        return 1;
    }

    DripIrrigation drip(moisture);
    SprinklerIrrigation sprinkler(moisture);

    cout << "\n--- Irrigation Requirements ---" << endl;
    drip.calculateWater();
    sprinkler.calculateWater();

    return 0;
}