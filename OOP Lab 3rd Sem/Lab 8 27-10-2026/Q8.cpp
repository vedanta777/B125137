#include <iostream>
using namespace std;

// Base class CloudResource
class CloudResource {
protected:
    double cpuHours;
public:
    CloudResource(double hours) {
        cpuHours = hours;
    }
    
    virtual void calculateCost() {
        cout << "Base cost calculation." << endl;
    }
};

// Derived class StandardInstance
class StandardInstance : public CloudResource {
public:
    StandardInstance(double hours) : CloudResource(hours) {}

    // Rs. 5 per CPU-hour, 15% discount if usage > 100 hours
    void calculateCost() override {
        double cost = cpuHours * 5.0;
        if (cpuHours > 100) {
            cost = cost - (cost * 0.15);
        }
        cout << "Standard Instance Cost for " << cpuHours << " CPU-hours: Rs. " << cost << endl;
    }
};

// Derived class PremiumInstance
class PremiumInstance : public CloudResource {
public:
    PremiumInstance(double hours) : CloudResource(hours) {}

    // Rs. 12 per CPU-hour, 15% discount if usage > 100 hours
    void calculateCost() override {
        double cost = cpuHours * 12.0;
        if (cpuHours > 100) {
            cost = cost - (cost * 0.15);
        }
        cout << "Premium Instance Cost for " << cpuHours << " CPU-hours: Rs. " << cost << endl;
    }
};

int main() {
    double hours;
    cout << "Enter total CPU-hours used: ";
    cin >> hours;

    StandardInstance stdInst(hours);
    PremiumInstance premInst(hours);

    cout << "\n--- Cloud Resource Costs ---" << endl;
    stdInst.calculateCost();
    premInst.calculateCost();

    return 0;
}