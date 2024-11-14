#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, m, c; cin >> n >> m >> c;
    vector e(n + 1, vector<int>());
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    vector<i64> siz(n + 1);
    i64 ans = LLONG_MAX;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        siz[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
        ans = min(ans, siz[u] * siz[u] + (n - siz[u]) * (n - siz[u]));
    };
    dfs(2, 0);
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}