#include <iostream>
using namespace std;

class ValueComparator {
private:
    int num1, num2, num3;
    double dNum1, dNum2;

public:
    ValueComparator() {
        num1 = 0; num2 = 0; num3 = 0;
        dNum1 = 0.0; dNum2 = 0.0;
    }

    int findLarger(int a, int b) { return (a > b) ? a : b; }
    double findLarger(double a, double b) { return (a > b) ? a : b; }
    int findLarger(int a, int b, int c) {
        if (a >= b && a >= c) return a;
        if (b >= a && b >= c) return b;
        return c;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- VALUE COMPARISON MENU ---\n";
            cout << "1. Compare 2 Integers\n";
            cout << "2. Compare 2 Floating-Point Numbers\n";
            cout << "3. Compare 3 Integers\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter first integer: "; cin >> num1;
                    cout << "Enter second integer: "; cin >> num2;
                    cout << "Larger: " << findLarger(num1, num2) << endl;
                    break;
                case 2:
                    cout << "Enter first float: "; cin >> dNum1;
                    cout << "Enter second float: "; cin >> dNum2;
                    cout << "Larger: " << findLarger(dNum1, dNum2) << endl;
                    break;
                case 3:
                    cout << "Enter first integer: "; cin >> num1;
                    cout << "Enter second integer: "; cin >> num2;
                    cout << "Enter third integer: "; cin >> num3;
                    cout << "Larger: " << findLarger(num1, num2, num3) << endl;
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }
};

int main() {
    ValueComparator comp;
    comp.showMenu();
    return 0;
}