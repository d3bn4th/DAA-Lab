#include<stdio.h>

int binary_search(int arr[], int target, int size){
    int low = 0;
    int high = size-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) high = mid - 1;
        if(arr[mid] < target) low = mid + 1;
    }
    return -1;
}
void insertion_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            //swapping
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {13, 26, 17, 8, 10, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nArray: ");
    print(arr,n);
    insertion_sort(arr,n);
    int target;
    printf("\nSorted Array: ");
    print(arr,n);
    printf("Enter element to search(binary) : ");
    scanf("%d", &target);
    int id = binary_search(arr,target,n);
    if(id != -1){
        printf("Element Found at %d index.\n", id);
    }
    else{
        printf("Element Not Found!!\n");
    }
    return 0;
}