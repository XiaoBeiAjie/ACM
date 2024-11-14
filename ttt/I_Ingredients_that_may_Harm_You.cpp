#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    constexpr int len = 1000000;
    vector<int> st(len + 1), mu(len + 1);
    vector<int> primes;
    function<void()> get_primes = [&] () {
        mu[1] = 1;
        for (int i = 2; i <= len; i ++ ) {
            if (!st[i]) mu[i] = -1, primes.push_back(i);
            for (int j = 0; primes[j] <= len / i; j ++ ) {
                st[primes[j] * i] = 1;
                if (i % primes[j] == 0) {
                    mu[primes[j] * i] = 0;
                    break;
                }
                else mu[primes[j] * i] = -mu[i];
            }
        }
    };
    get_primes();
    vector<int> cnt(len + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], cnt[w[i]] ++ ;
    for (int i = 1; i <= len; i ++ ) 
        for (int j = (i << 1); j <= len; j += i) 
            cnt[i] += cnt[j];
    constexpr int mod = 1000000007;
    vector<int> qmi(n + 1);
    qmi[0] = 1;
    for (int i = 1; i <= n; i ++ ) 
        qmi[i] = 2ll * qmi[i - 1] % mod;
    int q; cin >> q;
    while (q -- ) {
        int u; cin >> u;
        vector<int> d;
        for (int j = 0; primes[j] <= 1000 && primes[j] <= u; j ++ ) {
            if (u % primes[j] == 0) {
                while (u % primes[j] == 0) u /= primes[j];
                d.push_back(primes[j]);
            }
        }
        if (u != 1) d.push_back(u);
        int siz = d.size();
        int ans = 0;
        for (int mask = 1; mask < (1 << siz); mask ++ ) {
            int res = 1;
            for (int i = 0; i < siz; i ++ ) 
                if ((mask >> i) & 1) res *= d[i];
            ans += cnt[res] * mu[res];
        }
        cout << qmi[n + ans] << "\n";
    }
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}