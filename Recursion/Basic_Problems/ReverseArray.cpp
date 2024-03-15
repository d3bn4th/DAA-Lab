#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
} 
bool checkPalindrome(string &str, int start, int end) {
    if(start < end) {
        if(str[start] == str[end]){
            checkPalindrome(str,start + 1,end - 1);
        }
        else{
            return false;
        }
    }
    else {
        return true;   
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse(arr,0,n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    string str = "naman";
    cout << checkPalindrome(str,0,str.size()-1) << endl;
    return 0;
}