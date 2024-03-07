#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while (T--) {
        int M, C, D;
        cin >> M >> C >> D;
        int min_cost = INT_MAX;
        int j = 0;
        while(M>0){
            int cost = (M*M)*C + (j*j)*D;
            min_cost = min(min_cost, cost);
            j++;
            M--; 
        }
        cout << min_cost << endl;  
    }

    return 0;
}