#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int A[] = {2,1,4,3,6,5,8,7};
int B[100]; // auxiliary array
void Merge(int low, int mid, int high){
    int h = low, j = mid + 1, i = low;
    while((h <= mid) && (j <= high)) {
        if(A[h] <= A[j]) {
            B[i] = A[h]; h++; 
        }
        else {
            B[i] = A[j]; j++;
        }
        i++;
    }
    
    if(h > mid) {
        for(int k = j; k <= high; k++) {
            B[i] = A[k];
            i++;
        }
    }
    else {
        for(int k = h; k <= mid; k++) {
            B[i] = A[k];
            i++;
        }
    }
    // printArr(B, high - low + 1);
    // Copying the result to A
    for(int k = low; k <= high; k++) {
        A[k] = B[k];
    }
}

void MergeSort(int low, int high){
    if(low < high) {
        // Dividing into subproblems
        int mid = (low + high)/2;
        // solve the subproblems
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        // combining the solutions
        Merge(low, mid, high);
    }
}


int main(){
    int n = sizeof(A)/sizeof(A[0]); 
    printArr(A, n);

    // sorting
    MergeSort(0, n-1);

    printArr(A, n);

    // Merge(0,(n-1)/2,n-1);

    return 0;
}