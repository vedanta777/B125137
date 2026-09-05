#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    float price;
    int quantity;

public:
    // Accept product details from user
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, productName);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // Output product details and total price for this item
    void displayDetails() const {
        cout << "ID: " << productId << " | Name: " << productName
             << " | Price: $" << price << " | Qty: " << quantity
             << " | Subtotal: $" << getSubtotal() << endl;
    }

    // Calculate item cost (Price * Quantity)
    float getSubtotal() const {
        return price * quantity;
    }
};

int main() {
    int n;
    cout << "Enter number of products in shopping cart: ";
    cin >> n;

    // Dynamically allocate array of Product objects on heap based on user input 'n'
    Product* cart = new Product[n];

    // Input details for each product in cart
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Product " << (i + 1) << ":" << endl;
        cart[i].acceptDetails();
    }

    // Compute cart total
    float totalCartCost = 0.0f;
    cout << "\n--- Shopping Cart Summary ---" << endl;
    for (int i = 0; i < n; i++) {
        cart[i].displayDetails();
        totalCartCost += cart[i].getSubtotal();
    }

    cout << "--------------------------------" << endl;
    cout << "Total Shopping Cart Amount: $" << totalCartCost << endl;

    // Release allocated memory array
    delete[] cart;
    cart = nullptr;

    return 0;
}