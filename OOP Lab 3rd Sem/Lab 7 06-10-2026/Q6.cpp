#include <iostream>
using namespace std;

// Base Class 1 containing display()
class InternalExam {
protected:
    double internalScore;

public:
    InternalExam(double score = 0.0) {
        internalScore = score;
    }

    void display() {
        cout << "Internal Exam Score: " << internalScore << endl;
    }
};

// Base Class 2 containing another display() function with identical signature
class ExternalExam {
protected:
    double externalScore;

public:
    ExternalExam(double score = 0.0) {
        externalScore = score;
    }

    void display() {
        cout << "External Exam Score: " << externalScore << endl;
    }
};

// Derived class combining both exam results
class FinalResult : public InternalExam, public ExternalExam {
public:
    FinalResult(double inScore = 0.0, double exScore = 0.0) 
        : InternalExam(inScore), ExternalExam(exScore) {}

    void displayAll() {
        cout << "\n--- Final Results ---" << endl;
        
        // Disambiguating display() function calls using Scope Resolution Operator (::)
        InternalExam::display();
        ExternalExam::display();
        
        cout << "Combined Total Score: " << internalScore + externalScore << endl;
    }
};

int main() {
    double inScore, exScore;

    cout << "Enter Internal Exam Score: ";
    cin >> inScore;
    cout << "Enter External Exam Score: ";
    cin >> exScore;

    FinalResult result(inScore, exScore);
    result.displayAll();

    return 0;
}