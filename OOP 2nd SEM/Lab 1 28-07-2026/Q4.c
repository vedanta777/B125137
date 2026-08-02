#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
    float total_cost;
};

int main() {
    struct Product product;

    // Input collection
    printf("Enter Product ID: ");
    scanf("%d", &product.id);

    printf("Enter Price: ");
    scanf("%f", &product.price);

    printf("Enter Quantity: ");
    scanf("%d", &product.quantity);

    // Clearing leftover newline character from the input buffer
    getchar();

    printf("Enter Product Name: ");
    fgets(product.name, sizeof(product.name), stdin);
    product.name[strcspn(product.name, "\n")] = '\0'; // Remove trailing newline

    // Calculation of total cost
    product.total_cost = product.price * product.quantity;

    // Output display
    printf("\n--- Product Summary ---\n");
    printf("Product ID : %d\n", product.id);
    printf("Name       : %s\n", product.name);
    printf("Unit Price : $%.2f\n", product.price);
    printf("Quantity   : %d\n", product.quantity);
    printf("Total Cost : $%.2f\n", product.total_cost);

    return 0;
}