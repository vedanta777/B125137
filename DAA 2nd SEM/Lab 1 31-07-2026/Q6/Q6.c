#include <stdio.h>

int main()
{
    int arr[] = {5, 7, 3, 2, 9, 7, 5, 8, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int printed[n];

    for (int i = 0; i < n; i++)
        printed[i] = 0;

    printf("Elements with duplicates:\n");

    for (int i = 0; i < n; i++)
    {
        if (printed[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                printed[j] = 1;
            }
        }

        if (count > 1)
            printf("%d (appears %d times)\n", arr[i], count);
    }

    for (int i = 0; i < n; i++)
        printed[i] = 0;

    printf("\nElements without duplicates:\n");

    for (int i = 0; i < n; i++)
    {
        if (printed[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                printed[j] = 1;
            }
        }

        if (count == 1)
            printf("%d\n", arr[i]);
    }

    return 0;
}

/*
-> the algorithm compares all elements ahead of the current element and checks for any matches
-> for every match, the value of the element at the index number corresponding to index number of second occurence of the number, is increased by 1
-> at the end, if repetition [i] = 0 for arr[i] then arr[i] has no duplicates.
*/