#include<iostream>
using namespace std;

bool checkPalindrome(string &str, int start, int end) {
    if(start < end) {
        if(str[start] == str[end]){
            checkPalindrome(str,start + 1,end - 1);
        }
        else{
            return false;
        }
    }
    else {
        return true;   
    }
}

int main(){
    string str = "naman";
    cout << checkPalindrome(str,0,str.size()-1) << endl;
    return 0;
}