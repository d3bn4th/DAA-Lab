#include <iostream>
#include <vector>

using namespace std;

string checkCondition(const vector<int>& permutation) {
    int m = permutation.size();
    // Iterate through all possible pairs (a, b)
    for (int a = 0; a < m; ++a) {
        for (int b = 0; b < m; ++b) {
            // Check if the pair satisfies the condition
            if (a <= b) {
                for (int element : permutation) {
                    double quotient = static_cast<double>(a) / b;
                    if (quotient > element && element >= a) {
                        return "YES";
                    }
                }
            }
        }
    }

    // If no such pair is found
    return "NO";
}

int main() {
    // Example usage:
    vector<int> permutation1 = {1, 5, 2, 4, 3};
    string result1 = checkCondition(permutation1);
    cout << "Test Case 1: " << result1 << endl;

    vector<int> permutation2 = {7, 11, 9, 13, 10, 3, 1, 14, 12, 5, 2, 6, 4, 8};
    string result2 = checkCondition(permutation2);
    cout << "Test Case 2: " << result2 << endl;

    return 0;
}
