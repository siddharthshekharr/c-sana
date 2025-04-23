#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for stack
struct Stack
{
    int capacity;
    int top;
    int *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack operations
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// Function declaration to show the movement of disks
void moveDisksBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d);

// Function to implement TOH_Iterative
void tohIterative(int num_of_disks, struct Stack *src, struct Stack *aux, struct Stack *dest)
{
    int i, total_num_of_moves;
    char s = 'S', d = 'D', a = 'A';

    // If number of disks is even, then interchange destination pole and auxiliary pole
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }

    total_num_of_moves = pow(2, num_of_disks) - 1;

    // Larger disks will be pushed first
    for (i = num_of_disks; i >= 1; i--)
        push(src, i);

    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
        {
            moveDisksBetweenTwoPoles(src, dest, s, d);
        }
        else if (i % 3 == 2)
        {
            moveDisksBetweenTwoPoles(src, aux, s, a);
        }
        else if (i % 3 == 0)
        {
            moveDisksBetweenTwoPoles(aux, dest, a, d);
        }
    }
}

// Function to show the movement of disks
void moveDisksBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d)
{
    int pole1TopDisk = peek(src);
    int pole2TopDisk = peek(dest);

    // When pole 1 is empty
    if (pole1TopDisk == -1)
    {
        push(src, pop(dest));
        printf("Move disk %d from %c to %c\n", peek(src), d, s);
    }
    // When pole 2 is empty
    else if (pole2TopDisk == -1)
    {
        push(dest, pop(src));
        printf("Move disk %d from %c to %c\n", peek(dest), s, d);
    }
    // When top disk of pole 1 > top disk of pole 2
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pop(dest));
        printf("Move disk %d from %c to %c\n", peek(src), d, s);
    }
    // When top disk of pole 1 < top disk of pole 2
    else
    {
        push(dest, pop(src));
        printf("Move disk %d from %c to %c\n", peek(dest), s, d);
    }
}

// Recursive function to solve Tower of Hanoi
void tohRecursive(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tohRecursive(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tohRecursive(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nSolving Tower of Hanoi using Recursive approach:\n");
    tohRecursive(n, 'A', 'C', 'B');

    printf("\nSolving Tower of Hanoi using Iterative approach:\n");
    struct Stack *src, *dest, *aux;

    // Create three stacks of size 'n'
    src = createStack(n);
    aux = createStack(n);
    dest = createStack(n);

    tohIterative(n, src, aux, dest);

    return 0;
}