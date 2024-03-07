#include<stdio.h>

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int min(int a, int b) {
    return (a <= b) ? a : b;
}

// main function
int max_min[2]; // to store the result
void findMaxMin(int arr[], int low, int high) {
    // base case
    if(low == high) { 
        max_min[0] = arr[low];
        max_min[1] = arr[low];
    }
    else {
        // recursive call
        int mid = (low + high)/2;
        int left_max_min[2];
        int right_max_min[2];
        findMaxMin(arr,low,mid);
        left_max_min[0] = max_min[0];
        left_max_min[1] = max_min[1];
        findMaxMin(arr,mid + 1, high);
        right_max_min[0] = max_min[0];
        right_max_min[1] = max_min[1];
        
        // comparision
        max_min[0] = max(left_max_min[0], right_max_min[0]);
        max_min[1] = min(left_max_min[1], right_max_min[1]);
    }
    
}

int main() {
    int arr[] = {2, 1, 3, 5, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    findMaxMin(arr, 0, n-1);
    printf("Max : %d\n", max_min[0]);
    printf("Min : %d\n", max_min[1]);
    return 0;
}
