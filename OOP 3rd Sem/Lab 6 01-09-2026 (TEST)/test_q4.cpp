#include <iostream>
using namespace std;

int main() {
    const int SIZE = 8;
    int seats[SIZE];

    cout << "Enter " << SIZE << " cinema seat numbers:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Seat [" << i << "]: ";
        cin >> seats[i];
    }

    cout << "\nSeats BEFORE update: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(seats + i) << " ";
    }
    cout << endl;

    int pos, newSeatNum;
    cout << "\nEnter index position (0 to " << SIZE - 1 << ") to update: ";
    cin >> pos;

    if (pos >= 0 && pos < SIZE) {
        cout << "Enter new seat number: ";
        cin >> newSeatNum;

        *(seats + pos) = newSeatNum; 

        cout << "\nSeats AFTER update: ";
        for (int i = 0; i < SIZE; i++) {
            cout << *(seats + i) << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid position entered!" << endl;
    }

    return 0;
}