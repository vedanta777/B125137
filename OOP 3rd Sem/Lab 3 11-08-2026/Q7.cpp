#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // STEP 1: Allocate an array of 'm' pointers (pointer-to-pointer approach)
    // 'matrix' holds the base address of an array containing row pointers (int*)
    int** matrix = new int*[m];

    // STEP 2: Allocate memory for each individual row (an array of 'n' integers per row)
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    // Input 2D matrix elements from user
    cout << "Enter elements of " << m << "x" << n << " matrix as prompted" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> *(*(matrix + i) + j); 
            // Using pointer arithmetic to access matrix[i][j]
        }
    }

    // Display matrix in 2D grid format
    cout << "\nMatrix output:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // STEP 3: Deallocate memory for each individual row first
    for (int i = 0; i < m; i++) {
        delete[] matrix[i]; // Free memory allocated for each row array
    }

    // STEP 4: Deallocate the outer array of row pointers
    delete[] matrix;
    matrix = nullptr;

    return 0;
}