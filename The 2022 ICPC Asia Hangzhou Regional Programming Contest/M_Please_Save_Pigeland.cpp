#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

struct SegTree {
    int l, r;
    i64 val;
};

void solve() {
    int n, k; cin >> n >> k;
    vector<bool> st(n + 1);
    for (int i = 1; i <= k; i ++ ) {
        int u; cin >> u;
        st[u] = true;
    }
    vector e(n + 1, vector<array<int, 2>>());
    for (int i = 1; i < n; i ++ ) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w}); e[v].push_back({u, w});
    }
    if (k == 1) return cout << "0\n", void();
    constexpr int inf = 0x3f3f3f3f;
    vector<int> siz(n + 1), dfn(n + 1), l(n + 1, inf), r(n + 1);
    vector<i64> dis(n + 1), f(n + 1), gd(k + 1);
    vector<int> p(k + 1);
    int idx = 0;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        if (st[u]) {
            siz[u] = 1, f[u] += dis[u];
            dfn[u] = ++ idx, l[u] = idx, r[u] = idx;
            p[idx] = u;
        }
        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            dis[v] = dis[u] + w;
            dfs(v, u);
            l[u] = min(l[u], l[v]), r[u] = max(r[u], r[v]);
            siz[u] += siz[v], f[u] += f[v];
        }
    };
    dfs(1, 0);
    for (int i = k; i; i -- ) 
        gd[i] = dis[p[i]] - dis[p[i - 1]];
    vector<SegTree> tr(k << 2);
    function<void(int)> pushup = [&] (int root) {
        tr[root].val = gcd(tr[root << 1].val, tr[root << 1 | 1].val);
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].l = l, tr[root].r = r;
        if (l == r) {
            tr[root].val = gd[l];
            return ;
        }
        int mid = l + r >> 1;
        build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
        pushup(root);
    };
    function<void(int, int, int)> update = [&] (int root, int p, int c) {
        if (p < tr[root].l || p > tr[root].r) return ;
        if (tr[root].l == p && p == tr[root].r) {
            tr[root].val += c;
            return ;
        }
        if (tr[root << 1].r >= p) update(root << 1, p, c);
        if (tr[root << 1 | 1].l <= p) update(root << 1 | 1, p, c);
        pushup(root);   
    };
    function<i64(int, int, int)> query_gcd = [&] (int root, int l, int r) {
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].val;
        i64 res = 0;
        if (tr[root << 1].r >= l) res = gcd(res, query_gcd(root << 1, l, r));
        if (tr[root << 1 | 1].l <= r) res = gcd(res, query_gcd(root << 1 | 1, l, r));
        return res;
    };
    build(1, 1, k);
    i64 ans = 2ll * f[1] / query_gcd(1, 1, k);
    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            f[v] = f[u] + 1ll * (k - 2 * siz[v]) * w;
            update(1, 1, w);
            if (siz[v]) update(1, l[v], - 2 * w);
            if (r[v] != k && siz[v]) update(1, r[v] + 1, 2 * w);
            ans = min(ans, 2ll * f[v] / query_gcd(1, 1, k));
            dfs1(v, u);
            if (r[v] != k && siz[v]) update(1, r[v] + 1, - 2 * w);
            if (siz[v]) update(1, l[v], 2 * w);
            update(1, 1, -w);
        }
    };
    dfs1(1, 0);
    cout << ans << "\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}