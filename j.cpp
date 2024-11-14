#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> w(n + 1);
    vector<int> st(k + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        st[w[i]] = 1;
    }
    function<i64(int, int)> hs = [&] (int a, int b) {
        if (a > b) swap(a, b);
        return 1ll * a * 1000000 + b;
    };
    unordered_map<i64, int> mp;
    int res = 0;
    vector<int> cnt(k + 1);
    for (int i = 1; i <= m; i ++ ) {
        int u, v; cin >> u >> v;
        if (u == v) {
            if (st[u]) res ++;
            else cnt[u] ++;
        }
        else if (st[u] && st[v]) res ++;
        else if (st[u] || st[v]) {
            if (st[u]) cnt[v] ++;
            else if (st[v]) cnt[u] ++;
        }
        else mp[hs(u, v)] ++;
    }
    vector<int> b(k + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        return cnt[i] > cnt[j];
    });
    int ans = 0;
    int t = cnt[b[1]];
    if (k > 1) t += cnt[b[2]];
    ans = res + t;
    // cerr << res << "\n";
    //cerr << cnt[1] << " " << cnt[4] << "\n";
    for (auto [p, c] : mp) {
        int u = p % 1000000, v = p / 1000000;
        // cerr << u << " " << v << " " << c << "\n";
        ans = max(ans, res + cnt[u] + cnt[v] + c);
    }
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> T;
    while (T -- ) solve();
    return 0;
}