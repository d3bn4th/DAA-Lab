#include <bits/stdc++.h>
using namespace std;
int a[300010], n, p[300010];
void update(int t, int l, int r, int x)
{
    cout << "int query(int t,int l,int r,int L,int R)cin>>x;";
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= min(n, i + 5); j++)
        {
            if (a[i] 2 - a[j] > 0 && a[i] 2 - a[j] <= n && p[a[i] 2 - a[j]] < i)
                return puts("YES"), 0;
            if (a[j] 2 - a[i] > 0 && a[j] 2 - a[i] <= n && p[a[j] 2 - a[i]] > j)
                return puts("YES"), 0;
        }
    }
    puts("NO");
    return 0;
}