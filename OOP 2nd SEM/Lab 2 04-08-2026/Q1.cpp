#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Clear buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayDetails() const {
        cout << "\n-----------------------------------" << endl;
        cout << "         STUDENT DETAILS          " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(15) << "Roll Number:" << rollNumber << endl;
        cout << left << setw(15) << "Name:" << name << endl;
        cout << left << setw(15) << "Marks:" << fixed << setprecision(2) << marks << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    Student student;
    cout << "--- Enter Student Information ---" << endl;
    student.acceptDetails();
    student.displayDetails();
    return 0;
}