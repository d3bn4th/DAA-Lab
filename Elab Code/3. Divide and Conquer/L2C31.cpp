#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s = to_string(n);
    cout << s;
    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}   