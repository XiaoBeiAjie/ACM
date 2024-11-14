#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    constexpr int base = 510;
    vector<i64> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector pre(base, vector<i64> (n + 1)), sum(base, vector<i64> (n + 1));
    for (int b = 1; b < base; b ++ ) 
        for (int i = 1; i <= b; i ++ ) 
            for (int j = i, cnt = 1; j <= n; j += b, cnt ++) 
                if (i == j) 
                    sum[b][j] = pre[b][j] = w[i];
                else {
                    sum[b][j] = sum[b][j - b] + w[j] * cnt;
                    pre[b][j] = pre[b][j - b] + w[j];   
                }
                    
    while (q -- ) {
        int s, d, k;
        cin >> s >> d >> k;
        if (d >= base) {
            i64 ans = 0;
            for (int i = 0; i < k; i ++ ) 
                ans += w[s + i * d] * (i + 1);
            cout << ans << " ";
            continue;
        }
        int t = max(0, s - d), tt = (s + d - 1) / d - 1;
        cout << sum[d][s + d * (k - 1)] - sum[d][t] - 1ll * tt * (pre[d][s + d * (k - 1)] - pre[d][t]) << " ";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}