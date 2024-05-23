#include<stdio.h>
#include<stdlib.h>

int linearsearch(int arr[],int n, int target){
    for (int i = 0; i < arr[n]; i++)
    {
        if(arr[i]==target){
            return i;
        }
    }return -1;
    
}

int binarysearch(int arr[],int left,int right,int target){
    int mid = left + (right-left)/2;

    if(target==arr[mid]){
        return mid;
    }
    if(target>arr[mid]){
            return binarysearch(arr,mid+1, right,target);
    }if(target<arr[mid]){
            return binarysearch(arr,left,mid-1, target);
    }
    
}
int main(){
      int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 16;

    // Perform linear search
    int linearResult = linearsearch(arr, n, target);
    if (linearResult != -1) {
        printf("Linear Search: Element %d found at index %d\n", target, linearResult);
    } else {
        printf("Linear Search: Element %d not found in the array\n", target);
    }

    // Perform binary search
    int binaryResult = binarysearch(arr, 0, n - 1, target);
    if (binaryResult != -1) {
        printf("Binary Search: Element %d found at index %d\n", target, binaryResult);
    } else {
        printf("Binary Search: Element %d not found in the array\n", target);
    }

    return 0;
    
    
    
    
return 0;
}