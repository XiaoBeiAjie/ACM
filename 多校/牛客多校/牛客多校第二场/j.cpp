#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long ll;

int get(int x, int a) {
    if (x == 0) return 1;
    if (x == 1) return a;
    int f0 = 1, f1 = a, f2, f3;
    ll a2 = 1ll * a * a % mod;
    for (int i = 2; i <= x; i += 2) {
        f2 = (1ll * a * f1 % mod + 1ll * (i - 1) * f0 % mod) % mod;
        f3 = (1ll * (a2 + i) * f1 % mod + 1ll * a * (i - 1) % mod * f0 % mod) % mod;
        f0 = f2;
        f1 = f3;
    }
    if (x & 1) return f1;
    else return f0;
}

// void solve() {
//     ll n, a; cin >> n >> a;
//     int ans = get(n % mod, a);
//     int nn = n % mod;
//     while (n > nn) ans = 1ll * ans * a % mod, n -= mod;
//     cout << ans << endl;
// }

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n, a; cin >> n >> a;
    int ans = get(n % mod, a);
    int nn = n % mod;
    while (n > nn) ans = 1ll * ans * a % mod, n -= mod;
    cout << ans << endl;
    system("pause");
    return 0;
}