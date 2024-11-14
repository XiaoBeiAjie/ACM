#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct Edge {
    int u, v, w;
    bool operator < (const Edge& rh) const {
        return w < rh.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n << 1);
    for (int i = 1; i <= n; i ++ ) 
        p[i] = i;
    function<int(int)> find = [&] (int x) {
        return x == p[x] ? x : find(p[x]);
    };
    vector<Edge> e(m);
    for (int i = 0; i < m; i ++ ) 
        cin >> e[i].u >> e[i].v >> e[i].w;
    vector g(n << 1, vector<int> ());
    vector<int> val(n << 1), siz(n << 1), dep(n << 1);
    vector<int> top(n << 1), son(n << 1), ff(n << 1);
    vector<bool> vis(n << 1);
    int idx = n;
    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        siz[u] = 1; vis[u] = true;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1, ff[v] = u;
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
    };
    function<void(int, int)> dfs2 = [&] (int u, int tp) {
        top[u] = tp;
        if (!son[u]) return ;
        dfs2(son[u], tp);
        for (auto v : g[u]) {
            if (v == son[u] || v == ff[u]) 
                continue;
            dfs2(v, v);
        }
    };
    function<void()> kruskal = [&] () {
        sort(e.begin(), e.end());
        reverse(e.begin(), e.end());
        for (auto [u, v, w] : e) {
            u = find(u), v = find(v);
            if (u == v) continue;
            val[++ idx] = w;
            p[idx] = p[u] = p[v] = idx;
            g[idx].push_back(u); g[u].push_back(idx);
            g[idx].push_back(v); g[v].push_back(idx);
        }
        for (int i = 1; i <= idx; i ++ ) 
            if (!vis[i]) {
                int u = find(i); // 不能直接替换 u = find(u)
                dfs1(u, 0), dfs2(u, u);
            }
    }; 
    function<int(int, int)> lca = [&] (int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) u = ff[top[u]];
            else v = ff[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    };
    kruskal();
    int q; cin >> q;
    while (q -- ) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) cout << "-1\n";
        else cout << val[lca(u, v)] << "\n";
    }    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("P1967_14.in", "r", stdin);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}