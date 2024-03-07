 // find the peak element in a bitonic array
#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int> arr) {
    if(arr.size() == 1) return 0;
    int low = 0;
    int high = arr.size()-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(mid == 0 && arr[mid] > arr[mid + 1]) return mid;
        if(arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) {
            return mid;
        }  
        else if(arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        }  
        else if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) {
            high = mid - 1;
        }  
    }
    return -1;
}
    int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2 , 1};
    int index = findPeak(arr);
    if(index == -1) {
        cout << "Empty Array" << endl;
    }
    else { 
        cout << "Peak Element : " << arr[index] << endl;
    }
    return 0;
}