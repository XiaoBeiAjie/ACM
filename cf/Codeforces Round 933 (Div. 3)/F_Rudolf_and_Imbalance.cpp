#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    vector<ll> d(m);
    for (int i = 0; i < m; i ++ ) 
        cin >> d[i];
    vector<ll> w(k);
    for (int i = 0; i < k; i ++ ) 
        cin >> w[i];
    sort(d.begin(), d.end());
    sort(w.begin(), w.end());
    ll idx, dx = 0, cnt = 0, cx = 0;
    sort(a.begin() + 1, a.end());   
    for (int i = 1; i < n; i ++ ) 
        if (a[i + 1] - a[i] > dx) 
            cx = dx, dx = a[i + 1] - a[i], cnt = 1, idx = i;
        else if (a[i + 1] - a[i] > cx) cx = a[i + 1] - a[i];
    //if (cnt > 1) return cout << dx << "\n", void();
    ll ans = dx;
    for (int i = 0; i < m; i ++ ) {
        auto it = lower_bound(w.begin(), w.end(), ((a[idx] + a[idx + 1]) >> 1) - d[i]);
        if (it != w.end())
            ans = min(ans, max({abs(a[idx] - (d[i] + *it)), abs(a[idx + 1] - (d[i] + *it)), cx}));
        if (it != w.begin()) {
            it = prev(it);
            ans = min(ans, max({abs(a[idx] - (d[i] + *it)), abs(a[idx + 1] - (d[i] + *it)), cx}));
        }
        it = lower_bound(w.begin(), w.end(), ((a[idx] + a[idx + 1] + 1) >> 1) - d[i]);
        if (it != w.end())
            ans = min(ans, max({abs(a[idx] - (d[i] + *it)), abs(a[idx + 1] - (d[i] + *it)), cx}));
        if (it != w.begin()) {
            it = prev(it);
            ans = min(ans, max({abs(a[idx] - (d[i] + *it)), abs(a[idx + 1] - (d[i] + *it)), cx}));
        }   
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}