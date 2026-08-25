#include <iostream>
using namespace std;

class MaximumValueFinder {
private:
    int dummy;

public:
    MaximumValueFinder() { dummy = 0; }

    int findMax(int a, int b) { return (a > b) ? a : b; }
    int findMax(const int* ptr1, const int* ptr2) { return (*ptr1 > *ptr2) ? *ptr1 : *ptr2; }
    int findMax(const int* ptr, int size) {
        int maxVal = ptr[0];
        for (int i = 1; i < size; i++) if (ptr[i] > maxVal) maxVal = ptr[i];
        return maxVal;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- MAXIMUM VALUE FINDER MENU ---\n";
            cout << "1. Max of Two Integers (Values)\n";
            cout << "2. Max of Two Integers (Pointers)\n";
            cout << "3. Max of Array (Pointer + Size)\n";
            cout << "4. Exit\n";
            cout << "Enter choice: "; cin >> choice;

            if (choice == 1) {
                int a, b;
                cout << "Enter first integer: "; cin >> a;
                cout << "Enter second integer: "; cin >> b;
                cout << "Max: " << findMax(a, b) << endl;
            } else if (choice == 2) {
                int a, b;
                cout << "Enter first integer: "; cin >> a;
                cout << "Enter second integer: "; cin >> b;
                cout << "Max using pointers: " << findMax(&a, &b) << endl;
            } else if (choice == 3) {
                int s; cout << "Enter array size: "; cin >> s;
                int* arr = new int[s];
                for (int i = 0; i < s; i++) { cout << "E" << i+1 << ": "; cin >> arr[i]; }
                cout << "Max in array: " << findMax(arr, s) << endl;
                delete[] arr;
            }
        } while (choice != 4);
    }
};

int main() {
    MaximumValueFinder mvf;
    mvf.showMenu();
    return 0;
}