#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector e(n + 1, vector<int>());
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    vector<array<int, 2>> w(m + 1);
    for (int i = 1; i <= m; i ++ ) {
        int u, v; cin >> u >> v;
        w[i] = {u, v};
    }
    vector<int> dep(n + 1), l_(n + 1), r_(n + 1), dfn(n + 1);
    vector p(n + 1, vector<int>(20));
    int idx = 0;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        dep[u] = dep[fa] + 1; dfn[u] = ++ idx; l_[u] = r_[u] = idx;
        p[u][0] = fa;
        for (int i = 1; (1 << i) <= dep[u]; i ++ ) 
            p[u][i] = p[p[u][i - 1]][i - 1];
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            r_[u] = max(r_[u], idx);
        }
    };
    dfs(1, 0);
    function<int(int, int)> lca = [&] (int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; i >= 0; i -- ) 
            if (dep[u] - (1 << i) >= dep[v])
                u = p[u][i];
        if (u == v) return u;
        for (int i = 19; i >= 0; i -- ) 
            if (p[u][i] != p[v][i]) 
                u = p[u][i], v = p[v][i];
        return p[u][0];
    };
    function<int(int, int)> dist = [&] (int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    };
    function<int(int, int)> jump = [&] (int u, int len) {
        for (int i = 19; i >= 0; i -- ) 
            if (len >= (1 << i)) 
                u = p[u][i], len -= (1 << i);
        return u;
    };
    function<bool(int)> check = [&] (int mid) {
        vector<int> pre(n + 1);
        for (int i = 1; i <= m; i ++ ) {
            auto [u, v] = w[i];
            int distance = dist(u, v);
            if (distance <= mid) {
                pre[1] += 2;
                continue;
            }
            if (distance > 2 * mid) return false;
            int fa = lca(u, v);
            {
                int len = dist(fa, u);
                if (mid < len) {
                    int t = jump(u, mid);
                    pre[l_[t]] ++;
                    if (r_[t] != n) pre[r_[t] + 1] --;
                } 
                else {
                    int t = jump(v, distance - mid - 1);
                    pre[1] ++;
                    pre[l_[t]] --;
                    if (r_[t] != n) pre[r_[t] + 1] ++;
                }
            }
            {
                int len = dist(fa, v);
                if (mid < len) {
                    int t = jump(v, mid);
                    pre[l_[t]] ++;
                    if (r_[t] != n) pre[r_[t] + 1] --;
                } 
                else {
                    int t = jump(u, distance - mid - 1);
                    pre[1] ++;
                    pre[l_[t]] --;
                    if (r_[t] != n) pre[r_[t] + 1] ++;
                }
            }
        }
        for (int i = 1; i <= n; i ++ ) {
            pre[i] += pre[i - 1];
            if (pre[i] == 2 * m) 
                return true;
        }
        return false;
    };
    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}