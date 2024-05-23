/* Algortihm
Quicksort Algorithm

quicksort(arr[], low, high)
1. If low < high
    a. Partition the array by calling partition(arr, low, high)
    b. Recursively call quicksort for the left partition: quicksort(arr, low, pi-1)
    c. Recursively call quicksort for the right partition: quicksort(arr, pi+1, high)

partition(arr[], low, high)
1. Choose a pivot element from the array (commonly the last element)
2. Initialize two pointers i and j, where i is the index of the smaller element
3. Iterate through the array from low to high-1:
   a. If arr[j] <= pivot, swap arr[i] and arr[j], and increment i
4. Swap arr[i] and arr[high] to place the pivot in its correct position
5. Return the index i, which is now the correct position of the pivot

*/
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    // Choose the pivot (commonly the last element)
    int pivot = arr[high];
    
    // Index of the smaller element
    int i = low - 1;

    // Iterate through the array
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] to place the pivot in its correct position
    swap(&arr[i + 1], &arr[high]);

    // Return the index of the pivot element
    return i + 1;
}

// Function to perform Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test the Quicksort function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    quicksort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    
    return 0;
}
