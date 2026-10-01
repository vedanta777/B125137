#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Constructor with explicit assignment
    Time(int h = 0, int m = 0) {
        hours = h;
        minutes = m;
    }

    void input() {
        int h, m;
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        hours = h;
        minutes = m;
    }

    // Overloading '+' operator using explicit constructor call
    Time operator+(const Time& t) const {
        int totalHours = hours + t.hours;
        int totalMinutes = minutes + t.minutes;

        if (totalMinutes >= 60) {
            totalHours += totalMinutes / 60;
            totalMinutes %= 60;
        }

        return Time(totalHours, totalMinutes);
    }

    void display() const {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

int main() {
    Time t1, t2;

    cout << "--- Time 1 ---" << endl;
    t1.input();

    cout << "\n--- Time 2 ---" << endl;
    t2.input();

    Time total = t1 + t2;

    cout << "\nResult: ";
    total.display();

    return 0;
}