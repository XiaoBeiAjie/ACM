#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m, e;
    cin >> n >> m >> e;
    vector adj(n + 1, vector<int> ());
    for (int i = 1; i <= e; i ++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    vector<bool> vis(m + 1);
    vector<int>match(m + 1);
    function<bool(int)> dfs = [&] (int u) {
        for (auto v : adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    };
    for (int i = 1; i <= n; i ++ ) {
        vis.assign(vis.size(), false);
        if (dfs(i)) ans ++;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}