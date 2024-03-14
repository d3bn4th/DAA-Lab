#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &it : kArrays){
        for(auto &jt : it) {
            pq.push(jt);
        }
    } 
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    vector<vector<int>> kArrays;
    int k; cin >> k;
    int originalK = k; // Store the original value of k
    while(k--) {
        int n; cin >> n;
        vector<int> Array(n,0);
        for(int i = 0; i < n; i++){
            cin >> Array[i];
        }
        kArrays.push_back(Array);
    }
    vector<int> ans = mergeKSortedArrays(kArrays, originalK); // Use originalK instead of k

    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}