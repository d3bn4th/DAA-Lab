#include<stdio.h>

int linear_search(int arr[],int target, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == target) return i;
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
    int arr[] = {2,1,4,6,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Given array : ");
    printArr(arr,n);
    printf("Enter target element : ");
    scanf("%d", &target);
    // calling the linear_saerch function
    int res = linear_search(arr,target,n);
    if(res != -1){
        printf("Element Found!! at %d", res);
    }
    else{
        printf("Element NOT Found!!");
    }
    return 0;
}