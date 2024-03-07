#include<stdio.h>

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j >= 1 && arr[j-1] > arr[j] ){
            //swapping
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
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
    // calling the insertion sort function
    insertion_sort(arr,n);

    printf("Sorted Array : ");
    printArr(arr, n);

    return 0;
}