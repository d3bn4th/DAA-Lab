#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for(int k = 1; k <= T; k++) {
        int n; cin >> n;
        int arr[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        vector<int> w(n,0);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int mx = 0;
            int idx = 0;
            for(int j = 0; j < n; j++) {
                if(w[j] == 0 && arr[j][i] >= mx) {
                    mx = arr[j][i];
                    idx = j;
                }
            }
            sum += mx;
            // cout << mx << " ";
            w[idx] = 1; // woman paired with ith man
        }
        cout << "Line " << k << ": " << sum << endl;
    }

    return 0;
}