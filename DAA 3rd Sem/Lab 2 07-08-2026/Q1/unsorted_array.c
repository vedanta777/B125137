#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int size = 0;

int search(int key)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
            return i;
    }

    return -1;
}

void insert(int key)
{
    if(size == MAX)
    {
        printf("Dictionary is full!\n");
        return;
    }

    arr[size] = key;
    size++;
}

void delete(int key)
{
    int index = search(key);

    if(index == -1)
    {
        printf("Element not found.\n");
        return;
    }

    arr[index] = arr[size - 1];
    size--;
    printf("Element %d deleted successfully.\n", key);
}

int minimum()
{
    if(size == 0)
        return -1;

    int min = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    return min;
}

int maximum()
{
    if(size == 0)
        return -1;

    int max = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

int predecessor(int key)
{
    int pred = -1;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] < key)
        {
            if(pred == -1 || arr[i] > pred)
                pred = arr[i];
        }
    }

    return pred;
}

int successor(int key)
{
    int succ = -1;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] > key)
        {
            if(succ == -1 || arr[i] < succ)
                succ = arr[i];
        }
    }

    return succ;
}

void display()
{
    printf("\nDictionary: ");

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    // Initial element entry part
    insert(45);
    insert(12);
    insert(78);
    insert(23);
    insert(56);
    insert(91);
    insert(34);
    insert(67);
    insert(18);
    insert(82);
    insert(5);
    insert(39);
    insert(73);
    insert(27);
    insert(61);
    insert(49);
    insert(95);
    insert(14);
    insert(88);
    insert(31);
    insert(52);
    insert(9);
    insert(70);
    insert(41);
    insert(64);

    int choice, val, idx, res;

    while(1)
    {
        printf("\n--- MENU ---");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Minimum");
        printf("\n5. Maximum");
        printf("\n6. Predecessor");
        printf("\n7. Successor");
        printf("\n8. Display");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                printf("Inserted %d.\n", val);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                idx = search(val);
                if(idx != -1)
                    printf("%d found at index %d\n", val, idx);
                else
                    printf("%d not found\n", val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(val);
                break;

            case 4:
                res = minimum();
                if(res != -1)
                    printf("Minimum : %d\n", res);
                else
                    printf("Array is empty.\n");
                break;

            case 5:
                res = maximum();
                if(res != -1)
                    printf("Maximum : %d\n", res);
                else
                    printf("Array is empty.\n");
                break;

            case 6:
                printf("Enter value to find predecessor: ");
                scanf("%d", &val);
                res = predecessor(val);
                if(res != -1)
                    printf("Predecessor of %d : %d\n", val, res);
                else
                    printf("No predecessor found for %d.\n", val);
                break;

            case 7:
                printf("Enter value to find successor: ");
                scanf("%d", &val);
                res = successor(val);
                if(res != -1)
                    printf("Successor of %d : %d\n", val, res);
                else
                    printf("No successor found for %d.\n", val);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}