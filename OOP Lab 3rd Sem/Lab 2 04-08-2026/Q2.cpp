#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
    void readDimensions() {
        cout << "Enter Length of Rectangle: ";
        cin >> length;
        cout << "Enter Breadth of Rectangle: ";
        cin >> breadth;
    }

    double calculateArea() const {
        return length * breadth;
    }

    double calculatePerimeter() const {
        return 2 * (length + breadth);
    }

    void displayResults() const {
        cout << "\n-----------------------------------" << endl;
        cout << "       RECTANGLE RESULTS           " << endl;
        cout << "-----------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "Length:    " << length << endl;
        cout << "Breadth:   " << breadth << endl;
        cout << "Area:      " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    Rectangle rect;
    rect.readDimensions();
    rect.displayResults();
    return 0;
}