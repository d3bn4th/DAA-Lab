#include <iostream>
#include <map>
using namespace std;
const int N = 1 << 20;
int n, a[N], c[N], w;
void upd(int i, int c)
{
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map<int, int> u, v;
    for (int i = n; i-- > 0;)
    {
        int x = ++u[a[i]];
        while (x < N)
            ++c[x], x += x & -x;
    }
    for (int i = 0; i < n; ++i)
    {
        int x = u[a[i]]--, y = v[a[i]]++;
        while (x < N)
            --c[x], x += x & -x;
        while (y > 0)
            w += c[y], y -= y & -y;
    }
    cout << w << endl;
}