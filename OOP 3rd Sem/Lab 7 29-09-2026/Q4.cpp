#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor with explicit assignment
    Number(int v = 0) {
        value = v;
    }

    // Overloading unary '-' operator using explicit constructor call
    Number operator-() const {
        return Number(-value);
    }

    void display() const {
        cout << value << endl;
    }
};

int main() {
    int val;
    cout << "Enter an integer value: ";
    cin >> val;

    Number n1(val);
    Number n2 = -n1; // Overloaded operator creates new object

    cout << "\nOriginal object (n1): ";
    n1.display();

    cout << "New object (n2): ";
    n2.display();

    return 0;
}