#include <bits/stdc++.h>
using namespace std;
#define maxs long long
map<maxs, maxs> a;
maxs i, n, k, x, p;
int main()
{
    cin >> n;
    for (; i < n; i++)
        cin >> x, k += x, a[k]++, p = max(p, a[k]);
    cout << n - p;
}