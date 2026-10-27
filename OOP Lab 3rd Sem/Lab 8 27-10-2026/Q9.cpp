#include <iostream>
using namespace std;

// Base class Robot with virtual function
class Robot {
protected:
    double distance;
public:
    Robot(double dist) {
        distance = dist;
    }
    
    virtual void move() {
        cout << "Base robot move function." << endl;
    }
};

// Derived class WheeledRobot
class WheeledRobot : public Robot {
public:
    WheeledRobot(double dist) : Robot(dist) {}

    // Wheeled robot speed = 2 m/s
    void move() override {
        double time = distance / 2.0;
        cout << "Wheeled Robot travels " << distance << " meters in " << time << " seconds at 2 m/s." << endl;
    }
};

// Derived class TrackedRobot
class TrackedRobot : public Robot {
public:
    TrackedRobot(double dist) : Robot(dist) {}

    // Tracked robot speed = 1.2 m/s
    void move() override {
        double time = distance / 1.2;
        cout << "Tracked Robot travels " << distance << " meters in " << time << " seconds at 1.2 m/s." << endl;
    }
};

int main() {
    double distance;
    cout << "Enter distance to travel (in meters): ";
    cin >> distance;

    WheeledRobot wheeledObj(distance);
    TrackedRobot trackedObj(distance);

    // Base-class pointers demonstrating runtime polymorphism
    Robot* r1 = &wheeledObj;
    Robot* r2 = &trackedObj;

    cout << "\n--- Runtime Polymorphism Navigation ---" << endl;
    r1->move(); // Calls WheeledRobot's move()
    r2->move(); // Calls TrackedRobot's move()

    return 0;
}