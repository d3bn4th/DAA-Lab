/*
    Build a Max Heap form the given array
 */
#include<bits/stdc++.h>
using namespace std;

void heapify(int *A, int n, int i){
    int parent = i;
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;

    if(left_child < n && A[parent] < A[left_child]){
        parent = left_child;
    }
    if(right_child < n && A[parent] < A[right_child]){
        parent = right_child;
    }

    //swap
    if(parent != i){
        swap(A[parent], A[i]); 
        // calling the swapped down value
        heapify(A,n,parent);
    }
}

void buildMaxHeap(int *A, int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(A,n,i); // calling the heapify method on the ith node
    }    
}
int main(){
    int A[] = {54, 56, 55, 52, 53, 57, 50};
    int  n = sizeof(A)/sizeof(A[0]);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    buildMaxHeap(A, n);
    
    cout << "Heapified..." << endl;
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl; 

    return 0;
}