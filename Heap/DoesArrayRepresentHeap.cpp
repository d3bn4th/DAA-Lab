#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int cnt;
    Solution() {
        cnt = 0;
    }

    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        return cnt == 0;
    }
    
    bool isMaxHeap2(int arr[], int n)
    {
        // check for all non-leaf nodes
        for(int i = 0;  i <= (n/2 -1); i++){
            int leftChild = 2*i + 1;
            int rightChild = 2*i + 2;
            if(leftChild < n && arr[i] < arr[leftChild]) {
                return false;
            }
            if(rightChild < n && arr[i] < arr[rightChild]) {
                return false;
            }
        }
        return true;
    }
    
    void heapify(int arr[], int n, int index) {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        // Compare to find the largest node
        if(left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        // swap
        if(largest != index) {
            swap(arr[largest], arr[index]);
            cnt++;
        }
    }
};

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}
