#include <iostream>
using namespace std;

// Base class Character
class Character {
protected:
    int statVal;
public:
    // Constructor explicitly assigning initial value
    Character(int val) {
        statVal = val;
    }
    
    // Virtual attack function to be overridden
    virtual void attack() {
        cout << "Base character attack." << endl;
    }
};

// Derived class Warrior
class Warrior : public Character {
public:
    Warrior(int strength) : Character(strength) {}

    // Overriding attack() for Warrior (Damage = 20 + 2 * strength)
    void attack() override {
        int damage = 20 + (2 * statVal);
        cout << "Warrior attacks with strength " << statVal 
             << " and deals " << damage << " damage." << endl;
    }
};

// Derived class Archer
class Archer : public Character {
public:
    Archer(int agility) : Character(agility) {}

    // Overriding attack() for Archer (Damage = 15 + 3 * agility)
    void attack() override {
        int damage = 15 + (3 * statVal);
        cout << "Archer attacks with agility " << statVal 
             << " and deals " << damage << " damage." << endl;
    }
};

int main() {
    int str, agi;
    cout << "Enter Warrior's strength: ";
    cin >> str;
    cout << "Enter Archer's agility: ";
    cin >> agi;

    Warrior w(str);
    Archer a(agi);

    cout << "\n--- Battle Results ---" << endl;
    w.attack();
    a.attack();

    return 0;
}