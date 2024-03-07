#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void generateAllSubsequence(int idx, vector<int>& ss, vector<int>& ssSum, const vector<int>& arr) {
    int n = arr.size();
    if(idx >= n) {
        // add subsequence to the result
        int sum = 0;
        sum = accumulate(ss.begin(), ss.end(), 0);
        ssSum.push_back(sum);
        return;
    }
    // take
    ss.push_back(arr[idx]);
    generateAllSubsequence(idx + 1, ss, ssSum,  arr);
    // not take
    ss.pop_back();
    generateAllSubsequence(idx + 1, ss, ssSum, arr);
}

int minWeightLoss(int targetWeight, const vector<int>& fruitWeights) {
    // creating all possible combinations
    vector<int> ss = {}; // to store each subsequence
    vector<int> ssSum = {}; // to store sum of each subsequence
    generateAllSubsequence(0, ss,ssSum, fruitWeights);
    sort(ssSum.begin(), ssSum.end());
    return *upper_bound(ssSum.begin(), ssSum.end(), targetWeight-1) - targetWeight;
}

int main(){
    int T; cin >> T;
    while(T--){ 
        int n, targetWeight; cin >> n >> targetWeight;
        vector<int> fruitWeights(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            fruitWeights.push_back(x);
        }
        int result = minWeightLoss(targetWeight, fruitWeights);
        cout << result << endl;
    }

    return 0;
}

