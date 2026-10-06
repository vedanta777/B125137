#include <iostream>
#include <string>
using namespace std;

// Base class storing general rental parameters
class Vehicle {
protected:
    string regNumber;
    int rentalDays;

public:
    Vehicle(string reg = "", int days = 0) {
        regNumber = reg;
        rentalDays = days;
    }
};

// Intermediate derived class storing car rental rate
class Car : public Vehicle {
protected:
    double dailyRate;

public:
    Car(string reg = "", int days = 0, double rate = 0.0) : Vehicle(reg, days) {
        dailyRate = rate;
    }
};

// Derived class adding luxury surcharge
class LuxuryCar : public Car {
private:
    double luxuryCharge;

public:
    LuxuryCar(string reg = "", int days = 0, double rate = 0.0, double charge = 0.0) 
        : Car(reg, days, rate) {
        luxuryCharge = charge;
    }

    // Function to calculate and output the total cost
    void displayTotalCost() {
        double totalCost = (dailyRate + luxuryCharge) * rentalDays;

        cout << "\n--- Vehicle Rental Summary ---" << endl;
        cout << "Registration Number: " << regNumber << endl;
        cout << "Rental Days: " << rentalDays << endl;
        cout << "Daily Rate: " << dailyRate << endl;
        cout << "Luxury Charge / Day: " << luxuryCharge << endl;
        cout << "Total Rental Cost: " << totalCost << endl;
    }
};

int main() {
    string regNum;
    int days;
    double rate, charge;

    // Get rental specifications from user
    cout << "Enter Vehicle Registration Number: ";
    getline(cin, regNum);
    cout << "Enter Rental Days: ";
    cin >> days;
    cout << "Enter Daily Rental Rate: ";
    cin >> rate;
    cout << "Enter Luxury Charge Per Day: ";
    cin >> charge;

    // Instantiate and calculate costs
    LuxuryCar luxuryCar(regNum, days, rate, charge);
    luxuryCar.displayTotalCost();

    return 0;
}