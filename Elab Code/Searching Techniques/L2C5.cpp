#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
        int n; cin >> n;
        int arr[n][n];
        int trace = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0;j < n; j++) {
               cin >> arr[i][j];
               if(i == j) {
                    trace += arr[i][j];
               }
            }
        }
        // Transpose the matrix
        int transposed[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                transposed[i][j] = arr[j][i];
            }
        }
        // count rows with repeated elements
        int dup_rows = 0;
        int dup_cols = 0;
        for(int i = 0; i < n; i++){
            sort(arr[i], arr[i] + n);
            for(int j = 1; j < n; j++){
                if(arr[i][j] == arr[i][j-1]){
                    dup_rows++;
                    break;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            sort(transposed[i], transposed[i] + n);
            for(int j = 1; j < n; j++){
                if(transposed[i][j] == transposed[i][j-1]){
                    dup_cols++;
                    break;
                }
            }
        }
        cout << "Line  #" << i << ": "<< trace << " " << dup_rows << " " << dup_cols << endl;
    }
    return 0;
}