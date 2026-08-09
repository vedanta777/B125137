#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    if(key < head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL && temp->next->data < key)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

struct Node *search(int key)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void delete(int key)
{
    struct Node *temp = search(key);

    if(temp == NULL)
    {
        printf("Element not found.\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Element %d deleted successfully.\n", key);
}

int minimum()
{
    if(head == NULL)
        return -1;

    return head->data;
}

int maximum()
{
    if(head == NULL)
        return -1;

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    return temp->data;
}

int predecessor(int key)
{
    struct Node *temp = search(key);

    if(temp == NULL || temp->prev == NULL)
        return -1;

    return temp->prev->data;
}

int successor(int key)
{
    struct Node *temp = search(key);

    if(temp == NULL || temp->next == NULL)
        return -1;

    return temp->next->data;
}

void display()
{
    struct Node *temp = head;

    printf("\nDictionary: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

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

    int choice, val, res;

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
                if(search(val) != NULL)
                    printf("%d found in the list.\n", val);
                else
                    printf("%d not found.\n", val);
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
                    printf("List is empty.\n");
                break;

            case 5:
                res = maximum();
                if(res != -1)
                    printf("Maximum : %d\n", res);
                else
                    printf("List is empty.\n");
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