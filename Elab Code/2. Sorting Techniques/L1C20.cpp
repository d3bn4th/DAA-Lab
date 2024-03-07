#include<bits/stdc++.h>
#include <iomanip> 
using namespace std;

int main(){
    string m,s; cin >> m >> s;
    vector<string> mrr = {"RUBBER", "WOOD", "STEEL"};
    vector<string> srr = {"CONCRETE", "WOOD", "STEEL", "RUBBER", "ICE"};
    vector<vector<float>> data = {
        {0.90, 0.62, 0.57},
        {0.80, 0.42, 0.30},
        {0.70, 0.30, 0.74},
        {1.15, 0.80, 0.70},
        {0.15, 0.05, 0.03}
    };
    int x = find(srr.begin(), srr.end(), s) - srr.begin();
    int y = find(mrr.begin(), mrr.end(), m) - mrr.begin();
    float fcoeff = data[x][y];
    float min_slope = atan(fcoeff);
    cout << fixed << setprecision(2) << fcoeff << " " << setprecision(1) << min_slope*180/3.1415 ;
    return 0;
}