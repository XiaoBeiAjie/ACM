#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;

vector<ll> fac(200001);

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i ++ ) 
        s[i] -= '0';
    ll ans1 = 0, cnt1 = 1, ans2 = 0, cnt2 = 1;
    bool f = false;
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (f ^ s[i]) {
            f ^= 1;
            cnt1 = cnt1 * (res + 1) % mod;
            res = 0;
            continue;
        }
        else ans1 ++, res ++;
    }
    cnt1 = cnt1 * (res + 1) % mod;
    res = 0;
    f = true;
    for (int i = 1; i <= n; i ++ ) {
        if (f ^ s[i]) {
            f ^= 1;
            cnt2 = cnt2 * (res + 1) % mod;
            res = 0;
        }
        else ans2 ++, res ++;
    }
    cnt2 = cnt2 * (res + 1) % mod;
    if (ans1 < ans2) cout << ans1 << " " << fac[ans1] * cnt1 % mod << "\n";
    else if (ans2 < ans1) cout << ans2 << " " << fac[ans2] * cnt2 % mod << "\n";
    else cout << ans1 << " " << (fac[ans1] * cnt1 % mod + fac[ans2] * cnt2 % mod) % mod << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= 200000; i ++ ) 
        fac[i] = fac[i - 1] * i % mod;
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}