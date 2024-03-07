#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int r){
    int nL = mid - l + 1;
    int nR = r - mid;
    int L[nL], R[nR];

    for(int i = 0; i < nL; i++)
        L[i] = A[l + i];
    
    for(int i = 0; i < nR; i++)
        R[i] = A[mid + 1 + i];
    
    int i = 0, j = 0, k = l;
    while(i < nL && j < nR){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }
        else {
            A[k] = R[j];
            j += 1;
        }
        k += 1;
    }
    while( i < nL) {
        A[k] = L[i];
        k += 1;
        i += 1;
    }
    while( j < nR) {
        A[k] = R[j];
        k += 1;
        j += 1;
    }
}

void merge_sort(int A[], int l, int r){
    if(l >= r) return; // Base Case 

    int mid = (l + r)/2;
    
    // Recursive Call
    merge_sort(A, l, mid);
    merge_sort(A ,mid + 1, r);
    
    // merge sorted halves
    merge(A, l, mid, r);
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int arr[] = {2,1,4,3,6,5,8,7};
    int  n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n);
    // sorting
    merge_sort(arr,0, n-1);

    printArr(arr, n);
    return 0;
}