#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    // Member function to accept student data
    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Clear newline character left in input buffer by cin
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Member function to display student data
    void displayDetails() {
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    // Dynamically instantiate a 'Student' object on the heap using 'new'
    Student* s = new Student();

    // Access class member functions using the arrow operator '->' for pointer objects
    s->acceptDetails();
    s->displayDetails();

    // Invoke object destructor (if defined) and free memory allocated for the object
    delete s;
    s = nullptr;

    return 0;
}