#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& A, int n, int i){
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
        // calling the heapify of the 
        heapify(A,n,parent);
    }
}

vector<int> MinToMaxHeap(int n, vector<int>& arr) {
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
}


int main(){
    int n; cin >> n;
    vector<int> arr(n,0); 
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Min Heap : ";
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;

    MinToMaxHeap(n,arr);
    
    cout << "Max Heap : ";
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}