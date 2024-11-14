#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;
    map<array<ll, 2>, ll> mp;
    function<ll(ll, ll, ll)> check = [&] (ll l, ll r, ll k) {
        if (k < 0 || l > r) return 0ll;
        if (l == r) return 1ll;
        ll t = __lg(r - l + 1), len = r - l + 1;
        if (k >= t) return len;
        if (mp.find({len, k}) != mp.end()) return mp[{len, k}];
        ll mid = l + r >> 1;
        return mp[{len, k}] = check(l, mid - 1, k - 1) + check(mid + 1, r, k) + 1ll;
    };
    cout << check(l, r, k) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}