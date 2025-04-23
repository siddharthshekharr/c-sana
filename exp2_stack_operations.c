#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1;

// Function to check if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Function to add an element to stack
void push()
{
    int item;

    if (isFull())
    {
        printf("\nStack Overflow!\n");
        return;
    }

    printf("\nEnter the element to be pushed: ");
    scanf("%d", &item);

    top++;
    stack[top] = item;
    printf("\n%d pushed to stack successfully!\n", item);
}

// Function to remove an element from stack
void pop()
{
    int item;

    if (isEmpty())
    {
        printf("\nStack Underflow!\n");
        return;
    }

    item = stack[top];
    top--;
    printf("\n%d popped from stack successfully!\n", item);
}

// Function to display elements of stack
void display()
{
    int i;

    if (isEmpty())
    {
        printf("\nStack is empty!\n");
        return;
    }

    printf("\nStack elements are:\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n=== STACK OPERATIONS MENU ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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