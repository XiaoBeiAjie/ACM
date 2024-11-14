#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector son(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        son[p].push_back(i);
    }
    const int inf = 0x3f3f3f3f;
    function<void(int)> dfs = [&](int u)
    {
        if (son[u].empty())
            return;
        int res = inf;
        for (auto v : son[u]) {
            dfs(v);
            res = min(res, a[v]);
        }
        if (u == 1)
            a[u] = a[u] + res;
        else {
            if (res > a[u])
                a[u] = res + a[u] >> 1;
            else
                a[u] = res;
        }
    };
    dfs(1);
    cout << a[1] << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    system("pause");
    return 0;
}