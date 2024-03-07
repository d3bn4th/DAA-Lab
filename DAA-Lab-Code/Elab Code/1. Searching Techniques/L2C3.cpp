#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> arr;
    for(int i = 0; i < 4; i++) {
        string s; cin >> s;
        arr.push_back(s);
    }
    char MOJO[] = "MOJO";
    for(char it : MOJO){
        bool found = false;
        for(int i = 0; i < 4; i++) {
            string s = arr[i];
            for(int j = 0; j < s.size(); j++){
                if(s[j] == it){
                    cout << it << ": " << j  <<  ","<< i << endl;
                    found = true;
                    break;
                }

            }
            if(found) break;
        }
        if(found) continue;
    }
    return 0;
}