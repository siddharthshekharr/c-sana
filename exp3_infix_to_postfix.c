#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char item)
{
    if (top >= MAX - 1)
    {
        printf("\nStack Overflow.");
        return;
    }
    stack[++top] = item;
}

// Function to pop an element from the stack
char pop()
{
    if (top < 0)
    {
        printf("\nStack Underflow.");
        exit(1);
    }
    return stack[top--];
}

// Function to return the top element of the stack without popping it
char peek()
{
    if (top < 0)
    {
        return -1;
    }
    return stack[top];
}

// Function to check if the given character is an operand
int isOperand(char ch)
{
    return isalnum(ch);
}

// Function to determine the precedence of an operator
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix)
{
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        // If the scanned character is an operand, add it to the postfix expression
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        // If the scanned character is '(', push it onto the stack
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        // If the scanned character is ')', pop and add to the postfix expression until '(' is encountered
        else if (infix[i] == ')')
        {
            while (top > -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (top > -1 && peek() != '(')
            {
                printf("Invalid expression");
                exit(1);
            }
            else
            {
                pop(); // Pop '('
            }
        }
        // If the scanned character is an operator
        else
        {
            while (top > -1 && precedence(infix[i]) <= precedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (top > -1)
    {
        if (peek() == '(')
        {
            printf("Invalid expression");
            exit(1);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main function
int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}