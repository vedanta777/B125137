#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    // Constructor with explicit assignment
    Counter(int c = 0) {
        count = c;
    }

    // Prefix increment (++c)
    Counter& operator++() {
        count = count + 1;
        return *this;
    }

    // Postfix increment (c++) returning temporary state using explicit constructor
    Counter operator++(int) {
        Counter temp(count); // Explicit assignment constructor
        count = count + 1;
        return temp;
    }

    void display() const {
        cout << "Counter value: " << count << endl;
    }
};

int main() {
    int val;
    cout << "Enter initial counter value: ";
    cin >> val;

    Counter c(val);

    cout << "\n--- Prefix Increment (++c) ---" << endl;
    cout << "Before operation: ";
    c.display();
    Counter cPrefix = ++c;
    cout << "After operation: ";
    c.display();
    cout << "Returned value: ";
    cPrefix.display();

    cout << "\n--- Postfix Increment (c++) ---" << endl;
    cout << "Before operation: ";
    c.display();
    Counter cPostfix = c++;
    cout << "After operation: ";
    c.display();
    cout << "Returned value: ";
    cPostfix.display();

    return 0;
}