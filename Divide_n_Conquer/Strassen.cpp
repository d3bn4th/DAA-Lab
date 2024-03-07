#include <bits/stdc++.h>
using namespace std;

// Fixing the sizes of Mat_A and Mat_B
#define Row_1 4
#define Col_1 4
// Mat_A and Mat_B are square matrices of size 4 * 4
#define Row_2 4
#define Col_2 4
 
vector<vector<int> >Additionofmatrix(vector<vector<int> > Mat_A,
           vector<vector<int> > Mat_B, int divide_idx, int mul = 1)
{
    for (auto i = 0; i < divide_idx; i++)
        for (auto j = 0; j < divide_idx; j++)
            Mat_A[i][j]= Mat_A[i][j] + (mul * Mat_B[i][j]);
    return Mat_A;
}
 
vector<vector<int> > Strassen(vector<vector<int> > Mat_A, vector<vector<int> > Mat_B){
    // Computing the sizes of row and col of the first matrix
    int col_1 = Mat_A[0].size();
    int row_1 = Mat_A.size();
    // Computing the sizes of row and col of the second matrix
    int row_2 = Mat_B.size();
    int col_2 = Mat_B[0].size();
    
    // If this condition is not satisfied matrix multiplication is not possible 
    if (col_1 != row_2) {
        cout << "Matrix Multiplication not possible";
        return {};
    }
    
    //initializing the result matrix
    vector<int> Res_Row(col_2, 0);
    vector<vector<int> > Res(row_1, Res_Row);
 
    if (col_1 == 1)
        Res[0][0] = Mat_A[0][0] * Mat_B[0][0];
    else {
        int divide_idx = col_1 / 2;
        vector<int> Row_vec(divide_idx, 0);
 
        vector<vector<int> > A_11(divide_idx, Row_vec);
        vector<vector<int> > A_12(divide_idx, Row_vec);
        vector<vector<int> > A_21(divide_idx, Row_vec);
        vector<vector<int> > A_22(divide_idx, Row_vec);
        // dividing the matrices into its components
        vector<vector<int> > B_11(divide_idx, Row_vec);
        vector<vector<int> > B_12(divide_idx, Row_vec);
        vector<vector<int> > B_21(divide_idx, Row_vec);
        vector<vector<int> > B_22(divide_idx, Row_vec);
 
        for (auto i = 0; i < divide_idx; i++)
            for (auto j = 0; j < divide_idx; j++) {
                A_11[i][j] = Mat_A[i][j];
                A_12[i][j] = Mat_A[i][j + divide_idx];
                A_21[i][j] = Mat_A[divide_idx + i][j];
                A_22[i][j] = Mat_A[i + divide_idx][j + divide_idx];
                B_11[i][j] = Mat_B[i][j];
                B_12[i][j] = Mat_B[i][j + divide_idx];
                B_21[i][j] = Mat_B[divide_idx + i][j];
                B_22[i][j] = Mat_B[i + divide_idx][j + divide_idx];
            }
        // Callin all  7 Strassens calls for finding the p1,p2....
        vector<vector<int> > P_1(Strassen(A_11, Additionofmatrix(B_11, B_22, divide_idx, -1)));
        vector<vector<int> > P_2(Strassen(Additionofmatrix(A_11, A_12, divide_idx), B_22));
        vector<vector<int> > P_3(Strassen(Additionofmatrix(A_21, A_22, divide_idx), B_11));
        vector<vector<int> > P_4(Strassen(A_22, Additionofmatrix(B_21, B_11, divide_idx, -1)));
        vector<vector<int> > P_5(Strassen(Additionofmatrix(A_11, A_22, divide_idx),Additionofmatrix(B_11, B_22, divide_idx)));
        vector<vector<int> > P_6(Strassen(Additionofmatrix(A_12, A_22, divide_idx, -1), Additionofmatrix(B_21, B_22, divide_idx)));
        vector<vector<int> > P_7(Strassen(Additionofmatrix(A_11, A_21, divide_idx, -1),
            Additionofmatrix(B_11, B_12, divide_idx)));
        // All the p_1,...are obtained now they are solved to get values in the result matrix
        vector<vector<int> > Res_00(Additionofmatrix(
            Additionofmatrix(Additionofmatrix(P_5, P_4, divide_idx), P_7,divide_idx),
            P_2, divide_idx, -1));
        vector<vector<int> > Res_01(Additionofmatrix(P_1, P_2, divide_idx));
        vector<vector<int> > Res_10(Additionofmatrix(P_3, P_4, divide_idx));
        vector<vector<int> > Res_11(Additionofmatrix(Additionofmatrix(Additionofmatrix(P_5, P_1, divide_idx), P_3, divide_idx, -1), P_7, divide_idx, -1));
 
        for (auto i = 0; i < divide_idx; i++)
            for (auto j = 0; j < divide_idx; j++) {
                Res[i][j] = Res_00[i][j];
                Res[i][j + divide_idx] = Res_01[i][j];
                Res[divide_idx + i][j] = Res_10[i][j];
                Res[i + divide_idx][j + divide_idx] = Res_11[i][j];
            }
    }
    return Res;
}
 
int main(){
    // First matrix for multiplication is :
    vector<vector<int> > Mat_A = { { 1, 2, 1, 4 }, { 5, 2, 9, 6 }, { 4, 3, 2, 0 }, { 3, 5, 7, 6 } };
    // Second matrix for multiplication is:
    vector<vector<int> > Mat_B = { { 8, 1, 14, 13 }, { 2, 9, 5, 3 }, { 1, 2, 6, 7 }, { 2, 4, 9, 6 } };
 
    // Calculating the matrix multiplication by divide and conquer and using Strassen’s Matrix Multiplication algorithm
    vector<vector<int> > Result (Strassen(Mat_A, Mat_B));
    // Print the resultant obtained
    int Row=Row_1-1;
    int Col=Col_2-1;
    for (int i = 0 ; i <= Row_1-1; i++) {
        for (int j = 0 ; j <= Col_2-1; j++) {
            // Printing the value in the matrix at position [i][j]
            cout << setw(10);
            cout << Result[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
    
}
 
