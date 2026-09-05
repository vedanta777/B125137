#include <iostream>
using namespace std;

// Class to perform overloaded calculations
class NumberCalculator {
private:
    int val1, val2, val3;
    double dVal1, dVal2;

public:
    // Constructor using explicit initialization inside body
    NumberCalculator() {
        val1 = 0;
        val2 = 0;
        val3 = 0;
        dVal1 = 0.0;
        dVal2 = 0.0;
    }

    // Overloaded calculation functions
    int calculate(int a, int b) { return a + b; }
    int calculate(int a, int b, int c) { return a + b + c; }
    double calculate(double a, double b) { return a + b; }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- NUMBER CALCULATOR MENU ---\n";
            cout << "1. Add 2 Integers\n";
            cout << "2. Add 3 Integers\n";
            cout << "3. Add 2 Floating-Point Numbers\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter first integer: "; cin >> val1;
                    cout << "Enter second integer: "; cin >> val2;
                    cout << "Result: " << calculate(val1, val2) << endl;
                    break;
                case 2:
                    cout << "Enter first integer: "; cin >> val1;
                    cout << "Enter second integer: "; cin >> val2;
                    cout << "Enter third integer: "; cin >> val3;
                    cout << "Result: " << calculate(val1, val2, val3) << endl;
                    break;
                case 3:
                    cout << "Enter first float: "; cin >> dVal1;
                    cout << "Enter second float: "; cin >> dVal2;
                    cout << "Result: " << calculate(dVal1, dVal2) << endl;
                    break;
                case 4:
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    NumberCalculator calc;
    calc.showMenu();
    return 0;
}