#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    long accountNumber;
    string accountHolderName;
    double balance;

public:
    void enterDetails() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolderName);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "\n[Error] Insufficient Balance! Withdrawal Failed." << endl;
        } else if (amount <= 0) {
            cout << "\n[Error] Invalid withdrawal amount!" << endl;
        } else {
            balance -= amount;
            cout << "\nSuccessfully withdrew" << fixed << setprecision(2) << amount << endl;
        }
    }

    void displayDetails() const {
        cout << "\n-----------------------------------" << endl;
        cout << "        ACCOUNT DETAILS            " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(20) << "Account Number:" << accountNumber << endl;
        cout << left << setw(20) << "Account Holder:" << accountHolderName << endl;
        cout << left << setw(20) << "Current Balance:" << fixed << setprecision(2) << balance << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    BankAccount account;
    account.enterDetails();

    double depositAmt, withdrawAmt;
    cout << "\nEnter amount to deposit: ";
    cin >> depositAmt;
    account.deposit(depositAmt);

    cout << "\nEnter amount to withdraw: ";
    cin >> withdrawAmt;
    account.withdraw(withdrawAmt);

    account.displayDetails();
    return 0;
}