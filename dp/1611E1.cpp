#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long LL;

void solve1() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1, -1);
    vector<int> g[n + 1];
    queue<int> q;
    for (int i = 1; i <= k; i ++ ) {
        int x; cin >> x;
        c[x] = 0;
        q.push(x);
    }
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    c[1] = 1;
    q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u])
            if (c[v] == -1) c[v] = c[u], q.push(v);
    }
    for (int i = 2; i <= n; i ++ ) 
        if (g[i].size() == 1 && c[i] == 1) 
            return cout << "Yes" << endl, void();
    cout << "No" << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> d(n + 1, 0x3f3f3f3f), h(n + 1, 0x3f3f3f3f);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= k; i ++ ) {
        int x; cin >> x;
        h[x] = 0;
    }
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        if (!h[u]) return ;
        for (auto v : g[u]) {
            if (v == fa) continue;
            d[v] = d[u] + 1;
            self(self, v, u);
            h[u] = min(h[u], h[v] + 1);
        }
    };
    d[1] = 0;
    dfs(dfs, 1, 0);
    int ans = 0;
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        if (d[u] >= h[u]) return ans ++, void();
        if (g[u].size() == 1 && u != 1) return ans = -1, void();
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
            if (ans == -1) return ;
        }
    };
    dfs1(dfs1, 1, 0);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}