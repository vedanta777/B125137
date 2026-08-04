#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product {
private:
    int productID;
    string productName;
    int quantityAvailable;
    double pricePerUnit;

public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productID;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, productName);
        cout << "Enter Quantity Available: ";
        cin >> quantityAvailable;
        cout << "Enter Price per Unit: ";
        cin >> pricePerUnit;
    }

    void sellProduct(int unitsSold) {
        if (unitsSold > quantityAvailable) {
            cout << "\n[Error] Sale Failed! Not enough stock available." << endl;
        } else if (unitsSold <= 0) {
            cout << "\n[Error] Invalid quantity." << endl;
        } else {
            quantityAvailable -= unitsSold;
            cout << "\nSuccessfully sold " << unitsSold << " unit(s)." << endl;
        }
    }

    double calculateInventoryValue() const {
        return quantityAvailable * pricePerUnit;
    }

    void displayDetails() const {
        cout << "\n-----------------------------------" << endl;
        cout << "       PRODUCT INVENTORY           " << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(20) << "Product ID:" << productID << endl;
        cout << left << setw(20) << "Product Name:" << productName << endl;
        cout << left << setw(20) << "Stock Available:" << quantityAvailable << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(20) << "Price per Unit:" << pricePerUnit << endl;
        cout << left << setw(20) << "Total Stock Value:" << calculateInventoryValue() << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    Product prod;
    prod.acceptDetails();
    prod.displayDetails();

    int sellQty;
    cout << "\nEnter units to sell: ";
    cin >> sellQty;
    prod.sellProduct(sellQty);

    prod.displayDetails();
    return 0;
}