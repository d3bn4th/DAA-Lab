#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices recursively
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2, 0));

        // Divide matrices A and B into 4 submatrices
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }

        // Recursive calls to multiply submatrices
        vector<vector<int>> C11 = multiplyMatrices(A11, B11) + multiplyMatrices(A12, B21);
        vector<vector<int>> C12 = multiplyMatrices(A11, B12) + multiplyMatrices(A12, B22);
        vector<vector<int>> C21 = multiplyMatrices(A21, B11) + multiplyMatrices(A22, B21);
        vector<vector<int>> C22 = multiplyMatrices(A21, B12) + multiplyMatrices(A22, B22);

        // Combine submatrices to form the result matrix C
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                C[i][j] = C11[i][j];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }

    return C;
}

int main() {
    // Example usage
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    vector<vector<int>> C = multiplyMatrices(A, B);

    // Print the result matrix C
    for (const auto& row : C) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
