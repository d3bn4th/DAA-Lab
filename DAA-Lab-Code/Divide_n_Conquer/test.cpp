#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

class Solution
{
    public:    
    int select(int arr[], int i, int n){
        int minElement = INT_MAX;
        int minElementIndex = -1;
        for(int k = i; k < n; k++){
            if(arr[k] < minElement){
                minElement = arr[k];
                minElementIndex = k;
            }
        }
        return minElementIndex;
    }
    
    
    void selectionSort(int arr[], int n){
        for(int i = 0; i < n-1; i++){
            int minElementIndex = select(arr, i, n);
            cout << minElementIndex << endl;
            //swapping
            int temp = arr[i];
            arr[i] = arr[minElementIndex];
            arr[minElementIndex] = temp;
        }  
    }
};

void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main(){
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){    
        scanf("%d",&n);
    
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
        Solution ob;  
        ob.selectionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}