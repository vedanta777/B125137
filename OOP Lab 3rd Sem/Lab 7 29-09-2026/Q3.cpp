#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    float totalMarks;

public:
    // Constructor with explicit assignment
    Student(string n = "", float m = 0.0) {
        name = n;
        totalMarks = m;
    }

    void input() {
        string n;
        float m;
        cout << "Enter student name: ";
        cin >> n;
        cout << "Enter total marks: ";
        cin >> m;
        name = n;
        totalMarks = m;
    }

    // Overloading '>' operator
    bool operator>(const Student& s) const {
        return totalMarks > s.totalMarks;
    }

    string getName() const { return name; }
};

int main() {
    Student s1, s2;

    cout << "--- Student 1 ---" << endl;
    s1.input();

    cout << "\n--- Student 2 ---" << endl;
    s2.input();

    cout << endl;
    if (s1 > s2) {
        cout << s1.getName() << " has higher marks than " << s2.getName() << "." << endl;
    } else if (s2 > s1) {
        cout << s2.getName() << " has higher marks than " << s1.getName() << "." << endl;
    } else {
        cout << "Both students have equal marks." << endl;
    }

    return 0;
}