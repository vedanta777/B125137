#include <stdio.h>

struct Rectangle {
    float length;
    float breadth;
    float area;
    float perimeter;
};

int main() {
    struct Rectangle rect;

    // User Inputs 
    printf("Enter Length: ");
    scanf("%f", &rect.length);

    printf("Enter Breadth: ");
    scanf("%f", &rect.breadth);

    // Calculations
    rect.area = rect.length * rect.breadth;
    rect.perimeter = 2.0 * (rect.length + rect.breadth);
    
    // Output display
    printf("\n--- Rectangle Details ---\n");
    printf("Length    : %.2f\n", rect.length);
    printf("Breadth   : %.2f\n", rect.breadth);
    printf("Area      : %.2f\n", rect.area);
    printf("Perimeter : %.2f\n", rect.perimeter);
    
    return 0;
}
