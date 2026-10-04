#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    // Constructor with explicit assignment
    Temperature(float c = 0.0) {
        celsius = c;
    }

    void input() {
        float c;
        cout << "Enter temperature in Celsius: ";
        cin >> c;
        celsius = c;
    }

    // Overloading comparison operators
    bool operator<(const Temperature& t) const {
        return celsius < t.celsius;
    }

    bool operator>(const Temperature& t) const {
        return celsius > t.celsius;
    }

    float getCelsius() const { return celsius; }
};

int main() {
    Temperature t1, t2;

    cout << "--- Temperature 1 ---" << endl;
    t1.input();

    cout << "\n--- Temperature 2 ---" << endl;
    t2.input();

    cout << endl;
    if (t1 < t2) {
        cout << "First temperature (" << t1.getCelsius() << "°C) is LOWER than second temperature (" << t2.getCelsius() << "°C)." << endl;
    } 
    else if (t1 > t2) {
        cout << "First temperature (" << t1.getCelsius() << "°C) is HIGHER than second temperature (" << t2.getCelsius() << "°C)." << endl;
    } 
    else {
        cout << "Both temperatures are EQUAL (" << t1.getCelsius() << "°C)." << endl;
    }

    return 0;
}