#include <iostream>
using namespace std;

class DataSetComparator {
private:
    int count;

public:
    DataSetComparator() { count = 0; }

    int compare(int a, int b) { return (a > b) ? a : b; }
    double compare(double a, double b) { return (a > b) ? a : b; }
    bool compare(const int arr1[], const int arr2[], int size) {
        for (int i = 0; i < size; i++) if (arr1[i] != arr2[i]) return false;
        return true;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- DATASET COMPARATOR MENU ---\n";
            cout << "1. Compare 2 Integers\n";
            cout << "2. Compare 2 Floats\n";
            cout << "3. Compare 2 Integer Arrays\n";
            cout << "4. Exit\n";
            cout << "Enter choice: "; cin >> choice;

            if (choice == 1) {
                int a, b;
                cout << "Enter first integer: "; cin >> a;
                cout << "Enter second integer: "; cin >> b;
                cout << "Larger: " << compare(a, b) << endl;
            } else if (choice == 2) {
                double a, b;
                cout << "Enter first float: "; cin >> a;
                cout << "Enter second float: "; cin >> b;
                cout << "Larger: " << compare(a, b) << endl;
            } else if (choice == 3) {
                int s; cout << "Enter array size: "; cin >> s;
                int* a1 = new int[s]; int* a2 = new int[s];
                cout << "-- Array 1 --\n"; for (int i = 0; i < s; i++) { cout << "E" << i+1 << ": "; cin >> a1[i]; }
                cout << "-- Array 2 --\n"; for (int i = 0; i < s; i++) { cout << "E" << i+1 << ": "; cin >> a2[i]; }
                if (compare(a1, a2, s)) cout << "Arrays are identical.\n";
                else cout << "Arrays are NOT identical.\n";
                delete[] a1; delete[] a2;
            }
        } while (choice != 4);
    }
};

int main() {
    DataSetComparator dsc;
    dsc.showMenu();
    return 0;
}