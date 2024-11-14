#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector e(n + 1, vector<int>());
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    function<int(int)> find = [&](int x)
    {
        return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        int fv = find(v), fu = find(u);
        if (fv != fu)
            p[fv] = fu;
    }
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    int maxx = 0;
    vector<int> v1, v2, fa(n + 1);
    vector<int> dep(n + 1, 0x3f3f3f3f);
    vector<bool> vis(n + 1);
    function<void(int)> bfs = [&](int st)
    {
        queue<int> q;
        q.push(st);
        dep[st] = 1;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            maxx = max(maxx, dep[u]);
            if (dep[u] & 1)
                v1.push_back(u);
            else
                v2.push_back(u);
            for (auto v : e[u])
                if (dep[v] > dep[u] + 1)
                    dep[v] = dep[u] + 1, q.push(v), fa[v] = u;
        }
    };
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            cnt++, bfs(i);
    // cout << "<<" << v1.size() << " " << v2.size() << " " << cnt << "\n";
    if (cnt == 1)
    {
        for (int u = 1; u <= n; u++)
            if (e[u].size() == n - 1)
            {
                cout << "-1\n";
                return;
            }
        if (maxx == 3)
        {
            for (auto u : v1)
                cout << u << " ";
            int t = fa[v1.back()];
            for (auto u : v2)
                if (t != u)
                    cout << u << " ";
            cout << t << "\n";
        }
        else if (maxx == 4)
        {
            for (auto u : v2)
                cout << u << " ";
            for (auto u : v1)
                cout << u << " ";
            cout << "\n";
        }
        else if (maxx >= 5)
        {
            for (auto u : v1)
                cout << u << " ";
            for (auto u : v2)
                cout << u << " ";
            cout << "\n";
        }
    }
    else
    {
        // for (auto u : v1)
        //     cout << u << " ";
        int t = v1.back();
        int len = v2.size();
        int idx = -1;
        for (int i = 0; i < len; i++)
            if (fa[t] != v2[i] && fa[v2[i]] != t)
            {
                idx = i;
                break;
            }
        if (idx != -1)
        {
            for (int i : v1)
                cout << i << " ";
            for (int i = idx; i < v2.size(); i++)
                cout << v2[i] << " ";
            for (int i = 0; i < idx; i++)
                cout << v2[i] << " ";
            cout << endl;
            // cout << v2[idx] << " ";
            // t = v2[idx];
            // for (auto u : v2)
            //     if (u != t)
            //         cout << u << " ";
        }
        else
        {
            reverse(v1.begin(), v1.end());
            idx = -1;
            int t = v1.back();
            for (int i = 0; i < len; i++)
                if (fa[t] != v2[i] && fa[v2[i]] != t)
                {
                    idx = i;
                    break;
                }
            if (1)
            {
                for (int i : v1)
                    cout << i << " ";
                for (int i = idx; i < v2.size(); i++)
                    cout << v2[i] << " ";
                for (int i = 0; i < idx; i++)
                    cout << v2[i] << " ";
                cout << endl;
            }
        }
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