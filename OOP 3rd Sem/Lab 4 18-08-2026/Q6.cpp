#include <iostream>
using namespace std;

class Door; // Forward declaration

class SecuritySystem {
public:
    void checkLockStatus(const Door &d);
};

class Door {
private:
    int doorNumber;
    bool isLocked;

public:
    // Constructor using explicit assignment
    Door(int number, bool locked) {
        doorNumber = number;
        isLocked = locked;
    }

    // Friend Class Declaration
    friend class SecuritySystem;
};

void SecuritySystem::checkLockStatus(const Door &d) {
    cout << "\n--- Security System Check ---" << endl;
    cout << "Door Number: " << d.doorNumber << endl;
    if (d.isLocked) {
        cout << "Status: Locked" << endl;
    } 
    else {
        cout << "Status: Unlocked" << endl;
    }
}

int main() {
    int number;
    char choice;
    bool locked = false;

    cout << "Enter Door Number: ";
    cin >> number;
    cout << "Is the door locked? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        locked = true;
    }

    Door door(number, locked);
    SecuritySystem sec;
    sec.checkLockStatus(door);

    return 0;
}