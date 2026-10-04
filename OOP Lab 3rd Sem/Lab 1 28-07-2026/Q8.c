#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to find the index of the employee with the highest salary
int find_highest_paid_index(struct Employee employees[], int total_employees) {
    int max_index = 0;
    float max_salary = employees[0].salary; // Initialize with the first employee's salary

    for (int i = 1; i < total_employees; i++) {
        if (employees[i].salary > max_salary) {
            max_salary = employees[i].salary;
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    int count;

    printf("Enter number of employees: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    struct Employee employees[count];

    // User Inputs
    for (int i = 0; i < count; i++) {
        printf("\n--- Enter Details for Employee #%d ---\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &employees[i].id);

        printf("Salary     : ");
        scanf("%f", &employees[i].salary);

        // Clearing leftover newline character from buffer
        getchar();

        printf("Name       : ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline
    }

    // Finding and displaying highest paid employee
    int highest_index = find_highest_paid_index(employees, count);

    printf("\n=== Highest Paid Employee ===\n");
    printf("ID     : %d\n", employees[highest_index].id);
    printf("Name   : %s\n", employees[highest_index].name);
    printf("Salary : $%.2f\n", employees[highest_index].salary);

    return 0;
}