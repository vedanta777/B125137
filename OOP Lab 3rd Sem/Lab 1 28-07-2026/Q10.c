#include <stdio.h>
#include <string.h>

// Child structure
struct Date {
    int day;
    int month;
    int year;
};

// Parent structure (contains Date as a nested struct)
struct Student {
    int roll_no;
    char name[50];
    struct Date dob; // Named member variable
};

int main() {
    struct Student student;

    // 1. Basic Student Info
    printf("Enter Roll Number: ");
    scanf("%d", &student.roll_no);

    // Clearing leftover newline from input buffer before reading string
    getchar();

    printf("Enter Full Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove trailing newline

    // 2. Nested Structure Info (Accessed using double-dot notation: student.dob.day)
    printf("\n--- Enter Date of Birth ---\n");
    printf("Day (1-31)  : ");
    scanf("%d", &student.dob.day);

    printf("Month (1-12): ");
    scanf("%d", &student.dob.month);

    printf("Year (YYYY) : ");
    scanf("%d", &student.dob.year);

    // 3. Displaying Details
    printf("\n=== Student Details ===\n");
    printf("Roll Number   : %d\n", student.roll_no);
    printf("Name          : %s\n", student.name);

    // %02d pads single-digit days/months with a leading zero (e.g., 05/08/2004)
    printf("Date of Birth : %02d/%02d/%04d\n", 
           student.dob.day, 
           student.dob.month, 
           student.dob.year);

    return 0;
}