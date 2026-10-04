#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string studentName;
    string subject;
    double marks;
    double maxMarks;

public:
    // Constructor using explicit assignment
    Exam(string name, string sub, double m, double maxM) {
        studentName = name;
        subject = sub;
        marks = m;
        maxMarks = maxM;
    }

    friend class Result;
};

class Result {
public:
    double calculatePercentage(const Exam &e) {
        return (e.marks / e.maxMarks) * 100.0;
    }

    void displayResult(const Exam &e) {
        double pct = calculatePercentage(e);

        cout << "\n--- Exam Result ---" << endl;
        cout << "Student Name: " << e.studentName << endl;
        cout << "Subject: " << e.subject << endl;
        cout << "Marks: " << e.marks << " / " << e.maxMarks << endl;
        cout << "Percentage: " << pct << "%" << endl;

        if (pct >= 40.0) {
            cout << "Final Result: PASS" << endl;
        } 
        else {
            cout << "Final Result: FAIL" << endl;
        }
    }
};

int main() {
    string name, subject;
    double marks, maxMarks;

    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Marks Obtained: ";
    cin >> marks;
    cout << "Enter Maximum Marks: ";
    cin >> maxMarks;

    Exam exam(name, subject, marks, maxMarks);
    Result res;
    res.displayResult(exam);

    return 0;
}