#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

vector<vector<int>> subsequences;
int calcSum(const vector<int>& ss) {
    int sum = 0; 
    for(auto it : ss){
        sum += it;
    }
    return sum;
}
void printSubsequence(int idx, vector<int> ss, vector<int> arr) {
    int n = arr.size();
    if(idx >= n) {
        // add subsequence to the result
        subsequences.push_back(ss);
        return;
    }
    // take
    ss.push_back(arr[idx]);
    printSubsequence(idx + 1, ss, arr);
    ss.pop_back();
    printSubsequence(idx + 1, ss, arr);
}

void generateAllSubsequenceSum(int idx, vector<int>& ss, vector<int>& ssSum, const vector<int>& arr) {
    int n = arr.size();
    if (idx >= n) {
        // calculate the sum of the subsequence
        ssSum.push_back(calcSum(ss));
        return;
    }
    // take
    ss.push_back(arr[idx]);
    generateAllSubsequenceSum(idx + 1, ss, ssSum, arr);
    // not take
    ss.pop_back();
    generateAllSubsequenceSum(idx + 1, ss, ssSum, arr);
}

int main(){
    vector<int> arr = {3,1,2};
    vector<int> ss = {};
    vector<int> ssSum = {};
    printSubsequence(0,ss,arr);
    generateAllSubsequenceSum(0,ss, ssSum, arr);   
    int cnt = 0;
    for(auto i : subsequences) {
        cout << ++cnt<< ".  ";
        for(auto j : i){
            cout  <<  j << " ";
        }
        cout << endl;
    }
    cout << "Sum : " << endl;
    for(auto i : ssSum) {
        cout << i << endl;
    }
    return 0;
}