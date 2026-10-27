#include <iostream>
using namespace std;

// Base class Delivery
class Delivery {
protected:
    double distance;
public:
    Delivery(double dist) {
        distance = dist;
    }
    
    virtual void estimateTime() {
        cout << "Base delivery estimation." << endl;
    }
};

// Derived class BikeDelivery
class BikeDelivery : public Delivery {
public:
    BikeDelivery(double dist) : Delivery(dist) {}

    // Speed 20 km/h + 5 minutes traffic delay
    void estimateTime() override {
        // Time in hours = distance / speed, converted to minutes + 5 mins
        double timeInMinutes = (distance / 20.0) * 60.0 + 5.0;
        cout << "Bike Delivery Time for " << distance << " km: " 
             << timeInMinutes << " minutes" << endl;
    }
};

// Derived class DroneDelivery
class DroneDelivery : public Delivery {
public:
    DroneDelivery(double dist) : Delivery(dist) {}

    // Speed 40 km/h + 2 minutes take-off/landing
    void estimateTime() override {
        double timeInMinutes = (distance / 40.0) * 60.0 + 2.0;
        cout << "Drone Delivery Time for " << distance << " km: " 
             << timeInMinutes << " minutes" << endl;
    }
};

int main() {
    double dist;
    cout << "Enter delivery distance in km: ";
    cin >> dist;

    BikeDelivery bike(dist);
    DroneDelivery drone(dist);

    cout << "\n--- Delivery Estimates ---" << endl;
    bike.estimateTime();
    drone.estimateTime();

    return 0;
}