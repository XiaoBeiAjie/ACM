#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define endl "\n"
vector<int> e[N];
int f[N];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
vector<int> v1;
vector<int> v2;
int dep[N];
int ff[N];
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
void dfs(int u, int fa, int de)
{
    dep[u] = de;
    ff[u] = fa;
    if (de & 1)
        v2.push_back(u);
    else
        v1.push_back(u);
    for (int i : e[u])
    {
        if (i == fa)
            continue;
        dfs(i, u, de + 1);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    v1.clear();
    v2.clear();
    for(int i = 1 ; i <= n ; i++)
        e[i].clear();
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        merge(x, y);
    }
    int ct = 0;
    for (int i = 1; i <= n; i++)
        ct += (find(i) == i);
    if (ct == 1)
    {
        for (int i = 1; i <= n; i++)
            if (e[i].size() == n - 1)
            {
                cout << -1 << endl;
                return;
            }
        dfs(1, -1, 0);
        int maxx = 0;
        for (int i = 1; i <= n; i++)
            maxx = max(maxx, dep[i]);
        if (maxx >= 4)
        {
            for (int i : v1)
                cout << i << " ";
            int p = ff[v1.back()];
            for(int i : v2)
                if(i != p) cout << i << " ";
            if (p != -1) cout << p << endl;
            else cout << "\n";
        }
        else if(maxx == 3)
        {
            for (int i : v2)
                cout << i << " ";
            int p = ff[v2.back()];
            for (int i : v1)
                if(i != p) cout << i << " ";
            if (p != -1) cout << p << endl;
            else cout << "\n";
        }
        else
        {
            for (int i : v1)
                cout << i << " ";
            int p = ff[v1.back()];
            for(int i : v2)
                if(i != p) cout << i << " ";
            if (p != -1) cout << p << endl;
            else cout << "\n";
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if (find(i) == i)
                dfs(i, -1, 0);
        for (int i : v1)
            cout << i << " ";
        int p = ff[v1.back()];
            for(int i : v2)
                if(i != p) cout << i << " ";
        if (p != -1) cout << p << endl;
        else cout << "\n";
    }
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