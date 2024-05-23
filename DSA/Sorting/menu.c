#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Assume that the array is already sorted

        // Last i elements are already in place, so no need to check them again
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
    

void LinearSearch(int n, int arr[],int target){
    for(int i=0;i<n;i++){
        if(target==arr[i]) {
            printf ("\nElement found at index %d",i);
            break;
    }else{
        continue;
    }

}}

int main()
{
    int n, i, target, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    
   
        printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

      while(1){
    printf("\nSelect an option:\n");
    printf("1. Bubble Sort\n");
    printf("2. Linear Search\n3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice==2){
        printf("\nEnter the target value: ");
    scanf("%d", &target);
    }

        switch(choice){
        case 1: BubbleSort(arr,n);
        case 2: LinearSearch(n,arr,target);
        case 3: exit(1);

    }

       }
       return 0;

}

