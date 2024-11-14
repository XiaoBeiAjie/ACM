#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> w(n + 1);
    vector p(n + 1, vector<int>());
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        p[i].push_back(0);
        for (int j = 1; j <= w[i]; j ++ ) {
            int x; cin >> x;
            p[i].push_back(x);
        }
    }
    constexpr int inf = 0x3f3f3f3f;
    vector f(k + 1, array<int, 2>({-inf, -inf}));
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        vector g(k + 1, array<int, 2>({-inf, -inf}));
        for (int j = 0; j <= k; j ++ ) {
            g[j][0] = f[j][0], g[j][1] = f[j][1];
            for (int t = 1; t <= w[i]; t ++ ) {
                if (j >= t) g[j][1] = max(g[j][1], f[j - t][0] + p[i][t]);
                if (j >= w[i]) g[j][1] = max(g[j][1], f[j - w[i]][1] + p[i][w[i]]);
            }
            if (j >= w[i]) {
                g[j][0] = max(g[j][0], f[j - w[i]][0] + p[i][w[i]]);
                g[j][1] = max(g[j][1], f[j - w[i]][1] + p[i][w[i]]);
            }
        }
        f = move(g);
    }
    int ans = 0;
    for (int i = 1; i <= k; i ++ ) 
        ans = max(ans, f[i][0]);
    ans = max(ans, f[k][1]);
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}