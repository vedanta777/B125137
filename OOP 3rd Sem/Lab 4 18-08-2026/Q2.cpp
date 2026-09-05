#include <iostream>
#include <string>
using namespace std;

class Mobile {
private:
    string brand;
    string model;
    int batteryPercentage;

public:
    // Constructor using explicit assignment
    Mobile(string b, string m, int battery) {
        brand = b;
        model = m;
        batteryPercentage = battery;
    }

    // Friend function declaration
    friend void checkBattery(const Mobile &m);
};

// Friend function definition
void checkBattery(const Mobile &m) {
    cout << "\n--- Mobile Details ---" << endl;
    cout << "Brand: " << m.brand << endl;
    cout << "Model: " << m.model << endl;
    cout << "Battery Percentage: " << m.batteryPercentage << "%" << endl;

    if (m.batteryPercentage < 20) {
        cout << "Status: Battery Low" << endl;
    } else {
        cout << "Status: Battery Normal" << endl;
    }
}

int main() {
    string brand, model;
    int battery;

    cout << "Enter Mobile Brand: ";
    getline(cin, brand);
    cout << "Enter Mobile Model: ";
    getline(cin, model);
    cout << "Enter Battery Percentage: ";
    cin >> battery;

    Mobile phone(brand, model, battery);
    checkBattery(phone);

    return 0;
}