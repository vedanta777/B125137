#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    int c_marks;
    int math_marks;
    int physics_marks;
    int total_marks;
    float average;
};

int main() {
    struct Student student;

    // User Inputs
    printf("Enter Roll Number: ");
    scanf("%d", &student.roll_no);

    // Clearing leftover newline character from input buffer
    getchar();

    printf("Enter Full Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter C Programming Marks: ");
    scanf("%d", &student.c_marks);

    printf("Enter Math Marks: ");
    scanf("%d", &student.math_marks);

    printf("Enter Physics Marks: ");
    scanf("%d", &student.physics_marks);

    // Calculations
    student.total_marks = student.c_marks + student.math_marks + student.physics_marks;
    student.average = student.total_marks / 3.0f; // Cast to float for accurate decimal

    // Output display
    printf("\n--- Student Marksheet ---\n");
    printf("Roll Number : %d\n", student.roll_no);
    printf("Name        : %s\n", student.name);
    printf("C Marks     : %d\n", student.c_marks);
    printf("Math Marks  : %d\n", student.math_marks);
    printf("Physics     : %d\n", student.physics_marks);
    printf("Total Marks : %d / 300\n", student.total_marks);
    printf("Average     : %.2f%%\n", student.average);

    return 0;
}

 

