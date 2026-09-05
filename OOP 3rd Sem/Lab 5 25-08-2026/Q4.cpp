#include <iostream>
using namespace std;

class ElementSearcher {
private:
    int totalElements;

public:
    ElementSearcher() {
        totalElements = 0;
    }

    int search(const int arr[], int n, int target) {
        for (int i = 0; i < n; i++) if (arr[i] == target) return i;
        return -1;
    }

    int search(const char arr[], int n, char target) {
        for (int i = 0; i < n; i++) if (arr[i] == target) return i;
        return -1;
    }

    int search(const int arr[], int startIdx, int endIdx, int target) {
        for (int i = startIdx; i <= endIdx; i++) if (arr[i] == target) return i;
        return -1;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n--- ELEMENT SEARCH MENU ---\n";
            cout << "1. Search Integer in Integer Array\n";
            cout << "2. Search Character in Character Array\n";
            cout << "3. Search Integer in Bounded Range\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter size: "; cin >> totalElements;
                int* arr = new int[totalElements];
                for (int i = 0; i < totalElements; i++) {
                    cout << "Enter element " << (i + 1) << ": "; cin >> arr[i];
                }
                int target; cout << "Enter integer to search: "; cin >> target;
                int pos = search(arr, totalElements, target);
                if (pos != -1) cout << "Found at index: " << pos << endl;
                else cout << "Not found.\n";
                delete[] arr;
            } 
            else if (choice == 2) {
                cout << "Enter size: "; cin >> totalElements;
                char* arr = new char[totalElements];
                for (int i = 0; i < totalElements; i++) {
                    cout << "Enter character " << (i + 1) << ": "; cin >> arr[i];
                }
                char target; cout << "Enter character to search: "; cin >> target;
                int pos = search(arr, totalElements, target);
                if (pos != -1) cout << "Found at index: " << pos << endl;
                else cout << "Not found.\n";
                delete[] arr;
            } 
            else if (choice == 3) {
                cout << "Enter size: "; cin >> totalElements;
                int* arr = new int[totalElements];
                for (int i = 0; i < totalElements; i++) {
                    cout << "Enter element " << (i + 1) << ": "; cin >> arr[i];
                }
                int start, end, target;
                cout << "Enter start index: "; cin >> start;
                cout << "Enter end index: "; cin >> end;
                cout << "Enter target: "; cin >> target;
                int pos = search(arr, start, end, target);
                if (pos != -1) cout << "Found at index: " << pos << endl;
                else cout << "Not found in range.\n";
                delete[] arr;
            }
        } while (choice != 4);
    }
};

int main() {
    ElementSearcher es;
    es.showMenu();
    return 0;
}