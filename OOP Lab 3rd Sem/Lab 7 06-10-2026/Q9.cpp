#include <iostream>
#include <string>
using namespace std;

// Topmost base class
class Person {
protected:
    string name;

public:
    Person(string n = "") {
        name = n;
        // Tracing constructor execution order
        cout << "[Execution] Person constructor executed." << endl;
    }
};

// Intermediate derived class
class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(string n = "", int empID = 0) : Person(n) {
        employeeID = empID;
        cout << "[Execution] Employee constructor executed." << endl;
    }
};

// Bottom-most derived class
class Manager : public Employee {
private:
    string department;

public:
    Manager(string n = "", int empID = 0, string dept = "") : Employee(n, empID) {
        department = dept;
        cout << "[Execution] Manager constructor executed." << endl;
    }

    void displayDetails() {
        cout << "\n--- Manager Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    string name, dept;
    int empID;

    cout << "Enter Manager Name: ";
    getline(cin, name);
    cout << "Enter Employee ID: ";
    cin >> empID;
    cin.ignore(); // Clear buffer prior to reading string
    cout << "Enter Department: ";
    getline(cin, dept);

    cout << "\n--- Constructor Invocation Sequence ---" << endl;
    // Creating Manager object triggers base-to-derived constructor sequence
    Manager mgr(name, empID, dept);

    mgr.displayDetails();

    return 0;
}