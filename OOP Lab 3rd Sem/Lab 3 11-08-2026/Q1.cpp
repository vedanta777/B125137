#include <iostream>
using namespace std;

int main() {
    // 1. Dynamically allocate memory for a single integer on the heap.
    // 'new int' requests memory from the heap and returns its memory address, 
    // which is stored in the integer pointer 'ptr'.
    int* ptr = new int;

    // 2. Prompt the user for input and store it in the allocated memory space.
    cout << "Enter an integer: ";
    cin >> *ptr; // Dereference operator '*' accesses the memory location pointed to by 'ptr'

    // 3. Display the stored value
    cout << "Value stored at allocated memory: " << *ptr << endl;

    // 4. Release/free the dynamically allocated heap memory back to the system
    delete ptr;

    // 5. Reset pointer to nullptr to prevent a dangling pointer reference
    ptr = nullptr;

    return 0;
}