#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void delete(int arr[], int size, int element)
{
    int i, found = 0;

    // Find the position of the element to be deleted
   
        
        for ( i = 0; i < size; i++)
        {
            if (arr[i] == element)
        {
            found = 1;
            continue;
        }
            printf("%d ", arr[i]);
        }
    

    if (!found)
    {
        printf("Element not found in the array.\n");
        return;
    }

    printf("\nElement %d deleted from the array.\n", element);
}
int main(void)
{
    int n, i, item;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[50];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the item you want to delete of the array:\n");
    scanf("%d", &item);

    delete (arr, n, item);

    return 0;
}