#include <iostream>
#include <string>
using namespace std;

// Base class utilizing protected scope for fields
class Patient {
protected: // Protected members are accessible within derived classes
    string patientName;
    int patientID;
    int age;

public:
    Patient(string name = "", int id = 0, int a = 0) {
        patientName = name;
        patientID = id;
        age = a;
    }
};

// Derived class accessing protected properties directly
class InPatient : public Patient {
private:
    double roomCharges;
    int numberOfDays;

public:
    InPatient(string name = "", int id = 0, int a = 0, double charges = 0.0, int days = 0) 
        : Patient(name, id, a) {
        roomCharges = charges;
        numberOfDays = days;
    }

    void displayBill() {
        double totalBill = roomCharges * numberOfDays;

        cout << "\n--- Hospital Bill Summary ---" << endl;
        // Accessing inherited protected fields directly
        cout << "Patient Name: " << patientName << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Patient Age: " << age << endl;
        cout << "Room Charges Per Day: " << roomCharges << endl;
        cout << "Number of Days: " << numberOfDays << endl;
        cout << "Total Bill: " << totalBill << endl;
    }
};

int main() {
    string name;
    int id, age, days;
    double charges;

    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Patient Age: ";
    cin >> age;
    cout << "Enter Room Charges Per Day: ";
    cin >> charges;
    cout << "Enter Number of Days Admitted: ";
    cin >> days;

    InPatient patient(name, id, age, charges, days);
    patient.displayBill();

    return 0;
}