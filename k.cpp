#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    vector<int> b(m + 2);
    for (int i = 1; i <= m; i ++ ) 
        cin >> b[i];
    sort(a.begin() + 1, a.end());
    b[m + 1] = w + 1;
    sort(b.begin() + 1, b.end());
    m ++;
    int idx = 1;
    vector<int> ans;
    for (int i = 1; i <= m; i ++ ) {
        int l = b[i - 1], r = b[i];
        vector<int> v;
        while (idx <= n && a[idx] <= r) 
            v.push_back(a[idx]), idx ++;
        if (v.empty()) continue;
        vector<int> g;
        int rr = l;
        int t = v.size();
        for (int j = 0; j < t; j ++ ) {
            if (rr >= v[j]) continue;
            if (v[j] + k - 1 < r) {
                rr = v[j] + k - 1;
                g.push_back(v[j]);
            }
            else {
                int ll = r - 1 - k + 1;
                if (ll <= l) return cout << "-1\n", void();
                g.push_back(ll);
                int tt = g.size();
                for (int p = tt - 2; p >= 0; p -- ) {
                    if (g[p] + k - 1 < g[p + 1]) break;
                    ll = g[p + 1] - 1 - k + 1;
                    if (ll <= l) return cout << "-1\n", void();
                    g[p] = ll;
                }
                break;
            }
        }
        for (int j = 0; j < g.size(); j ++ ) 
            ans.push_back(g[j]);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++ ) 
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> T;
    while (T -- ) solve();
    return 0;
}