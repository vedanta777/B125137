#include <iostream>
using namespace std;

class DataPrinter {
private:
    int flag;

public:
    DataPrinter() { flag = 0; }

    void display(int val) { cout << "Integer: " << val << endl; }
    void display(double val) { cout << "Float: " << val << endl; }
    void display(char val) { cout << "Character: " << val << endl; }
    void display(const int arr[], int size) {
        cout << "Integer Array: [ ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "]\n";
    }
    void display(const char arr[], int size) {
        cout << "Character Array: [ ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "]\n";
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- DATA PRINTER MENU ---\n";
            cout << "1. Display Integer\n";
            cout << "2. Display Float\n";
            cout << "3. Display Character\n";
            cout << "4. Display Integer Array\n";
            cout << "5. Display Character Array\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: { int v; cout << "Enter integer: "; cin >> v; display(v); break; }
                case 2: { double v; cout << "Enter float: "; cin >> v; display(v); break; }
                case 3: { char v; cout << "Enter character: "; cin >> v; display(v); break; }
                case 4: {
                    int s; cout << "Enter array size: "; cin >> s;
                    int* arr = new int[s];
                    for (int i = 0; i < s; i++) { cout << "Element " << i+1 << ": "; cin >> arr[i]; }
                    display(arr, s); delete[] arr; break;
                }
                case 5: {
                    int s; cout << "Enter array size: "; cin >> s;
                    char* arr = new char[s];
                    for (int i = 0; i < s; i++) { cout << "Element " << i+1 << ": "; cin >> arr[i]; }
                    display(arr, s); delete[] arr; break;
                }
            }
        } while (choice != 6);
    }
};

int main() {
    DataPrinter dp;
    dp.showMenu();
    return 0;
}