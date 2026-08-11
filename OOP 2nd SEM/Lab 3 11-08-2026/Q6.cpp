#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    // Accept employee information
    void acceptDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // Flush newline character from the input buffer
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Display employee information
    void displayDetails() {
        cout << "ID: " << id << " | Name: " << name << " | Salary: " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Dynamically allocate an array of 'n' Employee objects.
    // This calls the default constructor for each element in the array.
    Employee* employees = new Employee[n];

    // Accept details for each employee in the dynamic array
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << (i + 1) << ":" << endl;
        employees[i].acceptDetails(); // Use dot operator because employees[i] dereferences the array element
    }

    // Display details for all employees
    cout << "\n--- Employee Details ---" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].displayDetails();
    }

    // Free the entire array of objects from heap memory using 'delete[]'
    delete[] employees;
    employees = nullptr;

    return 0;
}