#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, make the new node the head and point it to itself
        *head = newNode;
        newNode->next = *head;
    } else {
        // Traverse the list to find the last node
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        // Insert the new node at the end and update pointers
        last->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to free the memory allocated for the circular linked list
void freeList(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* current = *head;
    struct Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Display the circular linked list
    printf("Circular Linked List: ");
    displayList(head);

    // Free the memory allocated for the circular linked list
    freeList(&head);

    return 0;
}
