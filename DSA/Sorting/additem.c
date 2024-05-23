#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insertion (int a[],int n ,int key){
    int i,j;

      

    
    for (i = 0; i < n; i++) {
        if (a[i] > key) {
            break;
        }
    }

    
    for (j = n; j > i; j--) {
        a[j] = a[j - 1];
    }

    
    a[i] = key;

    for (int i = 0; i < n+1; i++) {
        printf("%d ", a[i]);
    }
}

    
    

int main()
{
    int n,key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[100 ];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to add in the array:\n");

    scanf("%d",&key);


    insertion(arr, n, key);
    

return 0;
}