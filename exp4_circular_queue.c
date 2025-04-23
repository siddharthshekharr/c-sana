#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

// Function to insert an element into circular queue
void insert()
{
    int item;

    if (isFull())
    {
        printf("\nCircular Queue Overflow!\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &item);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
    }

    cqueue[rear] = item;
    printf("\n%d inserted into the circular queue successfully!\n", item);
}

// Function to delete an element from circular queue
void delete()
{
    int item;

    if (isEmpty())
    {
        printf("\nCircular Queue Underflow!\n");
        return;
    }

    item = cqueue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    printf("\n%d deleted from the circular queue successfully!\n", item);
}

// Function to display the elements of circular queue
void display()
{
    int i;

    if (isEmpty())
    {
        printf("\nCircular Queue is empty!\n");
        return;
    }

    printf("\nCircular Queue elements:\n");

    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    else
    {
        for (i = front; i < MAX; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n=== CIRCULAR QUEUE OPERATIONS MENU ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting program. Goodbye!\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}