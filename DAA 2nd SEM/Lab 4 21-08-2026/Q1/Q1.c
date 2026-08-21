#include <stdio.h>

#define MAX_SIZE 25

#define RED 0
#define BLUE 1
#define YELLOW 2

// Helper function to map integer color codes to text
const char* getColorName(int color) {
    if (color == RED) return "Red";
    if (color == BLUE) return "Blue";
    return "Yellow";
}

void sortByColorStable(int A[][2], int n) {
    // Array-based queues storing [number, color] with capacity up to 25
    int redQ[MAX_SIZE][2], blueQ[MAX_SIZE][2], yellowQ[MAX_SIZE][2];
    
    // Front and Rear pointers for each queue
    int redFront = 0, redRear = 0;
    int blueFront = 0, blueRear = 0;
    int yellowFront = 0, yellowRear = 0;

    // Step 1: Enqueue elements based on color (preserves relative number order)
    for (int i = 0; i < n; i++) {
        int num = A[i][0];
        int color = A[i][1];

        if (color == RED) {
            redQ[redRear][0] = num;
            redQ[redRear][1] = color;
            redRear++;
        } else if (color == BLUE) {
            blueQ[blueRear][0] = num;
            blueQ[blueRear][1] = color;
            blueRear++;
        } else if (color == YELLOW) {
            yellowQ[yellowRear][0] = num;
            yellowQ[yellowRear][1] = color;
            yellowRear++;
        }
    }

    // Step 2: Dequeue REDs, then BLUEs, then YELLOWs back into original array
    int index = 0;

    while (redFront < redRear) {
        A[index][0] = redQ[redFront][0];
        A[index][1] = redQ[redFront][1];
        redFront++;
        index++;
    }

    while (blueFront < blueRear) {
        A[index][0] = blueQ[blueFront][0];
        A[index][1] = blueQ[blueFront][1];
        blueFront++;
        index++;
    }

    while (yellowFront < yellowRear) {
        A[index][0] = yellowQ[yellowFront][0];
        A[index][1] = yellowQ[yellowFront][1];
        yellowFront++;
        index++;
    }
}

int main() {
    // 25 elements sorted by number initially: {number, color_code}
    int A[MAX_SIZE][2] = {
        {2, BLUE},    {5, RED},     {8, YELLOW},  {11, RED},    {14, BLUE},
        {17, YELLOW}, {20, RED},    {23, BLUE},   {26, YELLOW}, {29, RED},
        {32, BLUE},   {35, YELLOW}, {38, RED},    {41, BLUE},   {44, YELLOW},
        {47, RED},    {50, BLUE},   {53, YELLOW}, {56, RED},    {59, BLUE},
        {62, YELLOW}, {65, RED},    {68, BLUE},   {71, YELLOW}, {74, RED}
    };
    
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Array (25 items sorted by number):\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %s)\n", A[i][0], getColorName(A[i][1]));
    }

    sortByColorStable(A, n);

    printf("\nSorted Array (Red < Blue < Yellow, Stable order maintained):\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %s)\n", A[i][0], getColorName(A[i][1]));
    }

    return 0;
}