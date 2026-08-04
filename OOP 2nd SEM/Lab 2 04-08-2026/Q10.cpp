#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ElectricityBill {
private:
    int consumerNumber;
    string consumerName;
    double unitsConsumed;

public:
    void acceptDetails() {
        cout << "Enter Consumer Number: ";
        cin >> consumerNumber;
        cin.ignore();
        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);
        cout << "Enter Units Consumed: ";
        cin >> unitsConsumed;
    }

    double calculateBill() const {
        double billAmount = 0.0;
        double units = unitsConsumed;

        if (units <= 100) {
            billAmount = units * 5.0;
        } else if (units <= 200) {
            billAmount = (100 * 5.0) + ((units - 100) * 7.0);
        } else {
            billAmount = (100 * 5.0) + (100 * 7.0) + ((units - 200) * 10.0);
        }

        return billAmount;
    }

    void displayBill() const {
        cout << "\n-----------------------------------" << endl;
        cout << "      ELECTRICITY BILL RECEIPT     " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(18) << "Consumer No:" << consumerNumber << endl;
        cout << left << setw(18) << "Consumer Name:" << consumerName << endl;
        cout << left << setw(18) << "Units Consumed:" << unitsConsumed << endl;
        cout << "-----------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(18) << "Total Amount:" << calculateBill() << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    ElectricityBill bill;
    bill.acceptDetails();
    bill.displayBill();
    return 0;
}