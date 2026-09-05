#include <iostream>
#include <cmath>
using namespace std;

class Counter {
private:
    int state;

public:
    Counter() { state = 0; }

    int count(int num) {
        if (num == 0) return 1;
        num = abs(num);
        int c = 0;
        while (num > 0) { c++; num /= 10; }
        return c;
    }

    int count(const int arr[], int size) { return size; }

    int count(const char arr[], int size, char target) {
        int c = 0;
        for (int i = 0; i < size; i++) if (arr[i] == target) c++;
        return c;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- COUNTER MENU ---\n";
            cout << "1. Count Digits in Integer\n";
            cout << "2. Count Elements in Array\n";
            cout << "3. Count Occurrences of Character\n";
            cout << "4. Exit\n";
            cout << "Enter choice: "; cin >> choice;

            if (choice == 1) {
                int n; cout << "Enter integer: "; cin >> n;
                cout << "Digits: " << count(n) << endl;
            } else if (choice == 2) {
                int s; cout << "Enter size: "; cin >> s;
                int* arr = new int[s];
                for (int i = 0; i < s; i++) { cout << "E" << i+1 << ": "; cin >> arr[i]; }
                cout << "Count: " << count(arr, s) << endl;
                delete[] arr;
            } else if (choice == 3) {
                int s; cout << "Enter size: "; cin >> s;
                char* arr = new char[s];
                for (int i = 0; i < s; i++) { cout << "E" << i+1 << ": "; cin >> arr[i]; }
                char target; cout << "Target char: "; cin >> target;
                cout << "Occurrences: " << count(arr, s, target) << endl;
                delete[] arr;
            }
        } while (choice != 4);
    }
};

int main() {
    Counter c;
    c.showMenu();
    return 0;
}