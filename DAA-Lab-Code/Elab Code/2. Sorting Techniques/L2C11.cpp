#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector<char> s;
    for(int i = 0; i < n; i++) {
        char x; cin >> x;
        s.push_back(x);
    }
    while(q--){
        int i,j,k; cin >> i >> j >> k;
        i--;
        j;
        if(k == 1) { 
            sort(s.begin() + i, s.begin() + j);
        }
        else {
            sort(s.begin()+ i, s.begin() + j, greater<char>());
        }
    }   
    for(auto it : s){
        cout << it;
    }
    return 0;
}