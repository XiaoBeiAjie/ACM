#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

ll fac[N], inv[N];

ll qmi(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;    
    }
    return res;
}

ll c(ll n, ll m, ll mod) {
    if (m > n) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

ll lucas(ll n, ll m, ll mod) {
    if (!m) return 1;
    return c(n % mod, m % mod, mod) * lucas(n / mod, m / mod, mod) % mod;
}

void solve() {
    ll n, m, mod;
    cin >> n >> m >> mod;
    n += m;
    fac[0] = 1;
    for (int i = 1; i <= mod; i ++ )
        fac[i] = fac[i - 1] * i % mod;
    inv[mod - 1] = qmi(fac[mod - 1], mod - 2, mod); 
    for (int i = mod - 1; i; i -- )
        inv[i - 1] = inv[i] * i % mod;
    cout << lucas(n, m, mod) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}