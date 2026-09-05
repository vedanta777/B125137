#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int numSubjects;
    float* marks; // Member variable pointer to dynamically hold marks array

public:
    // Constructor initializes pointer to nullptr
    Student() : marks(nullptr), numSubjects(0) {}

    // Method to capture student details and allocate dynamic memory internally
    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Number of Subjects: ";
        cin >> numSubjects;

        // Dynamically allocate memory for subject marks inside the object
        marks = new float[numSubjects];

        cout << "Enter marks for " << numSubjects << " subjects as prompted" << endl;
        for (int i = 0; i < numSubjects; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    // Method to sum up subject marks
    float calculateTotal() const {
        float total = 0;
        for (int i = 0; i < numSubjects; i++) {
            total += marks[i];
        }
        return total;
    }

    // Method to compute overall average
    float calculateAverage() const {
        if (numSubjects == 0) return 0;
        return calculateTotal() / numSubjects;
    }

    // Display complete mark sheet
    void displayResult() const {
        cout << "\n--- Complete Student Result ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < numSubjects; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal Marks: " << calculateTotal() << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
    }

    // Destructor automatically frees dynamic memory allocated for member 'marks'
    ~Student() {
        delete[] marks; // Prevents memory leak when Student object goes out of scope
        marks = nullptr;
    }
};

int main() {
    Student s;
    s.acceptDetails();
    s.displayResult();
    
    // Destructor is automatically called here when 's' goes out of scope
    return 0;
}