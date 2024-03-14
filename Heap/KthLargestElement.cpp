/*
    Find the Kth largest element form the given array
 */
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
        // calling the swapped down value
        heapify(A,n,parent);
    }
}

void buildMaxHeap(vector<int>& A, int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(A,n,i); // calling the heapify method on the ith node
    }    
}

int MaxElement(vector<int>& A, int n) {
    if(A.size() == 0) return -1;
    if(A.size() == 1) return A[0];
    int max = A[0];
    A[0] = A.back();
    A.pop_back();
    heapify(A,n,0); 
    return max;
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k; cin >> k;
    buildMaxHeap(arr, arr.size());
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    int ans;
    while(k--) {
        ans = MaxElement(arr,arr.size());
    }
    cout << ans << endl;
    return 0;
}