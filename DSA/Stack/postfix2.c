#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char arr[MAX_SIZE];
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isStackFull(stack)) {
        printf("Stack overflow. Cannot push %c.\n", value);
        return;
    }

    stack->arr[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return '\0';
    }

    return stack->arr[stack->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infixExpression, char *postfixExpression) {
    Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (infixExpression[i] != '\0') {
        char currentChar = infixExpression[i];

        if (isalnum(currentChar)) {
            // If operand, add to the postfix expression
            postfixExpression[j++] = currentChar;
        } else if (currentChar == '(') {
            // If '(' push onto the stack
            push(&stack, currentChar);
        } else if (currentChar == ')') {
            // Pop from stack and add to postfix until '(' is encountered
            while (!isStackEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfixExpression[j++] = pop(&stack);
            }
            // Pop '(' from the stack
            pop(&stack);
        } else if (isOperator(currentChar)) {
            // If operator, pop and add to postfix until stack is empty or '(' is encountered with lower precedence
            while (!isStackEmpty(&stack) && stack.arr[stack.top] != '(' &&
                   precedence(stack.arr[stack.top]) >= precedence(currentChar)) {
                postfixExpression[j++] = pop(&stack);
            }
            // Push current operator onto the stack
            push(&stack, currentChar);
        }

        i++;
    }

    // Pop remaining operators from the stack and add to postfix
    while (!isStackEmpty(&stack)) {
        postfixExpression[j++] = pop(&stack);
    }

    postfixExpression[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infixExpression[MAX_SIZE], postfixExpression[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infixExpression, MAX_SIZE, stdin);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
