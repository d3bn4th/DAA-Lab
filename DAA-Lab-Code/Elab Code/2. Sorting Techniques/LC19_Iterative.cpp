#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--) {
        int n, budget; cin >> n >> budget;
        vector<int> prices;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            prices.push_back(x);
        }
        sort(prices.begin(), prices.end());
        int i = 0;
        int cnt = 0;
        while(budget-prices[i] >= 0) {
            budget -= prices[i];
            i++;
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}