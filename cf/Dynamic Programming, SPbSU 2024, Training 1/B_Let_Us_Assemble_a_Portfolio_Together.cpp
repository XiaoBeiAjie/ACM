#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    map<i64, i64> f;
    f[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        map<i64, i64> g = f;
        int m; cin >> m;
        for (int j = 1; j <= m; j ++ ) {
            i64 v, w; cin >> v >> w;
            for (auto [u, d] : f) {
                if (w + u > k) continue;
                g[u + w] = max(g[u + w], d + v);
            } 
        }
        f = move(g);
    }
    i64 ans = 0;
    for (auto [u, d] : f) 
        ans = max(ans, d);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}