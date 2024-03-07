// Maximum Sub-array Sum
#include<bits/stdc++.h>
using namespace std;

int Max(int a, int b, int c) {
    if(a >= b && a >= c) return a;
    if(b > a && b > c) return b;
    else return c;
}
int MaxCrossSum(int A[], int low, int mid, int high) {
    int LCSum = INT_MIN;
    int RCSum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >= low; i--){
        sum += A[i];
        if(sum > LCSum){
            LCSum = sum;
        }
    }
    sum = 0;
    for(int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if(sum >RCSum) {
            RCSum = sum;
        }
    }
    return  LCSum + RCSum;
}
int MaxSubArraySum(int A[], int low, int high) {
    if(low == high) return A[low]; // Base Condition
    // Divide
    int mid = (low + high)/2;
    int LSum =  MaxSubArraySum(A,low, mid);
    int RSum = MaxSubArraySum(A, mid + 1, high);
    int CSum = MaxCrossSum(A,low,mid,high);
    return Max(LSum,RSum,CSum);
}   

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // output =  6
    int n = sizeof(arr)/sizeof(arr[0]);
    int result  = MaxSubArraySum(arr, 0, n-1);
    cout << result << endl;
    return 0;
}