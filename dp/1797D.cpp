#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) 
        cin >> a[i];
    vector<int> siz(n);
    vector<LL> sum(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        adj[-- u].push_back(-- v);
        adj[v].push_back(u);
    }
    vector<int> fa(n, -1);
    vector<set<pair<int, int>>> s(n);
    function<void(int)> dfs = [&](int u) {
        siz[u] = 1;
        sum[u] = a[u];
        for (auto v : adj[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;
            dfs(v);
            siz[u] += siz[v];
            sum[u] += sum[v];
            s[u].emplace(-siz[v], v);
        }
    };
    dfs(0);
    while (m -- ) {
        int op, u;
        cin >> op >> u;
        u --;
        if (op == 1) 
            cout << sum[u] << endl;
        else {
            if (s[u].empty()) continue;
            int v = s[u].begin()->second;
            s[fa[u]].erase({-siz[u], u});
            s[u].erase({-siz[v], v});
            siz[u] -= siz[v];
            siz[v] += siz[u];
            sum[u] -= sum[v];
            sum[v] += sum[u];
            s[fa[u]].emplace(-siz[v], v);
            s[v].emplace(-siz[u], u);
            fa[v] = fa[u];
            fa[u] = v;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}