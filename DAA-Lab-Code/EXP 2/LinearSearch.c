#include<stdio.h>

int linear_search(int arr[], int target, int size){
    for(int i=0;i<size;i++){
        if(arr[i] == target) return i;
    }
    return -1;
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
    int target;
    printf("\nArray: ");
    print(arr,n);
    printf("Enter element to search(linear) : ");
    scanf("%d", &target);
    int id = linear_search(arr,target,n);
    if(id != -1){
        printf("Element Found at %d index.\n", id);
    }
    else{
        printf("Element Not Found!!\n");
    }
    return 0;
}