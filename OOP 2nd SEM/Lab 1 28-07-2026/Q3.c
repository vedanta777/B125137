#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book book;

    // Input collection
    printf("Enter Book ID: ");
    scanf("%d", &book.id);

    printf("Enter Price: ");
    scanf("%f", &book.price);

    // Clearing leftover newline character from the input buffer
    getchar();

    printf("Enter Title: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Strip trailing newline

    printf("Enter Author Name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // Strip trailing newline

    // Output display
    printf("\n--- Book Details ---\n");
    printf("Book ID : %d\n", book.id);
    printf("Title   : %s\n", book.title);
    printf("Author  : %s\n", book.author);
    printf("Price   : $%.2f\n", book.price);

    return 0;
}
