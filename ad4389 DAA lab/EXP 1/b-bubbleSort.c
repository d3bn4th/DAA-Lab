#include<stdio.h>

void bubble_sort(int arr[], int n){
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                //swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2,1,4,6,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Given unsorted array : ");
    printArr(arr,n);
    // calling the bubble_sort  function
    bubble_sort(arr,n);

    printf("Sorted Array : ");
    printArr(arr, n);

    return 0;
}