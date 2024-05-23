#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];
~
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is the right index of the sub-array to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Utility function to print an array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver program to test the mergeSort function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}


// Algortihm
/*Merge Sort Algorithm

mergeSort(arr[], l, r)
1. If l < r
    a. Find the middle point m = (l+r)/2
    b. Call mergeSort for the first half: mergeSort(arr, l, m)
    c. Call mergeSort for the second half: mergeSort(arr, m+1, r)
    d. Merge the two halves sorted in step 2b and 2c:
       - Call the merge function: merge(arr, l, m, r)

merge(arr[], l, m, r)
1. Create temporary arrays L[] and R[]
2. Copy data to temporary arrays L[] and R[]:
   a. For i = 0 to n1-1, copy arr[l + i] to L[i]
   b. For j = 0 to n2-1, copy arr[m + 1+ j] to R[j]
3. Merge the two sorted arrays into the original array arr[l..r]:
   a. Initialize indices i, j, and k to 0
   b. While i < n1 and j < n2
        i. If L[i] <= R[j], copy L[i] to arr[k], and increment i and k
       ii. Else, copy R[j] to arr[k], and increment j and k
   c. Copy the remaining elements of L[], if there are any
   d. Copy the remaining elements of R[], if there are any
*/