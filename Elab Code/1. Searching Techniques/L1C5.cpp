// Peak Finding Algorithm
#include<bits/stdc++.h>
using namespace std;
float vol(float l, float b, float x) {
    return(l-2*x)*(b-2*x)*x;
}
int findPeak(vector<float> arr) {
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
    int T; cin >> T;
    while(T--) {
        float l,w; cin >> l >> w;
        int n = min(l,w)/2 + 1;
        vector<float> arr(n,0);
        for(int i = 0; i < n; i++) {
            arr[i] = vol(l,w,i);
        }
        int index = findPeak(arr);
        cout << arr[index] << endl;
    }    
    return 0;
}