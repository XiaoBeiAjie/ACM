#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> c[i], c[i] --;
    vector e(n + 1, vector<int>());
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    constexpr i64 inf = 1000000000000000;
    vector f(n + 1, vector ((1 << k) | 1, array<i64, 2>({0, 0})));
    function<void(int, int)> dfs = [&] (int u, int fa) {
        vector g(e[u].size() + 1, vector ((1 << k) | 1, array<i64, 2>({-inf, -inf})));
        g[0][0][0] = 0, g[0][1 << c[u]][1] = w[u];
        int cnt = 0;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            cnt ++; 
            for (int i = 0; i < (1 << k); i ++ ) {
                for (int j = i; j; j = (j - 1) & i) { // 没有把 000000 作为子集
                    int t = i ^ j;
                    g[cnt][i][1] = max(g[cnt][i][1], g[cnt - 1][t][1] + f[v][j][0]);
                    g[cnt][i][0] = max(g[cnt][i][0], g[cnt - 1][t][0] + max(f[v][j][1], f[v][j][0]));
                }
                g[cnt][i][1] = max(g[cnt][i][1], g[cnt - 1][i][1] + f[v][0][0]);
                g[cnt][i][0] = max(g[cnt][i][0], g[cnt - 1][i][0] + max(f[v][0][1], f[v][0][0]));
            } 
        }
        f[u] = move(g[cnt]);
    };
    dfs(1, 0);
    i64 ans = 0;
    for (int i = 0; i < (1 << k); i ++ ) 
        ans = max({ans, f[1][i][1], f[1][i][0]});
    cout << ans << "\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}