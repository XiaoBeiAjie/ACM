#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector e(n + 1, vector<int>());
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    vector<int> siz(n + 1);
    vector f(n + 1, vector (20, array<i64, 2>()));
    vector g(n + 1, vector (20, array<i64, 2>()));
    function<void(int, int)> dfs = [&] (int u, int fa) {
        siz[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
            for (int i = 0; i < 20; i ++ ) {
                g[u][i][1] += f[v][i][1];
                g[u][i][0] += f[v][i][0];
            }
        }
        for (int i = 0; i < 20; i ++ ) {
            f[u][i][(w[u] >> i) & 1] = g[u][i][(w[u] >> i) & 1];
            f[u][i][((w[u] >> i) & 1) ^ 1] = f[u][i][(w[u] >> i) & 1] + 1ll * siz[u] * (1 << i);
        }
    };
    dfs(1, 0);
    vector<i64> ans(n + 1);
    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        for (int i = 0; i < 20; i ++ ) {
            if (u != 1) f[u][i][(w[u] >> i) & 1] = g[u][i][(w[u] >> i) & 1] + f[fa][i][(w[u] >> i) & 1] - ((((w[u] >> i) & 1) == ((w[fa] >> i) & 1)) ? f[u][i][(w[u] >> i) & 1] : 1ll * siz[u] * (1 << i) + f[u][i][((w[u] >> i) & 1) ^ 1]);
            if (u != 1) f[u][i][((w[u] >> i) & 1) ^ 1] = f[u][i][(w[u] >> i) & 1] + 1ll * n * (1 << i);
            ans[u] += min(f[u][i][(w[u] >> i) & 1], f[u][i][((w[u] >> i) & 1) ^ 1]);
        }
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs1(v, u);
        }
    };
    dfs1(1, 0);
    for (int i = 1; i <= n; i ++ ) 
        cout << ans[i] << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}