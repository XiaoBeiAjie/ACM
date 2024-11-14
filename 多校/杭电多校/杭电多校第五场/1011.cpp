#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
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
    if (n % 3 == 2) cout << qmi(2, n - 1) << "\n";
    else cout << qmi(2, n) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}