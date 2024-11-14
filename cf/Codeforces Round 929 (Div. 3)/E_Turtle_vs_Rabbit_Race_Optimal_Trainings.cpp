#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], pre[i] += pre[i - 1] + w[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i ++ ) 
        mp[pre[i]] = i;
    int q; cin >> q;
    constexpr int inf = 0x3f3f3f3f;
    while (q -- ) {
        int l, u; cin >> l >> u;
        auto it = lower_bound(pre.begin(), pre.end(), u + pre[l - 1]);
        ll sum1 = -inf, sum2 = -inf;
        if (it != pre.end()) {
            ll t = *it - pre[l - 1];
            sum1 = (2 * u + 1 - t) * t >> 1;
        }
        if (it != pre.begin()) {
            ll t = *prev(it) - pre[l - 1];
            sum2 = (2 * u + 1 - t) * t >> 1;
        }
        if (sum1 > sum2 && it != pre.end()) cout << max(l, mp[*it]) << " ";
        else if (sum2 >= sum1 && it != pre.begin()) cout << max(l, mp[*prev(it)]) << " ";
        else cout << max(l, mp[*it]) << " ";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}