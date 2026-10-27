#include <iostream>
#include <cmath>
using namespace std;

// Base class MatchFormat
class MatchFormat {
protected:
    int firstInningsScore;
public:
    MatchFormat(int score) {
        firstInningsScore = score;
    }
    
    virtual void calculateTarget() {
        cout << "Base target calculation." << endl;
    }
};

// Derived class T20Match
class T20Match : public MatchFormat {
public:
    T20Match(int score) : MatchFormat(score) {}

    // T20 adds 1% run margin, rounded up
    void calculateTarget() override {
        double margin = firstInningsScore * 0.01;
        int target = firstInningsScore + ceil(margin);
        cout << "T20 Match Target: " << target << " (First innings: " << firstInningsScore << ")" << endl;
    }
};

// Derived class ODIMatch
class ODIMatch : public MatchFormat {
public:
    ODIMatch(int score) : MatchFormat(score) {}

    // ODI adds 2% run margin, rounded up
    void calculateTarget() override {
        double margin = firstInningsScore * 0.02;
        int target = firstInningsScore + ceil(margin);
        cout << "ODI Match Target: " << target << " (First innings: " << firstInningsScore << ")" << endl;
    }
};

int main() {
    int score;
    cout << "Enter first-innings score: ";
    cin >> score;

    T20Match t20(score);
    ODIMatch odi(score);

    cout << "\n--- Cricket Targets ---" << endl;
    t20.calculateTarget();
    odi.calculateTarget();

    return 0;
}