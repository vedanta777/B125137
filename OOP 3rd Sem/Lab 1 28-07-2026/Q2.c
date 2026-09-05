#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp;

    // User Inputs
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Clearing leftover newline character from the input buffer
    getchar();

    printf("Enter Full Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    // Remove trailing newline character added by fgets
    emp.name[strcspn(emp.name, "\n")] = '\0';

    // Output display
    printf("\n--- Employee Details ---\n");
    printf("ID     : %d\n", emp.id);
    printf("Name   : %s\n", emp.name);
    printf("Salary : $%.2f\n", emp.salary);

    return 0;
}