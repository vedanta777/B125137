#include <iostream>
using namespace std;

// Base Class 1: Stores marks for academic subjects
class Academic {
protected:
    double sub1, sub2, sub3;

public:
    Academic(double m1 = 0.0, double m2 = 0.0, double m3 = 0.0) {
        sub1 = m1;
        sub2 = m2;
        sub3 = m3;
    }
};

// Base Class 2: Stores sports activity marks
class Sports {
protected:
    double sportsMarks;

public:
    Sports(double sm = 0.0) {
        sportsMarks = sm;
    }
};

// Derived Class inheriting from BOTH Academic and Sports (Multiple Inheritance)
class StudentResult : public Academic, public Sports {
public:
    StudentResult(double m1 = 0.0, double m2 = 0.0, double m3 = 0.0, double sm = 0.0) 
        : Academic(m1, m2, m3), Sports(sm) {}

    // Computes overall score across 4 evaluations
    void displayResult() {
        double total = sub1 + sub2 + sub3 + sportsMarks;
        double average = total / 4.0; // Total divided by 4 subjects/scores

        cout << "\n--- Performance Breakdown ---" << endl;
        cout << "Academic Subject 1: " << sub1 << endl;
        cout << "Academic Subject 2: " << sub2 << endl;
        cout << "Academic Subject 3: " << sub3 << endl;
        cout << "Sports Marks: " << sportsMarks << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    double m1, m2, m3, sm;

    // Collect marks from user
    cout << "Enter Marks for Subject 1: ";
    cin >> m1;
    cout << "Enter Marks for Subject 2: ";
    cin >> m2;
    cout << "Enter Marks for Subject 3: ";
    cin >> m3;
    cout << "Enter Sports Marks: ";
    cin >> sm;

    StudentResult res(m1, m2, m3, sm);
    res.displayResult();

    return 0;
}