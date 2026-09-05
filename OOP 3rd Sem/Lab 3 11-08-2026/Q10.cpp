#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float basicSalary;
    int numMonths;
    float* monthlyEarnings; // Dynamic array pointer for month-by-month variable earnings

public:
    // Default Constructor initializing pointer to nullptr
    Employee() : monthlyEarnings(nullptr), numMonths(0) {}

    // Input employee data and allocate earnings array dynamically
    void acceptDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Basic Monthly Salary: ";
        cin >> basicSalary;
        cout << "Enter Number of Months: ";
        cin >> numMonths;

        // Dynamically allocate dynamic memory array for monthly extra earnings
        monthlyEarnings = new float[numMonths];

        cout << "Enter additional earnings for each month:" << endl;
        for (int i = 0; i < numMonths; i++) {
            cout << "Month " << (i + 1) << ": ";
            cin >> monthlyEarnings[i];
        }
    }

    // Calculate sum of base salary and variable earnings across all months
    float calculateTotalEarnings() const {
        float total = basicSalary * numMonths;
        for (int i = 0; i < numMonths; i++) {
            total += monthlyEarnings[i];
        }
        return total;
    }

    // Compute average monthly earnings
    float calculateAverageMonthlyEarning() const {
        if (numMonths == 0) return 0;
        return calculateTotalEarnings() / numMonths;
    }

    // Find 1-based month index with peak additional earnings
    int getHighestEarningMonth() const {
        if (numMonths == 0) return 0;
        int maxIndex = 0;
        for (int i = 1; i < numMonths; i++) {
            if (monthlyEarnings[i] > monthlyEarnings[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex + 1; // Return 1-based index for user readability
    }

    // Display comprehensive report
    void displayAnalysis() const {
        cout << "\n--- Employee Salary Analysis ---" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary / Month: " << basicSalary << endl;
        cout << "Total Earnings (" << numMonths << " months): " << calculateTotalEarnings() << endl;
        cout << "Average Monthly Earning: " << calculateAverageMonthlyEarning() << endl;

        int highestMonth = getHighestEarningMonth();
        if (highestMonth > 0) {
            float monthTotal = basicSalary + monthlyEarnings[highestMonth - 1];
            cout << "Month with Highest Earning: Month " << highestMonth
                 << " (Total: " << monthTotal << ")" << endl;
        }
    }

    // Destructor releases dynamic member array when employee object is destroyed
    ~Employee() {
        delete[] monthlyEarnings;
        monthlyEarnings = nullptr;
    }
};

int main() {
    Employee emp;
    emp.acceptDetails();
    emp.displayAnalysis();

    // Destructor handles monthlyEarnings cleanup automatically when 'emp' leaves scope
    return 0;
}