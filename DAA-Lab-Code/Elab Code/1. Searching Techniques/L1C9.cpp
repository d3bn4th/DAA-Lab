#include<bits/stdc++.h>
using namespace std;


int main(){
    int T; cin >> T;
    while(T--) {
        int i, n,l; cin >> n >> l;
        int arr[l];
        for(i=0;i<l;i++) {
            cin >> arr[i];
        }
        for(i=0;i<l-1;i++) {
            for(int j = i + 1; j < l; j++) {
                if(arr[i] + arr[j] == n){
                    
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
        
    }
    return 0;
}