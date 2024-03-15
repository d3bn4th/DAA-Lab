#include <iostream>
#include <vector>
using namespace std;
// print the first n fibonacci numbers

int fib(int n){
    if(n == 1 || n == 0) return n;
    return fib(n-1) + fib(n-2);
}
void fibCalc(vector<int>& ans, int n) {
    for(int i = 0; i < n; i++) {
        ans.push_back(fib(i));
    }
} 


vector<int> generateFibonacciNumbers(int n) {
    vector<int> ans;
    if(n > 0) ans.push_back(0);
    if(n > 1) ans.push_back(1);
    for(int i = 2; i < n; i++) {
        ans.push_back(ans[i-1] + ans[i-2]);
    }
    return ans;
}

int main(){
    int n = 5; 
    vector<int> ans = generateFibonacciNumbers(n);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
