#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of floating-point numbers: ";
    cin >> n;

    // Dynamically allocate memory for 'n' float numbers
    float* arr = new float[n];
    float sum = 0.0f;

    cout << "Enter " << n << " floating numbers as prompted" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter floating-point number " << (i + 1) << ": ";
        cin >> arr[i]; // Store input into array at index i
        sum += arr[i]; // Accumulate the sum of all elements
    }

    // Compute average
    float average = sum / n;

    // Display total sum and average
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    // Clean up allocated memory
    delete[] arr;
    arr = nullptr;

    return 0;
}