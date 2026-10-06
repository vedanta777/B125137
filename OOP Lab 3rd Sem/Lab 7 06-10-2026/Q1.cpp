#include <iostream>
#include <string>
using namespace std;

// Base class representing a general employee
class Employee {
protected:
    string name;
    double basicSalary;

public:
    // Parameterized constructor with default values and direct assignment
    Employee(string n = "", double bSalary = 0.0) {
        name = n;
        basicSalary = bSalary;
    }
};

// Intermediate derived class representing a developer (Inherits from Employee)
class Developer : public Employee {
protected:
    int experience; // Experience in years

public:
    // Constructor calling base class Employee constructor
    Developer(string n = "", double bSalary = 0.0, int exp = 0) : Employee(n, bSalary) {
        experience = exp;
    }
};

// Most derived class representing a senior developer (Inherits from Developer)
class SeniorDeveloper : public Developer {
private:
    double projectBonus;

public:
    // Constructor passing arguments up the multilevel hierarchy
    SeniorDeveloper(string n = "", double bSalary = 0.0, int exp = 0, double pBonus = 0.0) 
        : Developer(n, bSalary, exp) {
        projectBonus = pBonus;
    }

    // Calculates and outputs the salary breakdown
    void displaySalary() {
        // Experience Bonus = 5% of Basic Salary * Experience Years
        double expBonus = 0.05 * basicSalary * experience;
        double finalSalary = basicSalary + expBonus + projectBonus;

        cout << "\n--- Employee Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Experience Bonus: " << expBonus << endl;
        cout << "Project Bonus: " << projectBonus << endl;
        cout << "Final Salary: " << finalSalary << endl;
    }
};

int main() {
    string name;
    double basicSalary, projectBonus;
    int experience;

    // Prompt user for input details
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Basic Salary: ";
    cin >> basicSalary;
    cout << "Enter Experience (in years): ";
    cin >> experience;
    cout << "Enter Project Bonus: ";
    cin >> projectBonus;

    // Instantiate SeniorDeveloper object using explicit constructor assignment
    SeniorDeveloper dev(name, basicSalary, experience, projectBonus);
    
    // Display results
    dev.displaySalary();

    return 0;
}