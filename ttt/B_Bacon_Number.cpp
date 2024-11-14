#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n + m + 1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&] (int x) {
        return (p[x] == x) ? x : p[x] = find(p[x]);
    };
    vector e(n + m + 1, vector<int>());
    for (int i = 1; i <= n; i ++ ) {
        int s; cin >> s;
        int u = i + m;
        for (int j = 0; j < s; j ++ ) {
            int v; cin >> v;
            int fu = find(u), fv = find(v);
            if (fu != fv) { 
                p[fv] = fu;
                e[u].push_back(v); e[v].push_back(u);
            }
        }
    }
    vector<int> dep(n + m + 1), f(n + m + 1);
    function<void(int, int)> dfs = [&] (int u, int fa) {
        f[u] = fa, dep[u] = dep[fa] + 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
        }
    };
    for (int i = 1; i <= n + m; i ++ ) 
        if (find(i) == i) 
            dfs(i, i);
    int q; cin >> q;
    while (q -- ) {
        int u, v; cin >> u >> v;
        if (find(u) != find(v)) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> pre, suf;
        while (dep[u] > dep[v]) {
            pre.push_back(u);
            u = f[u];
        }
        while (dep[v] > dep[u]) {
            suf.push_back(v);
            v = f[v];
        }
        while (u != v) {
            pre.push_back(u); suf.push_back(v);
            u = f[u], v = f[v];
        }
        pre.push_back(u);
        reverse(suf.begin(), suf.end());
        pre.insert(pre.end(), suf.begin(), suf.end());
        cout << (pre.size() + 1) / 2 << "\n";
        for (auto v : pre) 
            cout << ((v > m) ? v - m : v) << " ";
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}