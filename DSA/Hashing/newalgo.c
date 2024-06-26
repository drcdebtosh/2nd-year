#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Node structure for linked list in each bucket
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Hash table structure
typedef struct {
    Node* buckets[TABLE_SIZE];
} HashTable;

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a key-value pair into the hash table
void insert(HashTable* table, int key, int value) {
    int index = hashFunction(key);

    // Create a new node
    Node* newNode = createNode(key, value);

    // Insert at the beginning of the linked list (chaining for collision resolution)
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

// Search for a key in the hash table and return its value
int search(HashTable* table, int key) {
    int index = hashFunction(key);

    // Traverse the linked list in the bucket
    Node* current = table->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value; // Found
        }
        current = current->next;
    }

    return -1; // Not found
}

// Delete a key-value pair from the hash table
void delete(HashTable* table, int key) {
    int index = hashFunction(key);

    // Traverse the linked list in the bucket
    Node* current = table->buckets[index];
    Node* prev = NULL;

    // Search for the key
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    // If key is found, delete the node
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            table->buckets[index] = current->next;
        }
        free(current);
    }
}

// Time Complexity Analysis:
// - Insertion: O(1) on average (assuming a good hash function and uniform distribution)
// - Search: O(1) on average (assuming a good hash function and uniform distribution)
// - Deletion: O(1) on average (assuming a good hash function and uniform distribution)

int main() {
    HashTable hashTable;

    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable.buckets[i] = NULL;
    }

    // Insert key-value pairs
    insert(&hashTable, 5, 42);
    insert(&hashTable, 12, 99);
    insert(&hashTable, 7, 32);

    // Search for values based on keys
    printf("Value for key 5: %d\n", search(&hashTable, 5));
    printf("Value for key 12: %d\n", search(&hashTable, 12));
    printf("Value for key 7: %d\n", search(&hashTable, 7));
    printf("Value for key 8: %d\n", search(&hashTable, 8));

    // Delete key-value pair
    delete(&hashTable, 12);

    // Search again after deletion
    printf("Value for key 12 after deletion: %d\n", search(&hashTable, 12));

    return 0;
}
