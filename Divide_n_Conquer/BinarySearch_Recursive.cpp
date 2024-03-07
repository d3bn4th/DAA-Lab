#include <iostream>
using namespace std;

int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int RBinarySearch(int low, int high, int key) {
    if(low == high) {
        if(A[low] == key) return low;
        else return -1;
    }
    else {
        int mid = (low+high)/2;
        if(A[mid] == key) return mid;
        if(A[mid] > key) return RBinarySearch(low, mid - 1, key);
        if(A[mid] < key) return RBinarySearch(mid + 1, high, key);
    }
    return -1;
}
 
int main(){
    int n = sizeof(A)/sizeof(A[0]);
    cout << RBinarySearch(0, n-1, 5) << endl;

    return 0;
}