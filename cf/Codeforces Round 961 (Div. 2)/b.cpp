#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> w(n + 1);
    map<ll, ll> mp; 
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> c[i];
        mp[w[i]] = c[i];
    } 
    ll ans = 0;
    for (auto [x, cnt1] : mp) {
        ll cnt2 = 0;
        if (mp.find(x + 1) != mp.end()) cnt2 = mp[x + 1];
        ll t = m / x;
        ll rc1 = min(t, cnt1), rc2 = 0;
        ll rest = m - rc1 * x;
        t = rest / (x + 1);
        rc2 = min(t, cnt2);
        rest -= rc2 * (x + 1);
        if (rest <= min(rc1, cnt2 - rc2)) rest = 0;
        else 
            rest -= min(rc1, cnt2 - rc2);
        ans = max(ans, m - rest);
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}