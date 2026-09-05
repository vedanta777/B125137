#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class StudentResult {
private:
    string studentName;
    int rollNumber;
    float marks[5];
    float totalMarks;
    float percentage;
    char grade;

public:
    void acceptDetails() {
        cout << "Enter Student Name: ";
        getline(cin, studentName);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter marks for 5 subjects (out of 100 each):\n";
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    void calculateResult() {
        totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            totalMarks += marks[i];
        }
        percentage = (totalMarks / 500.0f) * 100.0f;

        if (percentage >= 90) grade = 'A';
        else if (percentage >= 80) grade = 'B';
        else if (percentage >= 70) grade = 'C';
        else if (percentage >= 60) grade = 'D';
        else grade = 'F';
    }

    void displayResult() const {
        cout << "\n-----------------------------------" << endl;
        cout << "       STUDENT RESULT SHEET        " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(15) << "Roll Number:" << rollNumber << endl;
        cout << left << setw(15) << "Name:" << studentName << endl;
        cout << "-----------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(15) << "Total Marks:" << totalMarks << " / 500" << endl;
        cout << left << setw(15) << "Percentage:" << percentage << "%" << endl;
        cout << left << setw(15) << "Grade:" << grade << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    StudentResult student;
    student.acceptDetails();
    student.calculateResult();
    student.displayResult();
    return 0;
}