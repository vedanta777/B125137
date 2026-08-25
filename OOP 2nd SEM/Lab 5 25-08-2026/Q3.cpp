#include <iostream>
using namespace std;

class ArrayTotalCalculator {
private:
    int size;

public:
    ArrayTotalCalculator() {
        size = 0;
    }

    int total(const int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        return sum;
    }

    double total(const double arr[], int n) {
        double sum = 0.0;
        for (int i = 0; i < n; i++) sum += arr[i];
        return sum;
    }

    int total(const int arr[], int totalElements, int countToSum) {
        int sum = 0;
        for (int i = 0; i < countToSum && i < totalElements; i++) sum += arr[i];
        return sum;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- ARRAY TOTAL MENU ---\n";
            cout << "1. Total of Integer Array\n";
            cout << "2. Total of Float Array\n";
            cout << "3. Total of Integer Array Portion\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter size: "; cin >> size;
                int* arr = new int[size];
                for (int i = 0; i < size; i++) {
                    cout << "Enter element " << (i + 1) << ": "; cin >> arr[i];
                }
                cout << "Total: " << total(arr, size) << endl;
                delete[] arr;
            } else if (choice == 2) {
                cout << "Enter size: "; cin >> size;
                double* arr = new double[size];
                for (int i = 0; i < size; i++) {
                    cout << "Enter element " << (i + 1) << ": "; cin >> arr[i];
                }
                cout << "Total: " << total(arr, size) << endl;
                delete[] arr;
            } else if (choice == 3) {
                cout << "Enter full size: "; cin >> size;
                int* arr = new int[size];
                for (int i = 0; i < size; i++) {
                    cout << "Enter element " << (i + 1) << ": "; cin >> arr[i];
                }
                int portion;
                cout << "Enter number of elements to consider: "; cin >> portion;
                cout << "Portion Total: " << total(arr, size, portion) << endl;
                delete[] arr;
            }
        } while (choice != 4);
    }
};

int main() {
    ArrayTotalCalculator calc;
    calc.showMenu();
    return 0;
}