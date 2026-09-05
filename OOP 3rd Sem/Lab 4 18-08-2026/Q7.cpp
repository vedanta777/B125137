#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string name;
    int health;
    int score;
    int level;

public:
    // Constructor using explicit assignment
    Player(string n, int h, int s, int l) {
        name = n;
        health = h;
        score = s;
        level = l;
    }

    friend class GameManager;
};

class GameManager {
public:
    void displayDetails(const Player &p) {
        cout << "\n--- Player Details ---" << endl;
        cout << "Name: " << p.name << endl;
        cout << "Health: " << p.health << endl;
        cout << "Score: " << p.score << endl;
        cout << "Level: " << p.level << endl;
    }

    void checkAlive(const Player &p) {
        if (p.health > 0) {
            cout << "Status: " << p.name << " is ALIVE!" << endl;
        } 
        else {
            cout << "Status: " << p.name << " is DEAD!" << endl;
        }
    }

    void displayLevelAndScore(const Player &p) {
        cout << p.name << "'s Level: " << p.level << " | Score: " << p.score << endl;
    }
};

int main() {
    string name;
    int health, score, level;

    cout << "Enter Player Name: ";
    getline(cin, name);
    cout << "Enter Health: ";
    cin >> health;
    cout << "Enter Score: ";
    cin >> score;
    cout << "Enter Level: ";
    cin >> level;

    Player p(name, health, score, level);
    GameManager gm;

    gm.displayDetails(p);
    gm.checkAlive(p);
    gm.displayLevelAndScore(p);

    return 0;
}