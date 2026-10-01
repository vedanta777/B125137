#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor with explicit assignment
    Complex(float r = 0.0, float i = 0.0) {
        real = r;
        imag = i;
    }

    void input() {
        float r, i;
        cout << "Enter real part: ";
        cin >> r;
        cout << "Enter imaginary part: ";
        cin >> i;
        real = r;
        imag = i;
    }

    // Overloading '-' operator
    Complex operator-(const Complex& c) const {
        float rDiff = real - c.real;
        float iDiff = imag - c.imag;
        return Complex(rDiff, iDiff); // Explicit constructor call
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(0, 0), c2(0, 0);

    cout << "--- Complex Number 1 ---" << endl;
    c1.input();

    cout << "\n--- Complex Number 2 ---" << endl;
    c2.input();

    Complex result = c1 - c2;

    cout << "\nC1 - C2 = ";
    result.display();

    return 0;
}