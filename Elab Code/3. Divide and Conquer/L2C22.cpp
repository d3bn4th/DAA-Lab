#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> arrays(n);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;

        arrays[i].resize(size);
        for (int j = 0; j < size; ++j) {
            cin >> arrays[i][j];
        }

        sort(arrays[i].begin(), arrays[i].end());
    }

    int total_sum = 0;

    for (const auto& array : arrays) {
        int elements_to_pick = min(k, static_cast<int>(array.size()));
        for (int i = 0; i < elements_to_pick; ++i) {
            total_sum += array[i];
        }
        k -= elements_to_pick;
    }

    cout << total_sum << endl;

    return 0;
}
