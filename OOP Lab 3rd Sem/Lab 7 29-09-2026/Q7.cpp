#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor with explicit assignment
    Date(int d = 1, int m = 1, int y = 2026) {
        day = d;
        month = m;
        year = y;
    }

    void input() {
        int d, m, y;
        cout << "Enter Day, Month, Year (e.g., 15 08 2026): ";
        cin >> d >> m >> y;
        day = d;
        month = m;
        year = y;
    }

    // Overloading '==' operator
    bool operator==(const Date& d) const {
        return (day == d.day && month == d.month && year == d.year);
    }
};

int main() {
    Date d1, d2;

    cout << "--- Enter Date 1 ---" << endl;
    d1.input();

    cout << "\n--- Enter Date 2 ---" << endl;
    d2.input();

    cout << endl;
    if (d1 == d2) {
        cout << "Both dates are equal." << endl;
    } else {
        cout << "Dates are NOT equal." << endl;
    }

    return 0;
}