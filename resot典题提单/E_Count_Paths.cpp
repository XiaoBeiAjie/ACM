#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector e(n + 1, vector<int> ());
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    vector<int> siz(n + 1), son(n + 1);
    vector f(n + 1, map<int, int>());
    i64 ans = 0;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        siz[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
            if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
        }
        for (auto v : e[u]) {
            if (v == fa || v == son[u]) continue;
            for (auto [c, cnt] : f[v]) {
                if (c != w[u]) ans += 1ll * f[son[u]][c] * cnt;
                f[son[u]][c] += cnt;
            }
        }
        ans += f[son[u]][w[u]];
        f[u] = move(f[son[u]]);
        f[u][w[u]] = 1;
    };
    dfs(1, 0);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}