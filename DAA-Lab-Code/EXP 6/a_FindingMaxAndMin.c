#include<stdio.h>
#include<limits.h>

// to store the result 
struct tuple {
    int max;
    int min;
};
 
int max(int a, int b) {
    return (a >= b) ? a : b;
}

int min(int a, int b) {
    return (a <= b) ? a : b;
}

// main function
struct tuple findMax(int arr[], int low, int high) {
    // base case
    if(low == high) { 
        struct tuple res;
        res.min = arr[low];
        res.max = arr[low];
        return res;
    } 
    
    // recursive call
    int mid = (low + high)/2;
    struct tuple res1 = findMax(arr,low,mid);
    struct tuple res2 = findMax(arr,mid + 1, high);
    
    // comparision
    struct tuple res;
    res.max = max(res1.max, res2.max);
    res.min = min(res1.min, res2.min);
    return res;
}

int main() {
    int arr[] = {2, 1, 3, 5, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    struct tuple ans = findMax(arr, 0, n-1);
    printf("Max : %d\n", ans.max);
    printf("Min : %d\n", ans.min);
    return 0;
}