#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = " " + s;
    function<int(int, int)> qmi = [&] (int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % mod;
            a = 1ll * a * a % mod;
            b >>= 1;
        }
        return res;
    };
    vector<int> fac(n + 1), inv(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i ++ ) 
        fac[i] = 1ll * fac[i - 1] * i % mod; 
    inv[n] = qmi(fac[n], mod - 2);
    for (int i = n; i; i -- ) 
        inv[i - 1] = 1ll * inv[i] * i % mod; 
    ll ans = 1;
    for (int i = 2; i <= n - 1; i ++ ) 
        ans = ans * (s[i] == '?' ? i - 1 : 1) % mod;
    function<void()> query = [&] () {
        cout << (s[1] == '?' ? 0 : ans) << "\n";
    };
    query();
    while (m -- ) {
        int x; char c;
        cin >> x >> c;
        if (x != 1 && s[x] == '?') 
            ans = ans * inv[x - 1] % mod * fac[x - 2] % mod;
        s[x] = c;
        if (x != 1 && s[x] == '?')
            ans = ans * (x - 1) % mod;
        query();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    //system("pause");
    return 0;
}