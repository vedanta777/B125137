#include <iostream>
#include <string>
using namespace std;

// Base Person class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) {
        name = n;
        age = a;
    }
};

// Virtual base class inheritance prevents multiple copies of Person in TeachingAssistant
class Student : virtual public Person {
protected:
    int rollNo;
    double cgpa;

public:
    Student(string n = "", int a = 0, int r = 0, double c = 0.0) : Person(n, a) {
        rollNo = r;
        cgpa = c;
    }
};

// Virtual base class inheritance
class Employee : virtual public Person {
protected:
    int employeeID;
    double salary;

public:
    Employee(string n = "", int a = 0, int empID = 0, double sal = 0.0) : Person(n, a) {
        employeeID = empID;
        salary = sal;
    }
};

// Most derived class in the diamond structure
class TeachingAssistant : public Student, public Employee {
public:
    // Explicit call to Person constructor required due to virtual inheritance
    TeachingAssistant(string n = "", int a = 0, int r = 0, double c = 0.0, int empID = 0, double sal = 0.0) 
        : Person(n, a), Student(n, a, r, c), Employee(n, a, empID, sal) {}

    void display() {
        cout << "\n--- Teaching Assistant Information ---" << endl;
        // Direct access to name and age without ambiguity errors
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    string name;
    int age, rollNo, empID;
    double cgpa, salary;

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter CGPA: ";
    cin >> cgpa;
    cout << "Enter Employee ID: ";
    cin >> empID;
    cout << "Enter Salary: ";
    cin >> salary;

    TeachingAssistant ta(name, age, rollNo, cgpa, empID, salary);
    ta.display();

    return 0;
}