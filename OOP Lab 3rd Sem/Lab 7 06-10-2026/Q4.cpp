#include <iostream>
using namespace std;

// Base class for bank account data
class BankAccount {
protected:
    long long accountNumber;
    double balance;

public:
    BankAccount(long long accNo = 0, double bal = 0.0) {
        accountNumber = accNo;
        balance = bal;
    }
};

// Derived class 1: Savings Account (Inherits from BankAccount)
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(long long accNo = 0, double bal = 0.0, double rate = 0.0) 
        : BankAccount(accNo, bal) {
        interestRate = rate;
    }

    // Calculates and updates balance by adding interest
    void applyInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "\n--- Savings Account Details ---" << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Interest Added: " << interest << endl;
        cout << "Updated Balance: " << balance << endl;
    }
};

// Derived class 2: Current Account (Inherits from BankAccount)
class CurrentAccount : public BankAccount {
private:
    double minBalance;
    double maintenanceCharge;

public:
    CurrentAccount(long long accNo = 0, double bal = 0.0, double minBal = 0.0, double charge = 0.0) 
        : BankAccount(accNo, bal) {
        minBalance = minBal;
        maintenanceCharge = charge;
    }

    // Deducts charge if minimum balance threshold is not maintained
    void checkMaintenance() {
        cout << "\n--- Current Account Details ---" << endl;
        cout << "Account No: " << accountNumber << endl;
        if (balance < minBalance) {
            balance -= maintenanceCharge;
            cout << "Balance below minimum threshold (" << minBalance << ")." << endl;
            cout << "Maintenance charge of " << maintenanceCharge << " deducted." << endl;
        } else {
            cout << "Balance requirement met. No maintenance charge deducted." << endl;
        }
        cout << "Updated Balance: " << balance << endl;
    }
};

int main() {
    long long accNo;
    double bal, rate, minBal, charge;

    // Execute Savings Account processing
    cout << "--- Setup Savings Account ---" << endl;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> bal;
    cout << "Enter Interest Rate (%): ";
    cin >> rate;
    SavingsAccount sa(accNo, bal, rate);
    sa.applyInterest();

    // Execute Current Account processing
    cout << "\n--- Setup Current Account ---" << endl;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> bal;
    cout << "Enter Minimum Required Balance: ";
    cin >> minBal;
    cout << "Enter Maintenance Charge: ";
    cin >> charge;
    CurrentAccount ca(accNo, bal, minBal, charge);
    ca.checkMaintenance();

    return 0;
}