#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;

ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, k; cin >> n >> k;
    if (n == 1) return cout << qmi(2, k) << "\n", void();
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i ++ ) 
        cin >> p[i];
    cout << qmi((qmi(2, n) - 2 + mod) % mod, k) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}