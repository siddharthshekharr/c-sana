#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Global variable - pointer to head
struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning()
{
    int value;
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    printf("\n%d inserted at the beginning successfully!\n", value);
}

// Function to insert a node at the end of the linked list
void insertAtEnd()
{
    int value;
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("\n%d inserted at the end successfully!\n", value);
}

// Function to insert a node at a specific position
void insertAtPosition()
{
    int value, position, i;
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);
    printf("Enter the position (1-based indexing): ");
    scanf("%d", &position);

    if (position <= 0)
    {
        printf("\nInvalid position! Position should be >= 1.\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning();
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nPosition out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("\n%d inserted at position %d successfully!\n", value, position);
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("\nList is empty! Deletion not possible.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    printf("\n%d deleted from the beginning successfully!\n", temp->data);
    free(temp);
}

// Function to delete a node from the end of the linked list
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("\nList is empty! Deletion not possible.\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("\n%d deleted from the end successfully!\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("\n%d deleted from the end successfully!\n", temp->data);
    free(temp);
}

// Function to delete a node from a specific position
void deleteFromPosition()
{
    if (head == NULL)
    {
        printf("\nList is empty! Deletion not possible.\n");
        return;
    }

    int position, i;
    printf("\nEnter the position to delete (1-based indexing): ");
    scanf("%d", &position);

    if (position <= 0)
    {
        printf("\nInvalid position! Position should be >= 1.\n");
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nPosition out of range!\n");
        return;
    }

    prev->next = temp->next;

    printf("\n%d deleted from position %d successfully!\n", temp->data, position);
    free(temp);
}

// Function to display the linked list
void display()
{
    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("\nLinked List elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n=== SINGLY LINKED LIST OPERATIONS MENU ===\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            deleteFromPosition();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("\nExiting program. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}