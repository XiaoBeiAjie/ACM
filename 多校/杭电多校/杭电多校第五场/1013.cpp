#include <bits/stdc++.h>
using namespace std;
const int N = 100010,mod=1e9+7;
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
    ll n; cin >> n;
    cout << ((n * n % mod - n + 1) % mod + mod) % mod * qmi(n, mod - 2) % mod << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}