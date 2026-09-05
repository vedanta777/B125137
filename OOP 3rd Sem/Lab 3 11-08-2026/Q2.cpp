#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamically allocate a contiguous block of memory on the heap for 'n' integers.
    int* arr = new int[n];

    // Read elements individually with a prompt for each index
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i]; // Store input into array at index i
    }

    // Display the array elements
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free dynamically allocated array memory
    delete[] arr;

    // Reset pointer to nullptr for memory safety
    arr = nullptr;

    return 0;
}