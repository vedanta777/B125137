#include <iostream>
#include <string>
using namespace std;

// Topmost shared base class
class Employee {
protected:
    int employeeID;
    string name;

public:
    Employee(int id = 0, string n = "") {
        employeeID = id;
        name = n;
    }
};

// Virtual inheritance ensures single instance of Employee
class Developer : virtual public Employee {
protected:
    string programmingLanguage;

public:
    Developer(int id = 0, string n = "", string lang = "") : Employee(id, n) {
        programmingLanguage = lang;
    }
};

// Virtual inheritance ensures single instance of Employee
class Tester : virtual public Employee {
protected:
    string testingTool;

public:
    Tester(int id = 0, string n = "", string tool = "") : Employee(id, n) {
        testingTool = tool;
    }
};

// Derived from both Developer and Tester
class TechLead : public Developer, public Tester {
public:
    // TechLead directly initializes shared virtual base (Employee)
    TechLead(int id = 0, string n = "", string lang = "", string tool = "") 
        : Employee(id, n), Developer(id, n, lang), Tester(id, n, tool) {}

    void display() {
        cout << "\n--- Tech Lead Profile ---" << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Primary Programming Language: " << programmingLanguage << endl;
        cout << "Testing Tool Specialty: " << testingTool << endl;
    }
};

int main() {
    int id;
    string name, lang, tool;

    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Programming Language: ";
    getline(cin, lang);
    cout << "Enter Testing Tool: ";
    getline(cin, tool);

    // Instantiate TechLead without triggering diamond inheritance duplication
    TechLead lead(id, name, lang, tool);
    lead.display();

    return 0;
}