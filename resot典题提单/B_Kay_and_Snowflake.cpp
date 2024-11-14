#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector e(n + 1, vector<int> ());
    for (int v = 2; v <= n; v ++ ) {
        int u; cin >> u;
        e[u].push_back(v);
    }
    vector<int> siz(n + 1), son(n + 1), p(n + 1);
    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        siz[u] = 1, p[u] = fa;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
            siz[u] += siz[v];
        }
    };
    vector<int> ans(n + 1);
    function<void(int, int)> dfs2 = [&] (int u, int fa) {
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs2(v, u);
        }
        if (siz[u] == 1) return ans[u] = u, void();
        ans[u] = ans[son[u]];
        while (siz[ans[u]] * 2 < siz[u]) ans[u] = p[ans[u]]; 
    };
    dfs1(1, 0); dfs2(1, 0);
    while (q -- ) {
        int u; cin >> u;
        cout << ans[u] << "\n";
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}