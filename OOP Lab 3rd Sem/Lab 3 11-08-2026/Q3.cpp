#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;

    // Allocate heap memory for 'n' integers
    int* arr = new int[n];

    cout << "Enter " << n << " integers as prompted" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter integer \t" << (i + 1) << ": ";
        cin >> arr[i]; // Store input into array at index i
    }

    // Initialize 'largest' with the value of the first element using dereferencing (*arr)
    int largest = *arr;

    // Iterate through the array using pointer arithmetic to find the maximum value
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > largest) {
            largest = *(arr + i); // Update largest if current element is greater
        }
    }

    cout << "Largest element = " << largest << endl;

    // Deallocate the dynamic array memory
    delete[] arr;
    arr = nullptr;

    return 0;
}