#include <iostream>
#include <string>
using namespace std;

class FoodOrder {
private:
    int orderID;
    string foodItem;
    int quantity;
    double price;

public:
    // Constructor using explicit assignment
    FoodOrder(int id, string item, int qty, double pr) {
        orderID = id;
        foodItem = item;
        quantity = qty;
        price = pr;
    }

    // Friend function declaration
    friend void calculateBill(const FoodOrder &order);
};

// Friend function definition
void calculateBill(const FoodOrder &order) {
    double totalBill = order.quantity * order.price;

    cout << "\n--- Food Order Details ---" << endl;
    cout << "Order ID: " << order.orderID << endl;
    cout << "Food Item: " << order.foodItem << endl;
    cout << "Quantity: " << order.quantity << endl;
    cout << "Price per item: $" << order.price << endl;
    cout << "Total Bill: $" << totalBill << endl;
}

int main() {
    int id, qty;
    string item;
    double pr;

    cout << "Enter Order ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Food Item: ";
    getline(cin, item);
    cout << "Enter Quantity: ";
    cin >> qty;
    cout << "Enter Price: ";
    cin >> pr;

    FoodOrder order(id, item, qty, pr);
    calculateBill(order);

    return 0;
}