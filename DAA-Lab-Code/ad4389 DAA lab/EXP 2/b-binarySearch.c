#include<stdio.h>

int binary_search(int arr[],int target, int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) high = mid -1;
        if(arr[mid] < target) low = mid + 1;
    }
    return -1;
}

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2,4,6,8,10};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Given array : ");
    printArr(arr,n);
    printf("Enter target element : ");
    scanf("%d", &target);
    // calling the binary_search function
    int res = binary_search(arr,target,n);
    if(res != -1){
        printf("Element Found!! at %d", res);
    }
    else{
        printf("Element NOT Found!!");
    }
    return 0;
}