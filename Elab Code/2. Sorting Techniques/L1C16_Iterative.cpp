
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> vrr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vrr.push_back(x);
    }
    if(n == 1){
        cout << vrr[0] << endl;
    }
    else {
        sort(vrr.begin(), vrr.end());
        if(vrr[0] != vrr[1])  {
            cout << vrr[0] << endl;
            exit(0);
        }
        for(int i = 1; i < n; i++) {
            if(vrr[i] != vrr[i-1]){
                cout << vrr[i] << endl;
                break;
            }
        }
    }
    return 0;
}
