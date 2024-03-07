#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        int n; cin >> n;
        char arr[n];
        char prev;
        char cur;
        cin >> cur;
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            char x; cin >> x;
            if(x == 'Y' || x == 'O') {
                prev = cur;
                cur = x;
                if(cur != prev){
                    cnt++;
                }
            }
        }   
        cout << "Line #"<< i << ": " << cnt << endl;
    }

    return 0;
    
}