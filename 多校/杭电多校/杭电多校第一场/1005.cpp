#include <bits/stdc++.h>
using namespace std;
const int N = 10000010, mod = 998244353;
typedef long long LL;
int fac[N], inv[N];

int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, t = 0; cin >> n;
    vector<int> cnt(26);
    for (int i = 1; i <= n; i ++ ) {
        char c; cin >> c;
        int x; cin >> x;
        cnt[c - 'a'] = x;
        t += x;
    }
    if (t & 1) {
        int p = 1ll * inv[t] * fac[t >> 1] % mod, idx = 0;
        for (int i = 0; i <= 25; i ++ ) 
            if ((cnt[i] & 1) && (idx == 1)) p = 0;
            else {
                p = 1ll * p * fac[cnt[i]] % mod * inv[cnt[i] >> 1] % mod;
                if (cnt[i] & 1) idx ++;
            }
        cout << (1ll + p) * inv[2] % mod << endl; 
    } else {
        int p = 1ll * inv[t] * fac[t >> 1] % mod, idx = 0;
        for (int i = 0; i <= 25; i ++ ) 
            if ((cnt[i] & 1) && idx) p = 0;
            else {
                p = 1ll * p * fac[cnt[i]] % mod * inv[cnt[i] >> 1] % mod;
                if (cnt[i] & 1) idx ++;
            }
        cout << ((1ll - p) % mod + mod) * inv[2] % mod << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("1005.in","r",stdin);
    // freopen("3.out","w",stdout);
    fac[0] = 1;
    for (int i = 1; i < N; i ++ ) 
        fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[N - 1] = qmi(fac[N - 1], mod - 2);
    for (int i = N - 1; i; i -- ) 
        inv[i - 1] = 1ll * inv[i] * i % mod;
    //cerr << inv[0] << "!!" << endl;
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}