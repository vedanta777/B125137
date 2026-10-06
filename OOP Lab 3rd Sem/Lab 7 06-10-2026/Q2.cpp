#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class representing a general student
class Student {
protected:
    string name;
    int rollNo;

public:
    // Constructor with default parameters
    Student(string n = "", int r = 0) {
        name = n;
        rollNo = r;
    }

    // Pure virtual function to enable polymorphic overriding in derived classes
    virtual void calculateResult() = 0;
};

// Derived class for regular students
class RegularStudent : public Student {
private:
    double totalMarks;

public:
    RegularStudent(string n = "", int r = 0, double marks = 0.0) : Student(n, r) {
        totalMarks = marks;
    }

    // Overridden function to display result without modifications
    void calculateResult() override {
        cout << "\n--- Regular Student Result ---" << endl;
        cout << "Name: " << name << "\nRoll No: " << rollNo << endl;
        cout << "Final Total Marks: " << totalMarks << endl;
    }
};

// Derived class for scholarship students
class ScholarshipStudent : public Student {
private:
    double totalMarks;

public:
    ScholarshipStudent(string n = "", int r = 0, double marks = 0.0) : Student(n, r) {
        totalMarks = marks;
    }

    // Overridden function to add 5 bonus marks to the student's result
    void calculateResult() override {
        double finalMarks = totalMarks + 5; // Adding 5 bonus marks
        cout << "\n--- Scholarship Student Result ---" << endl;
        cout << "Name: " << name << "\nRoll No: " << rollNo << endl;
        cout << "Original Marks: " << totalMarks << endl;
        cout << "Bonus Marks: 5" << endl;
        cout << "Final Total Marks: " << finalMarks << endl;
    }
};

int main() {
    string name;
    int rollNo;
    double marks;

    // Get details for Regular Student
    cout << "Enter Regular Student Name: ";
    getline(cin, name);
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Total Marks: ";
    cin >> marks;
    RegularStudent regStud(name, rollNo, marks);

    // Consume trailing newline from input stream before reading the next string
    cin.ignore();

    // Get details for Scholarship Student
    cout << "\nEnter Scholarship Student Name: ";
    getline(cin, name);
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Total Marks: ";
    cin >> marks;
    ScholarshipStudent scholStud(name, rollNo, marks);

    // Call overridden methods
    regStud.calculateResult();
    scholStud.calculateResult();

    return 0;
}