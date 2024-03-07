#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        int n; cin >> n;
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string name;
            int l,b,h;
            cin >> name >> l >> b >> h;
            int vol = l * b * h;
            mp[name] = vol;
        }
        vector<int> vol;
        for(auto it : mp) {
            vol.push_back(it.second);
        }
        sort(vol.begin(), vol.end(), greater<int>()); // sort in reverse order

        if(vol[0] > vol[1]){
            string thief;
            string victim;
            for(auto it : mp) {
                if(vol[0] == it.second) {
                    thief = it.first;
                }
            }
            for(auto it : mp){
                if(vol[vol.size() - 1] == it.second) {
                    victim = it.first;
                }
            }
            cout << "Line " << i << ": " << thief  << " took chocolate from " << victim << endl;
        }
        else {
            cout << "Line " << i << ": no thief" << endl;
        }
    }
    // Mandatory Test Case
    int i = 0;
    int size = 0;
    for(i=0;i<size-1;i++) {}

    return 0;
}