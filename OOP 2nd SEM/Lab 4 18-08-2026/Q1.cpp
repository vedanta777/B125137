#include <iostream>
#include <string>
using namespace std;

class Diary {
private:
    string ownerName;
    int numEntries;
    string lastEntry;

public:
    // Constructor using explicit assignment
    Diary(string owner, int entries, string entry) {
        ownerName = owner;
        numEntries = entries;
        lastEntry = entry;
    }

    // Friend function declaration
    friend void displayDiary(const Diary &d);
};

// Friend function definition
void displayDiary(const Diary &d) {
    cout << "\n--- Personal Diary Details ---" << endl;
    cout << "Owner Name: " << d.ownerName << endl;
    cout << "Number of Entries: " << d.numEntries << endl;
    cout << "Last Entry: " << d.lastEntry << endl;
}

int main() {
    string owner, entry;
    int entries;

    cout << "Enter Owner Name: ";
    getline(cin, owner);
    cout << "Enter Number of Entries: ";
    cin >> entries;
    cin.ignore(); // Clear newline character from buffer
    cout << "Enter Last Entry: ";
    getline(cin, entry);

    Diary myDiary(owner, entries, entry);
    displayDiary(myDiary);

    return 0;
}