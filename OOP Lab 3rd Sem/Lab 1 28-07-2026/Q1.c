#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    int age;
    float cgpa;
};

int main() {
    struct Student student;

    // User Inputs

    printf("Enter roll number: ");
    scanf("%d", &student.roll_no);

    printf("Enter age: ");
    scanf("%d", &student.age);

    printf("Enter CGPA: ");
    scanf("%f", &student.cgpa);

    // Clearing the leftover newline character in input buffer before reading string
    getchar();

    printf("Enter full name: ");
    fgets(student.name, sizeof(student.name), stdin);

    // Removing trailing newline added by fgets if present
    student.name[strcspn(student.name, "\n")] = '\0';

    // Output display
    printf("\n--- Student Details ---\n");
    printf("Roll Number : %d\n", student.roll_no);
    printf("Name        : %s\n", student.name);
    printf("Age         : %d\n", student.age);
    printf("CGPA        : %.2f\n", student.cgpa);

    return 0;
}