#include<stdio.h>

void merge(){

}

int main(){
    int arr[] = {2,1,4,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    print("Given unsorted array : ");
    printArr(arr,n);
    // calling the merge sort function
    mergeSort(arr, 0, n-1);

    print("Sorted Array : \n");
    printArr(arr, n);

    return 0;
}