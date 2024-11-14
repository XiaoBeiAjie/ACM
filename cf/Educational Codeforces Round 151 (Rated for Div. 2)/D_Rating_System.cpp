#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], pre[i] = w[i] + pre[i - 1];
    ll mx = 0, ans = 0, ans1 = 0;
    for (int i = 1; i <= n; i ++ ) {
        ll cur = mx + pre[n] - pre[i - 1];
        if (cur > ans) ans = cur, ans1 = mx;
        if (pre[i] > mx) mx = pre[i];
    }
    if (mx > ans) ans1 = mx;
    cout << ans1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}