#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int minCharsToAdd(string s) {
    int n = s.size();
    for(int i = n; i >= 0; i--) {
        if(isPalindrome(s, 0, i)) {
            return n - i - 1;
        }
    }
    return n - 1;
}

int main(){
    string s; cin >> s;
    cout << minCharsToAdd(s);

    return 0;
}