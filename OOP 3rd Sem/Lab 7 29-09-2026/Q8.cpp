#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor with explicit assignment
    Item(string n = "", double p = 0.0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    void input() {
        string n;
        double p;
        int q;
        cout << "Enter item name: ";
        cin >> n;
        cout << "Enter price: ";
        cin >> p;
        cout << "Enter quantity: ";
        cin >> q;
        name = n;
        price = p;
        quantity = q;
    }

    // Overloading '+' operator returning explicit new object
    Item operator+(const Item& other) const {
        if (name == other.name && price == other.price) {
            return Item(name, price, quantity + other.quantity);
        } 
        else {
            cout << "\n[Error] Cannot combine items: Name or price mismatch!" << endl;
            return Item("", 0.0, -1);
        }
    }

    void display() const {
        if (quantity != -1) {
            cout << "Item: " << name << " | Price: $" << price << " | Quantity: " << quantity << endl;
        }
    }
};

int main() {
    Item item1, item2;

    cout << "--- Enter Item 1 Details ---" << endl;
    item1.input();

    cout << "\n--- Enter Item 2 Details ---" << endl;
    item2.input();

    Item combined = item1 + item2;

    cout << "\nCombined Inventory Result:" << endl;
    combined.display();

    return 0;
}