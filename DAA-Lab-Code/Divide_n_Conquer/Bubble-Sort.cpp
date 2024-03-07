#include <iostream>
using namespace std;

void bubble_sort(int *arr, int n){
    for(int i = n-2; i >=0; i--){
        //compare
        bool didSwap = false;
        for(int j = 0; j <= i; j++){
            if(arr[j] > arr[j+1]){
                // swapping
                didSwap = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        // makes the Best Case TC = O(1)
        if(!didSwap){
            break;
        }
    }
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}