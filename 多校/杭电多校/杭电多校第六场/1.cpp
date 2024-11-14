#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define endl "\n"
bool dfs(int u, int fa, int cnt, vector<vector<int>>& e, vector<int>& du)
{
    if (du[u] >= 2)
        cnt++;
    if (cnt >= 2)
        return false;
    bool f = 1;
    for (int i : e[u])
    {
        if (i == fa)
            continue;
        bool tmp = dfs(i, u, cnt, e, du);
        f = (f && tmp);
    }
    return f;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> e(n + 10);
    vector<int> du(n + 10, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        du[x]++, du[y]++;
    }
    int ct2 = 0;
    bool you2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] >= 2)
            ct2++;
        if (du[i] == 2)
            you2 = 1;
    }
    if (ct2 > 5 || (!you2))
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 2)
        {
            du[i] = 1;
            for (int j : e[i])
                du[j]--;
            bool f = 1;
            for (int j : e[i])
            {
                bool tmp = dfs(j, i, 0, e, du);
                f = (f && tmp);
            }
            if (f)
            {
                cout << "Yes" << endl;
                return;
            }
            du[i] = 2;
            for (int j : e[i])
                du[j]++;
        }
    }
    cout << "No" << endl;
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