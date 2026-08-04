#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
private:
    int empID;
    string name;
    double basicSalary;
    double hra;
    double da;
    double grossSalary;

public:
    void acceptDetails() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    void calculateSalary() {
        hra = 0.20 * basicSalary;
        da = 0.10 * basicSalary;
        grossSalary = basicSalary + hra + da;
    }

    void displaySalaryDetails() const {
        cout << "\n-----------------------------------" << endl;
        cout << "      EMPLOYEE SALARY SLIP         " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(18) << "Employee ID:" << empID << endl;
        cout << left << setw(18) << "Employee Name:" << name << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(18) << "Basic Salary:" << basicSalary << endl;
        cout << left << setw(18) << "HRA (20%):" << hra << endl;
        cout << left << setw(18) << "DA (10%):" << da << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(18) << "Gross Salary:" << grossSalary << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    Employee emp;
    emp.acceptDetails();
    emp.calculateSalary();
    emp.displaySalaryDetails();
    return 0;
}