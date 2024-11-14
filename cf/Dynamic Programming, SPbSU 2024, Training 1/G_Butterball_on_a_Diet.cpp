#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<array<int, 2>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i][0] >> w[i][1];
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        pre[i] = pre[i - 1] + w[i][0] + w[i][1];
    constexpr int inf = 0x3f3f3f3f;
    vector<i64> f(k + 1, -inf);
    f[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        vector<i64> g(k + 1, -inf);
        for (int j = 0; j < k; j ++ ) {
            if (f[j] == -inf) continue;
            int d = (pre[i - 1] - j) % k;
            for (int t = 1; t <= min(w[i][0], k - 1); t ++ ) {
                int dt = k - t;
                if (dt > w[i][1]) continue;
                int res1 = (j + w[i][0] - t) / k, res2 = (d + w[i][1] - dt) / k;
                g[(j + w[i][0] - t) % k] = max(g[(j + w[i][0] - t) % k], f[j] + 1 + res1 + res2);
            }
            int res1 = (j + w[i][0]) / k, res2 = (d + w[i][1]) / k;
            g[(j + w[i][0]) % k] = max(g[(j + w[i][0]) % k], f[j] + res1 + res2);
        }
        f = move(g);
    }
    cout << *max_element(f.begin(), f.end()) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}