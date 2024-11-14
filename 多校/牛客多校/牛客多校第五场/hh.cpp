#include <bits/stdc++.h>
using namespace std;
const int N = 45;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector e(n + 1, vector<int> ());
    for (int i = 1; i <= m; i ++ ) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> vis(n + 1);
    function<int(int, int)> dfs = [&] (int u, int fa) {
        int res = 0;
        vis[u] ++;
        //cerr << u << "\n";
        for (auto v : e[u]) 
            if (v != fa) 
                vis[v] ++;
        for (auto v : e[u]) {
            if (v == fa) continue;
            if (vis[v] == 1) res = max(res, dfs(v, u));
        }
        vis[u] --;
        for (auto v : e[u]) 
            if (v != fa) 
                vis[v] --;
        return res + 1;
    };
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        ans = max(ans, dfs(i, 0));
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}