#include <iostream>
using namespace std;

class ValueModifier {
private:
    int intVal;
    double floatVal;

public:
    ValueModifier() {
        intVal = 0;
        floatVal = 0.0;
    }

    void modify(int &val, int addAmount) { val += addAmount; }
    void modify(double &val, double addAmount) { val += addAmount; }
    void modify(int *valPtr, int addAmount) { if (valPtr) *valPtr += addAmount; }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- VALUE MODIFIER MENU ---\n";
            cout << "1. Add to Integer (Reference)\n";
            cout << "2. Add to Float (Reference)\n";
            cout << "3. Add to Integer (Pointer)\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                int add;
                cout << "Enter base integer: "; cin >> intVal;
                cout << "Enter value to add: "; cin >> add;
                cout << "Before: " << intVal << endl;
                modify(intVal, add);
                cout << "After: " << intVal << endl;
            } else if (choice == 2) {
                double add;
                cout << "Enter base float: "; cin >> floatVal;
                cout << "Enter value to add: "; cin >> add;
                cout << "Before: " << floatVal << endl;
                modify(floatVal, add);
                cout << "After: " << floatVal << endl;
            } else if (choice == 3) {
                int add;
                cout << "Enter base integer: "; cin >> intVal;
                cout << "Enter value to add: "; cin >> add;
                cout << "Before: " << intVal << endl;
                modify(&intVal, add);
                cout << "After: " << intVal << endl;
            }
        } while (choice != 4);
    }
};

int main() {
    ValueModifier vm;
    vm.showMenu();
    return 0;
}