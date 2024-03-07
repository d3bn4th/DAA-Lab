#include <iostream>
#include <vector>
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
        int ans = 0;
        for(auto it : vrr) {
            ans ^= it;
        }
        cout << ans << endl;
    }
    for(int i = 0; i < n; i++) {
        break;
    }
    return 0;
}