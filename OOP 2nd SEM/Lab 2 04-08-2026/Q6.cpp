#include <iostream>

using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    void inputDistance(int num) {
        cout << "Enter Distance " << num << " (Feet Inches): ";
        cin >> feet >> inches;
    }

    void addDistances(const Distance &d1, const Distance &d2) {
        inches = d1.inches + d2.inches;
        feet = d1.feet + d2.feet + (inches / 12);
        inches = inches % 12;
    }

    void displayDistance() const {
        cout << feet << " ft " << inches << " in" << endl;
    }
};

int main() {
    Distance d1, d2, total;

    d1.inputDistance(1);
    d2.inputDistance(2);

    total.addDistances(d1, d2);

    cout << "\n-----------------------------------" << endl;
    cout << "Distance 1: "; d1.displayDistance();
    cout << "Distance 2: "; d2.displayDistance();
    cout << "-----------------------------------" << endl;
    cout << "Total Distance: "; total.displayDistance();
    cout << "-----------------------------------" << endl;

    return 0;
}