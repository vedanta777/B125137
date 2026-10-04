#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class LibraryBook {
private:
    int bookID;
    string bookTitle;
    string studentName;
    int daysIssued;

public:
    void enterDetails() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, bookTitle);
        cout << "Enter Student Name: ";
        getline(cin, studentName);
        cout << "Enter Number of Days Issued: ";
        cin >> daysIssued;
    }

    double calculateFine() const {
        if (daysIssued > 15) {
            return (daysIssued - 15) * 2.0;
        }
        return 0.0;
    }

    void displayTransaction() const {
        cout << "\n-----------------------------------" << endl;
        cout << "     LIBRARY TRANSACTION DETAILS   " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(18) << "Book ID:" << bookID << endl;
        cout << left << setw(18) << "Book Title:" << bookTitle << endl;
        cout << left << setw(18) << "Student Name:" << studentName << endl;
        cout << left << setw(18) << "Days Issued:" << daysIssued << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(18) << "Fine Amount:" << calculateFine() << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    LibraryBook book;
    book.enterDetails();
    book.displayTransaction();
    return 0;
}