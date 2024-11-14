#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long ll;

ll qmi(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, m, mod;
    cin >> n >> m >> mod;
    vector c(n + 1, vector<ll> (n + 1));
    for (int i = 0; i <= n; i ++ ) c[i][0] = 1;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= i; j ++ ) 
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    vector f(n + 1, vector<ll> (m));
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m - 1; j ++ ) 
            f[i][j] = i * (f[i][j - 1] + f[i - 1][j - 1]) % mod;
    ll ans1 = 0, ans2 = 0;
    for (int k = 1; k <= n; k ++ ) {
        ll res1 = qmi(2, (m - 1) * (n - k), mod);
        ll res2 = qmi(2, k, mod) - 1;
        ll res3 = qmi(res2, m - 1, mod);
        ans1 = (ans1 + c[n][k] * res1 % mod * res3 % mod) % mod;
        if (k == 1) continue;
        ll res = 0;
        for (int t = k; t <= m - 1; t ++ ) {
            ll res1 = ((qmi(2, k, mod) - k - 1) % mod + mod) % mod;
            ll res2 = qmi(res1, m - 1 - t, mod) % mod;
            res = (res + f[k][t] * res2 % mod) % mod; 
        }
        ans2 = (ans2 + c[n][k] * res % mod * res1 % mod) % mod;
    }
    cout << ((ans1 - ans2 - n * qmi(2, (m - 1) * (n - 1), mod) % mod) % mod + mod) % mod << endl;
}
// - n * qmi((qmi(2, m, mod) - 1), n - 1, mod) % mod)

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}