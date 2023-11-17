#include <stdio.h>

#define MAX_SIZE 5 // Maximum stack size

int stack[MAX_SIZE]; // Array to store stack elements
int top = -1; // Initialize the top of the stack

// Function to push an element onto the stack
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = element;
        printf("Pushed %d onto the stack\n", element);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value for underflow
    } else {
        int element = stack[top--];
        return element;
    }
}

// Function to display the elements of the stack
void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, num;
    
    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to push onto the stack: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                num = pop();
                if (num != -1) {
                    printf("Popped %d from the stack\n", num);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
