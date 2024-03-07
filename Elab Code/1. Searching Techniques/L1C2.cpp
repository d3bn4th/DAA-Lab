#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, float> sizes = {{"1/4", 0.25}, {"1/3", 0.333}, {"1/2", 0.5}, {"1", 1}, {"2", 2}, {"3", 3}};
    
    float n; cin >> n; // num of sticks
    string sz; cin >> sz; // size of each stick
    float limit; cin >> limit;

    float size = sizes[sz];

    float amt = size * 0.45 * n;
    float force = 7.5 * amt;
    cout.precision(2);
    if(force > limit) cout << fixed << force << " the Mask should not eat it!" << endl;
    else cout << fixed << force<< " the Mask can eat it!" << endl;

    return 0;
}