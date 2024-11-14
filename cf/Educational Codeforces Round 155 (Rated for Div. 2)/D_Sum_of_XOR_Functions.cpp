#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    ll ans = 0;
    for (int t = 0; t < 31; t ++ ) {
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i ++ ) 
            b[i] = (w[i] >> t) & 1;
        vector<int> pre(n + 1);
        vector<ll> cnt(2), sum(2);
        cnt[0] = 1;
        ll res = 0;
        for (int r = 1; r <= n; r ++ ) {
            pre[r] = pre[r - 1] ^ (b[r] == 1);
            cnt[pre[r]] ++, sum[pre[r]] = (sum[pre[r]] + r) % mod;
            res = ((res + 1ll * r * cnt[pre[r] ^ 1] % mod - sum[pre[r] ^ 1]) % mod + mod) % mod; 
        }
        ans = (ans + res * (1ll << t) % mod) % mod;
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