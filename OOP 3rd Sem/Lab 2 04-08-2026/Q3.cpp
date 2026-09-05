#include <iostream>
#include <iomanip>

using namespace std;

class Calculator {
private:
    double num1;
    double num2;

public:
    void inputNumbers() {
        cout << "Enter First Number: ";
        cin >> num1;
        cout << "Enter Second Number: ";
        cin >> num2;
    }

    void add() const {
        cout << "Addition (" << num1 << " + " << num2 << ") = " << (num1 + num2) << endl;
    }

    void subtract() const {
        cout << "Subtraction (" << num1 << " - " << num2 << ") = " << (num1 - num2) << endl;
    }

    void multiply() const {
        cout << "Multiplication (" << num1 << " * " << num2 << ") = " << (num1 * num2) << endl;
    }

    void divide() const {
        if (num2 == 0) {
            cout << "Division Error: Division by zero is undefined!" << endl;
        } else {
            cout << "Division (" << num1 << " / " << num2 << ") = " << (num1 / num2) << endl;
        }
    }
};

int main() {
    Calculator calc;
    calc.inputNumbers();
    
    cout << "\n-----------------------------------" << endl;
    cout << "        CALCULATOR RESULTS         " << endl;
    cout << "-----------------------------------" << endl;
    calc.add();
    calc.subtract();
    calc.multiply();
    calc.divide();
    cout << "-----------------------------------" << endl;

    return 0;
}