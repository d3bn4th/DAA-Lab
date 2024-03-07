#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) { 
    if (n <= 1) return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }  
    return true;
}

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int i = 0;
        int ans = 2;
        while(n > 0) {
            if(isPrime(i)) {
                ans = i;
                n--;
            }
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}