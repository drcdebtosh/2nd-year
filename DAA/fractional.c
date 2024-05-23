#include <stdio.h>
#include <stdlib.h>

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value/weight ratio
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items based on value/weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0;  // Final value of items in knapsack

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the whole item won't exceed the capacity, add it
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        // If adding only a part of the item will fit, add the part
        else {
            int remainingWeight = W - currentWeight;
            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break; // Knapsack full
        }
    }
    return finalValue;
}

int main() {
    // Example usage
    int W = 50; // Weight capacity of knapsack
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}}; // Value and weight of items
    int n = sizeof(items) / sizeof(items[0]); // Number of items

    double maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %lf\n", maxValue);

    return 0;
}
