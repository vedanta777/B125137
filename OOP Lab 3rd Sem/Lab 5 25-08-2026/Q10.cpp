#include <iostream>
using namespace std;

class DataProcessor {
private:
    int id;

public:
    DataProcessor() { id = 1; }

    double process(int a, int b) { return (a + b) / 2.0; }
    double process(int a, double b) { return (a + b) / 2.0; }
    double process(double a, double b) { return (a + b) / 2.0; }
    double process(const int arr[], int size) {
        if (size <= 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < size; i++) sum += arr[i];
        return sum / size;
    }
    double process(const int* p1, const int* p2) { return (*p1 + *p2) / 2.0; }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- DATA PROCESSOR (AVERAGE) MENU ---\n";
            cout << "1. Average of 2 Integers\n";
            cout << "2. Average of 1 Integer and 1 Float\n";
            cout << "3. Average of 2 Floats\n";
            cout << "4. Average of Array Elements\n";
            cout << "5. Average using 2 Pointers\n";
            cout << "6. Exit\n";
            cout << "Enter choice: "; cin >> choice;

            if (choice == 1) {
                int a, b;
                cout << "Enter first integer: "; cin >> a;
                cout << "Enter second integer: "; cin >> b;
                cout << "Average: " << process(a, b) << endl;
            } else if (choice == 2) {
                int a; double b;
                cout << "Enter integer: "; cin >> a;
                cout << "Enter float: "; cin >> b;
                cout << "Average: " << process(a, b) << endl;
            } else if (choice == 3) {
                double a, b;
                cout << "Enter first float: "; cin >> a;
                cout << "Enter second float: "; cin >> b;
                cout << "Average: " << process(a, b) << endl;
            } else if (choice == 4) {
                int s; cout << "Enter size: "; cin >> s;
                int* arr = new int[s];
                for (int i = 0; i < s; i++) { cout << "E" << i+1 << ": "; cin >> arr[i]; }
                cout << "Average: " << process(arr, s) << endl;
                delete[] arr;
            } else if (choice == 5) {
                int a, b;
                cout << "Enter first integer: "; cin >> a;
                cout << "Enter second integer: "; cin >> b;
                cout << "Average: " << process(&a, &b) << endl;
            }
        } while (choice != 6);
    }
};

int main() {
    DataProcessor dp;
    dp.showMenu();
    return 0;
}