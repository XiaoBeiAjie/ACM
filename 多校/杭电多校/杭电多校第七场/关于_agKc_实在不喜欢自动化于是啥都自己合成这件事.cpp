#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<__int128_t> f(n + 1);
    vector e(n + 1, vector<array<__int128_t, 2>>());
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int p; cin >> p;
        if (p) {
            int t; cin >> t;
            while (t -- ) {
                ll x, a;
                cin >> x >> a;
                e[i].push_back({a, x});
            }
        }
        else {
            int t; cin >> t;
            f[i] = t;
        }
    }
    function<void(int, int)> dfs = [&] (int u, int fa) {
        __int128_t maxx = 0;
        int cnt = 0;
        for (auto [v, w] : e[u]) {
            dfs(v, u);
            cnt += vis[v];
            vis[u] |= vis[v];
            if (!vis[v]) {
                f[u] += w * f[v];
                maxx = max(maxx, w * f[v]);
            }
        }
        if (u != k && f[u] > 1000000000) 
            vis[u] = 1;
        if (u == k) {
            if (cnt >= 2) return cout << "Impossible\n", void();
            if (!vis[u]) f[u] -= maxx;
            if (f[k] > 1000000000) cout << "Impossible\n";
            else {
                int t = f[k];
                cout << t << "\n";
            }
        }
    };
    dfs(k, 0);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}