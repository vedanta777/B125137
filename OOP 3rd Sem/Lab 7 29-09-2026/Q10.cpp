#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor with explicit assignment
    Product(string n = "", double p = 0.0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    void input() {
        string n;
        double p;
        int q;
        cout << "Enter product name: ";
        cin >> n;
        cout << "Enter price: ";
        cin >> p;
        cout << "Enter quantity: ";
        cin >> q;
        name = n;
        price = p;
        quantity = q;
    }

    double getTotalValue() const {
        return price * quantity;
    }

    // Overloading '+' operator returning explicit new Product object
    Product operator+(const Product& p) const {
        if (name == p.name && price == p.price) {
            return Product(name, price, quantity + p.quantity);
        } 
        else {
            cout << "\n[Notice] Products cannot be merged (different name or price)." << endl;
            return *this;
        }
    }

    // Overloading '>' operator
    bool operator>(const Product& p) const {
        return this->getTotalValue() > p.getTotalValue();
    }

    void display() const {
        cout << "Product: " << name << " | Price: $" << price 
             << " | Quantity: " << quantity 
             << " | Total Value: $" << getTotalValue() << endl;
    }
};

int main() {
    Product p1, p2;

    cout << "--- Enter Product 1 Details ---" << endl;
    p1.input();

    cout << "\n--- Enter Product 2 Details ---" << endl;
    p2.input();

    cout << "\n=== Product Overloaded '+' Operation ===" << endl;
    Product combined = p1 + p2;
    cout << "Combined Product Details:" << endl;
    combined.display();

    cout << "\n=== Product Overloaded '>' Comparison ===" << endl;
    if (p1 > p2) {
        cout << "Product 1 has a HIGHER total value than Product 2." << endl;
    } 
    else if (p2 > p1) {
        cout << "Product 2 has a HIGHER total value than Product 1." << endl;
    } 
    else {
        cout << "Both products have the SAME total value." << endl;
    }

    return 0;
}