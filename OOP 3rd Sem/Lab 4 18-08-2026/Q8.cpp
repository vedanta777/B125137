#include <iostream>
#include <string>
using namespace std;

class TrainSeat {
private:
    int seatNumber;
    string passengerName;
    bool isBooked;

public:
    // Constructor using explicit assignment
    TrainSeat(int seat, string passenger, bool status) {
        seatNumber = seat;
        passengerName = passenger;
        isBooked = status;
    }

    friend class TicketChecker;
};

class TicketChecker {
public:
    void displaySeatDetails(const TrainSeat &seat) {
        cout << "\n--- Seat Information ---" << endl;
        cout << "Seat Number: " << seat.seatNumber << endl;
    }

    void checkBookingStatus(const TrainSeat &seat) {
        if (seat.isBooked) {
            cout << "Status: Booked" << endl;
        } else {
            cout << "Status: Available" << endl;
        }
    }

    void displayPassengerName(const TrainSeat &seat) {
        if (seat.isBooked) {
            cout << "Passenger Name: " << seat.passengerName << endl;
        } else {
            cout << "No passenger assigned to this seat." << endl;
        }
    }
};

int main() {
    int seat;
    string passenger = "N/A";
    char choice;
    bool status = false;

    cout << "Enter Seat Number: ";
    cin >> seat;
    cout << "Is the seat booked? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        status = true;
        cin.ignore();
        cout << "Enter Passenger Name: ";
        getline(cin, passenger);
    }

    TrainSeat tSeat(seat, passenger, status);
    TicketChecker tc;

    tc.displaySeatDetails(tSeat);
    tc.checkBookingStatus(tSeat);
    tc.displayPassengerName(tSeat);

    return 0;
}