#include<bits/stdc++.h>
using namespace std;
void bs(int arr[], int n) {
    for (int i = 0; i<n - 1; i++) 
        for (int j = 0; j<n-i- 1; j++) 
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
}
int main(){
    int T; cin >> T;
    while(T--) {
        int n,cnt = 0; cin>>n; int girls[n], boys[n];
        for(int i=0;i<n;i++) cin >> girls[i];
        for(int i=0;i<n;i++) cin >> boys[i];
        bs(girls, n); bs(boys, n); 
        for(int i = 0;i<n;i++) {
            if(girls[i]%boys[n-i-1] == 0 || boys[n-i-1]%girls[i] == 0) cnt++;
        }cout<<cnt<<endl;
    }
}