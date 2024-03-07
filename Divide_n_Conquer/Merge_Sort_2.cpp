#include<bits/stdc++.h>
using namespace std;


void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int A[] = {2,1,4,3,6,5,8,7};
void Merge_(int low, int mid, int high){
    int nL = mid - low + 1; cout << nL << endl;
    int nR = high - mid; cout << nR << endl;
    int L[nL];
    int R[nR];
    copy(A + low, A + mid + 1 , L);
    copy(A + mid + 1, A + high + 1, R);
    printArr(L, nL);
    printArr(R, nR);
    int i = 0, j = 0, k = low;
    while((i < nL) && (j < nR)) {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }  
    while(i < nL) {
        A[k] = L[i];
        i++;
        k++;      
    }
    while(j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}
void Merge(int low, int mid, int high){
    int n = high - low + 1;
    int B[n];  // O(n) extra space
    int h = low, j = mid + 1, i = low;
    while((h <= mid) && (j <= high)) {
        if(A[h] <= A[j]){
            B[i] = A[h]; h += 1;
        }
        else {
            B[i] = A[j]; j += 1;
        }
        i += 1;
    }
    if(h > mid) {
        for(int k = j; k <= high; k++){
            B[i] = A[k];
            i += 1;
        }
    }
    else {
        for(int k = h; k <= mid; k++) {
            B[i] = A[k];
            i += 1;
        }
    }

    // Copying the merged values back
    for(int k = low; k <= high; k++){
        A[k] = B[k];
    }
}

void MergeSort(int low, int high){
    // invalid or size = 1 array
    if(low >= high) {
        return;
    }
    else {
        // Dividing the Array into sub-arrays
        // finding the mid points
        int mid = (low + high)/2;
        
        // Recursive Call on the two halves
        MergeSort(low, mid);
        MergeSort(mid+1, high);

        // Merging the Results
        Merge_(low, mid, high);
    }
}

int main(){
    int  n = sizeof(A)/sizeof(A[0]);
    printArr(A, n);

    // sorting
    MergeSort(0, n-1);

    printArr(A, n);
    return 0;
}