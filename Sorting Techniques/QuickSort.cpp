#include<bits/stdc++.h>
using namespace std;

int A[] = {2,1,4,3,6,5,8,7, INT_MAX};

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Interchange(int i, int j) {
    int p = A[i];
    A[i] = A[j];
    A[j] = p;
}
int Partition(int low, int high) {
    int v = A[low];
    int i = low;
    int j = high;
    do {
        do {
            i++;
        }while(A[i] <= v);

        do {
            j--;
        }while(A[j] > v);

        if(i < j) {
            Interchange(i,j);
        }
    }while(i < j);
    // Interchange Pivot to its correct place at j
    Interchange(low,j);
    return j; // correct position of the pivot element
}

void QuickSort(int low, int high){
    if(low < high) {
        int j = Partition(low,high + 1);
        cout << j << endl;
        QuickSort(low,j-1);
        QuickSort(j+1,high);
    }
}

int main(){
    int n = sizeof(A)/sizeof(A[0]); 
    printArr(A, n-1);

    // sorting
    QuickSort(0, n-2);

    printArr(A, n-1);
    return 0;
}