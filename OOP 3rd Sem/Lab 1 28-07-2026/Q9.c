#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float cgpa;
};

// Function to print details of students with CGPA greater than 8.0
void print_top_students(struct Student students[], int count) {
    int found = 0;

    printf("\n=== Students with CGPA > 8.0 ===\n");
    for (int i = 0; i < count; i++) {
        if (students[i].cgpa > 8.0f) {
            printf("\nRoll Number : %d\n", students[i].roll_no);
            printf("Name        : %s\n", students[i].name);
            printf("CGPA        : %.2f\n", students[i].cgpa);
            printf("---------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No students found with a CGPA greater than 8.0.\n");
    }
}

int main() {
    int count;

    printf("Enter number of students: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Student students[count];

    // User Inputs
    for (int i = 0; i < count; i++) {
        printf("\n--- Enter Details for Student #%d ---\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_no);

        printf("Enter CGPA: ");
        scanf("%f", &students[i].cgpa);

        // Clearing leftover newline character from buffer
        getchar();

        printf("Enter Full Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove trailing newline
    }

    // Displaying high-achieving students
    print_top_students(students, count);

    return 0;
}