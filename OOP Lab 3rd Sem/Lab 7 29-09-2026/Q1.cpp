#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor with explicit assignment
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    void input() {
        int f, i;
        cout << "Enter feet: ";
        cin >> f;
        cout << "Enter inches: ";
        cin >> i;
        feet = f;
        inches = i;
    }

    // Overloading '+' operator returning a new object created explicitly via constructor
    Distance operator+(const Distance& d) const {
        int totalFeet = feet + d.feet;
        int totalInches = inches + d.inches;

        if (totalInches >= 12) {
            totalFeet += totalInches / 12;
            totalInches %= 12;
        }

        return Distance(totalFeet, totalInches); // Explicit constructor call
    }

    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1, d2;

    cout << "--- Distance 1 ---" << endl;
    d1.input();

    cout << "\n--- Distance 2 ---" << endl;
    d2.input();

    Distance sum = d1 + d2;

    cout << "\nResult:" << endl;
    sum.display();

    return 0;
}