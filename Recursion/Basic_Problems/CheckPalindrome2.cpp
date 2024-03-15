
#include<iostream>
using namespace std;

bool checkPalindrome(string &str,int n,  int i) {
    if(i >= n/2) return true;
    if(str[i] == str[n-i-1]){
        checkPalindrome(str, n, i+1);
    }
    else{
        return false;
    }
}

int main(){
    string str = "naman";
    cout << checkPalindrome(str,str.size(), 0) << endl;
    return 0;
}