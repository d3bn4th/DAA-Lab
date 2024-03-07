#include <iostream>
#include<limits.h>

using namespace std;

int findMin(int *arr, int start, int size){
    int minElement = INT_MAX;
    int minElementIndex = -1;
    for(int i = start; i < size; i++){
        if(arr[i] < minElement){
            minElement = arr[i];
            minElementIndex = i;
        }
    }
    if(minElementIndex == -1) {
        printf("Empty Array!!\n");
    }
    return minElementIndex;
}
void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        int minElementIndex = findMin(arr,i,size);
        swap(&arr[i], &arr[minElementIndex]);
    }
}

void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted Array : ";
    print(arr,size);
    
    SelectionSort(arr,size);

    cout << "Sorted Array : ";
    print(arr,size);
    
    return 0;
}