#include <iostream>
using namespace std;

void swap(int*a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion_sort(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}
int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}