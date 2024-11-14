#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u > v) swap(u, v);
        mp[{u, v}] = i;
    }
    vector<int> siz(n + 1), ans;
    bool f = 1;
    function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u] = 1;
        int cnt = 0;
        for (auto v : adj[u]) {
            if (v == fa) continue;
            dfs(v, u);
            if (!(siz[v] % 3)) ans.push_back(mp[{min(u, v), max(u, v)}]);
            else cnt += siz[v];
        }
        if (cnt > 2) return f = 0, void();
        else siz[u] = (siz[u] + cnt) % 3;
    };
    dfs(1, 0);
    if (siz[1] % 3) f = 0;
    if (f) {
        cout << ans.size() << endl;
        for (auto e : ans) 
            cout << e << " ";
        cout << endl;
    }
    else cout << "-1" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}